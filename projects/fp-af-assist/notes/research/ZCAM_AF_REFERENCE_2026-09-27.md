# Z CAM E2-F6 AF：可讀實作與失敗機制參考（2026-09-27）

## 定位與證據界線

本次是離線、唯讀韌體分析；沒有啟動韌體、連線相機、部署或修改 Ghidra 原專案。使用者已指出 Z CAM 的連續自動對焦體驗並不理想，因此本頁把它當成 **可讀 CDAF 與失敗機制的比較材料**，不是 CAF 效能標竿，也不建議 fp 照搬整套算法。

本地 `imvt_camera` 保留大量動態函式符號，且 CAF/SAF、FV、ROI、ISP、鏡頭介面均有實際可反編譯程式；本頁不只根據 strings 推論。以下地址都是這個 ELF 的虛擬地址（VA），不是 fp 地址。Ghidra 缺少原始結構與函式型別，涉及浮點參數、間接呼叫、結構布局處必須再用 AArch64 指令核對；「已追到」不代表所有模式會走該分支。

已追到的主幹是對比 FV 歷史、爬坡、回峰與重觸發。此 bounded 範圍沒有找到可移植的 DFD 模糊量→距離反演模型；這不等於證明整個韌體不存在其他輔助。IMX410 型號與無 PDAF 的分類不在本頁重新認證，分類應另引用官方資料；同感光元件不能消除 ISP、鏡頭、時序、處理器差異。

## 可重現的輸入

- 韌體包：`zcam_e2f6/fw/E2_F6_FW_1.0.13.fw`。
- ELF：`zcam_e2f6/out/rootfs/usr/bin/imvt_camera`，ELF64 LE AArch64。
- ELF SHA-256：`5882b6c18a2fda4f95efa4d0877e6ce1b8b34b69c9200a450a9d564239896e39`。
- 原有專案：`zcam_e2f6/ghidra/zcam.gpr`、`zcam.rep`，程式 `/imvt_camera`；本次複製到暫存目錄再以 `-readOnly -noanalysis` 分析。
- 既有解包／平台筆記：`zcam_e2f6/notes/ZCAM_E2F6_FIRMWARE.md:3-18`；平台 Hi3559AV100，IMX410 driver 靜態連結，來源路徑 `echo_imx410_ef_hi3559av100/adj_params.c`。
- 可重用的離線工具：`zcam_e2f6/color-firmware-20260924/scripts/DumpColorFunctions.java`、`elf_image.py`；後者將 VA 映射到 ELF LOAD segment，可讀符號、常數與參數。
- 已永久保存本次反編譯：[core（62 個函式）](/Users/dido/Developer.localized/SIGMAfp_re/research/autofocus/analysis/zcam_af_20260927/zcam-af-core-20260927.c)、[input（16 個函式）](/Users/dido/Developer.localized/SIGMAfp_re/research/autofocus/analysis/zcam_af_20260927/zcam-af-input-20260927.c)、[extra（2 個補建入口）](/Users/dido/Developer.localized/SIGMAfp_re/research/autofocus/analysis/zcam_af_20260927/zcam-af-extra-20260927.c)；[函式清單](/Users/dido/Developer.localized/SIGMAfp_re/research/autofocus/analysis/zcam_af_20260927/functions.tsv) 保留 VA／行號，[重現說明](/Users/dido/Developer.localized/SIGMAfp_re/projects/fp-af-assist/notes/evidence/analysis-zcam_af_20260927.md) 與 [生成命令](/Users/dido/Developer.localized/SIGMAfp_re/research/autofocus/analysis/zcam_af_20260927/reproduce.sh) 保存工具版本、完整範圍及限制。

## 確實連起來的控制路徑

