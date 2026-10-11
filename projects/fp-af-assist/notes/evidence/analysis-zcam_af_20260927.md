# Z CAM AF 離線反編譯存檔（2026-09-27）

原程式／證據目錄：[research/autofocus/analysis/zcam_af_20260927](../../../../research/autofocus/analysis/zcam_af_20260927/)。筆記已集中至 fp-af-assist；下文歷史結果與限制保留。

本目錄保存本次已完成的分析輸出，未修改反編譯 C。用途是重查呼叫／分支證據；不表示 Z CAM CAF 性能已驗收，也不是 fp 可編譯或部署的程式碼。

## 輸入與工具

- ELF：`/Users/dido/Developer.localized/SIGMAfp_re/zcam_e2f6/out/rootfs/usr/bin/imvt_camera`，來自 E2-F6 FW 1.0.13，ELF64 LE AArch64。
- ELF SHA-256：`5882b6c18a2fda4f95efa4d0877e6ce1b8b34b69c9200a450a9d564239896e39`。
- Ghidra **12.1.2 PUBLIC**，Temurin JDK **21.0.12**；本地工具在 `tools/ghidra/ghidra_12.1.2_PUBLIC`、`tools/jdk/Contents/Home`。
- 既有分析專案：`zcam_e2f6/ghidra/zcam.gpr` + `zcam.rep`，內部程式 `/imvt_camera`。重現依賴此專案的既有函式邊界／型別狀態；只從 ELF 重新自動分析不保證得到同樣 C。

## 保存內容

| 檔案 | 內容 |
|---|---|
| `zcam-af-core-20260927.c` | 62 個函式區塊；AF/FV/ROI/tracking 選定入口與一層直接 callee，保留 references |
| `zcam-af-input-20260927.c` | 16 個函式區塊；init、参数、NNIE、ISP helpers；不展開 callee |
| `zcam-af-extra-20260927.c` | 2 個函式區塊；原專案未建立 function 的 `0x00885eb0` 與 `0x00887c10` |
| `functions.tsv` | 80 個區塊／77 個唯一 VA；列出檔名、1-based 行號、ELF VA、函式名，重複項刻意保留 |
| `scripts/*.java` | 本次使用的 Ghidra 輸出腳本原樣保存 |
| `reproduce.sh` | 完整選擇 regex、depth 與三次產生命令；新輸出留在獨立暫存目錄 |
| `SHA256SUMS` | 保存的 C、Java、函式清單與 shell 指令的校驗值 |

## 最短重現方式

```bash
bash /Users/dido/Developer.localized/SIGMAfp_re/research/autofocus/analysis/zcam_af_20260927/reproduce.sh
```

腳本先檢查 ELF hash，複製整個 Ghidra 專案到新暫存目錄，再執行以下形式的命令；不觸碰原專案、不覆蓋本目錄的 C。`ZCAM_GHIDRA_DIR`、`ZCAM_JAVA_HOME` 可指定相容工具位置。

```text
analyzeHeadless <temporary-project-dir> zcam -process imvt_camera
  -readOnly -noanalysis -scriptPath <archive>/scripts
  -postScript DumpColorFunctions.java <output.c> <exact-regex> <depth>

analyzeHeadless <temporary-project-dir> zcam -process imvt_camera
  -readOnly -noanalysis -scriptPath <archive>/scripts
  -postScript ZcamAfExtra.java <output.c> 0x885eb0 0x887c10
```

`ZcamAfExtra` 只在暫存副本建立兩個 function；`-readOnly` 在程序結束時捨棄變更。core/input 的完整 regex 與 depth=1/0 已存於 shell 檔。core 展開 callee 的順序來自 Ghidra 的集合迭代，重跑的區塊順序／文字未必逐位元相同；請按函式 VA 比較內容。

## 限制與驗證

- C 是缺少原始型別／結構的反編譯結果；`undefined*`、參數次序、符號推定與浮點 ABI 不能直接當原始碼。重要判斷須回 ELF 指令核對。
- 只涵蓋已選函式，並非整份 AF 韌體；沒有執行韌體、相機測試、fp 移植或新算法研究。
- 保存時確認三份 C 與本次暫存輸出逐 byte 相同，函式清單行號／數量吻合；shell 通過語法檢查。本次存檔未重新跑完整 Ghidra。
- 研究結論與證據邊界見 [ZCAM_AF_REFERENCE_2026-09-27.md](/Users/dido/Developer.localized/SIGMAfp_re/projects/fp-af-assist/notes/research/ZCAM_AF_REFERENCE_2026-09-27.md)。
