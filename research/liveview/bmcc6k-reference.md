# 對照組：BMCC 6K 的 Live View／Rec.709 色彩資料

2026-09-24；Blackmagic Cinema Camera 6K 韌體 10.2.2／f17.326200。本頁把 BMCC 研究接入 SIGMA fp 的 Live View 與 [rawview 實作](../../projects/rawview/README.md)，不將跨機型參數當成 fp 的實測或校準。

完整資料歸檔於 [BMCC 6K 研究入口](../../bmcc6k/README.md)。本次已解開外層 payload 和 colour-science datapack；核心應用仍受第二層保護。以下有資料結構、數值與文件支持，尚不是完整的執行呼叫圖。

## 兩種 Rec.709 路徑

| 項目 | 已確認的資料 | 對 fp 研究的用途 |
| --- | --- | --- |
| 內建 Video | BMCC 6K 專屬 profile → `BMDVideo_709` → Rec.709 色域＋gamma enum 1 的 ISO 曲線族 | 把工作色域、曲線與輸出目標分開記錄，不能將「709」視為單一 gamma |
| Film 加監看 LUT | Gen 5 Film／Blackmagic Wide Gamut → 33³ LUT、四面體內插 → Rec709／BT1886 | 作為有明確輸入定義的離線顯示轉換對照 |
| Extended Video | 內建 encoding 指 Blackmagic 色域；獨立的 Film→Extended Video LUT 卻宣告 Rec709／BT1886 | 相似名稱不保證相同處理；不能假定內建模式就是載入該 `.cube` |
| 監看與錄製 | display LUT 可按輸出控制；BRAW 的嵌入 LUT 與監看另有設定 | 繼續分別驗證監看外觀、RAW 像素和 metadata；BMCC 的分工不證明 fp context 已隔離 |

## 可重現的數值

- 已恢復 **91 條 ISO 對應曲線**。每條 4096 個 18-bit words 可還原成 6144 個 12-bit 樣本；全部單調，repack 與原始資料一致。
- mode 2 的 13 條 Film 曲線強烈符合官方 Gen 5 公式：候選分段步距 `[1,1,2,4,8,16]`，每條只擬合一個輸入比例，完整資料的最大誤差小於 0.587 code。這是模型擬合，並非硬體尋址或 bit-exact 證明。
- 本機有兩組校準矩陣、色溫數值及 nested coefficients；Blackmagic 工作色域座標與官方 Gen 5 參考吻合。校準矩陣、工作色域轉換與監看 LUT 是不同層。

以下是合成中性輸入經兩份原廠 LUT 的數值，不是實拍 LCD 亮度：

| 相對 18% 灰的曝光 | Film→Video | Film→Extended Video |
| --- | ---: | ---: |
| 0 EV | 0.405541 | 0.410959 |
| +2 EV | 0.676640 | 0.693109 |
| +4 EV | 0.913845 | 0.882605 |
| +6 EV | 0.985901 | 0.960827 |

兩份 LUT 的高光肩部不同。固定 R 輸入、改變 G／B 也會改變 R 輸出，直接證明跨通道映射；不是三條彼此獨立的 gamma 曲線。

## 接入 rawview 時的實際分工

1. **來源與校準仍以 fp 為準。** 先確認 LV RAW／線性 RGB 的格式、黑位、增益與色域。Blackmagic 的感測器校準矩陣、ISO 曲線和硬體封裝不直接寫進 fp。
2. **BMCC LUT 只接受它宣告的輸入。** 若要離線比較，先用 fp 自身校準把已確認來源轉成 Blackmagic Wide Gamut，再作 Gen 5 Film 編碼；不能將 fp Bayer、任意線性 RGB 或已處理預覽直接送入 LUT。
3. **保留跨通道測試。** fp 已確認的一／三條 1D tone 表及 LCD 16 點 gamma，不能單獨重現任意 3D LUT。其他色彩區塊能做到什麼，仍需由 fp 證據決定。
4. **比較相同尺度。** Z CAM 的中灰數值、BMCC LUT 的正規化碼值與 fp LCD 的顯示亮度不能直接互換；先固定線性曝光尺度、工作色域、display transfer 與訊號範圍。
5. **繼續先定位截斷。** LUT 的平滑肩部不能恢復上游已剪平的像素差異；來源驗證、第一個 clip 和監看 context 隔離，仍先於機內映射實作。

這次是研究與資料整合，沒有新增 fp 顯示轉換 patch、3D LUT runtime、SUP 或相機部署。`rawview/captures` 保持 fp 實測用途。

## 研究入口與證據

- [完整 Live View／Rec.709 報告與流程圖](../../bmcc6k/analysis-20260924/bmcc6k-liveview-rec709-20260924/README.md)
- [datapack 解碼、ISO 曲線與封裝](../../bmcc6k/analysis-20260924/bmcc6k-liveview-rec709-20260924/datapack/FINDINGS.md)
- [91 條曲線與逐項驗證資訊](../../bmcc6k/analysis-20260924/bmcc6k-liveview-rec709-20260924/datapack/unpacked_curves.json)
- [Gen 5 候選座標與公式比對](../../bmcc6k/analysis-20260924/bmcc6k-liveview-rec709-20260924/datapack/curve_axis_checks.json)
- [兩份 LUT 數值與內插分析](../../bmcc6k/analysis-20260924/bmcc6k-liveview-rec709-20260924/luts/README.md)
- [本機校準矩陣](../../bmcc6k/analysis-20260924/bmcc6k-liveview-rec709-20260924/controls/CAMERA_CALIBRATION.md)
- [獨立驗證結果](../../bmcc6k/analysis-20260924/bmcc6k-liveview-rec709-20260924/verification.json)
- [BRAW 輸出／CDNG 殘留檢查](../../bmcc6k/analysis-20260924/bmcc6k-braw-cdng-20260924/README.md)：控制與資產已定位，encoder／writer 尚未還原；沒有可信的可見 CDNG writer 證據，也不能排除受保護程式內仍有相關代碼。

比較對象：[SIGMA fp 研究總報告](README.md)、[Z CAM 對照](zcam-e2f6-reference.md)、[rawlive 規劃](../../projects/rawlive/README.md)。