```text
imvt_af_init @ 0x007308c0
  ├─ lens type → imvt_cam_adj_register_af_params @ 0x00a69eb0
  ├─ imvt_isp_af_init @ 0x00886be8
  └─ imvt_n3a_af_init @ 0x008893c8
       ├─ MFT / EF / VCM adapter selection
       └─ imvt_isp_af_register_callback(0x00887c10)

get_focus_data_task @ 0x00885eb0
  → HI_MPI_ISP_GetVDTimeOut(0, 1, 200)
  → HI_MPI_ISP_GetFocusStatistics
  → 四平面 tile record → callback @ 0x00887c10
       + imvt_get_imu_data
       + n3a_ae_af_get_lv_value / n3a_ae_get_luma_contrast
  → n3a_af_update @ 0x00d3a010
  → n3a_af_parse_fv @ 0x00d41110
  → n3a_af_saf_task_run @ 0x00d3e270 或 n3a_af_caf_task_run @ 0x00d3adc8
  → lens function table：位置查詢、range、move(target, speed)
```

`get_focus_data_task` 的名字來自入口 `prctl` 參數，不是臆造函式名。實際 BL：`0x00885fd8`→GetVDTimeOut，`0x00885ff4`→GetFocusStatistics，`0x0088611c` 間接呼叫已註冊 callback；callback 中 `0x00887da0`→IMU，`0x00887de8`→AE LV，`0x00887e30`→luma/contrast，`0x00887ecc`→`n3a_af_update`。這是一條 ISP 原生統計控制鏈，沒有經過 USB 預覽畫面。

callback 含跳過初始幀與依輸入節奏參數／mode 降採樣的條件（節奏參數 default 30，完整 setter 語意待續追）；因此 **ISP 有新資料不等於每筆都被用來下 AF 決策**。GetFocusStatistics 連續兩次失敗時，此 task 將 running flag 清零並退出（`0x00886148`–`0x00886170`）；成功會清除前一次失敗旗標。這是可借鑑的失敗狀態區分，不是已量到其掉幀率。

## ISP 統計與 ROI：實際格式、仍缺的語意

`0x00886074`–`0x008860b4` 把每 tile 12-byte 記錄拆成 4 個 uint32 平面，前面有 2 個維度欄位，總緩衝 `0x2008` bytes，即 `2 + 4×512` 個 uint32。以 tile 原始起點 `t` 表示：

```text
FV_plane_1 = u16(t + 2)
FV_plane_2 = (10 * u16(t + 4) + 54 * u16(t + 6)) >> 6
plane_3    = u16(t + 8)
plane_4    = u16(t + 10)
```

row stride `0xcc` = 17×12；width/height 從 ISP AF config 的 16-bit 欄位讀出。這證實有多個硬體統計量被融合，但尚未以 HiSilicon SDK 的對應結構與 AF filter 設定逐欄命名。**不得把這兩個 FV 直接叫成 Sigma 的 H/L，或把 10:54 權重當成可搬到 fp 的係數。**

`n3a_af_parse_fv @ 0x00d41110`（0x44c bytes）維護 `0x2008` 歷史記錄，套用 per-tile 權重／遮罩、排除旗標，分別累積前兩個平面的 FV；加權均值存於 `0x0481a9b0`、`0x0481a9b4`。還有低 FV 模式的弱 tile 排除、highlight 與 luma 判斷。`n3a_af_parase_fv_get_trend_info @ 0x00d40d90` 計算多 tile 上升／下降比例與均值，並非僅看一個全畫面 scalar。

`imvt_isp_af_set_roi @ 0x008866d8`（0x2b0 bytes）將 normalized x/y/w/h 換成當前 ISP 尺寸；最小區域邊長有 256 的限制，x/y 對齊 4、width 對齊 8、height 對齊 2、右／下邊緣留 8。grid 奇數化，上限 17 columns×15 rows；初始 tile 參數 200。這些數字是 **HiSilicon 實作限制**，不是 fp ROI 限制。

`FUN_00885cb0` 使用 `HI_MPI_ISP_GetStatisticsConfig`／`SetStatisticsConfig`，成功後才把新的 normalized ROI/grid 傳給 `n3a_af_set_roi @ 0x00d41d28`。後者使用 mode profile 的 tile mask（root + `mode×0x220 + 0x4e8`），特定模式再遮掉上方邊角。該 callback 另可將 ROI 改動延後到 AF 未在搜尋時處理，避免在同一搜索中更換統計區域。

