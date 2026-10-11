#!/usr/bin/env bash
# Offline only. Keep the original Ghidra project and archived C unchanged.
set -euo pipefail
zcam_archive_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
zcam_repo_dir="$(cd "$zcam_archive_dir/../../../.." && pwd)"
zcam_ghidra_dir="${ZCAM_GHIDRA_DIR:-$zcam_repo_dir/tools/ghidra/ghidra_12.1.2_PUBLIC}"
zcam_java_dir="${ZCAM_JAVA_HOME:-$zcam_repo_dir/tools/jdk/Contents/Home}"
zcam_binary="$zcam_repo_dir/zcam_e2f6/out/rootfs/usr/bin/imvt_camera"
zcam_expected_hash='5882b6c18a2fda4f95efa4d0877e6ce1b8b34b69c9200a450a9d564239896e39'
zcam_actual_hash="$(shasum -a 256 "$zcam_binary")"
if [[ "${zcam_actual_hash%% *}" != "$zcam_expected_hash" ]]; then
  echo 'ELF hash differs from the audited input; stopping.' >&2
  exit 1
fi
zcam_work_dir="$(mktemp -d "${TMPDIR:-/tmp}/zcam-af-reproduce.XXXXXX")"
mkdir -p "$zcam_work_dir/output"
cp "$zcam_repo_dir/zcam_e2f6/ghidra/zcam.gpr" "$zcam_work_dir/zcam.gpr"
cp -R "$zcam_repo_dir/zcam_e2f6/ghidra/zcam.rep" "$zcam_work_dir/zcam.rep"
zcam_core_pattern='^(n3a_af_(caf_task_run|saf_task_run|parse_fv|update|lum_parse|parse_luma_highlight_and_contrast|parase_fv_get_trend_info|parase_fv_get_changed_percent_info|fv_set_final_focus_point|fv_set_down_hill_focus_point|set_roi)|imvt_isp_af_(get_res|set_roi|set_attr|init)|imvt_n3a_af_(set_face_roi|lose_face_roi|lose_human_roi)|imvt_tracker_(run|init)|imvt_nnie_af_.*|imvt_cam_adj_register_af_params)$'
zcam_input_pattern='^(imvt_n3a_af_init|n3a_af_.*set_params|imvt_nnie_enable_af_roi|imvt_af_init|FUN_00887.*|FUN_00885.*|FUN_008883d0|FUN_007e9010|FUN_007e9a50)$'
zcam_run() {
  local zcam_label="$1"
  shift
  JAVA_HOME="$zcam_java_dir" \
  JAVA_TOOL_OPTIONS="-Duser.home=$zcam_work_dir" \
    "$zcam_ghidra_dir/support/analyzeHeadless" "$zcam_work_dir" zcam \
    -process imvt_camera -readOnly -noanalysis \
    -scriptPath "$zcam_archive_dir/scripts" \
    -postScript "$@" \
    -log "$zcam_work_dir/output/$zcam_label.log" \
    -scriptlog "$zcam_work_dir/output/$zcam_label-script.log"
}
zcam_run core DumpColorFunctions.java "$zcam_work_dir/output/zcam-af-core-20260927.c" "$zcam_core_pattern" 1
zcam_run input DumpColorFunctions.java "$zcam_work_dir/output/zcam-af-input-20260927.c" "$zcam_input_pattern" 0
zcam_run extra ZcamAfExtra.java "$zcam_work_dir/output/zcam-af-extra-20260927.c" 0x885eb0 0x887c10
printf 'Reproduced files and logs: %s\n' "$zcam_work_dir/output"