## CAF 的抗抽動機制，以及它自身仍可能反覆搜尋的原因

主體 `n3a_af_caf_task_run @ 0x00d3adc8` 長 0x2d2c bytes；`n3a_af_saf_task_run @ 0x00d3e270` 長 0x279c。下表的狀態名是依分支操作歸納；有明文 log 的地方另外標示。不是已測得的 Z CAM 失敗原因排名。

| 實際分支／可定位證據 | 可確認的行為 | 對 fp 的意義／限制 |
|---|---|---|
| CAF 入口：`n3a_af_lum_parse`、`n3a_af_luminance_is_changing`、`n3a_af_camera_is_moving` | 非 force-focus 時，亮度改變或相機運動可 cancel CAF | 避免把 AE／鏡頭外運動當離焦，但 gate 太嚴可能長時間不動；IMU 與視覺移動不能互相替代 |
| `dir change skip this fv!!`，`0x00d3adc8` 函式內 | 反向後主動丟掉下一筆 FV；另有限制決策節奏的 counter | 已考慮舊統計／馬達延遲，但「丟一筆」不是曝光與位置配對已證明；fp 必須量自身延遲 |
| FV 與實際位置 history | 有效且 Δposition≠0 才算 `(FV_now−FV_prev)/abs(Δposition)`，再算二、三階差分 | 用位移而非命令次數歸一化；若 FV/position 時間錯配，導數仍會錯 |
| state 0 monitor，`max diff reach`、`reach max lv diff` | 相對／絕對 FV 差、luma、LV、stable counter 決定重觸發 | 很容易與 AE、ROI、紋理改變耦合；需重放並逐一消融 gate |
| `reach max out of focus frames, force focus` | 部分持續變化可累積到 force-focus，繞過一般 cancel 條件 | 解決一直不對焦，也可能重新引起 pumping；須量重觸發次數與成功率 |
| mode 3 的 `object depeth only chang a little, skip run focus` | ROI 面積／長寬比變化小，且位置／LV 條件滿足，可抑制再次搜索；ROI 面積變化還能影響起始方向 | 這是幾何變化 heuristic，不是校準的 face-size→depth→motor 模型 |
| state 3 climb，`fv double, slow focus step`、`flat increase step` | FV 快增可縮步，平坦區可放大步幅；維護 peak、上坡／下坡、方向次數 | 平坦到窄峰的跨越可能 overshoot；對單峰／靜態場景的假設不能視為追焦能力 |
| `fv is zero, maybe step is too large, skip peak, move back` | 明確包含跨峰後退回的補救路徑 | 可用來設計 fp 窄景深／低紋理失敗測試，不能證明有可靠失焦距離估計 |
| state 4 peak check；`0x00d3c208`、`0x00d3b7f8` 附近 | 多次檢查峰；驗證不符會回 state 3，search budget 可加 `0x32`（50） | 假峰、動態主體、變光可帶來回搜，容易表現為來回抽動；「有上限」不能直接當全程硬上限 |
| peak>80 且 (current+1)/peak≤0.5 的分支 | 判作可能 environment change，回 state 3 並擴充搜索 budget | 明確的失敗恢復，但場景改變與錯過焦點可能混淆 |
| range endpoints、`NG reach closet/infinite`、`s_caf_obj.max_try` | 碰界反轉，多次撞同端／budget 不足→state 7 NG | fp 應記錄撞界、反向次數、總行程與逾時，不以最後 FV 單值驗收 |
| state 6／7 | 成功或 NG 都清部分狀態、保存監看基準，再回 state 0 | 停下不等於合焦；NG 回監看後是否反覆重觸發，需動態 trace 才能判定 |

`n3a_af_fv_set_final_focus_point @ 0x00d41b40` 是依歷史選 tile／權重、無 survivor 時挑最強 tile；**名稱的 focus point 不應被誤讀成幾何 motor target**。

## 有確切位置的參數，不等於現在機身生效值

`imvt_cam_adj_register_af_params @ 0x00a69eb0` 依 lens type 1 選 root `0x01014750`，type 0 選 `0x01015ba8`；未知類型套後者並報 error。init 的 adapter 選擇把 type 1 對到 EF、type 0 對到 MFT；共有 VCM 初始化函式不代表 E2-F6 生效。

`n3a_af_register_params @ 0x00d3a478` 的指令證實：SAF 接 root；CAF 接 root+`0x90` 與 root+`0x13f8`；parse-FV 接 root。CAF setter `0x00d3de20` 複製主區 `0x450` bytes 與附加 `0x34` bytes；SAF setter `0x00d40c40` 複製 `0x90`。ISP AF block 由 `imvt_adj_get_af_isp_params @ 0x00a69f18` 返回 `0x00e2fd10`，長度 `0x10c`。

| root offset／消費位置 | root 0x01014750 | root 0x01015ba8 | 本次能確定的用途 |
|---|---:|---:|---|
| +0x4d0 → CAF global 0x047b7e48 | 75 | 75 | 搜索 budget 的初始／reset 值；重搜可再加 50，不是端到端 75 幀保證 |
| +0x4b8 → 0x047b7e30 | 2 | 3 | 成功後監看等待 counter 的來源，使用時 +1；不是秒數 |
| +0x1418 | 0 | 0 | `imvt_n3a_af_set_face_roi` 的 enable gate；兩份封裝 profile 預設關閉這層 face refinement |
| +0x142c | 500 | 250 | highlight/luma plane 的比較 threshold；仍需 SDK 欄位單位 |
| +0x1430 | 9 | 9 | grid tile 總數必須大於此值，才套用上述 highlight mask 判斷 |

`zcam_e2f6/out/rootfs/usr/local/share/script/pref.cfg:80-88` 另有封裝 defaults：`af.on=0`、`af.caf=0`、`af.area=1`、`af.caf_range=0`、`af.caf_sens=2`、`af.mode=1`、`af.live_caf=0`。這不能推出現在機身的 CAF 或 tracking 開關。

實際設定載入在 `zcam_e2f6/ghidra/rawsend.c:6907-6940`：range 0→normal、1→all、2→micro；CAF sensitivity 外部 3→內部 0、1→2、其他→1；ROI 位置存千分比、讀回除 1000。`rawsend.c:7005-7017` 分別處理 `sys.nnie.on` 與 `sys.nnie.af.on`，inference 執行與送 ROI 給 AF 是兩個開關。

## AI tracking 接 AF：可借鑑 ROI 契約，不可直接移植加速器

已追到 `FUN_007e9010`→`imvt_tracker_run @ 0x00d31910`→`imvt_tracking_process`→（AF ROI gate）`imvt_nnie_af_update_af_and_face @ 0x007eaab8`。`imvt_tracker_init @ 0x00d31bb0` 使用 YOLO2 helpers，416×416 input、13×13 grid、5 anchors；run 透過 `HI_MPI_SVP_NNIE_Forward/Query` 並操作 MMZ/cache flush。這依賴 HiSilicon NNIE，不能把 `.wk` 當作 fp/AAT 可直接跑的模型。

資產確實存在：`zcam_e2f6/out/app_data/app_data/nnie/zcam_ai_tracker.wk`、`haarcascade_frontalface_alt2.xml`；存在不是本機當前執行證據。

已讀到的 ROI 行為：

1. `imvt_nnie_af_update_af_and_face` 選特定 detection record（class/id 欄位 2，次欄位 0；全部 class 語意尚未復原）；缺失的前 2 次沿用上一矩形，連續第 3 次呼叫 `imvt_af_lose_human_roi`。另收集 class 4，最多 5 個矩形給 `imvt_af_set_face_roi`。
2. `FUN_007ea850` 做面積相關 deadband：以 1280×720（921600）面積正規化，基準 edge tolerance 40；面積比例 <0.1 用 20、0.1–<0.3 用 40、0.3–<0.7 用 52、≥0.7 用 80。新舊矩形面積比至少 0.9 且各邊在 tolerance 內時保留舊框；另有三邊完全相同分支。這是 hysteresis，不是時間平均。
3. 上述常數 VA：`0x007eaa00` f32=921600，`0x007eaa08/10/18/20/28` f64=0.1/0.3/0.7/1.3/0.9；基準 int40 在 `0x01041e8c`。這些是 binary default，可被運行期修改，不能當作 fp 合理預設。
4. `FUN_007eaa30` 比較 16-byte cached rectangle；未改變不重送 AF ROI，改變則 x/w 除 1280、y/h 除 720。`imvt_n3a_af_set_face_roi @ 0x00888548` 另有 running、profile gate、mode 3 條件，並挑符合 coarse ROI 條件的較大 face；lost-face/human 路徑可恢復 fallback ROI。

這些能支持 AAT 的「有效框、穩定框、遺失、fallback」契約。不能由 AI 偵測+CAF 的串接推出移動主體可可靠追焦，也不能由 ROI 面積條件推出它擁有準確單目距離。

## fp 可拿走的研究問題與下一個 bounded 工作

優先不是重寫 Z CAM CAF，而是把 fp 機內 DFD 輔助與 AAT 的可驗收條件說清楚：

1. **時序先於方向。** 在 fp 自己的 trace 中對齊 stats generation、曝光、ROI generation、lens actual position、命令完成／反向；比較反向後不同 discard/settle gate 的錯誤方向率。Z CAM 的一筆丟棄只是對照策略，不能跳過 fp 的位置／曝光對齊。
2. **ROI 穩定性和焦點可信度分開。** AAT 提供 identity、timestamp、座標域、ROI generation、lost 狀態；機內 stats consumer 只在一致 generation 上比較 FV。用有／無 ROI deadband、lost fallback 做離線消融，量 background lock、重觸發、恢復時間；不要先把 40px／3 次沿用搬過來。
3. **DFD 輔助只提案，CDAF 驗證。** 如果 fp 校準後的 H/L 或其他特徵能給可信方向／步距，讓它提供有信心門檻的 seed；低信心或亮度/ROI突變時退回可控搜尋。Z CAM 目前提供的是 contrast 驗證／失敗控制參考，沒有提供已驗證的 fp DFD 模型。
4. **反覆抽動要獨立量。** 同時記錄首次可用焦點時間、反向次數、總行程、撞界、錯誤重觸發、NG 率、失去目標後恢復時間。用窄峰、平坦低紋理、AE跳變、ROI移動／遮擋、相機移動、主體往返序列回放；一個最高 FV 或最後停住不能驗收 CAF。

下一次針對 Z CAM 的最小逆向包可限定為：

- **ISP 欄位確名：** 輸入本 ELF、`0x00e2fd10` 的 `0x10c` config、`0x00885cb0`/`0x00885eb0`、相符 Hi3559AV100 SDK headers。輸出 12-byte tile 原欄位名、兩個 FV filter/band、luma/highlight units、WDR branch 含義。沒有 headers 就保留 plane1/2/3/4 名稱。
- **搜尋／停住的狀態表：** 輸入兩份 roots、CAF `0x00d3adc8`、helpers `0x00d3a608/650/770` 和 EF adapter `0x00893470`。輸出每個 state 的進出、retry budget增減、stop/drive契約與 position時間；優先驗明 NG→monitor→retrigger 是否存在可無限重啟序列。先靜態／離線回放，不操作機身。
- **AAT 最小比較：** 輸入 `0x007ea850/aa30/aab8`、`0x00888548`、fp 現有已授權取得的 ROI/FV/position telemetry；只比較 ROI穩定／遺失策略，保留 fp 原鏡頭與統計介面。沒有已對齊資料時，輸出 blocker，不能報方向準確率。

截至此頁，完成的是可讀演算法的入口、實際資料路徑、具體分支和參數定位。尚未完成 Z CAM 動態效能測試、全結構復原、fp 移植、DFD 校準，或 AAT 接管機內焦點的驗收。
