/* FUNCTION imvt_nnie_af_update_af_and_face @ 007eaab8 body=[[007eaab8, 007eaaf3] [007eaaf8, 007eac77]]
REF Entry Point EXTERNAL caller=NONE
REF 00f01094 INDIRECTION caller=NONE
REF 00f64360 DATA caller=NONE
REF 007e9314 UNCONDITIONAL_CALL caller=FUN_007e9010@007e9010
*/

void imvt_nnie_af_update_af_and_face(short *param_1)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  ulong uVar7;
  short *psVar8;
  ulong uVar9;
  undefined8 extraout_x13;
  undefined8 local_68;
  undefined8 local_60;
  float local_58 [20];
  long local_8;
  
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  if (0 < param_1[4]) {
    iVar6 = 0;
    psVar8 = param_1;
    do {
      if ((psVar8[10] == 2) && (psVar8[0xb] == 0)) {
        DAT_01041e88 = 0;
        local_68 = CONCAT44((int)param_1[(long)iVar6 * 10 + 0xf],
                            (int)param_1[(long)iVar6 * 10 + 0xe]);
        local_60 = CONCAT44((int)param_1[(long)iVar6 * 10 + 0x11],
                            (int)param_1[(long)iVar6 * 10 + 0x10]);
        goto LAB_007eab48;
      }
      iVar6 = iVar6 + 1;
      psVar8 = psVar8 + 10;
    } while (iVar6 != param_1[4]);
  }
  DAT_01041e88 = DAT_01041e88 + 1;
  if (DAT_01041e88 < 3) {
    local_68 = DAT_01041e90;
    local_60 = DAT_01041e98;
LAB_007eab48:
    FUN_007ea850(&local_68);
    FUN_007eaa30(extraout_x13);
    sVar2 = param_1[4];
    if (sVar2 < 1) {
      uVar7 = 0;
    }
    else {
      psVar8 = param_1 + 10;
      uVar7 = 0;
      do {
        if (*psVar8 == 4) {
          uVar9 = -(uVar7 >> 0x1f) & 0xfffffff000000000 | uVar7 << 4;
          sVar3 = psVar8[5];
          uVar1 = (int)uVar7 + 1;
          uVar7 = (ulong)uVar1;
          sVar4 = psVar8[6];
          sVar5 = psVar8[7];
          *(float *)((long)local_58 + uVar9) = (float)(int)psVar8[4] / DAT_007eac78;
          *(float *)((long)local_58 + uVar9 + 4) = (float)(int)sVar3 / DAT_007eac7c;
          *(float *)((long)local_58 + uVar9 + 8) = (float)(int)sVar4 / DAT_007eac78;
          *(float *)((long)local_58 + uVar9 + 0xc) = (float)(int)sVar5 / DAT_007eac7c;
          if (4 < (int)uVar1) break;
        }
        psVar8 = psVar8 + 10;
      } while (psVar8 != param_1 + (ulong)((int)sVar2 - 1) * 10 + 0x14);
    }
    imvt_af_set_face_roi(local_58,uVar7);
  }
  else {
    imvt_af_lose_human_roi();
  }
  if (local_8 == *(long *)PTR___stack_chk_guard_010398b8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(0);
}



/* FUNCTION imvt_nnie_af_handle_detection @ 007eac80 body=[[007eac80, 007ead9b] [007eada0, 007eadc3] [007eadc8, 007eae03]]
REF Entry Point EXTERNAL caller=NONE
REF 00f0109c INDIRECTION caller=NONE
REF 00f64390 DATA caller=NONE
*/

void imvt_nnie_af_handle_detection(long param_1,long param_2)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  bool bVar9;
  long lVar10;
  int iVar11;
  bool bVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined8 extraout_x13;
  undefined8 local_18;
  undefined8 local_10;
  long local_8;
  
  iVar14 = 0x1aa;
  iVar13 = 0xf0;
  local_18 = 0xf0000001aa;
  local_10 = 0xf0000001aa;
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  iVar11 = 0;
  if (*(short *)(param_1 + 8) < 1) {
    DAT_01041e88 = DAT_01041e88 + 1;
    if (DAT_01041e88 < 3) {
      local_18 = CONCAT44(DAT_01041e90._4_4_,(undefined4)DAT_01041e90);
      local_10 = CONCAT44(DAT_01041e98._4_4_,(undefined4)DAT_01041e98);
    }
  }
  else {
    psVar8 = (short *)(param_1 + 0x1c);
    iVar15 = 0xf0;
    iVar16 = 0x1aa;
    bVar12 = false;
    bVar2 = false;
    bVar1 = false;
    bVar9 = false;
    do {
      if (iVar11 == 0) {
        iVar6 = (int)psVar8[3];
        iVar7 = (int)psVar8[2];
LAB_007eacec:
        iVar16 = iVar7;
        iVar15 = iVar6;
        bVar12 = true;
        iVar14 = (int)*psVar8;
        iVar13 = (int)psVar8[1];
        bVar2 = true;
        bVar1 = true;
        bVar9 = true;
      }
      else {
        iVar6 = (int)psVar8[3];
        iVar7 = (int)psVar8[2];
        if (iVar16 * iVar15 < (int)psVar8[2] * (int)psVar8[3]) goto LAB_007eacec;
      }
      iVar11 = iVar11 + 1;
      psVar8 = psVar8 + 10;
    } while (iVar11 != *(short *)(param_1 + 8));
    if (bVar9) {
      local_10 = CONCAT44(0xf0,iVar16);
    }
    if (bVar1) {
      local_10 = CONCAT44(iVar15,(undefined4)local_10);
    }
    if (bVar2) {
      local_18 = CONCAT44(0xf0,iVar14);
    }
    if (bVar12) {
      local_18 = CONCAT44(iVar13,(undefined4)local_18);
    }
    DAT_01041e88 = 0;
  }
  FUN_007ea850(&local_18);
  FUN_007eaa30(extraout_x13);
  lVar10 = *(long *)PTR___stack_chk_guard_010398b8;
  *(undefined2 *)(param_2 + 0x1a) = 0;
  uVar5 = DAT_01041e98._4_4_;
  uVar4 = (undefined4)DAT_01041e98;
  uVar3 = DAT_01041e90._4_4_;
  *(short *)(param_2 + 0x1c) = (short)(undefined4)DAT_01041e90;
  *(undefined2 *)(param_2 + 8) = 1;
  *(short *)(param_2 + 0x1e) = (short)uVar3;
  *(short *)(param_2 + 0x20) = (short)uVar4;
  *(short *)(param_2 + 0x22) = (short)uVar5;
  if (local_8 != lVar10) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  return;
}



/* FUNCTION imvt_isp_af_set_roi @ 008866d8 body=[[008866d8, 008868f3] [008868f8, 00886903] [00886908, 00886987]]
REF Entry Point EXTERNAL caller=NONE
REF 00886a90 UNCONDITIONAL_CALL caller=imvt_isp_af_set_attr@008869e8
REF 00887774 UNCONDITIONAL_CALL caller=FUN_00887708@00887708
*/

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void imvt_isp_af_set_roi(float param_1,float param_2,float param_3,float param_4,int param_5)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float local_18;
  float fStack_14;
  float local_10;
  float fStack_c;
  long local_8;
  
  fVar15 = (float)DAT_045a939c;
  fVar12 = (float)DAT_045a93a0;
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  fVar10 = param_1 * fVar15;
  fVar9 = param_2 * fVar12;
  fVar11 = DAT_00886988;
  if (DAT_00886990 <= (double)param_5) {
    fVar11 = (float)param_5;
  }
  if (fVar10 < 0.0) {
    fVar10 = 0.0;
  }
  if (fVar9 < 0.0) {
    fVar9 = 0.0;
  }
  fVar13 = param_3 * fVar15;
  if (param_3 * fVar15 < fVar11) {
    fVar13 = fVar11;
  }
  if (fVar13 < (float)(param_5 * 3)) {
    fVar13 = (float)(param_5 * 3);
  }
  fVar14 = param_4 * fVar12;
  if (param_4 * fVar12 < fVar11) {
    fVar14 = fVar11;
  }
  if ((float)(DAT_045a939c + -8) < fVar10 + fVar13) {
    fVar10 = (fVar15 - fVar13) - 8.0;
  }
  if ((float)(DAT_045a93a0 + -8) < fVar9 + fVar14) {
    fVar9 = (fVar12 - fVar14) - 8.0;
  }
  uVar7 = (uint)fVar10;
  uVar5 = (uint)fVar9;
  uVar8 = (uint)fVar13;
  uVar3 = uVar7 + 3;
  if (-1 < (int)uVar7) {
    uVar3 = uVar7;
  }
  uVar7 = uVar5 + 3;
  if (-1 < (int)uVar5) {
    uVar7 = uVar5;
  }
  uVar5 = uVar8 + 7;
  if (-1 < (int)uVar8) {
    uVar5 = uVar8;
  }
  local_10 = (float)(int)(uVar5 & 0xfffffff8);
  local_18 = (float)(int)(uVar3 & 0xfffffffc);
  fStack_14 = (float)(int)(uVar7 & 0xfffffffc);
  fStack_c = (float)(int)((int)fVar14 - ((int)fVar14 >> 0x1f) & 0xfffffffe);
  DAT_045a93b8 = param_5;
  DAT_045a97d8 = param_1;
  DAT_045a97dc = param_2;
  DAT_045a97e0 = param_3;
  DAT_045a97e4 = param_4;
  if (((((local_10 < DAT_00886988) || (fStack_c < DAT_00886988)) || (local_18 < 0.0)) ||
      ((fStack_14 < 0.0 || (local_10 < 0.0)))) || (fStack_c < 0.0)) goto LAB_0088688c;
  pthread_mutex_lock((pthread_mutex_t *)&DAT_045a97e8);
  iVar4 = memcmp(&DAT_045a97c8,&local_18,0x10);
  if ((iVar4 != 0) || (DAT_045a93a8 != 0)) {
    iVar4 = (int)(fVar13 / (float)DAT_045a93b8);
    iVar6 = (int)(fVar14 / (float)DAT_045a93b8);
    if (iVar4 < 0x12) {
      DAT_045a93b0 = (iVar4 + 1U & 0xfffffffe) - 1;
      bVar1 = DAT_045a93b0 < 1;
      if (iVar6 < 0x10) goto LAB_00886924;
      bVar2 = false;
      DAT_045a93b4 = 0xf;
LAB_00886938:
      if (bVar1 || bVar2) {
        DAT_045a93b0 = 1;
        DAT_045a93b4 = 1;
      }
    }
    else {
      DAT_045a93b0 = 0x11;
      if (iVar6 < 0x10) {
        bVar1 = false;
LAB_00886924:
        DAT_045a93b4 = (iVar6 + 1U & 0xfffffffe) - 1;
        bVar2 = DAT_045a93b4 < 1;
        goto LAB_00886938;
      }
      DAT_045a93b0 = 0x11;
      DAT_045a93b4 = 0xf;
    }
    _DAT_045a97c8 = CONCAT44(fStack_14,local_18);
    _DAT_045a97d0 = CONCAT44(fStack_c,local_10);
    DAT_045a93a8 = 1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_045a97e8);
LAB_0088688c:
  if (local_8 == *(long *)PTR___stack_chk_guard_010398b8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(0);
}



/* FUNCTION imvt_isp_af_set_attr @ 008869e8 body=[[008869e8, 00886a43] [00886a48, 00886ae7]]
REF Entry Point EXTERNAL caller=NONE
REF 008791d4 UNCONDITIONAL_CALL caller=imvt_cam_liveview_start@00879040
*/

void imvt_isp_af_set_attr(undefined8 param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  long local_8;
  
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  if (param_2 == (undefined8 *)0x0) {
    imvt_printf(0,"[isp_af] null point!!\n");
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    if (DAT_045a9390 != 0) {
      iVar2 = HI_MPI_ISP_GetPubAttr(0,&local_30);
      if (iVar2 == 0) {
        *param_2 = local_30;
        param_2[1] = uStack_28;
        param_2[2] = local_20;
        param_2[3] = uStack_18;
        param_2[4] = local_10;
      }
      else {
        imvt_printf(0,"[isp_af] HI_MPI_ISP_GetPubAttr failed 0x%x\n",iVar2);
      }
      DAT_045a9820 = *(undefined4 *)(param_2 + 4);
      DAT_045a939c = *(undefined4 *)(param_2 + 1);
      DAT_045a93a0 = *(undefined4 *)((long)param_2 + 0xc);
      imvt_isp_af_set_roi(DAT_045a97d8,DAT_045a97dc,DAT_045a97e0,DAT_045a97e4,DAT_045a93b8);
      FUN_00885cb0(DAT_045a97c8,DAT_045a97cc,DAT_045a97d0,DAT_045a97d4,DAT_045a93b0,DAT_045a93b4);
      uVar1 = 0;
    }
  }
  if (local_8 == *(long *)PTR___stack_chk_guard_010398b8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}



/* FUNCTION imvt_isp_af_get_res @ 00886ae8 body=[[00886ae8, 00886b03]]
REF Entry Point EXTERNAL caller=NONE
REF 008878e0 UNCONDITIONAL_CALL caller=FUN_00887840@00887840
REF 00889f74 UNCONDITIONAL_CALL caller=imvt_n3a_af_tof_dump_depth@00889f18
REF 00889700 UNCONDITIONAL_CALL caller=FUN_00889698@00889698
*/

void imvt_isp_af_get_res(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = DAT_045a939c;
  *param_2 = DAT_045a93a0;
  return;
}



/* FUNCTION imvt_isp_af_init @ 00886be8 body=[[00886be8, 00886d0f]]
REF Entry Point EXTERNAL caller=NONE
REF 007308ec UNCONDITIONAL_CALL caller=imvt_af_init@007308c0
*/

void imvt_isp_af_init(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 auStack_30 [8];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_10;
  long local_8;
  
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  iVar2 = HI_MPI_ISP_GetPubAttr(0,auStack_30,PTR___stack_chk_guard_010398b8,0);
  if (iVar2 != 0) {
    imvt_printf(0,"[isp_af] HI_MPI_ISP_GetPubAttr failed 0x%x\n",iVar2);
  }
  DAT_045a9390 = 1;
  DAT_045a939c = local_28;
  DAT_045a93a0 = uStack_24;
  DAT_045a9820 = local_10;
  DAT_045a97c8 = 0;
  DAT_045a97cc = 0;
  DAT_045a9394 = 0;
  DAT_045a9398 = 0x1e;
  DAT_045a93a8 = 0;
  DAT_045a93ac = 0;
  DAT_045a93b0 = 0x11;
  DAT_045a93b8 = 200;
  DAT_045a97c0 = 0;
  DAT_045a93b4 = 0xf;
  DAT_045a97d0 = DAT_00886d10;
  DAT_045a97d4 = DAT_00886d10;
  if (DAT_045a97b8 != (void *)0x0) {
    memcpy(&DAT_01067590,DAT_045a97b8,0x10c);
  }
  pthread_mutex_init((pthread_mutex_t *)&DAT_045a97e8,(pthread_mutexattr_t *)0x0);
  puVar3 = &DAT_045a8f90;
  do {
    puVar1 = puVar3 + 0x11;
    puVar4 = puVar3;
    do {
      puVar3 = puVar4 + 1;
      *puVar4 = 1;
      puVar4 = puVar3;
    } while (puVar3 != puVar1);
  } while (puVar3 != (undefined4 *)&DAT_045a938c);
  if (local_8 == *(long *)PTR___stack_chk_guard_010398b8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar2);
}



/* FUNCTION imvt_n3a_af_set_face_roi @ 00888548 body=[[00888548, 0088859b] [008885a0, 008885e3] [008885e8, 0088870f]]
REF Entry Point EXTERNAL caller=NONE
REF 00730948 UNCONDITIONAL_JUMP caller=imvt_af_set_face_roi@00730948
*/

undefined8 imvt_n3a_af_set_face_roi(float *param_1,uint param_2)

{
  int iVar1;
  float *pfVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  if ((DAT_045a98ac == 0) || (DAT_045a9978 == 0)) {
    imvt_printf(0,"[af] af is not running!!\n");
    return 0xffffffff;
  }
  if (*(int *)(DAT_045a9978 + 0x1418) == 0) {
    return 0;
  }
  fVar10 = *(float *)(DAT_045a9978 + 0x141c);
  iVar1 = n3a_af_get_af_mode(0);
  if ((iVar1 == 3) && (0 < (int)param_2)) {
    uVar5 = 0;
    uVar4 = 0xffffffff;
    iVar1 = 0;
    pfVar2 = param_1;
    do {
      fVar7 = pfVar2[2];
      if (((float)DAT_045a98e0 < *pfVar2 + fVar7) &&
         (*pfVar2 < (float)DAT_045a98e8 + (float)DAT_045a98e0)) {
        fVar6 = pfVar2[1];
        fVar9 = pfVar2[3];
        if ((DAT_045a98e0._4_4_ < fVar6 + fVar9) &&
           (((fVar6 < DAT_045a98e0._4_4_ + DAT_045a98e0._4_4_ &&
             (fVar6 <= DAT_045a98e0._4_4_ + DAT_045a98e8._4_4_ * fVar10)) &&
            (fVar6 + fVar9 < DAT_045a98e0._4_4_ + DAT_045a98e8._4_4_)))) {
          iVar1 = (int)uVar4;
          if (iVar1 == -1) {
            uVar4 = (ulong)uVar5;
            fVar6 = fVar7;
            fVar8 = fVar9;
          }
          else {
            fVar6 = param_1[(long)iVar1 * 4 + 2];
            fVar8 = param_1[(long)iVar1 * 4 + 3];
          }
          iVar1 = 1;
          uVar3 = uVar5;
          if (fVar7 * fVar9 <= fVar6 * fVar8) {
            uVar3 = (uint)uVar4;
          }
          uVar4 = (ulong)uVar3;
        }
      }
      uVar5 = uVar5 + 1;
      pfVar2 = pfVar2 + 4;
    } while (param_2 != uVar5);
    if (iVar1 != 0) {
      uVar4 = -(uVar4 >> 0x1f) & 0xfffffff000000000 | uVar4 << 4;
      DAT_045a98f0 = *(undefined4 *)((long)param_1 + uVar4);
      DAT_045a98f4 = *(undefined4 *)((long)param_1 + uVar4 + 4);
      DAT_045a98f8 = *(undefined4 *)((long)param_1 + uVar4 + 8);
      DAT_045a98fc = *(undefined4 *)((long)param_1 + uVar4 + 0xc);
      FUN_00887708(DAT_045a98f0,DAT_045a98f4,DAT_045a98f8,DAT_045a98fc);
      DAT_045a9908 = iVar1;
      return 0;
    }
  }
  if (DAT_045a9908 == 1) {
    FUN_008883d0();
  }
  DAT_045a9908 = 0;
  return 0;
}



/* FUNCTION imvt_n3a_af_lose_face_roi @ 00888710 body=[[00888710, 00888733] [00888738, 0088873f]]
REF Entry Point EXTERNAL caller=NONE
REF 00730950 UNCONDITIONAL_JUMP caller=imvt_af_lose_face_roi@00730950
*/

void imvt_n3a_af_lose_face_roi(void)

{
  if (((DAT_045a98ac != 0) && (DAT_045a9978 != 0)) && (DAT_045a9908 != 0)) {
    DAT_045a9908 = 0;
    FUN_008883d0();
    return;
  }
  return;
}



/* FUNCTION imvt_n3a_af_lose_human_roi @ 00888740 body=[[00888740, 008887df]]
REF Entry Point EXTERNAL caller=NONE
REF 008892b8 UNCONDITIONAL_CALL caller=imvt_n3a_af_set_mode@00889220
REF 00730958 UNCONDITIONAL_JUMP caller=imvt_af_lose_human_roi@00730958
REF 0088884c UNCONDITIONAL_CALL caller=FUN_008887e0@008887e0
*/

void imvt_n3a_af_lose_human_roi(void)

{
  long lVar1;
  int iVar2;
  
  lVar1 = DAT_045a9978;
  if ((DAT_045a98ac != 0) && (DAT_045a9978 != 0)) {
    iVar2 = n3a_af_get_af_mode();
    pthread_mutex_lock((pthread_mutex_t *)&DAT_045a9988);
    lVar1 = lVar1 + (long)iVar2 * 0x220;
    DAT_045a98e0._0_4_ = *(undefined4 *)(lVar1 + 0x6f0);
    DAT_045a98e0._4_4_ = *(undefined4 *)(lVar1 + 0x6f4);
    DAT_045a98e8._0_4_ = *(undefined4 *)(lVar1 + 0x6f8);
    DAT_045a98e8._4_4_ = *(undefined4 *)(lVar1 + 0x6fc);
    FUN_00887708((undefined4)DAT_045a98e0,DAT_045a98e0._4_4_,(undefined4)DAT_045a98e8,
                 DAT_045a98e8._4_4_);
    DAT_045a98c8 = 0;
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_045a9988);
    n3a_af_lose_human(1);
    return;
  }
  return;
}



/* FUNCTION imvt_cam_adj_register_af_params @ 00a69eb0 body=[[00a69eb0, 00a69f17]]
REF Entry Point EXTERNAL caller=NONE
REF 00f118a4 INDIRECTION caller=NONE
REF 00fbefc8 DATA caller=NONE
REF 007308d8 UNCONDITIONAL_CALL caller=imvt_af_init@007308c0
*/

ulong imvt_cam_adj_register_af_params(int param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if (param_1 == 1) {
    uVar2 = imvt_adj_get_af_isp_params();
    uVar3 = imvt_af_register_params(&DAT_01014750,uVar2);
    return uVar3;
  }
  if (param_1 != 0) {
    uVar2 = imvt_adj_get_af_isp_params();
    imvt_af_register_params(&DAT_01015ba8,uVar2);
    uVar1 = puts("adj_register_af_params error unknow lens type");
    return (ulong)uVar1;
  }
  uVar2 = imvt_adj_get_af_isp_params();
  uVar3 = imvt_af_register_params(&DAT_01015ba8,uVar2);
  return uVar3;
}



/* FUNCTION imvt_tracker_run @ 00d31910 body=[[00d31910, 00d319cb] [00d319d0, 00d31abb] [00d31ac0, 00d31b33]]
REF Entry Point EXTERNAL caller=NONE
REF 007e90c4 UNCONDITIONAL_CALL caller=FUN_007e9010@007e9010
*/

undefined8 imvt_tracker_run(long param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  byte *pbVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar4 = DAT_047b58b8;
  DAT_047b2480 = *(undefined8 *)(param_1 + 0x78);
  DAT_047b2478 = *(undefined8 *)(param_1 + 0x90);
  DAT_047b2474 = *(undefined4 *)(param_1 + 0x2c);
  local_4 = 0;
  local_8 = 0;
  HI_MPI_SYS_MmzFlushCache(DAT_047b5498,DAT_047b54a0,DAT_047b54a8);
  iVar2 = HI_MPI_SVP_NNIE_Forward
                    (&local_4,&DAT_047b2470,DAT_047b23f8,&DAT_047b2770,&DAT_047b5470,iVar4);
  if (iVar2 == 0) {
    iVar2 = 0;
    if (iVar4 != 0) {
      while (iVar2 = HI_MPI_SVP_NNIE_Query(DAT_047b547c,local_4,&local_8,1), iVar2 == -0x5fcc7fbf) {
        usleep(DAT_047b58bc);
        imvt_printf(1,"[imvt_yolo] HI_MPI_SVP_NNIE_Query Query timeout!\n");
      }
    }
    local_8 = 0;
    if (DAT_047b2770 == 5) {
      iVar4 = 0;
      if (DAT_047b2788 != 0) {
        lVar3 = 0;
        iVar4 = 0;
        do {
          pbVar1 = (byte *)(lVar3 + DAT_047b2778);
          lVar3 = lVar3 + 1;
          iVar4 = iVar4 + (uint)*pbVar1;
        } while ((uint)lVar3 < DAT_047b2788);
      }
      HI_MPI_SYS_MmzFlushCache(DAT_047b2780,DAT_047b2778,iVar4 * DAT_047b2774);
    }
    else if (DAT_047b5474 != 0) {
      uVar6 = 0;
      piVar5 = &DAT_047b2774;
      do {
        uVar6 = uVar6 + 1;
        HI_MPI_SYS_MmzFlushCache
                  (*(undefined8 *)(piVar5 + 3),*(undefined8 *)(piVar5 + 1),
                   piVar5[5] * piVar5[9] * piVar5[8] * *piVar5);
        piVar5 = piVar5 + 0xc;
      } while (uVar6 < DAT_047b5474);
    }
    if (iVar2 == 0) goto LAB_00d31a6c;
  }
  else {
    imvt_printf(0,"[imvt_yolo] HI_MPI_SVP_NNIE_Forward FAILED!\n");
    iVar2 = -1;
  }
  imvt_printf(0,"[imvt_yolo] imvt_yolo_nnie_forward failed! %x\n",iVar2);
LAB_00d31a6c:
  lVar3 = DAT_047b2778;
  *param_4 = param_2;
  param_4[1] = param_3;
  FUN_00d316a0(lVar3,param_4,0);
  memcpy(&DAT_047aea88,param_4,0x2ac);
  DAT_047b58b0 = lVar3;
  return 0;
}



/* FUNCTION imvt_tracker_init @ 00d31bb0 body=[[00d31bb0, 00d31d53] [00d31d58, 00d31dc3] [00d31dc8, 00d31dfb] [00d31e00, 00d31e23]]
REF Entry Point EXTERNAL caller=NONE
REF 007e9ac0 UNCONDITIONAL_CALL caller=FUN_007e9a50@007e9a50
*/

undefined8 imvt_tracker_init(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  uStack_8 = 0;
  memset(&DAT_047ae950,0,0x6f70);
  DAT_047ae97c = DAT_00d31e24;
  DAT_047ae980 = DAT_00d31e28;
  DAT_047ae984 = DAT_00d31e2c;
  DAT_047ae988 = DAT_00d31e30;
  DAT_047b58b8 = 1;
  DAT_047b58bc = 1000;
  DAT_047ae970 = 0xd;
  DAT_047ae974 = 0xd;
  DAT_047ae968 = 1;
  DAT_047ae96c = 5;
  DAT_047ae98c = DAT_00d31e34;
  DAT_047ae990 = DAT_00d31e38;
  DAT_047ae994 = DAT_00d31e3c;
  DAT_047ae998 = DAT_00d31e40;
  DAT_047ae9cc = 0x50;
  DAT_047ae9d0 = 1;
  DAT_047ae9d4 = 4;
  DAT_047ae9e0 = 0x1a0;
  DAT_047ae9e4 = 0x1a0;
  DAT_047ae99c = DAT_00d31e44;
  DAT_047ae9a0 = DAT_00d31e48;
  local_a8 = CONCAT44(local_a8._4_4_,1);
  DAT_047ae9ec = 0x11891;
  DAT_047ae960 = imvt_yolo2_get_mmz_memory_size_c(&DAT_047ae968);
  if ((int)DAT_047ae960 < 1) {
    DAT_047ae950 = 0;
    uVar2 = 0xffffffff;
    DAT_047ae958 = (void *)0x0;
  }
  else {
    DAT_047ae960 = DAT_047ae960 + 0xf & 0xfffffff0;
    iVar1 = HI_MPI_SYS_MmzAlloc_Cached(&DAT_047ae950,&DAT_047ae958,"IMVT_YOLO_INIT",0,DAT_047ae960);
    if (iVar1 != 0) {
      imvt_printf(0,"[imvt_yolo] %s Malloc memory failed!\n","imvt_yolo_alloc_mmz_cache");
      return 0xffffffff;
    }
    memset(DAT_047ae958,0,(long)(int)DAT_047ae960);
    HI_MPI_SYS_MmzFlushCache(DAT_047ae950,DAT_047ae958,DAT_047ae960);
    iVar1 = imvt_yolo2_init_c(&DAT_047ae968,DAT_047ae958,DAT_047ae960,0x1000);
    if (iVar1 == 0) {
      iVar1 = imvt_nnie_model_load(param_1,&DAT_047aed38);
      if (iVar1 == 0) {
        DAT_047b23f8 = &DAT_047aed38;
        iVar1 = imvt_nnie_param_init(&local_b0,&DAT_047b23f8);
        uVar2 = 0;
        if (iVar1 != 0) {
          imvt_nnie_param_deinit(&DAT_047b23f8);
          imvt_printf(0,"[imvt_yolo] %s innt param failed\n","imvt_tracker_init");
          return 0xffffffff;
        }
      }
      else {
        imvt_printf(0,"[imvt_yolo] %s load model failed\n","imvt_tracker_init");
        uVar2 = 0xffffffff;
      }
    }
    else {
      imvt_printf(0,"[imvt_yolo] %s init failed\n","imvt_tracker_init");
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}



/* FUNCTION n3a_af_update @ 00d3a010 body=[[00d3a010, 00d3a0e3] [00d3a0e8, 00d3a323]]
REF Entry Point EXTERNAL caller=NONE
REF 00f184dc INDIRECTION caller=NONE
REF 00fe0188 DATA caller=NONE
REF 00887ecc UNCONDITIONAL_CALL caller=NONE
*/

int n3a_af_update(void *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  undefined8 local_20b0;
  undefined8 uStack_20a8;
  undefined8 local_20a0;
  undefined8 uStack_2098;
  undefined8 local_2090;
  undefined8 local_2080;
  undefined8 uStack_2078;
  undefined8 local_2070;
  undefined4 local_2068;
  undefined1 auStack_2060 [8216];
  int local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  pvVar4 = memcpy(auStack_2060,param_1,0x2008);
  local_2070 = param_2[2];
  local_2080 = *param_2;
  uStack_2078 = param_2[1];
  local_2068 = *(undefined4 *)(param_2 + 3);
  local_2090 = param_5[4];
  local_20b0 = *param_5;
  uStack_20a8 = param_5[1];
  local_20a0 = param_5[2];
  uStack_2098 = param_5[3];
  n3a_af_parse_fv(pvVar4,&local_2080,param_3,param_4,&local_20b0);
  uVar1 = n3a_af_get_fv2();
  DAT_047b5944 = uVar1;
  if (DAT_047b5950 == 0) {
    return 0;
  }
  if (DAT_047b5958 != 0) {
    return 0;
  }
  if (DAT_047b5948 != 0) {
    return 0;
  }
  local_44 = 0x20;
  local_48 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  uStack_8 = 0;
  (**(code **)(DAT_047b5960 + 0x28))();
  DAT_047b5940 = (**(code **)(DAT_047b5960 + 0x28))();
  if ((DAT_047b5928 & 1) == 0) {
    if ((DAT_047b5928 >> 1 & 1) == 0) {
      DAT_047b594c = local_48;
      return 0;
    }
    iVar2 = n3a_af_caf_task_run(uVar1,&local_48,&local_44);
  }
  else {
    iVar2 = n3a_af_saf_task_run(uVar1,&local_48,&local_44);
  }
  DAT_047b594c = local_48;
  if (iVar2 == 0) {
    return 0;
  }
  if (local_48 != 0) {
    DAT_047b5938 = DAT_047b5938 + 1;
    if (*(int *)(DAT_047b5960 + 0xb8) == 0) {
      iVar3 = (**(code **)(DAT_047b5960 + 0x60))(&local_40,0x20);
      if ((iVar3 == 8) && (DAT_047b5940 < (short)local_40)) {
        DAT_047b5940 = (int)(short)local_40;
      }
      iVar3 = (int)uStack_38._6_2_;
      if (uStack_38._6_2_ < DAT_047b5940) {
        DAT_047b5940 = iVar3;
      }
      iVar5 = DAT_047b5940 + DAT_047b594c;
      if (DAT_047b5940 + DAT_047b594c < (int)(short)local_40) {
        iVar5 = (int)(short)local_40;
      }
      if (iVar3 < iVar5) {
        iVar5 = iVar3;
      }
    }
    else {
      iVar5 = local_48 + DAT_047b5940;
    }
    af_printf("lens next pos is %d, speed %d\n",iVar5,local_44);
    (**(code **)(DAT_047b5960 + 0x30))(iVar5,local_44);
  }
  if (1 < iVar2 - 2U) {
    return iVar2;
  }
  if ((DAT_047b5928 & 1) == 0) {
    return iVar2;
  }
  if (DAT_047b5928 != 1) {
    if ((DAT_047b5928 >> 1 & 1) == 0) goto LAB_00d3a24c;
    if (DAT_047b5954 != 0) {
      DAT_047b5928 = DAT_047b5928 & 0xfffffffe;
      n3a_af_caf_start();
      goto LAB_00d3a24c;
    }
  }
  DAT_047b593c = 0;
  DAT_047b594c = 0;
  DAT_047b5950 = 0;
LAB_00d3a24c:
  af_printf("focus done, focus %d times!!\n",DAT_047b5938);
  return iVar2;
}



/* FUNCTION n3a_af_caf_task_run @ 00d3adc8 body=[[00d3adc8, 00d3b3eb] [00d3b3f0, 00d3b42b] [00d3b430, 00d3b50b] [00d3b510, 00d3ba33] [00d3ba38, 00d3bd13] [00d3bd18, 00d3bdd3] [00d3bdd8, 00d3bde3] [00d3bde8, 00d3bdf3] [00d3bdf8, 00d3be1b] [00d3be20, 00d3be6b] [00d3be70, 00d3be83] [00d3be88, 00d3be93] [00d3be98, 00d3bea3] [00d3bea8, 00d3c86b] [00d3c870, 00d3cd83] [00d3cd88, 00d3d8cb] [00d3d8d0, 00d3d9fb] [00d3da00, 00d3daf3]]
REF Entry Point EXTERNAL caller=NONE
REF 00f185b4 INDIRECTION caller=NONE
REF 00fe0588 DATA caller=NONE
REF 00d3a1ac UNCONDITIONAL_CALL caller=n3a_af_update@00d3a010
*/

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined8 n3a_af_caf_task_run(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  double dVar4;
  float fVar5;
  double dVar6;
  float fVar7;
  float fVar8;
  double dVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  code *pcVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  uint *puVar22;
  uint *puVar23;
  int *piVar24;
  undefined8 *puVar25;
  undefined8 *puVar26;
  int *piVar27;
  char *pcVar28;
  undefined4 uVar29;
  uint uVar30;
  uint uVar31;
  int iVar32;
  long lVar33;
  undefined8 uVar34;
  long lVar35;
  long lVar36;
  float fVar37;
  float fVar38;
  double dVar39;
  double dVar40;
  float fVar41;
  float fVar42;
  float fVar43;
  int local_e4;
  int local_dc;
  double local_d8;
  int local_d0;
  int iStack_cc;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  ulong local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined4 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_60;
  ulong local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulong local_38;
  undefined8 local_30;
  ulong uStack_28;
  ulong local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  ulong uStack_8;
  
  *param_2 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_a8 = 0;
  pcVar19 = *(code **)(DAT_047b79e8 + 0x28);
  *param_3 = 0;
  iVar13 = (*pcVar19)();
  iVar13 = iVar13 - DAT_048179e0;
  iVar14 = -iVar13;
  if (-1 < iVar13) {
    iVar14 = iVar13;
  }
  iVar13 = n3a_af_get_af_mode();
  DAT_04817d30 = DAT_04817d30 + 1;
  DAT_04817d10 = DAT_04817d10 + 1;
  local_b8._0_4_ = 0;
  local_b8._4_4_ = 0;
  local_b0 = 0;
  uVar29 = 2;
  local_a8 = 0;
  if ((DAT_048179a4 == 4) && (uVar29 = 2, DAT_048179a8 == 4)) {
    uVar29 = 4;
  }
  if ((float)iVar14 < DAT_04817d38) {
    n3a_af_lum_parse(iVar14,(int)(DAT_04817d34 * 30.0),uVar29,
                     (-(ulong)(DAT_047b5990 >> 0x1f) & 0xfffffff800000000 | (ulong)DAT_047b5990 << 3
                     ) + (long)iVar13 * 0x84 + 0x47b7ae4);
  }
  iVar14 = n3a_af_luminance_is_changing();
  if ((iVar14 != 0) && (DAT_04817d58 == 0)) {
    af_printf("luminance is changing caf cancel !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    n3a_af_caf_cancel_focus();
  }
  iVar14 = n3a_af_camera_is_moving();
  if ((iVar14 != 0) && (DAT_04817d58 == 0)) {
    af_printf("camera is moving, caf cancel !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    n3a_af_caf_cancel_focus();
  }
  dVar9 = DAT_00d3db90;
  fVar8 = DAT_00d3db8c;
  fVar7 = DAT_00d3db88;
  dVar6 = DAT_00d3db70;
  fVar5 = DAT_00d3db50;
  dVar4 = DAT_00d3db18;
  if (DAT_047b79f8 + 1 < (ulong)(long)DAT_047b7a00) {
    DAT_047b79f8 = DAT_047b79f8 + 1;
    return 0;
  }
  DAT_047b79f8 = 0;
  do {
    local_b8._0_4_ = 0;
    local_d0 = 1;
    iStack_cc = 1;
    iVar15 = n3a_af_fv_get_tiles_num();
    iVar16 = n3a_af_get_af_mode();
    iVar14 = DAT_047b7e50;
    iVar13 = DAT_047b7e4c;
    uVar30 = DAT_047b5990;
    local_c8 = 0;
    uStack_c0 = 0;
    DAT_04817cc4 = 10.0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    uStack_48 = 0;
    local_40 = 0;
    local_38 = 0;
    if (DAT_04817cf0 != 0) {
      DAT_04817cf0 = 0;
      uVar34 = 0xffffffff;
      af_printf("dir change skip this fv!!\n");
      goto LAB_00d3b338;
    }
    local_90 = 0;
    local_88 = 0;
    local_a0 = 0;
    uStack_98 = 0;
    n3a_af_get_roi(&local_a0);
    _DAT_04817d40 = 0;
    DAT_04817d48 = 0;
    (**(code **)(DAT_047b79e8 + 0x60))(&DAT_04817d40,8);
    sVar3 = DAT_04817d40;
    if (0 < DAT_047b7e4c) {
      sVar3 = DAT_04817d48._6_2_;
    }
    local_dc = (int)sVar3;
    sVar3 = DAT_04817d40;
    if (0 < DAT_047b7e50) {
      sVar3 = DAT_04817d48._6_2_;
    }
    local_e4 = (int)sVar3;
    local_b8 = 0;
    local_b0 = local_b0 & 0xffffffff;
    iVar18 = -1;
    local_a8 = 0;
    DAT_04817cfc = DAT_04817cf8;
    if (DAT_048179ac == 0) {
      iVar18 = (**(code **)(DAT_047b79e8 + 0x28))();
      n3a_af_parase_fv_get_trend_info(&local_60);
      n3a_af_get_ae_info(&local_c8);
      puVar22 = &DAT_048179d0;
      do {
        puVar23 = puVar22 + -1;
        puVar22[1] = *puVar22;
        puVar22 = puVar23;
      } while (puVar23 != &DAT_048179ac);
      if ((DAT_048179dc < 1) || (param_1 < DAT_048179dc)) {
        DAT_048179dc = param_1;
      }
      if ((DAT_048179d8 < 1) || (DAT_048179d8 < param_1)) {
        DAT_048179d8 = param_1;
      }
      piVar27 = &DAT_04817a00;
      DAT_048179b0 = param_1;
      do {
        piVar24 = piVar27 + -1;
        piVar27[1] = *piVar27;
        piVar27 = piVar24;
      } while (piVar24 != &DAT_048179dc);
      if (((param_1 == -1) || (DAT_048179b4 == -1 || iVar18 == -1)) ||
         (iVar18 == DAT_048179e4 || DAT_048179e4 == -1)) {
        DAT_04817a08 = 0.0;
      }
      else {
        iVar32 = iVar18 - DAT_048179e4;
        iVar17 = -iVar32;
        if (-1 < iVar32) {
          iVar17 = iVar32;
        }
        DAT_04817a08 = (float)(param_1 - DAT_048179b4) / (float)iVar17;
      }
      puVar20 = &DAT_04817a28;
      DAT_048179e0 = iVar18;
      do {
        puVar21 = puVar20 + -1;
        puVar20[1] = *puVar20;
        puVar20[0xb] = puVar20[10];
        puVar20[0x15] = puVar20[0x14];
        puVar20 = puVar21;
      } while (puVar21 != &DAT_04817a04);
      DAT_04817a30 = DAT_04817a08 - DAT_04817a0c;
      DAT_04817c60 = (int)DAT_04817d00;
      DAT_04817a58 = DAT_04817a30 - DAT_04817a34;
      puVar20 = &DAT_04817c80;
      do {
        puVar21 = puVar20 + -1;
        puVar20[1] = *puVar20;
        puVar20 = puVar21;
      } while (puVar21 != (undefined4 *)((long)&DAT_04817c58 + 4));
      local_30 = local_60;
      uStack_28 = local_58;
      local_20 = local_50;
      uStack_18 = uStack_48;
      local_10 = local_40;
      uStack_8 = local_38;
      puVar25 = &DAT_04817c30;
      do {
        puVar26 = puVar25 + -6;
        *puVar25 = puVar25[-6];
        puVar25[1] = puVar25[-5];
        puVar25[2] = puVar25[-4];
        puVar25[3] = puVar25[-3];
        puVar25[4] = puVar25[-2];
        puVar25[5] = puVar25[-1];
        puVar25 = puVar26;
      } while (puVar26 != &DAT_04817a80);
      DAT_04817a80 = local_60;
      _DAT_04817a88 = local_58;
      DAT_04817aa0 = local_40;
      DAT_04817aa8 = local_38;
      _DAT_04817a90 = local_50;
      DAT_04817a98 = uStack_48;
    }
    lVar33 = 0;
    do {
      if (((&DAT_04817d40)[lVar33] <= iVar18) && (iVar18 < (&DAT_04817d42)[lVar33]))
      goto LAB_00d3b028;
      lVar33 = lVar33 + 1;
    } while (lVar33 != 7);
    lVar33 = 0;
LAB_00d3b028:
    local_80 = local_80 & 0xffffffff00000000;
    (**(code **)(DAT_047b79e8 + 0x50))(&local_80);
    uVar2 = (int)DAT_04817d48._6_2_ - (int)DAT_04817d40;
    uVar31 = -uVar2;
    if (-1 < (int)uVar2) {
      uVar31 = uVar2;
    }
    if ((DAT_047b7e90 == 0) || (0x1f < (uint)local_80)) {
      if (*(int *)(DAT_047b79e8 + 0xb8) == 1) {
LAB_00d3be08:
        DAT_04817d38 = (float)DAT_047b7a20;
      }
      else if (DAT_047b7a08 < uVar31) {
        if (uVar31 <= DAT_047b7a18) goto LAB_00d3be08;
        DAT_04817d38 = (float)(int)((double)(int)(uVar31 * DAT_047b7a20) / (double)DAT_047b7a18);
      }
      else {
        DAT_04817d38 = (float)DAT_047b7a10;
      }
    }
    else {
      DAT_04817d38 = (float)*(int *)(DAT_047b7e90 + (local_80 & 0xffffffff) * 0x18 + 0x50);
    }
    local_80 = local_80 & 0xffffffff00000000;
    iVar17 = (**(code **)(DAT_047b79e8 + 0x50))(&local_80);
    if ((DAT_047b7e90 == 0) || (0x1f < (uint)local_80)) {
      if (*(int *)(DAT_047b79e8 + 0xb8) == 1) {
LAB_00d3bdf8:
        DAT_04817d34 = DAT_047b7a24;
      }
      else if (DAT_047b7a08 < uVar31) {
        if (uVar31 <= DAT_047b7a18) goto LAB_00d3bdf8;
        if ((float)iVar17 / (float)(int)uVar31 <= (float)DAT_047b7a1c / (float)DAT_047b7a18) {
          DAT_04817d34 = ((float)DAT_047b7a1c / (float)DAT_047b7a18) /
                         ((float)iVar17 / (float)(int)uVar31);
        }
        else {
          DAT_04817d34 = 1.0;
        }
      }
      else {
        DAT_04817d34 = DAT_047b7a14;
      }
    }
    else {
      DAT_04817d34 = *(float *)(DAT_047b7e90 + (local_80 & 0xffffffff) * 0x18 + 0x58);
    }
    if ((int)DAT_04817d50 != 0) {
      DAT_04817d34 = DAT_04817d34 * DAT_04817d50._4_4_;
    }
    fVar42 = (float)(&DAT_047b5988)[(long)(int)lVar33 + 0x834];
    DAT_04817d34 = (float)(&DAT_047b5988)[(long)(int)lVar33 + 0x82c] * DAT_04817d34;
    (**(code **)(DAT_047b79e8 + 0x68))(&local_d0,&iStack_cc);
    local_b0 = CONCAT44(local_b0._4_4_,local_d0);
    if (DAT_04817d2c == 0) {
      DAT_048179a4 = 0;
      DAT_047b5994 = -500;
      DAT_04817d2c = 1;
      DAT_04817d0c = *(int *)(&DAT_047b7a84 + (long)iVar16 * 0x84 + (long)(int)uVar30 * 0x18);
      memset(&DAT_047b61c8,1,0x800);
      DAT_04817d20 = 0;
      DAT_04817d24 = 0;
      if (DAT_04817d28 != 0) {
        if (10 < DAT_04817d30) {
          DAT_04817d2c = 2;
        }
        goto joined_r0x00d3bd88;
      }
LAB_00d3b168:
      if (DAT_047b5988 < 1) {
LAB_00d3b3d0:
        if (DAT_047b5988 < -0x31) {
          iVar17 = -1;
          if ((DAT_048179a4 & 0xfffffffd) != 4) goto LAB_00d3b178;
          goto LAB_00d3b18c;
        }
      }
LAB_00d3b174:
      iVar17 = -1;
LAB_00d3b178:
      if ((DAT_04817cb0 != 0) && (DAT_04817cb4 != 0)) goto LAB_00d3b18c;
    }
    else {
      if (DAT_04817d28 == 0) {
        if (DAT_048179a4 < 2) goto joined_r0x00d3bd88;
        iVar17 = (**(code **)(DAT_047b79e8 + 0x20))();
        if (iVar17 == 0) {
          if (*(int *)(DAT_047b79e8 + 0xb8) == 1) {
            if ((((DAT_048179e0 == DAT_048179e4) && (DAT_048179e0 == DAT_048179e8)) &&
                (DAT_04817c88 == DAT_04817c8c)) && (DAT_04817c88 == DAT_047b7e50))
            goto LAB_00d3bb00;
          }
          else if (((DAT_048179e0 == DAT_048179e4) && (DAT_048179e0 == DAT_048179e8)) &&
                  (iVar17 = (**(code **)(DAT_047b79e8 + 0x10))(), iVar17 != 0)) goto LAB_00d3bb00;
          iVar17 = (**(code **)(DAT_047b79e8 + 0x18))();
          if (iVar17 == 0) {
            if (*(int *)(DAT_047b79e8 + 0xb8) == 1) {
              if (((DAT_048179e0 == DAT_048179e4) && (DAT_048179e0 == DAT_048179e8)) &&
                 ((DAT_04817c88 == DAT_04817c8c && (DAT_04817c88 == DAT_047b7e4c))))
              goto LAB_00d3c068;
            }
            else if (((DAT_048179e0 == DAT_048179e4) && (DAT_048179e0 == DAT_048179e8)) &&
                    (iVar17 = (**(code **)(DAT_047b79e8 + 8))(), iVar17 != 0)) goto LAB_00d3c068;
            goto joined_r0x00d3bd88;
          }
LAB_00d3c068:
          DAT_04817cb0 = DAT_04817cb0 + 1;
          if (DAT_04817cf8 == iVar13 && 1 < DAT_04817cb0) {
            af_printf("NG reach closet !!!!\n");
            DAT_048179a8 = DAT_048179a4;
            DAT_048179a4 = 7;
            goto LAB_00d3b168;
          }
          af_printf("reach closet, change dir!!!!\n");
          DAT_048179a8 = DAT_048179a4;
          iVar17 = local_e4;
          DAT_04817cf8 = iVar14;
        }
        else {
LAB_00d3bb00:
          DAT_04817cb4 = DAT_04817cb4 + 1;
          if (DAT_04817cf8 == iVar14 && 1 < DAT_04817cb4) {
            af_printf("NG reach infinite !!!!\n");
            DAT_048179a8 = DAT_048179a4;
            DAT_048179a4 = 7;
            goto LAB_00d3b168;
          }
          af_printf("reach infinite, change dir!!!!\n");
          DAT_048179a8 = DAT_048179a4;
          DAT_04817cf8 = iVar13;
          iVar17 = local_dc;
        }
        DAT_048179a4 = 3;
        if (DAT_047b5988 < 1) {
          goto joined_r0x00d3bac8;
        }
        goto LAB_00d3b178;
      }
      if (10 < DAT_04817d30) {
        DAT_04817d2c = 2;
      }
      if (1 < DAT_048179a4) {
        DAT_047b5994 = -500;
        DAT_048179a4 = 0;
        memset(&DAT_047b61c8,1,0x800);
        DAT_04817d20 = 0;
        DAT_04817d24 = 0;
        goto LAB_00d3b168;
      }
joined_r0x00d3bd88:
      if (0 < DAT_047b5988) goto LAB_00d3b174;
      if (DAT_048179a4 != 3) goto LAB_00d3b3d0;
      iVar17 = -1;
joined_r0x00d3bac8:
      if (99 < (int)local_50) goto LAB_00d3b178;
LAB_00d3b18c:
      DAT_048179a4 = 7;
      af_printf("s_caf_obj.max_try %d\n");
      DAT_04817cb0 = 0;
      DAT_047b5988 = DAT_047b7e48;
      DAT_04817cb4 = 0;
    }
    fVar37 = DAT_04817d04;
    iVar32 = DAT_048179b0;
    uVar31 = DAT_048179a4;
    if (DAT_04817d04 != 0.0) {
      DAT_04817d04 = 0.0;
      DAT_04817d00 = fVar37;
    }
    switch(DAT_048179a4) {
    case 0:
      DAT_047b5988 = DAT_047b7e48;
      DAT_04817d04 = 0.0;
      DAT_04817cb0 = 0;
      DAT_04817cb4 = 0;
      DAT_04817cf8 = 0;
      if (((DAT_048179a8 != 0) || (DAT_04817d28 != 0)) && (DAT_04817d2c != 3)) {
        DAT_04817d0c = 0;
      }
      DAT_048179a4 = 0;
      DAT_048179a8 = 0;
      DAT_04817d1c = 0;
      if ((DAT_04817d20 < 1) && (DAT_04817d24 < 1)) {
LAB_00d3c67c:
        local_80 = local_80 & 0xffffffff00000000;
        iVar15 = (**(code **)(DAT_047b79e8 + 0x50))(&local_80);
        fVar42 = (float)iVar15;
        if (fVar42 != DAT_04817d3c) {
          DAT_047b5994 = -500;
          n3a_af_get_fv_info(&DAT_047b59c0);
        }
        lVar36 = (long)iVar16;
        lVar35 = (long)(int)uVar30;
        iVar16 = (int)local_58 - DAT_047b5994;
        lVar33 = lVar36 * 0x84 + lVar35 * 0x18;
        iVar32 = (int)local_38 - DAT_047b5998;
        iVar15 = -iVar32;
        if (-1 < iVar32) {
          iVar15 = iVar32;
        }
        fVar41 = (float)iVar15;
        DAT_04817d28 = 0;
        fVar38 = (float)DAT_047b5998 * *(float *)(&DAT_047b7a88 + lVar33);
        iVar15 = uStack_c0._4_4_ - DAT_047b599c;
        fVar37 = ABS((float)iVar16 / (float)(DAT_047b5994 + 1));
        if (DAT_047b5994 + 499U < 999) {
          iVar32 = *(int *)(&DAT_047b7a7c + lVar33);
        }
        else {
          iVar32 = (int)((float)DAT_047b5994 * *(float *)(&DAT_047b7a78 + lVar33));
        }
        DAT_04817d3c = fVar42;
        if (fVar38 <= fVar41) {
          af_printf("!!!!!!!!!!!!!!!!!!!!!!!monitor y_changing!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        }
        iVar1 = -iVar15;
        if (-1 < iVar15) {
          iVar1 = iVar15;
        }
        if (*(int *)(&DAT_047b7a80 + lVar36 * 0x84 + lVar35 * 0x18) < iVar1) {
          af_printf("reach max lv diff is %d\n",iVar1);
        }
        iVar15 = -iVar16;
        if (-1 < iVar16) {
          iVar15 = iVar16;
        }
        if (iVar32 < iVar15) {
          lVar33 = lVar36 * 0x84 + lVar35 * 0xc;
          if ((iVar15 <= (int)((float)(int)local_58 * *(float *)(&DAT_047b7ac8 + lVar33))) ||
             ((DAT_04817ab8 - DAT_04817ae8) * iVar16 < 0)) {
            DAT_04817d5c = 0;
            if (DAT_04817d0c != 0) goto LAB_00d3cfe0;
LAB_00d3cf34:
            af_printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!max diff reach!!!!\n");
            DAT_04817d0c = 1;
            DAT_04817d08 = iVar16;
            goto LAB_00d3cf54;
          }
          DAT_04817d5c = DAT_04817d5c + 1;
          if (((*(int *)(&DAT_047b7ac0 + lVar33) != 0) &&
              (*(uint *)(&DAT_047b7ac4 + lVar33) < DAT_04817d5c)) &&
             (*(float *)(&DAT_047b7ac8 + lVar33) < fVar37)) {
            DAT_04817d5c = 0;
            DAT_04817d58 = 1;
            af_printf(
                     "@@@@@@@@@@@@@@@@@@@@@@reach max out of focus frames, force focus !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                     );
          }
          if (DAT_04817d0c == 0) goto LAB_00d3cf34;
          if (DAT_04817d0c < *(int *)(&DAT_047b7a84 + lVar36 * 0x84 + lVar35 * 0x18)) {
LAB_00d3c82c:
            iVar32 = DAT_04817a88 - DAT_04817ab8;
            iVar15 = -iVar32;
            if (-1 < iVar32) {
              iVar15 = iVar32;
            }
            if (*(int *)(&DAT_047b7a8c + lVar36 * 0x84 + lVar35 * 0x18) < iVar15) goto LAB_00d3d020;
            DAT_04817d0c = DAT_04817d0c + 1;
            goto LAB_00d3d02c;
          }
LAB_00d3d1c4:
          if ((int)DAT_047b7e80 != 0) goto LAB_00d3cf5c;
        }
        else {
          DAT_04817d5c = 0;
          if (DAT_04817d0c == 0) {
            if ((*(int *)(&DAT_047b7a80 + lVar36 * 0x84 + lVar35 * 0x18) < iVar1) ||
               (fVar38 <= fVar41)) goto LAB_00d3cf34;
          }
          else {
LAB_00d3cfe0:
            DAT_04817d5c = 0;
            lVar33 = lVar36 * 0x84 + lVar35 * 0x18;
            if (*(int *)(&DAT_047b7a84 + lVar33) <= DAT_04817d0c) goto LAB_00d3d1c4;
            if (((iVar32 < iVar15) || (*(int *)(&DAT_047b7a80 + lVar33) < iVar1)) ||
               (fVar38 <= fVar41)) goto LAB_00d3c82c;
LAB_00d3d020:
            DAT_04817d08 = 0;
            DAT_04817d0c = 0;
LAB_00d3d02c:
            af_printf("fv[0] %d fv[1] %d y_changeing %d monitor_fv %d\n",DAT_048179b0,DAT_048179b4,
                      fVar38 <= fVar41,DAT_047b5994);
            af_printf("stab count %d max_diff %d\n",DAT_04817d0c,
                      *(undefined4 *)(&DAT_047b7a7c + lVar36 * 0x84 + lVar35 * 0x18));
          }
LAB_00d3cf54:
          if ((int)DAT_047b7e80 != 0) {
LAB_00d3cf5c:
            if (((DAT_04817d68 == 0) && (0.0 < DAT_047b59a8)) &&
               ((iVar15 = n3a_af_get_af_mode(), iVar15 == 3 &&
                (((DAT_047b59a0 - iVar18) + 0x22U < 0x45 &&
                 (iVar1 < *(int *)(&DAT_047b7a80 + lVar36 * 0x84 + lVar35 * 0x18) && 100 < param_1))
                )))) {
              fVar41 = DAT_047b59b4 / DAT_047b59b0;
              fVar43 = DAT_047b59b4 * DAT_047b59b0;
              fVar42 = (float)local_90 / uStack_98._4_4_;
              fVar38 = (float)local_90 * uStack_98._4_4_ - fVar43;
              af_printf((double)fVar42,(double)fVar41,(double)fVar43,
                        (double)((float)local_90 * uStack_98._4_4_),"ratio %f %f size %f %f\n");
              if ((ABS(fVar42 - fVar41) < DAT_047b7e80._4_4_) &&
                 ((fVar38 == 0.0 || (ABS(fVar38) / fVar43 < DAT_047b7e88)))) {
                DAT_04817d0c = 0;
                af_printf(
                         "************************************object depeth only chang a little, skip run focus!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                         );
              }
            }
          }
          if ((DAT_04817d0c < *(int *)(&DAT_047b7a84 + lVar36 * 0x84 + lVar35 * 0x18)) &&
             (DAT_04817d58 == 0)) {
            DAT_04817ce8 = 0;
            DAT_04817cec = 0;
            goto LAB_00d3b1f4;
          }
        }
        DAT_04817d0c = 0;
        DAT_04817d58 = 0;
        if ((double)fVar37 <= DAT_00d3db18) {
          DAT_04817cc4 = 6.0;
        }
        if ((param_1 < 0xb) && ((int)local_50 < 0xb)) {
          DAT_04817cc4 = 10.0;
        }
        DAT_04817cf8 = iVar14;
        if (iVar16 < 1) {
          DAT_04817cf8 = iVar13;
        }
        fVar42 = DAT_04817cc4 * DAT_04817d34;
        iVar15 = (**(code **)(DAT_047b79e8 + 8))();
        if (iVar15 == 0) {
          iVar15 = (**(code **)(DAT_047b79e8 + 0x10))();
          if (iVar15 != 0) {
            DAT_04817cf8 = iVar13;
          }
        }
        else {
          DAT_04817cf8 = iVar14;
        }
        iVar15 = n3a_af_get_af_mode();
        if (iVar15 == 3) {
          if ((float)local_90 * uStack_98._4_4_ <= (float)DAT_047b79d8 * DAT_047b79d0._4_4_) {
            if ((float)local_90 * uStack_98._4_4_ < (float)DAT_047b79d8 * DAT_047b79d0._4_4_) {
              DAT_04817cf8 = iVar14;
            }
          }
          else {
            DAT_04817cf8 = iVar13;
          }
          if ((DAT_047b59a8 < 0.0) && (DAT_047b59ac < 0.0)) {
            DAT_04817cf8 = iVar13;
          }
        }
        DAT_047b79e0 = local_88;
        DAT_047b79d8 = local_90;
        DAT_047b79c8 = local_a0;
        DAT_047b79d0 = uStack_98;
        FUN_00d3a608();
        uVar30 = 3;
        pcVar28 = 
        "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!fv stable!!!!!!!!!!!!!!!!!!!\n";
LAB_00d3d288:
        DAT_048179a8 = DAT_048179a4;
        DAT_048179a4 = uVar30;
        af_printf(pcVar28);
        uVar31 = DAT_048179a8;
        break;
      }
      DAT_04817d20 = DAT_04817d20 + -1;
      if (DAT_04817d20 < 1) {
        af_printf("monitor fv is %d\n",param_1);
        DAT_047b5994 = (int)local_58;
        DAT_047b599c = uStack_c0._4_4_;
        DAT_047b59a0 = iVar18;
        n3a_af_get_fv_info(&DAT_047b59c0);
        DAT_04817d24 = DAT_04817d24 + -1;
        if (DAT_04817d24 < 1) {
          DAT_047b5998 = (int)local_38;
          if (DAT_04817d20 < 1) goto LAB_00d3c67c;
        }
        else if (DAT_04817d20 < 1) goto LAB_00d3b1f4;
LAB_00d3ba24:
        fVar42 = 0.0;
        uVar31 = DAT_048179a8;
      }
      else {
        DAT_04817d24 = DAT_04817d24 + -1;
        if (0 < DAT_04817d24) goto LAB_00d3ba24;
        DAT_047b5998 = (int)local_38;
        fVar42 = 0.0;
        uVar31 = 0;
      }
      goto LAB_00d3b1f8;
    case 1:
      fVar42 = (float)(iVar18 - DAT_04817d48._4_2_);
      if (fVar42 < 0.0) {
        fVar42 = -fVar42;
        DAT_04817cf8 = 1;
      }
      else {
        DAT_04817cf8 = -1;
      }
      DAT_04817d20 = DAT_047b7e30 + 1;
      DAT_048179a4 = 0;
      local_b0 = CONCAT44(local_b0._4_4_,local_d0);
      DAT_047b5988 = DAT_047b7e48;
      DAT_047b5994 = DAT_048179b0;
      DAT_048179a8 = 1;
      DAT_04817d24 = DAT_04817d20;
      break;
    default:
      af_printf("unknown caf status!!!\n");
      goto LAB_00d3b1f4;
    case 3:
      DAT_047b79d8 = local_90;
      DAT_047b5988 = DAT_047b5988 + -1;
      DAT_047b79e0 = local_88;
      DAT_047b79c8 = local_a0;
      DAT_047b79d0 = uStack_98;
      FUN_00d3a770();
      fVar37 = DAT_04817d00;
      uVar30 = DAT_048179a4;
      iVar14 = DAT_047b7ebc;
      if (DAT_048179a8 == 3) {
        DAT_047b598c = DAT_047b598c + 1;
        DAT_048179a4 = DAT_048179a8;
        DAT_048179a8 = uVar30;
        if (DAT_048179b0 <= DAT_048179b4) {
          dVar39 = DAT_00d3db48;
          if (DAT_048179b4 <= DAT_048179b0) goto LAB_00d3c4ac;
          DAT_04817cec = DAT_04817cec + 1;
          if (1 < DAT_04817ce8) {
            if ((((100 < DAT_048179b4) && (DAT_04817a08 < 0.0)) && (DAT_0481799c != 0)) &&
               ((DAT_00d3db38 <= ABS((double)(DAT_048179b0 - DAT_048179b4)) ||
                (0.5 <= ABS((double)(DAT_048179b4 - DAT_048179b0)) / (double)(DAT_048179b4 + 1)))))
            {
LAB_00d3d0d8:
              iVar14 = FUN_00d3a650();
              if (DAT_04817cfc == DAT_04817cf8) {
                DAT_04817cf8 = -DAT_04817cfc;
              }
              else {
                af_printf("!!!!!!!!!!!!!!!!!!!!last dir != cur dir, so skip change dir!!\n");
              }
              DAT_048179a8 = DAT_048179a4;
              DAT_048179a4 = 4;
              af_printf("down hill, peak fv %d!!!\n",DAT_04817cc8);
              fVar42 = (float)iVar14;
              uVar31 = DAT_048179a8;
              break;
            }
            if ((DAT_00d3db40 <= (double)local_60._4_4_) &&
               ((0x1e < param_1 && 2 < iVar15 && (1 < DAT_047b7eb8)))) {
              iVar15 = DAT_047b7eac - DAT_048179b0;
              iVar13 = -iVar15;
              if (-1 < iVar15) {
                iVar13 = iVar15;
              }
              if (0x13 < iVar13) {
                iVar15 = DAT_047b7eac - DAT_047b7e9c;
                iVar13 = -iVar15;
                if (-1 < iVar15) {
                  iVar13 = iVar15;
                }
                if (iVar13 < 0x14) {
                  if (0 < DAT_04817d1c) {
                    iVar15 = DAT_047b7ef8 - DAT_047b7ee8;
                    iVar13 = -iVar15;
                    if (-1 < iVar15) {
                      iVar13 = iVar15;
                    }
                    if (0x23 < iVar13) goto LAB_00d3d820;
                  }
                }
                else {
LAB_00d3d820:
                  if (DAT_0481799c != 0) goto LAB_00d3d0d8;
                }
              }
            }
          }
          af_printf("peak_pos %d, peak_fv %d fv_up %d, fv_down %d, up_hill %d, down_hill %d\n",
                    DAT_047b7eb0,DAT_047b7eac,DAT_04817ce8,DAT_04817cec,DAT_047b7eb8,DAT_047b7ebc);
          fVar41 = DAT_00d3daf4;
          if (((0x15d < DAT_047b7eac) && (fVar41 = DAT_00d3daf8, 299 < DAT_047b7eac - 700U)) &&
             (fVar41 = DAT_00d3db00, DAT_047b7eac < 1000)) {
            fVar41 = DAT_00d3dafc;
          }
          fVar38 = DAT_00d3db04;
          if ((0x30 < DAT_047b7eac - 0x97U) && (fVar38 = fVar41, DAT_047b7eac < 0x96)) {
            fVar38 = DAT_00d3db08;
          }
          iVar13 = DAT_048179a0;
          if (DAT_048179b0 < 0x97) {
            if (DAT_047b7eb8 < 3) goto LAB_00d3d488;
            if ((0x50 < DAT_047b7eac && 0 < DAT_047b7ebc) && (DAT_0481799c != 0)) {
              if (10 < iVar14) {
                iVar14 = 10;
              }
              if ((int)((float)(&DAT_048179b0)[iVar14] * fVar38) <=
                  (&DAT_048179b0)[iVar14] - DAT_048179b0) goto LAB_00d3d690;
            }
            if (DAT_048179a0 == 0) {
              if ((DAT_047b7ebc < 1) || (1 < DAT_04817d1c)) goto LAB_00d3d840;
LAB_00d3d898:
              if (((((DAT_047b7eac < 0x1f) && (DAT_04817b20 < 0x1f)) ||
                   (DAT_04817cf8 != DAT_04817cfc)) || (DAT_047b7eac - DAT_048179b0 < 0x23)) &&
                 (iVar13 == 0)) goto LAB_00d3d840;
            }
            else {
LAB_00d3d658:
              if (0 < DAT_047b7ebc) {
                if (DAT_047b7eac - DAT_048179b0 < (int)(fVar38 * 0.5 * (float)DAT_047b7eac))
                goto LAB_00d3cad4;
                af_printf("max point is down hill, so begain focus peak!!!!!!!!!!!\n");
                goto LAB_00d3d690;
              }
            }
LAB_00d3cae4:
            iVar14 = FUN_00d3ad00();
            local_d8 = DAT_00d3db48;
            dVar39 = DAT_00d3db48;
            if (iVar14 != 0) {
              iVar13 = DAT_047b7eb0 - DAT_048179e0;
              iVar14 = -iVar13;
              if (-1 < iVar13) {
                iVar14 = iVar13;
              }
              fVar37 = (float)((double)DAT_04817d00 * DAT_00d3db48);
              if ((float)iVar14 * 0.5 < (float)((double)DAT_04817d00 * DAT_00d3db48)) {
                fVar37 = (float)iVar14 * 0.5;
              }
              DAT_04817d1c = DAT_04817d1c + 1;
              DAT_04817ce8 = 0;
              DAT_04817cec = 0;
              if (DAT_04817cfc == DAT_04817cf8) {
                DAT_04817cf8 = -DAT_04817cfc;
              }
              else {
                af_printf("!!!!!!!!!!!!!!!!!!!!last dir != cur dir, so skip change dir!!\n");
              }
              if ((1 < DAT_04817d1c) && (DAT_04817d34 * DAT_00d3db50 < fVar37)) {
                fVar37 = DAT_04817d34 * DAT_00d3db50;
              }
              pcVar28 = "switch dir !!!!!!!!!!!!!!!!!!!!!!!!!!\n";
LAB_00d3cb8c:
              af_printf(pcVar28);
              dVar39 = local_d8;
            }
            goto LAB_00d3c4ac;
          }
          if ((DAT_047b7eb8 < 2) || (DAT_047b7eac < 0x51 || DAT_047b7ebc < 1)) {
LAB_00d3d488:
            if (DAT_048179a0 != 0) {
LAB_00d3cac0:
              if (2 < DAT_047b7eb8) goto LAB_00d3d658;
              if (0 < DAT_047b7ebc) {
LAB_00d3cad4:
                if (DAT_04817d1c < 2) goto LAB_00d3d898;
              }
              goto LAB_00d3cae4;
            }
            if (0 < DAT_047b7ebc) goto LAB_00d3d830;
LAB_00d3d49c:
            iVar13 = DAT_048179b4 - DAT_048179b0;
            iVar14 = -iVar13;
            if (-1 < iVar13) {
              iVar14 = iVar13;
            }
            fVar37 = DAT_04817d00 * 0.5;
            if (DAT_00d3db58 <= (double)iVar14 / (double)(DAT_048179b4 + 1)) {
LAB_00d3d7e0:
              fVar41 = (float)((double)DAT_04817d00 * DAT_00d3db60);
            }
            else {
              iVar13 = DAT_04817ac0 - DAT_04817a90;
              iVar14 = -iVar13;
              if (-1 < iVar13) {
                iVar14 = iVar13;
              }
              bVar10 = (double)iVar14 / (double)(DAT_04817ac0 + 1) < DAT_00d3db58;
              if ((!bVar10 && DAT_048179b4 != 0xa0) && (bVar10 || 0x9f < DAT_048179b4))
              goto LAB_00d3d7e0;
              fVar41 = fVar37;
              if ((double)fVar37 <= (double)DAT_04817d38 * DAT_00d3db60) {
                fVar41 = (float)((double)DAT_04817d00 * DAT_00d3db60);
              }
            }
            if ((2.0 <= (float)DAT_048179b4 / (float)(DAT_048179b0 + 1) && 0x14 < DAT_048179b4) &&
               (DAT_04817d1c < 3)) {
              DAT_04817d1c = DAT_04817d1c + 1;
              DAT_04817ce8 = 0;
              DAT_04817cec = 0;
              fVar41 = DAT_04817d00;
              if (DAT_04817d34 * 25.0 <= fVar37) {
                fVar41 = fVar37;
              }
              if (DAT_04817cfc == DAT_04817cf8) {
                DAT_04817cf8 = -DAT_04817cfc;
              }
              else {
                af_printf("!!!!!!!!!!!!!!!!!!!!last dir != cur dir, so skip change dir!!\n");
              }
              af_printf("fv is zero, maybe step is too large, skip peak, move back!!!!!!!\n");
            }
            fVar37 = fVar41;
            dVar39 = DAT_00d3db48;
            if (DAT_04817cec == 1) {
              if ((param_1 < 0x51) && (fVar37 = DAT_04817d34 * 30.0, fVar37 <= fVar41)) {
                fVar37 = (float)((double)fVar41 * DAT_00d3db68);
              }
            }
            else if ((param_1 < 0x51 && 1 < DAT_04817cec) &&
                    (fVar37 = DAT_04817d34 * DAT_00d3db50, fVar37 <= fVar41)) {
              fVar37 = (float)((double)fVar41 * DAT_00d3db30);
            }
            goto LAB_00d3c4ac;
          }
          if ((DAT_047b7eac - DAT_048179b0 < (int)((float)DAT_047b7eac * fVar38)) ||
             (DAT_0481799c == 0)) {
            if (DAT_048179a0 != 0) goto LAB_00d3cac0;
LAB_00d3d830:
            if (DAT_04817d1c < 2) {
              iVar13 = 0;
              goto LAB_00d3d898;
            }
LAB_00d3d840:
            if (((DAT_047b7ebc < 2) || (DAT_048179b8 < 0xf)) ||
               ((DAT_04817d1c < 2 ||
                ((DAT_04817cf8 != DAT_04817cfc || (DAT_047b7eac - DAT_048179b0 < 0x23))))))
            goto LAB_00d3d49c;
            iVar14 = FUN_00d3ad00();
            dVar39 = DAT_00d3db48;
            if (iVar14 == 0) goto LAB_00d3c4ac;
            DAT_04817d1c = DAT_04817d1c + 1;
            DAT_04817ce8 = 0;
            DAT_04817cec = 0;
            if (DAT_04817cfc == DAT_04817cf8) {
              DAT_04817cf8 = -DAT_04817cfc;
            }
            else {
              af_printf("!!!!!!!!!!!!!!!!!!!!last dir != cur dir, so skip change dir!!\n");
            }
            fVar37 = (float)((double)DAT_04817d00 * DAT_00d3db48);
            if ((1 < DAT_04817d1c) && (DAT_04817d34 * DAT_00d3db50 < fVar37)) {
              fVar37 = DAT_04817d34 * DAT_00d3db50;
            }
            local_d8 = DAT_00d3db48;
            pcVar28 = "switch dir !!!!!!!!!!!!!!!!!!!!!!!!!!@@@@@@@@@@@@@@@@@@@@\n";
            goto LAB_00d3cb8c;
          }
LAB_00d3d690:
          iVar14 = FUN_00d3a650();
          fVar42 = (float)iVar14;
          if (DAT_04817cfc == DAT_04817cf8) {
            DAT_04817cf8 = -DAT_04817cfc;
          }
          else {
            af_printf("!!!!!!!!!!!!!!!!!!!!last dir != cur dir, so skip change dir!!\n");
          }
          pcVar28 = "reach max down hill steps !!!!\n";
          uVar30 = 4;
          goto LAB_00d3d288;
        }
        DAT_04817cec = 0;
        dVar39 = (double)DAT_04817d00;
        DAT_04817ce8 = DAT_04817ce8 + 1;
        fVar37 = (float)(dVar39 * DAT_00d3db20);
        if (5.0 <= ABS((double)(DAT_048179b4 - DAT_048179b0)) / (double)(DAT_048179b4 + 1)) {
          fVar37 = (float)(dVar39 * DAT_00d3db18);
          af_printf("fv change too much!!!\n");
        }
        else if (DAT_04817a08 - DAT_04817a0c < 0.0) {
          if (0.0 <= DAT_04817a08) {
            if (DAT_04817a0c < 0.0) goto code_r0x00d3c484;
            fVar37 = (float)(dVar39 * DAT_00d3db28);
          }
        }
        else {
code_r0x00d3c484:
          if ((0.0 < DAT_04817a08) && (DAT_04817a0c < 0.0)) {
            fVar37 = (float)(dVar39 * DAT_00d3db30);
          }
        }
        af_printf((double)fVar37,"fv up!!! %f\n");
        dVar39 = DAT_00d3db48;
LAB_00d3c4ac:
        dVar39 = (double)DAT_04817d38 * dVar39;
        if ((float)(int)dVar39 < fVar37) {
          fVar37 = (float)dVar39;
        }
        if (DAT_048179b0 < 0x14) {
          fVar41 = fVar37;
          if ((((((DAT_048179b4 < 0x14) &&
                 (ABS((double)(DAT_048179b4 - DAT_048179b0)) / (double)(DAT_048179b4 + 1) < 5.0)) &&
                (DAT_04817cfc == DAT_04817cf8)) &&
               ((0 < (DAT_048179e0 - DAT_048179e4) * (DAT_048179e4 - DAT_048179e8) &&
                (fVar41 = DAT_04817d38, DAT_048179b0 != 0 && DAT_048179b0 != DAT_048179b4)))) &&
              (dVar39 = (double)DAT_04817d38 * DAT_00d3db60, fVar41 = fVar37,
              (double)fVar37 < dVar39)) && ((int)local_50 < 0x14)) {
            fVar37 = (float)dVar39;
            af_printf((double)fVar37,"low fv next step %f\n");
            goto LAB_00d3cd60;
          }
LAB_00d3c504:
          fVar37 = fVar41;
          if (2.0 <= (float)DAT_04817a90 / (float)(DAT_04817ac0 + 1) && 0x13 < DAT_04817a90)
          goto LAB_00d3c530;
        }
        else {
LAB_00d3cd60:
          fVar41 = fVar37;
          if ((float)DAT_048179b0 / (float)(DAT_048179b4 + 1) < 2.0 || DAT_048179b0 < 0x14)
          goto LAB_00d3c504;
LAB_00d3c530:
          if ((double)DAT_04817d38 * DAT_00d3db70 < (double)fVar37) {
            fVar37 = (float)((double)DAT_04817d38 * DAT_00d3db70);
            af_printf("fv double, slow focus step!!!\n");
          }
        }
        if ((DAT_047b598c < 7 && param_1 != 0x13) && (6 < DAT_047b598c || 0x12 < param_1)) {
          af_printf("step limit!!!!\n");
          fVar41 = DAT_04817d34 * 15.0;
          if ((fVar37 <= DAT_04817d34 * 15.0) && (fVar41 = fVar37, fVar37 <= DAT_04817d34 * 8.0)) {
            fVar41 = DAT_04817d34 * 8.0;
          }
        }
        else {
          uVar30 = 0;
          lVar33 = 0;
          iVar13 = DAT_048179e4;
          iVar14 = DAT_048179e0 - DAT_048179e4;
          while (-1 < iVar14 * (DAT_048179e0 - DAT_048179e4)) {
            uVar30 = uVar30 + *(int *)((long)&DAT_048179b0 + lVar33);
            if (lVar33 + 4 == 0x10) {
              uVar30 = uVar30 >> 2;
              fVar38 = (float)(int)(DAT_048179b0 - uVar30) / (float)(uVar30 + 1);
              fVar41 = DAT_00d3db0c;
              if ((0x31 < uVar30) && (fVar41 = DAT_00d3dafc, uVar30 < 0x50)) {
                fVar41 = DAT_00d3db10;
              }
              if (((0.0 < fVar38) && (DAT_048179b4 + -5 <= DAT_048179b0)) && (fVar38 < fVar41)) {
                af_printf("@@@@@@@@@@@@@@@@@fv is flat !!!!!!!!!!!!!!!!!!!!!!!!\n");
                if (param_1 < 300) {
                  dVar40 = (double)DAT_04817d38 * DAT_00d3db40;
                  fVar37 = (float)((double)DAT_04817d00 * DAT_00d3db30 * (double)fVar42);
                  dVar39 = (double)fVar37;
                  if (dVar40 < dVar39) {
LAB_00d3cea0:
                    fVar37 = (float)dVar40;
                    dVar39 = (double)fVar37;
                  }
                }
                else {
                  dVar40 = (double)DAT_04817d38 * DAT_00d3db80;
                  fVar37 = (float)((double)DAT_04817d00 * DAT_00d3db78 * (double)fVar42);
                  dVar39 = (double)fVar37;
                  if (dVar40 < dVar39) goto LAB_00d3cea0;
                }
                af_printf(dVar39,"flat increase step is %f\n");
              }
              break;
            }
            piVar27 = (int *)((long)&DAT_048179e8 + lVar33);
            iVar14 = iVar13 - *piVar27;
            lVar33 = lVar33 + 4;
            iVar13 = *piVar27;
          }
          fVar41 = fVar37;
          if (0.5 <= ABS(DAT_04817a08)) {
            if (fVar37 < DAT_04817d34 * 15.0) {
              fVar41 = DAT_04817d34 * 15.0;
            }
          }
          else if (fVar37 < DAT_04817d34 * 20.0) {
            fVar41 = DAT_04817d34 * 20.0;
          }
        }
        if (DAT_04817cfc == DAT_04817cf8) {
          if (DAT_04817d1c != 2) goto LAB_00d3c618;
        }
        else {
          if (DAT_04817d1c < 2) {
            if ((DAT_048179a0 == 0) &&
               ((DAT_047b7eac < 0x1f ||
                ((DAT_047b7eac - param_1 < 0x24 && (DAT_047b7eac - DAT_047b7e9c < 0x24)))))) {
              iVar13 = iVar18 - DAT_047b7e98;
              iVar14 = -iVar13;
              if (-1 < iVar13) {
                iVar14 = iVar13;
              }
              fVar42 = (float)iVar14;
              DAT_04817d04 = fVar41;
              af_printf(
                       "switch dir, but this switch to last start pos!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                       );
              uVar31 = DAT_048179a8;
              if ((0.0 < fVar42) && (fVar42 < 1.0)) {
                fVar42 = 1.0;
              }
              goto LAB_00d3b1f8;
            }
          }
          else if (DAT_04817d1c == 2) {
            if (0 < DAT_04817ce8) {
              iVar13 = DAT_047b7eb0 - DAT_047b7efc;
              iVar14 = -iVar13;
              if (-1 < iVar13) {
                iVar14 = iVar13;
              }
              if ((iVar14 <= (int)(DAT_04817d34 * fVar5)) &&
                 ((0x31 < DAT_047b7eac - DAT_047b7e9c || (0x31 < DAT_047b7eac - param_1)))) {
                af_printf(
                         "@@@@@@@@@@@@@@@@this is hill, last travel peak pos is clost now peak pos\n"
                         );
                iVar14 = FUN_00d3a650();
                DAT_048179a8 = DAT_048179a4;
                DAT_048179a4 = 4;
                fVar42 = (float)iVar14;
                uVar31 = DAT_048179a8;
                break;
              }
            }
            goto LAB_00d3cc6c;
          }
LAB_00d3c618:
          if ((2 < DAT_04817d1c) && (0 < DAT_04817ce8)) {
            iVar14 = FUN_00d3a650();
            DAT_048179a8 = DAT_048179a4;
            DAT_048179a4 = 4;
            af_printf("@@@@@@@@@@@@@@@@@@@down hill, reach max siwtch dirs, peak fv %d!!!\n",
                      DAT_04817cc8);
            fVar42 = (float)iVar14;
            uVar31 = DAT_048179a8;
            break;
          }
        }
LAB_00d3cc6c:
        if (DAT_04817a08 < 1.0) {
          if ((2.0 < DAT_04817a08) && (DAT_04817d34 * fVar8 <= fVar41)) {
            fVar41 = DAT_04817d34 * fVar8;
          }
        }
        else if (DAT_04817d34 * fVar7 <= fVar41) {
          fVar41 = DAT_04817d34 * fVar7;
        }
        if ((8 < DAT_047b598c) && (fVar41 <= DAT_04817d34 * 10.0)) {
          fVar41 = DAT_04817d34 * 10.0;
        }
        fVar42 = fVar41;
        uVar31 = DAT_048179a8;
        if (DAT_04817d38 < fVar41) {
          fVar42 = DAT_04817d38;
        }
      }
      else {
        DAT_04817ce8 = 0;
        DAT_04817cec = 0;
        DAT_04817d1c = 0;
        DAT_047b598c = 1;
        if (DAT_048179b0 < DAT_048179b4) {
          if (DAT_048179b0 < DAT_048179b4 + -10) {
            DAT_04817cec = 1;
            if (DAT_04817cfc == DAT_04817cf8) {
              DAT_04817cf8 = -DAT_04817cfc;
            }
            else {
              af_printf("!!!!!!!!!!!!!!!!!!!!last dir != cur dir, so skip change dir!!\n");
            }
          }
          fVar42 = DAT_04817cc4 * DAT_04817d34;
        }
        else {
          DAT_04817ce8 = 1;
          fVar42 = DAT_04817cc4 * DAT_04817d34;
        }
        DAT_048179a8 = DAT_048179a4;
        DAT_048179a4 = 3;
        uVar31 = DAT_048179a8;
      }
      break;
    case 4:
      DAT_047b79d8 = local_90;
      DAT_047b5988 = DAT_047b5988 + -1;
      DAT_047b79e0 = local_88;
      DAT_047b79c8 = local_a0;
      DAT_047b79d0 = uStack_98;
      FUN_00d3a770();
      if (DAT_04817cd8 == 0) {
        if (DAT_048179a8 != 4) goto LAB_00d3b6f0;
LAB_00d3c18c:
        iVar14 = (int)(DAT_04817d34 * 5.0);
        if (DAT_04817d1c < 1) goto LAB_00d3b708;
      }
      else {
        iVar32 = DAT_04817a90;
        if (DAT_048179a8 == 4) goto LAB_00d3c18c;
LAB_00d3b6f0:
        DAT_04817cdc = 0;
        DAT_04817ce8 = 0;
        DAT_04817cec = 0;
        DAT_04817d1c = 0;
        iVar14 = (int)(DAT_04817d34 * 5.0);
LAB_00d3b708:
        iVar15 = DAT_04817ccc - DAT_048179e0;
        iVar13 = -iVar15;
        if (-1 < iVar15) {
          iVar13 = iVar15;
        }
        if ((double)DAT_04817cd0 * dVar6 < (double)iVar13) {
          af_printf("add peak check step %d %d!!\n",(int)(DAT_04817d34 * 15.0),
                    (int)(DAT_04817ce4 * 1.5));
          if (DAT_04817ce4 < DAT_04817d34 * 15.0) {
            iVar14 = (int)DAT_04817ce4;
          }
          else {
            iVar14 = (int)(DAT_04817d34 * 15.0);
          }
        }
      }
      if (DAT_04817cdc == 0) {
        iVar14 = (int)(DAT_04817d00 * 0.5);
      }
      af_printf((double)((float)(iVar32 + 1) / (float)DAT_04817cc8),"cur_fv/peak %f\n");
      iVar13 = DAT_04817cdc;
      uVar30 = DAT_048179a4;
      if ((((DAT_04817cd4 == 0) && (DAT_04817cd8 == 0)) &&
          (0x50 < DAT_04817cc8 && iVar32 < DAT_04817cc8)) &&
         ((float)(iVar32 + 1) / (float)DAT_04817cc8 <= 0.5)) {
        local_b8 = CONCAT44(local_b8._4_4_,1);
        af_printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Mybe environment change!!!!!!!!!!!!!!!!!!!!\n")
        ;
        DAT_04817cb0 = 0;
        DAT_04817cb4 = 0;
        DAT_04817cd4 = DAT_04817cd4 + 1;
        DAT_04817d28 = 1;
        DAT_047b5988 = DAT_047b5988 + 0x32;
        DAT_048179a8 = DAT_048179a4;
        DAT_048179a4 = 3;
        FUN_00d3a608();
        goto LAB_00d3b1f4;
      }
      fVar42 = (float)iVar14;
      DAT_048179a4 = 4;
      DAT_048179a8 = uVar30;
      if (iVar32 < DAT_047b7eac) {
        DAT_04817cec = DAT_04817cec + 1;
        if (DAT_04817cec < 2) {
          if (iVar32 <= DAT_04817cc8) {
LAB_00d3cec8:
            iVar15 = DAT_04817ccc - DAT_048179e0;
            iVar14 = -iVar15;
            if (-1 < iVar15) {
              iVar14 = iVar15;
            }
            bVar10 = (double)iVar14 < (double)DAT_04817cd0 * dVar4;
            goto LAB_00d3c1d0;
          }
          if (0 < DAT_047b7ebc) goto LAB_00d3c1c4;
          if (DAT_04817cdc < 2) goto LAB_00d3cec8;
          if (DAT_047b7eac - iVar32 == 1) goto joined_r0x00d3c204;
        }
        else {
LAB_00d3c1c4:
          bVar10 = true;
LAB_00d3c1d0:
          if ((DAT_047b7eac - iVar32 == 1) || (!(bool)(1 < DAT_04817cdc & bVar10)))
          goto joined_r0x00d3c204;
        }
        DAT_04817d1c = DAT_04817d1c + 1;
        DAT_04817cf8 = -DAT_04817cf8;
        fVar42 = DAT_04817d00 * 0.5;
        if (1 < DAT_04817d1c) {
          if (0x46 < (DAT_04817cc8 - iVar32) + 0x23U) goto LAB_00d3b7f8;
          af_printf("search peak done !!!!\n");
          uVar31 = DAT_048179a4;
          DAT_048179a8 = DAT_048179a4;
          DAT_048179a4 = 6;
          break;
        }
        iVar14 = DAT_04817cdc + 1;
        if (DAT_04817cdc + 1 < 0x15) goto LAB_00d3b894;
LAB_00d3c208:
        DAT_04817cdc = DAT_04817cdc + 1;
        if (DAT_04817d1c < 1) {
          fVar42 = DAT_04817d34 * 10.0;
          if (DAT_04817ccc - iVar18 < 1) {
            DAT_04817cf8 = -1;
          }
          else {
            DAT_04817cf8 = 1;
          }
          af_printf("this is not a peak!!!!, retry search !!\n");
          DAT_04817cb0 = 0;
          DAT_04817cb4 = 0;
          DAT_047b5988 = DAT_047b5988 + 0x32;
          DAT_048179a8 = DAT_048179a4;
          DAT_048179a4 = 3;
          FUN_00d3a608();
          if (DAT_048179a4 != 6) {
            uVar31 = DAT_048179a8;
            if (fVar42 < DAT_04817d34 * 5.0) {
              fVar42 = DAT_04817d34 * 5.0;
            }
            break;
          }
        }
        else {
LAB_00d3b7f8:
          DAT_04817cdc = iVar13 + 1;
          af_printf("search peak done, this pos approach peak !!!!\n");
          DAT_048179a8 = DAT_048179a4;
          DAT_048179a4 = 6;
        }
        iVar32 = iVar32 - DAT_04817cc8;
        if ((599 < DAT_04817cc8 || -100 < iVar32) &&
           (DAT_04817cc8 < 0x259 || (int)((double)DAT_04817cc8 * dVar9) < iVar32)) {
          iVar14 = DAT_04817ccc - iVar18;
          iVar13 = -iVar14;
          if (-1 < iVar14) {
            iVar13 = iVar14;
          }
          iVar15 = -iVar32;
          if (-1 < iVar32) {
            iVar15 = iVar32;
          }
          iVar14 = DAT_04817cdc;
          if (iVar15 <= iVar13 * 0x14 || iVar13 < 0x14) goto LAB_00d3b894;
        }
        af_printf("@@@@@@@@@@@this is not a peak!!!!, retry search !!\n");
        fVar42 = DAT_04817d34 * 10.0;
        if (DAT_04817ccc - iVar18 < 1) {
          DAT_04817cf8 = -1;
        }
        else {
          DAT_04817cf8 = 1;
        }
        DAT_047b5988 = DAT_047b5988 + 0x32;
        DAT_04817cb0 = 0;
        DAT_048179a8 = DAT_048179a4;
        DAT_04817cb4 = 0;
        DAT_048179a4 = 3;
        FUN_00d3a608();
        iVar14 = DAT_04817cdc;
      }
      else {
        DAT_04817cec = 0;
joined_r0x00d3c204:
        if (0x14 < DAT_04817cdc + 1) goto LAB_00d3c208;
        DAT_04817cdc = DAT_04817cdc + 1;
        iVar14 = DAT_04817cdc;
        if (1 < DAT_04817d1c) goto LAB_00d3b7f8;
      }
LAB_00d3b894:
      DAT_04817cdc = iVar14;
      uVar31 = DAT_048179a8;
      if (fVar42 < DAT_04817d34 * 5.0) {
        fVar42 = DAT_04817d34 * 5.0;
      }
      break;
    case 5:
      fVar42 = 0.0;
      if (DAT_048179a8 != 4) {
        DAT_04817d1c = 0;
        goto LAB_00d3b1f4;
      }
      goto LAB_00d3b200;
    case 6:
      FUN_00d3a608();
      n3a_af_fv_set_final_focus_point(0);
      DAT_04817cb0 = 0;
      DAT_04817d20 = DAT_047b7e30 + 1;
      DAT_04817cb4 = 0;
      DAT_047b5994 = DAT_048179b0;
      DAT_04817d24 = 1;
      n3a_af_get_roi(&DAT_047b59a4);
      n3a_af_get_roi(&DAT_047b79c8);
      pcVar19 = DAT_04817d60;
      DAT_048179a8 = DAT_048179a4;
      DAT_04817cd4 = 0;
      DAT_04817cd8 = 0;
      DAT_048179a4 = 0;
      if ((DAT_04817d2c == 1) && (DAT_04817d2c = 2, DAT_04817d60 != (code *)0x0)) {
        uVar34 = (**(code **)(DAT_047b79e8 + 0x28))();
        (*pcVar19)(uVar34,0);
      }
      goto LAB_00d3b1f4;
    case 7:
      DAT_04817cf8 = -1;
      local_b0 = CONCAT44(local_b0._4_4_,(iStack_cc + (iStack_cc + local_d0) / 2) / 2);
      FUN_00d3a608();
      DAT_04817cb0 = 0;
      DAT_047b5988 = DAT_047b7e48;
      DAT_04817cb4 = 0;
      DAT_04817cd4 = 0;
      DAT_04817d20 = 3;
      DAT_04817d24 = 3;
      af_printf(0,"CAF_STM_NG %d\n");
      DAT_04817cd8 = 0;
      n3a_af_get_roi(&DAT_047b59a4);
      DAT_047b59b0 = 1.0;
      DAT_047b59b4 = 1.0;
      DAT_047b59a8 = -1.0;
      DAT_047b59ac = -1.0;
      n3a_af_get_roi(&DAT_047b79c8);
      pcVar19 = DAT_04817d60;
      DAT_048179a8 = DAT_048179a4;
      DAT_048179a4 = 0;
      if ((DAT_04817d2c == 1) && (DAT_04817d2c = 2, DAT_04817d60 != (code *)0x0)) {
        uVar34 = (**(code **)(DAT_047b79e8 + 0x28))();
        (*pcVar19)(uVar34,0xffffffff);
      }
LAB_00d3b1f4:
      fVar42 = 0.0;
      uVar31 = DAT_048179a8;
      goto LAB_00d3b1f8;
    }
    if (((0.0 < fVar42) && (fVar42 < 1.0)) || (fVar42 < 0.0)) {
      fVar42 = 1.0;
    }
LAB_00d3b1f8:
    if (uVar31 == 7) {
LAB_00d3b490:
      iVar14 = (int)((float)iVar18 + fVar42 * (float)DAT_04817cf8);
      if (iVar14 < DAT_04817d42 && DAT_04817cf8 == -1) {
        iVar15 = (int)DAT_04817d42;
        iVar13 = iVar15 - DAT_04817d40;
      }
      else {
        bVar10 = false;
        bVar11 = true;
        bVar12 = false;
        if (DAT_04817cf8 == 1) {
          iVar13 = (int)DAT_04817d48._4_2_;
          bVar12 = SBORROW4(iVar14,iVar13);
          bVar10 = iVar14 - iVar13 < 0;
          bVar11 = iVar14 == iVar13;
        }
        if (bVar11 || bVar10 != bVar12) goto LAB_00d3b248;
        iVar15 = (int)DAT_04817d48._4_2_;
        iVar13 = DAT_04817d48._6_2_ - iVar15;
      }
      iVar16 = -iVar13;
      if (-1 < iVar13) {
        iVar16 = iVar13;
      }
      if ((double)(iVar16 / 3) < ABS((double)(iVar14 - iVar15))) {
        fVar42 = fVar42 * 0.5;
      }
    }
    else {
LAB_00d3b200:
      iVar14 = (**(code **)(DAT_047b79e8 + 0x10))();
      if ((iVar14 == 0) && (iVar14 = (**(code **)(DAT_047b79e8 + 8))(), iVar14 == 0))
      goto LAB_00d3b490;
      fVar37 = fVar42;
      if ((iVar18 < DAT_04817d48._4_2_) || (DAT_04817cf8 != 1)) {
LAB_00d3b22c:
        fVar42 = fVar37;
        if ((iVar18 <= DAT_04817d42) && (DAT_04817cf8 == -1)) {
          iVar13 = (int)DAT_04817d42 - (int)DAT_04817d40;
          iVar14 = -iVar13;
          if (-1 < iVar13) {
            iVar14 = iVar13;
          }
          if ((float)(iVar14 / 5) <= fVar37) {
            af_printf("at closest_section slow step\n");
            fVar42 = (float)(iVar14 / 5);
          }
        }
      }
      else {
        iVar13 = (int)DAT_04817d48._6_2_ - (int)DAT_04817d48._4_2_;
        iVar14 = -iVar13;
        if (-1 < iVar13) {
          iVar14 = iVar13;
        }
        fVar37 = (float)(iVar14 / 5);
        if (fVar37 <= fVar42) {
          af_printf("at  infinite_section slow step\n");
          goto LAB_00d3b22c;
        }
      }
    }
LAB_00d3b248:
    if ((fVar42 != 0.0) && (DAT_04817d00 = fVar42, DAT_048179e0 == DAT_048179e4)) {
      fVar42 = fVar42 + 1.0;
      DAT_04817d00 = fVar42;
    }
    if (DAT_048179a4 - 3 < 2) {
      local_70 = 0;
      local_68 = 0;
      local_80 = 0;
      uStack_78 = 0;
      n3a_af_get_roi(&local_80);
      iVar14 = DAT_048179b0;
      if (DAT_04817cd8 != 0) {
        iVar14 = DAT_04817a90;
      }
      DAT_047b7ea4 = iVar14;
      if (DAT_047b8190 == 0) {
        DAT_047b7ed8 = local_70;
        DAT_047b7ee0 = local_68;
        DAT_047b7ec8 = local_80;
        DAT_047b7ed0 = uStack_78;
        DAT_047b7ec4 = 0;
        DAT_047b7e98 = DAT_048179e0;
        DAT_047b7ea0 = DAT_048179e0;
        DAT_047b7ea8 = DAT_04817cf8;
        DAT_047b7eb0 = DAT_048179e0;
        DAT_047b7eb4 = iVar17;
        if ((iVar17 == -1) && (DAT_047b7eb4 = local_e4, DAT_04817cf8 == DAT_047b7e4c)) {
          DAT_047b7eb4 = local_dc;
        }
        DAT_047b7eb8 = 0;
        DAT_047b7ebc = 0;
        DAT_047b7ec0 = 0;
        DAT_047b8190 = 1;
        DAT_047b7e9c = iVar14;
        DAT_047b7eac = iVar14;
      }
      else {
        if (DAT_047b7eac < iVar14) {
          DAT_047b7eb8 = DAT_047b7eb8 + 1;
          DAT_047b7ebc = 0;
          DAT_047b7eb0 = DAT_048179e0;
          DAT_047b7eac = iVar14;
        }
        else {
          DAT_047b7ebc = DAT_047b7ebc + 1;
        }
        DAT_047b7ea0 = DAT_048179e0;
        DAT_047b7ec0 = DAT_047b7ec0 + 1;
        iVar13 = memcmp(&local_80,&DAT_047b7ec8,0x1c);
        if (iVar13 != 0) {
          DAT_047b7ec4 = DAT_047b7ec4 + 1;
        }
        if (DAT_04817cf8 != DAT_04817cfc) {
          piVar27 = (int *)&DAT_047b8144;
          do {
            piVar24 = piVar27 + -0x13;
            *(undefined8 *)piVar27 = *(undefined8 *)piVar24;
            *(undefined8 *)(piVar27 + 2) = *(undefined8 *)(piVar27 + -0x11);
            *(undefined8 *)(piVar27 + 4) = *(undefined8 *)(piVar27 + -0xf);
            *(undefined8 *)(piVar27 + 6) = *(undefined8 *)(piVar27 + -0xd);
            *(undefined8 *)(piVar27 + 8) = *(undefined8 *)(piVar27 + -0xb);
            *(undefined8 *)(piVar27 + 10) = *(undefined8 *)(piVar27 + -9);
            *(undefined8 *)(piVar27 + 0x10) = *(undefined8 *)(piVar27 + -3);
            *(undefined8 *)(piVar27 + 0xc) = *(undefined8 *)(piVar27 + -7);
            *(undefined8 *)(piVar27 + 0xe) = *(undefined8 *)(piVar27 + -5);
            piVar27[0x12] = piVar27[-1];
            piVar27 = piVar24;
          } while (piVar24 != &DAT_047b7e98);
          DAT_047b8190 = DAT_047b8190 + 1;
          DAT_047b7e98 = DAT_048179e0;
          DAT_047b7ea0 = DAT_048179e0;
          DAT_047b7ea8 = DAT_04817cf8;
          DAT_047b7eb0 = DAT_048179e0;
          DAT_047b7eb4 = iVar17;
          if ((iVar17 == -1) && (DAT_047b7eb4 = local_e4, DAT_04817cf8 == DAT_047b7e4c)) {
            DAT_047b7eb4 = local_dc;
          }
          DAT_047b7eb8 = 0;
          DAT_047b7ed8 = local_70;
          DAT_047b7ee0 = local_68;
          DAT_047b7ebc = 0;
          DAT_047b7ec0 = 0;
          DAT_047b7ec4 = 0;
          DAT_047b7ec8 = local_80;
          DAT_047b7ed0 = uStack_78;
          DAT_047b7e9c = iVar14;
          DAT_047b7ea4 = iVar14;
          DAT_047b7eac = iVar14;
        }
        if ((DAT_04817d1c == 1) && (DAT_048179a4 == 3)) {
          af_printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@last peak pos %d\n",DAT_047b7efc);
          DAT_047b7eb4 = DAT_047b7efc;
        }
      }
      FUN_00d3aa58(local_dc,local_e4,iVar17);
    }
    DAT_04817c88 = DAT_04817cf8;
    uVar30 = DAT_048179a4;
    puVar20 = &DAT_04817ca8;
    do {
      puVar21 = puVar20 + -1;
      puVar20[1] = *puVar20;
      puVar20 = puVar21;
    } while (puVar21 != &DAT_04817c84);
    uVar34 = 1;
    DAT_048179ac = (uint)((int)local_b8 == 1);
    local_b8._4_4_ = (int)((float)DAT_04817c88 * fVar42);
    if (uVar30 != 0) {
      af_printf((double)DAT_04817a08,(double)DAT_04817a58,
                "[%s]\tderv %.4f der_k %.4f\t pos %4d fv %5d\tnext step %d continue%d\t\n",
                (&PTR_s_STM_MONITOR_01018030)[(int)DAT_048179a8],DAT_048179e0,DAT_048179b0);
      af_printf((double)local_60._4_4_,(double)(float)local_60,
                "aver_fv %d y_total %lld y_aver %d down %.4f up %.4f max %d min %d\n",
                local_58 & 0xffffffff,local_40,local_38 & 0xffffffff,local_50 & 0xffffffff,
                local_50._4_4_);
    }
LAB_00d3b338:
    *param_2 = local_b8._4_4_;
    *param_3 = (undefined4)local_b0;
    if (DAT_048179a4 == 0 || DAT_048179a4 - 6 < 2) {
      DAT_047b7a00 = 1;
      if ((int)local_b8 == 0) {
        DAT_047b7a00 = 1;
        return uVar34;
      }
    }
    else {
      DAT_047b7a00 = DAT_047b7e30;
      if ((DAT_047b7e38 != 0) && (local_b8._4_4_ <= (int)((float)DAT_047b7e3c * DAT_04817d34))) {
        DAT_047b7a00 = DAT_047b7e40;
      }
      if ((int)local_b8 == 0) {
        return uVar34;
      }
    }
  } while( true );
}



/* FUNCTION n3a_af_saf_task_run @ 00d3e270 body=[[00d3e270, 00d3fc33] [00d3fc38, 00d400d3] [00d400d8, 00d4012b] [00d40130, 00d4016b] [00d40170, 00d40a0b]]
REF Entry Point EXTERNAL caller=NONE
REF 00f1863c INDIRECTION caller=NONE
REF 00fe080c DATA caller=NONE
REF 00d3a27c UNCONDITIONAL_CALL caller=n3a_af_update@00d3a010
*/

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 n3a_af_saf_task_run(int param_1,int *param_2,undefined4 *param_3)

{
  long lVar1;
  ulong uVar2;
  short sVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  float fVar7;
  float fVar8;
  code *pcVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  float *pfVar16;
  float *pfVar17;
  int *piVar18;
  uint *puVar19;
  undefined8 uVar20;
  int *piVar21;
  undefined4 *puVar22;
  undefined8 *puVar23;
  undefined8 *puVar24;
  char *pcVar25;
  uint *puVar26;
  undefined4 *puVar27;
  uint *puVar28;
  undefined1 *puVar29;
  ulong uVar30;
  uint uVar31;
  long lVar32;
  int iVar33;
  int iVar34;
  uint uVar35;
  uint uVar36;
  float fVar37;
  double dVar38;
  float fVar39;
  int local_a0;
  int local_9c;
  uint *local_98;
  undefined4 local_84;
  undefined4 uStack_80;
  uint local_7c;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_60;
  ulong local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulong uStack_28;
  ulong local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  *param_3 = 0;
  *param_2 = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  if (DAT_04817e00 == 0) {
LAB_00d3e408:
    if (DAT_0481a9a8 == 0) goto LAB_00d3e2ec;
  }
  else if (DAT_0481a9a8 == 0) {
    if ((DAT_0481a998._4_4_ != 0) || (DAT_0481a2e8 != 0)) goto LAB_00d3e2ec;
    (*(code *)DAT_04817d78[0xc])(&DAT_0481a2f8,8);
    iVar14 = (int)DAT_0481a306 - (int)DAT_0481a2f8;
    iVar10 = -iVar14;
    if (-1 < iVar14) {
      iVar10 = iVar14;
    }
    if (iVar10 <= DAT_04817e08) goto LAB_00d3e408;
    DAT_0481a9a8 = 1;
    if (DAT_0481a93c == 0) {
      DAT_0481a93c = 1;
      DAT_0481a9a8 = 1;
      return 0;
    }
  }
  if ((int)DAT_0481a990 != 0) {
LAB_00d3e2ec:
    iVar10 = (*(code *)*DAT_04817d78)();
    fVar8 = DAT_00d40a5c;
    fVar7 = DAT_00d40a58;
    dVar6 = DAT_00d40a50;
    dVar5 = DAT_00d40a48;
    dVar4 = DAT_00d40a38;
    if (iVar10 != 0) {
      return 0;
    }
    if (((int)DAT_0481a990 == 1) && (DAT_0481a93c - 1U < 3)) {
      DAT_0481a93c = DAT_0481a93c + 1;
      return 0;
    }
    DAT_0481a2e8 = DAT_0481a2e8 + 1;
    if (DAT_04817d88 + 1 < (ulong)(long)DAT_04817d90) {
      DAT_04817d88 = DAT_04817d88 + 1;
      return 0;
    }
    DAT_04817d88 = 0;
    if (DAT_0481a93c == 0) {
      DAT_0481a93c = 1;
      DAT_04817d88 = 0;
      return 0;
    }
    do {
      while( true ) {
        uVar36 = DAT_04817dfc;
        uVar35 = DAT_04817df8;
        local_60 = 0;
        local_58 = 0;
        local_84 = 1;
        uStack_80 = 1;
        local_50 = 0;
        uStack_48 = 0;
        local_78 = 0;
        local_40 = 0;
        uStack_38 = 0;
        local_70 = local_70 & 0xffffffff;
        local_68 = 0;
        iVar10 = (*(code *)*DAT_04817d78)();
        if (iVar10 != 0) break;
        DAT_04819658 = DAT_04819650;
        (*(code *)DAT_04817d78[0xc])(&DAT_0481a2f8,8);
        (*(code *)DAT_04817d78[0xc])(&DAT_0481a2f8,8);
        sVar3 = DAT_0481a2f8;
        if (0 < (int)DAT_04817df8) {
          sVar3 = DAT_0481a306;
        }
        local_9c = (int)sVar3;
        sVar3 = DAT_0481a2f8;
        if (0 < (int)DAT_04817dfc) {
          sVar3 = DAT_0481a306;
        }
        local_a0 = (int)sVar3;
        local_98 = &local_7c;
        local_7c = 0;
        (*(code *)DAT_04817d78[10])(local_98);
        uVar15 = (int)DAT_0481a306 - (int)DAT_0481a2f8;
        uVar31 = -uVar15;
        if (-1 < (int)uVar15) {
          uVar31 = uVar15;
        }
        if ((DAT_04817e28 == 0) || (0x1f < local_7c)) {
          if (*(int *)(DAT_04817d78 + 0x17) == 1) {
LAB_00d3f104:
            DAT_0481a2f4 = DAT_04817db0;
          }
          else if (DAT_04817d98 < uVar31) {
            if (uVar31 <= DAT_04817da8) goto LAB_00d3f104;
            DAT_0481a2f4 = DAT_04817dc0;
          }
          else {
            DAT_0481a2f4 = DAT_04817da0;
          }
        }
        else {
          DAT_0481a2f4 = *(int *)(DAT_04817e28 + (ulong)local_7c * 0x18 + 0x50);
        }
        local_7c = 0;
        iVar10 = (*(code *)DAT_04817d78[10])(local_98);
        if ((DAT_04817e28 == 0) || (0x1f < local_7c)) {
          if (*(int *)(DAT_04817d78 + 0x17) == 1) {
LAB_00d3f0f4:
            DAT_0481a2f0 = DAT_04817db4;
            dVar38 = (double)DAT_04817db4;
          }
          else if (DAT_04817d98 < uVar31) {
            if (uVar31 <= DAT_04817da8) goto LAB_00d3f0f4;
            if ((float)iVar10 / (float)(int)uVar31 <= (float)DAT_04817dac / (float)DAT_04817da8) {
              DAT_0481a2f0 = ((float)DAT_04817dac / (float)DAT_04817da8) /
                             ((float)iVar10 / (float)(int)uVar31);
              dVar38 = (double)DAT_0481a2f0;
            }
            else {
              DAT_0481a2f0 = 1.0;
              dVar38 = 1.0;
            }
          }
          else {
            DAT_0481a2f0 = DAT_04817da4;
            dVar38 = (double)DAT_04817da4;
          }
        }
        else {
          DAT_0481a2f0 = *(float *)(DAT_04817e28 + (ulong)local_7c * 0x18 + 0x58);
          dVar38 = (double)DAT_0481a2f0;
        }
        af_printf(dVar38,"step factor %.2f\n");
        if ((int)DAT_0481a308 != 0) {
          DAT_0481a2f0 = DAT_0481a2f0 * DAT_0481a308._4_4_;
        }
        if ((DAT_04817e30 == 0) && (DAT_0481961c == 0)) {
          pfVar17 = &DAT_04818fd0;
          do {
            pfVar16 = pfVar17 + 1;
            *pfVar17 = 0.0;
            pfVar17 = pfVar16;
          } while (pfVar16 != &DAT_04819110);
          pfVar17 = &DAT_04819110;
          do {
            *pfVar17 = 0.0;
            pfVar16 = pfVar17 + 1;
            pfVar17[0x50] = 0.0;
            pfVar17 = pfVar16;
          } while (pfVar16 != &DAT_04819250);
          piVar21 = &DAT_04817e3c;
          do {
            piVar18 = piVar21 + 1;
            *piVar21 = -1;
            piVar21 = piVar18;
          } while (piVar18 != &DAT_04817f7c);
          DAT_04817f7c = -1;
          DAT_04817f80 = -1;
          piVar21 = &DAT_04818e88;
          do {
            piVar18 = piVar21 + 1;
            *piVar21 = -1;
            piVar21 = piVar18;
          } while (piVar18 != &DAT_04818fc8);
          puVar19 = (uint *)&DAT_04819390;
          do {
            puVar28 = puVar19 + 1;
            *puVar19 = 0;
            puVar19 = puVar28;
          } while (puVar28 != &DAT_048194d0);
          DAT_04817e38 = 0;
          DAT_04818fc8 = 0;
          DAT_04818fcc = 0;
        }
        iVar10 = (*(code *)DAT_04817d78[5])();
        if (DAT_04817e38 == 0) {
          puVar19 = &DAT_04817f74;
          do {
            puVar28 = puVar19 + -1;
            puVar19[1] = *puVar19;
            puVar19 = puVar28;
          } while (puVar28 != &DAT_04817e38);
          if ((DAT_04817f80 < 1) || (param_1 < DAT_04817f80)) {
            DAT_04817f80 = param_1;
          }
          if ((DAT_04817f7c < 1) || (DAT_04817f7c < param_1)) {
            DAT_04817f7c = param_1;
          }
          puVar22 = &DAT_04818fc0;
          DAT_04817e3c = param_1;
          do {
            puVar27 = puVar22 + -1;
            puVar22[1] = *puVar22;
            puVar22 = puVar27;
          } while (puVar27 != (undefined4 *)((long)&DAT_04818e80 + 4));
          DAT_04818fd0 = DAT_00d40a0c;
          if (((param_1 != -1) && (DAT_04817e40 != -1 && iVar10 != -1)) &&
             (iVar10 != DAT_04818e8c && DAT_04818e8c != -1)) {
            iVar11 = iVar10 - DAT_04818e8c;
            iVar14 = -iVar11;
            if (-1 < iVar11) {
              iVar14 = iVar11;
            }
            DAT_04818fd0 = (float)(param_1 - DAT_04817e40) / (float)iVar14;
          }
          piVar21 = &DAT_04819108;
          DAT_04818e88 = iVar10;
          do {
            piVar18 = piVar21 + -1;
            piVar21[1] = *piVar21;
            piVar21[0x51] = piVar21[0x50];
            piVar21[0xa1] = piVar21[0xa0];
            piVar21 = piVar18;
          } while (piVar18 != &DAT_04818fcc);
          DAT_04819110 = DAT_04818fd0 - DAT_04818fd4;
          DAT_04819390 = (int)DAT_0481a2e0;
          DAT_04819250 = DAT_04819110 - DAT_04819114;
          puVar22 = &DAT_048194c8;
          do {
            puVar27 = puVar22 + -1;
            puVar22[1] = *puVar22;
            puVar22 = puVar27;
          } while (puVar27 != &DAT_0481938c);
          n3a_af_parase_fv_get_trend_info(&local_60);
          local_30 = local_60;
          uStack_28 = local_58;
          local_20 = local_50;
          uStack_18 = uStack_48;
          local_10 = local_40;
          uStack_8 = uStack_38;
          puVar23 = &DAT_04818e58;
          do {
            puVar24 = puVar23 + -6;
            *puVar23 = puVar23[-6];
            puVar23[1] = puVar23[-5];
            puVar23[2] = puVar23[-4];
            puVar23[3] = puVar23[-3];
            puVar23[4] = puVar23[-2];
            puVar23[5] = puVar23[-1];
            puVar23 = puVar24;
          } while (puVar24 != &DAT_04817f88);
          DAT_04817f88 = local_60;
          DAT_04817f90 = local_58;
          _DAT_04817f98 = local_50;
          DAT_04817fa0 = uStack_48;
          DAT_04817fa8 = local_40;
          DAT_04817fb0 = uStack_38;
        }
        (*(code *)DAT_04817d78[0xd])(&local_84,&uStack_80);
        af_printf("max_speed %d\n",local_84);
        local_70 = CONCAT44(local_70._4_4_,local_84);
        iVar14 = FUN_00d3e0f0();
        uVar31 = DAT_04817e30;
        if (iVar14 == 1) {
          DAT_04818fc8 = DAT_04818fc8 + 1;
          if ((DAT_04817e30 != 0) && (DAT_04817e34 != 0)) {
            if (1 < DAT_04818fc8) {
              if ((int)(DAT_04817df4 - DAT_04817d74) < 0xb) goto LAB_00d3ea94;
              pcVar25 = "lens at closest, search peak failed\n";
LAB_00d3ed34:
              af_printf(pcVar25);
              DAT_04817e34 = DAT_04817e30;
              DAT_04817e30 = 7;
            }
            goto LAB_00d3ed48;
          }
          if (DAT_04818fc8 < 2) goto LAB_00d3ed48;
LAB_00d3ea94:
          DAT_04817e30 = 2;
          DAT_04817e34 = uVar31;
          DAT_04819650 = uVar36;
          iVar34 = (int)DAT_0481a304;
          iVar11 = iVar10 - DAT_0481a2fa;
          iVar14 = -iVar11;
          if (-1 < iVar11) {
            iVar14 = iVar11;
          }
          fVar39 = (float)iVar14;
          goto LAB_00d3eac0;
        }
        iVar14 = FUN_00d3e1b0();
        uVar31 = DAT_04817e30;
        if (iVar14 == 1) {
          DAT_04818fcc = DAT_04818fcc + 1;
          if ((DAT_04817e30 == 0) || (DAT_04817e34 == 0)) {
            if (1 < DAT_04818fcc) goto LAB_00d3ee14;
          }
          else if (1 < DAT_04818fcc) {
            if (10 < (int)(DAT_04817df4 - DAT_04817d74)) {
              pcVar25 = "lens at infinite, search peak failed\n";
              goto LAB_00d3ed34;
            }
LAB_00d3ee14:
            DAT_04817e30 = 2;
            iVar34 = (int)DAT_0481a2fa;
            iVar11 = iVar10 - DAT_0481a304;
            iVar14 = -iVar11;
            if (-1 < iVar11) {
              iVar14 = iVar11;
            }
            uVar36 = uVar35;
            fVar39 = (float)iVar14;
            DAT_04817e34 = uVar31;
            DAT_04819650 = uVar35;
            goto LAB_00d3eac0;
          }
        }
LAB_00d3ed48:
        uVar15 = DAT_04817d74;
        if (DAT_04817df4 == DAT_04817d74 && param_1 < 6) {
          local_98 = &DAT_04817d70;
          iVar14 = (*(code *)DAT_04817d78[1])();
          if (iVar14 == 0) {
            uVar15 = local_98[1];
          }
          else {
            local_98[0x496] = 0;
            local_98[0x31] = local_98[0x30];
            local_98[0x30] = 1;
            af_printf("at closest section, fv is too lower, go to infinite\n");
            uVar15 = local_98[1];
          }
        }
        fVar39 = DAT_0481a2e0;
        uVar31 = DAT_04817e30;
        if (((int)uVar15 < 1) || ((DAT_04818fc8 != 0 && (DAT_04818fcc != 0)))) {
          af_printf("search NG, try %d reach_closest %d reach_infinite %d\n",0x50 - uVar15,
                    DAT_04818fc8,DAT_04818fcc);
          DAT_04818fc8 = 0;
          DAT_04818fcc = 0;
switchD_00d3f1b4_caseD_7:
          DAT_04817e30 = 0;
          DAT_04817e34 = 7;
          DAT_04819650 = 0xffffffff;
          local_70 = CONCAT44(1,local_84);
          af_printf("this peack search is NG!!!\n ");
          pcVar9 = DAT_0481a310;
          DAT_04817d70 = 0;
          if (DAT_0481a310 == (code *)0x0) {
            uVar12 = 3;
            uVar31 = DAT_04817e34;
          }
          else {
            uVar20 = (*(code *)DAT_04817d78[5])();
            uVar12 = 3;
            (*pcVar9)(uVar20,0xffffffff);
            uVar31 = DAT_04817e34;
          }
LAB_00d3edf8:
          iVar34 = -1;
          fVar39 = 0.0;
          uVar36 = DAT_04819650;
        }
        else {
          switch(DAT_04817e30) {
          case 0:
            if (DAT_04817e34 != 0) {
              DAT_04817e30 = 0;
              DAT_04817e34 = 0;
              DAT_04819640 = 0;
              DAT_04819644 = 0;
              DAT_0481964c = 0;
            }
            if (DAT_0481961c == 0) {
              DAT_04819640 = 0;
              DAT_04819644 = 0;
              DAT_0481964c = 0;
            }
            af_printf("SAF_STM_IDLE  !!\n");
            DAT_04817d74 = DAT_04817d74 - 1;
            DAT_0481961c = DAT_0481961c + 1;
            iVar14 = FUN_00d3e1b0();
            uVar31 = DAT_04817e30;
            if (iVar14 == 0) {
              iVar14 = FUN_00d3e0f0();
              uVar31 = DAT_04817e30;
              if (iVar14 == 0) {
                if (DAT_0481961c == 1) {
                  if (DAT_0481a9a8 == 0) {
                    iVar14 = (*(code *)DAT_04817d78[1])();
                    DAT_04819650 = uVar35;
                    if (iVar14 != 0) {
                      DAT_04819650 = uVar36;
                    }
                  }
                  else {
                    DAT_04819650 = DAT_0481a988._4_4_;
                  }
                  uVar36 = DAT_04817e30;
                  if (DAT_04817e34 != 1) {
                    uVar35 = DAT_04819650;
                  }
                  DAT_04819650 = uVar35;
                  DAT_04817e30 = 0;
                  DAT_04817e34 = uVar36;
                  DAT_04819640 = 0;
                  DAT_04819644 = 0;
                  DAT_04819658 = DAT_04819650;
                  af_printf("STM_IDEL init search dirction fv %d !!\n",DAT_04817e3c);
                }
                else if (DAT_04817e40 < DAT_04817e3c) {
                  DAT_04819644 = 0;
                  DAT_04819640 = DAT_04819640 + 1;
                  if (0x32 < DAT_04817e3c) {
                    if (DAT_04817e40 + 0xe < DAT_04817e3c) {
LAB_00d402f0:
                      iVar34 = -1;
                      af_printf("STM_IDEL search dirction fv %d  %d!!\n");
                      DAT_04817e34 = DAT_04817e30;
                      DAT_04817e30 = 2;
                      fVar39 = (float)((double)DAT_0481a2e0 * DAT_00d40a20);
                      uVar36 = DAT_04819650;
                      uVar31 = DAT_04817e34;
                      break;
                    }
                    if (1 < DAT_04819640) {
                      iVar14 = DAT_04819640;
                      if (0x50 < DAT_04819640) {
                        iVar14 = 0x50;
                      }
                      iVar11 = DAT_04817e3c - (&DAT_04817e3c)[iVar14];
                      iVar14 = -iVar11;
                      if (-1 < iVar11) {
                        iVar14 = iVar11;
                      }
                      if (0xe < iVar14) goto LAB_00d402f0;
                    }
                  }
                }
                else if (DAT_04817e3c < DAT_04817e40) {
                  DAT_04819640 = 0;
                  iVar14 = DAT_04819644 + 1;
                  if (DAT_04817e40 < 0x33) {
LAB_00d40650:
                    if ((2 < iVar14) && (DAT_0481964c < 2)) {
                      DAT_0481964c = DAT_0481964c + 1;
                      uVar36 = -DAT_04819650;
                      puVar19 = &DAT_04819394;
                      fVar39 = (float)DAT_04819390 + 0.0;
                      do {
                        fVar39 = fVar39 + (float)(int)*puVar19;
                        if (&DAT_04817d70 + (ulong)(DAT_04819644 - 1) + 0x589 == puVar19) break;
                        puVar19 = puVar19 + 1;
                      } while (puVar19 != &DAT_048194d0);
                      iVar34 = -1;
                      fVar39 = fVar39 + DAT_0481a2f0 * 20.0;
                      DAT_04819644 = iVar14;
                      DAT_04819650 = uVar36;
                      uVar31 = DAT_04817e34;
                      break;
                    }
                  }
                  else {
                    if (DAT_04817e3c + 0xe < DAT_04817e40) {
                      if (iVar14 < 1) {
                        fVar39 = 0.0;
                        DAT_04819644 = iVar14;
                        DAT_04819650 = -DAT_04819650;
                      }
                      else {
LAB_00d40510:
                        DAT_04819650 = -DAT_04819650;
                        fVar39 = 0.0;
                        local_98 = (uint *)&DAT_04819390;
                        iVar11 = 0;
                        DAT_04819644 = iVar14;
                        do {
                          uVar35 = *local_98;
                          iVar11 = iVar11 + 1;
                          fVar39 = fVar39 + (float)(int)uVar35;
                          local_98 = local_98 + 1;
                          af_printf("s_saf_obj.step_history[i] %d\n",uVar35);
                        } while (iVar11 < 0x50 && iVar11 < DAT_04819644);
                      }
                      iVar34 = -1;
                      DAT_04817e34 = DAT_04817e30;
                      fVar39 = fVar39 + DAT_0481a2f0 * 10.0;
                      DAT_04817e30 = 2;
                      af_printf("STM_IDEL search dirction done dir %d!!\n",DAT_04819650);
                      uVar36 = DAT_04819650;
                      uVar31 = DAT_04817e34;
                      break;
                    }
                    if (1 < iVar14) {
                      iVar11 = iVar14;
                      if (0x50 < iVar14) {
                        iVar11 = 0x50;
                      }
                      iVar34 = DAT_04817e3c - (&DAT_04817e3c)[iVar11];
                      iVar11 = -iVar34;
                      if (-1 < iVar34) {
                        iVar11 = iVar34;
                      }
                      if (0xe < iVar11) goto LAB_00d40510;
                      goto LAB_00d40650;
                    }
                  }
                  DAT_04819644 = iVar14;
                  if (((DAT_04817e3c >= 0 && DAT_04817e40 < 0) == DAT_04817e3c < 0) &&
                     (-1 < DAT_04817e44 && 9 < DAT_04817e40)) {
                    iVar11 = 0;
                    if (DAT_04817e3c + 1 != 0) {
                      iVar11 = (DAT_04817e40 + 1) / (DAT_04817e3c + 1);
                    }
                    if (5 < iVar11) {
                      iVar11 = 0;
                      if (DAT_04817e44 + 1 != 0) {
                        iVar11 = (DAT_04817e40 + 1) / (DAT_04817e44 + 1);
                      }
                      if (5 < iVar11) {
                        DAT_04819650 = -DAT_04819650;
                        DAT_0481964c = DAT_0481964c + 1;
                        pcVar25 = "peak is on back !!!!\n";
                        fVar39 = (float)((double)DAT_0481a2e0 * DAT_00d40a20);
                        goto LAB_00d401dc;
                      }
                    }
                  }
                }
                else {
                  DAT_04819640 = 0;
                  DAT_04819644 = 0;
                  af_printf("dir fv equal !!!!!!!!!!!!!!!!!!\n");
                  iVar14 = FUN_00d3e1b0();
                  if ((iVar14 != 0) || (iVar14 = FUN_00d3e0f0(), iVar14 != 0)) {
                    uVar12 = 1;
                    DAT_04817e34 = DAT_04817e30;
                    DAT_04817e30 = 6;
                    af_printf("STM_IDEL is at infinite or closest done\n");
                    uVar31 = DAT_04817e34;
                    goto LAB_00d3edf8;
                  }
                }
                if (DAT_0481961c < 2) {
                  fVar39 = DAT_00d40a10;
                  if ((0x31 < DAT_04817e3c) && (fVar39 = 25.0, 99 < DAT_04817e3c)) {
                    fVar39 = 10.0;
                  }
                  fVar39 = fVar39 * DAT_0481a2f0;
                }
                else {
                  fVar39 = (float)((DAT_0481961c + -1) * 0x1e) + DAT_0481a2e0 * 0.5 + 0.0;
                }
                if (DAT_04819658 != DAT_04819650) {
                  fVar39 = (float)DAT_0481a2f4 * 0.25;
                }
                if ((0 < DAT_04817e40) &&
                   (5.0 <= ABS((double)(DAT_04817e40 - DAT_04817e3c)) / (double)(DAT_04817e40 + 1)))
                {
                  fVar39 = (float)((double)DAT_0481a2e0 * DAT_00d40a20);
                  af_printf("fv change too much!!!\n");
                }
                iVar34 = -1;
                if ((float)DAT_0481a2f4 < fVar39) {
                  fVar39 = (float)DAT_0481a2f4;
                }
                af_printf((double)fVar39,"idel next step %d\n");
                uVar36 = DAT_04819650;
                uVar31 = DAT_04817e34;
              }
              else {
                DAT_04819650 = uVar36;
                DAT_04819658 = uVar36;
                if (param_1 < 0x1e) {
                  fVar39 = DAT_0481a2f0 * DAT_00d40a10;
                }
                else {
                  fVar39 = DAT_0481a2f0 * 25.0;
                }
                iVar34 = -1;
                DAT_04817e30 = 2;
                DAT_04817e34 = uVar31;
              }
            }
            else {
              DAT_04819650 = uVar35;
              if (param_1 < 0x1e) {
                fVar39 = DAT_0481a2f0 * DAT_00d40a10;
              }
              else {
                fVar39 = DAT_0481a2f0 * 25.0;
              }
              iVar34 = -1;
              DAT_04817e30 = 2;
              DAT_04817e34 = uVar31;
              uVar36 = uVar35;
              DAT_04819658 = uVar35;
            }
            break;
          case 1:
            fVar39 = (float)(iVar10 - DAT_0481a304);
            if (fVar39 < 0.0) {
              fVar39 = -fVar39;
              DAT_04819650 = 1;
              uVar36 = DAT_04817e30;
            }
            else {
              DAT_04819650 = 0xffffffff;
              uVar36 = 0xffffffff;
            }
            iVar34 = -1;
            DAT_04817e30 = 0;
            DAT_04817e34 = 1;
            break;
          case 2:
            DAT_04817d74 = uVar15 - 1;
            if (DAT_04817e34 != 2) {
              DAT_04819640 = 0;
              DAT_04819644 = 0;
              DAT_04819654 = 0;
              if ((float)DAT_0481a2f4 < DAT_0481a2e0) {
                af_printf("^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                DAT_0481a2e0 = (float)DAT_0481a2f4;
              }
              if ((DAT_04818e88 - DAT_04818e8c) * (DAT_04818e8c - DAT_04818e90) < 0) {
                DAT_0481a2e0 = DAT_0481a2f0 * DAT_00d40a30;
                af_printf((double)DAT_0481a2e0,"@@@crose base step is %f\n");
                DAT_04817e34 = DAT_04817e30;
              }
              else {
                af_printf((double)DAT_0481a2e0,"!!!crose base step is %f\n");
                DAT_0481a2e0 = (float)((double)DAT_0481a2e0 * DAT_00d40a28);
                af_printf((double)DAT_0481a2e0,"!!!crose base step is %f\n");
                DAT_04817e34 = DAT_04817e30;
              }
            }
            DAT_04817e30 = 2;
            if (DAT_04817e40 < DAT_04817e3c) {
              fVar37 = DAT_0481a2e0;
              if (local_60._4_4_ < (float)local_60) {
                DAT_04819644 = 0;
                DAT_04819640 = DAT_04819640 + 1;
                fVar39 = DAT_04818fd0 - DAT_04818fd4;
                if ((1.0 <= fVar39) || (fVar39 <= 0.0)) {
                  if (fVar39 < 0.0) {
                    if (param_1 < 0x65) {
                      fVar37 = DAT_0481a2e0 * 1.5;
                    }
                    else if (ABS(fVar39) <= 1.5) {
                      fVar37 = (float)(int)((double)DAT_0481a2e0 * DAT_00d40a40);
                    }
                    else {
                      fVar37 = (float)(int)((double)DAT_0481a2e0 * DAT_00d40a38);
                    }
                    if (fVar37 <= DAT_0481a2f0 * 30.0) {
                      fVar37 = DAT_0481a2f0 * 30.0;
                    }
                  }
                  else if ((DAT_04818fd0 <= 0.0) || (0.0 <= DAT_04818fd4)) {
                    if ((1.0 <= DAT_04818fd4) ||
                       (((1.0 <= DAT_04818fd8 || (DAT_04818fd8 <= 0.0)) ||
                        (DAT_04818fd0 / DAT_04818fd4 < 1.0)))) {
                      if ((DAT_04818fd4 <= 1.0) || (DAT_04818fd0 / DAT_04818fd4 < 1.5)) {
                        if (DAT_04818fd4 / DAT_04818fd0 < 1.0) goto LAB_00d409c4;
                        fVar37 = (float)((double)DAT_0481a2e0 * DAT_00d40a48);
                      }
                      else {
                        fVar37 = (DAT_04818fd4 / DAT_04818fd0) * DAT_0481a2e0;
                        af_printf("begain slow !!!\n");
                      }
                    }
                    else {
                      af_printf("last derivative_history[0]climb fv increase so fast, slow it!!!\n")
                      ;
                      fVar37 = DAT_00d40a18;
                    }
                  }
                  else {
                    fVar37 = DAT_0481a2e0 * 0.5;
                  }
                }
                else if (param_1 < 0x65) {
                  fVar37 = DAT_0481a2e0 + DAT_0481a2e0;
                }
                else {
LAB_00d409c4:
                  fVar37 = DAT_0481a2e0 * 1.5;
                }
              }
            }
            else {
              fVar37 = DAT_0481a2e0;
              if (DAT_04817e3c < DAT_04817e40) {
                DAT_04819644 = DAT_04819644 + 1;
                iVar14 = DAT_04819644;
                if (0x50 < DAT_04819644) {
                  iVar14 = 0x50;
                }
                iVar14 = (&DAT_04817e3c)[iVar14];
                fVar39 = DAT_00d40a14;
                if (iVar14 < 0xfa) {
                  fVar39 = 0.5;
                }
                if ((DAT_04817e3c < 0x3d || DAT_04819640 < 2) || DAT_04819644 < 2) {
                  if (1 < DAT_04819644) goto LAB_00d3f568;
LAB_00d3ffb4:
                  dVar38 = (double)DAT_0481a2e0 * DAT_00d40a40;
LAB_00d3f5dc:
                  fVar37 = (float)dVar38;
                  if (DAT_04819654 < 4) goto LAB_00d3f5f4;
                  iVar34 = -1;
                  DAT_04819644 = 0;
                  DAT_04819650 = -DAT_04819650;
                  iVar14 = FUN_00d3e000();
                  fVar39 = (float)iVar14;
                  af_printf("reach max switch dir counts!!!\n");
                  DAT_04817e34 = DAT_04817e30;
                  DAT_04817e30 = 3;
                  uVar36 = DAT_04819650;
                  uVar31 = DAT_04817e34;
                }
                else {
                  if (iVar14 - DAT_04817e3c < (int)((float)iVar14 * fVar39)) {
LAB_00d3f568:
                    if (((DAT_04819640 < 1) || (DAT_04819670 - DAT_04817e3c < 0x51)) ||
                       (DAT_00d40a50 <= (double)DAT_04819640)) {
                      if (DAT_04819644 < 3) goto LAB_00d3ffb4;
                      DAT_04819654 = DAT_04819654 + 1;
                      DAT_04819650 = -DAT_04819650;
                      af_printf("reach max down_count, switch dir!!\n");
                      DAT_04819644 = 0;
                      dVar38 = (double)DAT_0481a2e0 * DAT_00d40a40;
                      goto LAB_00d3f5dc;
                    }
                    DAT_04819650 = -DAT_04819650;
                    iVar14 = FUN_00d3e000();
                    fVar39 = (float)iVar14;
                    DAT_04817e34 = DAT_04817e30;
                    DAT_04817e30 = 3;
                    af_printf("reach max down counts !!\n");
                    pcVar25 = "af down hill!!!\n";
                  }
                  else {
                    DAT_04819650 = -DAT_04819650;
                    iVar14 = FUN_00d3e000();
                    fVar39 = (float)iVar14;
                    pcVar25 = "af down hill!!!\n";
                    DAT_04817e34 = DAT_04817e30;
                    DAT_04817e30 = 3;
                  }
LAB_00d401dc:
                  af_printf(pcVar25);
                  iVar34 = -1;
                  uVar36 = DAT_04819650;
                  uVar31 = DAT_04817e34;
                }
                break;
              }
            }
LAB_00d3f5f4:
            if ((fVar7 < DAT_04818fd0) && (DAT_0481a2f0 * DAT_00d40a18 < fVar37)) {
              fVar37 = DAT_0481a2f0 * DAT_00d40a18;
            }
            if ((30.0 < DAT_04818fd0) && (DAT_0481a2f0 * DAT_00d40a30 < fVar37)) {
              fVar37 = DAT_0481a2f0 * DAT_00d40a30;
            }
            if ((100 < DAT_04817e40) &&
               (2.0 <= ABS((double)DAT_04817e40) / (double)(DAT_04817e3c + 1))) {
              fVar37 = (float)((double)DAT_0481a2e0 * DAT_00d40a20);
              af_printf("fv change too much!!!\n");
            }
            if (((0x13 < DAT_04817e3c) || (0x13 < DAT_04817e40)) ||
               (5.0 <= ABS((double)(DAT_04817e40 - DAT_04817e3c)) / (double)(DAT_04817e40 + 1))) {
              if ((int)DAT_04817d74 < (int)(DAT_04817df4 - 8)) {
                uVar35 = 0;
                iVar14 = DAT_04818e88 - DAT_04818e8c;
                piVar21 = &DAT_04817e3c;
                iVar11 = DAT_04818e8c;
                while (0 < (DAT_04818e88 - DAT_04818e8c) * iVar14) {
                  uVar35 = uVar35 + *piVar21;
                  if (piVar21 + 1 == (int *)&DAT_04817e4c) {
                    uVar35 = uVar35 >> 2;
                    fVar39 = (float)(uVar35 + 1);
                    goto LAB_00d3fe70;
                  }
                  piVar18 = piVar21 + 0x415;
                  iVar14 = iVar11 - *piVar18;
                  piVar21 = piVar21 + 1;
                  iVar11 = *piVar18;
                }
              }
              else {
                fVar39 = 1.0;
                uVar35 = 0;
LAB_00d3fe70:
                fVar39 = (float)(int)(DAT_04817e3c - uVar35) / fVar39;
                if ((0.0 < fVar39) && ((double)fVar39 < dVar6)) {
                  af_printf("@@@@@@@@@@@@@@@@@fv is flat !!!!!!!!!!!!!!!!!!!!!!!!\n");
                  fVar37 = (float)((double)DAT_0481a2e0 * DAT_00d40a48);
                }
              }
LAB_00d3f6d8:
              fVar39 = (float)DAT_0481a2f4;
              if (fVar37 <= fVar39) goto LAB_00d3fddc;
            }
            else {
              if (DAT_04817e3c != 0 && DAT_04817e40 != DAT_04817e3c) {
                if ((double)fVar37 < (double)DAT_0481a2f4 * dVar4) {
                  fVar37 = (float)((double)DAT_0481a2f4 * dVar4);
                  af_printf((double)fVar37,"low fv next step %f\n");
                }
                goto LAB_00d3f6d8;
              }
              fVar37 = (float)DAT_0481a2f4;
LAB_00d3fddc:
              fVar39 = fVar37;
              if (fVar39 <= DAT_0481a2f0 * 25.0) {
                fVar39 = DAT_0481a2f0 * fVar8;
              }
            }
            iVar34 = -1;
            af_printf((double)fVar39,"crose next step %f!!\n");
            uVar36 = DAT_04819650;
            uVar31 = DAT_04817e34;
            break;
          case 3:
            if (DAT_04817e34 != 3) {
              DAT_04819620 = 0;
              DAT_04819624 = 0;
              DAT_04819628 = 0;
            }
            DAT_04817e30 = 3;
            DAT_04817e34 = 3;
            iVar14 = DAT_04817f98;
            iVar11 = DAT_04817fc8;
            if (DAT_0481a934 == 0) {
              iVar14 = DAT_04817e3c;
              iVar11 = DAT_04817e40;
            }
            DAT_04817d74 = uVar15 - 1;
            if (DAT_04817e3c != -1) {
              if (((DAT_04817e40 == -1) || (DAT_04817e44 == -1)) || (DAT_04817e48 == -1)) {
                uVar12 = 1;
                goto LAB_00d3edf8;
              }
              if ((DAT_04819620 < 0x14) && (DAT_04819628 == 0)) {
                if (DAT_04819620 == 0) {
                  if (1 < DAT_04819630 - DAT_04818e88) {
                    DAT_04819650 = 1;
                    if (iVar14 < DAT_0481962c) {
LAB_00d40794:
                      iVar14 = DAT_04818e88 - DAT_04819630;
                      goto joined_r0x00d40164;
                    }
                    goto LAB_00d3f3c0;
                  }
                  DAT_04819650 = 0xffffffff;
                  if (DAT_0481962c <= iVar14) goto LAB_00d3f3c0;
                }
                else {
                  if (iVar14 < DAT_0481962c) {
                    if (DAT_04819650 == 1) goto LAB_00d40794;
                    if (DAT_04819650 != 0xffffffff) goto LAB_00d3f3cc;
                    iVar14 = DAT_04819630 - DAT_04818e88;
joined_r0x00d40164:
                    if (iVar14 < 0x14) goto LAB_00d3f3cc;
                  }
LAB_00d3f3c0:
                  DAT_04819628 = 1;
                }
LAB_00d3f3cc:
                af_printf("fine search, keep moving, close to peak peak_fv %d peak_pos %d\n",
                          DAT_0481962c,DAT_04819630);
                uVar31 = DAT_04817e34;
              }
              else if (iVar14 < iVar11 + -1) {
                DAT_04819640 = 0;
                DAT_04819644 = DAT_04819644 + 1;
                if (((DAT_04818fd0 < 0.0) && (0.0 < DAT_04818fd4)) &&
                   ((ABS(DAT_04818fd0) < -0.5 &&
                    ((0.5 < ABS(DAT_04818fd4) && (ABS(DAT_04818fd0 + DAT_04818fd4) < 2.5)))))) {
                  local_78 = CONCAT44(local_78._4_4_,1);
                }
                fVar39 = DAT_0481a2e0 * 0.5;
                if (0 < DAT_04819620) {
                  if ((DAT_04819624 < 1) &&
                     (((DAT_04819624 != 0 || (iVar14 + 0xe < DAT_0481962c)) && (DAT_04819644 < 2))))
                  {
                    fVar39 = (float)((double)DAT_0481a2e0 * dVar5);
LAB_00d4088c:
                    if ((DAT_04819624 != 1) || (iVar14 <= DAT_0481962c)) goto LAB_00d40070;
                  }
                  else {
                    DAT_04819624 = DAT_04819624 + 1;
                    DAT_04819650 = -DAT_04819650;
                    if (DAT_04819624 < 2) goto LAB_00d4088c;
                  }
                  DAT_04817e30 = 4;
                  DAT_0481962c = iVar11;
                }
LAB_00d40070:
                af_printf("[STM] fine search to peak search\n");
                uVar31 = DAT_04817e34;
              }
              else {
                DAT_04819644 = 0;
                DAT_04819640 = DAT_04819640 + 1;
                if (DAT_04819620 < 1) {
                  fVar39 = DAT_0481a2e0 * 0.5;
                }
                else if (DAT_04818fd0 - DAT_04818fd4 <= 0.0) {
                  if (DAT_04818fd0 - DAT_04818fd4 < 0.0) {
                    fVar39 = DAT_0481a2e0 * 1.5 + 0.5;
                  }
                }
                else {
                  fVar39 = (float)(dVar5 * (double)DAT_0481a2e0 + 0.5);
                }
              }
              DAT_04819620 = DAT_04819620 + 1;
              if (DAT_04819620 < 3) {
                fVar37 = DAT_0481a2f0 * fVar7;
                if (fVar37 < fVar39) {
                  fVar39 = fVar37;
                }
              }
              else if (DAT_0481a2f0 * 20.0 < fVar39) {
                fVar39 = DAT_0481a2f0 * 20.0;
              }
              uVar36 = DAT_04819650;
              if ((float)DAT_04817d84 * DAT_0481a2f0 < fVar39) {
                iVar34 = -1;
              }
              else {
                iVar34 = -1;
                fVar39 = (float)DAT_04817d84 * DAT_0481a2f0;
              }
              break;
            }
            iVar34 = -1;
            if (DAT_04819658 == DAT_04819650) {
              fVar39 = 0.0;
              uVar12 = 1;
              uVar36 = DAT_04819650;
            }
            else {
              uVar12 = 1;
              fVar39 = 0.0;
              DAT_04819648 = 1;
              uVar36 = DAT_04819650;
            }
            goto LAB_00d3eb10;
          case 4:
            if (DAT_04817e34 != 4) {
              DAT_0481962c = 0;
              DAT_04819634 = 0;
            }
            DAT_04817e30 = 4;
            DAT_04817e34 = 4;
            iVar11 = DAT_04817e40;
            iVar14 = DAT_04817e3c;
            if (DAT_0481a934 != 0) {
              iVar11 = DAT_04817fc8;
              iVar14 = DAT_04817f98;
            }
            DAT_04817d74 = uVar15 - 1;
            if (iVar14 < iVar11) {
              DAT_04819634 = DAT_04819634 + 1;
              DAT_04819650 = -DAT_04819650;
              fVar39 = DAT_0481a2e0 * 0.5;
            }
            else if (iVar14 == iVar11) {
              fVar39 = DAT_0481a2e0 + DAT_0481a2e0;
            }
            else {
              fVar39 = (float)DAT_04817d84 * DAT_0481a2f0;
            }
            if (DAT_04819634 == 1) {
              if (DAT_04819658 != DAT_04819650) goto LAB_00d3ff38;
            }
            else if (DAT_04819634 < 2) {
LAB_00d3ff38:
              fVar37 = (float)DAT_04817d84 * DAT_0481a2f0 + (float)DAT_04817d84 * DAT_0481a2f0;
              if (fVar37 < fVar39) {
                fVar39 = fVar37;
              }
              iVar34 = -1;
              uVar36 = DAT_04819650;
              break;
            }
            af_printf("s_saf_obj.step_history[1] %d\n",DAT_04819398);
            DAT_04817e34 = DAT_04817e30;
            DAT_04817e30 = 6;
            iVar14 = 0x4f;
            lVar32 = 0x4f;
            piVar21 = &DAT_04817f78;
            do {
              lVar1 = (long)iVar14;
              if (*piVar21 <= (&DAT_04817e3c)[lVar32]) {
                lVar1 = lVar32;
              }
              iVar14 = iVar14 + -1;
              lVar32 = lVar1;
              piVar21 = piVar21 + -1;
            } while (iVar14 != 0);
            fVar39 = (float)(iVar10 - (&DAT_04818e88)[lVar1]);
            uVar31 = DAT_04817e34;
            if (fVar39 < 0.0) {
              iVar34 = -1;
              DAT_04819650 = 1;
              uVar36 = 1;
              fVar39 = -fVar39;
            }
            else {
              iVar34 = -1;
              DAT_04819650 = 0xffffffff;
              uVar36 = 0xffffffff;
            }
            break;
          default:
            uVar12 = 1;
            iVar34 = -1;
            fVar39 = 0.0;
            uVar36 = DAT_04819650;
            uVar31 = DAT_04817e34;
            goto LAB_00d3eaf4;
          case 6:
            n3a_af_fv_set_final_focus_point(0);
            DAT_04817e34 = DAT_04817e30;
            DAT_04817e30 = 0;
            local_70 = CONCAT44(1,(undefined4)local_70);
            local_68 = 1;
            af_printf("SAF_STM_DONE_OK!!!!!!!11\n");
            pcVar9 = DAT_0481a310;
            DAT_04817d70 = 0;
            if (DAT_0481a310 == (code *)0x0) {
              uVar12 = 2;
              uVar31 = DAT_04817e34;
            }
            else {
              uVar12 = 2;
              uVar20 = (*(code *)DAT_04817d78[5])();
              (*pcVar9)(uVar20,0);
              uVar31 = DAT_04817e34;
            }
            goto LAB_00d3edf8;
          case 7:
            goto switchD_00d3f1b4_caseD_7;
          }
LAB_00d3eac0:
          if ((0.0 < fVar39) && (fVar37 = (float)DAT_04817d84 * DAT_0481a2f0 * 0.5, fVar39 < fVar37)
             ) {
            fVar39 = fVar37;
          }
          uVar12 = 1;
        }
LAB_00d3eaf4:
        if (DAT_04819658 != uVar36) {
          DAT_04819648 = 1;
        }
        if (uVar31 == 7) {
LAB_00d3eb5c:
          if ((0.0 < fVar39) && (fVar37 = 1.0, fVar39 < 1.0)) goto LAB_00d3ee4c;
          iVar10 = DAT_04819678;
          if (fVar39 < 0.0) {
            fVar37 = 1.0;
            fVar39 = 1.0;
            DAT_0481a2e0 = fVar39;
            if (DAT_04818e88 != DAT_04818e8c) goto joined_r0x00d3eb94;
            goto LAB_00d3f128;
          }
          fVar37 = fVar39;
          if (fVar39 != 0.0) goto LAB_00d3ee4c;
        }
        else {
LAB_00d3eb10:
          fVar37 = (float)iVar10 + fVar39 * (float)(int)uVar36;
          if (fVar37 < (float)(DAT_0481a306 + -0x32) || uVar36 != 1) {
LAB_00d3eb3c:
            if ((((float)(DAT_0481a2f8 + 0x32) < fVar37 || uVar36 != 0xffffffff) ||
                (fVar39 = fVar39 / 3.0, DAT_0481a2f8 + 0x32 < iVar10)) || (fVar39 <= 15.0))
            goto LAB_00d3eb5c;
            af_printf("at infinite_section slow step\n");
            fVar37 = 10.0;
          }
          else {
            fVar39 = fVar39 / 3.0;
            if ((iVar10 < DAT_0481a306 + -0x32) || (fVar39 <= 15.0)) {
              fVar37 = (float)iVar10 + fVar39 * (float)(int)uVar36;
              goto LAB_00d3eb3c;
            }
            fVar37 = 10.0;
          }
LAB_00d3ee4c:
          fVar39 = fVar37;
          iVar10 = DAT_04819678;
          DAT_0481a2e0 = fVar37;
          if (DAT_04818e88 == DAT_04818e8c) {
LAB_00d3f128:
            fVar39 = fVar37 + 1.0;
            iVar10 = DAT_04819678;
            DAT_0481a2e0 = fVar39;
          }
        }
joined_r0x00d3eb94:
        DAT_04819678 = iVar34;
        if ((DAT_04817e30 & 0xfffffffd) == 0) {
          DAT_04819664 = DAT_04818e88;
          if (DAT_0481a2dc == 0) {
            if (DAT_04819678 == -1) {
              piVar21 = &local_a0;
              if (DAT_04819650 == DAT_04817df8) {
                piVar21 = &local_9c;
              }
              DAT_04819678 = *piVar21;
            }
            DAT_0481967c = 0;
            DAT_04819680 = 0;
            DAT_0481a2dc = 1;
            DAT_0481965c = DAT_04818e88;
            DAT_04819660 = DAT_04817e3c;
            DAT_04819668 = DAT_04817e3c;
            DAT_0481966c = DAT_04819650;
            DAT_04819670 = DAT_04817e3c;
            DAT_04819674 = DAT_04818e88;
            iVar10 = DAT_04819678;
          }
          else {
            if (DAT_04819670 < DAT_04817e3c) {
              DAT_0481967c = DAT_0481967c + 1;
              DAT_04819680 = 0;
              DAT_04819670 = DAT_04817e3c;
              DAT_04819674 = DAT_04818e88;
            }
            else {
              DAT_04819680 = DAT_04819680 + 1;
            }
            if (DAT_04819650 != DAT_04819658) {
              piVar21 = (int *)&DAT_0481a2b4;
              do {
                piVar18 = piVar21 + -10;
                *(undefined8 *)piVar21 = *(undefined8 *)piVar18;
                *(undefined8 *)(piVar21 + 2) = *(undefined8 *)(piVar21 + -8);
                *(undefined8 *)(piVar21 + 8) = *(undefined8 *)(piVar21 + -2);
                *(undefined8 *)(piVar21 + 4) = *(undefined8 *)(piVar21 + -6);
                *(undefined8 *)(piVar21 + 6) = *(undefined8 *)(piVar21 + -4);
                piVar21 = piVar18;
              } while (piVar18 != &DAT_0481965c);
              DAT_0481a2dc = DAT_0481a2dc + 1;
              DAT_0481965c = DAT_04818e88;
              DAT_04819664 = DAT_04818e88;
              DAT_04819674 = DAT_04818e88;
              DAT_04819660 = DAT_04817e3c;
              DAT_04819670 = DAT_04817e3c;
              DAT_0481966c = DAT_04819650;
              if ((DAT_04819678 == -1) && (DAT_04819678 = local_a0, DAT_04819650 == DAT_04817df8)) {
                DAT_04819678 = local_9c;
              }
              DAT_0481967c = 0;
              DAT_04819680 = 0;
              iVar10 = DAT_04819678;
            }
            DAT_04819678 = iVar10;
            DAT_04818e88 = DAT_04819664;
            DAT_04819668 = DAT_04817e3c;
            iVar10 = DAT_04819678;
            if ((DAT_04819654 == 1) && (DAT_04817e30 == 2)) {
              af_printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@last peak pos %d\n",DAT_0481969c);
              iVar10 = DAT_0481969c;
            }
          }
        }
        DAT_04819678 = iVar10;
        DAT_048194d0 = DAT_04819650;
        iVar14 = DAT_04818e88;
        iVar10 = DAT_04817e3c;
        puVar22 = &DAT_04819608;
        do {
          puVar27 = puVar22 + -1;
          puVar22[1] = *puVar22;
          puVar22 = puVar27;
        } while (puVar27 != &DAT_048194cc);
        iVar11 = (int)local_78;
        uVar30 = local_78 & 0xffffffff;
        DAT_04817e38 = (uint)((int)local_78 == 1);
        iVar34 = (int)((float)(int)DAT_048194d0 * fVar39);
        local_78 = CONCAT44(iVar34,(int)local_78);
        DAT_04819658 = DAT_048194d0;
        af_printf((double)DAT_04818fd0,(double)DAT_04819250,
                  "[%s]\tderv %.4f der_k %.4f\t pos %4d fv %5d\tnext step %d continue%d\t\n",
                  (&PTR_s_STM_IDLE_01018070)[(int)DAT_04817e34],iVar14,iVar10,iVar34,uVar30);
        af_printf((double)local_60._4_4_,(double)(float)local_60,
                  "aver %d y %lld down %.4f up %.4f max %d min %d\n",local_58 & 0xffffffff,local_40,
                  local_50 & 0xffffffff,local_50._4_4_);
        *param_2 = iVar34;
        *param_3 = (undefined4)local_70;
        iVar10 = iVar11;
        if (DAT_04817e30 - 6 < 2) goto LAB_00d3ec70;
LAB_00d3e3cc:
        DAT_04817d90 = DAT_04817de0;
        if ((DAT_04817de8 != 0) && (iVar34 <= (int)((float)DAT_04817dec * DAT_0481a2f0))) {
          DAT_04817d90 = DAT_04817df0;
        }
        if (iVar11 == 0) {
          return uVar12;
        }
      }
      iVar34 = 0;
      iVar11 = 0;
      *param_2 = 0;
      uVar12 = 0;
      *param_3 = (undefined4)local_70;
      iVar10 = 0;
      if (1 < DAT_04817e30 - 6) goto LAB_00d3e3cc;
LAB_00d3ec70:
      DAT_04817d90 = 1;
      if (iVar10 == 0) {
        DAT_04817d90 = 1;
        return uVar12;
      }
    } while( true );
  }
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  uStack_8 = 0;
  (*(code *)DAT_04817d78[0xd])(&local_7c,&local_60);
  n3a_af_parase_fv_get_trend_info(&local_30);
  iVar11 = (*(code *)DAT_04817d78[5])();
  iVar14 = (int)local_20;
  DAT_0481a8b8 = (*(code *)*DAT_04817d78)();
  iVar10 = DAT_0481a930;
  if (0x77 < DAT_0481a930) {
    iVar10 = 0x77;
  }
  if (0 < iVar10) {
    lVar32 = (long)(int)(iVar10 - 1U);
    puVar19 = &DAT_04817d70 + lVar32 + 0x96a;
    puVar28 = &DAT_04817d74 + lVar32 + 0x96a;
    puVar29 = &DAT_0481a8b8 + lVar32;
    do {
      puVar26 = puVar19 + -1;
      *puVar28 = *puVar19;
      puVar28[0x78] = puVar19[0x78];
      puVar28[0xf0] = puVar19[0xf0];
      puVar29[iVar10 - lVar32] = *puVar29;
      puVar19 = puVar26;
      puVar28 = puVar28 + -1;
      puVar29 = puVar29 + -1;
    } while (&DAT_04817d70 + ((lVar32 + 0x969) - (ulong)(iVar10 - 1U)) != puVar26);
  }
  DAT_0481a930 = DAT_0481a930 + 1;
  DAT_0481a6d8 = iVar14;
  DAT_0481a318 = iVar11;
  DAT_0481a4f8 = param_1;
  uVar12 = (*(code *)*DAT_04817d78)();
  uVar13 = (*(code *)DAT_04817d78[5])();
  af_printf("motor running %d pos %d fv %d, point_fv %d\n",uVar12,uVar13,param_1,
            local_20 & 0xffffffff);
  iVar10 = (int)((float)(int)local_7c * DAT_04817e24 + 0.5);
  if ((int)DAT_0481a980 - 1U < 2) {
    puVar23 = &DAT_0481a960;
    if ((int)DAT_0481a980 == 1) {
      puVar23 = &DAT_0481a940;
    }
    iVar14 = *(int *)(puVar23 + 2);
    if (iVar14 < param_1) {
      iVar11 = 0;
      *(int *)(puVar23 + 2) = param_1;
      *(undefined4 *)((long)puVar23 + 0x14) = 0;
      *(int *)((long)puVar23 + 0x1c) = *(int *)((long)puVar23 + 0x1c) + 1;
      iVar14 = param_1;
    }
    else {
      iVar11 = iVar14 - param_1;
      *(int *)(puVar23 + 3) = *(int *)(puVar23 + 3) + 1;
    }
    if (((DAT_04817e1c < iVar11) && (DAT_04817e18 <= *(int *)(puVar23 + 3))) &&
       (DAT_04817e14 <= *(int *)((long)puVar23 + 0x1c))) {
      if ((DAT_0481a9a0._4_4_ == 0) && (iVar14 = (*(code *)*DAT_04817d78)(), iVar14 != 0)) {
        (*(code *)DAT_04817d78[0x16])();
        DAT_0481a9a0._4_4_ = 1;
      }
      DAT_0481a980._0_4_ = 3;
      af_printf("far search gentle peak done !!!\n");
    }
    else if ((DAT_04817e0c < iVar11) &&
            ((float)DAT_04817e10 <= (float)iVar14 / (float)(param_1 + 1))) {
      if ((DAT_0481a9a0._4_4_ == 0) && (iVar14 = (*(code *)*DAT_04817d78)(), iVar14 != 0)) {
        if ((int)DAT_0481a980 != 2) {
          af_printf("need switch dir go to near!!!");
          (*(code *)DAT_04817d78[0x16])();
          DAT_0481a988._0_4_ = 1;
          DAT_0481a9a0._4_4_ = 1;
          return 0;
        }
        (*(code *)DAT_04817d78[0x16])();
        DAT_0481a9a0._4_4_ = 1;
        af_printf("focus stop !!!!\n");
      }
      if ((int)DAT_0481a980 == 2) {
        if ((DAT_04817e0c < *(int *)(puVar23 + 2) - *(int *)((long)puVar23 + 4)) &&
           ((float)DAT_04817e10 <=
            (float)*(int *)(puVar23 + 2) / (float)(*(int *)((long)puVar23 + 4) + 1))) {
          DAT_0481a980._0_4_ = 3;
          af_printf("far search sharp peak done !!!\n");
        }
      }
    }
  }
  iVar14 = (*(code *)*DAT_04817d78)();
  if (iVar14 != 0) {
    af_printf("motor running !!!\n");
    DAT_0481a998._4_4_ = DAT_0481a998._4_4_ + 1;
    return 0;
  }
  DAT_0481a9a0._0_4_ = (int)DAT_0481a9a0 + 1;
  if ((int)DAT_0481a980 == 0) {
    DAT_0481a940._0_4_ = 0;
    DAT_0481a950._4_4_ = 0;
    DAT_0481a958._0_4_ = 0;
    DAT_0481a958._4_4_ = 0;
    DAT_0481a940._4_4_ = param_1;
    DAT_0481a950._0_4_ = param_1;
    af_printf("goto far point!!!!\n");
    DAT_0481a9a0._4_4_ = 0;
    (*(code *)DAT_04817d78[0x15])(1,iVar10);
    DAT_0481a980._0_4_ = (int)DAT_0481a980 + 1;
    DAT_0481a998._4_4_ = 0;
    DAT_0481a9a0._0_4_ = 0;
    return 0;
  }
  if ((int)DAT_0481a980 == 1) {
    if (DAT_0481a998._4_4_ == 0 && (int)DAT_0481a9a0 < 5) {
      return 0;
    }
    DAT_0481a988._0_4_ = (int)DAT_0481a980;
    DAT_0481a948._0_4_ = 0;
    DAT_0481a960._0_4_ = 0;
    DAT_0481a978._0_4_ = 0;
    DAT_0481a978._4_4_ = 0;
    DAT_0481a948._4_4_ = param_1;
    DAT_0481a960._4_4_ = param_1;
    af_printf("goto near point!!!!\n");
    (*(code *)DAT_04817d78[0x15])(0,iVar10);
    DAT_0481a980._0_4_ = (int)DAT_0481a980 + 1;
    DAT_0481a998._4_4_ = 0;
    DAT_0481a9a0._0_4_ = 0;
    DAT_0481a9a0._4_4_ = 0;
    return 0;
  }
  if ((int)DAT_0481a980 < 2) {
    return 0;
  }
  if (DAT_0481a998._4_4_ == 0 && (int)DAT_0481a9a0 < 5) {
    return 0;
  }
  if (DAT_0481a980._4_4_ == 0) {
    DAT_0481a968._0_4_ = 0;
    DAT_0481a980._4_4_ = 1;
    DAT_0481a968._4_4_ = param_1;
  }
  uVar30 = (ulong)DAT_0481a4f8;
  if (DAT_0481a930 < 2) {
    iVar10 = 0;
    lVar32 = 0;
    iVar14 = DAT_0481a6d8;
    iVar11 = DAT_0481a318;
LAB_00d3fac4:
    iVar33 = (&DAT_0481a318)[iVar10 + 1] - iVar11;
    iVar34 = (&DAT_0481a318)[iVar10 + 1];
    if ((&DAT_0481a8b8)[lVar32] != '\x01') {
      iVar34 = iVar11;
    }
  }
  else {
    puVar22 = &DAT_0481a31c;
    iVar10 = 0;
    iVar14 = 1;
    lVar32 = 0;
    local_98 = (uint *)((ulong)local_98 & 0xffffffff00000000);
    do {
      af_printf("pos %d fv %d\n",*puVar22,puVar22[0x78]);
      uVar30 = uVar30 + (long)(int)puVar22[0x78];
      if ((&DAT_0481a4f8)[lVar32] <= (int)puVar22[0x78]) {
        lVar32 = (long)iVar14;
        local_98 = (uint *)CONCAT44(local_98._4_4_,iVar14);
      }
      piVar21 = puVar22 + 0xf0;
      puVar22 = puVar22 + 1;
      if ((&DAT_0481a6d8)[iVar10] <= *piVar21) {
        iVar10 = iVar14;
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 < DAT_0481a930);
    uVar2 = 0;
    if ((long)iVar14 != 0) {
      uVar2 = uVar30 / (ulong)(long)iVar14;
    }
    iVar14 = (&DAT_0481a4f8)[lVar32];
    if (0x23 < (long)iVar14 - uVar2) {
      iVar10 = (&DAT_0481a318)[lVar32];
      if ((int)local_98 < 0x77) {
        iVar33 = (&DAT_0481a318)[(int)local_98 + 1] - iVar10;
        iVar34 = (&DAT_0481a318)[(int)local_98 + 1];
        if ((&DAT_0481a8b8)[lVar32] != '\x01') {
          iVar34 = iVar10;
        }
      }
      else {
        iVar33 = (&DAT_0481a318)[(int)local_98 + -1] - iVar10;
        iVar34 = iVar10;
      }
      goto LAB_00d3e6d4;
    }
    lVar32 = (long)iVar10;
    iVar34 = (&DAT_0481a318)[lVar32];
    iVar14 = (&DAT_0481a6d8)[lVar32];
    iVar11 = iVar34;
    if (iVar10 < 0x77) goto LAB_00d3fac4;
    iVar33 = (&DAT_0481a318)[iVar10 + -1] - iVar34;
  }
  af_printf("low freq image, using point fv peak!!!\n");
LAB_00d3e6d4:
  DAT_0481a988._4_4_ = 0xffffffff;
  if (0 < iVar33) {
    DAT_0481a988._4_4_ = 1;
  }
  DAT_0481a990._0_4_ = 1;
  af_printf("gsearch peak done pos %d fv %d!!!\n",iVar34,iVar14);
  uVar12 = (*(code *)*DAT_04817d78)();
  uVar13 = (*(code *)DAT_04817d78[5])();
  af_printf("lens motor running %d pos %d\n",uVar12,uVar13);
  (*(code *)DAT_04817d78[6])(iVar34,0xffffffff);
  return 0;
}



/* FUNCTION n3a_af_parase_fv_get_trend_info @ 00d40d90 body=[[00d40d90, 00d40ed3] [00d40ed8, 00d40f53]]
REF Entry Point EXTERNAL caller=NONE
REF 00f1869c INDIRECTION caller=NONE
REF 00fe09a8 DATA caller=NONE
REF 00d3bb58 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3e454 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3f058 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
*/

void n3a_af_parase_fv_get_trend_info(float *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  ulong uVar6;
  float *pfVar7;
  short *psVar8;
  long lVar9;
  ulong uVar10;
  float fVar11;
  int iVar12;
  ulong uVar13;
  float fVar14;
  int iVar15;
  float fVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  
  iVar4 = DAT_04820610;
  iVar3 = DAT_0482060c;
  param_1[6] = 0.0;
  param_1[8] = 0.0;
  param_1[9] = 0.0;
  if (iVar4 < 1) {
    dVar22 = 0.0;
    dVar20 = 0.0;
    uVar10 = 0;
    uVar6 = 0;
    fVar11 = 0.0;
    fVar16 = 0.0;
    uVar13 = 0;
    dVar21 = dVar20;
  }
  else {
    iVar19 = 0;
    uVar10 = 0;
    iVar18 = 0;
    iVar12 = 0;
    iVar17 = 0;
    iVar15 = 0;
    fVar11 = 0.0;
    fVar16 = 0.0;
    uVar13 = 0;
    do {
      if (0 < iVar3) {
        lVar9 = (long)iVar19;
        pcVar5 = &DAT_0481b9b8 + lVar9;
        pfVar7 = (float *)(&DAT_0481a9b0 + lVar9 + 0x1919);
        psVar8 = (short *)((long)&DAT_0481a9b0 + (lVar9 + 0x2a14) * 2);
        do {
          if (*pcVar5 != '\0') {
            iVar12 = iVar12 + 1;
            fVar1 = *pfVar7;
            uVar13 = uVar13 + (long)(int)fVar1;
            if (*psVar8 == 0) {
              fVar14 = pfVar7[0x400];
              if (psVar8[0x202] != 0 || (int)fVar1 <= (int)fVar16) goto LAB_00d40e34;
              fVar2 = pfVar7[0x802];
              if (fVar14 == 0.0) {
                fVar16 = fVar1;
              }
              if ((int)fVar1 < (int)fVar11) {
                fVar11 = fVar1;
              }
              if (0 < (int)fVar1 - (int)fVar2) goto LAB_00d40e4c;
LAB_00d40ecc:
              if (fVar1 != fVar2) {
                iVar17 = iVar17 + 1;
              }
            }
            else {
              fVar14 = pfVar7[0x400];
LAB_00d40e34:
              fVar2 = pfVar7[0x802];
              if ((int)fVar1 < (int)fVar11) {
                fVar11 = fVar1;
              }
              if ((int)fVar1 - (int)fVar2 < 1) goto LAB_00d40ecc;
LAB_00d40e4c:
              iVar15 = iVar15 + 1;
            }
            uVar10 = uVar10 + (long)(int)pfVar7[0x200];
            *(ulong *)(param_1 + 8) = uVar10;
            param_1[6] = (float)((int)param_1[6] + (int)fVar14);
          }
          pcVar5 = pcVar5 + 1;
          pfVar7 = pfVar7 + 1;
          psVar8 = psVar8 + 1;
        } while (&DAT_0481b9b9 + (ulong)(iVar3 - 1) + lVar9 != pcVar5);
      }
      iVar18 = iVar18 + 1;
      iVar19 = iVar19 + iVar3;
    } while (iVar4 != iVar18);
    uVar6 = (ulong)iVar12;
    dVar20 = (double)iVar12;
    dVar22 = (double)iVar17;
    dVar21 = (double)iVar15;
  }
  param_1[4] = fVar16;
  param_1[5] = fVar11;
  fVar16 = 0.0;
  if (uVar6 != 0) {
    fVar16 = (float)(uVar13 / uVar6);
  }
  fVar11 = 0.0;
  if (uVar6 != 0) {
    fVar11 = (float)(uVar10 / uVar6);
  }
  param_1[2] = fVar16;
  param_1[10] = fVar11;
  *param_1 = (float)(dVar21 / dVar20);
  param_1[1] = (float)(dVar22 / dVar20);
  return;
}



/* FUNCTION n3a_af_parase_fv_get_changed_percent_info @ 00d40f58 body=[[00d40f58, 00d41027]]
REF Entry Point EXTERNAL caller=NONE
REF 00f186a4 INDIRECTION caller=NONE
REF 00fe09dc DATA caller=NONE
*/

float n3a_af_parase_fv_get_changed_percent_info(int param_1,long param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  long lVar5;
  long lVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  double dVar12;
  double dVar13;
  
  dVar13 = 0.0;
  dVar12 = 0.0;
  if (0 < DAT_04820610) {
    iVar11 = 0;
    iVar10 = 0;
    iVar8 = 0;
    iVar9 = 0;
    do {
      if (0 < DAT_0482060c) {
        lVar5 = (long)iVar11;
        pcVar4 = &DAT_0481b9b8 + lVar5;
        lVar6 = param_2 + lVar5 * 4;
        piVar7 = &DAT_04820e14 + lVar5;
        do {
          cVar2 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          if (cVar2 != '\0') {
            iVar9 = iVar9 + 1;
            iVar3 = *(int *)(lVar6 + 0x808) - *piVar7;
            iVar1 = -iVar3;
            if (-1 < iVar3) {
              iVar1 = iVar3;
            }
            if (param_1 <= iVar1) {
              iVar8 = iVar8 + 1;
            }
          }
          lVar6 = lVar6 + 4;
          piVar7 = piVar7 + 1;
        } while (&DAT_0481b9b9 + (ulong)(DAT_0482060c - 1) + lVar5 != pcVar4);
      }
      iVar10 = iVar10 + 1;
      iVar11 = iVar11 + DAT_0482060c;
    } while (DAT_04820610 != iVar10);
    dVar12 = (double)iVar8;
    dVar13 = (double)iVar9;
  }
  return (float)(dVar12 / dVar13);
}



/* FUNCTION n3a_af_parse_luma_highlight_and_contrast @ 00d41028 body=[[00d41028, 00d4110f]]
REF Entry Point EXTERNAL caller=NONE
REF 00f186ac INDIRECTION caller=NONE
REF 00fe09f0 DATA caller=NONE
REF 00d411c0 UNCONDITIONAL_CALL caller=n3a_af_parse_fv@00d41110
*/

undefined8 n3a_af_parse_luma_highlight_and_contrast(void)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  
  lVar4 = DAT_0482d588;
  iVar3 = DAT_04820610;
  iVar2 = DAT_0482060c;
  memset(&DAT_0481fdd8,0,0x808);
  if (0 < iVar3) {
    iVar7 = 0;
    iVar6 = 0;
    do {
      if (0 < iVar2) {
        lVar5 = 0;
        do {
          lVar1 = iVar7 + lVar5;
          lVar5 = lVar5 + 1;
          if ((((&DAT_0481b9b8)[lVar1] != '\0') && (*(int *)(lVar4 + 0x1430) < iVar3 * iVar2)) &&
             (*(int *)(lVar4 + 0x142c) <= (int)(&DAT_04821e14)[lVar1])) {
            (&DAT_0481fdd8)[lVar1] = 1;
          }
        } while ((int)lVar5 < iVar2);
      }
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + iVar2;
    } while (iVar3 != iVar6);
  }
  return 0;
}



/* FUNCTION n3a_af_parse_fv @ 00d41110 body=[[00d41110, 00d414fb] [00d41500, 00d4155b]]
REF Entry Point EXTERNAL caller=NONE
REF 00f186b4 INDIRECTION caller=NONE
REF 00fe0a20 DATA caller=NONE
REF 00d3a0a0 UNCONDITIONAL_CALL caller=n3a_af_update@00d3a010
*/

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
n3a_af_parse_fv(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int *piVar8;
  short *psVar9;
  long lVar10;
  byte *pbVar11;
  int *piVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  undefined4 *__src;
  int iVar20;
  undefined4 *__s;
  float fVar21;
  
  iVar2 = *param_1;
  iVar3 = param_1[1];
  iVar5 = n3a_af_get_af_mode();
  fVar21 = *(float *)(DAT_0482d588 + (long)iVar5 * 0x220 + 0x6ec);
  __s = (undefined4 *)&DAT_0482a634;
  do {
    __src = __s + -0x802;
    memset(__s,0,0x2008);
    memcpy(__s,__src,0x2008);
    __s = __src;
  } while (__src != &DAT_0482060c);
  memcpy(&DAT_0482060c,param_1,0x2008);
  n3a_af_parse_luma_highlight_and_contrast();
  if (iVar3 < 1) {
    iVar20 = (int)(fVar21 * 0.0);
    iVar6 = n3a_af_caf_is_doing_focus();
    iVar5 = iVar20;
    if (iVar6 == 0) {
LAB_00d41538:
      DAT_0482d590 = 1;
    }
  }
  else {
    iVar17 = 0;
    iVar6 = 0;
    iVar5 = 0;
    iVar18 = 0;
    iVar16 = 0;
    iVar20 = 0;
    uVar15 = 0;
    uVar13 = 0;
    do {
      if (0 < iVar2) {
        lVar10 = (long)iVar17;
        pcVar7 = &DAT_0481b9b8 + lVar10;
        piVar8 = param_1 + lVar10;
        psVar9 = (short *)((long)&DAT_0481a9b0 + (lVar10 + 0x2a14) * 2);
        do {
          if (*pcVar7 != '\0') {
            if ((*psVar9 == 0) && (psVar9[0x202] == 0)) {
              if (piVar8[2] == 0) {
                iVar16 = iVar16 + 1;
              }
              uVar13 = uVar13 + (long)piVar8[2];
              uVar15 = uVar15 + (long)piVar8[0x202];
              if (piVar8[0x202] == 0) {
                iVar18 = iVar18 + 1;
              }
            }
            else {
              iVar20 = iVar20 + 1;
            }
            iVar5 = iVar5 + 1;
          }
          pcVar7 = pcVar7 + 1;
          piVar8 = piVar8 + 1;
          psVar9 = psVar9 + 1;
        } while (pcVar7 != &DAT_0481b9b9 + (ulong)(iVar2 - 1) + lVar10);
      }
      iVar6 = iVar6 + 1;
      iVar17 = iVar17 + iVar2;
    } while (iVar3 != iVar6);
    iVar16 = (iVar5 - iVar20) - iVar16;
    iVar18 = (iVar5 - iVar20) - iVar18;
    uVar14 = uVar13;
    if (iVar16 != 0) {
      uVar14 = 0;
      if ((long)iVar16 != 0) {
        uVar14 = uVar13 / (ulong)(long)iVar16;
      }
    }
    if (iVar18 == 0) {
      iVar18 = 1;
    }
    uVar13 = 0;
    if ((long)iVar18 != 0) {
      uVar13 = uVar15 / (ulong)(long)iVar18;
    }
    iVar20 = (int)(fVar21 * (float)uVar14);
    iVar5 = (int)((float)uVar13 * fVar21);
    iVar6 = n3a_af_caf_is_doing_focus();
    if (iVar6 == 0) {
      if (uVar13 < 0x46) goto LAB_00d41538;
      DAT_0482d590 = 0;
    }
  }
  iVar6 = n3a_af_is_caf_on();
  if (iVar6 == 0) {
    DAT_0482d590 = 0;
  }
  iVar16 = DAT_0482d590;
  DAT_0481bbb8 = 0;
  DAT_0481bbbc = 0;
  DAT_0481bbc0 = 0;
  iVar17 = *param_5 - DAT_0482c640;
  iVar6 = -iVar17;
  if (-1 < iVar17) {
    iVar6 = iVar17;
  }
  if (iVar6 <= DAT_0482d580) {
    iVar17 = param_5[1] - DAT_0482c644;
    iVar6 = -iVar17;
    if (-1 < iVar17) {
      iVar6 = iVar17;
    }
    if ((iVar6 <= DAT_0482d580) && (param_5[2] - (int)DAT_0482c648 <= DAT_0482d580))
    goto LAB_00d41354;
  }
  DAT_0481bbc0 = 1;
LAB_00d41354:
  DAT_0482c660 = *(undefined8 *)(param_5 + 8);
  _DAT_0482c640 = *(undefined8 *)param_5;
  DAT_0482c648 = *(undefined8 *)(param_5 + 2);
  DAT_0482c650 = *(undefined8 *)(param_5 + 4);
  DAT_0482c658 = *(undefined8 *)(param_5 + 6);
  DAT_048205fc = param_3;
  DAT_04820604 = param_4;
  if (iVar3 < 1) {
    DAT_0481a9b0 = 0;
    uVar13 = 0;
    uVar15 = 1;
  }
  else {
    iVar19 = 0;
    iVar6 = 0;
    iVar18 = 0;
    iVar17 = 0;
    uVar13 = 0;
    uVar15 = 0;
    do {
      if (0 < iVar2) {
        lVar10 = (long)iVar19;
        pbVar11 = &DAT_0481b9b8 + lVar10;
        psVar9 = (short *)((long)&DAT_0481a9b0 + (lVar10 + 0x2a14) * 2);
        piVar8 = param_1 + lVar10 + 2;
        piVar12 = &DAT_0481a9b0 + lVar10 + 2;
        do {
          while ((*psVar9 != 0 || (psVar9[0x202] != 0))) {
LAB_00d41430:
            piVar1 = piVar8 + 0x400;
            piVar8 = piVar8 + 1;
            psVar9 = psVar9 + 1;
            *piVar12 = *piVar1;
            pbVar11 = pbVar11 + 1;
            piVar12 = piVar12 + 1;
            if (piVar8 == param_1 + (ulong)(iVar2 - 1) + 3 + lVar10) goto LAB_00d414a0;
          }
          if (iVar16 != 0) {
            if (iVar20 <= *piVar8) {
              iVar17 = iVar17 + (uint)*pbVar11;
              uVar15 = uVar15 + (long)(int)(*piVar8 * (uint)*pbVar11);
            }
            if (iVar5 <= piVar8[0x200]) {
              iVar18 = iVar18 + (uint)*pbVar11;
              uVar13 = uVar13 + (long)(int)(piVar8[0x200] * (uint)*pbVar11);
            }
            goto LAB_00d41430;
          }
          bVar4 = *pbVar11;
          piVar1 = piVar8 + 1;
          psVar9 = psVar9 + 1;
          iVar17 = iVar17 + (uint)bVar4;
          iVar18 = iVar18 + (uint)bVar4;
          pbVar11 = pbVar11 + 1;
          uVar15 = uVar15 + (long)(int)((uint)bVar4 * *piVar8);
          uVar13 = uVar13 + (long)(int)((uint)bVar4 * piVar8[0x200]);
          *piVar12 = piVar8[0x400];
          piVar8 = piVar1;
          piVar12 = piVar12 + 1;
        } while (piVar1 != param_1 + (ulong)(iVar2 - 1) + 3 + lVar10);
      }
LAB_00d414a0:
      iVar6 = iVar6 + 1;
      iVar19 = iVar19 + iVar2;
    } while (iVar3 != iVar6);
    uVar14 = uVar15;
    if (iVar17 != 0) {
      uVar14 = 0;
      if ((long)iVar17 != 0) {
        uVar14 = uVar15 / (ulong)(long)iVar17;
      }
    }
    DAT_0481a9b0 = (undefined4)uVar14;
    uVar15 = (ulong)iVar18;
    if (iVar18 == 0) {
      uVar15 = 1;
    }
  }
  DAT_0481a9b4 = 0;
  if (uVar15 != 0) {
    DAT_0481a9b4 = (undefined4)(uVar13 / uVar15);
  }
  return 0;
}



/* FUNCTION n3a_af_lum_parse @ 00d41608 body=[[00d41608, 00d41743]]
REF Entry Point EXTERNAL caller=NONE
REF 00f186ec INDIRECTION caller=NONE
REF 00fe0af8 DATA caller=NONE
REF 00d3c3d0 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
*/

undefined8 n3a_af_lum_parse(undefined8 param_1,undefined8 param_2,int param_3,uint *param_4)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  if (5 < param_3) {
    param_3 = 5;
  }
  DAT_0481bbb8 = 0;
  DAT_0481bbbc = 0;
  uVar10 = (uint)((double)DAT_0482060c * 0.5 * (double)DAT_04820610);
  if (param_4[1] < uVar10) {
    uVar10 = param_4[1];
  }
  if (0 < DAT_04820610) {
    iVar9 = 0;
    iVar8 = 0;
    uVar6 = 0;
    uVar7 = 0;
    do {
      if (0 < DAT_0482060c) {
        pcVar4 = &DAT_0481b9b8 + iVar9;
        piVar5 = &DAT_0481a9b0 + (long)iVar9 + 0x1b19;
        do {
          cVar2 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          if (cVar2 != '\0') {
            uVar3 = *piVar5 - piVar5[0x802];
            uVar1 = -uVar3;
            if (-1 < (int)uVar3) {
              uVar1 = uVar3;
            }
            if (*param_4 < uVar1) {
              uVar7 = uVar7 + 1;
            }
            uVar3 = piVar5[(long)param_3 * 0x802] - *piVar5;
            uVar1 = -uVar3;
            if (-1 < (int)uVar3) {
              uVar1 = uVar3;
            }
            if (*param_4 < uVar1) {
              uVar6 = uVar6 + 1;
            }
          }
          piVar5 = piVar5 + 1;
        } while (pcVar4 != &DAT_0481b9b9 + (ulong)(DAT_0482060c - 1) + (long)iVar9);
      }
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + DAT_0482060c;
    } while (DAT_04820610 != iVar8);
    if (uVar10 < uVar7 || uVar10 < uVar6) {
      af_printf("y_continuously_changing !!!!!!!!!!!!!!!!!!\n");
      DAT_0481bbb8 = 1;
    }
  }
  return 0;
}



/* FUNCTION n3a_af_fv_set_down_hill_focus_point @ 00d41778 body=[[00d41778, 00d41b3f]]
REF Entry Point EXTERNAL caller=NONE
REF 00f18704 INDIRECTION caller=NONE
REF 00fe0b48 DATA caller=NONE
REF 00d3a700 UNCONDITIONAL_CALL caller=FUN_00d3a650@00d3a650
REF 00d3e098 UNCONDITIONAL_CALL caller=FUN_00d3e000@00d3e000
*/

undefined8 n3a_af_fv_set_down_hill_focus_point(int param_1,int param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  int iVar12;
  long lVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  ulong uVar19;
  ulong uVar20;
  int iVar21;
  ulong uVar22;
  ulong uVar23;
  ulong uVar24;
  int iVar25;
  ulong uVar26;
  int local_800 [512];
  
  if (5 < param_1) {
    param_1 = 5;
  }
  if (5 < param_2) {
    param_2 = 5;
  }
  lVar13 = (long)param_1;
  memset(local_800,0,0x800);
  lVar8 = DAT_0482d588;
  memcpy(&DAT_0481bbc4,&DAT_0482060c + lVar13 * 0x802,0x2008);
  memcpy(&DAT_0481dbcc,&DAT_0482060c + (long)param_2 * 0x802,0x2008);
  iVar7 = DAT_04820610;
  iVar6 = DAT_0482060c;
  memset(&DAT_0481fbd4,0,0x200);
  iVar18 = 0;
  if (0 < iVar7) {
    iVar16 = 0;
    iVar17 = 0;
    uVar23 = 0;
    iVar18 = 0;
    iVar21 = 0;
    iVar25 = 0;
    uVar19 = 0;
    uVar26 = 0;
    do {
      if (0 < iVar6) {
        lVar9 = (long)iVar16;
        pbVar10 = &DAT_0481b9b8 + lVar9;
        piVar14 = &DAT_0481a9b0 + (long)param_1 * 0x802 + 0x1919 + lVar9;
        lVar9 = (lVar9 + (long)param_1 * 0x802) * 4;
        iVar12 = iVar16;
        do {
          bVar4 = *pbVar10;
          pbVar10 = pbVar10 + 1;
          if (bVar4 != 0) {
            iVar2 = *(int *)(lVar8 + 0x142c);
            if ((piVar14[0x400] < iVar2) &&
               (*(int *)((long)&DAT_04821e14 + lVar9 + (long)param_2 * 0x2008 + lVar13 * -0x2008) <
                iVar2)) {
              iVar3 = piVar14[lVar13 * -0x802 + (long)param_2 * 0x802];
              iVar21 = iVar21 + (uint)bVar4;
              iVar2 = *piVar14;
              iVar5 = iVar2 - iVar3;
              *(int *)((long)local_800 + lVar9 + lVar13 * -0x2008) = iVar5;
              uVar15 = (uint)bVar4;
              uVar19 = uVar19 + (long)(int)(iVar2 * uVar15);
              uVar23 = uVar23 + (long)(int)(uVar15 * iVar3);
              if (0 < iVar5) {
                uVar26 = uVar26 + (long)(int)(uVar15 * iVar5);
                iVar25 = iVar25 + uVar15;
              }
              if ((int)(&DAT_0481a9c4)[lVar13 * 0x802 + (long)iVar18 + 0x1914] < iVar2) {
                iVar18 = iVar12;
              }
            }
          }
          iVar12 = iVar12 + 1;
          piVar14 = piVar14 + 1;
          lVar9 = lVar9 + 4;
        } while (iVar12 != iVar16 + iVar6);
      }
      iVar16 = iVar16 + iVar6;
      iVar17 = iVar17 + 1;
    } while (iVar7 != iVar17);
    uVar20 = uVar19;
    uVar24 = uVar23;
    if (iVar21 != 0) {
      uVar22 = (ulong)iVar21;
      uVar20 = 0;
      if (uVar22 != 0) {
        uVar20 = uVar19 / uVar22;
      }
      uVar24 = 0;
      if (uVar22 != 0) {
        uVar24 = uVar23 / uVar22;
      }
    }
    if (iVar25 == 0) {
      iVar25 = 1;
    }
    iVar16 = 0;
    iVar21 = 0;
    iVar17 = 0;
    uVar19 = 0;
    if ((long)iVar25 != 0) {
      uVar19 = uVar26 / (ulong)(long)iVar25;
    }
    DAT_0481fdd4 = 0;
    do {
      if (0 < iVar6) {
        lVar9 = (long)iVar16;
        lVar1 = (ulong)(iVar6 - 1) + lVar9;
        puVar11 = &DAT_0481fbd4 + lVar9;
        piVar14 = &DAT_0481a9b0 + (long)param_1 * 0x802 + 0x1919 + lVar9;
        do {
          if (((puVar11[-0x421c] != '\0') &&
              (iVar25 = *(int *)(lVar8 + 0x142c), piVar14[0x400] < iVar25)) &&
             ((int)(&DAT_04821e14)[lVar9 + (long)param_2 * 0x802] < iVar25)) {
            if ((((ulong)(long)*piVar14 < uVar20) ||
                (*piVar14 < piVar14[lVar13 * -0x802 + (long)param_2 * 0x802])) ||
               (((ulong)(long)piVar14[lVar13 * -0x802 + (long)param_2 * 0x802] < uVar24 ||
                ((ulong)(long)local_800[lVar9] <= uVar19)))) {
              *puVar11 = 0;
            }
            else {
              *puVar11 = 1;
              iVar17 = iVar17 + 1;
              DAT_0481fdd4 = iVar17;
            }
          }
          puVar11 = puVar11 + 1;
          piVar14 = piVar14 + 1;
          lVar9 = lVar9 + 1;
        } while (puVar11 != &DAT_0481fbd5 + lVar1);
      }
      iVar21 = iVar21 + 1;
      iVar16 = iVar16 + iVar6;
    } while (iVar7 != iVar21);
    if (iVar17 != 0) {
      return 0;
    }
  }
  DAT_0481fdd4 = 1;
  (&DAT_0481fbd4)[iVar18] = 1;
  return 0;
}



/* FUNCTION n3a_af_fv_set_final_focus_point @ 00d41b40 body=[[00d41b40, 00d41ca3]]
REF Entry Point EXTERNAL caller=NONE
REF 00f1870c INDIRECTION caller=NONE
REF 00fe0ba4 DATA caller=NONE
REF 00d3b5fc UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3f1c0 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
*/

undefined8 n3a_af_fv_set_final_focus_point(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar3 = DAT_04820610;
  iVar2 = DAT_0482060c;
  if (5 < param_1) {
    param_1 = 5;
  }
  iVar10 = DAT_0481fdd4;
  if (DAT_04820610 < 1) {
    iVar8 = 0;
  }
  else {
    iVar9 = 0;
    iVar11 = 0;
    iVar8 = 0;
    do {
      if (0 < iVar2) {
        pcVar4 = &DAT_0481fbd4 + iVar9;
        piVar7 = &DAT_0481a9b0 + (long)param_1 * 0x802 + 0x1919 + (long)iVar9;
        iVar5 = iVar9;
        do {
          uVar6 = (uint)(byte)pcVar4[-0x421c];
          if (pcVar4[-0x421c] != 0) {
            iVar1 = *piVar7;
            if ((*pcVar4 != '\0') && (iVar1 <= piVar7[(long)param_1 * -0x802 + -0xa90])) {
              *pcVar4 = '\0';
              iVar10 = iVar10 + -1;
              uVar6 = (uint)(byte)pcVar4[-0x421c];
              DAT_0481fdd4 = iVar10;
            }
            if ((int)((uint)(byte)(&DAT_0481b9b8)[iVar8] *
                     (&DAT_0481a9c4)[(long)param_1 * 0x802 + (long)iVar8 + 0x1914]) <
                (int)(uVar6 * iVar1)) {
              iVar8 = iVar5;
            }
          }
          iVar5 = iVar5 + 1;
          piVar7 = piVar7 + 1;
          pcVar4 = pcVar4 + 1;
        } while (iVar5 != iVar9 + iVar2);
      }
      iVar9 = iVar9 + iVar2;
      iVar11 = iVar11 + 1;
    } while (iVar3 != iVar11);
  }
  if (iVar10 == 0) {
    DAT_0481fdd4 = 1;
    (&DAT_0481fbd4)[iVar8] = 1;
  }
  return 0;
}



/* FUNCTION n3a_af_set_roi @ 00d41d28 body=[[00d41d28, 00d41e2b] [00d41e30, 00d41ecf]]
REF Entry Point EXTERNAL caller=NONE
REF 00f18734 INDIRECTION caller=NONE
REF 00fe0c34 DATA caller=NONE
REF 00885e3c UNCONDITIONAL_CALL caller=FUN_00885cb0@00885cb0
*/

undefined8 n3a_af_set_roi(undefined8 *param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  float fVar14;
  
  iVar3 = *(int *)((long)param_1 + 0x14);
  iVar4 = *(int *)(param_1 + 3);
  iVar5 = n3a_af_get_af_mode();
  lVar2 = DAT_0482d588 + (long)iVar5 * 0x220;
  fVar14 = *(float *)(DAT_0482d588 + 0x13f0);
  iVar11 = (int)((float)iVar3 * *(float *)(DAT_0482d588 + 0x13f4) + 0.5);
  iVar10 = (int)((float)*(int *)(lVar2 + 0x4e4) * 0.5 - (float)(iVar4 / 2));
  if ((0 < iVar4) && (iVar10 < *(int *)(lVar2 + 0x4e4))) {
    iVar9 = (int)((float)*(int *)(lVar2 + 0x4e0) * 0.5 - (float)(iVar3 / 2));
    iVar13 = 0;
    iVar12 = 0;
    do {
      if ((0 < iVar3) && (iVar6 = *(int *)(lVar2 + 0x4e0), iVar9 < iVar6)) {
        puVar8 = &DAT_0481b9b8 + iVar13;
        iVar7 = 0;
        do {
          iVar1 = iVar7 + 1;
          *puVar8 = *(undefined1 *)(lVar2 + (iVar7 + iVar10 * iVar6 + iVar9) + 0x4e8);
          if (((2 < iVar3 && 2 < iVar4) &&
               (iVar12 < (int)((float)iVar4 * fVar14 + 0.5) && iVar5 == 3)) &&
             (iVar7 < iVar11 || iVar3 - iVar11 <= iVar7)) {
            *puVar8 = 0;
          }
          puVar8 = puVar8 + 1;
        } while ((iVar3 != iVar1) &&
                (iVar6 = *(int *)(lVar2 + 0x4e0), iVar7 = iVar1, iVar1 + iVar9 < iVar6));
      }
      iVar12 = iVar12 + 1;
      if (iVar4 == iVar12) break;
      iVar10 = iVar10 + 1;
      iVar13 = iVar13 + iVar3;
    } while (iVar10 < *(int *)(lVar2 + 0x4e4));
  }
  DAT_048205e0 = *param_1;
  DAT_048205e8 = param_1[1];
  DAT_048205f0 = param_1[2];
  DAT_048205f8 = *(undefined4 *)(param_1 + 3);
  return 0;
}



/* FUNCTION FUN_007ea850 @ 007ea850 body=[[007ea850, 007ea903] [007ea908, 007ea90b] [007ea910, 007ea9a3] [007ea9a8, 007ea9db] [007ea9e0, 007ea9f3] [007ea9f8, 007ea9ff]]
REF 00f01084 INDIRECTION caller=NONE
REF 00f64318 DATA caller=NONE
REF 007eab50 UNCONDITIONAL_CALL caller=imvt_nnie_af_update_af_and_face@007eaab8
REF 007ead40 UNCONDITIONAL_CALL caller=imvt_nnie_af_handle_detection@007eac80
*/

void FUN_007ea850(int *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  char cVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  double dVar13;
  
  iVar3 = param_1[2];
  iVar5 = param_1[3];
  fVar11 = (float)(iVar3 * iVar5);
  dVar13 = (double)(fVar11 / DAT_007eaa00);
  if (DAT_007eaa08 <= dVar13) {
    iVar10 = DAT_01041e8c;
    if (DAT_007eaa10 <= dVar13) {
      if (DAT_007eaa18 <= dVar13) {
        iVar10 = DAT_01041e8c << 1;
      }
      else {
        iVar10 = (int)((double)DAT_01041e8c * DAT_007eaa20);
      }
    }
  }
  else {
    iVar10 = DAT_01041e8c / 2;
  }
  fVar12 = (float)((int)DAT_01041e98 * DAT_01041e98._4_4_);
  if (iVar3 * iVar5 < (int)DAT_01041e98 * DAT_01041e98._4_4_) {
    fVar11 = fVar11 / fVar12;
  }
  else {
    fVar11 = fVar12 / fVar11;
  }
  iVar4 = *param_1;
  iVar6 = param_1[1];
  if (DAT_007eaa28 <= (double)fVar11) {
    iVar7 = DAT_01041e90._4_4_ - iVar6;
    bVar1 = false;
    iVar2 = -iVar7;
    if (-1 < iVar7) {
      iVar2 = iVar7;
    }
    if (iVar2 <= iVar10) {
      iVar7 = (int)DAT_01041e90 - iVar4;
      iVar2 = -iVar7;
      if (-1 < iVar7) {
        iVar2 = iVar7;
      }
      bVar1 = iVar2 <= iVar10;
    }
    iVar7 = ((int)DAT_01041e90 + (int)DAT_01041e98) - (iVar3 + iVar4);
    iVar2 = -iVar7;
    if (-1 < iVar7) {
      iVar2 = iVar7;
    }
    if (iVar10 < iVar2) {
      bVar1 = false;
    }
    iVar7 = (DAT_01041e90._4_4_ + DAT_01041e98._4_4_) - (iVar5 + iVar6);
    iVar2 = -iVar7;
    if (-1 < iVar7) {
      iVar2 = iVar7;
    }
    if (iVar10 < iVar2) {
      bVar1 = false;
    }
    cVar9 = (int)DAT_01041e90 == iVar4;
    if (iVar6 == DAT_01041e90._4_4_) {
      cVar9 = cVar9 + '\x01';
    }
    if ((int)DAT_01041e90 + (int)DAT_01041e98 == iVar3 + iVar4) goto LAB_007ea96c;
LAB_007ea8e4:
    if (DAT_01041e90._4_4_ + DAT_01041e98._4_4_ != iVar5 + iVar6) goto LAB_007ea8ec;
LAB_007ea978:
    cVar9 = cVar9 + '\x01';
  }
  else {
    cVar9 = (int)DAT_01041e90 == iVar4;
    if (iVar6 == DAT_01041e90._4_4_) {
      cVar9 = cVar9 + '\x01';
    }
    bVar1 = false;
    if ((int)DAT_01041e90 + (int)DAT_01041e98 != iVar3 + iVar4) goto LAB_007ea8e4;
LAB_007ea96c:
    cVar9 = cVar9 + '\x01';
    if (DAT_01041e90._4_4_ + DAT_01041e98._4_4_ == iVar5 + iVar6) goto LAB_007ea978;
  }
  if ((cVar9 == '\x03') && (DAT_007eaa18 < (double)fVar11)) {
    uVar8 = CONCAT44(DAT_01041e98._4_4_,(int)DAT_01041e98);
    *(ulong *)param_1 = CONCAT44(DAT_01041e90._4_4_,(int)DAT_01041e90);
    *(undefined8 *)(param_1 + 2) = uVar8;
    return;
  }
LAB_007ea8ec:
  if (bVar1) {
    uVar8 = CONCAT44(DAT_01041e98._4_4_,(int)DAT_01041e98);
    *(ulong *)param_1 = CONCAT44(DAT_01041e90._4_4_,(int)DAT_01041e90);
    *(undefined8 *)(param_1 + 2) = uVar8;
    return;
  }
  return;
}



/* FUNCTION FUN_007eaa30 @ 007eaa30 body=[[007eaa30, 007eaaab]]
REF 00f0108c INDIRECTION caller=NONE
REF 00f6432c DATA caller=NONE
REF 007eab58 UNCONDITIONAL_CALL caller=imvt_nnie_af_update_af_and_face@007eaab8
REF 007ead48 UNCONDITIONAL_CALL caller=imvt_nnie_af_handle_detection@007eac80
*/

void FUN_007eaa30(int *param_1)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,&DAT_01041e90,0x10);
  if (iVar1 == 0) {
    return;
  }
  DAT_01041e90 = *(undefined8 *)param_1;
  DAT_01041e98 = *(undefined8 *)(param_1 + 2);
  imvt_af_set_roi((float)*param_1 / DAT_007eaab0,(float)param_1[1] / DAT_007eaaac,
                  (float)param_1[2] / DAT_007eaab0,(float)param_1[3] / DAT_007eaaac);
  return;
}



/* FUNCTION imvt_printf @ 00a38960 body=[[00a38960, 00a38c77]]
REF Entry Point EXTERNAL caller=NONE
REF 01034ab0 DATA caller=NONE
REF 00f0f604 INDIRECTION caller=NONE
REF 00fb3c0c DATA caller=NONE
REF 007aa060 UNCONDITIONAL_CALL caller=addUartConnection@007a9fb0
REF 007aa118 UNCONDITIONAL_CALL caller=addUartConnection@007a9fb0
REF 007a91fc UNCONDITIONAL_CALL caller=UartConnection@007a9168
REF 007a958c UNCONDITIONAL_CALL caller=init@007a9560
REF 007a95b8 UNCONDITIONAL_CALL caller=init@007a9560
REF 007abf6c UNCONDITIONAL_CALL caller=init@007abe38
REF 007ab1ac UNCONDITIONAL_CALL caller=openTty@007ab0b8
REF 007ab1d4 UNCONDITIONAL_CALL caller=openTty@007ab0b8
REF 007ab1f8 UNCONDITIONAL_CALL caller=openTty@007ab0b8
REF 007d6d48 UNCONDITIONAL_CALL caller=insertEventJsonMap@007d6ce8
REF 007df95c UNCONDITIONAL_CALL caller=initEventJsonMap@007df768
REF 00607efc UNCONDITIONAL_CALL caller=main@00607ad0
REF 00607fd8 UNCONDITIONAL_CALL caller=main@00607ad0
REF 00608004 UNCONDITIONAL_CALL caller=main@00607ad0
REF 0060801c UNCONDITIONAL_CALL caller=main@00607ad0
REF 00608034 UNCONDITIONAL_CALL caller=main@00607ad0
REF 006080c4 UNCONDITIONAL_CALL caller=main@00607ad0
REF 006080d8 UNCONDITIONAL_CALL caller=main@00607ad0
REF 00608158 UNCONDITIONAL_CALL caller=main@00607ad0
REF 00611834 UNCONDITIONAL_CALL caller=FUN_006117f8@006117f8
REF 007aa21c UNCONDITIONAL_CALL caller=addUartConnection@007aa150
REF 007aa258 UNCONDITIONAL_CALL caller=addUartConnection@007aa150
REF 007aa288 UNCONDITIONAL_CALL caller=addUartConnection@007aa150
REF 0061466c UNCONDITIONAL_CALL caller=guiMain@006145b8
REF 0061469c UNCONDITIONAL_CALL caller=guiMain@006145b8
REF 0065e0a8 UNCONDITIONAL_CALL caller=scanFolder@0065dce8
REF 00687ba0 UNCONDITIONAL_CALL caller=find@00687a78
REF 006c339c UNCONDITIONAL_CALL caller=trValueFromInt@006c32f8
REF 006b0498 UNCONDITIONAL_CALL caller=commit@006b0288
REF 006afed0 UNCONDITIONAL_CALL caller=stringToInt@006afe50
REF 006b1c38 UNCONDITIONAL_CALL caller=reload@006b1be0
REF 006b1d64 UNCONDITIONAL_CALL caller=reload@006b1be0
REF 006b1d94 UNCONDITIONAL_CALL caller=reload@006b1be0
REF 006b1a84 UNCONDITIONAL_CALL caller=loadContent@006b1748
REF 006da7a8 UNCONDITIONAL_CALL caller=FUN_006da6c0@006da6c0
REF 006da7e4 UNCONDITIONAL_CALL caller=FUN_006da6c0@006da6c0
REF 006e736c UNCONDITIONAL_CALL caller=reset@006e72d0
REF 0086e504 UNCONDITIONAL_CALL caller=imvt_cam_movie_stop@0086e420
REF 006f91a4 UNCONDITIONAL_CALL caller=imvt_cam_controller_photo_cap_stop@006f9138
REF 006b0e8c UNCONDITIONAL_CALL caller=preference_get_int_value@006b0e50
REF 006fc980 UNCONDITIONAL_CALL caller=imvt_cam_controller_color_lut_load@006fc8f8
REF 008892e4 UNCONDITIONAL_CALL caller=imvt_n3a_af_set_mode@00889220
REF 008883c4 UNCONDITIONAL_CALL caller=imvt_n3a_af_set_roi@00888298
REF 008893a4 UNCONDITIONAL_CALL caller=imvt_n3a_af_set_roi_type@00889338
REF 00701ae8 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_stop_record@00701a78
REF 00701b34 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_stop_record@00701a78
REF 00701bc0 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_stop_record@00701a78
REF 0070177c UNCONDITIONAL_CALL caller=FUN_00701748@00701748
REF 006e99ac UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006e9d20 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006e9d40 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006e9d90 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006e9f34 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea2e8 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea30c UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea330 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea354 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea384 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea3a0 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea3c0 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea3e0 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea400 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea448 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea468 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea484 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea4a8 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea4c8 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea4ec UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea508 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 006ea51c UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
REF 00613894 UNCONDITIONAL_CALL caller=imvt_cam_product_override_bitrate_settings@006137d0
REF 006db4d0 UNCONDITIONAL_CALL caller=network_register_callback@006db4a8
REF 006f2750 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_start_stream_service@006f2410
REF 006f2824 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_start_stream_service@006f2410
REF 006ee538 UNCONDITIONAL_CALL caller=FUN_006ee450@006ee450
REF 006ee594 UNCONDITIONAL_CALL caller=FUN_006ee450@006ee450
REF 006ee618 UNCONDITIONAL_CALL caller=FUN_006ee450@006ee450
REF 006ee670 UNCONDITIONAL_CALL caller=FUN_006ee450@006ee450
REF 006ee6e4 UNCONDITIONAL_CALL caller=FUN_006ee450@006ee450
REF 006f62f8 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_init@006f5e88
REF 0086f78c UNCONDITIONAL_CALL caller=imvt_cam_movie_set_timelapse_interval@0086f708
REF 0086f7fc UNCONDITIONAL_CALL caller=imvt_cam_movie_set_timelapse_interval@0086f708
REF 0086f86c UNCONDITIONAL_CALL caller=imvt_cam_movie_set_timelapse_interval@0086f708
REF 0086f8dc UNCONDITIONAL_CALL caller=imvt_cam_movie_set_timelapse_interval@0086f708
REF 0086f94c UNCONDITIONAL_CALL caller=imvt_cam_movie_set_timelapse_interval@0086f708
REF 0086f964 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_timelapse_interval@0086f708
REF 0086ff1c UNCONDITIONAL_CALL caller=imvt_cam_movie_set_max_duration@0086fe98
REF 0086ff8c UNCONDITIONAL_CALL caller=imvt_cam_movie_set_max_duration@0086fe98
REF 0086fffc UNCONDITIONAL_CALL caller=imvt_cam_movie_set_max_duration@0086fe98
REF 0087006c UNCONDITIONAL_CALL caller=imvt_cam_movie_set_max_duration@0086fe98
REF 008700dc UNCONDITIONAL_CALL caller=imvt_cam_movie_set_max_duration@0086fe98
REF 006eeb34 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_stop_prerecord@006eeac8
REF 006eeb98 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_stop_prerecord@006eeac8
REF 006eebdc UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_stop_prerecord@006eeac8
REF 006f39b0 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_start_prerecord@006f3918
REF 006f3a5c UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_start_prerecord@006f3918
REF 006f3ac8 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_start_prerecord@006f3918
REF 006f3b20 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_start_prerecord@006f3918
REF 006f3b38 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_start_prerecord@006f3918
REF 006f3b4c UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_start_prerecord@006f3918
REF 006f3b6c UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_start_prerecord@006f3918
REF 006e8474 UNCONDITIONAL_CALL caller=FUN_006e8418@006e8418
REF 006f2f4c UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_timecode@006f2ee8
REF 006f2fbc UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_timecode@006f2ee8
REF 006f3398 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_meta_config@006f2fc8
REF 006f33e0 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_meta_config@006f2fc8
REF 006f37cc UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_meta_config@006f2fc8
REF 006f5a0c UNCONDITIONAL_CALL caller=imvt_cam_controller_set_record_encoder_format@006f5988
REF 006f5a7c UNCONDITIONAL_CALL caller=imvt_cam_controller_set_record_encoder_format@006f5988
REF 006ec43c UNCONDITIONAL_CALL caller=imvt_cam_controller_constraint_get_prores_bitrate@006ec398
REF 006ec490 UNCONDITIONAL_CALL caller=imvt_cam_controller_constraint_get_prores_bitrate@006ec398
REF 006ec9d4 UNCONDITIONAL_CALL caller=imvt_cam_controller_constraint_is_video_encoder_type_supported@006ec958
REF 006eca24 UNCONDITIONAL_CALL caller=imvt_cam_controller_constraint_is_video_encoder_type_supported@006ec958
REF 006eca54 UNCONDITIONAL_CALL caller=imvt_cam_controller_constraint_is_video_encoder_type_supported@006ec958
REF 006eca7c UNCONDITIONAL_CALL caller=imvt_cam_controller_constraint_is_video_encoder_type_supported@006ec958
REF 006ecb04 UNCONDITIONAL_CALL caller=imvt_cam_controller_constraint_is_video_encoder_type_supported@006ec958
REF 006f0744 UNCONDITIONAL_CALL caller=imvt_cam_contoller_streaming_pause@006f0708
REF 006f080c UNCONDITIONAL_CALL caller=imvt_cam_contoller_streaming_pause@006f0708
REF 006ef5dc UNCONDITIONAL_CALL caller=imvt_cam_controller_disable_rtmp@006ef450
REF 006ef61c UNCONDITIONAL_CALL caller=imvt_cam_controller_disable_rtmp@006ef450
REF 006f55c4 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_video_rotation@006f5538
REF 0086902c UNCONDITIONAL_CALL caller=imvt_cam_set_rotation@00868f88
REF 00869050 UNCONDITIONAL_CALL caller=imvt_cam_set_rotation@00868f88
REF 006fa798 UNCONDITIONAL_CALL caller=imvt_cam_controller_output_camera_version@006fa760
REF 006fa7b0 UNCONDITIONAL_CALL caller=imvt_cam_controller_output_camera_version@006fa760
REF 006fa7c8 UNCONDITIONAL_CALL caller=imvt_cam_controller_output_camera_version@006fa760
REF 006fa84c UNCONDITIONAL_CALL caller=imvt_cam_controller_get_sn@006fa7f8
REF 006fec58 UNCONDITIONAL_CALL caller=FUN_006fe728@006fe728
REF 006fecb0 UNCONDITIONAL_CALL caller=FUN_006fe728@006fe728
REF 006ffa1c UNCONDITIONAL_CALL caller=FUN_006fe728@006fe728
REF 006ffa38 UNCONDITIONAL_CALL caller=FUN_006fe728@006fe728
REF 006ffad0 UNCONDITIONAL_CALL caller=FUN_006fe728@006fe728
REF 006f1ba8 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_raw_send_start@006f19a8
REF 006f1ccc UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_raw_send_start@006f19a8
REF 006f1ce4 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_raw_send_start@006f19a8
REF 006f1d10 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_raw_send_start@006f19a8
REF 006f1d28 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_raw_send_start@006f19a8
REF 006f1d40 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_raw_send_start@006f19a8
REF 006f1968 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_raw_send_update_timecode@006f18d0
REF 006f199c UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_raw_send_update_timecode@006f18d0
REF 006f6494 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_send_stream_type@006f6428
REF 006f6668 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_send_stream_type@006f6428
REF 006f66fc UNCONDITIONAL_CALL caller=imvt_cam_controller_set_send_stream_type@006f6428
REF 006f3c58 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_record_null_write@006f3c30
REF 006f3d3c UNCONDITIONAL_CALL caller=imvt_cam_controller_set_record_null_write@006f3c30
REF 006f825c UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_set_raw_stacking_info@006f8218
REF 006f7bf0 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_ae_set_shutter_time_seq@006f7b98
REF 006f86bc UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_chk_and_upd_extend_iso_status@006f8560
REF 006f854c UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_update_extend_iso_and_pregamma_index@006f8440
REF 006f8078 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_upd_auto_min_iso_limit@006f8038
REF 006fc6ac UNCONDITIONAL_CALL caller=imvt_cam_controller_opmode_set_mode@006fc3e0
REF 006fc6d0 UNCONDITIONAL_CALL caller=imvt_cam_controller_opmode_set_mode@006fc3e0
REF 006ef874 UNCONDITIONAL_CALL caller=imvt_cam_controller_rtmp_auto_restart@006ef760
REF 006eeffc UNCONDITIONAL_CALL caller=imvt_cam_controller_get_rtmp_url@006eee88
REF 006ef168 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_rtmp@006ef080
REF 006ef40c UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_rtmp@006ef080
REF 006ef440 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_rtmp@006ef080
REF 006ed5f4 UNCONDITIONAL_CALL caller=FUN_006ed380@006ed380
REF 006ed898 UNCONDITIONAL_CALL caller=FUN_006ed380@006ed380
REF 006edfac UNCONDITIONAL_CALL caller=imvt_cam_controller_start_record@006edd48
REF 006ee060 UNCONDITIONAL_CALL caller=imvt_cam_controller_start_record@006edd48
REF 006ee084 UNCONDITIONAL_CALL caller=imvt_cam_controller_start_record@006edd48
REF 00872dc0 UNCONDITIONAL_CALL caller=imvt_cam_movie_start@00872ca0
REF 0087ac00 UNCONDITIONAL_CALL caller=imvt_cam_raw_send_trigger_record_start@0087ab90
REF 006f0244 UNCONDITIONAL_CALL caller=imvt_cam_controller_srt_auto_restart@006f0150
REF 006efc64 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_srt@006efa88
REF 006efc80 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_srt@006efa88
REF 006efc9c UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_srt@006efa88
REF 009e6860 UNCONDITIONAL_CALL caller=fmt_push_muxer_push_is_runing@009e67f0
REF 006f4804 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_fourth_stream_split_duration@006f4700
REF 0086fddc UNCONDITIONAL_CALL caller=imvt_cam_movie_get_split_interval@0086fd48
REF 0086fe1c UNCONDITIONAL_CALL caller=imvt_cam_movie_get_split_interval@0086fd48
REF 0086fe5c UNCONDITIONAL_CALL caller=imvt_cam_movie_get_split_interval@0086fd48
REF 0086fe74 UNCONDITIONAL_CALL caller=imvt_cam_movie_get_split_interval@0086fd48
REF 0086fe8c UNCONDITIONAL_CALL caller=imvt_cam_movie_get_split_interval@0086fd48
REF 0086f478 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_record_audio_type@0086f3e0
REF 0086f4c4 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_record_audio_type@0086f3e0
REF 0086f4e0 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_record_audio_type@0086f3e0
REF 0086f538 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_record_audio_type@0086f3e0
REF 0086f550 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_record_audio_type@0086f3e0
REF 0086f568 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_record_audio_type@0086f3e0
REF 0086f580 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_record_audio_type@0086f3e0
REF 0086f598 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_record_audio_type@0086f3e0
REF 00701d94 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_check_master_record_or_photo_prepared_ready@00701cc8
REF 00701da8 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_check_master_record_or_photo_prepared_ready@00701cc8
REF 006fd968 UNCONDITIONAL_CALL caller=imvt_cam_controller_get_is_low_battery@006fd8b0
REF 00703360 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_set_movie_timecode@00703318
REF 0086d484 UNCONDITIONAL_CALL caller=imvt_movie_set_timecode@0086d428
REF 0086d500 UNCONDITIONAL_CALL caller=imvt_movie_set_timecode@0086d428
REF 0086d51c UNCONDITIONAL_CALL caller=imvt_movie_set_timecode@0086d428
REF 0086d534 UNCONDITIONAL_CALL caller=imvt_movie_set_timecode@0086d428
REF 0086d54c UNCONDITIONAL_CALL caller=imvt_movie_set_timecode@0086d428
REF 00703c90 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_start_record@00703b38
REF 00703d10 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_start_record@00703b38
REF 00703d64 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_start_record@00703b38
REF 00703da0 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_start_record@00703b38
REF 00701f44 UNCONDITIONAL_CALL caller=FUN_00701ea0@00701ea0
REF 00701fbc UNCONDITIONAL_CALL caller=FUN_00701ea0@00701ea0
REF 00702020 UNCONDITIONAL_CALL caller=FUN_00701ea0@00701ea0
REF 00702038 UNCONDITIONAL_CALL caller=FUN_00701ea0@00701ea0
REF 00702058 UNCONDITIONAL_CALL caller=FUN_00701ea0@00701ea0
REF 00702078 UNCONDITIONAL_CALL caller=FUN_00701ea0@00701ea0
REF 007041b4 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_net_sync_init_task@00704068
REF 007041d8 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_net_sync_init_task@00704068
REF 00704204 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_net_sync_init_task@00704068
REF 0061368c UNCONDITIONAL_CALL caller=imvt_lcd_ui_init@00613678
REF 00704fd8 UNCONDITIONAL_CALL caller=FUN_00704f50@00704f50
REF 0071553c UNCONDITIONAL_CALL caller=imvt_cam_app_set_config@00714fe8
REF 006e95c8 UNCONDITIONAL_CALL caller=imvt_cam_controller_exit@006e9540
REF 0088847c UNCONDITIONAL_CALL caller=imvt_n3a_af_get_roi@008883e8
REF 00888f94 UNCONDITIONAL_CALL caller=FUN_00888f7c@00888f7c
REF 00730a24 UNCONDITIONAL_CALL caller=imvt_af_set_range_normal@00730a08
REF 00730a54 UNCONDITIONAL_CALL caller=imvt_af_set_range_micro@00730a38
REF 00730a7c UNCONDITIONAL_CALL caller=imvt_af_set_rang_all@00730a68
REF 00888fdc UNCONDITIONAL_CALL caller=FUN_00888fc4@00888fc4
REF 00888534 UNCONDITIONAL_CALL caller=imvt_n3a_af_flip_enable@00888488
REF 0073134c UNCONDITIONAL_CALL caller=fmt_mjpeg_http_create@00731220
REF 007313ec UNCONDITIONAL_CALL caller=fmt_mjpeg_http_destroy@00731368
REF 00731660 UNCONDITIONAL_CALL caller=fmt_mjpeg_http_force_enable_push@007315f8
REF 00731694 UNCONDITIONAL_CALL caller=fmt_mjpeg_http_force_enable_push@007315f8
REF 00731724 UNCONDITIONAL_CALL caller=fmt_mjpeg_http_force_disable_push@007316c8
REF 00731788 UNCONDITIONAL_CALL caller=fmt_mjpeg_http_force_disable_push@007316c8
REF 00733398 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_init_resolution@007332b8
REF 00732d58 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_set_resolution@00732c48
REF 00732d78 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_set_resolution@00732c48
REF 00732d98 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_set_resolution@00732c48
REF 00733248 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_convert_resolution@00733118
REF 00733264 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_convert_resolution@00733118
REF 0073328c UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_convert_resolution@00733118
REF 007332ac UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_convert_resolution@00733118
REF 00733578 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_set_fps@007333b8
REF 00733598 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_set_fps@007333b8
REF 007335b8 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_set_fps@007333b8
REF 0073405c UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_resolution@00733eb0
REF 00734080 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_resolution@00733eb0
REF 007340a8 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_resolution@00733eb0
REF 007340c4 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_resolution@00733eb0
REF 007341e0 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_fps@007340d0
REF 00734200 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_fps@007340d0
REF 007342ec UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_video_encoder@00734210
REF 0073430c UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_video_encoder@00734210
REF 00734330 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_video_encoder@00734210
REF 00734350 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_video_encoder@00734210
REF 00734438 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_bitrate@00734360
REF 00734458 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_bitrate@00734360
REF 00734474 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_update_bitrate@00734360
REF 0073599c UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_init_config@007358a0
REF 007359c0 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_init_config@007358a0
REF 00735a40 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_init_config@007358a0
REF 00735e90 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_init_config@007358a0
REF 00735eac UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_init_config@007358a0
REF 00735ec8 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_init_config@007358a0
REF 007352d8 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_get_machine_name@00735248
REF 006db060 UNCONDITIONAL_CALL caller=get_mac_address@006daf68
REF 007355d8 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_get_stream_name@007354b0
REF 00735600 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_get_stream_name@007354b0
REF 00735838 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_get_group_name@00735760
REF 00739b40 UNCONDITIONAL_CALL caller=start@00739a50
REF 007465e4 UNCONDITIONAL_CALL caller=SSLContext@00746588
REF 0074662c UNCONDITIONAL_CALL caller=SSLContext@00746588
REF 00746848 UNCONDITIONAL_CALL caller=initWithPem@00746790
REF 00746860 UNCONDITIONAL_CALL caller=initWithPem@00746790
REF 00746880 UNCONDITIONAL_CALL caller=initWithPem@00746790
REF 00746894 UNCONDITIONAL_CALL caller=initWithPem@00746790
REF 007a8db0 UNCONDITIONAL_CALL caller=init@007a8d80
REF 007a8e24 UNCONDITIONAL_CALL caller=init@007a8d80
REF 007a8e74 UNCONDITIONAL_CALL caller=init@007a8d80
REF 007a8c5c UNCONDITIONAL_CALL caller=openTty@007a8b38
REF 007a8ca4 UNCONDITIONAL_CALL caller=openTty@007a8b38
REF 007a8cc8 UNCONDITIONAL_CALL caller=openTty@007a8b38
REF 007a97d8 UNCONDITIONAL_CALL caller=~UartService@007a97a8
REF 007a9708 UNCONDITIONAL_CALL caller=deinit@007a9698
REF 007a9610 UNCONDITIONAL_CALL caller=deinit@007a95e0
REF 007aaf84 UNCONDITIONAL_CALL caller=deinit@007aaf18
REF 007aafc4 UNCONDITIONAL_CALL caller=deinit@007aaf18
REF 007b553c UNCONDITIONAL_CALL caller=UartComm@007b5498
REF 007b5574 UNCONDITIONAL_CALL caller=UartComm@007b5498
REF 007b5964 UNCONDITIONAL_CALL caller=init@007b5920
REF 007b5aac UNCONDITIONAL_CALL caller=init@007b5920
REF 007b5af8 UNCONDITIONAL_CALL caller=init@007b5920
REF 007b58c4 UNCONDITIONAL_CALL caller=openTty@007b57d0
REF 007b58ec UNCONDITIONAL_CALL caller=openTty@007b57d0
REF 007b5910 UNCONDITIONAL_CALL caller=openTty@007b57d0
REF 007beed8 UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_sync_dcf_index@007beec0
REF 007c09cc UNCONDITIONAL_CALL caller=imvt_cam_uart_master_controller_broadcast_master_raw_stack_info@007c0920
REF 007c09e4 UNCONDITIONAL_CALL caller=imvt_cam_uart_master_controller_broadcast_master_raw_stack_info@007c0920
REF 007c0b38 UNCONDITIONAL_CALL caller=imvt_calibration_set_factory_mode@007c0b18
REF 007c0b4c UNCONDITIONAL_CALL caller=imvt_calibration_set_factory_mode@007c0b18
REF 007c0bcc UNCONDITIONAL_CALL caller=imvt_calibration_get_isolated_status@007c0ba0
REF 007c1210 UNCONDITIONAL_CALL caller=imvt_calib_auto_reboot_flag_check@007c11a0
REF 007c1330 UNCONDITIONAL_CALL caller=imvt_calib_auto_reboot_flag_check@007c11a0
REF 007c136c UNCONDITIONAL_CALL caller=imvt_calib_auto_reboot_flag_check@007c11a0
REF 007c13c8 UNCONDITIONAL_CALL caller=imvt_calib_auto_reboot_flag_check@007c11a0
REF 007c13d8 UNCONDITIONAL_CALL caller=imvt_calib_auto_reboot_flag_check@007c11a0
REF 007c0ca4 UNCONDITIONAL_CALL caller=FUN_007c0bf0@007c0bf0
REF 007c40d0 UNCONDITIONAL_CALL caller=imvt_wb_calib_init@007c3f88
REF 007c40e4 UNCONDITIONAL_CALL caller=imvt_wb_calib_init@007c3f88
REF 007c4104 UNCONDITIONAL_CALL caller=imvt_wb_calib_init@007c3f88
REF 007c411c UNCONDITIONAL_CALL caller=imvt_wb_calib_init@007c3f88
REF 007c33f4 UNCONDITIONAL_CALL caller=FUN_007c31e0@007c31e0
REF 007c341c UNCONDITIONAL_CALL caller=FUN_007c31e0@007c31e0
REF 007c34b8 UNCONDITIONAL_CALL caller=FUN_007c31e0@007c31e0
REF 007c34c8 UNCONDITIONAL_CALL caller=FUN_007c31e0@007c31e0
REF 007c886c UNCONDITIONAL_CALL caller=imvt_dpc_init@007c8768
REF 007c8888 UNCONDITIONAL_CALL caller=imvt_dpc_init@007c8768
REF 007c88a8 UNCONDITIONAL_CALL caller=imvt_dpc_init@007c8768
REF 007c88b4 UNCONDITIONAL_CALL caller=imvt_dpc_init@007c8768
REF 007c88c0 UNCONDITIONAL_CALL caller=imvt_dpc_init@007c8768
REF 007ca290 UNCONDITIONAL_CALL caller=imvt_blc_calib_set_current_resolution_group@007ca260
REF 007ca318 UNCONDITIONAL_CALL caller=imvt_blc_calib_set_current_resolution_group@007ca260
REF 007cee30 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_init@007cebc8
REF 007cee68 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_init@007cebc8
REF 007cef28 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_init@007cebc8
REF 007cef4c UNCONDITIONAL_CALL caller=imvt_blc_calib_high_init@007cebc8
REF 007cef60 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_init@007cebc8
REF 007cef78 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_init@007cebc8
REF 007cef98 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_init@007cebc8
REF 007cefb8 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_init@007cebc8
REF 007cefc8 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_init@007cebc8
REF 007cefe0 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_init@007cebc8
REF 007cf000 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_init@007cebc8
REF 007cf020 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_init@007cebc8
REF 00a3a264 UNCONDITIONAL_CALL caller=imvt_task_start@00a3a1f8
REF 00a3a288 UNCONDITIONAL_CALL caller=imvt_task_start@00a3a1f8
REF 00a3a2a4 UNCONDITIONAL_CALL caller=imvt_task_start@00a3a1f8
REF 007e9950 UNCONDITIONAL_CALL caller=imvt_nnie_init@007e9850
REF 007e9c18 UNCONDITIONAL_CALL caller=imvt_nnie_enable@007e9b88
REF 007e9c38 UNCONDITIONAL_CALL caller=imvt_nnie_enable@007e9b88
REF 007e9d74 UNCONDITIONAL_CALL caller=imvt_nnie_deinit@007e9c48
REF 007e9de0 UNCONDITIONAL_CALL caller=imvt_nnie_deinit@007e9c48
REF 007e9df4 UNCONDITIONAL_CALL caller=imvt_nnie_deinit@007e9c48
REF 007e9e0c UNCONDITIONAL_CALL caller=imvt_nnie_deinit@007e9c48
REF 007ea184 UNCONDITIONAL_CALL caller=FUN_007ea0e8@007ea0e8
REF 0087a2e0 UNCONDITIONAL_CALL caller=imvt_cam_dispatcher_start@0087a220
REF 0087a308 UNCONDITIONAL_CALL caller=imvt_cam_dispatcher_start@0087a220
REF 0087a324 UNCONDITIONAL_CALL caller=imvt_cam_dispatcher_start@0087a220
REF 0087a418 UNCONDITIONAL_CALL caller=imvt_cam_dispatcher_stop@0087a338
REF 0087a440 UNCONDITIONAL_CALL caller=imvt_cam_dispatcher_stop@0087a338
REF 0087a460 UNCONDITIONAL_CALL caller=imvt_cam_dispatcher_stop@0087a338
REF 00801c2c UNCONDITIONAL_CALL caller=update_clut@00801b78
REF 00801f0c UNCONDITIONAL_CALL caller=update_clut@00801b78
REF 00801f44 UNCONDITIONAL_CALL caller=update_clut@00801b78
REF 00802830 UNCONDITIONAL_CALL caller=setMatrixValue@008027c8
REF 00802848 UNCONDITIONAL_CALL caller=setMatrixValue@008027c8
REF 008065e8 UNCONDITIONAL_CALL caller=gl_assitool_init@00806450
REF 00a4142c UNCONDITIONAL_CALL caller=shell_register@00a412d8
REF 00a41514 UNCONDITIONAL_CALL caller=shell_register@00a412d8
REF 00a41544 UNCONDITIONAL_CALL caller=shell_register@00a412d8
REF 0081b574 UNCONDITIONAL_CALL caller=imvt_custom_gamma_update_system_gamma@0081b450
REF 0081b588 UNCONDITIONAL_CALL caller=imvt_custom_gamma_update_system_gamma@0081b450
REF 0081b71c UNCONDITIONAL_CALL caller=imvt_cgamma_wrapper_set_version@0081b5f8
REF 0081c14c UNCONDITIONAL_CALL caller=FUN_0081c0c8@0081c0c8
REF 0081c168 UNCONDITIONAL_CALL caller=FUN_0081c0c8@0081c0c8
REF 00821bbc UNCONDITIONAL_CALL caller=imvt_cam_wifi_ctrl_init@00821b20
REF 00821be0 UNCONDITIONAL_CALL caller=imvt_cam_wifi_ctrl_init@00821b20
REF 00821c08 UNCONDITIONAL_CALL caller=imvt_cam_wifi_ctrl_init@00821b20
REF 008229a8 UNCONDITIONAL_CALL caller=imvt_raw_stacking_init@008228e0
REF 00822c44 UNCONDITIONAL_CALL caller=FUN_00822bc0@00822bc0
REF 00822c60 UNCONDITIONAL_CALL caller=FUN_00822bc0@00822bc0
REF 006e749c UNCONDITIONAL_CALL caller=setValue@006e73b8
REF 006e757c UNCONDITIONAL_CALL caller=imvt_mcache_set@006e7540
REF 006e75cc UNCONDITIONAL_CALL caller=FUN_006e75b4@006e75b4
REF 006e74dc UNCONDITIONAL_CALL caller=FUN_006e74c4@006e74c4
REF 006e7530 UNCONDITIONAL_CALL caller=imvt_mcache_get@006e74f8
REF 00828944 UNCONDITIONAL_CALL caller=getSecAndFrame@00828900
REF 00828a34 UNCONDITIONAL_CALL caller=enableRecRun@008289f8
REF 00829784 UNCONDITIONAL_CALL caller=setInitValue@008296e8
REF 0082a6b4 UNCONDITIONAL_CALL caller=imvt_app_timecode_get_movie_timecode_value@0082a488
REF 0082a6d0 UNCONDITIONAL_CALL caller=imvt_app_timecode_get_movie_timecode_value@0082a488
REF 007b5be0 UNCONDITIONAL_CALL caller=sendPacketToUart@007b5b78
REF 007b61ec UNCONDITIONAL_CALL caller=waitAck@007b60c8
REF 0082aba8 UNCONDITIONAL_CALL caller=imvt_app_timecode_set_vsif_rss_start@0082aab0
REF 0082ad90 UNCONDITIONAL_CALL caller=imvt_app_timecode_update_vsif_tc@0082aca8
REF 0082aeb4 UNCONDITIONAL_CALL caller=imvt_app_timecode_update_vsif_tc@0082aca8
REF 0082b048 UNCONDITIONAL_CALL caller=imvt_app_timecode_set_vsif_rss_stop@0082af58
REF 008322a0 UNCONDITIONAL_CALL caller=imvt_ptz_init@00832218
REF 00835284 UNCONDITIONAL_CALL caller=commSetTimeCode@00835178
REF 008353d4 UNCONDITIONAL_CALL caller=commSetRss@008352d8
REF 008365ac UNCONDITIONAL_CALL caller=commSetTimeCodeRunEnable@008364b0
REF 008481e0 UNCONDITIONAL_CALL caller=FUN_008480a0@008480a0
REF 0084823c UNCONDITIONAL_CALL caller=FUN_008480a0@008480a0
REF 00848258 UNCONDITIONAL_CALL caller=FUN_008480a0@008480a0
REF 0084826c UNCONDITIONAL_CALL caller=FUN_008480a0@008480a0
REF 00848288 UNCONDITIONAL_CALL caller=FUN_008480a0@008480a0
REF 0084980c UNCONDITIONAL_CALL caller=fmt_uvc_streamer_disable@008497d0
REF 00849878 UNCONDITIONAL_CALL caller=fmt_uvc_streamer_disable@008497d0
REF 00703ebc UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_net_sync_stop_rec_async@00703e40
REF 00868d0c UNCONDITIONAL_CALL caller=imvt_cam_opmode_init@00868bc8
REF 00868d90 UNCONDITIONAL_CALL caller=imvt_cam_opmode_init@00868bc8
REF 00885254 UNCONDITIONAL_CALL caller=imvt_sys_exit@00885230
REF 0086918c UNCONDITIONAL_CALL caller=imvt_cam_opmode_set_mode@00869168
REF 008692e8 UNCONDITIONAL_CALL caller=imvt_cam_opmode_set_mode@00869168
REF 00868a64 UNCONDITIONAL_CALL caller=FUN_008689f0@008689f0
REF 00868a8c UNCONDITIONAL_CALL caller=FUN_008689f0@008689f0
REF 00868b04 UNCONDITIONAL_CALL caller=FUN_008689f0@008689f0
REF 00868b28 UNCONDITIONAL_CALL caller=FUN_008689f0@008689f0
REF 00891c44 UNCONDITIONAL_CALL caller=imvt_aaa_cb_update_res@00891bf8
REF 00a5ad14 UNCONDITIONAL_CALL caller=imvt_switch_res_refresh_enc_param@00a5aad8
REF 008696c4 UNCONDITIONAL_CALL caller=imvt_cam_init@00869660
REF 00869710 UNCONDITIONAL_CALL caller=imvt_cam_init@00869660
REF 0086973c UNCONDITIONAL_CALL caller=imvt_cam_init@00869660
REF 00869768 UNCONDITIONAL_CALL caller=imvt_cam_init@00869660
REF 00869790 UNCONDITIONAL_CALL caller=imvt_cam_init@00869660
REF 00869510 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_res@00869498
REF 008695e4 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_res@00869498
REF 00869610 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_res@00869498
REF 0086963c UNCONDITIONAL_CALL caller=imvt_cam_movie_set_res@00869498
REF 00869654 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_res@00869498
REF 0086a0bc UNCONDITIONAL_CALL caller=FUN_00869f50@00869f50
REF 0086a0e4 UNCONDITIONAL_CALL caller=FUN_00869f50@00869f50
REF 0086a11c UNCONDITIONAL_CALL caller=FUN_00869f50@00869f50
REF 0086a134 UNCONDITIONAL_CALL caller=FUN_00869f50@00869f50
REF 0086a8c4 UNCONDITIONAL_CALL caller=FUN_0086a8a8@0086a8a8
REF 0086df34 UNCONDITIONAL_CALL caller=imvt_cam_movie_recording_cur_ref@0086dea8
REF 0086e7ac UNCONDITIONAL_CALL caller=_imvt_cam_movie_pre_record_disable@0086e760
REF 0086e7d8 UNCONDITIONAL_CALL caller=_imvt_cam_movie_pre_record_disable@0086e760
REF 0086e8b0 UNCONDITIONAL_CALL caller=imvt_cam_movie_force_stop@0086e830
REF 0086eeac UNCONDITIONAL_CALL caller=imvt_cam_movie_set_bitrate@0086eb78
REF 0086cd50 UNCONDITIONAL_CALL caller=FUN_0086cce8@0086cce8
REF 0086cdb0 UNCONDITIONAL_CALL caller=FUN_0086cce8@0086cce8
REF 0086fb54 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_split_interval@0086fad0
REF 0086fbc4 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_split_interval@0086fad0
REF 0086fc34 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_split_interval@0086fad0
REF 0086fca4 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_split_interval@0086fad0
REF 0086fd14 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_split_interval@0086fad0
REF 0086fd2c UNCONDITIONAL_CALL caller=imvt_cam_movie_set_split_interval@0086fad0
REF 008708bc UNCONDITIONAL_CALL caller=imvt_cam_movie_init@00870468
REF 00870904 UNCONDITIONAL_CALL caller=imvt_cam_movie_init@00870468
REF 0087096c UNCONDITIONAL_CALL caller=imvt_cam_movie_init@00870468
REF 008709a4 UNCONDITIONAL_CALL caller=imvt_cam_movie_init@00870468
REF 008709f4 UNCONDITIONAL_CALL caller=imvt_cam_movie_init@00870468
REF 00870a0c UNCONDITIONAL_CALL caller=imvt_cam_movie_init@00870468
REF 00870a20 UNCONDITIONAL_CALL caller=imvt_cam_movie_init@00870468
REF 00870c48 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_sn@00870bf0
REF 00870cb8 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_fw_version@00870c60
REF 00870d28 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_maker@00870cd0
REF 00870d98 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_model@00870d40
REF 00870e08 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_reel_name@00870db0
REF 00871168 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 008713a4 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00871b64 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00871fc8 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872044 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872088 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 008720d8 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872104 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 0087211c UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872134 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 008721c4 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872230 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872264 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 0087238c UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872440 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872550 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872574 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 0087266c UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 008726e0 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 0087275c UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 0087278c UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 008727a8 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 008727d0 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872898 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 008728bc UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872998 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 008729ac UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 008729c0 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 008729d4 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 008729ec UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872a00 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872a34 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00872a58 UNCONDITIONAL_CALL caller=FUN_00870f18@00870f18
REF 00870eb4 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_type@00870e90
REF 00870f00 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_type@00870e90
REF 00872bc0 UNCONDITIONAL_CALL caller=_imvt_cam_movie_pre_record_enable@00872ad8
REF 00872be8 UNCONDITIONAL_CALL caller=_imvt_cam_movie_pre_record_enable@00872ad8
REF 00872c10 UNCONDITIONAL_CALL caller=_imvt_cam_movie_pre_record_enable@00872ad8
REF 00872c34 UNCONDITIONAL_CALL caller=_imvt_cam_movie_pre_record_enable@00872ad8
REF 00872e3c UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_lut@00872e10
REF 00872e88 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_lut@00872e10
REF 00873094 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_clear_key@00872f28
REF 008730b0 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_clear_key@00872f28
REF 00873180 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_common@008730c8
REF 00873248 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_common@008730c8
REF 00873280 UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_common@008730c8
REF 0087329c UNCONDITIONAL_CALL caller=imvt_cam_movie_meta_set_common@008730c8
REF 00877564 UNCONDITIONAL_CALL caller=imvt_cam_audio_path_enable_aenc@008774f0
REF 008776cc UNCONDITIONAL_CALL caller=imvt_cam_audio_path_enable_ai@00877650
REF 00877754 UNCONDITIONAL_CALL caller=imvt_cam_audio_path_disable_ai@00877700
REF 00877810 UNCONDITIONAL_CALL caller=imvt_cam_audio_unregister_frame_cb@008777e0
REF 008778ec UNCONDITIONAL_CALL caller=imvt_cam_audio_path_init@00877890
REF 008774c4 UNCONDITIONAL_CALL caller=imvt_cam_audio_path_enable_hdmi_audio@00877460
REF 008773bc UNCONDITIONAL_CALL caller=imvt_cam_audio_path_disable_speaker@00877370
REF 00877434 UNCONDITIONAL_CALL caller=imvt_cam_audio_path_disable_hdmi_audio@008773e8
REF 00877c34 UNCONDITIONAL_CALL caller=imvt_cam_audio_rms_set_interval@00877bd8
REF 00877e28 UNCONDITIONAL_CALL caller=imvt_cam_audio_rms_init@00877da8
REF 00877f80 UNCONDITIONAL_CALL caller=imvt_cam_audio_rms_start@00877ef8
REF 00877f90 UNCONDITIONAL_CALL caller=imvt_cam_audio_rms_start@00877ef8
REF 00877fb8 UNCONDITIONAL_CALL caller=imvt_cam_audio_rms_start@00877ef8
REF 008777d0 UNCONDITIONAL_CALL caller=imvt_cam_audio_register_frame_cb@008777a0
REF 008784fc UNCONDITIONAL_CALL caller=audio_dispatcher_enable_channel@00878488
REF 0087855c UNCONDITIONAL_CALL caller=audio_dispatcher_enable_channel@00878488
REF 00878bbc UNCONDITIONAL_CALL caller=raw_audio_dispatcher_enable_channel@00878b08
REF 00878c10 UNCONDITIONAL_CALL caller=raw_audio_dispatcher_enable_channel@00878b08
REF 00878c44 UNCONDITIONAL_CALL caller=raw_audio_dispatcher_enable_channel@00878b08
REF 00878c58 UNCONDITIONAL_CALL caller=raw_audio_dispatcher_enable_channel@00878b08
REF 00878e90 UNCONDITIONAL_CALL caller=raw_audio_dispatcher_init@00878d78
REF 00878eb4 UNCONDITIONAL_CALL caller=raw_audio_dispatcher_init@00878d78
REF 00878ecc UNCONDITIONAL_CALL caller=raw_audio_dispatcher_init@00878d78
REF 00878ef4 UNCONDITIONAL_CALL caller=raw_audio_dispatcher_init@00878d78
REF 00878fe0 UNCONDITIONAL_CALL caller=raw_audio_dispatcher_exit@00878f10
REF 00878ff0 UNCONDITIONAL_CALL caller=raw_audio_dispatcher_exit@00878f10
REF 008791c8 UNCONDITIONAL_CALL caller=imvt_cam_liveview_start@00879040
REF 008791f8 UNCONDITIONAL_CALL caller=imvt_cam_liveview_start@00879040
REF 008aec88 UNCONDITIONAL_CALL caller=pipeline_init_adp@008aebd0
REF 0087a1a8 UNCONDITIONAL_CALL caller=imvt_cam_dispatcher_register@0087a158
REF 0087a214 UNCONDITIONAL_CALL caller=imvt_cam_dispatcher_register@0087a158
REF 0087a590 UNCONDITIONAL_CALL caller=imvt_cam_dispatcher_init@0087a470
REF 0087ab10 UNCONDITIONAL_CALL caller=imvt_cam_raw_send_start@0087aa88
REF 0087ab30 UNCONDITIONAL_CALL caller=imvt_cam_raw_send_start@0087aa88
REF 0087cf48 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info_byurl@0087cde8
REF 0087cfe8 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info_byurl@0087cde8
REF 0087d030 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info_byurl@0087cde8
REF 0087d078 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info_byurl@0087cde8
REF 0087d114 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info_byurl@0087cde8
REF 0087d13c UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info_byurl@0087cde8
REF 0087d160 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info_byurl@0087cde8
REF 0087d1a0 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info_byurl@0087cde8
REF 0087d268 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info_byurl@0087cde8
REF 0087d2c4 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info_byurl@0087cde8
REF 0087d2e0 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info_byurl@0087cde8
REF 0087d304 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info_byurl@0087cde8
REF 0087da10 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_url@0087d968
REF 0087da38 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_url@0087d968
REF 0087dac4 UNCONDITIONAL_CALL caller=imvt_cam_playback_stop@0087da48
REF 0087dbac UNCONDITIONAL_CALL caller=imvt_cam_playback_stop@0087da48
REF 0087dbd4 UNCONDITIONAL_CALL caller=imvt_cam_playback_stop@0087da48
REF 0087e0a0 UNCONDITIONAL_CALL caller=imvt_cam_playback_is_idle@0087e028
REF 0087e0c8 UNCONDITIONAL_CALL caller=imvt_cam_playback_is_idle@0087e028
REF 0087e148 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_status@0087e0d8
REF 0087e170 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_status@0087e0d8
REF 0087e480 UNCONDITIONAL_CALL caller=imvt_cam_playback_reset_last_frame@0087e420
REF 0087e4b0 UNCONDITIONAL_CALL caller=imvt_cam_playback_reset_last_frame@0087e420
REF 0087eabc UNCONDITIONAL_CALL caller=imvt_cam_playback_init_playback_mode@0087e958
REF 0087ead4 UNCONDITIONAL_CALL caller=imvt_cam_playback_init_playback_mode@0087e958
REF 0087eafc UNCONDITIONAL_CALL caller=imvt_cam_playback_init_playback_mode@0087e958
REF 0087eb24 UNCONDITIONAL_CALL caller=imvt_cam_playback_init_playback_mode@0087e958
REF 0087ec44 UNCONDITIONAL_CALL caller=imvt_cam_playback_deinit_playback_mode@0087eb58
REF 00881c48 UNCONDITIONAL_CALL caller=imvt_cam_photo_init@00881a88
REF 00881c8c UNCONDITIONAL_CALL caller=imvt_cam_photo_init@00881a88
REF 00881cbc UNCONDITIONAL_CALL caller=imvt_cam_photo_init@00881a88
REF 00881cd0 UNCONDITIONAL_CALL caller=imvt_cam_photo_init@00881a88
REF 008830a0 UNCONDITIONAL_CALL caller=imvt_raw_capture_init@00882f60
REF 008830b8 UNCONDITIONAL_CALL caller=imvt_raw_capture_init@00882f60
REF 008832f8 UNCONDITIONAL_CALL caller=imvt_raw_capture_set_raw_stacking@008832c0
REF 00883358 UNCONDITIONAL_CALL caller=imvt_raw_capture_set_raw_stacking@008832c0
REF 0088336c UNCONDITIONAL_CALL caller=imvt_raw_capture_set_raw_stacking@008832c0
REF 0088373c UNCONDITIONAL_CALL caller=imvt_cam_region_osd_roi_init@00883700
REF 0088375c UNCONDITIONAL_CALL caller=imvt_cam_region_osd_roi_init@00883700
REF 008843dc UNCONDITIONAL_CALL caller=imvt_cam_iq_set_contrast@008843a0
REF 00884454 UNCONDITIONAL_CALL caller=imvt_cam_iq_set_hue@00884418
REF 008844cc UNCONDITIONAL_CALL caller=imvt_cam_iq_set_luma@00884490
REF 00884544 UNCONDITIONAL_CALL caller=imvt_cam_iq_set_saturation@00884508
REF 008845ac UNCONDITIONAL_CALL caller=imvt_cam_iq_set_csc_type@00884578
REF 00884614 UNCONDITIONAL_CALL caller=imvt_cam_iq_set_tv_mode@008845e0
REF 00884694 UNCONDITIONAL_CALL caller=imvt_cam_iq_set_sharpen_level@00884628
REF 00884260 UNCONDITIONAL_CALL caller=FUN_0088423c@0088423c
REF 00884888 UNCONDITIONAL_CALL caller=FUN_00884864@00884864
REF 0088493c UNCONDITIONAL_CALL caller=imvt_cam_iq_set_gamma_style@008848a8
REF 00884a04 UNCONDITIONAL_CALL caller=imvt_cam_iq_set_user_gamma@00884958
REF 00884b44 UNCONDITIONAL_CALL caller=imvt_cam_iq_set_clut_style@00884ab0
REF 00884d54 UNCONDITIONAL_CALL caller=imvt_cam_profile_reload_on_resolution@00884c90
REF 00884d7c UNCONDITIONAL_CALL caller=imvt_cam_profile_reload_on_resolution@00884c90
REF 00884d94 UNCONDITIONAL_CALL caller=imvt_cam_profile_reload_on_resolution@00884c90
REF 00884db8 UNCONDITIONAL_CALL caller=imvt_cam_profile_reload_on_resolution@00884c90
REF 00884fa0 UNCONDITIONAL_CALL caller=imvt_cam_profile_set_ootf@00884f58
REF 008850b4 UNCONDITIONAL_CALL caller=imvt_sys_init@00884fe0
REF 00885164 UNCONDITIONAL_CALL caller=imvt_sys_init@00884fe0
REF 00885180 UNCONDITIONAL_CALL caller=imvt_sys_init@00884fe0
REF 00885198 UNCONDITIONAL_CALL caller=imvt_sys_init@00884fe0
REF 008851b0 UNCONDITIONAL_CALL caller=imvt_sys_init@00884fe0
REF 008851c8 UNCONDITIONAL_CALL caller=imvt_sys_init@00884fe0
REF 008851e4 UNCONDITIONAL_CALL caller=imvt_sys_init@00884fe0
REF 00885204 UNCONDITIONAL_CALL caller=imvt_sys_init@00884fe0
REF 00885220 UNCONDITIONAL_CALL caller=imvt_sys_init@00884fe0
REF 0088584c UNCONDITIONAL_CALL caller=FUN_00885834@00885834
REF 00886a68 UNCONDITIONAL_CALL caller=imvt_isp_af_set_attr@008869e8
REF 00886ad8 UNCONDITIONAL_CALL caller=imvt_isp_af_set_attr@008869e8
REF 00886d04 UNCONDITIONAL_CALL caller=imvt_isp_af_init@00886be8
REF 00887364 UNCONDITIONAL_CALL caller=imvt_isp_callback_register_init@008872f8
REF 008873f4 UNCONDITIONAL_CALL caller=imvt_cam_adj_pause_adj@008873d8
REF 00887830 UNCONDITIONAL_CALL caller=FUN_00887708@00887708
REF 0088808c UNCONDITIONAL_CALL caller=FUN_00888030@00888030
REF 00888ef4 UNCONDITIONAL_CALL caller=FUN_00888edc@00888edc
REF 00889324 UNCONDITIONAL_CALL caller=FUN_0088930c@0088930c
REF 0088948c UNCONDITIONAL_CALL caller=imvt_n3a_af_init@008893c8
REF 0088cd18 UNCONDITIONAL_CALL caller=imvt_n3a_ae_set_extended_iso@0088ccc8
REF 0088d004 UNCONDITIONAL_CALL caller=imvt_n3a_ae_init@0088cf18
REF 00890208 UNCONDITIONAL_CALL caller=n3a_network_camera_init@00890148
REF 008902fc UNCONDITIONAL_CALL caller=n3a_network_camera_init@00890148
REF 0089033c UNCONDITIONAL_CALL caller=n3a_network_camera_init@00890148
REF 008903a0 UNCONDITIONAL_CALL caller=n3a_network_camera_init@00890148
REF 008903b8 UNCONDITIONAL_CALL caller=n3a_network_camera_init@00890148
REF 00890488 UNCONDITIONAL_CALL caller=n3a_network_camera_stop@00890468
REF 0088f3f0 UNCONDITIONAL_CALL caller=FUN_0088f1e8@0088f1e8
REF 0088f5e4 UNCONDITIONAL_CALL caller=FUN_0088f1e8@0088f1e8
REF 0088f60c UNCONDITIONAL_CALL caller=FUN_0088f1e8@0088f1e8
REF 0088f620 UNCONDITIONAL_CALL caller=FUN_0088f1e8@0088f1e8
REF 0088f63c UNCONDITIONAL_CALL caller=FUN_0088f1e8@0088f1e8
REF 008905b0 UNCONDITIONAL_CALL caller=n3a_network_camera_deinit@00890550
REF 00890404 UNCONDITIONAL_CALL caller=n3a_network_camera_start@008903c8
REF 0089041c UNCONDITIONAL_CALL caller=n3a_network_camera_start@008903c8
REF 00890810 UNCONDITIONAL_CALL caller=n3a_network_camera_cmd_task_wait_time@008907e0
REF 00890bf0 UNCONDITIONAL_CALL caller=imvt_n3a_mov_init@00890ad8
REF 00891618 UNCONDITIONAL_CALL caller=imvt_n3a_task_init@008915f8
REF 0089140c UNCONDITIONAL_CALL caller=FUN_008913d8@008913d8
REF 0089172c UNCONDITIONAL_CALL caller=imvt_n3a_task_start@00891710
REF 00891794 UNCONDITIONAL_CALL caller=imvt_n3a_task_stop@00891778
REF 00891a74 UNCONDITIONAL_CALL caller=imvt_aaa_cb_init@008919b0
REF 00891a9c UNCONDITIONAL_CALL caller=imvt_aaa_cb_init@008919b0
REF 00891ad4 UNCONDITIONAL_CALL caller=imvt_aaa_cb_init@008919b0
REF 00891afc UNCONDITIONAL_CALL caller=imvt_aaa_cb_init@008919b0
REF 00891b24 UNCONDITIONAL_CALL caller=imvt_aaa_cb_init@008919b0
REF 00891b48 UNCONDITIONAL_CALL caller=imvt_aaa_cb_init@008919b0
REF 00891b68 UNCONDITIONAL_CALL caller=imvt_aaa_cb_init@008919b0
REF 00891b88 UNCONDITIONAL_CALL caller=imvt_aaa_cb_init@008919b0
REF 00891bac UNCONDITIONAL_CALL caller=imvt_aaa_cb_init@008919b0
REF 008a0234 UNCONDITIONAL_CALL caller=imvt_pipeline_dispatcher_soc_get_adp@008a0210
REF 008a0254 UNCONDITIONAL_CALL caller=imvt_pipeline_dispatcher_soc_get_adp@008a0210
REF 008a29b4 UNCONDITIONAL_CALL caller=imvt_vi_yuv_dispatcher_soc_init@008a2998
REF 008a267c UNCONDITIONAL_CALL caller=FUN_008a2510@008a2510
REF 008a2690 UNCONDITIONAL_CALL caller=FUN_008a2510@008a2510
REF 008a26b4 UNCONDITIONAL_CALL caller=FUN_008a2510@008a2510
REF 008af818 UNCONDITIONAL_CALL caller=imvt_hdmi_device_get_res_size_by_vic@008af7f8
REF 008afaa8 UNCONDITIONAL_CALL caller=imvt_hdmi_device_register_cable_insert_callback@008afa78
REF 008b9e10 UNCONDITIONAL_CALL caller=stop@008b9d68
REF 008d8284 UNCONDITIONAL_CALL caller=fmt_rtsp_server_start@008d81f0
REF 008d82bc UNCONDITIONAL_CALL caller=fmt_rtsp_server_start@008d81f0
REF 008d82f0 UNCONDITIONAL_CALL caller=fmt_rtsp_server_stop@008d82c8
REF 008d830c UNCONDITIONAL_CALL caller=fmt_rtsp_server_stop@008d82c8
REF 008d8450 UNCONDITIONAL_CALL caller=fmt_rtsp_server_callback@008d83d0
REF 00921964 UNCONDITIONAL_CALL caller=fmt_srt_set_passphrase@009218c0
REF 00921a10 UNCONDITIONAL_CALL caller=fmt_srt_set_pbkey_len@00921978
REF 00921a78 UNCONDITIONAL_CALL caller=fmt_srt_set_latency@00921a30
REF 00921ad8 UNCONDITIONAL_CALL caller=fmt_srt_set_ttl@00921a90
REF 009231c8 UNCONDITIONAL_CALL caller=start@009230a8
REF 00923220 UNCONDITIONAL_CALL caller=start@009230a8
REF 00923258 UNCONDITIONAL_CALL caller=start@009230a8
REF 00923354 UNCONDITIONAL_CALL caller=stop@009232c0
REF 009233c8 UNCONDITIONAL_CALL caller=pause@00923398
REF 00923440 UNCONDITIONAL_CALL caller=resume@00923410
REF 009b38d4 UNCONDITIONAL_CALL caller=fmt_rtmp_create@009b3860
REF 009b3928 UNCONDITIONAL_CALL caller=fmt_rtmp_create@009b3860
REF 009b3b04 UNCONDITIONAL_CALL caller=fmt_rtmp_disable_push@009b3ad8
REF 009d8748 UNCONDITIONAL_CALL caller=ndi_server_start@009d8520
REF 009d8804 UNCONDITIONAL_CALL caller=ndi_server_start@009d8520
REF 009d8824 UNCONDITIONAL_CALL caller=ndi_server_start@009d8520
REF 009d8838 UNCONDITIONAL_CALL caller=ndi_server_start@009d8520
REF 009d885c UNCONDITIONAL_CALL caller=ndi_server_start@009d8520
REF 009d8888 UNCONDITIONAL_CALL caller=ndi_server_start@009d8520
REF 009d88c0 UNCONDITIONAL_CALL caller=ndi_server_start@009d8520
REF 009d88e4 UNCONDITIONAL_CALL caller=ndi_server_start@009d8520
REF 009d8930 UNCONDITIONAL_CALL caller=ndi_server_stop@009d88f8
REF 009d8964 UNCONDITIONAL_CALL caller=ndi_server_stop@009d88f8
REF 009d7590 UNCONDITIONAL_CALL caller=FUN_009d7518@009d7518
REF 009d762c UNCONDITIONAL_CALL caller=FUN_009d7518@009d7518
REF 009d8b20 UNCONDITIONAL_CALL caller=ndi_server_register_callback@009d8a80
REF 009d8df8 UNCONDITIONAL_CALL caller=ndi_server_set_capabilities@009d8d70
REF 009d8e14 UNCONDITIONAL_CALL caller=ndi_server_set_capabilities@009d8d70
REF 009d90ec UNCONDITIONAL_CALL caller=ndi_server_set_ndi_param@009d8e20
REF 009d7114 UNCONDITIONAL_CALL caller=FUN_009d6fa0@009d6fa0
REF 009e1df4 UNCONDITIONAL_CALL caller=fetch_streamer_create@009e1c70
REF 009e1e2c UNCONDITIONAL_CALL caller=fetch_streamer_create@009e1c70
REF 009e1e54 UNCONDITIONAL_CALL caller=fetch_streamer_create@009e1c70
REF 009e1e7c UNCONDITIONAL_CALL caller=fetch_streamer_create@009e1c70
REF 009e1ea4 UNCONDITIONAL_CALL caller=fetch_streamer_create@009e1c70
REF 009e1edc UNCONDITIONAL_CALL caller=fetch_streamer_create@009e1c70
REF 009e1fac UNCONDITIONAL_CALL caller=fetch_streamer_destroy@009e1ef8
REF 009e6584 UNCONDITIONAL_CALL caller=fmt_push_muxer_enable_push@009e64c0
REF 009e5738 UNCONDITIONAL_CALL caller=FUN_009e5668@009e5668
REF 009e5780 UNCONDITIONAL_CALL caller=FUN_009e5668@009e5668
REF 009e5974 UNCONDITIONAL_CALL caller=FUN_009e595c@009e595c
REF 009eaf7c UNCONDITIONAL_CALL caller=frame_fifo_create@009eaf10
REF 009eafac UNCONDITIONAL_CALL caller=frame_fifo_create@009eaf10
REF 009eb0e4 UNCONDITIONAL_CALL caller=frame_fifo_create@009eaf10
REF 009eb0f8 UNCONDITIONAL_CALL caller=frame_fifo_create@009eaf10
REF 009eb238 UNCONDITIONAL_CALL caller=frame_fifo_set_multhread_cpy@009eb120
REF 009eb26c UNCONDITIONAL_CALL caller=frame_fifo_set_multhread_cpy@009eb120
REF 00a17198 UNCONDITIONAL_CALL caller=fmt_demuxer_create_heif@00a17110
REF 00a38f90 UNCONDITIONAL_CALL caller=imvt_log_init@00a38e20
REF 00a38da0 UNCONDITIONAL_CALL caller=FUN_00a38c78@00a38c78
REF 00a39130 UNCONDITIONAL_CALL caller=imvt_log_deinit@00a390e0
REF 00a394f4 UNCONDITIONAL_CALL caller=imvt_log_set_log_target@00a39458
REF 00a3d7c8 UNCONDITIONAL_CALL caller=imvt_get_storage_filesystem_format@00a3d6a0
REF 00a3d654 UNCONDITIONAL_CALL caller=FUN_00a3d5e8@00a3d5e8
REF 00a3d684 UNCONDITIONAL_CALL caller=FUN_00a3d5e8@00a3d5e8
REF 00a3da4c UNCONDITIONAL_CALL caller=FUN_00a3da34@00a3da34
REF 00a3c644 UNCONDITIONAL_CALL caller=FUN_00a3c518@00a3c518
REF 00a3c6e4 UNCONDITIONAL_CALL caller=FUN_00a3c518@00a3c518
REF 00a3c714 UNCONDITIONAL_CALL caller=FUN_00a3c518@00a3c518
REF 00a3c73c UNCONDITIONAL_CALL caller=FUN_00a3c518@00a3c518
REF 00a3c754 UNCONDITIONAL_CALL caller=FUN_00a3c518@00a3c518
REF 00a3c77c UNCONDITIONAL_CALL caller=FUN_00a3c518@00a3c518
REF 00a3e774 UNCONDITIONAL_CALL caller=imvt_storage_mount_nfs_as_storage@00a3e720
REF 00a3e808 UNCONDITIONAL_CALL caller=imvt_storage_mount_nfs_as_storage@00a3e720
REF 00a3e818 UNCONDITIONAL_CALL caller=imvt_storage_mount_nfs_as_storage@00a3e720
REF 00a3e840 UNCONDITIONAL_CALL caller=imvt_storage_mount_nfs_as_storage@00a3e720
REF 00a3e858 UNCONDITIONAL_CALL caller=imvt_storage_mount_nfs_as_storage@00a3e720
REF 00a3e884 UNCONDITIONAL_CALL caller=imvt_storage_mount_nfs_as_storage@00a3e720
REF 00a3e898 UNCONDITIONAL_CALL caller=imvt_storage_mount_nfs_as_storage@00a3e720
REF 00a3cf2c UNCONDITIONAL_CALL caller=FUN_00a3cdc8@00a3cdc8
REF 00a3e714 UNCONDITIONAL_CALL caller=imvt_storage_unmount_nfs_as_storage@00a3e6c8
REF 00a3ef3c UNCONDITIONAL_CALL caller=imvt_storage_umount@00a3ee40
REF 00a406ec UNCONDITIONAL_CALL caller=FUN_00a405e8@00a405e8
REF 00a40514 UNCONDITIONAL_CALL caller=FUN_00a404a8@00a404a8
REF 00a4056c UNCONDITIONAL_CALL caller=FUN_00a404a8@00a404a8
REF 00a4057c UNCONDITIONAL_CALL caller=FUN_00a404a8@00a404a8
REF 00a421e0 UNCONDITIONAL_CALL caller=imvt_usb_device_set_role@00a41eb0
REF 00a4222c UNCONDITIONAL_CALL caller=imvt_usb_device_set_role@00a41eb0
REF 00a42284 UNCONDITIONAL_CALL caller=imvt_usb_device_set_role@00a41eb0
REF 00a4230c UNCONDITIONAL_CALL caller=imvt_usb_device_set_role@00a41eb0
REF 00a42338 UNCONDITIONAL_CALL caller=imvt_usb_device_set_role@00a41eb0
REF 00a42360 UNCONDITIONAL_CALL caller=imvt_usb_device_set_role@00a41eb0
REF 00a42378 UNCONDITIONAL_CALL caller=imvt_usb_device_set_role@00a41eb0
REF 00a42390 UNCONDITIONAL_CALL caller=imvt_usb_device_set_role@00a41eb0
REF 00a423c0 UNCONDITIONAL_CALL caller=imvt_usb_device_set_role@00a41eb0
REF 00a423ec UNCONDITIONAL_CALL caller=imvt_usb_device_set_role@00a41eb0
REF 00a42420 UNCONDITIONAL_CALL caller=imvt_usb_device_set_role@00a41eb0
REF 00a3ea40 UNCONDITIONAL_CALL caller=imvt_storage_mount@00a3e8c8
REF 00a3ea80 UNCONDITIONAL_CALL caller=imvt_storage_mount@00a3e8c8
REF 00a3eaec UNCONDITIONAL_CALL caller=imvt_storage_mount@00a3e8c8
REF 00a3eb50 UNCONDITIONAL_CALL caller=imvt_storage_mount@00a3e8c8
REF 00a3eb78 UNCONDITIONAL_CALL caller=imvt_storage_mount@00a3e8c8
REF 00a3ebcc UNCONDITIONAL_CALL caller=imvt_storage_mount@00a3e8c8
REF 00a3d120 UNCONDITIONAL_CALL caller=FUN_00a3d030@00a3d030
REF 00a3d13c UNCONDITIONAL_CALL caller=FUN_00a3d030@00a3d030
REF 00a3d160 UNCONDITIONAL_CALL caller=FUN_00a3d030@00a3d030
REF 00a41d8c UNCONDITIONAL_CALL caller=FUN_00a41c90@00a41c90
REF 00a425e8 UNCONDITIONAL_CALL caller=imvt_usb_manger_register_callback@00a42528
REF 00a426e4 UNCONDITIONAL_CALL caller=imvt_usb_manager_init@00a42620
REF 00a42714 UNCONDITIONAL_CALL caller=imvt_usb_manager_init@00a42620
REF 00a42ab8 UNCONDITIONAL_CALL caller=FUN_00a42a28@00a42a28
REF 00a42acc UNCONDITIONAL_CALL caller=FUN_00a42a28@00a42a28
REF 00a43ec4 UNCONDITIONAL_CALL caller=imvt_update_remove_emmc_fw@00a43e00
REF 00a43cb8 UNCONDITIONAL_CALL caller=FUN_00a43c10@00a43c10
REF 00a43cd4 UNCONDITIONAL_CALL caller=FUN_00a43c10@00a43c10
REF 00a43df0 UNCONDITIONAL_CALL caller=imvt_update_scan_dir_get_fw_path@00a43ce8
REF 00a42d6c UNCONDITIONAL_CALL caller=FUN_00a42ad8@00a42ad8
REF 00a42d84 UNCONDITIONAL_CALL caller=FUN_00a42ad8@00a42ad8
REF 00a449e0 UNCONDITIONAL_CALL caller=imvt_wifi_get_mode@00a448f0
REF 00a45044 UNCONDITIONAL_CALL caller=imvt_adc_read_data@00a44ff8
REF 00a450c0 UNCONDITIONAL_CALL caller=imvt_adc_read_data@00a44ff8
REF 00a44fe4 UNCONDITIONAL_CALL caller=imvt_adc_stop_convent@00a44f50
REF 00a44cd4 UNCONDITIONAL_CALL caller=FUN_00a44c78@00a44c78
REF 00a44df8 UNCONDITIONAL_CALL caller=imvt_adc_disable_chn@00a44d90
REF 00a44e1c UNCONDITIONAL_CALL caller=imvt_adc_disable_chn@00a44d90
REF 00a454bc UNCONDITIONAL_CALL caller=imvt_kernel_rmmod@00a45468
REF 00a45614 UNCONDITIONAL_CALL caller=imvt_kernel_insmod@00a454d8
REF 00a45650 UNCONDITIONAL_CALL caller=imvt_kernel_insmod@00a454d8
REF 00a456a4 UNCONDITIONAL_CALL caller=imvt_kernel_insmod@00a454d8
REF 00a456f0 UNCONDITIONAL_CALL caller=imvt_kernel_insmod@00a454d8
REF 00a4574c UNCONDITIONAL_CALL caller=imvt_kernel_insmod@00a454d8
REF 00a45770 UNCONDITIONAL_CALL caller=imvt_kernel_insmod@00a454d8
REF 00a48030 UNCONDITIONAL_CALL caller=imvt_sys_service_client_execute_system_cmd@00a47ea0
REF 00a48074 UNCONDITIONAL_CALL caller=imvt_sys_service_client_execute_system_cmd@00a47ea0
REF 00a480b4 UNCONDITIONAL_CALL caller=imvt_sys_service_client_execute_system_cmd@00a47ea0
REF 00a480e4 UNCONDITIONAL_CALL caller=imvt_sys_service_client_execute_system_cmd@00a47ea0
REF 00a480fc UNCONDITIONAL_CALL caller=imvt_sys_service_client_execute_system_cmd@00a47ea0
REF 00a48264 UNCONDITIONAL_CALL caller=imvt_sys_service_client_init@00a481c0
REF 00a49660 UNCONDITIONAL_CALL caller=imvt_i2c_gpio_bus_unregister@00a495e0
REF 00a49680 UNCONDITIONAL_CALL caller=imvt_i2c_gpio_bus_unregister@00a495e0
REF 00a4f110 UNCONDITIONAL_CALL caller=imvt_sys_read_sn@00a4f030
REF 00a50d60 UNCONDITIONAL_CALL caller=imvt_rs485_master_control_init@00a50d28
REF 00a50df4 UNCONDITIONAL_CALL caller=imvt_rs485_master_control_init@00a50d28
REF 00a50e1c UNCONDITIONAL_CALL caller=imvt_rs485_master_control_init@00a50d28
REF 00a51458 UNCONDITIONAL_CALL caller=imvt_rs485_slave_control_init@00a513e0
REF 00a51624 UNCONDITIONAL_CALL caller=imvt_rs485_slave_control_init@00a513e0
REF 00a5164c UNCONDITIONAL_CALL caller=imvt_rs485_slave_control_init@00a513e0
REF 00a5167c UNCONDITIONAL_CALL caller=imvt_rs485_slave_control_init@00a513e0
REF 00a51cc8 UNCONDITIONAL_CALL caller=imvt_imu_init@00a51c40
REF 00a51d64 UNCONDITIONAL_CALL caller=imvt_imu_exit@00a51d18
REF 00a52a54 UNCONDITIONAL_CALL caller=imvt_otp_encryption_verify_is_ok@00a529a8
REF 00a52b80 UNCONDITIONAL_CALL caller=imvt_otp_encryption_verify_is_ok@00a529a8
REF 00a52bc4 UNCONDITIONAL_CALL caller=imvt_otp_encryption_verify_is_ok@00a529a8
REF 00a531a4 UNCONDITIONAL_CALL caller=open_tty@00a530a8
REF 00a538a0 UNCONDITIONAL_CALL caller=uart_write_package_iov_data@00a53690
REF 00a53954 UNCONDITIONAL_CALL caller=uart_write_package_iov_data@00a53690
REF 00a53978 UNCONDITIONAL_CALL caller=uart_write_package_iov_data@00a53690
REF 00a59b24 UNCONDITIONAL_CALL caller=imvt_cam_get_brief_vi_params@00a59ac8
REF 00a59b7c UNCONDITIONAL_CALL caller=imvt_cam_get_brief_vi_params@00a59ac8
REF 00a59b8c UNCONDITIONAL_CALL caller=imvt_cam_get_brief_vi_params@00a59ac8
REF 006fbbcc UNCONDITIONAL_CALL caller=imvt_cam_lvds_crop_position_get_by_sensor_mode@006fba18
REF 00a59900 UNCONDITIONAL_CALL caller=FUN_00a594e0@00a594e0
REF 00a59d20 UNCONDITIONAL_CALL caller=imvt_cam_get_basic_vi_info@00a59c60
REF 00a59d30 UNCONDITIONAL_CALL caller=imvt_cam_get_basic_vi_info@00a59c60
REF 00a59e28 UNCONDITIONAL_CALL caller=imvt_cam_get_raw_params@00a59db0
REF 00a5b5c8 UNCONDITIONAL_CALL caller=n3a_config_set_e_nd_attached@00a5b530
REF 00a5b624 UNCONDITIONAL_CALL caller=n3a_config_set_e_nd_attached@00a5b530
REF 00a64764 UNCONDITIONAL_CALL caller=n3a_drive_e_nd_set_nd_param@00a64728
REF 00a6479c UNCONDITIONAL_CALL caller=n3a_drive_e_nd_set_nd_param@00a64728
REF 00a64608 UNCONDITIONAL_CALL caller=n3a_drive_e_nd_init@00a64598
REF 00a6461c UNCONDITIONAL_CALL caller=n3a_drive_e_nd_init@00a64598
REF 00a65c08 UNCONDITIONAL_CALL caller=FUN_00a65b98@00a65b98
REF 00a65c98 UNCONDITIONAL_CALL caller=FUN_00a65b98@00a65b98
REF 00a65b5c UNCONDITIONAL_CALL caller=skip_crop_mode_nd_shading@00a65b20
REF 00a65b84 UNCONDITIONAL_CALL caller=skip_crop_mode_nd_shading@00a65b20
REF 00a66a4c UNCONDITIONAL_CALL caller=imvt_cam_adj_hookup_sensor@00a66a30
REF 00ab85e0 UNCONDITIONAL_CALL caller=FUN_00ab8528@00ab8528
REF 00ab8604 UNCONDITIONAL_CALL caller=FUN_00ab8528@00ab8528
REF 00ab8748 UNCONDITIONAL_CALL caller=imvt_adj_start@00ab86f0
REF 00ab8764 UNCONDITIONAL_CALL caller=imvt_adj_start@00ab86f0
REF 00ab8ab0 UNCONDITIONAL_CALL caller=imvt_adj_register_system_callback@00ab8a30
REF 00abb1a0 UNCONDITIONAL_CALL caller=imvt_raw_bpc_init@00abb130
REF 00abc3b8 UNCONDITIONAL_CALL caller=imvt_raw_bpc_detect_init@00abc378
REF 00abcfa8 UNCONDITIONAL_CALL caller=imvt_raw_stacker_init@00abcf68
REF 00abe2d0 UNCONDITIONAL_CALL caller=~ICAMServicePrivate@00abe2b0
REF 00ac0ccc UNCONDITIONAL_CALL caller=~ICamClient@00ac0ca8
REF 00b94858 UNCONDITIONAL_CALL caller=imvt_sensor_init_stage1@00b947f0
REF 00b9487c UNCONDITIONAL_CALL caller=imvt_sensor_init_stage1@00b947f0
REF 00b958c8 UNCONDITIONAL_CALL caller=sensor_get_sensor_mode_info@00b95890
REF 00b94ee8 UNCONDITIONAL_CALL caller=sensor_spi_write@00b94e28
REF 00b94e18 UNCONDITIONAL_CALL caller=sensor_spi_read@00b94d50
REF 00cfea18 UNCONDITIONAL_CALL caller=imvt_lens_controller_init@00cfe9c0
REF 00cfea74 UNCONDITIONAL_CALL caller=imvt_lens_controller_init@00cfe9c0
REF 00cfea94 UNCONDITIONAL_CALL caller=imvt_lens_controller_init@00cfe9c0
REF 00cfeb0c UNCONDITIONAL_CALL caller=imvt_lens_controller_exit@00cfeaa0
REF 00cfeb3c UNCONDITIONAL_CALL caller=imvt_lens_controller_exit@00cfeaa0
REF 00cfeb58 UNCONDITIONAL_CALL caller=imvt_lens_controller_exit@00cfeaa0
REF 00cff3b0 UNCONDITIONAL_CALL caller=ef_lens_device_create@00cff198
REF 00d029e8 UNCONDITIONAL_CALL caller=dummy_lens_device_create@00d02848
REF 00d03204 UNCONDITIONAL_CALL caller=mfts_lens_device_create@00d02fe8
REF 00d10a2c UNCONDITIONAL_CALL caller=lcd_device_create@00d10978
REF 00d10b04 UNCONDITIONAL_CALL caller=imvt_temperature_read@00d10a70
REF 00d10b2c UNCONDITIONAL_CALL caller=imvt_temperature_read@00d10a70
REF 00d10ca0 UNCONDITIONAL_CALL caller=imvt_temperature_read@00d10a70
REF 00d10d40 UNCONDITIONAL_CALL caller=imvt_temperature_init@00d10cc8
REF 00d11424 UNCONDITIONAL_CALL caller=dm2016_verify@00d11208
REF 00d1144c UNCONDITIONAL_CALL caller=dm2016_verify@00d11208
REF 00d11464 UNCONDITIONAL_CALL caller=dm2016_verify@00d11208
REF 00d11478 UNCONDITIONAL_CALL caller=dm2016_verify@00d11208
REF 00d1149c UNCONDITIONAL_CALL caller=dm2016_verify@00d11208
REF 00d114c4 UNCONDITIONAL_CALL caller=dm2016_verify@00d11208
REF 00d114f0 UNCONDITIONAL_CALL caller=dm2016_verify@00d11208
REF 00d1150c UNCONDITIONAL_CALL caller=dm2016_verify@00d11208
REF 00d11520 UNCONDITIONAL_CALL caller=dm2016_verify@00d11208
REF 00d1d22c UNCONDITIONAL_CALL caller=imvt_rtc_get_time@00d1d118
REF 00d1e1ac UNCONDITIONAL_CALL caller=imvt_eND_power_control@00d1e0d0
REF 00d1e244 UNCONDITIONAL_CALL caller=imvt_eND_power_control@00d1e0d0
REF 00d1e61c UNCONDITIONAL_CALL caller=imvt_i2c_to_spi_write@00d1e530
REF 00d1e638 UNCONDITIONAL_CALL caller=imvt_i2c_to_spi_write@00d1e530
REF 00d1e654 UNCONDITIONAL_CALL caller=imvt_i2c_to_spi_write@00d1e530
REF 00d1e72c UNCONDITIONAL_CALL caller=imvt_i2c_to_spi_read@00d1e660
REF 00d1e778 UNCONDITIONAL_CALL caller=imvt_i2c_to_spi_read@00d1e660
REF 00d1e7a0 UNCONDITIONAL_CALL caller=imvt_i2c_to_spi_read@00d1e660
REF 00d1e7bc UNCONDITIONAL_CALL caller=imvt_i2c_to_spi_read@00d1e660
REF 00d1e9f8 UNCONDITIONAL_CALL caller=imvt_hdmi_recv_register_insert_callback@00d1e9c0
REF 00d1f518 UNCONDITIONAL_CALL caller=imvt_hdmi_recv_controller_init@00d1f4c0
REF 00d1f59c UNCONDITIONAL_CALL caller=imvt_hdmi_recv_controller_exit@00d1f550
REF 00d1f5cc UNCONDITIONAL_CALL caller=imvt_hdmi_recv_controller_exit@00d1f550
REF 00d21080 UNCONDITIONAL_CALL caller=hdmi_recv_dummy_device_create@00d21000
REF 00d22418 UNCONDITIONAL_CALL caller=imvt_sdi_recv_register_insert_callback@00d223e0
REF 00d22474 UNCONDITIONAL_CALL caller=imvt_sdi_recv_controller_init@00d22438
REF 00d224fc UNCONDITIONAL_CALL caller=imvt_sdi_recv_controller_exit@00d224b0
REF 00d2252c UNCONDITIONAL_CALL caller=imvt_sdi_recv_controller_exit@00d224b0
REF 00d23504 UNCONDITIONAL_CALL caller=sdi_recv_dummy_device_create@00d234a0
REF 006c7064 UNCONDITIONAL_CALL caller=doUpgradeFw@006c6fc0
REF 006c7084 UNCONDITIONAL_CALL caller=doUpgradeFw@006c6fc0
REF 006c6e14 UNCONDITIONAL_CALL caller=reboot@006c6de8
REF 00a43504 UNCONDITIONAL_CALL caller=imvt_updater_read_file_string@00a43480
REF 00a435a0 UNCONDITIONAL_CALL caller=imvt_updater_read_file_string@00a43480
REF 00a435bc UNCONDITIONAL_CALL caller=imvt_updater_read_file_string@00a43480
REF 00a435e0 UNCONDITIONAL_CALL caller=imvt_updater_read_file_string@00a43480
REF 00a435f4 UNCONDITIONAL_CALL caller=imvt_updater_read_file_string@00a43480
REF 00a4360c UNCONDITIONAL_CALL caller=imvt_updater_read_file_string@00a43480
REF 00a43808 UNCONDITIONAL_CALL caller=imvt_updater_set_recovery_flag@00a437a8
REF 00a43238 UNCONDITIONAL_CALL caller=FUN_00a431b8@00a431b8
REF 00a4324c UNCONDITIONAL_CALL caller=FUN_00a431b8@00a431b8
REF 00a43ac0 UNCONDITIONAL_CALL caller=imvt_updater_check_fw_validity@00a43a40
REF 00a43af4 UNCONDITIONAL_CALL caller=imvt_updater_check_fw_validity@00a43a40
REF 00a4308c UNCONDITIONAL_CALL caller=FUN_00a42f80@00a42f80
REF 00a431ac UNCONDITIONAL_CALL caller=FUN_00a42f80@00a42f80
REF 00a44014 UNCONDITIONAL_CALL caller=imvt_update_copy_updatefile_to_emmc@00a43ed0
REF 00a440a8 UNCONDITIONAL_CALL caller=imvt_update_copy_updatefile_to_emmc@00a43ed0
REF 00a440dc UNCONDITIONAL_CALL caller=imvt_update_copy_updatefile_to_emmc@00a43ed0
REF 00a44198 UNCONDITIONAL_CALL caller=imvt_update_copy_updatefile_to_emmc@00a43ed0
REF 00a441ac UNCONDITIONAL_CALL caller=imvt_update_copy_updatefile_to_emmc@00a43ed0
REF 00a441c8 UNCONDITIONAL_CALL caller=imvt_update_copy_updatefile_to_emmc@00a43ed0
REF 00a441e0 UNCONDITIONAL_CALL caller=imvt_update_copy_updatefile_to_emmc@00a43ed0
REF 00a441fc UNCONDITIONAL_CALL caller=imvt_update_copy_updatefile_to_emmc@00a43ed0
REF 00a44218 UNCONDITIONAL_CALL caller=imvt_update_copy_updatefile_to_emmc@00a43ed0
REF 00a4434c UNCONDITIONAL_CALL caller=imvt_do_updater@00a44228
REF 00a44398 UNCONDITIONAL_CALL caller=imvt_do_updater@00a44228
REF 00a443d4 UNCONDITIONAL_CALL caller=imvt_do_updater@00a44228
REF 00a44400 UNCONDITIONAL_CALL caller=imvt_do_updater@00a44228
REF 00a444bc UNCONDITIONAL_CALL caller=imvt_do_updater@00a44228
REF 00a444e0 UNCONDITIONAL_CALL caller=imvt_do_updater@00a44228
REF 00a429a4 UNCONDITIONAL_CALL caller=FUN_00a42780@00a42780
REF 00a429fc UNCONDITIONAL_CALL caller=FUN_00a42780@00a42780
REF 00a42a18 UNCONDITIONAL_CALL caller=FUN_00a42780@00a42780
REF 006afdd0 UNCONDITIONAL_CALL caller=resetFileContent@006afc10
REF 006afde0 UNCONDITIONAL_CALL caller=resetFileContent@006afc10
REF 006dd864 UNCONDITIONAL_CALL caller=writeMd5ToFile@006dd7e0
REF 006df148 UNCONDITIONAL_CALL caller=encryptFile@006def68
REF 006df174 UNCONDITIONAL_CALL caller=encryptFile@006def68
REF 006dece0 UNCONDITIONAL_CALL caller=intToBinary@006deb80
REF 0061c9f4 UNCONDITIONAL_CALL caller=loadCertificate@0061c8c0
REF 006dfaec UNCONDITIONAL_CALL caller=copyProfile@006df690
REF 006dfb10 UNCONDITIONAL_CALL caller=copyProfile@006df690
REF 006dff04 UNCONDITIONAL_CALL caller=mergeFiles@006dfc78
REF 00738c50 UNCONDITIONAL_CALL caller=pemTempCertificateIsValid@00738bf8
REF 008028a4 UNCONDITIONAL_CALL caller=setMatrixDefaultValue@00802850
REF 007a4734 UNCONDITIONAL_CALL caller=saveConfig@007a4630
REF 00674340 UNCONDITIONAL_CALL caller=getList@00673d08
REF 0067be88 UNCONDITIONAL_CALL caller=getList@0067b568
REF 00695570 UNCONDITIONAL_CALL caller=updateCustomizedImageFile@00695468
REF 0062fbcc UNCONDITIONAL_CALL caller=detectCorruptedFiles@0062eef0
REF 0062fc10 UNCONDITIONAL_CALL caller=detectCorruptedFiles@0062eef0
REF 00a075ac UNCONDITIONAL_CALL caller=mov_recovery_file@00a07558
REF 00a0767c UNCONDITIONAL_CALL caller=mov_recovery_file@00a07558
REF 00a078d4 UNCONDITIONAL_CALL caller=mov_recovery_file@00a07558
REF 00a07af8 UNCONDITIONAL_CALL caller=mov_recovery_file@00a07558
REF 00a07b3c UNCONDITIONAL_CALL caller=mov_recovery_file@00a07558
REF 00a07b70 UNCONDITIONAL_CALL caller=mov_recovery_file@00a07558
REF 00a07b88 UNCONDITIONAL_CALL caller=mov_recovery_file@00a07558
REF 00a07bbc UNCONDITIONAL_CALL caller=mov_recovery_file@00a07558
REF 00a07bf8 UNCONDITIONAL_CALL caller=mov_recovery_file@00a07558
REF 00a07c48 UNCONDITIONAL_CALL caller=mov_recovery_file@00a07558
REF 00a07c80 UNCONDITIONAL_CALL caller=mov_recovery_file@00a07558
REF 009ffa5c UNCONDITIONAL_CALL caller=FUN_009ff9a0@009ff9a0
REF 009ffe78 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 009fff70 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 009fffdc UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00108 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00128 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a001d0 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00268 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00388 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a003a8 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00408 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a0041c UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a006bc UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a006e0 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a0097c UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00990 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a009a4 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a009c0 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a009f0 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00a24 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00a60 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00a88 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00a9c UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00abc UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00ae8 UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00afc UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00b5c UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 00a00b6c UNCONDITIONAL_CALL caller=FUN_009ffd38@009ffd38
REF 009ffc2c UNCONDITIONAL_CALL caller=FUN_009ffaf0@009ffaf0
REF 009ffbbc UNCONDITIONAL_CALL caller=FUN_009ffaf0@009ffaf0
REF 009ffc98 UNCONDITIONAL_CALL caller=FUN_009ffaf0@009ffaf0
REF 009ffce4 UNCONDITIONAL_CALL caller=FUN_009ffaf0@009ffaf0
REF 009ffcfc UNCONDITIONAL_CALL caller=FUN_009ffaf0@009ffaf0
REF 009ffd14 UNCONDITIONAL_CALL caller=FUN_009ffaf0@009ffaf0
REF 009ffd2c UNCONDITIONAL_CALL caller=FUN_009ffaf0@009ffaf0
REF 00a00cc0 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a00db8 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a00fdc UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a00f74 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a00ff4 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a0101c UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01180 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a011a0 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01248 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a0136c UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01408 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01428 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01488 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a0149c UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01764 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01a0c UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01a24 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01a68 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01a7c UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01a90 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01aa4 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01acc UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01ae0 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01b00 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01b14 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01b30 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01b50 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01b84 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01bd4 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01bf4 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01c20 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01c38 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01c50 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01c60 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01c80 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01ca4 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01cbc UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01d18 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01d28 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01d54 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01d68 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01d88 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01d9c UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01dbc UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a01dd0 UNCONDITIONAL_CALL caller=FUN_00a00b78@00a00b78
REF 00a04cd8 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a04d58 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a062fc UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a0637c UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a05cc4 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a05bec UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a05d04 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a06f58 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a06fcc UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a07478 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a07498 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a06630 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a069dc UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a070b8 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a070fc UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a071f8 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a07248 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a07330 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a07368 UNCONDITIONAL_CALL caller=FUN_00a049e8@00a049e8
REF 00a02164 UNCONDITIONAL_CALL caller=FUN_00a02000@00a02000
REF 00a0bca0 UNCONDITIONAL_CALL caller=buf_mov_wb32@00a0bc10
REF 00a03f98 UNCONDITIONAL_CALL caller=FUN_00a03d80@00a03d80
REF 00a0bac0 UNCONDITIONAL_CALL caller=buf_mov_wb8@00a0ba48
REF 00a0bb58 UNCONDITIONAL_CALL caller=buf_mov_wb16@00a0bad8
REF 00a0bbf8 UNCONDITIONAL_CALL caller=buf_mov_wb24@00a0bb70
REF 00a0bd68 UNCONDITIONAL_CALL caller=buf_mov_wb64@00a0bcb8
REF 00a0bf20 UNCONDITIONAL_CALL caller=buf_mov_rb32@00a0bea8
REF 00a0bfa8 UNCONDITIONAL_CALL caller=FUN_00a0bf84@00a0bf84
REF 00a0c020 UNCONDITIONAL_CALL caller=FUN_00a0bffc@00a0bffc
REF 00a0c098 UNCONDITIONAL_CALL caller=buf_mov_write@00a0c048
REF 00a0c148 UNCONDITIONAL_CALL caller=buf_mov_read@00a0c0f8
REF 006dd8dc UNCONDITIONAL_CALL caller=readMd5FromFile@006dd870
REF 006ddaf8 UNCONDITIONAL_CALL caller=readMd5FromFile@006dd870
REF 006df604 UNCONDITIONAL_CALL caller=decryptFile@006df2c0
REF 006df624 UNCONDITIONAL_CALL caller=decryptFile@006df2c0
REF 006e5df4 UNCONDITIONAL_CALL caller=importFrom@006e5930
REF 006e5e44 UNCONDITIONAL_CALL caller=importFrom@006e5930
REF 006e6068 UNCONDITIONAL_CALL caller=importAndDecryptProfile@006e5fa8
REF 00a49454 UNCONDITIONAL_CALL caller=imvt_sntp_client_start@00a49390
REF 00a49484 UNCONDITIONAL_CALL caller=imvt_sntp_client_start@00a49390
REF 00829d4c UNCONDITIONAL_CALL caller=setTimeCodeValue@00829c90
REF 00666754 UNCONDITIONAL_CALL caller=setPhotoInfo@00666148
REF 00663368 UNCONDITIONAL_CALL caller=updateUi@00662d18
REF 006636d8 UNCONDITIONAL_CALL caller=keyReleaseEvent@00663420
REF 00662e2c UNCONDITIONAL_CALL caller=updateUi@00662d18
REF 006631b8 UNCONDITIONAL_CALL caller=updateUi@00662d18
REF 0065a18c UNCONDITIONAL_CALL caller=getMediaInfo@0065a120
REF 006638ec UNCONDITIONAL_CALL caller=keyReleaseEvent@00663420
REF 006716a0 UNCONDITIONAL_CALL caller=getOtherFileRealName@00671530
REF 006727b0 UNCONDITIONAL_CALL caller=copyFileToCamera@00672568
REF 006727c8 UNCONDITIONAL_CALL caller=copyFileToCamera@00672568
REF 00676618 UNCONDITIONAL_CALL caller=setCameraShutterAngle@006765a0
REF 00678d34 UNCONDITIONAL_CALL caller=findFileFromDir@00678c98
REF 0067c934 UNCONDITIONAL_CALL caller=getFileSize@0067c818
REF 0067cabc UNCONDITIONAL_CALL caller=scaledImage@0067c9b0
REF 0067cc50 UNCONDITIONAL_CALL caller=scaledImage@0067c9b0
REF 0067ccf4 UNCONDITIONAL_CALL caller=scaledImage@0067c9b0
REF 0067cd54 UNCONDITIONAL_CALL caller=scaledImage@0067c9b0
REF 0067cd88 UNCONDITIONAL_CALL caller=scaledImage@0067c9b0
REF 0069cd40 UNCONDITIONAL_CALL caller=autoOff@0069cc10
REF 006a09b4 UNCONDITIONAL_CALL caller=handleMiscEvent@006a04a0
REF 006a09d0 UNCONDITIONAL_CALL caller=handleMiscEvent@006a04a0
REF 006a0edc UNCONDITIONAL_CALL caller=handleMiscEvent@006a04a0
REF 006a0ef8 UNCONDITIONAL_CALL caller=handleMiscEvent@006a04a0
REF 006a1398 UNCONDITIONAL_CALL caller=handlePubMessage@006a12f8
REF 006a895c UNCONDITIONAL_CALL caller=calibration@006a8688
REF 006c7f7c UNCONDITIONAL_CALL caller=getWifiSSID@006c7e98
REF 006f9130 UNCONDITIONAL_CALL caller=imvt_cam_controller_photo_cap@006f9060
REF 00702e1c UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_photo_cap@00702d60
REF 00702e4c UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_photo_cap@00702d60
REF 00702f84 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_photo_cap@00702d60
REF 00702fb0 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_photo_cap@00702d60
REF 00702fd0 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_photo_cap@00702d60
REF 00702fe8 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_photo_cap@00702d60
REF 00703000 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_photo_cap@00702d60
REF 00703018 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_photo_cap@00702d60
REF 007020c0 UNCONDITIONAL_CALL caller=FUN_00702088@00702088
REF 008816d0 UNCONDITIONAL_CALL caller=imvt_cam_photo_start_timelapse@00881680
REF 008815ec UNCONDITIONAL_CALL caller=imvt_cam_photo_capture@00881568
REF 0077602c UNCONDITIONAL_CALL caller=push@00775fb0
REF 00776108 UNCONDITIONAL_CALL caller=push@00775fb0
REF 0077611c UNCONDITIONAL_CALL caller=push@00775fb0
REF 007a7db0 UNCONDITIONAL_CALL caller=loadConfig@007a7d28
REF 007a82a8 UNCONDITIONAL_CALL caller=loadConfig@007a7d28
REF 007a83cc UNCONDITIONAL_CALL caller=loadConfig@007a7d28
REF 007a8470 UNCONDITIONAL_CALL caller=loadConfig@007a7d28
REF 007a84ac UNCONDITIONAL_CALL caller=loadConfig@007a7d28
REF 00775314 UNCONDITIONAL_CALL caller=init@007751f0
REF 007753d4 UNCONDITIONAL_CALL caller=init@007751f0
REF 0073fa4c UNCONDITIONAL_CALL caller=prepareHttpServer@0073f900
REF 007751bc UNCONDITIONAL_CALL caller=setupSSL@00775148
REF 007513c4 UNCONDITIONAL_CALL caller=changePassword@00751208
REF 00751524 UNCONDITIONAL_CALL caller=changePassword@00751208
REF 00750790 UNCONDITIONAL_CALL caller=initPermission@00750598
REF 00752f84 UNCONDITIONAL_CALL caller=~MyDocumentHandler@00752f58
REF 0075c9d0 UNCONDITIONAL_CALL caller=processRequest@0075c910
REF 0075ca54 UNCONDITIONAL_CALL caller=processRequest@0075c910
REF 0075416c UNCONDITIONAL_CALL caller=uploadFile@007540d8
REF 00777fd4 UNCONDITIONAL_CALL caller=handleUploadFile@007776c8
REF 00778060 UNCONDITIONAL_CALL caller=handleUploadFile@007776c8
REF 00746c7c UNCONDITIONAL_CALL caller=read@00746bf8
REF 0082f4f4 UNCONDITIONAL_CALL caller=storeTotalFileMd5@0082f3b0
REF 0076615c UNCONDITIONAL_CALL caller=handleSetConfig@00765f30
REF 007663ec UNCONDITIONAL_CALL caller=handleSetConfig@00765f30
REF 00766558 UNCONDITIONAL_CALL caller=handleSetConfig@00765f30
REF 00766590 UNCONDITIONAL_CALL caller=handleSetConfig@00765f30
REF 007665fc UNCONDITIONAL_CALL caller=handleSetConfig@00765f30
REF 0076661c UNCONDITIONAL_CALL caller=handleSetConfig@00765f30
REF 007668b0 UNCONDITIONAL_CALL caller=handleCard@00766688
REF 0081f3b8 UNCONDITIONAL_CALL caller=wifi_get_ap_list@0081f0e0
REF 0081f3d4 UNCONDITIONAL_CALL caller=wifi_get_ap_list@0081f0e0
REF 0081f3e4 UNCONDITIONAL_CALL caller=wifi_get_ap_list@0081f0e0
REF 0081f404 UNCONDITIONAL_CALL caller=wifi_get_ap_list@0081f0e0
REF 0081f424 UNCONDITIONAL_CALL caller=wifi_get_ap_list@0081f0e0
REF 0081e374 UNCONDITIONAL_CALL caller=FUN_0081e340@0081e340
REF 0081e924 UNCONDITIONAL_CALL caller=FUN_0081e878@0081e878
REF 00820c04 UNCONDITIONAL_CALL caller=wifi_get_current_ap_name@00820b78
REF 00824ecc UNCONDITIONAL_CALL caller=imvt_lut_file_color_load@00824ea8
REF 0082570c UNCONDITIONAL_CALL caller=imvt_lut_file_get_user_import@00825580
REF 00775a34 UNCONDITIONAL_CALL caller=handleWrite@00775888
REF 00776b24 UNCONDITIONAL_CALL caller=init@007765d0
REF 007469e0 UNCONDITIONAL_CALL caller=handshake@00746970
REF 00746a38 UNCONDITIONAL_CALL caller=handshake@00746970
REF 00780e9c UNCONDITIONAL_CALL caller=handleRequest@00780868
REF 006c73dc UNCONDITIONAL_CALL caller=getIPAddr@006c7318
REF 006c73f4 UNCONDITIONAL_CALL caller=getIPAddr@006c7318
REF 006c7c84 UNCONDITIONAL_CALL caller=getLANConnectStatus@006c7bc8
REF 006c7c9c UNCONDITIONAL_CALL caller=getLANConnectStatus@006c7bc8
REF 0078c938 UNCONDITIONAL_CALL caller=uploadCertificate@0078bd70
REF 0078c500 UNCONDITIONAL_CALL caller=uploadCertificate@0078bd70
REF 0078cddc UNCONDITIONAL_CALL caller=uploadCertificate@0078bd70
REF 008332a0 UNCONDITIONAL_CALL caller=cert_util_mkcert@00833208
REF 008334a8 UNCONDITIONAL_CALL caller=cert_util_mkcert@00833208
REF 008334cc UNCONDITIONAL_CALL caller=cert_util_mkcert@00833208
REF 008337a8 UNCONDITIONAL_CALL caller=cert_util_extract_cert_info@008335a0
REF 008337c0 UNCONDITIONAL_CALL caller=cert_util_extract_cert_info@008335a0
REF 007a7ac4 UNCONDITIONAL_CALL caller=addToWhitelist@007a7a40
REF 007a7b1c UNCONDITIONAL_CALL caller=addToWhitelist@007a7a40
REF 007a7c34 UNCONDITIONAL_CALL caller=addToBlacklist@007a7bb0
REF 007a7c8c UNCONDITIONAL_CALL caller=addToBlacklist@007a7bb0
REF 007a4fb0 UNCONDITIONAL_CALL caller=deleteConfig@007a4f00
REF 007b31d8 UNCONDITIONAL_CALL caller=handleUartCmd@007b3060
REF 007b87d8 UNCONDITIONAL_CALL caller=FactoryModeController@007b85e8
REF 007b92ac UNCONDITIONAL_CALL caller=imvt_factory_led_init@007b9220
REF 007b92cc UNCONDITIONAL_CALL caller=imvt_factory_led_init@007b9220
REF 007bdba4 UNCONDITIONAL_CALL caller=FactoryModeNoGUIController@007bd9c0
REF 007bdbdc UNCONDITIONAL_CALL caller=FactoryModeNoGUIController@007bd9c0
REF 007bc7cc UNCONDITIONAL_CALL caller=FUN_007bc658@007bc658
REF 007bc84c UNCONDITIONAL_CALL caller=FUN_007bc658@007bc658
REF 007bc89c UNCONDITIONAL_CALL caller=FUN_007bc658@007bc658
REF 007bc8ec UNCONDITIONAL_CALL caller=FUN_007bc658@007bc658
REF 007bc8fc UNCONDITIONAL_CALL caller=FUN_007bc658@007bc658
REF 007bc918 UNCONDITIONAL_CALL caller=FUN_007bc658@007bc658
REF 007bcacc UNCONDITIONAL_CALL caller=FUN_007bc930@007bc930
REF 007bcaf0 UNCONDITIONAL_CALL caller=FUN_007bc930@007bc930
REF 00a4f1a4 UNCONDITIONAL_CALL caller=imvt_sys_write_sn@00a4f120
REF 00a4f1e0 UNCONDITIONAL_CALL caller=imvt_sys_write_sn@00a4f120
REF 007d6634 UNCONDITIONAL_CALL caller=writeEvent@007d6560
REF 007d672c UNCONDITIONAL_CALL caller=writeMessage@007d6658
REF 007d7cf4 UNCONDITIONAL_CALL caller=FUN_007d7630@007d7630
REF 007d7d70 UNCONDITIONAL_CALL caller=FUN_007d7630@007d7630
REF 007d7dfc UNCONDITIONAL_CALL caller=FUN_007d7630@007d7630
REF 007d7f44 UNCONDITIONAL_CALL caller=FUN_007d7630@007d7630
REF 007e3de0 UNCONDITIONAL_CALL caller=acquireMessageCtx@007e3c90
REF 007e3e90 UNCONDITIONAL_CALL caller=acquireMessageCtx@007e3c90
REF 007d6bf0 UNCONDITIONAL_CALL caller=stat@007d6bd0
REF 007d6c04 UNCONDITIONAL_CALL caller=stat@007d6bd0
REF 007d6c18 UNCONDITIONAL_CALL caller=stat@007d6bd0
REF 007d6c2c UNCONDITIONAL_CALL caller=stat@007d6bd0
REF 007d6c40 UNCONDITIONAL_CALL caller=stat@007d6bd0
REF 007d6c54 UNCONDITIONAL_CALL caller=stat@007d6bd0
REF 007e36b8 UNCONDITIONAL_CALL caller=releaseBuffer@007e3668
REF 007e6070 UNCONDITIONAL_CALL caller=onMessage@007e5e50
REF 007e7a9c UNCONDITIONAL_CALL caller=handleEvent@007e7660
REF 007e77cc UNCONDITIONAL_CALL caller=handleEvent@007e7660
REF 007e7778 UNCONDITIONAL_CALL caller=handleEvent@007e7660
REF 007e7ad4 UNCONDITIONAL_CALL caller=handleEvent@007e7660
REF 007e7300 UNCONDITIONAL_CALL caller=broadcast@007e6ed8
REF 00877d5c UNCONDITIONAL_CALL caller=imvt_cam_audio_rms_get_db@00877ca8
REF 00877d98 UNCONDITIONAL_CALL caller=imvt_cam_audio_rms_get_db@00877ca8
REF 0087d90c UNCONDITIONAL_CALL caller=imvt_cam_playback_get_volume@0087d780
REF 0087d930 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_volume@0087d780
REF 0087d958 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_volume@0087d780
REF 007e81e8 UNCONDITIONAL_CALL caller=handlePubMessage@007e7fb8
REF 007f020c UNCONDITIONAL_CALL caller=imvt_tracking_get_ssd_json_result@007efed8
REF 0081ac40 UNCONDITIONAL_CALL caller=imvt_maintain_log_generate_zcam_report@0081ab10
REF 0081b0ac UNCONDITIONAL_CALL caller=imvt_maintain_log_generate_zcam_report@0081ab10
REF 0081b12c UNCONDITIONAL_CALL caller=imvt_maintain_log_generate_zcam_report@0081ab10
REF 0081c5ac UNCONDITIONAL_CALL caller=addStorageToServer@0081c410
REF 0081c39c UNCONDITIONAL_CALL caller=mtpServerSetup@0081c310
REF 00832a74 UNCONDITIONAL_CALL caller=imvt_ptz_focus_set_speed@008329b8
REF 0083500c UNCONDITIONAL_CALL caller=commReboot@00834ef8
REF 00835524 UNCONDITIONAL_CALL caller=commSetSdiOnOff@00835428
REF 00835674 UNCONDITIONAL_CALL caller=commSetSdiLevel@00835578
REF 008357d4 UNCONDITIONAL_CALL caller=commGetVersionNew@008356c8
REF 00835934 UNCONDITIONAL_CALL caller=commGetIapCurPart@00835828
REF 00835a8c UNCONDITIONAL_CALL caller=commSetIapStart@00835988
REF 00835bec UNCONDITIONAL_CALL caller=commSetIapDownload@00835ae8
REF 00835d3c UNCONDITIONAL_CALL caller=commSetIapVerify@00835c40
REF 00835e8c UNCONDITIONAL_CALL caller=commSetIapEnd@00835d90
REF 0083645c UNCONDITIONAL_CALL caller=commSetBreathingLightEnable@00836360
REF 008366fc UNCONDITIONAL_CALL caller=commSetTimeCodeDropFlag@00836600
REF 0083684c UNCONDITIONAL_CALL caller=commSetSdiCableDriverLevel@00836750
REF 008369a4 UNCONDITIONAL_CALL caller=commSetSdiReg@008368a0
REF 00836b04 UNCONDITIONAL_CALL caller=commGetSdiReg@008369f8
REF 008386b8 UNCONDITIONAL_CALL caller=safeSendPacket@008385a0
REF 0087c2c0 UNCONDITIONAL_CALL caller=FUN_0087c1d8@0087c1d8
REF 0087c56c UNCONDITIONAL_CALL caller=FUN_0087c1d8@0087c1d8
REF 008bb290 UNCONDITIONAL_CALL caller=start@008bb220
REF 008ba21c UNCONDITIONAL_CALL caller=handleStartCommand@008ba108
REF 008ba230 UNCONDITIONAL_CALL caller=handleStartCommand@008ba108
REF 008ba248 UNCONDITIONAL_CALL caller=handleStartCommand@008ba108
REF 008ba254 UNCONDITIONAL_CALL caller=handleStartCommand@008ba108
REF 008ba26c UNCONDITIONAL_CALL caller=handleStartCommand@008ba108
REF 008ba284 UNCONDITIONAL_CALL caller=handleStartCommand@008ba108
REF 008ba290 UNCONDITIONAL_CALL caller=handleStartCommand@008ba108
REF 008bab5c UNCONDITIONAL_CALL caller=handleStartCommand@008ba108
REF 008c1d4c UNCONDITIONAL_CALL caller=SrtSource@008c18f8
REF 0087f9b8 UNCONDITIONAL_CALL caller=imvt_cam_playback_set_url@0087f030
REF 008b971c UNCONDITIONAL_CALL caller=setPlaySpeed@008b9610
REF 008b9f10 UNCONDITIONAL_CALL caller=pause@008b9ea8
REF 008ba040 UNCONDITIONAL_CALL caller=resume@008b9fd8
REF 008bdeb4 UNCONDITIONAL_CALL caller=task@008bdd90
REF 008bdf94 UNCONDITIONAL_CALL caller=task@008bdd90
REF 008be018 UNCONDITIONAL_CALL caller=task@008bdd90
REF 008be4bc UNCONDITIONAL_CALL caller=task@008bdd90
REF 008be580 UNCONDITIONAL_CALL caller=task@008bdd90
REF 008c1ecc UNCONDITIONAL_CALL caller=listenerTask@008c1e20
REF 008c1fe4 UNCONDITIONAL_CALL caller=listenerTask@008c1e20
REF 008c2378 UNCONDITIONAL_CALL caller=listenerTask@008c1e20
REF 008c2654 UNCONDITIONAL_CALL caller=listenerTask@008c1e20
REF 008c02b0 UNCONDITIONAL_CALL caller=setTimer@008c0210
REF 008c2d54 UNCONDITIONAL_CALL caller=callerTask@008c28b8
REF 008c2f70 UNCONDITIONAL_CALL caller=callerTask@008c28b8
REF 008c3088 UNCONDITIONAL_CALL caller=callerTask@008c28b8
REF 00a18cb0 UNCONDITIONAL_CALL caller=Connector@00a18bb0
REF 008c9c20 UNCONDITIONAL_CALL caller=task@008c9b30
REF 008c9d3c UNCONDITIONAL_CALL caller=task@008c9b30
REF 008c9e50 UNCONDITIONAL_CALL caller=task@008c9b30
REF 008ca2a8 UNCONDITIONAL_CALL caller=task@008c9b30
REF 008ca280 UNCONDITIONAL_CALL caller=task@008c9b30
REF 008ceb90 UNCONDITIONAL_CALL caller=createFileDemuxer@008ce9c8
REF 00a13e78 UNCONDITIONAL_CALL caller=fmt_demuxer_create_jpeg@00a13df0
REF 008d20d0 UNCONDITIONAL_CALL caller=sendVFrame@008d1f28
REF 008d23c8 UNCONDITIONAL_CALL caller=sendAFrame@008d2238
REF 008d8020 UNCONDITIONAL_CALL caller=FUN_008d7da0@008d7da0
REF 008d8064 UNCONDITIONAL_CALL caller=FUN_008d7da0@008d7da0
REF 008d8124 UNCONDITIONAL_CALL caller=FUN_008d7da0@008d7da0
REF 008d8c4c UNCONDITIONAL_CALL caller=PrivateH264VideoSource@008d8bf8
REF 008db59c UNCONDITIONAL_CALL caller=createNew@008db458
REF 00877298 UNCONDITIONAL_CALL caller=imvt_cam_audio_register_aenc_frame_cb@00877268
REF 008772d8 UNCONDITIONAL_CALL caller=imvt_cam_audio_unregister_aenc_frame_cb@008772a8
REF 008de3ac UNCONDITIONAL_CALL caller=PrivateH265VideoSource@008de358
REF 00920ff8 UNCONDITIONAL_CALL caller=FUN_00920eb0@00920eb0
REF 00922670 UNCONDITIONAL_CALL caller=FUN_00921af0@00921af0
REF 009227d8 UNCONDITIONAL_CALL caller=FUN_00921af0@00921af0
REF 00a14588 UNCONDITIONAL_CALL caller=fmt_ts_muxer_add_stream@00a144d8
REF 00a145a4 UNCONDITIONAL_CALL caller=fmt_ts_muxer_add_stream@00a144d8
REF 00a14644 UNCONDITIONAL_CALL caller=fmt_ts_muxer_create@00a145b0
REF 00a1465c UNCONDITIONAL_CALL caller=fmt_ts_muxer_create@00a145b0
REF 00a1467c UNCONDITIONAL_CALL caller=fmt_ts_muxer_create@00a145b0
REF 00a146c8 UNCONDITIONAL_CALL caller=fmt_ts_muxer_destroy@00a14688
REF 00925f18 UNCONDITIONAL_CALL caller=handleAccept@00925bf8
REF 00926488 UNCONDITIONAL_CALL caller=handleAccept@00925bf8
REF 0092649c UNCONDITIONAL_CALL caller=handleAccept@00925bf8
REF 009264b4 UNCONDITIONAL_CALL caller=handleAccept@00925bf8
REF 009264d0 UNCONDITIONAL_CALL caller=handleAccept@00925bf8
REF 00927e64 UNCONDITIONAL_CALL caller=listenerTask@00927da0
REF 0092823c UNCONDITIONAL_CALL caller=listenerTask@00927da0
REF 00928478 UNCONDITIONAL_CALL caller=listenerTask@00927da0
REF 00928594 UNCONDITIONAL_CALL caller=listenerTask@00927da0
REF 009285b4 UNCONDITIONAL_CALL caller=listenerTask@00927da0
REF 009285d8 UNCONDITIONAL_CALL caller=listenerTask@00927da0
REF 009eaac0 UNCONDITIONAL_CALL caller=frame_fifo_get_frame@009ea990
REF 009eab14 UNCONDITIONAL_CALL caller=frame_fifo_get_frame@009ea990
REF 009eadd4 UNCONDITIONAL_CALL caller=frame_fifo_release_current_frame@009eacc8
REF 009eae60 UNCONDITIONAL_CALL caller=frame_fifo_release_current_frame@009eacc8
REF 009ebd58 UNCONDITIONAL_CALL caller=gop_buffer_get_frame_info@009ebb60
REF 009ebd7c UNCONDITIONAL_CALL caller=gop_buffer_get_frame_info@009ebb60
REF 009ebe7c UNCONDITIONAL_CALL caller=gop_buffer_release_current_frame@009ebd98
REF 009ebee4 UNCONDITIONAL_CALL caller=gop_buffer_release_current_frame@009ebd98
REF 009ebf08 UNCONDITIONAL_CALL caller=gop_buffer_release_current_frame@009ebd98
REF 009ebf24 UNCONDITIONAL_CALL caller=gop_buffer_release_current_frame@009ebd98
REF 009ebf5c UNCONDITIONAL_CALL caller=gop_buffer_release_current_frame@009ebd98
REF 00a1440c UNCONDITIONAL_CALL caller=fmt_ts_muxer_write_video@00a14350
REF 00a14424 UNCONDITIONAL_CALL caller=fmt_ts_muxer_write_video@00a14350
REF 00a14310 UNCONDITIONAL_CALL caller=fmt_ts_muxer_write_stream_packet@00a14260
REF 00a144a4 UNCONDITIONAL_CALL caller=fmt_ts_muxer_write_audio@00a14440
REF 00a144bc UNCONDITIONAL_CALL caller=fmt_ts_muxer_write_audio@00a14440
REF 009f95f8 UNCONDITIONAL_CALL caller=info_log@009f94e8
REF 006f4260 UNCONDITIONAL_CALL caller=imvt_cam_controller_disable_ssp_push@006f4128
REF 006f42e4 UNCONDITIONAL_CALL caller=imvt_cam_controller_disable_ssp_push@006f4128
REF 009fb7cc UNCONDITIONAL_CALL caller=heartbeat@009fb740
REF 00a19c88 UNCONDITIONAL_CALL caller=send@00a19a58
REF 00a19ca0 UNCONDITIONAL_CALL caller=send@00a19a58
REF 00a197e4 UNCONDITIONAL_CALL caller=sendDataInBuffer@00a19758
REF 00a199a8 UNCONDITIONAL_CALL caller=startRead@00a198f0
REF 00a19e94 UNCONDITIONAL_CALL caller=~TcpConnection@00a19e50
REF 00a19f2c UNCONDITIONAL_CALL caller=~TcpConnection@00a19e50
REF 00a1a068 UNCONDITIONAL_CALL caller=~TcpConnection@00a19e50
REF 00a1a0d8 UNCONDITIONAL_CALL caller=~TcpConnection@00a19e50
REF 00a1a0f4 UNCONDITIONAL_CALL caller=~TcpConnection@00a19e50
REF 00a19d14 UNCONDITIONAL_CALL caller=forceClose@00a19cd0
REF 00a19e08 UNCONDITIONAL_CALL caller=forceClose@00a19cd0
REF 00a18af8 UNCONDITIONAL_CALL caller=doReconnect@00a18ac8
REF 00a18924 UNCONDITIONAL_CALL caller=close@00a188b8
REF 00a189b8 UNCONDITIONAL_CALL caller=close@00a188b8
REF 00a1920c UNCONDITIONAL_CALL caller=stop@00a190f8
REF 00a19270 UNCONDITIONAL_CALL caller=stop@00a190f8
REF 00a192ac UNCONDITIONAL_CALL caller=stop@00a190f8
REF 00a1a308 UNCONDITIONAL_CALL caller=onCloseHandler@00a1a1a0
REF 00a1a65c UNCONDITIONAL_CALL caller=onReadCb@00a1a4f8
REF 00a1a408 UNCONDITIONAL_CALL caller=onClose@00a1a3e0
REF 00a1a444 UNCONDITIONAL_CALL caller=onClose@00a1a3e0
REF 00a1a1d8 UNCONDITIONAL_CALL caller=onCloseHandler@00a1a1a0
REF 00a68430 UNCONDITIONAL_CALL caller=_imvt_img_set_gamma@00a68050
REF 00a68a44 UNCONDITIONAL_CALL caller=file_analysis@00a686d8
REF 00a68be8 UNCONDITIONAL_CALL caller=file_analysis@00a686d8
REF 00a68c04 UNCONDITIONAL_CALL caller=file_analysis@00a686d8
REF 00a68c20 UNCONDITIONAL_CALL caller=file_analysis@00a686d8
REF 00a68d3c UNCONDITIONAL_CALL caller=imvt_img_set_gamma@00a68cc0
REF 00a675d0 UNCONDITIONAL_CALL caller=FUN_00a67570@00a67570
REF 00a697ac UNCONDITIONAL_CALL caller=FUN_00a69728@00a69728
REF 00a697f4 UNCONDITIONAL_CALL caller=FUN_00a69728@00a69728
REF 00a69bb8 UNCONDITIONAL_CALL caller=FUN_00a69958@00a69958
REF 00a699dc UNCONDITIONAL_CALL caller=FUN_00a69958@00a69958
REF 00abe8bc UNCONDITIONAL_CALL caller=handleDeviceAddedInLooper@00abe890
REF 00abe9dc UNCONDITIONAL_CALL caller=handleDeviceRemovedInLooper@00abe998
REF 00abe950 UNCONDITIONAL_CALL caller=disconnectDevice@00abe930
REF 009ea1ec UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea1fc UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea388 UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea3cc UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea3e0 UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea470 UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea4a8 UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea524 UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea550 UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea570 UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea590 UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea6a0 UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea7e0 UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea954 UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 009ea97c UNCONDITIONAL_CALL caller=frame_fifo_write_frame_data@009ea0b0
REF 00ac3ce0 UNCONDITIONAL_CALL caller=ping@00ac3c90
REF 00ac4428 UNCONDITIONAL_CALL caller=connectEstablished@00ac43e8
REF 00acc82c UNCONDITIONAL_CALL caller=connectEstablished@00acc7e8
REF 00acd484 UNCONDITIONAL_CALL caller=TcpConnection@00acd2b0
REF 00accc6c UNCONDITIONAL_CALL caller=connectDestroyed@00accc30
REF 00accccc UNCONDITIONAL_CALL caller=connectDestroyed@00accc30
REF 00ac3930 UNCONDITIONAL_CALL caller=~ICamConnection@00ac3910
REF 00acbab8 UNCONDITIONAL_CALL caller=~TcpConnection@00acba90
REF 00accf28 UNCONDITIONAL_CALL caller=handleClose@00acce58
REF 00a3ba64 UNCONDITIONAL_CALL caller=bsp_arch_hi3559av100_init@00a3b928
REF 00a3bc08 UNCONDITIONAL_CALL caller=bsp_arch_hi3559av100_init@00a3b928
REF 00a3bfb8 UNCONDITIONAL_CALL caller=bsp_arch_hi3559av100_init@00a3b928
REF 00a3bfd0 UNCONDITIONAL_CALL caller=bsp_arch_hi3559av100_init@00a3b928
REF 00a3bfe0 UNCONDITIONAL_CALL caller=bsp_arch_hi3559av100_init@00a3b928
REF 00a45200 UNCONDITIONAL_CALL caller=imvt_adc_init@00a450e8
REF 00a45250 UNCONDITIONAL_CALL caller=imvt_adc_init@00a450e8
REF 00a45294 UNCONDITIONAL_CALL caller=imvt_adc_init@00a450e8
REF 00a452ac UNCONDITIONAL_CALL caller=imvt_adc_init@00a450e8
REF 00a44d58 UNCONDITIONAL_CALL caller=imvt_adc_enable_chn@00a44cf0
REF 00a44d7c UNCONDITIONAL_CALL caller=imvt_adc_enable_chn@00a44cf0
REF 00a44e9c UNCONDITIONAL_CALL caller=imvt_adc_set_bit_wide@00a44e30
REF 00a44ebc UNCONDITIONAL_CALL caller=imvt_adc_set_bit_wide@00a44e30
REF 00a44f30 UNCONDITIONAL_CALL caller=imvt_adc_start_convent@00a44ed0
REF 00a495a4 UNCONDITIONAL_CALL caller=imvt_i2c_gpio_bus_register@00a49520
REF 00a495d0 UNCONDITIONAL_CALL caller=imvt_i2c_gpio_bus_register@00a49520
REF 007bba80 UNCONDITIONAL_CALL caller=imvt_cam_is_facotry_mode@007bba50
REF 007bbab4 UNCONDITIONAL_CALL caller=imvt_cam_is_facotry_mode@007bba50
REF 006118f8 UNCONDITIONAL_CALL caller=FUN_006118e0@006118e0
REF 00611980 UNCONDITIONAL_CALL caller=FUN_00611968@00611968
REF 006c7efc UNCONDITIONAL_CALL caller=getWifiSSID@006c7e98
REF 006a2060 UNCONDITIONAL_CALL caller=changeOptionValue@006a1f70
REF 006a20e8 UNCONDITIONAL_CALL caller=changeOptionValue@006a1f70
REF 006a2100 UNCONDITIONAL_CALL caller=changeOptionValue@006a1f70
REF 00629b1c UNCONDITIONAL_CALL caller=showConfigByKey@00629890
REF 00629b3c UNCONDITIONAL_CALL caller=showConfigByKey@00629890
REF 0062c714 UNCONDITIONAL_CALL caller=customKeyEndAutoDetection@0062c6b8
REF 0062c75c UNCONDITIONAL_CALL caller=customKeyEndAutoDetection@0062c6b8
REF 0062ccbc UNCONDITIONAL_CALL caller=customKeyAperture@0062cc50
REF 0062cef0 UNCONDITIONAL_CALL caller=customKeyColorTemp@0062ce60
REF 0062edc0 UNCONDITIONAL_CALL caller=checkStreamingDialog@0062ed40
REF 006314b8 UNCONDITIONAL_CALL caller=keyReleaseEvent@006313c0
REF 0063151c UNCONDITIONAL_CALL caller=keyReleaseEvent@006313c0
REF 00631554 UNCONDITIONAL_CALL caller=keyReleaseEvent@006313c0
REF 0063157c UNCONDITIONAL_CALL caller=keyReleaseEvent@006313c0
REF 006315cc UNCONDITIONAL_CALL caller=keyReleaseEvent@006313c0
REF 00631654 UNCONDITIONAL_CALL caller=keyReleaseEvent@006313c0
REF 0063167c UNCONDITIONAL_CALL caller=keyReleaseEvent@006313c0
REF 006316bc UNCONDITIONAL_CALL caller=keyReleaseEvent@006313c0
REF 00631704 UNCONDITIONAL_CALL caller=keyReleaseEvent@006313c0
REF 0068fdfc UNCONDITIONAL_CALL caller=setData@0068fbf8
REF 00690210 UNCONDITIONAL_CALL caller=setData@0068fe30
REF 00696fe8 UNCONDITIONAL_CALL caller=setData@00696d98
REF 006770a8 UNCONDITIONAL_CALL caller=checkNoVinStatus@00677060
REF 0067e618 UNCONDITIONAL_CALL caller=pluginMonitor@0067e510
REF 0067e674 UNCONDITIONAL_CALL caller=pluginMonitor@0067e510
REF 0069bfbc UNCONDITIONAL_CALL caller=powerOff@0069bfa8
REF 006c6d84 UNCONDITIONAL_CALL caller=shutdown@006c6d58
REF 00a448b4 UNCONDITIONAL_CALL caller=imvt_poweroff@00a44840
REF 00a448cc UNCONDITIONAL_CALL caller=imvt_poweroff@00a44840
REF 007bee24 UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_shudown_preapare@007bee10
REF 007bee4c UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_shutdown@007bee38
REF 00a44724 UNCONDITIONAL_CALL caller=FUN_00a44678@00a44678
REF 00a4474c UNCONDITIONAL_CALL caller=FUN_00a44678@00a44678
REF 0069c558 UNCONDITIONAL_CALL caller=checkFwVersionAndUpgrade@0069c480
REF 0069c574 UNCONDITIONAL_CALL caller=checkFwVersionAndUpgrade@0069c480
REF 0069c5a4 UNCONDITIONAL_CALL caller=checkFwVersionAndUpgrade@0069c480
REF 0069c914 UNCONDITIONAL_CALL caller=getMonitorHdmiMsg@0069c728
REF 0069c954 UNCONDITIONAL_CALL caller=getMonitorHdmiMsg@0069c728
REF 0069c99c UNCONDITIONAL_CALL caller=getMonitorHdmiMsg@0069c728
REF 0069c9d0 UNCONDITIONAL_CALL caller=getMonitorHdmiMsg@0069c728
REF 006c7d18 UNCONDITIONAL_CALL caller=getUSBIsRecognizable@006c7ca8
REF 006c7e8c UNCONDITIONAL_CALL caller=getUSBIsSuperSpeed@006c7d28
REF 0069cb84 UNCONDITIONAL_CALL caller=isRecordOk@0069cb08
REF 0069cf78 UNCONDITIONAL_CALL caller=checkRecordStatus@0069cf28
REF 006a42dc UNCONDITIONAL_CALL caller=subscribeEvent@006a4278
REF 006a75a0 UNCONDITIONAL_CALL caller=updateSnAndResetDcf@006a73d0
REF 006a701c UNCONDITIONAL_CALL caller=resetDcf@006a6ea8
REF 006a7210 UNCONDITIONAL_CALL caller=updateProductSn@006a7170
REF 006a728c UNCONDITIONAL_CALL caller=updateProductSn@006a7170
REF 006a7300 UNCONDITIONAL_CALL caller=updateProductSn@006a7170
REF 006a73a0 UNCONDITIONAL_CALL caller=updateProductSn@006a7170
REF 006a7150 UNCONDITIONAL_CALL caller=isNeedForceWriteSn@006a7038
REF 006b0ab0 UNCONDITIONAL_CALL caller=preference_contains_key@006b0a78
REF 006c74c8 UNCONDITIONAL_CALL caller=getNetmaskAddr@006c7400
REF 006c74dc UNCONDITIONAL_CALL caller=getNetmaskAddr@006c7400
REF 006c76d4 UNCONDITIONAL_CALL caller=getGatewayAddr@006c74e8
REF 006c76ec UNCONDITIONAL_CALL caller=getGatewayAddr@006c74e8
REF 006da978 UNCONDITIONAL_CALL caller=restart_net_if@006da8f8
REF 006daa14 UNCONDITIONAL_CALL caller=restart_net_if@006da8f8
REF 006daa30 UNCONDITIONAL_CALL caller=restart_net_if@006da8f8
REF 006daaec UNCONDITIONAL_CALL caller=stop_udhcpd_service@006daa40
REF 006dab34 UNCONDITIONAL_CALL caller=stop_udhcpd_service@006daa40
REF 006dab84 UNCONDITIONAL_CALL caller=stop_udhcpd_service@006daa40
REF 006dabf4 UNCONDITIONAL_CALL caller=start_udhcpd_service@006dab90
REF 006dac2c UNCONDITIONAL_CALL caller=start_udhcpd_service@006dab90
REF 006dac64 UNCONDITIONAL_CALL caller=start_udhcpd_service@006dab90
REF 006dad50 UNCONDITIONAL_CALL caller=stop_udhcpc_service@006dac78
REF 006dad94 UNCONDITIONAL_CALL caller=stop_udhcpc_service@006dac78
REF 006dade4 UNCONDITIONAL_CALL caller=stop_udhcpc_service@006dac78
REF 006daeac UNCONDITIONAL_CALL caller=start_udhcpc_service@006dadf0
REF 006daf04 UNCONDITIONAL_CALL caller=start_udhcpc_service@006dadf0
REF 006daf58 UNCONDITIONAL_CALL caller=start_udhcpc_service@006dadf0
REF 006db1fc UNCONDITIONAL_CALL caller=nerwork_get_connected_if@006db0b8
REF 006db21c UNCONDITIONAL_CALL caller=nerwork_get_connected_if@006db0b8
REF 006db2fc UNCONDITIONAL_CALL caller=nerwork_get_ip_address@006db238
REF 006db314 UNCONDITIONAL_CALL caller=nerwork_get_ip_address@006db238
REF 006db694 UNCONDITIONAL_CALL caller=network_get_netmask@006db5b8
REF 006db6ac UNCONDITIONAL_CALL caller=network_get_netmask@006db5b8
REF 006db870 UNCONDITIONAL_CALL caller=network_get_gateway@006db6c8
REF 006db994 UNCONDITIONAL_CALL caller=network_set_dns@006db880
REF 006dba38 UNCONDITIONAL_CALL caller=network_set_dns@006db880
REF 006dba7c UNCONDITIONAL_CALL caller=network_set_dns@006db880
REF 006dbab4 UNCONDITIONAL_CALL caller=network_set_dns@006db880
REF 006dbadc UNCONDITIONAL_CALL caller=network_set_dns@006db880
REF 006dbb04 UNCONDITIONAL_CALL caller=network_set_dns@006db880
REF 006dbc58 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dbf64 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dc024 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dc144 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dc288 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dc45c UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dc478 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dc618 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dc7c8 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dc908 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dc960 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dcb2c UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dcb54 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dcb9c UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dcc64 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dcc94 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dccbc UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dccec UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dcd08 UNCONDITIONAL_CALL caller=FUN_006dbb10@006dbb10
REF 006dcee0 UNCONDITIONAL_CALL caller=network_get_dns@006dcd10
REF 006dcf24 UNCONDITIONAL_CALL caller=network_get_dns@006dcd10
REF 006dcf4c UNCONDITIONAL_CALL caller=network_get_dns@006dcd10
REF 006e8514 UNCONDITIONAL_CALL caller=FUN_006e84a0@006e84a0
REF 006e85b4 UNCONDITIONAL_CALL caller=FUN_006e8540@006e8540
REF 006e8654 UNCONDITIONAL_CALL caller=FUN_006e85e0@006e85e0
REF 006e86e4 UNCONDITIONAL_CALL caller=FUN_006e8680@006e8680
REF 006e877c UNCONDITIONAL_CALL caller=FUN_006e8748@006e8748
REF 006fb5bc UNCONDITIONAL_CALL caller=imvt_cam_controller_update_hdmi_format@006fb4b8
REF 006fb5d4 UNCONDITIONAL_CALL caller=imvt_cam_controller_update_hdmi_format@006fb4b8
REF 006fb47c UNCONDITIONAL_CALL caller=imvt_cam_controller_update_hdmi_format_in_res_auto_mode@006fb428
REF 00a046a0 UNCONDITIONAL_CALL caller=mov_file_is_bad@00a04480
REF 00a04768 UNCONDITIONAL_CALL caller=mov_file_is_bad@00a04480
REF 00a047b4 UNCONDITIONAL_CALL caller=mov_file_is_bad@00a04480
REF 00a047d0 UNCONDITIONAL_CALL caller=mov_file_is_bad@00a04480
REF 00a04820 UNCONDITIONAL_CALL caller=mov_file_is_bad@00a04480
REF 00a04840 UNCONDITIONAL_CALL caller=mov_file_is_bad@00a04480
REF 00a04860 UNCONDITIONAL_CALL caller=mov_file_is_bad@00a04480
REF 00a0474c UNCONDITIONAL_CALL caller=mov_file_is_bad@00a04480
REF 00888dc4 UNCONDITIONAL_CALL caller=FUN_00888dac@00888dac
REF 007e86f0 UNCONDITIONAL_CALL caller=imvt_nnie_ptz_lens_flen_changed@007e8688
REF 00888224 UNCONDITIONAL_CALL caller=imvt_n3a_af_handle_lens_attach@008881a0
REF 006e9110 UNCONDITIONAL_CALL caller=FUN_006e8ee8@006e8ee8
REF 00702454 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_monitor_gaurd_multi_cam@00702310
REF 00702474 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_monitor_gaurd_multi_cam@00702310
REF 007024ac UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_monitor_gaurd_multi_cam@00702310
REF 007024cc UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_monitor_gaurd_multi_cam@00702310
REF 007024e8 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_monitor_gaurd_multi_cam@00702310
REF 00702504 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_monitor_gaurd_multi_cam@00702310
REF 00702968 UNCONDITIONAL_CALL caller=imvt_cam_controller_monitor_check_slave_status@00702890
REF 007029ec UNCONDITIONAL_CALL caller=imvt_cam_controller_monitor_check_slave_status@00702890
REF 007beeb0 UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_sync_rtc@007bee88
REF 008afcd4 UNCONDITIONAL_CALL caller=imvt_hdmi_device_hotplug_run@008afcb0
REF 006e9264 UNCONDITIONAL_CALL caller=FUN_006e9198@006e9198
REF 006e94f0 UNCONDITIONAL_CALL caller=imvt_cam_controller_file_repair@006e9430
REF 006e950c UNCONDITIONAL_CALL caller=imvt_cam_controller_file_repair@006e9430
REF 006e9774 UNCONDITIONAL_CALL caller=imvt_cam_controller_at_exit@006e9758
REF 006ea69c UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006ea800 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006ea8d4 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006ea920 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006ea9ec UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eab18 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eab44 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eab80 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eacf0 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006ead30 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006ead90 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eae7c UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eaf04 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eaf2c UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eaf84 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eafc4 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eb090 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eb1b4 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eb1cc UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eb280 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eb438 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eb4d4 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eb550 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eb5b8 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006eb634 UNCONDITIONAL_CALL caller=FUN_006ea620@006ea620
REF 006f06cc UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_icam_push@006f0608
REF 006f06fc UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_icam_push@006f0608
REF 0086d79c UNCONDITIONAL_CALL caller=imvt_cam_movie_set_timescale@0086d6f8
REF 006f9734 UNCONDITIONAL_CALL caller=imvt_cam_logo_show_from_sdcard_logo_cfg@006f96e0
REF 006f98ec UNCONDITIONAL_CALL caller=imvt_cam_logo_show_from_sdcard_logo_cfg@006f96e0
REF 006fbe04 UNCONDITIONAL_CALL caller=imvt_cam_controller_load_lens_preference_setting@006fbc68
REF 00700530 UNCONDITIONAL_CALL caller=imvt_cam_controller_config_from_storage_cfg@00700490
REF 007008d8 UNCONDITIONAL_CALL caller=imvt_cam_controller_config_from_storage_cfg@00700490
REF 0070092c UNCONDITIONAL_CALL caller=imvt_cam_controller_config_from_storage_cfg@00700490
REF 00700f00 UNCONDITIONAL_CALL caller=imvt_cam_controller_config_from_storage_cfg@00700490
REF 00701000 UNCONDITIONAL_CALL caller=imvt_cam_controller_config_from_storage_cfg@00700490
REF 00701084 UNCONDITIONAL_CALL caller=imvt_cam_controller_config_from_storage_cfg@00700490
REF 007010a8 UNCONDITIONAL_CALL caller=imvt_cam_controller_config_from_storage_cfg@00700490
REF 00701100 UNCONDITIONAL_CALL caller=imvt_cam_controller_config_from_storage_cfg@00700490
REF 00701124 UNCONDITIONAL_CALL caller=imvt_cam_controller_config_from_storage_cfg@00700490
REF 0070118c UNCONDITIONAL_CALL caller=imvt_cam_controller_config_from_storage_cfg@00700490
REF 006f6c94 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format_with_restart@006f6bf8
REF 006f6d58 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format_with_restart@006f6bf8
REF 006f6d68 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format_with_restart@006f6bf8
REF 006f6d78 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format_with_restart@006f6bf8
REF 006f6d84 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format_with_restart@006f6bf8
REF 006f6e14 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format_with_restart@006f6bf8
REF 006f6e34 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format_with_restart@006f6bf8
REF 006f6e4c UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format_with_restart@006f6bf8
REF 006f68fc UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format@006f6858
REF 006f6910 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format@006f6858
REF 006f6978 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format@006f6858
REF 006f6a00 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format@006f6858
REF 006f6b2c UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format@006f6858
REF 006f6ba0 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format@006f6858
REF 006f6bd0 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format@006f6858
REF 006f6be8 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_movie_format@006f6858
REF 006ffb78 UNCONDITIONAL_CALL caller=imvt_cam_controller_reset_setting@006ffb50
REF 006ffd84 UNCONDITIONAL_CALL caller=imvt_cam_controller_reset_setting@006ffb50
REF 006ffda4 UNCONDITIONAL_CALL caller=imvt_cam_controller_reset_setting@006ffb50
REF 006ffdd0 UNCONDITIONAL_CALL caller=imvt_cam_controller_reset_setting@006ffb50
REF 00702bd8 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_clear_setting@00702b90
REF 00888284 UNCONDITIONAL_CALL caller=imvt_n3a_af_region_show@00888230
REF 00888a90 UNCONDITIONAL_CALL caller=imvt_n3a_af_enable_mf@00888a08
REF 00888b38 UNCONDITIONAL_CALL caller=imvt_n3a_af_disable_mf@00888a98
REF 00888d1c UNCONDITIONAL_CALL caller=imvt_n3a_af_set_caf_on@00888ce0
REF 00888d3c UNCONDITIONAL_CALL caller=imvt_n3a_af_set_caf_on@00888ce0
REF 00888d7c UNCONDITIONAL_CALL caller=FUN_00888d64@00888d64
REF 00888e0c UNCONDITIONAL_CALL caller=FUN_00888df4@00888df4
REF 00888e54 UNCONDITIONAL_CALL caller=FUN_00888e3c@00888e3c
REF 007a9370 UNCONDITIONAL_CALL caller=sendMsgAddConnection@007a92f8
REF 007a9468 UNCONDITIONAL_CALL caller=sendMsgDelConnection@007a93f0
REF 007b81f4 UNCONDITIONAL_CALL caller=remountNvPartition@007b8110
REF 007bee74 UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_clear_setting@007bee60
REF 007c1880 UNCONDITIONAL_CALL caller=imvt_calib_run_calibration@007c1830
REF 007c18b4 UNCONDITIONAL_CALL caller=imvt_calib_run_calibration@007c1830
REF 007c19b0 UNCONDITIONAL_CALL caller=imvt_calib_run_calibration@007c1830
REF 007c2e08 UNCONDITIONAL_CALL caller=imvt_calib_enable_calibration@007c2db8
REF 007d4ed8 UNCONDITIONAL_CALL caller=imvt_name_rule_reelname_compute_folder_max_file_num@007d4d90
REF 007d5080 UNCONDITIONAL_CALL caller=imvt_name_rule_reelname_compute_folder_max_file_num@007d4d90
REF 007d50a8 UNCONDITIONAL_CALL caller=imvt_name_rule_reelname_compute_folder_max_file_num@007d4d90
REF 007d50c4 UNCONDITIONAL_CALL caller=imvt_name_rule_reelname_compute_folder_max_file_num@007d4d90
REF 008289ec UNCONDITIONAL_CALL caller=setDropFrame@00828968
REF 00869408 UNCONDITIONAL_CALL caller=imvt_cam_set_video_system@00869368
REF 0086944c UNCONDITIONAL_CALL caller=imvt_cam_set_video_system@00869368
REF 0086948c UNCONDITIONAL_CALL caller=imvt_cam_set_video_system@00869368
REF 00877344 UNCONDITIONAL_CALL caller=imvt_cam_audio_path_enable_speaker@008772e8
REF 008839d4 UNCONDITIONAL_CALL caller=imvt_cam_region_logo_show@008839a8
REF 00a47dcc UNCONDITIONAL_CALL caller=imvt_file_monitor_start@00a47da0
REF 00a5a7b0 UNCONDITIONAL_CALL caller=imvt_get_movie_res_by_video_system@00a5a730
REF 006edb74 UNCONDITIONAL_CALL caller=imvt_cam_controller_start_record_pre@006eda78
REF 006edcd4 UNCONDITIONAL_CALL caller=imvt_cam_controller_stop_record_post@006edc00
REF 006ee118 UNCONDITIONAL_CALL caller=io_error_cb@006ee0e8
REF 006ee184 UNCONDITIONAL_CALL caller=FUN_006ee150@006ee150
REF 006ee390 UNCONDITIONAL_CALL caller=FUN_006ee308@006ee308
REF 006eed2c UNCONDITIONAL_CALL caller=imvt_cam_controller_get_rtmp_bitrate@006eecb0
REF 006f09f0 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_mjpeg_http@006f0978
REF 006f0a34 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_mjpeg_http@006f0978
REF 007314fc UNCONDITIONAL_CALL caller=fmt_mjpeg_http_enable_push@00731488
REF 00731540 UNCONDITIONAL_CALL caller=fmt_mjpeg_http_enable_push@00731488
REF 007315a8 UNCONDITIONAL_CALL caller=fmt_mjpeg_http_enable_push@00731488
REF 006f0a8c UNCONDITIONAL_CALL caller=imvt_cam_controller_disable_mjpeg_http@006f0a40
REF 006f0ab4 UNCONDITIONAL_CALL caller=imvt_cam_controller_disable_mjpeg_http@006f0a40
REF 0073180c UNCONDITIONAL_CALL caller=fmt_mjpeg_http_disable_push@00731798
REF 00731854 UNCONDITIONAL_CALL caller=fmt_mjpeg_http_disable_push@00731798
REF 00731888 UNCONDITIONAL_CALL caller=fmt_mjpeg_http_disable_push@00731798
REF 007318cc UNCONDITIONAL_CALL caller=fmt_mjpeg_http_disable_push@00731798
REF 006f0b94 UNCONDITIONAL_CALL caller=FUN_006f0b48@006f0b48
REF 006f0dd0 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ndi_push@006f0c58
REF 006f0e30 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ndi_push@006f0c58
REF 009daa58 UNCONDITIONAL_CALL caller=fmt_ndi_muxer_enable_push@009daa18
REF 009daae0 UNCONDITIONAL_CALL caller=fmt_ndi_muxer_enable_push@009daa18
REF 009dac10 UNCONDITIONAL_CALL caller=fmt_ndi_muxer_disable_push@009daaf0
REF 006f0f00 UNCONDITIONAL_CALL caller=FUN_006f0e38@006f0e38
REF 006f0ff0 UNCONDITIONAL_CALL caller=FUN_006f0e38@006f0e38
REF 006f1034 UNCONDITIONAL_CALL caller=FUN_006f0e38@006f0e38
REF 006f1050 UNCONDITIONAL_CALL caller=FUN_006f0e38@006f0e38
REF 006f116c UNCONDITIONAL_CALL caller=imvt_cam_controller_disable_ndi_push@006f1060
REF 006f11e0 UNCONDITIONAL_CALL caller=FUN_006f1178@006f1178
REF 0086ead4 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_profile@0086ea30
REF 0086f344 UNCONDITIONAL_CALL caller=imvt_cam_movie_set_gop@0086f010
REF 0087018c UNCONDITIONAL_CALL caller=imvt_cam_movie_get_max_duration@008700f8
REF 008701cc UNCONDITIONAL_CALL caller=imvt_cam_movie_get_max_duration@008700f8
REF 0087020c UNCONDITIONAL_CALL caller=imvt_cam_movie_get_max_duration@008700f8
REF 00870224 UNCONDITIONAL_CALL caller=imvt_cam_movie_get_max_duration@008700f8
REF 0087023c UNCONDITIONAL_CALL caller=imvt_cam_movie_get_max_duration@008700f8
REF 006f3c24 UNCONDITIONAL_CALL caller=imvt_cam_controller_movie_set_prerecord_duration@006f3b78
REF 006f3e08 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ssp_push@006f3d48
REF 006f3e8c UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ssp_push@006f3d48
REF 006f3ea4 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ssp_push@006f3d48
REF 006f3f88 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ssp_push@006f3d48
REF 006f3fa0 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ssp_push@006f3d48
REF 006f3fb8 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ssp_push@006f3d48
REF 006f3fd4 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ssp_push@006f3d48
REF 006f40b8 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ssp_push@006f3d48
REF 006f40d8 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ssp_push@006f3d48
REF 006f40f0 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ssp_push@006f3d48
REF 006f4120 UNCONDITIONAL_CALL caller=imvt_cam_controller_enable_ssp_push@006f3d48
REF 0086d804 UNCONDITIONAL_CALL caller=imvt_movie_set_ssp_timecode@0086d7a8
REF 0086d874 UNCONDITIONAL_CALL caller=imvt_movie_set_ssp_timecode@0086d7a8
REF 0086d890 UNCONDITIONAL_CALL caller=imvt_movie_set_ssp_timecode@0086d7a8
REF 0086d8a8 UNCONDITIONAL_CALL caller=imvt_movie_set_ssp_timecode@0086d7a8
REF 00a17b5c UNCONDITIONAL_CALL caller=fmt_ssp_muxer_enable_push@00a17a58
REF 006f4488 UNCONDITIONAL_CALL caller=imvt_cam_controller_ssp_main_stream_enable@006f4300
REF 006f4c20 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_stream_hdr@006f4b58
REF 006f4ce8 UNCONDITIONAL_CALL caller=imvt_cam_controller_cancel_stream_hdr@006f4c30
REF 006f4d58 UNCONDITIONAL_CALL caller=imvt_cam_controller_get_sec_stream_resolution_type@006f4cf8
REF 006f5030 UNCONDITIONAL_CALL caller=imvt_cam_controller_update_sec_stream_resolution@006f4ee0
REF 006f525c UNCONDITIONAL_CALL caller=imvt_cam_controller_update_sec_stream_fps@006f5040
REF 006f5308 UNCONDITIONAL_CALL caller=imvt_cam_controller_update_sec_stream_bitwidth@006f5270
REF 006f541c UNCONDITIONAL_CALL caller=imvt_cam_controller_update_sec_stream_encoder@006f5378
REF 006f7184 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_awb_set_wb_mode@006f70e8
REF 006f71cc UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_awb_set_wb_mode@006f70e8
REF 006f7354 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_awb_set_mwb_cct@006f7288
REF 006f7764 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_ae_e_nd_auto_detect@006f76d8
REF 006f7778 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_ae_e_nd_auto_detect@006f76d8
REF 006f7794 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_ae_e_nd_auto_detect@006f76d8
REF 00a5b6d0 UNCONDITIONAL_CALL caller=n3a_config_format_e_nd_stop@00a5b648
REF 006f7848 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_ae_set_exposure_mode@006f77e0
REF 006f78d0 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_ae_set_still_shutter_speed@006f7850
REF 006f78e8 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_ae_set_still_shutter_speed@006f7850
REF 006f78fc UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_ae_set_still_shutter_speed@006f7850
REF 006f8884 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_ae_set_iso_cfg@006f8828
REF 006f8a84 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_ae_set_micro_shutter_angle@006f8a20
REF 006f8d88 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_awb_one_push_gray_chart_wb@006f8c48
REF 006f8f98 UNCONDITIONAL_CALL caller=imvt_cam_controller_n3a_awb_one_push_auto_wb@006f8d98
REF 00881994 UNCONDITIONAL_CALL caller=imvt_cam_photo_snap_video_thumbnail@00881900
REF 006fa8fc UNCONDITIONAL_CALL caller=imvt_cam_controller_set_sn@006fa858
REF 006fa910 UNCONDITIONAL_CALL caller=imvt_cam_controller_set_sn@006fa858
REF 00a3f7c4 UNCONDITIONAL_CALL caller=imvt_storage_format@00a3f6d0
REF 00a3f7fc UNCONDITIONAL_CALL caller=imvt_storage_format@00a3f6d0
REF 00a3f934 UNCONDITIONAL_CALL caller=imvt_storage_format@00a3f6d0
REF 00a3f994 UNCONDITIONAL_CALL caller=imvt_storage_format@00a3f6d0
REF 00a3c930 UNCONDITIONAL_CALL caller=FUN_00a3c788@00a3c788
REF 00a3c9b8 UNCONDITIONAL_CALL caller=FUN_00a3c788@00a3c788
REF 00a3d27c UNCONDITIONAL_CALL caller=FUN_00a3d170@00a3d170
REF 00a3d2d0 UNCONDITIONAL_CALL caller=FUN_00a3d170@00a3d170
REF 00a3d3a4 UNCONDITIONAL_CALL caller=FUN_00a3d170@00a3d170
REF 00a3d3cc UNCONDITIONAL_CALL caller=FUN_00a3d170@00a3d170
REF 00a3d400 UNCONDITIONAL_CALL caller=FUN_00a3d170@00a3d170
REF 00a3d41c UNCONDITIONAL_CALL caller=FUN_00a3d170@00a3d170
REF 00a3d438 UNCONDITIONAL_CALL caller=FUN_00a3d170@00a3d170
REF 00a3d450 UNCONDITIONAL_CALL caller=FUN_00a3d170@00a3d170
REF 00a3d480 UNCONDITIONAL_CALL caller=FUN_00a3d170@00a3d170
REF 00a3d4c4 UNCONDITIONAL_CALL caller=FUN_00a3d170@00a3d170
REF 00a3d4f8 UNCONDITIONAL_CALL caller=FUN_00a3d170@00a3d170
REF 00a3d524 UNCONDITIONAL_CALL caller=FUN_00a3d170@00a3d170
REF 00a3fd10 UNCONDITIONAL_CALL caller=imvt_storage_secure_erase_format@00a3fca8
REF 00a3fda0 UNCONDITIONAL_CALL caller=imvt_storage_secure_erase_format@00a3fca8
REF 00a3fdc0 UNCONDITIONAL_CALL caller=imvt_storage_secure_erase_format@00a3fca8
REF 0087cd88 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info@0087ccc8
REF 0087cdb0 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info@0087ccc8
REF 0087cdd8 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_info@0087ccc8
REF 006fb3ac UNCONDITIONAL_CALL caller=imvt_cam_controller_set_hdmi_output_resolution@006fb230
REF 006fb958 UNCONDITIONAL_CALL caller=imvt_cam_lvds_crop_position_set@006fb728
REF 006fb9d4 UNCONDITIONAL_CALL caller=imvt_cam_lvds_crop_position_set@006fb728
REF 006fba04 UNCONDITIONAL_CALL caller=imvt_cam_lvds_crop_position_set@006fb728
REF 00888bfc UNCONDITIONAL_CALL caller=imvt_n3a_af_focus@00888bb0
REF 00888c1c UNCONDITIONAL_CALL caller=imvt_n3a_af_focus@00888bb0
REF 00888c34 UNCONDITIONAL_CALL caller=imvt_n3a_af_focus@00888bb0
REF 006fda60 UNCONDITIONAL_CALL caller=imvt_cam_controller_get_is_dead_battery@006fd9a8
REF 006fdd50 UNCONDITIONAL_CALL caller=imvt_cam_controller_write_volume_lable@006fdcc8
REF 008209d4 UNCONDITIONAL_CALL caller=wifi_sta_init@00820850
REF 00820a04 UNCONDITIONAL_CALL caller=wifi_sta_init@00820850
REF 00820a3c UNCONDITIONAL_CALL caller=wifi_sta_init@00820850
REF 00820a64 UNCONDITIONAL_CALL caller=wifi_sta_init@00820850
REF 00820a84 UNCONDITIONAL_CALL caller=wifi_sta_init@00820850
REF 00820a98 UNCONDITIONAL_CALL caller=wifi_sta_init@00820850
REF 00820aa8 UNCONDITIONAL_CALL caller=wifi_sta_init@00820850
REF 00820abc UNCONDITIONAL_CALL caller=wifi_sta_init@00820850
REF 00820ad4 UNCONDITIONAL_CALL caller=wifi_sta_init@00820850
REF 0081fed8 UNCONDITIONAL_CALL caller=wifi_scan@0081fdf8
REF 0081fef4 UNCONDITIONAL_CALL caller=wifi_scan@0081fdf8
REF 0081eaac UNCONDITIONAL_CALL caller=FUN_0081e9e8@0081e9e8
REF 0081eac4 UNCONDITIONAL_CALL caller=FUN_0081e9e8@0081e9e8
REF 00821ad4 UNCONDITIONAL_CALL caller=wifi_sta_connect_ap@008219d8
REF 00821af4 UNCONDITIONAL_CALL caller=wifi_sta_connect_ap@008219d8
REF 00821b0c UNCONDITIONAL_CALL caller=wifi_sta_connect_ap@008219d8
REF 0081ef20 UNCONDITIONAL_CALL caller=FUN_0081edd8@0081edd8
REF 0081effc UNCONDITIONAL_CALL caller=FUN_0081ef38@0081ef38
REF 0081f558 UNCONDITIONAL_CALL caller=wifi_select_network@0081f438
REF 0081f574 UNCONDITIONAL_CALL caller=wifi_select_network@0081f438
REF 0081f9b0 UNCONDITIONAL_CALL caller=wifi_select_ap@0081f850
REF 0081fb68 UNCONDITIONAL_CALL caller=wifi_select_ap@0081f850
REF 0081fba0 UNCONDITIONAL_CALL caller=wifi_select_ap@0081f850
REF 0081fc00 UNCONDITIONAL_CALL caller=wifi_select_ap@0081f850
REF 0081fc20 UNCONDITIONAL_CALL caller=wifi_select_ap@0081f850
REF 0081fc40 UNCONDITIONAL_CALL caller=wifi_select_ap@0081f850
REF 0081fc60 UNCONDITIONAL_CALL caller=wifi_select_ap@0081f850
REF 0081fc80 UNCONDITIONAL_CALL caller=wifi_select_ap@0081f850
REF 0081fca0 UNCONDITIONAL_CALL caller=wifi_select_ap@0081f850
REF 0081f670 UNCONDITIONAL_CALL caller=wifi_delete_network@0081f588
REF 0081f68c UNCONDITIONAL_CALL caller=wifi_delete_network@0081f588
REF 00821158 UNCONDITIONAL_CALL caller=wifi_is_network_pswd_enterd@00821048
REF 00820eb4 UNCONDITIONAL_CALL caller=wifi_get_all_ap_password_was_entered@00820dc0
REF 00820ed4 UNCONDITIONAL_CALL caller=wifi_get_all_ap_password_was_entered@00820dc0
REF 00820efc UNCONDITIONAL_CALL caller=wifi_get_all_ap_password_was_entered@00820dc0
REF 00820f18 UNCONDITIONAL_CALL caller=wifi_get_all_ap_password_was_entered@00820dc0
REF 00820f30 UNCONDITIONAL_CALL caller=wifi_get_all_ap_password_was_entered@00820dc0
REF 00820f50 UNCONDITIONAL_CALL caller=wifi_get_all_ap_password_was_entered@00820dc0
REF 006fe290 UNCONDITIONAL_CALL caller=imvt_cam_controller_update_volume_lable@006fe1d8
REF 006fe2c4 UNCONDITIONAL_CALL caller=imvt_cam_controller_update_volume_lable@006fe1d8
REF 006fe2e0 UNCONDITIONAL_CALL caller=imvt_cam_controller_update_volume_lable@006fe1d8
REF 006fe360 UNCONDITIONAL_CALL caller=imvt_cam_controller_liveview_set_flip@006fe310
REF 0070171c UNCONDITIONAL_CALL caller=FUN_007015d0@007015d0
REF 00701880 UNCONDITIONAL_CALL caller=FUN_00701790@00701790
REF 0070189c UNCONDITIONAL_CALL caller=FUN_00701790@00701790
REF 00873a08 UNCONDITIONAL_CALL caller=imvt_multiple_control_set_req_gpio@008739e8
REF 00873a40 UNCONDITIONAL_CALL caller=imvt_multiple_control_set_ack_gpio@00873a20
REF 007031e0 UNCONDITIONAL_CALL caller=FUN_00703030@00703030
REF 00703218 UNCONDITIONAL_CALL caller=FUN_00703030@00703030
REF 00703228 UNCONDITIONAL_CALL caller=FUN_00703030@00703030
REF 0070323c UNCONDITIONAL_CALL caller=FUN_00703030@00703030
REF 0070325c UNCONDITIONAL_CALL caller=FUN_00703030@00703030
REF 00703658 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_net_sync_get_rejoin_info@00703518
REF 007036c0 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_net_sync_get_rejoin_info@00703518
REF 00703e2c UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_net_sync_start_rec_async@00703db0
REF 007039c8 UNCONDITIONAL_CALL caller=FUN_00703890@00703890
REF 0070400c UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_net_sync_set_trigger_ts@00703f30
REF 00704024 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_net_sync_set_trigger_ts@00703f30
REF 0070403c UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_net_sync_set_trigger_ts@00703f30
REF 00704054 UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_net_sync_set_trigger_ts@00703f30
REF 0080775c UNCONDITIONAL_CALL caller=gl_image_process_destroy@00807738
REF 008078c8 UNCONDITIONAL_CALL caller=gl_image_process_destroy@00807738
REF 0080381c UNCONDITIONAL_CALL caller=FUN_008037d0@008037d0
REF 00803a00 UNCONDITIONAL_CALL caller=FUN_008038a0@008038a0
REF 00803a20 UNCONDITIONAL_CALL caller=FUN_008038a0@008038a0
REF 00803a3c UNCONDITIONAL_CALL caller=FUN_008038a0@008038a0
REF 008041f4 UNCONDITIONAL_CALL caller=FUN_008040a0@008040a0
REF 00803890 UNCONDITIONAL_CALL caller=FUN_00803830@00803830
REF 00806fdc UNCONDITIONAL_CALL caller=gl_image_process_handle_video_frame@00806e90
REF 00807144 UNCONDITIONAL_CALL caller=gl_image_process_handle_video_frame@00806e90
REF 008066f4 UNCONDITIONAL_CALL caller=gl_gpu_process_handle_yuv_data@00806690
REF 00806898 UNCONDITIONAL_CALL caller=gl_gpu_process_handle_yuv_data@00806690
REF 0083b468 UNCONDITIONAL_CALL caller=gl_util_create_native_pixmap@0083b2f0
REF 0083b248 UNCONDITIONAL_CALL caller=FUN_0083b1a8@0083b1a8
REF 00807448 UNCONDITIONAL_CALL caller=gl_image_process_create@008071a0
REF 008076b0 UNCONDITIONAL_CALL caller=gl_image_process_create@008071a0
REF 0083b924 UNCONDITIONAL_CALL caller=gl_util_create_shader_program@0083b7f8
REF 0083b28c UNCONDITIONAL_CALL caller=FUN_0083b258@0083b258
REF 0083b6b8 UNCONDITIONAL_CALL caller=gl_util_create_shader@0083b5d0
REF 0083ba4c UNCONDITIONAL_CALL caller=gl_util_create_ogl_context@0083b958
REF 0083bb34 UNCONDITIONAL_CALL caller=gl_util_create_ogl_context@0083b958
REF 0083bb54 UNCONDITIONAL_CALL caller=gl_util_create_ogl_context@0083b958
REF 0083bb6c UNCONDITIONAL_CALL caller=gl_util_create_ogl_context@0083b958
REF 0083bb84 UNCONDITIONAL_CALL caller=gl_util_create_ogl_context@0083b958
REF 0083bb9c UNCONDITIONAL_CALL caller=gl_util_create_ogl_context@0083b958
REF 0083bbb0 UNCONDITIONAL_CALL caller=gl_util_create_ogl_context@0083b958
REF 0083bbc0 UNCONDITIONAL_CALL caller=gl_util_create_ogl_context@0083b958
REF 0083bbd4 UNCONDITIONAL_CALL caller=gl_util_create_ogl_context@0083b958
REF 0083b18c UNCONDITIONAL_CALL caller=FUN_0083b158@0083b158
REF 00707b24 UNCONDITIONAL_CALL caller=FUN_00707b10@00707b10
REF 00707b54 UNCONDITIONAL_CALL caller=FUN_00707b38@00707b38
REF 00707b84 UNCONDITIONAL_CALL caller=FUN_00707b68@00707b68
REF 00707bb4 UNCONDITIONAL_CALL caller=FUN_00707b98@00707b98
REF 00707bec UNCONDITIONAL_CALL caller=FUN_00707bc8@00707bc8
REF 007084d4 UNCONDITIONAL_CALL caller=FUN_00708480@00708480
REF 0070853c UNCONDITIONAL_CALL caller=FUN_007084e8@007084e8
REF 007087e0 UNCONDITIONAL_CALL caller=FUN_007087c0@007087c0
REF 00733980 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_get_fps@00733858
REF 007330c4 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_get_resolution@00732f78
REF 007330e8 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_get_resolution@00732f78
REF 00733108 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_get_resolution@00732f78
REF 00733e84 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_get_video_encoder@00733de0
REF 00733e9c UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_get_video_encoder@00733de0
REF 00733c78 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_set_video_encoder@00733b80
REF 00733c98 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_set_video_encoder@00733b80
REF 00733cb8 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_set_video_encoder@00733b80
REF 00709aec UNCONDITIONAL_CALL caller=FUN_007099f8@007099f8
REF 00709b04 UNCONDITIONAL_CALL caller=FUN_007099f8@007099f8
REF 0070a848 UNCONDITIONAL_CALL caller=FUN_0070a730@0070a730
REF 0070b194 UNCONDITIONAL_CALL caller=FUN_0070b130@0070b130
REF 0070b284 UNCONDITIONAL_CALL caller=FUN_0070b218@0070b218
REF 0070b738 UNCONDITIONAL_CALL caller=FUN_0070b6c8@0070b6c8
REF 0070bd94 UNCONDITIONAL_CALL caller=FUN_0070bcf0@0070bcf0
REF 00888b9c UNCONDITIONAL_CALL caller=imvt_n3a_af_is_af_prohibited@00888b50
REF 0070c274 UNCONDITIONAL_CALL caller=FUN_0070c1b8@0070c1b8
REF 0070c414 UNCONDITIONAL_CALL caller=FUN_0070c280@0070c280
REF 0070c950 UNCONDITIONAL_CALL caller=FUN_0070c860@0070c860
REF 0070ca2c UNCONDITIONAL_CALL caller=FUN_0070c860@0070c860
REF 0070cab0 UNCONDITIONAL_CALL caller=FUN_0070ca40@0070ca40
REF 0070d390 UNCONDITIONAL_CALL caller=FUN_0070d2e0@0070d2e0
REF 0070d440 UNCONDITIONAL_CALL caller=FUN_0070d3a0@0070d3a0
REF 008890dc UNCONDITIONAL_CALL caller=imvt_n3a_af_lock@00889088
REF 00889154 UNCONDITIONAL_CALL caller=imvt_n3a_af_unlock@00889110
REF 0070da54 UNCONDITIONAL_CALL caller=FUN_0070d990@0070d990
REF 0070dca0 UNCONDITIONAL_CALL caller=FUN_0070dc18@0070dc18
REF 0070dd54 UNCONDITIONAL_CALL caller=FUN_0070dce0@0070dce0
REF 0070de08 UNCONDITIONAL_CALL caller=FUN_0070ddec@0070ddec
REF 0070def8 UNCONDITIONAL_CALL caller=FUN_0070dec0@0070dec0
REF 0070df40 UNCONDITIONAL_CALL caller=FUN_0070df08@0070df08
REF 0070df9c UNCONDITIONAL_CALL caller=FUN_0070df50@0070df50
REF 00869bf8 UNCONDITIONAL_CALL caller=imvt_cam_crop_position_get@00869b50
REF 00869c10 UNCONDITIONAL_CALL caller=imvt_cam_crop_position_get@00869b50
REF 00869c30 UNCONDITIONAL_CALL caller=imvt_cam_crop_position_get@00869b50
REF 00869c50 UNCONDITIONAL_CALL caller=imvt_cam_crop_position_get@00869b50
REF 00869cb4 UNCONDITIONAL_CALL caller=imvt_cam_crop_position_get@00869b50
REF 0070e094 UNCONDITIONAL_CALL caller=FUN_0070dff0@0070dff0
REF 0070e0b0 UNCONDITIONAL_CALL caller=FUN_0070dff0@0070dff0
REF 00869a2c UNCONDITIONAL_CALL caller=imvt_cam_crop_position_set@00869808
REF 00869aac UNCONDITIONAL_CALL caller=imvt_cam_crop_position_set@00869808
REF 00869acc UNCONDITIONAL_CALL caller=imvt_cam_crop_position_set@00869808
REF 00869aec UNCONDITIONAL_CALL caller=imvt_cam_crop_position_set@00869808
REF 00869b0c UNCONDITIONAL_CALL caller=imvt_cam_crop_position_set@00869808
REF 00869b3c UNCONDITIONAL_CALL caller=imvt_cam_crop_position_set@00869808
REF 0070e5a8 UNCONDITIONAL_CALL caller=FUN_0070e450@0070e450
REF 0070e6cc UNCONDITIONAL_CALL caller=FUN_0070e450@0070e450
REF 0070e838 UNCONDITIONAL_CALL caller=FUN_0070e758@0070e758
REF 0070e854 UNCONDITIONAL_CALL caller=FUN_0070e758@0070e758
REF 0070e870 UNCONDITIONAL_CALL caller=FUN_0070e758@0070e758
REF 0070edf4 UNCONDITIONAL_CALL caller=FUN_0070ed50@0070ed50
REF 0070ef90 UNCONDITIONAL_CALL caller=FUN_0070ed50@0070ed50
REF 0070f010 UNCONDITIONAL_CALL caller=FUN_0070ed50@0070ed50
REF 00889024 UNCONDITIONAL_CALL caller=FUN_0088900c@0088900c
REF 0070f3c4 UNCONDITIONAL_CALL caller=FUN_0070f358@0070f358
REF 0070f6f4 UNCONDITIONAL_CALL caller=FUN_0070f618@0070f618
REF 0070f8b4 UNCONDITIONAL_CALL caller=FUN_0070f7d8@0070f7d8
REF 0070f978 UNCONDITIONAL_CALL caller=FUN_0070f940@0070f940
REF 00888c74 UNCONDITIONAL_CALL caller=FUN_00888c5c@00888c5c
REF 0070ffd8 UNCONDITIONAL_CALL caller=FUN_0070ff70@0070ff70
REF 00710134 UNCONDITIONAL_CALL caller=FUN_007100d8@007100d8
REF 007101b8 UNCONDITIONAL_CALL caller=FUN_00710140@00710140
REF 007101f8 UNCONDITIONAL_CALL caller=FUN_00710140@00710140
REF 008af69c UNCONDITIONAL_CALL caller=pipeline_format_get_vo_res_by_video_system@008af5f8
REF 00710cb0 UNCONDITIONAL_CALL caller=FUN_00710a08@00710a08
REF 00711644 UNCONDITIONAL_CALL caller=FUN_00711510@00711510
REF 00a3e61c UNCONDITIONAL_CALL caller=imvt_app_storage_mgr_is_optimized_card_format@00a3e580
REF 00712d7c UNCONDITIONAL_CALL caller=FUN_00712ca8@00712ca8
REF 00712e78 UNCONDITIONAL_CALL caller=FUN_00712e08@00712e08
REF 00713098 UNCONDITIONAL_CALL caller=FUN_00712ff0@00712ff0
REF 0071312c UNCONDITIONAL_CALL caller=FUN_007130a8@007130a8
REF 0071320c UNCONDITIONAL_CALL caller=FUN_00713140@00713140
REF 00888ea4 UNCONDITIONAL_CALL caller=FUN_00888e8c@00888e8c
REF 0071344c UNCONDITIONAL_CALL caller=FUN_007133b8@007133b8
REF 00713b48 UNCONDITIONAL_CALL caller=FUN_00713a90@00713a90
REF 00713c1c UNCONDITIONAL_CALL caller=FUN_00713b80@00713b80
REF 00713d28 UNCONDITIONAL_CALL caller=FUN_00713c30@00713c30
REF 00713f0c UNCONDITIONAL_CALL caller=FUN_00713e18@00713e18
REF 0071469c UNCONDITIONAL_CALL caller=FUN_00714668@00714668
REF 00714a08 UNCONDITIONAL_CALL caller=FUN_00714978@00714978
REF 00714d8c UNCONDITIONAL_CALL caller=FUN_00714d78@00714d78
REF 00714db4 UNCONDITIONAL_CALL caller=FUN_00714da0@00714da0
REF 00714ddc UNCONDITIONAL_CALL caller=FUN_00714dc8@00714dc8
REF 007159f4 UNCONDITIONAL_CALL caller=FUN_007157e8@007157e8
REF 00715a74 UNCONDITIONAL_CALL caller=FUN_007157e8@007157e8
REF 00715b6c UNCONDITIONAL_CALL caller=FUN_00715a80@00715a80
REF 00715e9c UNCONDITIONAL_CALL caller=FUN_00715d58@00715d58
REF 00715ed0 UNCONDITIONAL_CALL caller=FUN_00715d58@00715d58
REF 00868de8 UNCONDITIONAL_CALL caller=imvt_cam_opmode_set_player_instance_num@00868dc8
REF 0072b688 UNCONDITIONAL_CALL caller=startRecordComp@0072b570
REF 0072b6e0 UNCONDITIONAL_CALL caller=startRecordComp@0072b570
REF 0072b93c UNCONDITIONAL_CALL caller=pauseRecordingComp@0072b918
REF 0072b98c UNCONDITIONAL_CALL caller=isRecordingPausedComp@0072b968
REF 0072b9dc UNCONDITIONAL_CALL caller=resumeRecordingComp@0072b9b8
REF 0072bb60 UNCONDITIONAL_CALL caller=startTimelapseVideoRecordingComp@0072bad0
REF 0072bc8c UNCONDITIONAL_CALL caller=setMovieConfigComp@0072bc40
REF 0072c074 UNCONDITIONAL_CALL caller=setGopComp@0072c020
REF 007bef00 UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_sync_movie_reel_name@007beee8
REF 0072c634 UNCONDITIONAL_CALL caller=captureComp@0072c5a8
REF 008817f8 UNCONDITIONAL_CALL caller=imvt_cam_photo_start_burst@00881780
REF 0072d13c UNCONDITIONAL_CALL caller=playbackSetUrlComp@0072cf20
REF 0087d748 UNCONDITIONAL_CALL caller=imvt_cam_playback_is_surpport@0087d6d8
REF 0087d770 UNCONDITIONAL_CALL caller=imvt_cam_playback_is_surpport@0087d6d8
REF 0087f0a8 UNCONDITIONAL_CALL caller=imvt_cam_playback_set_url@0087f030
REF 0087fa84 UNCONDITIONAL_CALL caller=imvt_cam_playback_set_url@0087f030
REF 0087facc UNCONDITIONAL_CALL caller=imvt_cam_playback_set_url@0087f030
REF 0087dc54 UNCONDITIONAL_CALL caller=imvt_cam_playback_start@0087dbe0
REF 0087dca4 UNCONDITIONAL_CALL caller=imvt_cam_playback_start@0087dbe0
REF 0087dd4c UNCONDITIONAL_CALL caller=imvt_cam_playback_start@0087dbe0
REF 0087dd74 UNCONDITIONAL_CALL caller=imvt_cam_playback_start@0087dbe0
REF 0087dd90 UNCONDITIONAL_CALL caller=imvt_cam_playback_start@0087dbe0
REF 0087de04 UNCONDITIONAL_CALL caller=imvt_cam_playback_pause@0087dda0
REF 0087de7c UNCONDITIONAL_CALL caller=imvt_cam_playback_pause@0087dda0
REF 0087deb4 UNCONDITIONAL_CALL caller=imvt_cam_playback_pause@0087dda0
REF 0087dedc UNCONDITIONAL_CALL caller=imvt_cam_playback_pause@0087dda0
REF 008c7ca4 UNCONDITIONAL_CALL caller=pause@008c7c38
REF 0087df44 UNCONDITIONAL_CALL caller=imvt_cam_playback_resume@0087dee8
REF 0087dfbc UNCONDITIONAL_CALL caller=imvt_cam_playback_resume@0087dee8
REF 0087dff4 UNCONDITIONAL_CALL caller=imvt_cam_playback_resume@0087dee8
REF 0087e01c UNCONDITIONAL_CALL caller=imvt_cam_playback_resume@0087dee8
REF 008c7c0c UNCONDITIONAL_CALL caller=resume@008c7ba0
REF 0087e5e4 UNCONDITIONAL_CALL caller=imvt_cam_playback_seek_to@0087e4b8
REF 0087e60c UNCONDITIONAL_CALL caller=imvt_cam_playback_seek_to@0087e4b8
REF 0087e208 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_speed@0087e180
REF 0087e230 UNCONDITIONAL_CALL caller=imvt_cam_playback_get_speed@0087e180
REF 0087e2fc UNCONDITIONAL_CALL caller=imvt_cam_playback_set_fastforword@0087e240
REF 0087e324 UNCONDITIONAL_CALL caller=imvt_cam_playback_set_fastforword@0087e240
REF 008cc3c0 UNCONDITIONAL_CALL caller=setPlaySpeed@008cc2c8
REF 008cc0d8 UNCONDITIONAL_CALL caller=setTimer@008cc030
REF 008cc2a8 UNCONDITIONAL_CALL caller=updateVideoTimerforSpeed@008cc158
REF 0087e3ec UNCONDITIONAL_CALL caller=imvt_cam_playback_set_fastbackword@0087e330
REF 0087e414 UNCONDITIONAL_CALL caller=imvt_cam_playback_set_fastbackword@0087e330
REF 0087d698 UNCONDITIONAL_CALL caller=imvt_cam_playback_total_time@0087d610
REF 0087d6c0 UNCONDITIONAL_CALL caller=imvt_cam_playback_total_time@0087d610
REF 0087e6b8 UNCONDITIONAL_CALL caller=imvt_cam_playback_set_play_speed@0087e618
REF 0087e6e0 UNCONDITIONAL_CALL caller=imvt_cam_playback_set_play_speed@0087e618
REF 0087e708 UNCONDITIONAL_CALL caller=imvt_cam_playback_set_play_speed@0087e618
REF 0087e804 UNCONDITIONAL_CALL caller=imvt_cam_playback_forward_frame@0087e718
REF 0087e82c UNCONDITIONAL_CALL caller=imvt_cam_playback_forward_frame@0087e718
REF 0087e924 UNCONDITIONAL_CALL caller=imvt_cam_playback_backward_frame@0087e838
REF 0087e94c UNCONDITIONAL_CALL caller=imvt_cam_playback_backward_frame@0087e838
REF 0072d89c UNCONDITIONAL_CALL caller=isOptimizedCardFormatComp@0072d7c8
REF 0072dd3c UNCONDITIONAL_CALL caller=powerdownComp@0072dd18
REF 0072dd8c UNCONDITIONAL_CALL caller=rebootComp@0072dd68
REF 0072dddc UNCONDITIONAL_CALL caller=doUpgradeComp@0072ddb8
REF 00888ccc UNCONDITIONAL_CALL caller=imvt_n3a_af_cancel_saf@00888c88
REF 007b3890 UNCONDITIONAL_CALL caller=getLastCmd@007b3830
REF 007bf3d8 UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_check_record_remain@007bf390
REF 007bd1c8 UNCONDITIONAL_CALL caller=doFactoryEthTest@007bd088
REF 007bd1e4 UNCONDITIONAL_CALL caller=doFactoryEthTest@007bd088
REF 007bd200 UNCONDITIONAL_CALL caller=doFactoryEthTest@007bd088
REF 007bd37c UNCONDITIONAL_CALL caller=doFactoryLensTest@007bd248
REF 007bc34c UNCONDITIONAL_CALL caller=FUN_007bc2f8@007bc2f8
REF 0072fd30 UNCONDITIONAL_CALL caller=getCropPositionComp@0072fce8
REF 0072fd8c UNCONDITIONAL_CALL caller=getCropPositionComp@0072fce8
REF 0072fe10 UNCONDITIONAL_CALL caller=setCropPositionComp@0072fdb0
REF 0072fe74 UNCONDITIONAL_CALL caller=setCropPositionComp@0072fdb0
REF 0072febc UNCONDITIONAL_CALL caller=setCropPositionComp@0072fdb0
REF 0072fed8 UNCONDITIONAL_CALL caller=setCropPositionComp@0072fdb0
REF 0072fefc UNCONDITIONAL_CALL caller=setCropPositionComp@0072fdb0
REF 007c2f8c UNCONDITIONAL_CALL caller=FUN_007c2f28@007c2f28
REF 007c2fa8 UNCONDITIONAL_CALL caller=FUN_007c2f28@007c2f28
REF 007c2ffc UNCONDITIONAL_CALL caller=FUN_007c2f28@007c2f28
REF 007c3098 UNCONDITIONAL_CALL caller=FUN_007c2f28@007c2f28
REF 007c30b4 UNCONDITIONAL_CALL caller=FUN_007c2f28@007c2f28
REF 007c30d0 UNCONDITIONAL_CALL caller=FUN_007c2f28@007c2f28
REF 00736504 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_set_param@00736188
REF 00736524 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_set_param@00736188
REF 009d9164 UNCONDITIONAL_CALL caller=ndi_server_get_ndi_param@009d90f8
REF 008886f4 UNCONDITIONAL_CALL caller=imvt_n3a_af_set_face_roi@00888548
REF 00888f44 UNCONDITIONAL_CALL caller=FUN_00888f2c@00888f2c
REF 00730ab4 UNCONDITIONAL_CALL caller=imvt_af_focus_inf@00730a98
REF 008889a8 UNCONDITIONAL_CALL caller=imvt_n3a_af_get_focus_point@00888850
REF 00730d74 UNCONDITIONAL_CALL caller=FUN_00730cf0@00730cf0
REF 00730d90 UNCONDITIONAL_CALL caller=FUN_00730cf0@00730cf0
REF 00730ec4 UNCONDITIONAL_CALL caller=FUN_00730db8@00730db8
REF 00730ee4 UNCONDITIONAL_CALL caller=FUN_00730db8@00730db8
REF 00730efc UNCONDITIONAL_CALL caller=FUN_00730db8@00730db8
REF 00730f14 UNCONDITIONAL_CALL caller=FUN_00730db8@00730db8
REF 00746bdc UNCONDITIONAL_CALL caller=write@00746b50
REF 00731098 UNCONDITIONAL_CALL caller=FUN_00730f20@00730f20
REF 00731120 UNCONDITIONAL_CALL caller=FUN_00730f20@00730f20
REF 00731140 UNCONDITIONAL_CALL caller=FUN_00730f20@00730f20
REF 00731158 UNCONDITIONAL_CALL caller=FUN_00730f20@00730f20
REF 00731178 UNCONDITIONAL_CALL caller=FUN_00730f20@00730f20
REF 00731190 UNCONDITIONAL_CALL caller=FUN_00730f20@00730f20
REF 007311b0 UNCONDITIONAL_CALL caller=FUN_00730f20@00730f20
REF 007311c8 UNCONDITIONAL_CALL caller=FUN_00730f20@00730f20
REF 007311f0 UNCONDITIONAL_CALL caller=FUN_00730f20@00730f20
REF 00731204 UNCONDITIONAL_CALL caller=FUN_00730f20@00730f20
REF 008837bc UNCONDITIONAL_CALL caller=imvt_cam_region_osd_draw_msg@00883768
REF 008837e0 UNCONDITIONAL_CALL caller=imvt_cam_region_osd_draw_msg@00883768
REF 008837f8 UNCONDITIONAL_CALL caller=imvt_cam_region_osd_draw_msg@00883768
REF 0088383c UNCONDITIONAL_CALL caller=imvt_cam_region_osd_show@00883800
REF 0088385c UNCONDITIONAL_CALL caller=imvt_cam_region_osd_show@00883800
REF 00733aa8 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_init_fps@00733990
REF 00733ad4 UNCONDITIONAL_CALL caller=imvt_cam_controller_stream_init_fps@00733990
REF 00734b9c UNCONDITIONAL_CALL caller=FUN_00734aa0@00734aa0
REF 00734c00 UNCONDITIONAL_CALL caller=FUN_00734aa0@00734aa0
REF 00734c1c UNCONDITIONAL_CALL caller=FUN_00734aa0@00734aa0
REF 00734c38 UNCONDITIONAL_CALL caller=FUN_00734aa0@00734aa0
REF 00734c58 UNCONDITIONAL_CALL caller=FUN_00734aa0@00734aa0
REF 00734dd4 UNCONDITIONAL_CALL caller=FUN_00734c68@00734c68
REF 00734f6c UNCONDITIONAL_CALL caller=FUN_00734c68@00734c68
REF 00734f98 UNCONDITIONAL_CALL caller=FUN_00734c68@00734c68
REF 00735064 UNCONDITIONAL_CALL caller=FUN_00734c68@00734c68
REF 00735088 UNCONDITIONAL_CALL caller=FUN_00734c68@00734c68
REF 007350a8 UNCONDITIONAL_CALL caller=FUN_00734c68@00734c68
REF 007350d8 UNCONDITIONAL_CALL caller=FUN_00734c68@00734c68
REF 0073510c UNCONDITIONAL_CALL caller=FUN_00734c68@00734c68
REF 007351fc UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_set_machine_name@00735120
REF 0073521c UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_set_machine_name@00735120
REF 0073523c UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_set_machine_name@00735120
REF 00735448 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_set_stream_name@00735368
REF 00735464 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_set_stream_name@00735368
REF 00735484 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_set_stream_name@00735368
REF 007354a4 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_set_stream_name@00735368
REF 00735714 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_set_group_name@00735638
REF 00735734 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_set_group_name@00735638
REF 00735754 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_set_group_name@00735638
REF 00736110 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_disable_push@007360d8
REF 00736168 UNCONDITIONAL_CALL caller=imvt_cam_controller_ndi_enable_push@00736130
REF 009d8c84 UNCONDITIONAL_CALL caller=ndi_server_enable_push@009d8bb0
REF 009d8ca0 UNCONDITIONAL_CALL caller=ndi_server_enable_push@009d8bb0
REF 009d8cbc UNCONDITIONAL_CALL caller=ndi_server_enable_push@009d8bb0
REF 009d8cf4 UNCONDITIONAL_CALL caller=ndi_server_enable_push@009d8bb0
REF 009d8d14 UNCONDITIONAL_CALL caller=ndi_server_enable_push@009d8bb0
REF 009d8d44 UNCONDITIONAL_CALL caller=ndi_server_enable_push@009d8bb0
REF 009d8d64 UNCONDITIONAL_CALL caller=ndi_server_enable_push@009d8bb0
REF 007368c8 UNCONDITIONAL_CALL caller=handleWriteData@007367f8
REF 007368f4 UNCONDITIONAL_CALL caller=handleWriteData@007367f8
REF 007387f4 UNCONDITIONAL_CALL caller=permissionHandler@007382e0
REF 00776eec UNCONDITIONAL_CALL caller=closeConnectionAtExit@00776e68
REF 0073b1e4 UNCONDITIONAL_CALL caller=FUN_0073b158@0073b158
REF 0073c1fc UNCONDITIONAL_CALL caller=FUN_0073c0f0@0073c0f0
REF 0073c3b4 UNCONDITIONAL_CALL caller=FUN_0073c0f0@0073c0f0
REF 0073c43c UNCONDITIONAL_CALL caller=FUN_0073c0f0@0073c0f0
REF 007466e8 UNCONDITIONAL_CALL caller=init@00746650
REF 0074670c UNCONDITIONAL_CALL caller=init@00746650
REF 00746734 UNCONDITIONAL_CALL caller=init@00746650
REF 0074675c UNCONDITIONAL_CALL caller=init@00746650
REF 00746784 UNCONDITIONAL_CALL caller=init@00746650
REF 00752b24 UNCONDITIONAL_CALL caller=handleWriteData@00752a80
REF 00752c3c UNCONDITIONAL_CALL caller=handleWriteData@00752a80
REF 00752c60 UNCONDITIONAL_CALL caller=handleWriteData@00752a80
REF 00752c90 UNCONDITIONAL_CALL caller=handleWriteData@00752a80
REF 00752e24 UNCONDITIONAL_CALL caller=handleListFodler@00752d50
REF 00774a4c UNCONDITIONAL_CALL caller=dump@00774a08
REF 00774a60 UNCONDITIONAL_CALL caller=dump@00774a08
REF 0075d070 UNCONDITIONAL_CALL caller=sessionTimeout@0075d040
REF 0075d140 UNCONDITIONAL_CALL caller=FUN_0075d0e8@0075d0e8
REF 0075d17c UNCONDITIONAL_CALL caller=FUN_0075d0e8@0075d0e8
REF 007621b0 UNCONDITIONAL_CALL caller=handleUiHint@00762068
REF 00762214 UNCONDITIONAL_CALL caller=handleShutdown@007621c8
REF 00762250 UNCONDITIONAL_CALL caller=handleShutdown@007621c8
REF 00762280 UNCONDITIONAL_CALL caller=handleShutdown@007621c8
REF 007622a0 UNCONDITIONAL_CALL caller=handleShutdown@007621c8
REF 007622b4 UNCONDITIONAL_CALL caller=handleShutdown@007621c8
REF 00762354 UNCONDITIONAL_CALL caller=handleReboot@00762308
REF 007623a0 UNCONDITIONAL_CALL caller=handleReboot@00762308
REF 007623c0 UNCONDITIONAL_CALL caller=handleReboot@00762308
REF 007623d4 UNCONDITIONAL_CALL caller=handleReboot@00762308
REF 007628b0 UNCONDITIONAL_CALL caller=handleAf@00762458
REF 00762824 UNCONDITIONAL_CALL caller=handleAf@00762458
REF 00763cfc UNCONDITIONAL_CALL caller=handleMode@00763550
REF 00764670 UNCONDITIONAL_CALL caller=handleCrop@007645e0
REF 007646c4 UNCONDITIONAL_CALL caller=handleCrop@007645e0
REF 0076479c UNCONDITIONAL_CALL caller=handleCrop@007645e0
REF 00764950 UNCONDITIONAL_CALL caller=handleSetTimeCode@00764840
REF 00764994 UNCONDITIONAL_CALL caller=handleSetTimeCode@00764840
REF 00764a1c UNCONDITIONAL_CALL caller=handleSetTimeCode@00764840
REF 00764a38 UNCONDITIONAL_CALL caller=handleSetTimeCode@00764840
REF 00764ab8 UNCONDITIONAL_CALL caller=handleSetTimeCode@00764840
REF 00829608 UNCONDITIONAL_CALL caller=qurryTcStr@00829440
REF 00766a14 UNCONDITIONAL_CALL caller=handleCard@00766688
REF 00767124 UNCONDITIONAL_CALL caller=handleCalibration@00766f78
REF 00767640 UNCONDITIONAL_CALL caller=handleCalibration@00766f78
REF 00767700 UNCONDITIONAL_CALL caller=handleCalibration@00766f78
REF 007c1810 UNCONDITIONAL_CALL caller=imvt_calib_run_calibration_async@007c1768
REF 007c41dc UNCONDITIONAL_CALL caller=imvt_wb_calib_verify@007c4168
REF 007c4204 UNCONDITIONAL_CALL caller=imvt_wb_calib_verify@007c4168
REF 007c4734 UNCONDITIONAL_CALL caller=imvt_wb_calib_get_network_calib_last_gain@007c46e0
REF 007c95b8 UNCONDITIONAL_CALL caller=imvt_dpc_verify@007c9558
REF 007c95cc UNCONDITIONAL_CALL caller=imvt_dpc_verify@007c9558
REF 007c95ec UNCONDITIONAL_CALL caller=imvt_dpc_verify@007c9558
REF 007c9614 UNCONDITIONAL_CALL caller=imvt_dpc_verify@007c9558
REF 007c962c UNCONDITIONAL_CALL caller=imvt_dpc_verify@007c9558
REF 007c9648 UNCONDITIONAL_CALL caller=imvt_dpc_verify@007c9558
REF 007c4ec8 UNCONDITIONAL_CALL caller=FUN_007c4ce8@007c4ce8
REF 007c5f9c UNCONDITIONAL_CALL caller=FUN_007c5f58@007c5f58
REF 007c2764 UNCONDITIONAL_CALL caller=imvt_calib_get_common_vfr_list@007c2610
REF 007c2798 UNCONDITIONAL_CALL caller=imvt_calib_get_common_vfr_list@007c2610
REF 007cd684 UNCONDITIONAL_CALL caller=imvt_fpn_calib_verify@007cd5d0
REF 007cd69c UNCONDITIONAL_CALL caller=imvt_fpn_calib_verify@007cd5d0
REF 007cd6b4 UNCONDITIONAL_CALL caller=imvt_fpn_calib_verify@007cd5d0
REF 007cd6c8 UNCONDITIONAL_CALL caller=imvt_fpn_calib_verify@007cd5d0
REF 007cd6e0 UNCONDITIONAL_CALL caller=imvt_fpn_calib_verify@007cd5d0
REF 007cd738 UNCONDITIONAL_CALL caller=imvt_fpn_calib_verify@007cd5d0
REF 007cbde8 UNCONDITIONAL_CALL caller=FUN_007cbc30@007cbc30
REF 007d0e30 UNCONDITIONAL_CALL caller=imvt_blc_high_calib_verify@007d0d78
REF 007d0e48 UNCONDITIONAL_CALL caller=imvt_blc_high_calib_verify@007d0d78
REF 007d0e5c UNCONDITIONAL_CALL caller=imvt_blc_high_calib_verify@007d0d78
REF 007d0e74 UNCONDITIONAL_CALL caller=imvt_blc_high_calib_verify@007d0d78
REF 007d0ed0 UNCONDITIONAL_CALL caller=imvt_blc_high_calib_verify@007d0d78
REF 00b95a1c UNCONDITIONAL_CALL caller=sensor_get_readout_mode@00b959d8
REF 00767c84 UNCONDITIONAL_CALL caller=handleLighting@00767910
REF 008530b8 UNCONDITIONAL_CALL caller=FUN_00852e40@00852e40
REF 00769d00 UNCONDITIONAL_CALL caller=handlePushRTMP@00769a88
REF 0076be60 UNCONDITIONAL_CALL caller=handleStreamSetting@0076b0b8
REF 0086efd0 UNCONDITIONAL_CALL caller=imvt_cam_movie_requestidr@0086ef48
REF 0076c058 UNCONDITIONAL_CALL caller=handleCalibrationConfig@0076bf30
REF 0076c394 UNCONDITIONAL_CALL caller=handleCalibrationConfig@0076bf30
REF 0076ccb8 UNCONDITIONAL_CALL caller=handleNetworkModeConfig@0076c538
REF 0076cf74 UNCONDITIONAL_CALL caller=handleSntp@0076cdc8
REF 0076d010 UNCONDITIONAL_CALL caller=handleSntp@0076cdc8
REF 0076d038 UNCONDITIONAL_CALL caller=handleSntp@0076cdc8
REF 0076d0a8 UNCONDITIONAL_CALL caller=handleSntp@0076cdc8
REF 00a492e4 UNCONDITIONAL_CALL caller=imvt_sntp_client_set_sync_interval@00a49270
REF 0076d38c UNCONDITIONAL_CALL caller=handleLens@0076d2d8
REF 0076d6a8 UNCONDITIONAL_CALL caller=handleLens@0076d2d8
REF 0076d6cc UNCONDITIONAL_CALL caller=handleLens@0076d2d8
REF 0076d920 UNCONDITIONAL_CALL caller=handleLens@0076d2d8
REF 0076d944 UNCONDITIONAL_CALL caller=handleLens@0076d2d8
REF 0076f9d8 UNCONDITIONAL_CALL caller=handleGetConfig@0076f470
REF 00774980 UNCONDITIONAL_CALL caller=dumpAll@00774950
REF 007749a0 UNCONDITIONAL_CALL caller=dumpAll@00774950
REF 007749e0 UNCONDITIONAL_CALL caller=dumpAll@00774950
REF 00775a8c UNCONDITIONAL_CALL caller=handleWrite@00775888
REF 00775aac UNCONDITIONAL_CALL caller=handleWrite@00775888
REF 007771b0 UNCONDITIONAL_CALL caller=handleAccept@00777110
REF 00777360 UNCONDITIONAL_CALL caller=handleAccept@00777110
REF 00777384 UNCONDITIONAL_CALL caller=handleAccept@00777110
REF 007773b4 UNCONDITIONAL_CALL caller=handleAccept@00777110
REF 007773f0 UNCONDITIONAL_CALL caller=handleAccept@00777110
REF 0077743c UNCONDITIONAL_CALL caller=handleAccept@00777110
REF 00778b08 UNCONDITIONAL_CALL caller=recycleConnectionInLooper@00778aa0
REF 00778e7c UNCONDITIONAL_CALL caller=recycleConnectionInLooper@00778aa0
REF 00778eac UNCONDITIONAL_CALL caller=recycleConnectionInLooper@00778aa0
REF 0077a2f0 UNCONDITIONAL_CALL caller=handleWriteData@0077a238
REF 0081b104 UNCONDITIONAL_CALL caller=imvt_maintain_log_generate_zcam_report@0081ab10
REF 00a64e50 UNCONDITIONAL_CALL caller=FUN_00a64df8@00a64df8
REF 00a64e88 UNCONDITIONAL_CALL caller=FUN_00a64df8@00a64df8
REF 00a64eec UNCONDITIONAL_CALL caller=FUN_00a64df8@00a64df8
REF 00a64f10 UNCONDITIONAL_CALL caller=FUN_00a64df8@00a64df8
REF 00a64f38 UNCONDITIONAL_CALL caller=FUN_00a64df8@00a64df8
REF 00a65048 UNCONDITIONAL_CALL caller=imvt_qa_bypass@00a64fc0
REF 00a65078 UNCONDITIONAL_CALL caller=imvt_qa_bypass@00a64fc0
REF 00a64d50 UNCONDITIONAL_CALL caller=imvt_qa_bypass_shell_status@00a64cf8
REF 00a64d98 UNCONDITIONAL_CALL caller=imvt_qa_bypass_shell_status@00a64cf8
REF 00a64de8 UNCONDITIONAL_CALL caller=imvt_qa_bypass_shell_status@00a64cf8
REF 00a651b8 UNCONDITIONAL_CALL caller=imvt_qa_bypass_get_status@00a65080
REF 00a651dc UNCONDITIONAL_CALL caller=imvt_qa_bypass_get_status@00a65080
REF 00787a00 UNCONDITIONAL_CALL caller=handleGetRequest@007872b8
REF 007a8fc4 UNCONDITIONAL_CALL caller=enqueuePubMsg@007a8f28
REF 007a9090 UNCONDITIONAL_CALL caller=enqueueEvent@007a8fe0
REF 007a9148 UNCONDITIONAL_CALL caller=FUN_007a90e4@007a90e4
REF 007a999c UNCONDITIONAL_CALL caller=delUartConnection@007a98e8
REF 007a99c8 UNCONDITIONAL_CALL caller=delUartConnection@007a98e8
REF 007a9b74 UNCONDITIONAL_CALL caller=procReceiveDataControl@007a9ac8
REF 007a9d3c UNCONDITIONAL_CALL caller=procOneFrame@007a9ca0
REF 007a9d58 UNCONDITIONAL_CALL caller=procOneFrame@007a9ca0
REF 007b0dec UNCONDITIONAL_CALL caller=uartProtocolProcFrame@007b0c68
REF 007b0e3c UNCONDITIONAL_CALL caller=uartProtocolProcFrame@007b0c68
REF 007b0e58 UNCONDITIONAL_CALL caller=uartProtocolProcFrame@007b0c68
REF 007b0e6c UNCONDITIONAL_CALL caller=uartProtocolProcFrame@007b0c68
REF 007b0e84 UNCONDITIONAL_CALL caller=uartProtocolProcFrame@007b0c68
REF 007aa314 UNCONDITIONAL_CALL caller=worker@007aa2b8
REF 007aa3c8 UNCONDITIONAL_CALL caller=worker@007aa2b8
REF 007aa638 UNCONDITIONAL_CALL caller=worker@007aa2b8
REF 007aa664 UNCONDITIONAL_CALL caller=worker@007aa2b8
REF 007aa674 UNCONDITIONAL_CALL caller=worker@007aa2b8
REF 007aa6e8 UNCONDITIONAL_CALL caller=worker@007aa2b8
REF 007aa838 UNCONDITIONAL_CALL caller=worker@007aa2b8
REF 007aa868 UNCONDITIONAL_CALL caller=worker@007aa2b8
REF 007aa91c UNCONDITIONAL_CALL caller=worker@007aa2b8
REF 007aae48 UNCONDITIONAL_CALL caller=sendTask@007aab60
REF 007aaea0 UNCONDITIONAL_CALL caller=sendTask@007aab60
REF 007aaeb4 UNCONDITIONAL_CALL caller=sendTask@007aab60
REF 007aaedc UNCONDITIONAL_CALL caller=sendTask@007aab60
REF 007ab6ac UNCONDITIONAL_CALL caller=procReceiveData@007ab490
REF 007ab6c0 UNCONDITIONAL_CALL caller=procReceiveData@007ab490
REF 007ab6ec UNCONDITIONAL_CALL caller=procReceiveData@007ab490
REF 007ab90c UNCONDITIONAL_CALL caller=recvTask@007ab708
REF 007ab934 UNCONDITIONAL_CALL caller=recvTask@007ab708
REF 007ac09c UNCONDITIONAL_CALL caller=FUN_007abfb0@007abfb0
REF 007ac0b4 UNCONDITIONAL_CALL caller=FUN_007abfb0@007abfb0
REF 007ac1ac UNCONDITIONAL_CALL caller=FUN_007ac0c8@007ac0c8
REF 007ac1c0 UNCONDITIONAL_CALL caller=FUN_007ac0c8@007ac0c8
REF 007ac274 UNCONDITIONAL_CALL caller=FUN_007ac1d8@007ac1d8
REF 007ac290 UNCONDITIONAL_CALL caller=FUN_007ac1d8@007ac1d8
REF 007ac2b4 UNCONDITIONAL_CALL caller=FUN_007ac1d8@007ac1d8
REF 007ac340 UNCONDITIONAL_CALL caller=FUN_007ac2c0@007ac2c0
REF 007ac3ec UNCONDITIONAL_CALL caller=FUN_007ac2c0@007ac2c0
REF 007ac510 UNCONDITIONAL_CALL caller=FUN_007ac2c0@007ac2c0
REF 007ac52c UNCONDITIONAL_CALL caller=FUN_007ac2c0@007ac2c0
REF 007ac5d0 UNCONDITIONAL_CALL caller=FUN_007ac2c0@007ac2c0
REF 007ac668 UNCONDITIONAL_CALL caller=FUN_007ac5e0@007ac5e0
REF 007ac70c UNCONDITIONAL_CALL caller=FUN_007ac5e0@007ac5e0
REF 007ac724 UNCONDITIONAL_CALL caller=FUN_007ac5e0@007ac5e0
REF 007ac7ac UNCONDITIONAL_CALL caller=FUN_007ac738@007ac738
REF 007ac86c UNCONDITIONAL_CALL caller=FUN_007ac738@007ac738
REF 007ac880 UNCONDITIONAL_CALL caller=FUN_007ac738@007ac738
REF 007ac91c UNCONDITIONAL_CALL caller=FUN_007ac8b8@007ac8b8
REF 007ac984 UNCONDITIONAL_CALL caller=FUN_007ac8b8@007ac8b8
REF 007ac99c UNCONDITIONAL_CALL caller=FUN_007ac8b8@007ac8b8
REF 007aca24 UNCONDITIONAL_CALL caller=FUN_007ac9c0@007ac9c0
REF 007acaac UNCONDITIONAL_CALL caller=FUN_007ac9c0@007ac9c0
REF 007acac0 UNCONDITIONAL_CALL caller=FUN_007ac9c0@007ac9c0
REF 007acb34 UNCONDITIONAL_CALL caller=FUN_007acad0@007acad0
REF 007acbbc UNCONDITIONAL_CALL caller=FUN_007acad0@007acad0
REF 007acbd4 UNCONDITIONAL_CALL caller=FUN_007acad0@007acad0
REF 007acc54 UNCONDITIONAL_CALL caller=FUN_007acbe8@007acbe8
REF 007accf0 UNCONDITIONAL_CALL caller=FUN_007acbe8@007acbe8
REF 007acd04 UNCONDITIONAL_CALL caller=FUN_007acbe8@007acbe8
REF 007acd74 UNCONDITIONAL_CALL caller=FUN_007acd10@007acd10
REF 007acdec UNCONDITIONAL_CALL caller=FUN_007acd10@007acd10
REF 007ace00 UNCONDITIONAL_CALL caller=FUN_007acd10@007acd10
REF 007ace7c UNCONDITIONAL_CALL caller=FUN_007ace10@007ace10
REF 007acf04 UNCONDITIONAL_CALL caller=FUN_007ace10@007ace10
REF 007acf18 UNCONDITIONAL_CALL caller=FUN_007ace10@007ace10
REF 007ad2cc UNCONDITIONAL_CALL caller=FUN_007ad248@007ad248
REF 007ad3d4 UNCONDITIONAL_CALL caller=FUN_007ad248@007ad248
REF 007ad43c UNCONDITIONAL_CALL caller=FUN_007ad248@007ad248
REF 007ad4d4 UNCONDITIONAL_CALL caller=FUN_007ad450@007ad450
REF 007ad5ec UNCONDITIONAL_CALL caller=FUN_007ad450@007ad450
REF 007ad604 UNCONDITIONAL_CALL caller=FUN_007ad450@007ad450
REF 007ad6a8 UNCONDITIONAL_CALL caller=FUN_007ad620@007ad620
REF 007ad7d8 UNCONDITIONAL_CALL caller=FUN_007ad620@007ad620
REF 007ad824 UNCONDITIONAL_CALL caller=FUN_007ad620@007ad620
REF 007ad8a4 UNCONDITIONAL_CALL caller=FUN_007ad830@007ad830
REF 007ad9a8 UNCONDITIONAL_CALL caller=FUN_007ad830@007ad830
REF 007ad9cc UNCONDITIONAL_CALL caller=FUN_007ad830@007ad830
REF 007ada5c UNCONDITIONAL_CALL caller=FUN_007ad9d8@007ad9d8
REF 007adb4c UNCONDITIONAL_CALL caller=FUN_007ad9d8@007ad9d8
REF 007adba8 UNCONDITIONAL_CALL caller=FUN_007ad9d8@007ad9d8
REF 007adc04 UNCONDITIONAL_CALL caller=FUN_007adbb8@007adbb8
REF 007adc7c UNCONDITIONAL_CALL caller=FUN_007adbb8@007adbb8
REF 007adc9c UNCONDITIONAL_CALL caller=FUN_007adbb8@007adbb8
REF 007add0c UNCONDITIONAL_CALL caller=FUN_007adca8@007adca8
REF 007ade0c UNCONDITIONAL_CALL caller=FUN_007adca8@007adca8
REF 007ade20 UNCONDITIONAL_CALL caller=FUN_007adca8@007adca8
REF 007adf70 UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007adfb0 UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007adfe0 UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007ae01c UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007ae034 UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007ae05c UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007ae074 UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007ae088 UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007ae0a4 UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007ae0bc UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007ae0d4 UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007ae0f0 UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007ae104 UNCONDITIONAL_CALL caller=FUN_007ade30@007ade30
REF 007ae284 UNCONDITIONAL_CALL caller=FUN_007ae168@007ae168
REF 007ae298 UNCONDITIONAL_CALL caller=FUN_007ae168@007ae168
REF 007ae30c UNCONDITIONAL_CALL caller=FUN_007ae2a8@007ae2a8
REF 007ae41c UNCONDITIONAL_CALL caller=FUN_007ae2a8@007ae2a8
REF 007ae430 UNCONDITIONAL_CALL caller=FUN_007ae2a8@007ae2a8
REF 007ae4a4 UNCONDITIONAL_CALL caller=FUN_007ae440@007ae440
REF 007ae55c UNCONDITIONAL_CALL caller=FUN_007ae440@007ae440
REF 007ae570 UNCONDITIONAL_CALL caller=FUN_007ae440@007ae440
REF 007ae5dc UNCONDITIONAL_CALL caller=FUN_007ae580@007ae580
REF 007ae684 UNCONDITIONAL_CALL caller=FUN_007ae580@007ae580
REF 007ae698 UNCONDITIONAL_CALL caller=FUN_007ae580@007ae580
REF 007ae708 UNCONDITIONAL_CALL caller=FUN_007ae6a8@007ae6a8
REF 007ae7f4 UNCONDITIONAL_CALL caller=FUN_007ae6a8@007ae6a8
REF 007ae808 UNCONDITIONAL_CALL caller=FUN_007ae6a8@007ae6a8
REF 007ae880 UNCONDITIONAL_CALL caller=FUN_007ae818@007ae818
REF 007ae90c UNCONDITIONAL_CALL caller=FUN_007ae818@007ae818
REF 007ae920 UNCONDITIONAL_CALL caller=FUN_007ae818@007ae818
REF 007ae9dc UNCONDITIONAL_CALL caller=FUN_007ae970@007ae970
REF 007aea5c UNCONDITIONAL_CALL caller=FUN_007ae970@007ae970
REF 007aea70 UNCONDITIONAL_CALL caller=FUN_007ae970@007ae970
REF 007aea94 UNCONDITIONAL_CALL caller=FUN_007aea80@007aea80
REF 007aeb08 UNCONDITIONAL_CALL caller=FUN_007aeaa8@007aeaa8
REF 007aeb98 UNCONDITIONAL_CALL caller=FUN_007aeaa8@007aeaa8
REF 007aec10 UNCONDITIONAL_CALL caller=FUN_007aebb0@007aebb0
REF 007aeca0 UNCONDITIONAL_CALL caller=FUN_007aebb0@007aebb0
REF 007aed18 UNCONDITIONAL_CALL caller=FUN_007aecb8@007aecb8
REF 007aeda8 UNCONDITIONAL_CALL caller=FUN_007aecb8@007aecb8
REF 007aee20 UNCONDITIONAL_CALL caller=FUN_007aedc0@007aedc0
REF 007aeeb0 UNCONDITIONAL_CALL caller=FUN_007aedc0@007aedc0
REF 007aef28 UNCONDITIONAL_CALL caller=FUN_007aeec8@007aeec8
REF 007aefc0 UNCONDITIONAL_CALL caller=FUN_007aeec8@007aeec8
REF 007af020 UNCONDITIONAL_CALL caller=FUN_007aefd8@007aefd8
REF 007af044 UNCONDITIONAL_CALL caller=FUN_007aefd8@007aefd8
REF 007af0ac UNCONDITIONAL_CALL caller=FUN_007af060@007af060
REF 007af0ec UNCONDITIONAL_CALL caller=FUN_007af060@007af060
REF 007af154 UNCONDITIONAL_CALL caller=FUN_007af108@007af108
REF 007af194 UNCONDITIONAL_CALL caller=FUN_007af108@007af108
REF 007af1fc UNCONDITIONAL_CALL caller=FUN_007af1b0@007af1b0
REF 007af23c UNCONDITIONAL_CALL caller=FUN_007af1b0@007af1b0
REF 007af2a4 UNCONDITIONAL_CALL caller=FUN_007af258@007af258
REF 007af2cc UNCONDITIONAL_CALL caller=FUN_007af258@007af258
REF 007af334 UNCONDITIONAL_CALL caller=FUN_007af2e8@007af2e8
REF 007af364 UNCONDITIONAL_CALL caller=FUN_007af2e8@007af2e8
REF 007af3cc UNCONDITIONAL_CALL caller=FUN_007af380@007af380
REF 007af414 UNCONDITIONAL_CALL caller=FUN_007af380@007af380
REF 007af488 UNCONDITIONAL_CALL caller=FUN_007af430@007af430
REF 007af4b4 UNCONDITIONAL_CALL caller=FUN_007af430@007af430
REF 007af530 UNCONDITIONAL_CALL caller=FUN_007af4d0@007af4d0
REF 007af55c UNCONDITIONAL_CALL caller=FUN_007af4d0@007af4d0
REF 007af5c4 UNCONDITIONAL_CALL caller=FUN_007af578@007af578
REF 007af5f4 UNCONDITIONAL_CALL caller=FUN_007af578@007af578
REF 007af65c UNCONDITIONAL_CALL caller=FUN_007af610@007af610
REF 007af694 UNCONDITIONAL_CALL caller=FUN_007af610@007af610
REF 007af6fc UNCONDITIONAL_CALL caller=FUN_007af6b0@007af6b0
REF 007af734 UNCONDITIONAL_CALL caller=FUN_007af6b0@007af6b0
REF 007af79c UNCONDITIONAL_CALL caller=FUN_007af750@007af750
REF 007af7d4 UNCONDITIONAL_CALL caller=FUN_007af750@007af750
REF 007af83c UNCONDITIONAL_CALL caller=FUN_007af7f0@007af7f0
REF 007af874 UNCONDITIONAL_CALL caller=FUN_007af7f0@007af7f0
REF 007af8e8 UNCONDITIONAL_CALL caller=FUN_007af890@007af890
REF 007af914 UNCONDITIONAL_CALL caller=FUN_007af890@007af890
REF 007af92c UNCONDITIONAL_CALL caller=FUN_007af890@007af890
REF 007af994 UNCONDITIONAL_CALL caller=FUN_007af940@007af940
REF 007af9bc UNCONDITIONAL_CALL caller=FUN_007af940@007af940
REF 007afa1c UNCONDITIONAL_CALL caller=FUN_007af9d8@007af9d8
REF 007afa90 UNCONDITIONAL_CALL caller=FUN_007afa30@007afa30
REF 007afb20 UNCONDITIONAL_CALL caller=FUN_007afa30@007afa30
REF 007afbb4 UNCONDITIONAL_CALL caller=FUN_007afb48@007afb48
REF 007afc34 UNCONDITIONAL_CALL caller=FUN_007afb48@007afb48
REF 007afc48 UNCONDITIONAL_CALL caller=FUN_007afb48@007afb48
REF 007afcc4 UNCONDITIONAL_CALL caller=FUN_007afc58@007afc58
REF 007afd2c UNCONDITIONAL_CALL caller=FUN_007afc58@007afc58
REF 007b0914 UNCONDITIONAL_CALL caller=FUN_007afc58@007afc58
REF 007b12a8 UNCONDITIONAL_CALL caller=FUN_007b1238@007b1238
REF 007b1378 UNCONDITIONAL_CALL caller=FUN_007b1350@007b1350
REF 007b14bc UNCONDITIONAL_CALL caller=FUN_007b1440@007b1440
REF 007b156c UNCONDITIONAL_CALL caller=FUN_007b1440@007b1440
REF 007b15ac UNCONDITIONAL_CALL caller=FUN_007b1440@007b1440
REF 007b1604 UNCONDITIONAL_CALL caller=FUN_007b1440@007b1440
REF 007b16a4 UNCONDITIONAL_CALL caller=FUN_007b1440@007b1440
REF 007b16dc UNCONDITIONAL_CALL caller=FUN_007b1440@007b1440
REF 007b1734 UNCONDITIONAL_CALL caller=FUN_007b1440@007b1440
REF 007b1784 UNCONDITIONAL_CALL caller=FUN_007b1440@007b1440
REF 007b17d4 UNCONDITIONAL_CALL caller=FUN_007b1440@007b1440
REF 007b1b5c UNCONDITIONAL_CALL caller=FUN_007b1b18@007b1b18
REF 007b2dd4 UNCONDITIONAL_CALL caller=FUN_007b2d18@007b2d18
REF 007b2e44 UNCONDITIONAL_CALL caller=FUN_007b2d18@007b2d18
REF 007b30dc UNCONDITIONAL_CALL caller=handleUartCmd@007b3060
REF 007b33b4 UNCONDITIONAL_CALL caller=FUN_007b3298@007b3298
REF 007b3424 UNCONDITIONAL_CALL caller=FUN_007b3298@007b3298
REF 007b3534 UNCONDITIONAL_CALL caller=FUN_007b3298@007b3298
REF 007b3644 UNCONDITIONAL_CALL caller=FUN_007b3298@007b3298
REF 007b366c UNCONDITIONAL_CALL caller=FUN_007b3298@007b3298
REF 007b368c UNCONDITIONAL_CALL caller=FUN_007b3298@007b3298
REF 007b36f0 UNCONDITIONAL_CALL caller=FUN_007b3298@007b3298
REF 007b3704 UNCONDITIONAL_CALL caller=FUN_007b3298@007b3298
REF 007b3718 UNCONDITIONAL_CALL caller=FUN_007b3298@007b3298
REF 007b4788 UNCONDITIONAL_CALL caller=handleUartCmd@007b4698
REF 007b482c UNCONDITIONAL_CALL caller=handleUartCmd@007b4698
REF 007b4da8 UNCONDITIONAL_CALL caller=ltcDeviceConnectMonitor@007b4d60
REF 007b5274 UNCONDITIONAL_CALL caller=FUN_007b51a8@007b51a8
REF 007b5628 UNCONDITIONAL_CALL caller=deinit@007b55b0
REF 007b57ac UNCONDITIONAL_CALL caller=checkCrc16@007b5740
REF 007b5d84 UNCONDITIONAL_CALL caller=procOneFrame@007b5c00
REF 007b5e1c UNCONDITIONAL_CALL caller=worker@007b5dc0
REF 007b6004 UNCONDITIONAL_CALL caller=worker@007b5dc0
REF 007b606c UNCONDITIONAL_CALL caller=worker@007b5dc0
REF 007b6094 UNCONDITIONAL_CALL caller=worker@007b5dc0
REF 007b60b8 UNCONDITIONAL_CALL caller=worker@007b5dc0
REF 007b775c UNCONDITIONAL_CALL caller=FUN_007b75e8@007b75e8
REF 007b77dc UNCONDITIONAL_CALL caller=FUN_007b75e8@007b75e8
REF 007b782c UNCONDITIONAL_CALL caller=FUN_007b75e8@007b75e8
REF 007b787c UNCONDITIONAL_CALL caller=FUN_007b75e8@007b75e8
REF 007b788c UNCONDITIONAL_CALL caller=FUN_007b75e8@007b75e8
REF 007b78a8 UNCONDITIONAL_CALL caller=FUN_007b75e8@007b75e8
REF 007b7a5c UNCONDITIONAL_CALL caller=FUN_007b78c0@007b78c0
REF 007b7a80 UNCONDITIONAL_CALL caller=FUN_007b78c0@007b78c0
REF 007b842c UNCONDITIONAL_CALL caller=init@007b8358
REF 007bb9c0 UNCONDITIONAL_CALL caller=imvt_cam_factory_handle_message@007bb978
REF 007bb9e4 UNCONDITIONAL_CALL caller=imvt_cam_factory_handle_message@007bb978
REF 007bba0c UNCONDITIONAL_CALL caller=imvt_cam_factory_handle_message@007bb978
REF 007bba2c UNCONDITIONAL_CALL caller=imvt_cam_factory_handle_message@007bb978
REF 007b9dd8 UNCONDITIONAL_CALL caller=FUN_007b9db8@007b9db8
REF 00a4686c UNCONDITIONAL_CALL caller=imvt_expansion_port_set_role@00a46858
REF 00a46894 UNCONDITIONAL_CALL caller=imvt_expansion_port_detect@00a46880
REF 007ba194 UNCONDITIONAL_CALL caller=FUN_007ba070@007ba070
REF 007ba7d8 UNCONDITIONAL_CALL caller=FUN_007ba7a0@007ba7a0
REF 007ba9e4 UNCONDITIONAL_CALL caller=FUN_007ba9b0@007ba9b0
REF 007baa3c UNCONDITIONAL_CALL caller=FUN_007baa08@007baa08
REF 007baa94 UNCONDITIONAL_CALL caller=FUN_007baa60@007baa60
REF 007baae4 UNCONDITIONAL_CALL caller=FUN_007baab8@007baab8
REF 007bab34 UNCONDITIONAL_CALL caller=FUN_007bab00@007bab00
REF 007bacf4 UNCONDITIONAL_CALL caller=FUN_007bacc0@007bacc0
REF 007bad4c UNCONDITIONAL_CALL caller=FUN_007bad18@007bad18
REF 007badac UNCONDITIONAL_CALL caller=FUN_007bad80@007bad80
REF 007badfc UNCONDITIONAL_CALL caller=FUN_007badc8@007badc8
REF 007bae54 UNCONDITIONAL_CALL caller=FUN_007bae20@007bae20
REF 007baeac UNCONDITIONAL_CALL caller=FUN_007bae78@007bae78
REF 007baf04 UNCONDITIONAL_CALL caller=FUN_007baed0@007baed0
REF 007baf74 UNCONDITIONAL_CALL caller=FUN_007baf28@007baf28
REF 007bafd8 UNCONDITIONAL_CALL caller=FUN_007baf28@007baf28
REF 007bb25c UNCONDITIONAL_CALL caller=FUN_007bb010@007bb010
REF 007bb370 UNCONDITIONAL_CALL caller=FUN_007bb2a0@007bb2a0
REF 007bb880 UNCONDITIONAL_CALL caller=FUN_007bb770@007bb770
REF 007bb8b4 UNCONDITIONAL_CALL caller=FUN_007bb770@007bb770
REF 007bb8d8 UNCONDITIONAL_CALL caller=FUN_007bb770@007bb770
REF 007bcb38 UNCONDITIONAL_CALL caller=FUN_007bcb00@007bcb00
REF 007bcec0 UNCONDITIONAL_CALL caller=FUN_007bcdf0@007bcdf0
REF 007bd630 UNCONDITIONAL_CALL caller=onKey@007bd568
REF 007bd8a8 UNCONDITIONAL_CALL caller=SD_test@007bd7b8
REF 007bebc4 UNCONDITIONAL_CALL caller=onMessage@007bea30
REF 00a50cc4 UNCONDITIONAL_CALL caller=imvt_rs485_master_control_send_with_response@00a50b08
REF 00a50d00 UNCONDITIONAL_CALL caller=imvt_rs485_master_control_send_with_response@00a50b08
REF 00a50654 UNCONDITIONAL_CALL caller=FUN_00a504b8@00a504b8
REF 00a5066c UNCONDITIONAL_CALL caller=FUN_00a504b8@00a504b8
REF 00a5068c UNCONDITIONAL_CALL caller=FUN_00a504b8@00a504b8
REF 00a506a4 UNCONDITIONAL_CALL caller=FUN_00a504b8@00a504b8
REF 00a506b8 UNCONDITIONAL_CALL caller=FUN_00a504b8@00a504b8
REF 00a53478 UNCONDITIONAL_CALL caller=uart_read_package_head@00a53288
REF 00a5349c UNCONDITIONAL_CALL caller=uart_read_package_head@00a53288
REF 00a534d8 UNCONDITIONAL_CALL caller=uart_read_package_head@00a53288
REF 00a534f8 UNCONDITIONAL_CALL caller=uart_read_package_head@00a53288
REF 00a53510 UNCONDITIONAL_CALL caller=uart_read_package_head@00a53288
REF 00a53528 UNCONDITIONAL_CALL caller=uart_read_package_head@00a53288
REF 00a5354c UNCONDITIONAL_CALL caller=uart_read_package_head@00a53288
REF 00a53090 UNCONDITIONAL_CALL caller=FUN_00a52f10@00a52f10
REF 00a535cc UNCONDITIONAL_CALL caller=uart_read_package_data@00a53560
REF 00a53674 UNCONDITIONAL_CALL caller=compare_receive_package_check_sum_is_ok@00a535e0
REF 007bf03c UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_set_config@007bef10
REF 007bf054 UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_set_config@007bef10
REF 007bf2d0 UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_set_mode@007bf210
REF 007bf4b8 UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_send_mac@007bf3f8
REF 007bf588 UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_get_sdcard_status@007bf4c8
REF 007bf76c UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_sync_video_system@007bf6f8
REF 007bf7f4 UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_sync_video_resolution@007bf780
REF 007bf84c UNCONDITIONAL_CALL caller=imvt_cam_uart_controller_calibration_check@007bf818
REF 007bfd38 UNCONDITIONAL_CALL caller=handleMsgWithResponse@007bfc90
REF 007bfe24 UNCONDITIONAL_CALL caller=handleMsgWithResponse@007bfc90
REF 007bfe3c UNCONDITIONAL_CALL caller=handleMsgWithResponse@007bfc90
REF 007bfe54 UNCONDITIONAL_CALL caller=handleMsgWithResponse@007bfc90
REF 007c0df0 UNCONDITIONAL_CALL caller=FUN_007c0ce0@007c0ce0
REF 007c0e44 UNCONDITIONAL_CALL caller=FUN_007c0ce0@007c0ce0
REF 007c0fac UNCONDITIONAL_CALL caller=imvt_calib_parse_config_file@007c0f50
REF 007c105c UNCONDITIONAL_CALL caller=imvt_calib_parse_config_file@007c0f50
REF 007c10c0 UNCONDITIONAL_CALL caller=imvt_calib_parse_config_file@007c0f50
REF 007c14f8 UNCONDITIONAL_CALL caller=imvt_calib_auto_reboot_flag_set@007c1440
REF 007c15e4 UNCONDITIONAL_CALL caller=imvt_calib_auto_reboot_flag_set@007c1440
REF 007c1604 UNCONDITIONAL_CALL caller=imvt_calib_auto_reboot_flag_set@007c1440
REF 007c16c4 UNCONDITIONAL_CALL caller=imvt_calib_fast_restart_pgm_with_resolution@007c1638
REF 007c16d4 UNCONDITIONAL_CALL caller=imvt_calib_fast_restart_pgm_with_resolution@007c1638
REF 007c16e0 UNCONDITIONAL_CALL caller=imvt_calib_fast_restart_pgm_with_resolution@007c1638
REF 007c1a74 UNCONDITIONAL_CALL caller=imvt_calib_master_set_all_camera_movie_mode_and_resolution@007c19e0
REF 007c1b84 UNCONDITIONAL_CALL caller=imvt_calib_master_set_all_camera_movie_mode_and_resolution@007c19e0
REF 007c1bc0 UNCONDITIONAL_CALL caller=imvt_calib_master_set_all_camera_movie_mode_and_resolution@007c19e0
REF 007c1bdc UNCONDITIONAL_CALL caller=imvt_calib_master_set_all_camera_movie_mode_and_resolution@007c19e0
REF 007c1bfc UNCONDITIONAL_CALL caller=imvt_calib_master_set_all_camera_movie_mode_and_resolution@007c19e0
REF 007c1c14 UNCONDITIONAL_CALL caller=imvt_calib_master_set_all_camera_movie_mode_and_resolution@007c19e0
REF 007c1c30 UNCONDITIONAL_CALL caller=imvt_calib_master_set_all_camera_movie_mode_and_resolution@007c19e0
REF 007c1c9c UNCONDITIONAL_CALL caller=imvt_calib_master_query_n_wait_result@007c1c40
REF 007c1d38 UNCONDITIONAL_CALL caller=imvt_calib_master_query_n_wait_result@007c1c40
REF 007c1d5c UNCONDITIONAL_CALL caller=imvt_calib_master_query_n_wait_result@007c1c40
REF 007c1df0 UNCONDITIONAL_CALL caller=imvt_calib_master_query_n_wait_result@007c1c40
REF 007c1e14 UNCONDITIONAL_CALL caller=imvt_calib_master_query_n_wait_result@007c1c40
REF 007c1e2c UNCONDITIONAL_CALL caller=imvt_calib_master_query_n_wait_result@007c1c40
REF 007c1e3c UNCONDITIONAL_CALL caller=imvt_calib_master_query_n_wait_result@007c1c40
REF 007c1e58 UNCONDITIONAL_CALL caller=imvt_calib_master_query_n_wait_result@007c1c40
REF 007c1f88 UNCONDITIONAL_CALL caller=imvt_calib_master_send_request@007c1e68
REF 007c1fa4 UNCONDITIONAL_CALL caller=imvt_calib_master_send_request@007c1e68
REF 007c1fd8 UNCONDITIONAL_CALL caller=imvt_calib_master_send_request@007c1e68
REF 007c2000 UNCONDITIONAL_CALL caller=imvt_calib_master_send_request@007c1e68
REF 007c2020 UNCONDITIONAL_CALL caller=imvt_calib_master_send_request@007c1e68
REF 007c20e4 UNCONDITIONAL_CALL caller=imvt_calib_master_wait_request_done@007c2030
REF 007c224c UNCONDITIONAL_CALL caller=imvt_calib_process_sync_packet@007c21a0
REF 007c2328 UNCONDITIONAL_CALL caller=imvt_calib_util_disable_dp_dynamic@007c22d8
REF 007c2368 UNCONDITIONAL_CALL caller=imvt_calib_util_disable_dp_dynamic@007c22d8
REF 007c23ec UNCONDITIONAL_CALL caller=imvt_calib_util_disable_dp_static@007c2378
REF 007c2440 UNCONDITIONAL_CALL caller=imvt_calib_util_disable_dp_static@007c2378
REF 007c253c UNCONDITIONAL_CALL caller=imvt_calib_util_test_switch_all_resolutions@007c2450
REF 007c255c UNCONDITIONAL_CALL caller=imvt_calib_util_test_switch_all_resolutions@007c2450
REF 007c256c UNCONDITIONAL_CALL caller=imvt_calib_util_test_switch_all_resolutions@007c2450
REF 007c2578 UNCONDITIONAL_CALL caller=imvt_calib_util_test_switch_all_resolutions@007c2450
REF 007c2a10 UNCONDITIONAL_CALL caller=imvt_calib_shell_show_blc_mode@007c2988
REF 007c2a78 UNCONDITIONAL_CALL caller=imvt_calib_shell_show_blc_mode@007c2988
REF 007c2b68 UNCONDITIONAL_CALL caller=imvt_calib_reset_liveview@007c2b48
REF 007c2ca4 UNCONDITIONAL_CALL caller=imvt_calib_switch_resolution@007c2c38
REF 007c3184 UNCONDITIONAL_CALL caller=imvt_calib_user_debug_dpc_for_current_res@007c3170
REF 007c31cc UNCONDITIONAL_CALL caller=imvt_calib_user_debug_dpc_for_current_res@007c3170
REF 007c3698 UNCONDITIONAL_CALL caller=FUN_007c3518@007c3518
REF 007c36dc UNCONDITIONAL_CALL caller=FUN_007c3518@007c3518
REF 007c3830 UNCONDITIONAL_CALL caller=FUN_007c36e8@007c36e8
REF 007c386c UNCONDITIONAL_CALL caller=FUN_007c36e8@007c36e8
REF 007c3920 UNCONDITIONAL_CALL caller=FUN_007c36e8@007c36e8
REF 007c3948 UNCONDITIONAL_CALL caller=FUN_007c36e8@007c36e8
REF 007c3af4 UNCONDITIONAL_CALL caller=FUN_007c3998@007c3998
REF 007c3bac UNCONDITIONAL_CALL caller=FUN_007c3998@007c3998
REF 007c3bd8 UNCONDITIONAL_CALL caller=FUN_007c3998@007c3998
REF 007c3c74 UNCONDITIONAL_CALL caller=FUN_007c3998@007c3998
REF 007c3c9c UNCONDITIONAL_CALL caller=FUN_007c3998@007c3998
REF 007c3cdc UNCONDITIONAL_CALL caller=FUN_007c3998@007c3998
REF 007c3e88 UNCONDITIONAL_CALL caller=FUN_007c3998@007c3998
REF 007c3ecc UNCONDITIONAL_CALL caller=FUN_007c3998@007c3998
REF 007c3f60 UNCONDITIONAL_CALL caller=FUN_007c3998@007c3998
REF 0088366c UNCONDITIONAL_CALL caller=imvt_cam_region_msg_show@00883608
REF 00883690 UNCONDITIONAL_CALL caller=imvt_cam_region_msg_show@00883608
REF 008836b8 UNCONDITIONAL_CALL caller=imvt_cam_region_msg_show@00883608
REF 0088da4c UNCONDITIONAL_CALL caller=imvt_n3a_ae_set_sensor_channel@0088da18
REF 0088da74 UNCONDITIONAL_CALL caller=imvt_n3a_ae_set_sensor_channel@0088da18
REF 007c4290 UNCONDITIONAL_CALL caller=imvt_wb_calib_run@007c4230
REF 007c42c0 UNCONDITIONAL_CALL caller=imvt_wb_calib_run@007c4230
REF 007c42f0 UNCONDITIONAL_CALL caller=imvt_wb_calib_run@007c4230
REF 007c43f8 UNCONDITIONAL_CALL caller=imvt_wb_calib_run@007c4230
REF 007c44a0 UNCONDITIONAL_CALL caller=imvt_wb_calib_run@007c4230
REF 007c4544 UNCONDITIONAL_CALL caller=imvt_wb_calib_run@007c4230
REF 007c460c UNCONDITIONAL_CALL caller=imvt_wb_calib_run@007c4230
REF 007c4628 UNCONDITIONAL_CALL caller=imvt_wb_calib_run@007c4230
REF 007c463c UNCONDITIONAL_CALL caller=imvt_wb_calib_run@007c4230
REF 007c465c UNCONDITIONAL_CALL caller=imvt_wb_calib_run@007c4230
REF 007c4670 UNCONDITIONAL_CALL caller=imvt_wb_calib_run@007c4230
REF 007c4690 UNCONDITIONAL_CALL caller=imvt_wb_calib_run@007c4230
REF 007c4a40 UNCONDITIONAL_CALL caller=FUN_007c4920@007c4920
REF 007c4a74 UNCONDITIONAL_CALL caller=FUN_007c4920@007c4920
REF 007c4cb0 UNCONDITIONAL_CALL caller=FUN_007c4ae8@007c4ae8
REF 007c5224 UNCONDITIONAL_CALL caller=FUN_007c51a8@007c51a8
REF 007c524c UNCONDITIONAL_CALL caller=FUN_007c51a8@007c51a8
REF 007c529c UNCONDITIONAL_CALL caller=FUN_007c51a8@007c51a8
REF 007c531c UNCONDITIONAL_CALL caller=FUN_007c51a8@007c51a8
REF 007c5438 UNCONDITIONAL_CALL caller=FUN_007c5340@007c5340
REF 007c5494 UNCONDITIONAL_CALL caller=FUN_007c5340@007c5340
REF 007c54c0 UNCONDITIONAL_CALL caller=FUN_007c5340@007c5340
REF 007c54f0 UNCONDITIONAL_CALL caller=FUN_007c5340@007c5340
REF 007c5508 UNCONDITIONAL_CALL caller=FUN_007c5340@007c5340
REF 00839d4c UNCONDITIONAL_CALL caller=FUN_00839d34@00839d34
REF 00839dc4 UNCONDITIONAL_CALL caller=imvt_bpc_calibration_check_result@00839d98
REF 007c5614 UNCONDITIONAL_CALL caller=FUN_007c5518@007c5518
REF 007c570c UNCONDITIONAL_CALL caller=FUN_007c5518@007c5518
REF 007c5760 UNCONDITIONAL_CALL caller=FUN_007c5518@007c5518
REF 007c5a04 UNCONDITIONAL_CALL caller=FUN_007c5518@007c5518
REF 007c5b00 UNCONDITIONAL_CALL caller=FUN_007c5518@007c5518
REF 00839e04 UNCONDITIONAL_CALL caller=imvt_bpc_calibration_set_wdr_single_chan@00839dd8
REF 00839e94 UNCONDITIONAL_CALL caller=imvt_bpc_calibration_merge_result@00839e18
REF 00839eb8 UNCONDITIONAL_CALL caller=imvt_bpc_calibration_merge_result@00839e18
REF 007c6038 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_print@007c5ff0
REF 007c606c UNCONDITIONAL_CALL caller=imvt_dpc_cmd_print@007c5ff0
REF 007c60ec UNCONDITIONAL_CALL caller=imvt_dpc_cmd_print@007c5ff0
REF 007c610c UNCONDITIONAL_CALL caller=imvt_dpc_cmd_print@007c5ff0
REF 007c6128 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_print@007c5ff0
REF 007c6168 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_print@007c5ff0
REF 007c6188 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_print@007c5ff0
REF 007c61a4 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_print@007c5ff0
REF 007c6280 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c628c UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c6298 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c6328 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c6358 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c66d0 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c66ec UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c6708 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c6734 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c6928 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c6994 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c6a28 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c6c3c UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c6c58 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c6c74 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_load@007c6208
REF 007c6ce4 UNCONDITIONAL_CALL caller=imvt_dpc_setup_param@007c6c80
REF 007c6d00 UNCONDITIONAL_CALL caller=imvt_dpc_setup_param@007c6c80
REF 007c6d7c UNCONDITIONAL_CALL caller=imvt_dpc_cmd_save@007c6d10
REF 007c6d88 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_save@007c6d10
REF 007c6d94 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_save@007c6d10
REF 007c6da0 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_save@007c6d10
REF 007c6e08 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_save@007c6d10
REF 007c7020 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_save@007c6d10
REF 007c7040 UNCONDITIONAL_CALL caller=imvt_dpc_cmd_save@007c6d10
REF 007c705c UNCONDITIONAL_CALL caller=imvt_dpc_cmd_save@007c6d10
REF 007c70dc UNCONDITIONAL_CALL caller=FUN_007c7070@007c7070
REF 007c70e8 UNCONDITIONAL_CALL caller=FUN_007c7070@007c7070
REF 007c70fc UNCONDITIONAL_CALL caller=FUN_007c7070@007c7070
REF 007c7270 UNCONDITIONAL_CALL caller=FUN_007c7070@007c7070
REF 007c766c UNCONDITIONAL_CALL caller=FUN_007c7070@007c7070
REF 007c7788 UNCONDITIONAL_CALL caller=FUN_007c7070@007c7070
REF 007c7704 UNCONDITIONAL_CALL caller=FUN_007c7070@007c7070
REF 007c7744 UNCONDITIONAL_CALL caller=FUN_007c7070@007c7070
REF 007c7930 UNCONDITIONAL_CALL caller=FUN_007c7070@007c7070
REF 00869d2c UNCONDITIONAL_CALL caller=imvt_cam_opmode_get_lvds_cap_window@00869cc0
REF 007c7a34 UNCONDITIONAL_CALL caller=imvt_dpc_calib_enable_calibration@007c79d8
REF 007c7a8c UNCONDITIONAL_CALL caller=imvt_dpc_calib_enable_calibration@007c79d8
REF 00839d84 UNCONDITIONAL_CALL caller=imvt_bpc_calibration_enable@00839d60
REF 007c7c68 UNCONDITIONAL_CALL caller=FUN_007c7c0c@007c7c0c
REF 007c7d64 UNCONDITIONAL_CALL caller=FUN_007c7d00@007c7d00
REF 007c7de0 UNCONDITIONAL_CALL caller=FUN_007c7d00@007c7d00
REF 007c7eb0 UNCONDITIONAL_CALL caller=FUN_007c7d00@007c7d00
REF 007c8178 UNCONDITIONAL_CALL caller=FUN_007c7f80@007c7f80
REF 007c8278 UNCONDITIONAL_CALL caller=FUN_007c7f80@007c7f80
REF 007c8290 UNCONDITIONAL_CALL caller=FUN_007c7f80@007c7f80
REF 007c82a8 UNCONDITIONAL_CALL caller=FUN_007c7f80@007c7f80
REF 007c82c0 UNCONDITIONAL_CALL caller=FUN_007c7f80@007c7f80
REF 007c8324 UNCONDITIONAL_CALL caller=FUN_007c7f80@007c7f80
REF 007c839c UNCONDITIONAL_CALL caller=FUN_007c7f80@007c7f80
REF 007c8444 UNCONDITIONAL_CALL caller=imvt_dpc_calib_run_calibration@007c83f8
REF 007c84a4 UNCONDITIONAL_CALL caller=imvt_dpc_calib_run_calibration@007c83f8
REF 007c85c0 UNCONDITIONAL_CALL caller=imvt_dpc_calib_run_calibration@007c83f8
REF 007c8628 UNCONDITIONAL_CALL caller=imvt_dpc_calib_run_calibration@007c83f8
REF 007c86c8 UNCONDITIONAL_CALL caller=imvt_dpc_calib_run_calibration@007c83f8
REF 007c8d1c UNCONDITIONAL_CALL caller=imvt_dpc_get_dp_static_table@007c88d0
REF 007c8d80 UNCONDITIONAL_CALL caller=imvt_dpc_get_dp_static_table@007c88d0
REF 007c91e4 UNCONDITIONAL_CALL caller=imvt_dpc_get_dp_static_table@007c88d0
REF 007c92d0 UNCONDITIONAL_CALL caller=imvt_dpc_get_dp_static_table@007c88d0
REF 007c918c UNCONDITIONAL_CALL caller=imvt_dpc_get_dp_static_table@007c88d0
REF 007c91c0 UNCONDITIONAL_CALL caller=imvt_dpc_get_dp_static_table@007c88d0
REF 007c93a0 UNCONDITIONAL_CALL caller=imvt_dpc_get_dp_static_table@007c88d0
REF 007c941c UNCONDITIONAL_CALL caller=imvt_dpc_get_dp_static_table@007c88d0
REF 007c9444 UNCONDITIONAL_CALL caller=imvt_dpc_get_dp_static_table@007c88d0
REF 007c946c UNCONDITIONAL_CALL caller=imvt_dpc_get_dp_static_table@007c88d0
REF 007c9490 UNCONDITIONAL_CALL caller=imvt_dpc_get_dp_static_table@007c88d0
REF 007c94b0 UNCONDITIONAL_CALL caller=imvt_dpc_get_dp_static_table@007c88d0
REF 007c94f4 UNCONDITIONAL_CALL caller=imvt_dpc_show_res@007c94c8
REF 007c951c UNCONDITIONAL_CALL caller=imvt_dpc_show_result@007c9508
REF 007c9538 UNCONDITIONAL_CALL caller=imvt_dpc_show_result@007c9508
REF 007c9750 UNCONDITIONAL_CALL caller=imvt_dpc_calib_require_all_calibration@007c96d0
REF 007c98d8 UNCONDITIONAL_CALL caller=FUN_007c9788@007c9788
REF 007c98ec UNCONDITIONAL_CALL caller=FUN_007c9788@007c9788
REF 007c9904 UNCONDITIONAL_CALL caller=FUN_007c9788@007c9788
REF 007c9928 UNCONDITIONAL_CALL caller=FUN_007c9788@007c9788
REF 007c9950 UNCONDITIONAL_CALL caller=FUN_007c9788@007c9788
REF 007c9960 UNCONDITIONAL_CALL caller=FUN_007c9788@007c9788
REF 007c9978 UNCONDITIONAL_CALL caller=FUN_007c9788@007c9788
REF 007c99a0 UNCONDITIONAL_CALL caller=FUN_007c9788@007c9788
REF 007c99c4 UNCONDITIONAL_CALL caller=FUN_007c9788@007c9788
REF 007c9aec UNCONDITIONAL_CALL caller=FUN_007c99d8@007c99d8
REF 007c9b24 UNCONDITIONAL_CALL caller=FUN_007c99d8@007c99d8
REF 007c9c5c UNCONDITIONAL_CALL caller=FUN_007c9b30@007c9b30
REF 007c9c88 UNCONDITIONAL_CALL caller=FUN_007c9b30@007c9b30
REF 007c9ca8 UNCONDITIONAL_CALL caller=FUN_007c9b30@007c9b30
REF 007c9d5c UNCONDITIONAL_CALL caller=FUN_007c9cb8@007c9cb8
REF 007c9e18 UNCONDITIONAL_CALL caller=FUN_007c9cb8@007c9cb8
REF 007c9efc UNCONDITIONAL_CALL caller=FUN_007c9cb8@007c9cb8
REF 007ca164 UNCONDITIONAL_CALL caller=imvt_blc_calib_init@007ca0a8
REF 007ca1ec UNCONDITIONAL_CALL caller=imvt_blc_calib_register_blc_param@007ca178
REF 007ca214 UNCONDITIONAL_CALL caller=imvt_blc_calib_register_blc_param@007ca178
REF 007ca434 UNCONDITIONAL_CALL caller=imvt_blc_calib_process_msg@007ca388
REF 007ca520 UNCONDITIONAL_CALL caller=imvt_blc_send_request_and_wait_all@007ca4c0
REF 007ca584 UNCONDITIONAL_CALL caller=imvt_blc_send_request_and_wait_all@007ca4c0
REF 007ca650 UNCONDITIONAL_CALL caller=imvt_blc_send_request_and_wait_all@007ca4c0
REF 007ca7a8 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007ca7fc UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007ca844 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007ca8e4 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007ca90c UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007ca980 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cab34 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007caad0 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cabbc UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cac24 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cacac UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cad18 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cad34 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cad74 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cad90 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cada8 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cae04 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cae90 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007caed0 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007caee8 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007caf2c UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007caf84 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cafa0 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 007cb048 UNCONDITIONAL_CALL caller=imvt_blc_calib_run_calibration@007ca720
REF 00a6688c UNCONDITIONAL_CALL caller=imvt_cam_adj_get_movie_blc_mode@00a66838
REF 00a668a8 UNCONDITIONAL_CALL caller=imvt_cam_adj_get_movie_blc_mode@00a66838
REF 007cb0f4 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_print@007cb080
REF 007cb150 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_print@007cb080
REF 007cb184 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_print@007cb080
REF 007cb1f8 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_print@007cb080
REF 007cb250 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_print@007cb080
REF 007cb328 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_print_shutter_only@007cb2a0
REF 007cb384 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_print_shutter_only@007cb2a0
REF 007cb3a4 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_print_shutter_only@007cb2a0
REF 007cb444 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_print_shutter_only@007cb2a0
REF 007cb4a8 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_print_shutter_only@007cb2a0
REF 007cb530 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_load@007cb4d8
REF 007cb550 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_load@007cb4d8
REF 007cb5b0 UNCONDITIONAL_CALL caller=imvt_blc_calib_shell_cmd_save@007cb560
REF 007cb704 UNCONDITIONAL_CALL caller=imvt_blc_calib_get_calib_table@007cb610
REF 007cb6ac UNCONDITIONAL_CALL caller=imvt_blc_calib_get_calib_table@007cb610
REF 007cb74c UNCONDITIONAL_CALL caller=imvt_blc_calib_get_calib_table@007cb610
REF 007cb7d0 UNCONDITIONAL_CALL caller=imvt_blc_calib_get_calib_table@007cb610
REF 007cb7e8 UNCONDITIONAL_CALL caller=imvt_blc_calib_get_calib_table@007cb610
REF 007cb818 UNCONDITIONAL_CALL caller=imvt_blc_calib_get_calib_table@007cb610
REF 007cb87c UNCONDITIONAL_CALL caller=imvt_blc_calib_get_calib_table@007cb610
REF 007cb978 UNCONDITIONAL_CALL caller=imvt_blc_calib_verify@007cb8b0
REF 007cb990 UNCONDITIONAL_CALL caller=imvt_blc_calib_verify@007cb8b0
REF 007cb9cc UNCONDITIONAL_CALL caller=imvt_blc_calib_verify@007cb8b0
REF 007cc0f8 UNCONDITIONAL_CALL caller=FUN_007cbff0@007cbff0
REF 007d1938 UNCONDITIONAL_CALL caller=imvt_fpn_impl_disable@007d18b0
REF 007d1964 UNCONDITIONAL_CALL caller=imvt_fpn_impl_disable@007d18b0
REF 007cc360 UNCONDITIONAL_CALL caller=imvt_fpn_calib_update_on_res@007cc130
REF 007cc3ac UNCONDITIONAL_CALL caller=imvt_fpn_calib_update_on_res@007cc130
REF 007cc3f8 UNCONDITIONAL_CALL caller=imvt_fpn_calib_update_on_res@007cc130
REF 007cc40c UNCONDITIONAL_CALL caller=imvt_fpn_calib_update_on_res@007cc130
REF 007cc424 UNCONDITIONAL_CALL caller=imvt_fpn_calib_update_on_res@007cc130
REF 007cc448 UNCONDITIONAL_CALL caller=imvt_fpn_calib_update_on_res@007cc130
REF 007cc464 UNCONDITIONAL_CALL caller=imvt_fpn_calib_update_on_res@007cc130
REF 007d1608 UNCONDITIONAL_CALL caller=imvt_fpn_impl_load@007d1468
REF 007d16a4 UNCONDITIONAL_CALL caller=imvt_fpn_impl_load@007d1468
REF 007d16bc UNCONDITIONAL_CALL caller=imvt_fpn_impl_load@007d1468
REF 007d16fc UNCONDITIONAL_CALL caller=imvt_fpn_impl_load@007d1468
REF 007d1718 UNCONDITIONAL_CALL caller=imvt_fpn_impl_load@007d1468
REF 007d172c UNCONDITIONAL_CALL caller=imvt_fpn_impl_load@007d1468
REF 007d0f68 UNCONDITIONAL_CALL caller=FUN_007d0ee0@007d0ee0
REF 007d0f80 UNCONDITIONAL_CALL caller=FUN_007d0ee0@007d0ee0
REF 007d10d4 UNCONDITIONAL_CALL caller=FUN_007d0f88@007d0f88
REF 007d10e8 UNCONDITIONAL_CALL caller=FUN_007d0f88@007d0f88
REF 007d1104 UNCONDITIONAL_CALL caller=FUN_007d0f88@007d0f88
REF 007d19cc UNCONDITIONAL_CALL caller=imvt_fpn_impl_enable@007d1970
REF 007d1a08 UNCONDITIONAL_CALL caller=imvt_fpn_impl_enable@007d1970
REF 007d1a24 UNCONDITIONAL_CALL caller=imvt_fpn_impl_enable@007d1970
REF 007cc624 UNCONDITIONAL_CALL caller=imvt_fpn_calib_init@007cc478
REF 007cc644 UNCONDITIONAL_CALL caller=imvt_fpn_calib_init@007cc478
REF 007cc658 UNCONDITIONAL_CALL caller=imvt_fpn_calib_init@007cc478
REF 007cc670 UNCONDITIONAL_CALL caller=imvt_fpn_calib_init@007cc478
REF 007cc690 UNCONDITIONAL_CALL caller=imvt_fpn_calib_init@007cc478
REF 007cc6b0 UNCONDITIONAL_CALL caller=imvt_fpn_calib_init@007cc478
REF 007cc6c0 UNCONDITIONAL_CALL caller=imvt_fpn_calib_init@007cc478
REF 007cc6d8 UNCONDITIONAL_CALL caller=imvt_fpn_calib_init@007cc478
REF 007cc6f8 UNCONDITIONAL_CALL caller=imvt_fpn_calib_init@007cc478
REF 007cc718 UNCONDITIONAL_CALL caller=imvt_fpn_calib_init@007cc478
REF 007d1860 UNCONDITIONAL_CALL caller=imvt_fpn_impl_init@007d1778
REF 007cc77c UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_prepare@007cc758
REF 007cc7ac UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_run@007cc798
REF 007cc918 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_test_cur_res@007cc7c0
REF 007cc95c UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_test_cur_res@007cc7c0
REF 007cca34 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_test_cur_res@007cc7c0
REF 007ccab8 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_test_cur_res@007cc7c0
REF 007ccad0 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_test_cur_res@007cc7c0
REF 007ccae4 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_test_cur_res@007cc7c0
REF 007d11a8 UNCONDITIONAL_CALL caller=imvt_fpn_impl_do_calib@007d1160
REF 007d1238 UNCONDITIONAL_CALL caller=imvt_fpn_impl_do_calib@007d1160
REF 007d125c UNCONDITIONAL_CALL caller=imvt_fpn_impl_do_calib@007d1160
REF 007d126c UNCONDITIONAL_CALL caller=imvt_fpn_impl_do_calib@007d1160
REF 007d12ec UNCONDITIONAL_CALL caller=imvt_fpn_impl_do_calib@007d1160
REF 007d1304 UNCONDITIONAL_CALL caller=imvt_fpn_impl_do_calib@007d1160
REF 007d1334 UNCONDITIONAL_CALL caller=imvt_fpn_impl_do_calib@007d1160
REF 007d1424 UNCONDITIONAL_CALL caller=imvt_fpn_impl_do_calib@007d1160
REF 007d1440 UNCONDITIONAL_CALL caller=imvt_fpn_impl_do_calib@007d1160
REF 007d1454 UNCONDITIONAL_CALL caller=imvt_fpn_impl_do_calib@007d1160
REF 007ccb6c UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_show_res@007ccaf8
REF 007ccb80 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_show_res@007ccaf8
REF 007ccb90 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_show_res@007ccaf8
REF 007ccc38 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_show_res@007ccaf8
REF 007ccc9c UNCONDITIONAL_CALL caller=imvt_fpn_calib_run_calibration@007ccc88
REF 007ccd60 UNCONDITIONAL_CALL caller=imvt_fpn_calib_process_msg@007cccb0
REF 007cce70 UNCONDITIONAL_CALL caller=imvt_fpn_send_request_and_wait_all@007cce10
REF 007cced4 UNCONDITIONAL_CALL caller=imvt_fpn_send_request_and_wait_all@007cce10
REF 007ccfa0 UNCONDITIONAL_CALL caller=imvt_fpn_send_request_and_wait_all@007cce10
REF 007cd26c UNCONDITIONAL_CALL caller=_fpn_calib_insert_result@007cd070
REF 007cd2dc UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_save@007cd280
REF 007cd388 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_save@007cd280
REF 007cd3d0 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_save@007cd280
REF 007cd408 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_save@007cd280
REF 007cd424 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_save@007cd280
REF 007cd474 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_show@007cd430
REF 007cd488 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_show@007cd430
REF 007cd4f0 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_show@007cd430
REF 007cd50c UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_show@007cd430
REF 007cd528 UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_show@007cd430
REF 007cd54c UNCONDITIONAL_CALL caller=imvt_fpn_calib_shell_show@007cd430
REF 007cd83c UNCONDITIONAL_CALL caller=FUN_007cd808@007cd808
REF 007cd84c UNCONDITIONAL_CALL caller=FUN_007cd808@007cd808
REF 007cd85c UNCONDITIONAL_CALL caller=FUN_007cd808@007cd808
REF 007cd86c UNCONDITIONAL_CALL caller=FUN_007cd808@007cd808
REF 007cdb7c UNCONDITIONAL_CALL caller=FUN_007cda68@007cda68
REF 007cdbb4 UNCONDITIONAL_CALL caller=FUN_007cda68@007cda68
REF 007cdca0 UNCONDITIONAL_CALL caller=FUN_007cdc20@007cdc20
REF 007cdcc4 UNCONDITIONAL_CALL caller=FUN_007cdc20@007cdc20
REF 007cdd34 UNCONDITIONAL_CALL caller=FUN_007cdc20@007cdc20
REF 007cdd74 UNCONDITIONAL_CALL caller=FUN_007cdc20@007cdc20
REF 007ce1c0 UNCONDITIONAL_CALL caller=FUN_007ce118@007ce118
REF 007ce20c UNCONDITIONAL_CALL caller=FUN_007ce118@007ce118
REF 007ce344 UNCONDITIONAL_CALL caller=FUN_007ce118@007ce118
REF 007ce404 UNCONDITIONAL_CALL caller=FUN_007ce118@007ce118
REF 007ce450 UNCONDITIONAL_CALL caller=FUN_007ce118@007ce118
REF 007ce578 UNCONDITIONAL_CALL caller=FUN_007ce118@007ce118
REF 007ce5a8 UNCONDITIONAL_CALL caller=FUN_007ce118@007ce118
REF 007ce5cc UNCONDITIONAL_CALL caller=FUN_007ce118@007ce118
REF 007ce610 UNCONDITIONAL_CALL caller=FUN_007ce118@007ce118
REF 007ce644 UNCONDITIONAL_CALL caller=FUN_007ce118@007ce118
REF 007ce6e0 UNCONDITIONAL_CALL caller=FUN_007ce660@007ce660
REF 007ce720 UNCONDITIONAL_CALL caller=FUN_007ce660@007ce660
REF 007ce788 UNCONDITIONAL_CALL caller=FUN_007ce660@007ce660
REF 007ce7c8 UNCONDITIONAL_CALL caller=FUN_007ce660@007ce660
REF 007ce838 UNCONDITIONAL_CALL caller=FUN_007ce660@007ce660
REF 007ce8a0 UNCONDITIONAL_CALL caller=FUN_007ce848@007ce848
REF 007ce9b0 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_get_blc_table@007ce8b0
REF 007ce9c0 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_get_blc_table@007ce8b0
REF 007ceaac UNCONDITIONAL_CALL caller=imvt_blc_calib_high_get_blc_table@007ce8b0
REF 007ceaf0 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_get_blc_table@007ce8b0
REF 007ceb04 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_get_blc_table@007ce8b0
REF 007ceb1c UNCONDITIONAL_CALL caller=imvt_blc_calib_high_get_blc_table@007ce8b0
REF 007ceb50 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_get_blc_table@007ce8b0
REF 007ceb6c UNCONDITIONAL_CALL caller=imvt_blc_calib_high_get_blc_table@007ce8b0
REF 007cf084 UNCONDITIONAL_CALL caller=FUN_007cf030@007cf030
REF 007cf128 UNCONDITIONAL_CALL caller=FUN_007cf030@007cf030
REF 007cf170 UNCONDITIONAL_CALL caller=FUN_007cf030@007cf030
REF 007cf1a8 UNCONDITIONAL_CALL caller=FUN_007cf030@007cf030
REF 007cf1c4 UNCONDITIONAL_CALL caller=FUN_007cf030@007cf030
REF 007cf328 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_run@007cf1e8
REF 007cf368 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_run@007cf1e8
REF 007cf3dc UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_run@007cf1e8
REF 007cf420 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_run@007cf1e8
REF 007cf4a0 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_run@007cf1e8
REF 007cf5dc UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_run@007cf1e8
REF 007cf5f4 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_run@007cf1e8
REF 007cf708 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_test_cur_res@007cf628
REF 007cf74c UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_test_cur_res@007cf628
REF 007cf770 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_test_cur_res@007cf628
REF 007cf784 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_test_cur_res@007cf628
REF 007cf810 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_show_res@007cf798
REF 007cf824 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_show_res@007cf798
REF 007cf8b0 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_show_res@007cf798
REF 007cf9b8 UNCONDITIONAL_CALL caller=imvt_blc_high_calib_process_msg@007cf908
REF 007cfab0 UNCONDITIONAL_CALL caller=imvt_blc_high_send_request_and_wait_all@007cfa50
REF 007cfb14 UNCONDITIONAL_CALL caller=imvt_blc_high_send_request_and_wait_all@007cfa50
REF 007cfbe0 UNCONDITIONAL_CALL caller=imvt_blc_high_send_request_and_wait_all@007cfa50
REF 007cfd30 UNCONDITIONAL_CALL caller=FUN_007cfcb0@007cfcb0
REF 007cfd44 UNCONDITIONAL_CALL caller=FUN_007cfcb0@007cfcb0
REF 007cfda8 UNCONDITIONAL_CALL caller=FUN_007cfcb0@007cfcb0
REF 007cfd84 UNCONDITIONAL_CALL caller=FUN_007cfcb0@007cfcb0
REF 007cfeb4 UNCONDITIONAL_CALL caller=FUN_007cfcb0@007cfcb0
REF 007cfeec UNCONDITIONAL_CALL caller=FUN_007cfcb0@007cfcb0
REF 007cfe34 UNCONDITIONAL_CALL caller=FUN_007cfcb0@007cfcb0
REF 0088e6e4 UNCONDITIONAL_CALL caller=imvt_n3a_ae_get_average_ae_sum@0088e650
REF 0088e708 UNCONDITIONAL_CALL caller=imvt_n3a_ae_get_average_ae_sum@0088e650
REF 007d00b8 UNCONDITIONAL_CALL caller=imvt_blc_high_calib_run_calibration@007cffe8
REF 007d00f4 UNCONDITIONAL_CALL caller=imvt_blc_high_calib_run_calibration@007cffe8
REF 007d01a8 UNCONDITIONAL_CALL caller=imvt_blc_high_calib_run_calibration@007cffe8
REF 007d0240 UNCONDITIONAL_CALL caller=imvt_blc_high_calib_run_calibration@007cffe8
REF 007d0458 UNCONDITIONAL_CALL caller=_blc_calib_insert_table@007d02d8
REF 007d04b8 UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d0558 UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d056c UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d0584 UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d059c UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d05b0 UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d05c4 UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d05d8 UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d05fc UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d0674 UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d070c UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d072c UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d076c UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d07b8 UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d07e4 UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d07fc UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d081c UNCONDITIONAL_CALL caller=FUN_007d0468@007d0468
REF 007d08ac UNCONDITIONAL_CALL caller=FUN_007d0858@007d0858
REF 007d08c4 UNCONDITIONAL_CALL caller=FUN_007d0858@007d0858
REF 007d08d0 UNCONDITIONAL_CALL caller=FUN_007d0858@007d0858
REF 007d08f0 UNCONDITIONAL_CALL caller=FUN_007d0858@007d0858
REF 007d0a70 UNCONDITIONAL_CALL caller=FUN_007d0858@007d0858
REF 007d0a9c UNCONDITIONAL_CALL caller=FUN_007d0858@007d0858
REF 007d0ad8 UNCONDITIONAL_CALL caller=FUN_007d0858@007d0858
REF 007d0b28 UNCONDITIONAL_CALL caller=FUN_007d0858@007d0858
REF 007d0b38 UNCONDITIONAL_CALL caller=FUN_007d0858@007d0858
REF 007d0b90 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_show@007d0b60
REF 007d0ba4 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_show@007d0b60
REF 007d0c00 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_show@007d0b60
REF 007d0c1c UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_show@007d0b60
REF 007d0c40 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_show@007d0b60
REF 007d0c70 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_show@007d0b60
REF 007d0c94 UNCONDITIONAL_CALL caller=imvt_blc_calib_high_shell_show@007d0b60
REF 007d0d1c UNCONDITIONAL_CALL caller=imvt_blc_high_calib_enable_calibration@007d0ce0
REF 007d1f44 UNCONDITIONAL_CALL caller=FUN_007d1e00@007d1e00
REF 007d237c UNCONDITIONAL_CALL caller=FUN_007d2328@007d2328
REF 007d239c UNCONDITIONAL_CALL caller=FUN_007d2328@007d2328
REF 007d2cb0 UNCONDITIONAL_CALL caller=FUN_007d29d8@007d29d8
REF 007d2d50 UNCONDITIONAL_CALL caller=FUN_007d29d8@007d29d8
REF 007d2e0c UNCONDITIONAL_CALL caller=FUN_007d29d8@007d29d8
REF 007d2f54 UNCONDITIONAL_CALL caller=FUN_007d29d8@007d29d8
REF 007d360c UNCONDITIONAL_CALL caller=FUN_007d34c8@007d34c8
REF 007d37bc UNCONDITIONAL_CALL caller=FUN_007d3768@007d3768
REF 007d37dc UNCONDITIONAL_CALL caller=FUN_007d3768@007d3768
REF 007d38dc UNCONDITIONAL_CALL caller=FUN_007d37e8@007d37e8
REF 007d3978 UNCONDITIONAL_CALL caller=FUN_007d38f0@007d38f0
REF 007d3dbc UNCONDITIONAL_CALL caller=FUN_007d3a10@007d3a10
REF 007d4268 UNCONDITIONAL_CALL caller=FUN_007d3dd8@007d3dd8
REF 007d451c UNCONDITIONAL_CALL caller=naming_reelname_compute_media_num_init@007d44c8
REF 007d4aa4 UNCONDITIONAL_CALL caller=naming_reelname_scan_dcim@007d4890
REF 007d4bfc UNCONDITIONAL_CALL caller=naming_reelname_scan_dcim@007d4890
REF 007d83b8 UNCONDITIONAL_CALL caller=FUN_007d81a8@007d81a8
REF 007e1cfc UNCONDITIONAL_CALL caller=enqueuePubMsg@007e1bc8
REF 007e203c UNCONDITIONAL_CALL caller=enqueueEvent@007e1f08
REF 007e7f84 UNCONDITIONAL_CALL caller=FUN_007e7de8@007e7de8
REF 007e8530 UNCONDITIONAL_CALL caller=FUN_007e8498@007e8498
REF 007e85c8 UNCONDITIONAL_CALL caller=print_current_speed_param@007e8598
REF 007e85ec UNCONDITIONAL_CALL caller=print_current_speed_param@007e8598
REF 007e8600 UNCONDITIONAL_CALL caller=print_current_speed_param@007e8598
REF 007e8614 UNCONDITIONAL_CALL caller=print_current_speed_param@007e8598
REF 007e8628 UNCONDITIONAL_CALL caller=print_current_speed_param@007e8598
REF 007e863c UNCONDITIONAL_CALL caller=print_current_speed_param@007e8598
REF 007e8650 UNCONDITIONAL_CALL caller=print_current_speed_param@007e8598
REF 007e8664 UNCONDITIONAL_CALL caller=print_current_speed_param@007e8598
REF 007e87f4 UNCONDITIONAL_CALL caller=imvt_nnie_ptz_debug_flen@007e8770
REF 007e8808 UNCONDITIONAL_CALL caller=imvt_nnie_ptz_debug_flen@007e8770
REF 007e899c UNCONDITIONAL_CALL caller=FUN_007e897c@007e897c
REF 007e8a2c UNCONDITIONAL_CALL caller=FUN_007e8a14@007e8a14
REF 007e8bc0 UNCONDITIONAL_CALL caller=imvt_nnie_ptz_handle_detection@007e8a38
REF 007e8ca8 UNCONDITIONAL_CALL caller=imvt_nnie_ptz_handle_detection@007e8a38
REF 007e8e2c UNCONDITIONAL_CALL caller=imvt_nnie_ptz_handle_detection@007e8a38
REF 007e8e54 UNCONDITIONAL_CALL caller=imvt_nnie_ptz_handle_detection@007e8a38
REF 007e8ee4 UNCONDITIONAL_CALL caller=imvt_nnie_ptz_enable_af@007e8e68
REF 007e9238 UNCONDITIONAL_CALL caller=FUN_007e9010@007e9010
REF 007e9358 UNCONDITIONAL_CALL caller=FUN_007e9010@007e9010
REF 007e9374 UNCONDITIONAL_CALL caller=FUN_007e9010@007e9010
REF 00d319e0 UNCONDITIONAL_CALL caller=imvt_tracker_run@00d31910
REF 00d31ad0 UNCONDITIONAL_CALL caller=imvt_tracker_run@00d31910
REF 00d31b28 UNCONDITIONAL_CALL caller=imvt_tracker_run@00d31910
REF 007e93c0 UNCONDITIONAL_CALL caller=FUN_007e9390@007e9390
REF 007e9530 UNCONDITIONAL_CALL caller=FUN_007e9430@007e9430
REF 007e9684 UNCONDITIONAL_CALL caller=FUN_007e9430@007e9430
REF 007e969c UNCONDITIONAL_CALL caller=FUN_007e9430@007e9430
REF 007e970c UNCONDITIONAL_CALL caller=FUN_007e9430@007e9430
REF 007e974c UNCONDITIONAL_CALL caller=FUN_007e9430@007e9430
REF 007e9814 UNCONDITIONAL_CALL caller=FUN_007e9430@007e9430
REF 007e9adc UNCONDITIONAL_CALL caller=FUN_007e9a50@007e9a50
REF 007e9b4c UNCONDITIONAL_CALL caller=FUN_007e9a50@007e9a50
REF 00d31d6c UNCONDITIONAL_CALL caller=imvt_tracker_init@00d31bb0
REF 00d31da8 UNCONDITIONAL_CALL caller=imvt_tracker_init@00d31bb0
REF 00d31df0 UNCONDITIONAL_CALL caller=imvt_tracker_init@00d31bb0
REF 00d31e18 UNCONDITIONAL_CALL caller=imvt_tracker_init@00d31bb0
REF 00d32764 UNCONDITIONAL_CALL caller=imvt_nnie_model_load@00d32668
REF 00d327c0 UNCONDITIONAL_CALL caller=imvt_nnie_model_load@00d32668
REF 00d327dc UNCONDITIONAL_CALL caller=imvt_nnie_model_load@00d32668
REF 00d327fc UNCONDITIONAL_CALL caller=imvt_nnie_model_load@00d32668
REF 00d3281c UNCONDITIONAL_CALL caller=imvt_nnie_model_load@00d32668
REF 00d3283c UNCONDITIONAL_CALL caller=imvt_nnie_model_load@00d32668
REF 00d32944 UNCONDITIONAL_CALL caller=imvt_nnie_param_init@00d328f8
REF 00d3295c UNCONDITIONAL_CALL caller=imvt_nnie_param_init@00d328f8
REF 00d325f0 UNCONDITIONAL_CALL caller=FUN_00d31f58@00d31f58
REF 00d32608 UNCONDITIONAL_CALL caller=FUN_00d31f58@00d31f58
REF 007e9ec0 UNCONDITIONAL_CALL caller=imvt_nnie_set_resolution_changed@007e9e18
REF 007e9ee0 UNCONDITIONAL_CALL caller=imvt_nnie_set_resolution_changed@007e9e18
REF 007e9f34 UNCONDITIONAL_CALL caller=imvt_nnie_set_probility@007e9ef0
REF 007e9f70 UNCONDITIONAL_CALL caller=imvt_nnie_set_probility@007e9ef0
REF 007e9f94 UNCONDITIONAL_CALL caller=imvt_nnie_set_probility@007e9ef0
REF 007ea084 UNCONDITIONAL_CALL caller=imvt_nnie_enable_log@007ea050
REF 007ea644 UNCONDITIONAL_CALL caller=imvt_nnie_crop_set_rect@007ea5a8
REF 007ea728 UNCONDITIONAL_CALL caller=imvt_nnie_crop_set_rect2@007ea678
REF 007ea7dc UNCONDITIONAL_CALL caller=imvt_nnie_crop_set_speed@007ea790
REF 007ea7f0 UNCONDITIONAL_CALL caller=imvt_nnie_crop_set_speed@007ea790
REF 007ea830 UNCONDITIONAL_CALL caller=imvt_nnie_crop_set_padding@007ea800
REF 00801718 UNCONDITIONAL_CALL caller=debugLogStatus@008016e0
REF 00801740 UNCONDITIONAL_CALL caller=debugLogStatus@008016e0
REF 00801750 UNCONDITIONAL_CALL caller=debugLogStatus@008016e0
REF 0080177c UNCONDITIONAL_CALL caller=debugLogStatus@008016e0
REF 008017a8 UNCONDITIONAL_CALL caller=debugLogStatus@008016e0
REF 008017d4 UNCONDITIONAL_CALL caller=debugLogStatus@008016e0
REF 008017f8 UNCONDITIONAL_CALL caller=debugLogStatus@008016e0
REF 0080182c UNCONDITIONAL_CALL caller=debugLogStatus@008016e0
REF 00801848 UNCONDITIONAL_CALL caller=debugLogStatus@008016e0
REF 00801868 UNCONDITIONAL_CALL caller=debugLogStatus@008016e0
REF 008018a4 UNCONDITIONAL_CALL caller=debugLogStatus@008016e0
REF 008047c8 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 00805328 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 00805404 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 0080466c UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 008054e0 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 00805658 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 00805708 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 00805728 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 00805778 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 00805798 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 008057b8 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 008057d4 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 008057f8 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 00805870 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 00805890 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 0080a0bc UNCONDITIONAL_CALL caller=t_uart_controller_transport_broadcast_handle@0080a098
REF 0080a0d4 UNCONDITIONAL_CALL caller=t_uart_controller_transport_broadcast_handle@0080a098
REF 0080a3dc UNCONDITIONAL_CALL caller=FUN_0080a378@0080a378
REF 0080a670 UNCONDITIONAL_CALL caller=FUN_0080a5c8@0080a5c8
REF 0080a75c UNCONDITIONAL_CALL caller=FUN_0080a6d0@0080a6d0
REF 0080a7bc UNCONDITIONAL_CALL caller=FUN_0080a7a0@0080a7a0
REF 0080a8ac UNCONDITIONAL_CALL caller=FUN_0080a810@0080a810
REF 0080a930 UNCONDITIONAL_CALL caller=FUN_0080a8f8@0080a8f8
REF 0080a964 UNCONDITIONAL_CALL caller=FUN_0080a8f8@0080a8f8
REF 0080a9cc UNCONDITIONAL_CALL caller=FUN_0080a988@0080a988
REF 0080a9ec UNCONDITIONAL_CALL caller=FUN_0080a988@0080a988
REF 0080aa40 UNCONDITIONAL_CALL caller=FUN_0080a9f8@0080a9f8
REF 0080ab54 UNCONDITIONAL_CALL caller=FUN_0080aa88@0080aa88
REF 0080aba0 UNCONDITIONAL_CALL caller=FUN_0080aa88@0080aa88
REF 0080ac04 UNCONDITIONAL_CALL caller=FUN_0080aa88@0080aa88
REF 0080ac1c UNCONDITIONAL_CALL caller=FUN_0080aa88@0080aa88
REF 0080ac74 UNCONDITIONAL_CALL caller=FUN_0080ac30@0080ac30
REF 0080acd8 UNCONDITIONAL_CALL caller=FUN_0080aca0@0080aca0
REF 0080acf0 UNCONDITIONAL_CALL caller=FUN_0080aca0@0080aca0
REF 0080ad08 UNCONDITIONAL_CALL caller=FUN_0080aca0@0080aca0
REF 0080ad20 UNCONDITIONAL_CALL caller=FUN_0080aca0@0080aca0
REF 0080ad38 UNCONDITIONAL_CALL caller=FUN_0080aca0@0080aca0
REF 0080adb4 UNCONDITIONAL_CALL caller=FUN_0080ad68@0080ad68
REF 0080b03c UNCONDITIONAL_CALL caller=FUN_0080af80@0080af80
REF 0080b374 UNCONDITIONAL_CALL caller=FUN_0080b2b0@0080b2b0
REF 0080b388 UNCONDITIONAL_CALL caller=FUN_0080b2b0@0080b2b0
REF 0080b4e8 UNCONDITIONAL_CALL caller=FUN_0080b488@0080b488
REF 0080b514 UNCONDITIONAL_CALL caller=FUN_0080b488@0080b488
REF 0080b53c UNCONDITIONAL_CALL caller=FUN_0080b488@0080b488
REF 0080b564 UNCONDITIONAL_CALL caller=FUN_0080b488@0080b488
REF 0080b670 UNCONDITIONAL_CALL caller=t_uart_controller_transport_reponse_handle@0080b640
REF 0080b688 UNCONDITIONAL_CALL caller=t_uart_controller_transport_reponse_handle@0080b640
REF 0080b810 UNCONDITIONAL_CALL caller=FUN_0080b7e8@0080b7e8
REF 0080b82c UNCONDITIONAL_CALL caller=FUN_0080b7e8@0080b7e8
REF 0080b84c UNCONDITIONAL_CALL caller=FUN_0080b7e8@0080b7e8
REF 0080b890 UNCONDITIONAL_CALL caller=FUN_0080b860@0080b860
REF 0080b958 UNCONDITIONAL_CALL caller=FUN_0080b8d8@0080b8d8
REF 0080b9dc UNCONDITIONAL_CALL caller=FUN_0080b978@0080b978
REF 0080ba64 UNCONDITIONAL_CALL caller=FUN_0080b9f0@0080b9f0
REF 0080ba9c UNCONDITIONAL_CALL caller=FUN_0080b9f0@0080b9f0
REF 0080bab4 UNCONDITIONAL_CALL caller=FUN_0080b9f0@0080b9f0
REF 0080bad4 UNCONDITIONAL_CALL caller=FUN_0080b9f0@0080b9f0
REF 0080bae8 UNCONDITIONAL_CALL caller=FUN_0080b9f0@0080b9f0
REF 0080bb14 UNCONDITIONAL_CALL caller=FUN_0080b9f0@0080b9f0
REF 0080bb40 UNCONDITIONAL_CALL caller=FUN_0080b9f0@0080b9f0
REF 0080bb6c UNCONDITIONAL_CALL caller=FUN_0080bb50@0080bb50
REF 0080bc2c UNCONDITIONAL_CALL caller=FUN_0080bb98@0080bb98
REF 0080bcb4 UNCONDITIONAL_CALL caller=FUN_0080bc40@0080bc40
REF 0080bd04 UNCONDITIONAL_CALL caller=FUN_0080bc40@0080bc40
REF 0080bd7c UNCONDITIONAL_CALL caller=FUN_0080bd60@0080bd60
REF 0080be20 UNCONDITIONAL_CALL caller=FUN_0080bd98@0080bd98
REF 0080bed4 UNCONDITIONAL_CALL caller=FUN_0080beb8@0080beb8
REF 0080bf34 UNCONDITIONAL_CALL caller=FUN_0080bf00@0080bf00
REF 008213c8 UNCONDITIONAL_CALL caller=wifi_disconnect_network@00821230
REF 008213e0 UNCONDITIONAL_CALL caller=wifi_disconnect_network@00821230
REF 00821404 UNCONDITIONAL_CALL caller=wifi_disconnect_network@00821230
REF 0080bff0 UNCONDITIONAL_CALL caller=FUN_0080bf48@0080bf48
REF 0080c00c UNCONDITIONAL_CALL caller=FUN_0080bf48@0080bf48
REF 0080c0b4 UNCONDITIONAL_CALL caller=FUN_0080c020@0080c020
REF 0080c0ec UNCONDITIONAL_CALL caller=FUN_0080c020@0080c020
REF 0080c100 UNCONDITIONAL_CALL caller=FUN_0080c020@0080c020
REF 0081fdc0 UNCONDITIONAL_CALL caller=wifi_get_connect_ap_info@0081fcb0
REF 0081fde8 UNCONDITIONAL_CALL caller=wifi_get_connect_ap_info@0081fcb0
REF 0080c174 UNCONDITIONAL_CALL caller=FUN_0080c110@0080c110
REF 0080c1a4 UNCONDITIONAL_CALL caller=FUN_0080c110@0080c110
REF 0080c1f0 UNCONDITIONAL_CALL caller=FUN_0080c110@0080c110
REF 0080c2bc UNCONDITIONAL_CALL caller=FUN_0080c288@0080c288
REF 0080c2cc UNCONDITIONAL_CALL caller=FUN_0080c288@0080c288
REF 0080c314 UNCONDITIONAL_CALL caller=FUN_0080c2e0@0080c2e0
REF 0080c324 UNCONDITIONAL_CALL caller=FUN_0080c2e0@0080c2e0
REF 0080c374 UNCONDITIONAL_CALL caller=FUN_0080c338@0080c338
REF 0080c384 UNCONDITIONAL_CALL caller=FUN_0080c338@0080c338
REF 0080c394 UNCONDITIONAL_CALL caller=FUN_0080c338@0080c338
REF 0080c3e4 UNCONDITIONAL_CALL caller=FUN_0080c3a8@0080c3a8
REF 0080c3f4 UNCONDITIONAL_CALL caller=FUN_0080c3a8@0080c3a8
REF 0080c404 UNCONDITIONAL_CALL caller=FUN_0080c3a8@0080c3a8
REF 0080c414 UNCONDITIONAL_CALL caller=FUN_0080c3a8@0080c3a8
REF 0080c424 UNCONDITIONAL_CALL caller=FUN_0080c3a8@0080c3a8
REF 0080c4e4 UNCONDITIONAL_CALL caller=FUN_0080c438@0080c438
REF 0080c4fc UNCONDITIONAL_CALL caller=FUN_0080c438@0080c438
REF 0080c560 UNCONDITIONAL_CALL caller=FUN_0080c508@0080c508
REF 0080c5b0 UNCONDITIONAL_CALL caller=FUN_0080c508@0080c508
REF 0080c5c8 UNCONDITIONAL_CALL caller=FUN_0080c508@0080c508
REF 0080c62c UNCONDITIONAL_CALL caller=FUN_0080c5f8@0080c5f8
REF 0080c678 UNCONDITIONAL_CALL caller=FUN_0080c640@0080c640
REF 0080c6a4 UNCONDITIONAL_CALL caller=FUN_0080c640@0080c640
REF 0080c6bc UNCONDITIONAL_CALL caller=FUN_0080c640@0080c640
REF 0080c730 UNCONDITIONAL_CALL caller=FUN_0080c6c8@0080c6c8
REF 0080c74c UNCONDITIONAL_CALL caller=FUN_0080c6c8@0080c6c8
REF 0080c764 UNCONDITIONAL_CALL caller=FUN_0080c6c8@0080c6c8
REF 0080c7a4 UNCONDITIONAL_CALL caller=FUN_0080c770@0080c770
REF 0080c7c4 UNCONDITIONAL_CALL caller=FUN_0080c770@0080c770
REF 0080c868 UNCONDITIONAL_CALL caller=FUN_0080c7d8@0080c7d8
REF 0080c87c UNCONDITIONAL_CALL caller=FUN_0080c7d8@0080c7d8
REF 0080c8e8 UNCONDITIONAL_CALL caller=FUN_0080c888@0080c888
REF 0080c918 UNCONDITIONAL_CALL caller=FUN_0080c888@0080c888
REF 0080c9b0 UNCONDITIONAL_CALL caller=FUN_0080c950@0080c950
REF 0080c9e0 UNCONDITIONAL_CALL caller=FUN_0080c950@0080c950
REF 0080ca78 UNCONDITIONAL_CALL caller=FUN_0080ca18@0080ca18
REF 0080caa8 UNCONDITIONAL_CALL caller=FUN_0080ca18@0080ca18
REF 0080cb0c UNCONDITIONAL_CALL caller=FUN_0080cae0@0080cae0
REF 0080cb60 UNCONDITIONAL_CALL caller=FUN_0080cae0@0080cae0
REF 0080cba4 UNCONDITIONAL_CALL caller=FUN_0080cae0@0080cae0
REF 0080cbfc UNCONDITIONAL_CALL caller=FUN_0080cbb8@0080cbb8
REF 0080cd0c UNCONDITIONAL_CALL caller=FUN_0080cc80@0080cc80
REF 0080cd88 UNCONDITIONAL_CALL caller=FUN_0080cd20@0080cd20
REF 0080cda4 UNCONDITIONAL_CALL caller=FUN_0080cd20@0080cd20
REF 0080cdbc UNCONDITIONAL_CALL caller=FUN_0080cd20@0080cd20
REF 0080ce48 UNCONDITIONAL_CALL caller=shell_run_t_cmd@0080cdc8
REF 0080ce6c UNCONDITIONAL_CALL caller=shell_run_t_cmd@0080cdc8
REF 0080cec4 UNCONDITIONAL_CALL caller=shell_run_t_cmd@0080cdc8
REF 0080cee0 UNCONDITIONAL_CALL caller=shell_run_t_cmd@0080cdc8
REF 0080d3d0 UNCONDITIONAL_CALL caller=FUN_0080d388@0080d388
REF 0080d478 UNCONDITIONAL_CALL caller=FUN_0080d430@0080d430
REF 0080d510 UNCONDITIONAL_CALL caller=FUN_0080d4d8@0080d4d8
REF 0080d554 UNCONDITIONAL_CALL caller=FUN_0080d538@0080d538
REF 0080d690 UNCONDITIONAL_CALL caller=FUN_0080d660@0080d660
REF 0080d724 UNCONDITIONAL_CALL caller=FUN_0080d6e0@0080d6e0
REF 0080d784 UNCONDITIONAL_CALL caller=FUN_0080d740@0080d740
REF 0080d838 UNCONDITIONAL_CALL caller=FUN_0080d7d0@0080d7d0
REF 0080d874 UNCONDITIONAL_CALL caller=FUN_0080d7d0@0080d7d0
REF 0080d884 UNCONDITIONAL_CALL caller=FUN_0080d7d0@0080d7d0
REF 0080d8f4 UNCONDITIONAL_CALL caller=FUN_0080d7d0@0080d7d0
REF 0080da40 UNCONDITIONAL_CALL caller=FUN_0080d7d0@0080d7d0
REF 00b95af8 UNCONDITIONAL_CALL caller=sensor_get_readout_time@00b95a40
REF 00b95948 UNCONDITIONAL_CALL caller=sensor_get_readout_info@00b95908
REF 0080da88 UNCONDITIONAL_CALL caller=FUN_0080da68@0080da68
REF 0086fa14 UNCONDITIONAL_CALL caller=imvt_cam_movie_get_timelapse_interval@0086f980
REF 0086fa54 UNCONDITIONAL_CALL caller=imvt_cam_movie_get_timelapse_interval@0086f980
REF 0086fa94 UNCONDITIONAL_CALL caller=imvt_cam_movie_get_timelapse_interval@0086f980
REF 0086faac UNCONDITIONAL_CALL caller=imvt_cam_movie_get_timelapse_interval@0086f980
REF 0086fac4 UNCONDITIONAL_CALL caller=imvt_cam_movie_get_timelapse_interval@0086f980
REF 0080daec UNCONDITIONAL_CALL caller=FUN_0080da98@0080da98
REF 0080db68 UNCONDITIONAL_CALL caller=FUN_0080da98@0080da98
REF 0080dbc0 UNCONDITIONAL_CALL caller=FUN_0080da98@0080da98
REF 0080dbec UNCONDITIONAL_CALL caller=FUN_0080da98@0080da98
REF 0080dc54 UNCONDITIONAL_CALL caller=FUN_0080da98@0080da98
REF 0080dc9c UNCONDITIONAL_CALL caller=FUN_0080da98@0080da98
REF 0080dd3c UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080dde4 UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080ddf4 UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080de04 UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080de14 UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080de24 UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080de34 UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080de40 UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080de4c UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080de5c UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080dea0 UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080dec8 UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080df2c UNCONDITIONAL_CALL caller=FUN_0080dca8@0080dca8
REF 0080e044 UNCONDITIONAL_CALL caller=FUN_0080e010@0080e010
REF 0086dba4 UNCONDITIONAL_CALL caller=imvt_cam_movie_enable_proxy_track@0086db50
REF 0080e0b4 UNCONDITIONAL_CALL caller=FUN_0080e058@0080e058
REF 0086dc98 UNCONDITIONAL_CALL caller=imvt_movie_update_fps@0086dbb0
REF 0086ddf0 UNCONDITIONAL_CALL caller=imvt_movie_update_fps@0086dbb0
REF 0086de2c UNCONDITIONAL_CALL caller=imvt_movie_update_fps@0086dbb0
REF 0086de78 UNCONDITIONAL_CALL caller=imvt_movie_update_fps@0086dbb0
REF 0080e114 UNCONDITIONAL_CALL caller=FUN_0080e0c8@0080e0c8
REF 0080e140 UNCONDITIONAL_CALL caller=FUN_0080e0c8@0080e0c8
REF 0080e4f8 UNCONDITIONAL_CALL caller=FUN_0080e420@0080e420
REF 0080e508 UNCONDITIONAL_CALL caller=FUN_0080e420@0080e420
REF 0080e518 UNCONDITIONAL_CALL caller=FUN_0080e420@0080e420
REF 0080e528 UNCONDITIONAL_CALL caller=FUN_0080e420@0080e420
REF 0080e534 UNCONDITIONAL_CALL caller=FUN_0080e420@0080e420
REF 0088eb58 UNCONDITIONAL_CALL caller=imvt_aaa_ae_set_bracketing@0088eaf0
REF 0088eba4 UNCONDITIONAL_CALL caller=imvt_aaa_ae_set_bracketing@0088eaf0
REF 0088ebc8 UNCONDITIONAL_CALL caller=imvt_aaa_ae_set_bracketing@0088eaf0
REF 0088ebec UNCONDITIONAL_CALL caller=imvt_aaa_ae_set_bracketing@0088eaf0
REF 0088ec0c UNCONDITIONAL_CALL caller=imvt_aaa_ae_set_bracketing@0088eaf0
REF 0080e57c UNCONDITIONAL_CALL caller=FUN_0080e540@0080e540
REF 00abb87c UNCONDITIONAL_CALL caller=imvt_raw_bpc_debug_load_bad_pixel@00abb758
REF 00abb6ec UNCONDITIONAL_CALL caller=imvt_raw_bpc_debug_save_bad_pixel@00abb618
REF 00abb734 UNCONDITIONAL_CALL caller=imvt_raw_bpc_debug_save_bad_pixel@00abb618
REF 00abb8d0 UNCONDITIONAL_CALL caller=imvt_raw_bpc_debug_gen_random_bad_pixel@00abb890
REF 00abb8e4 UNCONDITIONAL_CALL caller=imvt_raw_bpc_debug_gen_random_bad_pixel@00abb890
REF 00abb8f4 UNCONDITIONAL_CALL caller=imvt_raw_bpc_debug_gen_random_bad_pixel@00abb890
REF 00abb9a0 UNCONDITIONAL_CALL caller=imvt_raw_bpc_debug_gen_random_bad_pixel@00abb890
REF 00abb2ec UNCONDITIONAL_CALL caller=calc_bad_pixel_for_round2@00abb290
REF 00abb408 UNCONDITIONAL_CALL caller=calc_bad_pixel_for_round2@00abb290
REF 00abb598 UNCONDITIONAL_CALL caller=FUN_00abb470@00abb470
REF 00abb5bc UNCONDITIONAL_CALL caller=FUN_00abb470@00abb470
REF 00abb27c UNCONDITIONAL_CALL caller=insert_bad_pixel_for_round2@00abb1f8
REF 00ab9fc4 UNCONDITIONAL_CALL caller=imvt_raw_blc_status@00ab9fa0
REF 00ab9fe0 UNCONDITIONAL_CALL caller=imvt_raw_blc_status@00ab9fa0
REF 00ab9ff4 UNCONDITIONAL_CALL caller=imvt_raw_blc_status@00ab9fa0
REF 00aba010 UNCONDITIONAL_CALL caller=imvt_raw_blc_status@00ab9fa0
REF 00aba038 UNCONDITIONAL_CALL caller=imvt_raw_blc_status@00ab9fa0
REF 0080e9b0 UNCONDITIONAL_CALL caller=FUN_0080e930@0080e930
REF 0080eac0 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080ead4 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080eae8 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080eafc UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080eb10 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080eb24 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080eb38 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080eb4c UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080eb5c UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080eba0 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080ebb0 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080ebd4 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080ebe4 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080ec04 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080ec1c UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080ec34 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080ec4c UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080ec64 UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080ec7c UNCONDITIONAL_CALL caller=FUN_0080eaa0@0080eaa0
REF 0080ecc8 UNCONDITIONAL_CALL caller=FUN_0080ec88@0080ec88
REF 0080ed2c UNCONDITIONAL_CALL caller=FUN_0080ece8@0080ece8
REF 00868f54 UNCONDITIONAL_CALL caller=imvt_cam_set_vo_mode@00868ef0
REF 0081b7d0 UNCONDITIONAL_CALL caller=imvt_cgamma_wrapper_shell_show_status@0081b778
REF 0081b7f0 UNCONDITIONAL_CALL caller=imvt_cgamma_wrapper_shell_show_status@0081b778
REF 0081b818 UNCONDITIONAL_CALL caller=imvt_cgamma_wrapper_shell_show_status@0081b778
REF 0081b844 UNCONDITIONAL_CALL caller=imvt_cgamma_wrapper_shell_show_status@0081b778
REF 0081b854 UNCONDITIONAL_CALL caller=imvt_cgamma_wrapper_shell_show_status@0081b778
REF 0080eea8 UNCONDITIONAL_CALL caller=FUN_0080ee70@0080ee70
REF 0080ef0c UNCONDITIONAL_CALL caller=FUN_0080eed0@0080eed0
REF 0080ef34 UNCONDITIONAL_CALL caller=FUN_0080eed0@0080eed0
REF 0080ef5c UNCONDITIONAL_CALL caller=FUN_0080eed0@0080eed0
REF 0080ef6c UNCONDITIONAL_CALL caller=FUN_0080eed0@0080eed0
REF 0080ef7c UNCONDITIONAL_CALL caller=FUN_0080eed0@0080eed0
REF 00ab88f0 UNCONDITIONAL_CALL caller=imvt_adj_module_status@00ab88c8
REF 00ab8854 UNCONDITIONAL_CALL caller=imvt_adj_info@00ab8828
REF 00ab88b0 UNCONDITIONAL_CALL caller=imvt_adj_info@00ab8828
REF 0080f158 UNCONDITIONAL_CALL caller=FUN_0080f138@0080f138
REF 00885b80 UNCONDITIONAL_CALL caller=imvt_isp_blc_shell_show_table@00885b48
REF 00885b98 UNCONDITIONAL_CALL caller=imvt_isp_blc_shell_show_table@00885b48
REF 00885be4 UNCONDITIONAL_CALL caller=imvt_isp_blc_shell_show_table@00885b48
REF 00885c1c UNCONDITIONAL_CALL caller=imvt_isp_blc_shell_show_table@00885b48
REF 0080f1e0 UNCONDITIONAL_CALL caller=FUN_0080f168@0080f168
REF 0080f250 UNCONDITIONAL_CALL caller=FUN_0080f168@0080f168
REF 0080f2ec UNCONDITIONAL_CALL caller=FUN_0080f168@0080f168
REF 0080f2fc UNCONDITIONAL_CALL caller=FUN_0080f168@0080f168
REF 0080f30c UNCONDITIONAL_CALL caller=FUN_0080f168@0080f168
REF 0080f3ac UNCONDITIONAL_CALL caller=FUN_0080f338@0080f338
REF 0080f4d8 UNCONDITIONAL_CALL caller=FUN_0080f468@0080f468
REF 008840d8 UNCONDITIONAL_CALL caller=imvt_cam_raw_movie_start@00883f68
REF 00884140 UNCONDITIONAL_CALL caller=imvt_cam_raw_movie_start@00883f68
REF 00884150 UNCONDITIONAL_CALL caller=imvt_cam_raw_movie_start@00883f68
REF 00884168 UNCONDITIONAL_CALL caller=imvt_cam_raw_movie_start@00883f68
REF 0080f950 UNCONDITIONAL_CALL caller=FUN_0080f8d8@0080f8d8
REF 0080f9ac UNCONDITIONAL_CALL caller=FUN_0080f8d8@0080f8d8
REF 0080fb00 UNCONDITIONAL_CALL caller=FUN_0080f9f8@0080f9f8
REF 00886280 UNCONDITIONAL_CALL caller=imvt_isp_fv_table_output@008861e8
REF 00886374 UNCONDITIONAL_CALL caller=imvt_isp_fv_table_output@008861e8
REF 00886494 UNCONDITIONAL_CALL caller=imvt_isp_fv_table_output@008861e8
REF 00886580 UNCONDITIONAL_CALL caller=imvt_isp_fv_table_output@008861e8
REF 008865fc UNCONDITIONAL_CALL caller=imvt_isp_fv_table_output@008861e8
REF 0088661c UNCONDITIONAL_CALL caller=imvt_isp_fv_table_output@008861e8
REF 00886668 UNCONDITIONAL_CALL caller=imvt_isp_fv_table_output@008861e8
REF 00886698 UNCONDITIONAL_CALL caller=imvt_isp_fv_table_output@008861e8
REF 008866b0 UNCONDITIONAL_CALL caller=imvt_isp_fv_table_output@008861e8
REF 008866c8 UNCONDITIONAL_CALL caller=imvt_isp_fv_table_output@008861e8
REF 0080fbc4 UNCONDITIONAL_CALL caller=FUN_0080fb98@0080fb98
REF 0080fd60 UNCONDITIONAL_CALL caller=FUN_0080fc28@0080fc28
REF 0080fdd0 UNCONDITIONAL_CALL caller=FUN_0080fc28@0080fc28
REF 0080fe24 UNCONDITIONAL_CALL caller=FUN_0080fc28@0080fc28
REF 0080fe70 UNCONDITIONAL_CALL caller=FUN_0080fc28@0080fc28
REF 0080fee0 UNCONDITIONAL_CALL caller=FUN_0080fc28@0080fc28
REF 0080ff20 UNCONDITIONAL_CALL caller=FUN_0080ff08@0080ff08
REF 0080ff48 UNCONDITIONAL_CALL caller=FUN_0080ff30@0080ff30
REF 0081002c UNCONDITIONAL_CALL caller=FUN_0080ffc8@0080ffc8
REF 008100a4 UNCONDITIONAL_CALL caller=FUN_00810040@00810040
REF 008100f4 UNCONDITIONAL_CALL caller=FUN_008100b8@008100b8
REF 00810104 UNCONDITIONAL_CALL caller=FUN_008100b8@008100b8
REF 00810114 UNCONDITIONAL_CALL caller=FUN_008100b8@008100b8
REF 00810124 UNCONDITIONAL_CALL caller=FUN_008100b8@008100b8
REF 00810184 UNCONDITIONAL_CALL caller=FUN_00810138@00810138
REF 00810194 UNCONDITIONAL_CALL caller=FUN_00810138@00810138
REF 008101a4 UNCONDITIONAL_CALL caller=FUN_00810138@00810138
REF 008101b4 UNCONDITIONAL_CALL caller=FUN_00810138@00810138
REF 00810214 UNCONDITIONAL_CALL caller=FUN_008101c8@008101c8
REF 00810224 UNCONDITIONAL_CALL caller=FUN_008101c8@008101c8
REF 00810234 UNCONDITIONAL_CALL caller=FUN_008101c8@008101c8
REF 00810244 UNCONDITIONAL_CALL caller=FUN_008101c8@008101c8
REF 008102a4 UNCONDITIONAL_CALL caller=FUN_00810258@00810258
REF 008102b4 UNCONDITIONAL_CALL caller=FUN_00810258@00810258
REF 008102c4 UNCONDITIONAL_CALL caller=FUN_00810258@00810258
REF 008102d4 UNCONDITIONAL_CALL caller=FUN_00810258@00810258
REF 00810334 UNCONDITIONAL_CALL caller=FUN_008102e8@008102e8
REF 00810344 UNCONDITIONAL_CALL caller=FUN_008102e8@008102e8
REF 00810354 UNCONDITIONAL_CALL caller=FUN_008102e8@008102e8
REF 00810364 UNCONDITIONAL_CALL caller=FUN_008102e8@008102e8
REF 008103b4 UNCONDITIONAL_CALL caller=FUN_00810378@00810378
REF 008103c4 UNCONDITIONAL_CALL caller=FUN_00810378@00810378
REF 008103d4 UNCONDITIONAL_CALL caller=FUN_00810378@00810378
REF 008103e4 UNCONDITIONAL_CALL caller=FUN_00810378@00810378
REF 008104b0 UNCONDITIONAL_CALL caller=FUN_008103f8@008103f8
REF 008104ec UNCONDITIONAL_CALL caller=FUN_008103f8@008103f8
REF 008104fc UNCONDITIONAL_CALL caller=FUN_008103f8@008103f8
REF 0081050c UNCONDITIONAL_CALL caller=FUN_008103f8@008103f8
REF 008105d4 UNCONDITIONAL_CALL caller=FUN_00810518@00810518
REF 008105e4 UNCONDITIONAL_CALL caller=FUN_00810518@00810518
REF 008105f4 UNCONDITIONAL_CALL caller=FUN_00810518@00810518
REF 00810664 UNCONDITIONAL_CALL caller=FUN_00810600@00810600
REF 00810674 UNCONDITIONAL_CALL caller=FUN_00810600@00810600
REF 00810684 UNCONDITIONAL_CALL caller=FUN_00810600@00810600
REF 00810694 UNCONDITIONAL_CALL caller=FUN_00810600@00810600
REF 008106a4 UNCONDITIONAL_CALL caller=FUN_00810600@00810600
REF 008106b4 UNCONDITIONAL_CALL caller=FUN_00810600@00810600
REF 00810784 UNCONDITIONAL_CALL caller=FUN_008106c8@008106c8
REF 00810794 UNCONDITIONAL_CALL caller=FUN_008106c8@008106c8
REF 008107a4 UNCONDITIONAL_CALL caller=FUN_008106c8@008106c8
REF 0081087c UNCONDITIONAL_CALL caller=FUN_008107c0@008107c0
REF 0081088c UNCONDITIONAL_CALL caller=FUN_008107c0@008107c0
REF 0081089c UNCONDITIONAL_CALL caller=FUN_008107c0@008107c0
REF 008108f4 UNCONDITIONAL_CALL caller=FUN_008108b8@008108b8
REF 00810904 UNCONDITIONAL_CALL caller=FUN_008108b8@008108b8
REF 00810914 UNCONDITIONAL_CALL caller=FUN_008108b8@008108b8
REF 00810924 UNCONDITIONAL_CALL caller=FUN_008108b8@008108b8
REF 00810974 UNCONDITIONAL_CALL caller=FUN_00810938@00810938
REF 00810984 UNCONDITIONAL_CALL caller=FUN_00810938@00810938
REF 00810994 UNCONDITIONAL_CALL caller=FUN_00810938@00810938
REF 008109a4 UNCONDITIONAL_CALL caller=FUN_00810938@00810938
REF 008109f4 UNCONDITIONAL_CALL caller=FUN_008109b8@008109b8
REF 00810a04 UNCONDITIONAL_CALL caller=FUN_008109b8@008109b8
REF 00810a14 UNCONDITIONAL_CALL caller=FUN_008109b8@008109b8
REF 00810a24 UNCONDITIONAL_CALL caller=FUN_008109b8@008109b8
REF 00810aa8 UNCONDITIONAL_CALL caller=FUN_00810a38@00810a38
REF 00810adc UNCONDITIONAL_CALL caller=FUN_00810a38@00810a38
REF 00810aec UNCONDITIONAL_CALL caller=FUN_00810a38@00810a38
REF 00810afc UNCONDITIONAL_CALL caller=FUN_00810a38@00810a38
REF 00810b0c UNCONDITIONAL_CALL caller=FUN_00810a38@00810a38
REF 00810b9c UNCONDITIONAL_CALL caller=FUN_00810b28@00810b28
REF 00810be0 UNCONDITIONAL_CALL caller=FUN_00810b28@00810b28
REF 00810c24 UNCONDITIONAL_CALL caller=FUN_00810b28@00810b28
REF 00810c3c UNCONDITIONAL_CALL caller=FUN_00810b28@00810b28
REF 00810c84 UNCONDITIONAL_CALL caller=FUN_00810c48@00810c48
REF 00810ca4 UNCONDITIONAL_CALL caller=FUN_00810c48@00810c48
REF 00810cb4 UNCONDITIONAL_CALL caller=FUN_00810c48@00810c48
REF 00810cc4 UNCONDITIONAL_CALL caller=FUN_00810c48@00810c48
REF 00810d8c UNCONDITIONAL_CALL caller=FUN_00810cd8@00810cd8
REF 00810d9c UNCONDITIONAL_CALL caller=FUN_00810cd8@00810cd8
REF 00810dac UNCONDITIONAL_CALL caller=FUN_00810cd8@00810cd8
REF 00810e44 UNCONDITIONAL_CALL caller=FUN_00810db8@00810db8
REF 00810e84 UNCONDITIONAL_CALL caller=FUN_00810db8@00810db8
REF 00810e94 UNCONDITIONAL_CALL caller=FUN_00810db8@00810db8
REF 00810ea4 UNCONDITIONAL_CALL caller=FUN_00810db8@00810db8
REF 00810eb4 UNCONDITIONAL_CALL caller=FUN_00810db8@00810db8
REF 00810ec4 UNCONDITIONAL_CALL caller=FUN_00810db8@00810db8
REF 00810f0c UNCONDITIONAL_CALL caller=FUN_00810ed0@00810ed0
REF 00810f1c UNCONDITIONAL_CALL caller=FUN_00810ed0@00810ed0
REF 00810f2c UNCONDITIONAL_CALL caller=FUN_00810ed0@00810ed0
REF 00810f3c UNCONDITIONAL_CALL caller=FUN_00810ed0@00810ed0
REF 00810f8c UNCONDITIONAL_CALL caller=FUN_00810f50@00810f50
REF 00810f9c UNCONDITIONAL_CALL caller=FUN_00810f50@00810f50
REF 00810fac UNCONDITIONAL_CALL caller=FUN_00810f50@00810f50
REF 00810fbc UNCONDITIONAL_CALL caller=FUN_00810f50@00810f50
REF 0081108c UNCONDITIONAL_CALL caller=FUN_00810fd0@00810fd0
REF 0081109c UNCONDITIONAL_CALL caller=FUN_00810fd0@00810fd0
REF 008110ac UNCONDITIONAL_CALL caller=FUN_00810fd0@00810fd0
REF 008110bc UNCONDITIONAL_CALL caller=FUN_00810fd0@00810fd0
REF 008110cc UNCONDITIONAL_CALL caller=FUN_00810fd0@00810fd0
REF 00811170 UNCONDITIONAL_CALL caller=FUN_008110e8@008110e8
REF 008111ac UNCONDITIONAL_CALL caller=FUN_008110e8@008110e8
REF 008111bc UNCONDITIONAL_CALL caller=FUN_008110e8@008110e8
REF 008111cc UNCONDITIONAL_CALL caller=FUN_008110e8@008110e8
REF 008111dc UNCONDITIONAL_CALL caller=FUN_008110e8@008110e8
REF 008111ec UNCONDITIONAL_CALL caller=FUN_008110e8@008110e8
REF 00811244 UNCONDITIONAL_CALL caller=FUN_00811208@00811208
REF 00811254 UNCONDITIONAL_CALL caller=FUN_00811208@00811208
REF 00811264 UNCONDITIONAL_CALL caller=FUN_00811208@00811208
REF 00811274 UNCONDITIONAL_CALL caller=FUN_00811208@00811208
REF 008112c4 UNCONDITIONAL_CALL caller=FUN_00811288@00811288
REF 008112d4 UNCONDITIONAL_CALL caller=FUN_00811288@00811288
REF 008112e4 UNCONDITIONAL_CALL caller=FUN_00811288@00811288
REF 008112f4 UNCONDITIONAL_CALL caller=FUN_00811288@00811288
REF 00811344 UNCONDITIONAL_CALL caller=FUN_00811308@00811308
REF 00811354 UNCONDITIONAL_CALL caller=FUN_00811308@00811308
REF 00811364 UNCONDITIONAL_CALL caller=FUN_00811308@00811308
REF 00811374 UNCONDITIONAL_CALL caller=FUN_00811308@00811308
REF 008113e4 UNCONDITIONAL_CALL caller=FUN_00811388@00811388
REF 0081142c UNCONDITIONAL_CALL caller=FUN_00811388@00811388
REF 0081143c UNCONDITIONAL_CALL caller=FUN_00811388@00811388
REF 0081144c UNCONDITIONAL_CALL caller=FUN_00811388@00811388
REF 0081145c UNCONDITIONAL_CALL caller=FUN_00811388@00811388
REF 008114b0 UNCONDITIONAL_CALL caller=FUN_00811478@00811478
REF 008114c0 UNCONDITIONAL_CALL caller=FUN_00811478@00811478
REF 008114d0 UNCONDITIONAL_CALL caller=FUN_00811478@00811478
REF 008114e0 UNCONDITIONAL_CALL caller=FUN_00811478@00811478
REF 008114f0 UNCONDITIONAL_CALL caller=FUN_00811478@00811478
REF 0081152c UNCONDITIONAL_CALL caller=FUN_00811478@00811478
REF 00811580 UNCONDITIONAL_CALL caller=FUN_00811548@00811548
REF 00811590 UNCONDITIONAL_CALL caller=FUN_00811548@00811548
REF 008115a0 UNCONDITIONAL_CALL caller=FUN_00811548@00811548
REF 008115b0 UNCONDITIONAL_CALL caller=FUN_00811548@00811548
REF 008115c0 UNCONDITIONAL_CALL caller=FUN_00811548@00811548
REF 008115d0 UNCONDITIONAL_CALL caller=FUN_00811548@00811548
REF 0081160c UNCONDITIONAL_CALL caller=FUN_00811548@00811548
REF 00811660 UNCONDITIONAL_CALL caller=FUN_00811628@00811628
REF 00811670 UNCONDITIONAL_CALL caller=FUN_00811628@00811628
REF 00811680 UNCONDITIONAL_CALL caller=FUN_00811628@00811628
REF 00811690 UNCONDITIONAL_CALL caller=FUN_00811628@00811628
REF 008116cc UNCONDITIONAL_CALL caller=FUN_00811628@00811628
REF 00811720 UNCONDITIONAL_CALL caller=FUN_008116e8@008116e8
REF 00811730 UNCONDITIONAL_CALL caller=FUN_008116e8@008116e8
REF 00811740 UNCONDITIONAL_CALL caller=FUN_008116e8@008116e8
REF 00811750 UNCONDITIONAL_CALL caller=FUN_008116e8@008116e8
REF 008830f0 UNCONDITIONAL_CALL caller=imvt_raw_capture_set_channel@008830c8
REF 008117d4 UNCONDITIONAL_CALL caller=FUN_00811790@00811790
REF 008117e4 UNCONDITIONAL_CALL caller=FUN_00811790@00811790
REF 008117f4 UNCONDITIONAL_CALL caller=FUN_00811790@00811790
REF 00811804 UNCONDITIONAL_CALL caller=FUN_00811790@00811790
REF 00811814 UNCONDITIONAL_CALL caller=FUN_00811790@00811790
REF 00811864 UNCONDITIONAL_CALL caller=FUN_00811790@00811790
REF 008119ac UNCONDITIONAL_CALL caller=FUN_00811970@00811970
REF 00811a54 UNCONDITIONAL_CALL caller=FUN_008119c0@008119c0
REF 0089a658 UNCONDITIONAL_CALL caller=imvt_mov_set_vpss_chn_fps@0089a5b8
REF 0089a678 UNCONDITIONAL_CALL caller=imvt_mov_set_vpss_chn_fps@0089a5b8
REF 00811b14 UNCONDITIONAL_CALL caller=FUN_00811a70@00811a70
REF 00811b24 UNCONDITIONAL_CALL caller=FUN_00811a70@00811a70
REF 00811b34 UNCONDITIONAL_CALL caller=FUN_00811a70@00811a70
REF 00811bf4 UNCONDITIONAL_CALL caller=FUN_00811b40@00811b40
REF 00811c04 UNCONDITIONAL_CALL caller=FUN_00811b40@00811b40
REF 00811c14 UNCONDITIONAL_CALL caller=FUN_00811b40@00811b40
REF 00811c24 UNCONDITIONAL_CALL caller=FUN_00811b40@00811b40
REF 00811cdc UNCONDITIONAL_CALL caller=FUN_00811c30@00811c30
REF 00811cec UNCONDITIONAL_CALL caller=FUN_00811c30@00811c30
REF 00811cfc UNCONDITIONAL_CALL caller=FUN_00811c30@00811c30
REF 00811d84 UNCONDITIONAL_CALL caller=FUN_00811d08@00811d08
REF 00811dcc UNCONDITIONAL_CALL caller=FUN_00811d08@00811d08
REF 00811e28 UNCONDITIONAL_CALL caller=FUN_00811dd8@00811dd8
REF 00811e4c UNCONDITIONAL_CALL caller=FUN_00811dd8@00811dd8
REF 00811e5c UNCONDITIONAL_CALL caller=FUN_00811dd8@00811dd8
REF 00811e6c UNCONDITIONAL_CALL caller=FUN_00811dd8@00811dd8
REF 00811e7c UNCONDITIONAL_CALL caller=FUN_00811dd8@00811dd8
REF 00811e94 UNCONDITIONAL_CALL caller=FUN_00811dd8@00811dd8
REF 00811ef8 UNCONDITIONAL_CALL caller=FUN_00811ea8@00811ea8
REF 00811f1c UNCONDITIONAL_CALL caller=FUN_00811ea8@00811ea8
REF 00811f2c UNCONDITIONAL_CALL caller=FUN_00811ea8@00811ea8
REF 00811f3c UNCONDITIONAL_CALL caller=FUN_00811ea8@00811ea8
REF 00811f4c UNCONDITIONAL_CALL caller=FUN_00811ea8@00811ea8
REF 00811f5c UNCONDITIONAL_CALL caller=FUN_00811ea8@00811ea8
REF 00811f74 UNCONDITIONAL_CALL caller=FUN_00811ea8@00811ea8
REF 00812068 UNCONDITIONAL_CALL caller=FUN_00811f88@00811f88
REF 00812094 UNCONDITIONAL_CALL caller=FUN_00811f88@00811f88
REF 008120c4 UNCONDITIONAL_CALL caller=FUN_008120a0@008120a0
REF 008120d4 UNCONDITIONAL_CALL caller=FUN_008120a0@008120a0
REF 008120e4 UNCONDITIONAL_CALL caller=FUN_008120a0@008120a0
REF 008120f4 UNCONDITIONAL_CALL caller=FUN_008120a0@008120a0
REF 00812104 UNCONDITIONAL_CALL caller=FUN_008120a0@008120a0
REF 00812114 UNCONDITIONAL_CALL caller=FUN_008120a0@008120a0
REF 00812198 UNCONDITIONAL_CALL caller=FUN_008120a0@008120a0
REF 008121a8 UNCONDITIONAL_CALL caller=FUN_008120a0@008120a0
REF 008121f8 UNCONDITIONAL_CALL caller=FUN_008121d8@008121d8
REF 00812208 UNCONDITIONAL_CALL caller=FUN_008121d8@008121d8
REF 008737fc UNCONDITIONAL_CALL caller=imvt_vi_yuv_dump_start@00873798
REF 00812288 UNCONDITIONAL_CALL caller=FUN_00812268@00812268
REF 00812298 UNCONDITIONAL_CALL caller=FUN_00812268@00812268
REF 00873720 UNCONDITIONAL_CALL caller=FUN_008736f8@008736f8
REF 0081231c UNCONDITIONAL_CALL caller=FUN_008122f8@008122f8
REF 0081232c UNCONDITIONAL_CALL caller=FUN_008122f8@008122f8
REF 0081233c UNCONDITIONAL_CALL caller=FUN_008122f8@008122f8
REF 008123c4 UNCONDITIONAL_CALL caller=FUN_008122f8@008122f8
REF 008124f4 UNCONDITIONAL_CALL caller=FUN_008124b8@008124b8
REF 00812514 UNCONDITIONAL_CALL caller=FUN_008124b8@008124b8
REF 00812524 UNCONDITIONAL_CALL caller=FUN_008124b8@008124b8
REF 008125d8 UNCONDITIONAL_CALL caller=FUN_00812538@00812538
REF 00812618 UNCONDITIONAL_CALL caller=FUN_00812538@00812538
REF 008126a4 UNCONDITIONAL_CALL caller=FUN_00812660@00812660
REF 00812714 UNCONDITIONAL_CALL caller=FUN_00812660@00812660
REF 00812750 UNCONDITIONAL_CALL caller=FUN_00812660@00812660
REF 00812974 UNCONDITIONAL_CALL caller=FUN_00812908@00812908
REF 00812a9c UNCONDITIONAL_CALL caller=FUN_00812a58@00812a58
REF 00812f4c UNCONDITIONAL_CALL caller=FUN_00812f10@00812f10
REF 0083b0dc UNCONDITIONAL_CALL caller=imvt_nf_calib_run@0083b058
REF 0083b100 UNCONDITIONAL_CALL caller=imvt_nf_calib_run@0083b058
REF 0083aefc UNCONDITIONAL_CALL caller=imvt_nf_calib_save_file@0083adf8
REF 0083af1c UNCONDITIONAL_CALL caller=imvt_nf_calib_save_file@0083adf8
REF 00812f94 UNCONDITIONAL_CALL caller=FUN_00812f78@00812f78
REF 00813210 UNCONDITIONAL_CALL caller=FUN_008131f0@008131f0
REF 00813250 UNCONDITIONAL_CALL caller=FUN_00813230@00813230
REF 00813284 UNCONDITIONAL_CALL caller=FUN_00813270@00813270
REF 00813360 UNCONDITIONAL_CALL caller=FUN_00813340@00813340
REF 0081345c UNCONDITIONAL_CALL caller=FUN_00813440@00813440
REF 0083a3b4 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a36c UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a3c8 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a3dc UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a3f0 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a404 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a418 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a42c UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a440 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a454 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a468 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a47c UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a490 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a4a4 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a4f8 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a524 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a534 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a548 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a55c UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a570 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a584 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a598 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a5ac UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a5c0 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a5d4 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a5e8 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a5fc UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a610 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0083a624 UNCONDITIONAL_CALL caller=imvt_cac_dump@0083a308
REF 0081348c UNCONDITIONAL_CALL caller=FUN_00813470@00813470
REF 008134ec UNCONDITIONAL_CALL caller=FUN_008134d0@008134d0
REF 00813514 UNCONDITIONAL_CALL caller=FUN_00813500@00813500
REF 00813534 UNCONDITIONAL_CALL caller=FUN_00813500@00813500
REF 008136e4 UNCONDITIONAL_CALL caller=FUN_00813678@00813678
REF 00813704 UNCONDITIONAL_CALL caller=FUN_00813678@00813678
REF 00813714 UNCONDITIONAL_CALL caller=FUN_00813678@00813678
REF 00813724 UNCONDITIONAL_CALL caller=FUN_00813678@00813678
REF 00813734 UNCONDITIONAL_CALL caller=FUN_00813678@00813678
REF 00813744 UNCONDITIONAL_CALL caller=FUN_00813678@00813678
REF 00813754 UNCONDITIONAL_CALL caller=FUN_00813678@00813678
REF 008137bc UNCONDITIONAL_CALL caller=FUN_00813768@00813768
REF 008137ec UNCONDITIONAL_CALL caller=FUN_00813768@00813768
REF 008137fc UNCONDITIONAL_CALL caller=FUN_00813768@00813768
REF 00813848 UNCONDITIONAL_CALL caller=FUN_00813810@00813810
REF 00813874 UNCONDITIONAL_CALL caller=FUN_00813810@00813810
REF 008138b8 UNCONDITIONAL_CALL caller=FUN_00813890@00813890
REF 008138d0 UNCONDITIONAL_CALL caller=FUN_00813890@00813890
REF 008138e0 UNCONDITIONAL_CALL caller=FUN_00813890@00813890
REF 00813920 UNCONDITIONAL_CALL caller=FUN_00813890@00813890
REF 0083acec UNCONDITIONAL_CALL caller=imvt_cac_save_@0083ab18
REF 0083ad10 UNCONDITIONAL_CALL caller=imvt_cac_save_@0083ab18
REF 0083ad88 UNCONDITIONAL_CALL caller=imvt_cac_save_@0083ab18
REF 0083adac UNCONDITIONAL_CALL caller=imvt_cac_save_@0083ab18
REF 0083adc4 UNCONDITIONAL_CALL caller=imvt_cac_save_@0083ab18
REF 00813960 UNCONDITIONAL_CALL caller=FUN_00813938@00813938
REF 00813978 UNCONDITIONAL_CALL caller=FUN_00813938@00813938
REF 00813988 UNCONDITIONAL_CALL caller=FUN_00813938@00813938
REF 008139c8 UNCONDITIONAL_CALL caller=FUN_00813938@00813938
REF 00813a08 UNCONDITIONAL_CALL caller=FUN_008139e0@008139e0
REF 00813a20 UNCONDITIONAL_CALL caller=FUN_008139e0@008139e0
REF 00813a30 UNCONDITIONAL_CALL caller=FUN_008139e0@008139e0
REF 00813a70 UNCONDITIONAL_CALL caller=FUN_008139e0@008139e0
REF 0083a798 UNCONDITIONAL_CALL caller=imvt_cac_load_@0083a630
REF 0083a84c UNCONDITIONAL_CALL caller=imvt_cac_load_@0083a630
REF 0083a8f8 UNCONDITIONAL_CALL caller=imvt_cac_load_@0083a630
REF 0083a91c UNCONDITIONAL_CALL caller=imvt_cac_load_@0083a630
REF 0083a938 UNCONDITIONAL_CALL caller=imvt_cac_load_@0083a630
REF 00813ab0 UNCONDITIONAL_CALL caller=FUN_00813a88@00813a88
REF 00813ac8 UNCONDITIONAL_CALL caller=FUN_00813a88@00813a88
REF 00813ad8 UNCONDITIONAL_CALL caller=FUN_00813a88@00813a88
REF 00813b18 UNCONDITIONAL_CALL caller=FUN_00813a88@00813a88
REF 00813b5c UNCONDITIONAL_CALL caller=FUN_00813b30@00813b30
REF 00813bd4 UNCONDITIONAL_CALL caller=FUN_00813b30@00813b30
REF 00813c0c UNCONDITIONAL_CALL caller=FUN_00813b30@00813b30
REF 00813c34 UNCONDITIONAL_CALL caller=FUN_00813b30@00813b30
REF 0083a0ec UNCONDITIONAL_CALL caller=imvt_cac_apply@00839fb8
REF 0083a14c UNCONDITIONAL_CALL caller=imvt_cac_apply@00839fb8
REF 0083a174 UNCONDITIONAL_CALL caller=imvt_cac_apply@00839fb8
REF 00813c88 UNCONDITIONAL_CALL caller=FUN_00813c60@00813c60
REF 00813cb8 UNCONDITIONAL_CALL caller=FUN_00813c60@00813c60
REF 00813cdc UNCONDITIONAL_CALL caller=FUN_00813c60@00813c60
REF 00839fa8 UNCONDITIONAL_CALL caller=imvt_cac_reset@00839f38
REF 00813d18 UNCONDITIONAL_CALL caller=FUN_00813cf0@00813cf0
REF 00813d30 UNCONDITIONAL_CALL caller=FUN_00813cf0@00813cf0
REF 00813d40 UNCONDITIONAL_CALL caller=FUN_00813cf0@00813cf0
REF 00813d80 UNCONDITIONAL_CALL caller=FUN_00813cf0@00813cf0
REF 0083a9f8 UNCONDITIONAL_CALL caller=imvt_cac_load@0083a958
REF 0083aa5c UNCONDITIONAL_CALL caller=imvt_cac_load@0083a958
REF 0083aa8c UNCONDITIONAL_CALL caller=imvt_cac_load@0083a958
REF 00813dc0 UNCONDITIONAL_CALL caller=FUN_00813d98@00813d98
REF 00813dd8 UNCONDITIONAL_CALL caller=FUN_00813d98@00813d98
REF 00813de8 UNCONDITIONAL_CALL caller=FUN_00813d98@00813d98
REF 00813e40 UNCONDITIONAL_CALL caller=FUN_00813d98@00813d98
REF 00813e84 UNCONDITIONAL_CALL caller=FUN_00813e58@00813e58
REF 00813f10 UNCONDITIONAL_CALL caller=FUN_00813e58@00813e58
REF 00813f34 UNCONDITIONAL_CALL caller=FUN_00813e58@00813e58
REF 00813f44 UNCONDITIONAL_CALL caller=FUN_00813e58@00813e58
REF 00813f9c UNCONDITIONAL_CALL caller=FUN_00813f70@00813f70
REF 00813fb4 UNCONDITIONAL_CALL caller=FUN_00813f70@00813f70
REF 00813fc4 UNCONDITIONAL_CALL caller=FUN_00813f70@00813f70
REF 00814024 UNCONDITIONAL_CALL caller=FUN_00813f70@00813f70
REF 00814068 UNCONDITIONAL_CALL caller=FUN_00814040@00814040
REF 00814080 UNCONDITIONAL_CALL caller=FUN_00814040@00814040
REF 008140c0 UNCONDITIONAL_CALL caller=FUN_00814040@00814040
REF 00814100 UNCONDITIONAL_CALL caller=FUN_008140d8@008140d8
REF 00814130 UNCONDITIONAL_CALL caller=FUN_008140d8@008140d8
REF 00814154 UNCONDITIONAL_CALL caller=FUN_008140d8@008140d8
REF 00814190 UNCONDITIONAL_CALL caller=FUN_00814168@00814168
REF 008141c0 UNCONDITIONAL_CALL caller=FUN_00814168@00814168
REF 008141e4 UNCONDITIONAL_CALL caller=FUN_00814168@00814168
REF 00814220 UNCONDITIONAL_CALL caller=FUN_008141f8@008141f8
REF 00814250 UNCONDITIONAL_CALL caller=FUN_008141f8@008141f8
REF 00814274 UNCONDITIONAL_CALL caller=FUN_008141f8@008141f8
REF 008142b0 UNCONDITIONAL_CALL caller=FUN_00814288@00814288
REF 008142c8 UNCONDITIONAL_CALL caller=FUN_00814288@00814288
REF 00814308 UNCONDITIONAL_CALL caller=FUN_00814288@00814288
REF 00814348 UNCONDITIONAL_CALL caller=FUN_00814320@00814320
REF 00814360 UNCONDITIONAL_CALL caller=FUN_00814320@00814320
REF 00814370 UNCONDITIONAL_CALL caller=FUN_00814320@00814320
REF 008143b0 UNCONDITIONAL_CALL caller=FUN_00814320@00814320
REF 008143f0 UNCONDITIONAL_CALL caller=FUN_008143c8@008143c8
REF 00814408 UNCONDITIONAL_CALL caller=FUN_008143c8@008143c8
REF 00814448 UNCONDITIONAL_CALL caller=FUN_008143c8@008143c8
REF 00814488 UNCONDITIONAL_CALL caller=FUN_00814460@00814460
REF 008144a0 UNCONDITIONAL_CALL caller=FUN_00814460@00814460
REF 008144e0 UNCONDITIONAL_CALL caller=FUN_00814460@00814460
REF 008145d0 UNCONDITIONAL_CALL caller=FUN_008144f8@008144f8
REF 008146f4 UNCONDITIONAL_CALL caller=FUN_008146c0@008146c0
REF 00814704 UNCONDITIONAL_CALL caller=FUN_008146c0@008146c0
REF 00814734 UNCONDITIONAL_CALL caller=FUN_00814718@00814718
REF 00814744 UNCONDITIONAL_CALL caller=FUN_00814718@00814718
REF 008147a4 UNCONDITIONAL_CALL caller=FUN_00814778@00814778
REF 008147bc UNCONDITIONAL_CALL caller=FUN_00814778@00814778
REF 0081484c UNCONDITIONAL_CALL caller=FUN_00814820@00814820
REF 00814864 UNCONDITIONAL_CALL caller=FUN_00814820@00814820
REF 00814874 UNCONDITIONAL_CALL caller=FUN_00814820@00814820
REF 00814884 UNCONDITIONAL_CALL caller=FUN_00814820@00814820
REF 00814894 UNCONDITIONAL_CALL caller=FUN_00814820@00814820
REF 008148fc UNCONDITIONAL_CALL caller=FUN_008148d0@008148d0
REF 00814914 UNCONDITIONAL_CALL caller=FUN_008148d0@008148d0
REF 00814924 UNCONDITIONAL_CALL caller=FUN_008148d0@008148d0
REF 00814934 UNCONDITIONAL_CALL caller=FUN_008148d0@008148d0
REF 00814944 UNCONDITIONAL_CALL caller=FUN_008148d0@008148d0
REF 00814954 UNCONDITIONAL_CALL caller=FUN_008148d0@008148d0
REF 00814f84 UNCONDITIONAL_CALL caller=FUN_00814ec0@00814ec0
REF 00814fd0 UNCONDITIONAL_CALL caller=FUN_00814ec0@00814ec0
REF 00815004 UNCONDITIONAL_CALL caller=FUN_00814fe0@00814fe0
REF 00815050 UNCONDITIONAL_CALL caller=FUN_00815018@00815018
REF 0081506c UNCONDITIONAL_CALL caller=FUN_00815018@00815018
REF 00815080 UNCONDITIONAL_CALL caller=FUN_00815018@00815018
REF 00815094 UNCONDITIONAL_CALL caller=FUN_00815018@00815018
REF 008150a8 UNCONDITIONAL_CALL caller=FUN_00815018@00815018
REF 008150bc UNCONDITIONAL_CALL caller=FUN_00815018@00815018
REF 00815110 UNCONDITIONAL_CALL caller=FUN_008150d0@008150d0
REF 00815170 UNCONDITIONAL_CALL caller=FUN_00815128@00815128
REF 00815198 UNCONDITIONAL_CALL caller=FUN_00815128@00815128
REF 0081525c UNCONDITIONAL_CALL caller=FUN_00815240@00815240
REF 0081528c UNCONDITIONAL_CALL caller=FUN_00815270@00815270
REF 008152bc UNCONDITIONAL_CALL caller=FUN_008152a0@008152a0
REF 00815394 UNCONDITIONAL_CALL caller=FUN_008152d0@008152d0
REF 008153c4 UNCONDITIONAL_CALL caller=FUN_008152d0@008152d0
REF 008153dc UNCONDITIONAL_CALL caller=FUN_008152d0@008152d0
REF 008153f8 UNCONDITIONAL_CALL caller=FUN_008152d0@008152d0
REF 00815490 UNCONDITIONAL_CALL caller=FUN_00815408@00815408
REF 00d1e348 UNCONDITIONAL_CALL caller=imvt_eND_shell_show_voltage@00d1e2b8
REF 00d1e39c UNCONDITIONAL_CALL caller=imvt_eND_shell_show_voltage@00d1e2b8
REF 00d1e3ec UNCONDITIONAL_CALL caller=imvt_eND_shell_show_voltage@00d1e2b8
REF 0081554c UNCONDITIONAL_CALL caller=FUN_00815530@00815530
REF 00815564 UNCONDITIONAL_CALL caller=FUN_00815530@00815530
REF 00815584 UNCONDITIONAL_CALL caller=FUN_00815530@00815530
REF 008155d0 UNCONDITIONAL_CALL caller=FUN_00815590@00815590
REF 00815610 UNCONDITIONAL_CALL caller=FUN_00815590@00815590
REF 00815634 UNCONDITIONAL_CALL caller=FUN_00815590@00815590
REF 0081574c UNCONDITIONAL_CALL caller=FUN_008156f8@008156f8
REF 00815794 UNCONDITIONAL_CALL caller=FUN_00815778@00815778
REF 008157ec UNCONDITIONAL_CALL caller=FUN_008157a8@008157a8
REF 00815824 UNCONDITIONAL_CALL caller=FUN_00815808@00815808
REF 00815878 UNCONDITIONAL_CALL caller=FUN_00815838@00815838
REF 008158bc UNCONDITIONAL_CALL caller=FUN_008158a0@008158a0
REF 008158ec UNCONDITIONAL_CALL caller=FUN_008158d0@008158d0
REF 0081592c UNCONDITIONAL_CALL caller=FUN_00815918@00815918
REF 00815ac4 UNCONDITIONAL_CALL caller=FUN_00815a88@00815a88
REF 00815af0 UNCONDITIONAL_CALL caller=FUN_00815a88@00815a88
REF 00815b08 UNCONDITIONAL_CALL caller=FUN_00815a88@00815a88
REF 00815b84 UNCONDITIONAL_CALL caller=FUN_00815b68@00815b68
REF 00815bec UNCONDITIONAL_CALL caller=FUN_00815bb0@00815bb0
REF 00815c54 UNCONDITIONAL_CALL caller=FUN_00815c18@00815c18
REF 00815c80 UNCONDITIONAL_CALL caller=FUN_00815c18@00815c18
REF 00815c9c UNCONDITIONAL_CALL caller=FUN_00815c18@00815c18
REF 00815cd4 UNCONDITIONAL_CALL caller=FUN_00815c18@00815c18
REF 00815f54 UNCONDITIONAL_CALL caller=FUN_00815ef0@00815ef0
REF 00816010 UNCONDITIONAL_CALL caller=FUN_00815f98@00815f98
REF 00816050 UNCONDITIONAL_CALL caller=FUN_00815f98@00815f98
REF 008160c4 UNCONDITIONAL_CALL caller=FUN_00816070@00816070
REF 0081612c UNCONDITIONAL_CALL caller=FUN_008160e8@008160e8
REF 008161bc UNCONDITIONAL_CALL caller=FUN_00816178@00816178
REF 0081621c UNCONDITIONAL_CALL caller=FUN_008161d8@008161d8
REF 008162d4 UNCONDITIONAL_CALL caller=FUN_00816238@00816238
REF 008163d0 UNCONDITIONAL_CALL caller=FUN_00816338@00816338
REF 00816408 UNCONDITIONAL_CALL caller=FUN_00816338@00816338
REF 00816568 UNCONDITIONAL_CALL caller=FUN_008164f8@008164f8
REF 008165d0 UNCONDITIONAL_CALL caller=FUN_00816598@00816598
REF 008165e4 UNCONDITIONAL_CALL caller=FUN_00816598@00816598
REF 008165f8 UNCONDITIONAL_CALL caller=FUN_00816598@00816598
REF 0081660c UNCONDITIONAL_CALL caller=FUN_00816598@00816598
REF 00816620 UNCONDITIONAL_CALL caller=FUN_00816598@00816598
REF 00816634 UNCONDITIONAL_CALL caller=FUN_00816598@00816598
REF 00816648 UNCONDITIONAL_CALL caller=FUN_00816598@00816598
REF 008166b8 UNCONDITIONAL_CALL caller=FUN_00816670@00816670
REF 008166d4 UNCONDITIONAL_CALL caller=FUN_00816670@00816670
REF 008166f0 UNCONDITIONAL_CALL caller=FUN_00816670@00816670
REF 0081670c UNCONDITIONAL_CALL caller=FUN_00816670@00816670
REF 00816728 UNCONDITIONAL_CALL caller=FUN_00816670@00816670
REF 00816744 UNCONDITIONAL_CALL caller=FUN_00816670@00816670
REF 00816760 UNCONDITIONAL_CALL caller=FUN_00816670@00816670
REF 008167b8 UNCONDITIONAL_CALL caller=FUN_00816798@00816798
REF 00816800 UNCONDITIONAL_CALL caller=FUN_008167c8@008167c8
REF 00816814 UNCONDITIONAL_CALL caller=FUN_008167c8@008167c8
REF 008168e4 UNCONDITIONAL_CALL caller=FUN_00816840@00816840
REF 00816900 UNCONDITIONAL_CALL caller=FUN_00816840@00816840
REF 00816914 UNCONDITIONAL_CALL caller=FUN_00816840@00816840
REF 00816a30 UNCONDITIONAL_CALL caller=FUN_00816960@00816960
REF 00816af8 UNCONDITIONAL_CALL caller=FUN_00816aa0@00816aa0
REF 00816b2c UNCONDITIONAL_CALL caller=FUN_00816aa0@00816aa0
REF 00816bac UNCONDITIONAL_CALL caller=FUN_00816b70@00816b70
REF 00816bc4 UNCONDITIONAL_CALL caller=FUN_00816b70@00816b70
REF 00816bdc UNCONDITIONAL_CALL caller=FUN_00816b70@00816b70
REF 00816bf4 UNCONDITIONAL_CALL caller=FUN_00816b70@00816b70
REF 00816c0c UNCONDITIONAL_CALL caller=FUN_00816b70@00816b70
REF 00816c28 UNCONDITIONAL_CALL caller=FUN_00816b70@00816b70
REF 00816c3c UNCONDITIONAL_CALL caller=FUN_00816b70@00816b70
REF 00816c50 UNCONDITIONAL_CALL caller=FUN_00816b70@00816b70
REF 00816c68 UNCONDITIONAL_CALL caller=FUN_00816b70@00816b70
REF 00816dcc UNCONDITIONAL_CALL caller=FUN_00816db0@00816db0
REF 00816de4 UNCONDITIONAL_CALL caller=FUN_00816db0@00816db0
REF 00816e9c UNCONDITIONAL_CALL caller=FUN_00816e18@00816e18
REF 00816f10 UNCONDITIONAL_CALL caller=FUN_00816ed0@00816ed0
REF 00816f5c UNCONDITIONAL_CALL caller=FUN_00816ed0@00816ed0
REF 00816f78 UNCONDITIONAL_CALL caller=FUN_00816ed0@00816ed0
REF 00817024 UNCONDITIONAL_CALL caller=FUN_00816f88@00816f88
REF 00817040 UNCONDITIONAL_CALL caller=FUN_00816f88@00816f88
REF 00817074 UNCONDITIONAL_CALL caller=FUN_00816f88@00816f88
REF 008170a0 UNCONDITIONAL_CALL caller=FUN_00816f88@00816f88
REF 008170bc UNCONDITIONAL_CALL caller=FUN_00816f88@00816f88
REF 008170ec UNCONDITIONAL_CALL caller=FUN_008170c8@008170c8
REF 0081710c UNCONDITIONAL_CALL caller=FUN_008170c8@008170c8
REF 00817160 UNCONDITIONAL_CALL caller=FUN_00817120@00817120
REF 00817184 UNCONDITIONAL_CALL caller=FUN_00817120@00817120
REF 008171c0 UNCONDITIONAL_CALL caller=FUN_00817120@00817120
REF 008171e0 UNCONDITIONAL_CALL caller=FUN_00817120@00817120
REF 00817238 UNCONDITIONAL_CALL caller=FUN_008171f0@008171f0
REF 0081725c UNCONDITIONAL_CALL caller=FUN_008171f0@008171f0
REF 00817288 UNCONDITIONAL_CALL caller=FUN_008171f0@008171f0
REF 008172c0 UNCONDITIONAL_CALL caller=FUN_008172a0@008172a0
REF 008172dc UNCONDITIONAL_CALL caller=FUN_008172a0@008172a0
REF 0081732c UNCONDITIONAL_CALL caller=FUN_008172f0@008172f0
REF 0081737c UNCONDITIONAL_CALL caller=FUN_00817340@00817340
REF 0081738c UNCONDITIONAL_CALL caller=FUN_00817340@00817340
REF 0081739c UNCONDITIONAL_CALL caller=FUN_00817340@00817340
REF 008173ac UNCONDITIONAL_CALL caller=FUN_00817340@00817340
REF 008173fc UNCONDITIONAL_CALL caller=FUN_008173c0@008173c0
REF 0081744c UNCONDITIONAL_CALL caller=FUN_00817410@00817410
REF 0081745c UNCONDITIONAL_CALL caller=FUN_00817410@00817410
REF 0081746c UNCONDITIONAL_CALL caller=FUN_00817410@00817410
REF 008174b0 UNCONDITIONAL_CALL caller=FUN_00817480@00817480
REF 008174cc UNCONDITIONAL_CALL caller=FUN_00817480@00817480
REF 00817524 UNCONDITIONAL_CALL caller=FUN_008174e8@008174e8
REF 00817534 UNCONDITIONAL_CALL caller=FUN_008174e8@008174e8
REF 00817544 UNCONDITIONAL_CALL caller=FUN_008174e8@008174e8
REF 00817554 UNCONDITIONAL_CALL caller=FUN_008174e8@008174e8
REF 00817564 UNCONDITIONAL_CALL caller=FUN_008174e8@008174e8
REF 008175ec UNCONDITIONAL_CALL caller=FUN_008175b0@008175b0
REF 0081763c UNCONDITIONAL_CALL caller=FUN_00817600@00817600
REF 0081768c UNCONDITIONAL_CALL caller=FUN_00817650@00817650
REF 008176dc UNCONDITIONAL_CALL caller=FUN_008176a0@008176a0
REF 0081772c UNCONDITIONAL_CALL caller=FUN_008176f0@008176f0
REF 0081777c UNCONDITIONAL_CALL caller=FUN_00817740@00817740
REF 00817914 UNCONDITIONAL_CALL caller=FUN_00817860@00817860
REF 00817970 UNCONDITIONAL_CALL caller=FUN_00817860@00817860
REF 00817984 UNCONDITIONAL_CALL caller=FUN_00817860@00817860
REF 00817a40 UNCONDITIONAL_CALL caller=FUN_008179b0@008179b0
REF 00817ae0 UNCONDITIONAL_CALL caller=FUN_00817a50@00817a50
REF 00817b50 UNCONDITIONAL_CALL caller=FUN_00817af0@00817af0
REF 00817d28 UNCONDITIONAL_CALL caller=FUN_00817c90@00817c90
REF 00817dc8 UNCONDITIONAL_CALL caller=FUN_00817d38@00817d38
REF 00817e20 UNCONDITIONAL_CALL caller=FUN_00817dd8@00817dd8
REF 00817e58 UNCONDITIONAL_CALL caller=FUN_00817dd8@00817dd8
REF 00817e94 UNCONDITIONAL_CALL caller=FUN_00817e70@00817e70
REF 00817eb4 UNCONDITIONAL_CALL caller=FUN_00817e70@00817e70
REF 00817ed4 UNCONDITIONAL_CALL caller=FUN_00817e70@00817e70
REF 00817efc UNCONDITIONAL_CALL caller=FUN_00817ee8@00817ee8
REF 00817f94 UNCONDITIONAL_CALL caller=FUN_00817f70@00817f70
REF 00817fbc UNCONDITIONAL_CALL caller=FUN_00817f70@00817f70
REF 008181bc UNCONDITIONAL_CALL caller=FUN_00818120@00818120
REF 008181f4 UNCONDITIONAL_CALL caller=FUN_008181c8@008181c8
REF 0081826c UNCONDITIONAL_CALL caller=FUN_008181c8@008181c8
REF 0081827c UNCONDITIONAL_CALL caller=FUN_008181c8@008181c8
REF 0081828c UNCONDITIONAL_CALL caller=FUN_008181c8@008181c8
REF 0081829c UNCONDITIONAL_CALL caller=FUN_008181c8@008181c8
REF 008182ac UNCONDITIONAL_CALL caller=FUN_008181c8@008181c8
REF 008182fc UNCONDITIONAL_CALL caller=FUN_008182c0@008182c0
REF 0081839c UNCONDITIONAL_CALL caller=FUN_00818318@00818318
REF 00a3d884 UNCONDITIONAL_CALL caller=imvt_storage_test@00a3d800
REF 008185e4 UNCONDITIONAL_CALL caller=FUN_00818490@00818490
REF 00d1cdfc UNCONDITIONAL_CALL caller=imvt_pmu_do_update@00d1cd60
REF 00d1ce58 UNCONDITIONAL_CALL caller=imvt_pmu_do_update@00d1cd60
REF 00d1ce70 UNCONDITIONAL_CALL caller=imvt_pmu_do_update@00d1cd60
REF 00d1ce88 UNCONDITIONAL_CALL caller=imvt_pmu_do_update@00d1cd60
REF 00d1c15c UNCONDITIONAL_CALL caller=FUN_00d1c018@00d1c018
REF 00d1c254 UNCONDITIONAL_CALL caller=imvt_pmu_open_tty@00d1c168
REF 00d1c27c UNCONDITIONAL_CALL caller=imvt_pmu_open_tty@00d1c168
REF 00d1c29c UNCONDITIONAL_CALL caller=imvt_pmu_open_tty@00d1c168
REF 00d1c4d8 UNCONDITIONAL_CALL caller=imvt_pmu_uart_recv_timeout@00d1c348
REF 00d1c83c UNCONDITIONAL_CALL caller=FUN_00d1c5f8@00d1c5f8
REF 00d1ca80 UNCONDITIONAL_CALL caller=FUN_00d1c5f8@00d1c5f8
REF 00d1cb74 UNCONDITIONAL_CALL caller=FUN_00d1c5f8@00d1c5f8
REF 00d1cba0 UNCONDITIONAL_CALL caller=FUN_00d1c5f8@00d1c5f8
REF 00d1cbbc UNCONDITIONAL_CALL caller=FUN_00d1c5f8@00d1c5f8
REF 00d1cbd4 UNCONDITIONAL_CALL caller=FUN_00d1c5f8@00d1c5f8
REF 00d1cc10 UNCONDITIONAL_CALL caller=FUN_00d1c5f8@00d1c5f8
REF 00d1cc48 UNCONDITIONAL_CALL caller=FUN_00d1c5f8@00d1c5f8
REF 00d1cc5c UNCONDITIONAL_CALL caller=FUN_00d1c5f8@00d1c5f8
REF 00818728 UNCONDITIONAL_CALL caller=FUN_00818710@00818710
REF 0081882c UNCONDITIONAL_CALL caller=FUN_00818748@00818748
REF 00a46ba0 UNCONDITIONAL_CALL caller=imvt_expansion_io_set_output@00a46b18
REF 00a469b8 UNCONDITIONAL_CALL caller=FUN_00a468a8@00a468a8
REF 00a469d4 UNCONDITIONAL_CALL caller=FUN_00a468a8@00a468a8
REF 00a469f4 UNCONDITIONAL_CALL caller=FUN_00a468a8@00a468a8
REF 00a46ac0 UNCONDITIONAL_CALL caller=FUN_00a46a10@00a46a10
REF 00a46ae4 UNCONDITIONAL_CALL caller=FUN_00a46a10@00a46a10
REF 00a46b00 UNCONDITIONAL_CALL caller=FUN_00a46a10@00a46a10
REF 00a46d60 UNCONDITIONAL_CALL caller=imvt_expansion_io_write_port@00a46cb8
REF 00a46c38 UNCONDITIONAL_CALL caller=imvt_expansion_io_set_input@00a46bb0
REF 00818b68 UNCONDITIONAL_CALL caller=FUN_00818b48@00818b48
REF 00818b84 UNCONDITIONAL_CALL caller=FUN_00818b48@00818b48
REF 00818bb8 UNCONDITIONAL_CALL caller=FUN_00818b98@00818b98
REF 00818bd4 UNCONDITIONAL_CALL caller=FUN_00818b98@00818b98
REF 00818cac UNCONDITIONAL_CALL caller=FUN_00818c70@00818c70
REF 00818d08 UNCONDITIONAL_CALL caller=FUN_00818cc0@00818cc0
REF 00818d2c UNCONDITIONAL_CALL caller=FUN_00818cc0@00818cc0
REF 00818d58 UNCONDITIONAL_CALL caller=FUN_00818cc0@00818cc0
REF 0081917c UNCONDITIONAL_CALL caller=FUN_00819158@00819158
REF 0081918c UNCONDITIONAL_CALL caller=FUN_00819158@00819158
REF 008191e4 UNCONDITIONAL_CALL caller=FUN_008191a0@008191a0
REF 008191f4 UNCONDITIONAL_CALL caller=FUN_008191a0@008191a0
REF 00819204 UNCONDITIONAL_CALL caller=FUN_008191a0@008191a0
REF 00819234 UNCONDITIONAL_CALL caller=FUN_00819210@00819210
REF 00819244 UNCONDITIONAL_CALL caller=FUN_00819210@00819210
REF 00819294 UNCONDITIONAL_CALL caller=FUN_00819258@00819258
REF 008192a4 UNCONDITIONAL_CALL caller=FUN_00819258@00819258
REF 008192b4 UNCONDITIONAL_CALL caller=FUN_00819258@00819258
REF 008192e4 UNCONDITIONAL_CALL caller=FUN_008192c0@008192c0
REF 008192f4 UNCONDITIONAL_CALL caller=FUN_008192c0@008192c0
REF 008193a4 UNCONDITIONAL_CALL caller=FUN_00819340@00819340
REF 008193d0 UNCONDITIONAL_CALL caller=FUN_00819340@00819340
REF 008193e0 UNCONDITIONAL_CALL caller=FUN_00819340@00819340
REF 008193f0 UNCONDITIONAL_CALL caller=FUN_00819340@00819340
REF 00819400 UNCONDITIONAL_CALL caller=FUN_00819340@00819340
REF 00819414 UNCONDITIONAL_CALL caller=FUN_00819340@00819340
REF 00819494 UNCONDITIONAL_CALL caller=FUN_00819430@00819430
REF 008194c0 UNCONDITIONAL_CALL caller=FUN_00819430@00819430
REF 008194d0 UNCONDITIONAL_CALL caller=FUN_00819430@00819430
REF 008194e0 UNCONDITIONAL_CALL caller=FUN_00819430@00819430
REF 008194f0 UNCONDITIONAL_CALL caller=FUN_00819430@00819430
REF 00819504 UNCONDITIONAL_CALL caller=FUN_00819430@00819430
REF 00819584 UNCONDITIONAL_CALL caller=FUN_00819520@00819520
REF 008195b0 UNCONDITIONAL_CALL caller=FUN_00819520@00819520
REF 008195c0 UNCONDITIONAL_CALL caller=FUN_00819520@00819520
REF 008195d0 UNCONDITIONAL_CALL caller=FUN_00819520@00819520
REF 008195e0 UNCONDITIONAL_CALL caller=FUN_00819520@00819520
REF 008195f4 UNCONDITIONAL_CALL caller=FUN_00819520@00819520
REF 00a656d4 UNCONDITIONAL_CALL caller=imvt_qa_res_show_info@00a65448
REF 00a65788 UNCONDITIONAL_CALL caller=imvt_qa_res_show_info@00a65448
REF 00a657c4 UNCONDITIONAL_CALL caller=imvt_qa_res_show_info@00a65448
REF 00a657d8 UNCONDITIONAL_CALL caller=imvt_qa_res_show_info@00a65448
REF 00a65808 UNCONDITIONAL_CALL caller=imvt_qa_res_show_info@00a65448
REF 00a6581c UNCONDITIONAL_CALL caller=imvt_qa_res_show_info@00a65448
REF 00a6584c UNCONDITIONAL_CALL caller=imvt_qa_res_show_info@00a65448
REF 00b95b88 UNCONDITIONAL_CALL caller=sensor_get_sensor_mode_name@00b95b48
REF 00abda18 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abda28 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abda38 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abda50 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abda68 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abda80 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdaa4 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdac4 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdae4 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdb08 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdb28 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdb50 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdb5c UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdb6c UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdb7c UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdb94 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdba8 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdbbc UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdbd0 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdbec UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdc04 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdc1c UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 00abdc28 UNCONDITIONAL_CALL caller=imvt_raw_info_debug_show@00abd9c0
REF 0081979c UNCONDITIONAL_CALL caller=FUN_00819778@00819778
REF 008197f4 UNCONDITIONAL_CALL caller=FUN_00819778@00819778
REF 00819804 UNCONDITIONAL_CALL caller=FUN_00819778@00819778
REF 00a64fa8 UNCONDITIONAL_CALL caller=imvt_qa_bypass_key@00a64f48
REF 0081983c UNCONDITIONAL_CALL caller=FUN_00819818@00819818
REF 00819884 UNCONDITIONAL_CALL caller=FUN_00819818@00819818
REF 00819894 UNCONDITIONAL_CALL caller=FUN_00819818@00819818
REF 0081994c UNCONDITIONAL_CALL caller=FUN_00819938@00819938
REF 0081995c UNCONDITIONAL_CALL caller=FUN_00819938@00819938
REF 0081999c UNCONDITIONAL_CALL caller=FUN_00819938@00819938
REF 008199f4 UNCONDITIONAL_CALL caller=FUN_008199c8@008199c8
REF 00819a0c UNCONDITIONAL_CALL caller=FUN_008199c8@008199c8
REF 00819a1c UNCONDITIONAL_CALL caller=FUN_008199c8@008199c8
REF 00819a2c UNCONDITIONAL_CALL caller=FUN_008199c8@008199c8
REF 00a65aa4 UNCONDITIONAL_CALL caller=imvt_iq_gain_shell_set_max_again@00a65a68
REF 00b953b8 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b953d4 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b953e4 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95434 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95450 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b9546c UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b9548c UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95548 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b954e0 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95568 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95598 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b955a8 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b955e4 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95600 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95610 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95664 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95688 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b956bc UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b956c8 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b956e0 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95708 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95750 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95798 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b957e8 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95828 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95838 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b95854 UNCONDITIONAL_CALL caller=imvt_sensor_debug_request@00b952e0
REF 00b950e0 UNCONDITIONAL_CALL caller=FUN_00b95060@00b95060
REF 00b95134 UNCONDITIONAL_CALL caller=FUN_00b95060@00b95060
REF 00b95208 UNCONDITIONAL_CALL caller=FUN_00b95060@00b95060
REF 00b951a4 UNCONDITIONAL_CALL caller=FUN_00b95060@00b95060
REF 00b9523c UNCONDITIONAL_CALL caller=FUN_00b95060@00b95060
REF 00b9529c UNCONDITIONAL_CALL caller=FUN_00b95060@00b95060
REF 00b96154 UNCONDITIONAL_CALL caller=sensor_n3a_calc_svr_shr@00b96000
REF 00b96528 UNCONDITIONAL_CALL caller=sensor_mode_adc_is_11bits@00b964d8
REF 00b94920 UNCONDITIONAL_CALL caller=imvt_sensor_init_stage2@00b94888
REF 00b9494c UNCONDITIONAL_CALL caller=imvt_sensor_init_stage2@00b94888
REF 00b94098 UNCONDITIONAL_CALL caller=sensor_dump_all_register@00b94008
REF 00b94128 UNCONDITIONAL_CALL caller=sensor_dump_all_register@00b94008
REF 00b96424 UNCONDITIONAL_CALL caller=FUN_00b963fc@00b963fc
REF 00819ea4 UNCONDITIONAL_CALL caller=FUN_00819e00@00819e00
REF 00819eb4 UNCONDITIONAL_CALL caller=FUN_00819e00@00819e00
REF 00819ec4 UNCONDITIONAL_CALL caller=FUN_00819e00@00819e00
REF 00819f64 UNCONDITIONAL_CALL caller=FUN_00819ee0@00819ee0
REF 00819f70 UNCONDITIONAL_CALL caller=FUN_00819ee0@00819ee0
REF 00819f7c UNCONDITIONAL_CALL caller=FUN_00819ee0@00819ee0
REF 0081a10c UNCONDITIONAL_CALL caller=FUN_0081a088@0081a088
REF 0081a21c UNCONDITIONAL_CALL caller=FUN_0081a088@0081a088
REF 0081a2a0 UNCONDITIONAL_CALL caller=FUN_0081a088@0081a088
REF 0081a310 UNCONDITIONAL_CALL caller=FUN_0081a088@0081a088
REF 0081a334 UNCONDITIONAL_CALL caller=FUN_0081a088@0081a088
REF 0081a348 UNCONDITIONAL_CALL caller=FUN_0081a088@0081a088
REF 0081a46c UNCONDITIONAL_CALL caller=imvt_cam_set_next_case@0081a3c8
REF 0081a4f0 UNCONDITIONAL_CALL caller=imvt_cam_set_next_case@0081a3c8
REF 0081a724 UNCONDITIONAL_CALL caller=imvt_cam_pref_recursion_tree@0081a4f8
REF 0081a864 UNCONDITIONAL_CALL caller=imvt_cam_copy_file@0081a768
REF 0081a890 UNCONDITIONAL_CALL caller=imvt_cam_copy_file@0081a768
REF 0081a8ac UNCONDITIONAL_CALL caller=imvt_cam_copy_file@0081a768
REF 0081c5c4 UNCONDITIONAL_CALL caller=addStorageToServer@0081c410
REF 0081d484 UNCONDITIONAL_CALL caller=handleCameraUsbEvent@0081d418
REF 0081d4a4 UNCONDITIONAL_CALL caller=handleCameraUsbEvent@0081d418
REF 0081ed90 UNCONDITIONAL_CALL caller=FUN_0081ecc8@0081ecc8
REF 0081eda0 UNCONDITIONAL_CALL caller=FUN_0081ecc8@0081ecc8
REF 0081f708 UNCONDITIONAL_CALL caller=wifi_is_new_connect_time_out@0081f6a0
REF 0081f79c UNCONDITIONAL_CALL caller=wifi_is_new_connect_time_out@0081f6a0
REF 0081f7c4 UNCONDITIONAL_CALL caller=wifi_is_new_connect_time_out@0081f6a0
REF 008202c0 UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 0082046c UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 0082047c UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 008205ec UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 00820624 UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 00820638 UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 00820650 UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 00820664 UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 00820680 UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 00820694 UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 008206a8 UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 008206bc UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 008206d0 UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 00820708 UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 0082071c UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 00820754 UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 008207bc UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 008207d0 UNCONDITIONAL_CALL caller=FUN_0081ff08@0081ff08
REF 00820cc4 UNCONDITIONAL_CALL caller=wifi_get_current_ap_signal@00820c10
REF 00820cf0 UNCONDITIONAL_CALL caller=wifi_get_current_ap_signal@00820c10
REF 00821220 UNCONDITIONAL_CALL caller=wifi_get_all_connected_ap@00821168
REF 008214f8 UNCONDITIONAL_CALL caller=wifi_del_enterd_pswd_network@00821410
REF 00821550 UNCONDITIONAL_CALL caller=wifi_del_enterd_pswd_network@00821410
REF 00821568 UNCONDITIONAL_CALL caller=wifi_del_enterd_pswd_network@00821410
REF 0082161c UNCONDITIONAL_CALL caller=wifi_is_connect@00821570
REF 00821760 UNCONDITIONAL_CALL caller=wifi_get_connected_ap@00821630
REF 00821800 UNCONDITIONAL_CALL caller=wifi_get_connected_ap_channel@00821770
REF 008218a4 UNCONDITIONAL_CALL caller=wifi_get_connected_ap_channel@00821770
REF 008219ac UNCONDITIONAL_CALL caller=wifi_get_connected_ap_channel@00821770
REF 008219c4 UNCONDITIONAL_CALL caller=wifi_get_connected_ap_channel@00821770
REF 00822474 UNCONDITIONAL_CALL caller=FUN_00822268@00822268
REF 00822894 UNCONDITIONAL_CALL caller=FUN_00822878@00822878
REF 00822a88 UNCONDITIONAL_CALL caller=imvt_raw_stacking_start@00822a58
REF 008288e4 UNCONDITIONAL_CALL caller=getInitSecAndFrame@008288a0
REF 0082a774 UNCONDITIONAL_CALL caller=imvt_app_timecode_update_record_timecode@0082a6e0
REF 0082a79c UNCONDITIONAL_CALL caller=imvt_app_timecode_update_record_timecode@0082a6e0
REF 0082bb64 UNCONDITIONAL_CALL caller=HPTimer@0082ba18
REF 0082bb84 UNCONDITIONAL_CALL caller=HPTimer@0082ba18
REF 0082bba4 UNCONDITIONAL_CALL caller=HPTimer@0082ba18
REF 0082bca4 UNCONDITIONAL_CALL caller=~HPTimer@0082bbc0
REF 0082bd9c UNCONDITIONAL_CALL caller=start@0082bcb0
REF 0082bdbc UNCONDITIONAL_CALL caller=start@0082bcb0
REF 0082be64 UNCONDITIONAL_CALL caller=stop@0082bdd0
REF 0082be84 UNCONDITIONAL_CALL caller=stop@0082bdd0
REF 0082bfb0 UNCONDITIONAL_CALL caller=setInterval@0082be98
REF 0082bfc8 UNCONDITIONAL_CALL caller=setInterval@0082be98
REF 0082c118 UNCONDITIONAL_CALL caller=timerThread@0082bfd8
REF 0082c49c UNCONDITIONAL_CALL caller=active@0082c3e0
REF 0082d620 UNCONDITIONAL_CALL caller=cameraEventHandler@0082d530
REF 0082d6e8 UNCONDITIONAL_CALL caller=cameraEventHandler@0082d530
REF 0082d814 UNCONDITIONAL_CALL caller=cameraEventHandler@0082d530
REF 0082d8c4 UNCONDITIONAL_CALL caller=cameraEventHandler@0082d530
REF 0082d8fc UNCONDITIONAL_CALL caller=cameraEventHandler@0082d530
REF 0082d99c UNCONDITIONAL_CALL caller=cameraEventHandler@0082d530
REF 0082da3c UNCONDITIONAL_CALL caller=cameraEventHandler@0082d530
REF 0082dfbc UNCONDITIONAL_CALL caller=dispatchMessage@0082dec0
REF 0082e158 UNCONDITIONAL_CALL caller=dispatchMessage@0082dec0
REF 0082e1fc UNCONDITIONAL_CALL caller=dispatchMessage@0082dec0
REF 0082e2a8 UNCONDITIONAL_CALL caller=dispatchMessage@0082dec0
REF 008387a4 UNCONDITIONAL_CALL caller=init@00838768
REF 008388e4 UNCONDITIONAL_CALL caller=init@00838768
REF 008383fc UNCONDITIONAL_CALL caller=openTty@00838308
REF 00838424 UNCONDITIONAL_CALL caller=openTty@00838308
REF 00838448 UNCONDITIONAL_CALL caller=openTty@00838308
REF 00837d98 UNCONDITIONAL_CALL caller=deinit@00837d20
REF 00834168 UNCONDITIONAL_CALL caller=handleUartCmd@00834108
REF 008341bc UNCONDITIONAL_CALL caller=handleUartCmd@00834108
REF 008341e0 UNCONDITIONAL_CALL caller=handleUartCmd@00834108
REF 008341f4 UNCONDITIONAL_CALL caller=handleUartCmd@00834108
REF 00834634 UNCONDITIONAL_CALL caller=FUN_00834520@00834520
REF 00836050 UNCONDITIONAL_CALL caller=commUpgrade@00835ee8
REF 00836114 UNCONDITIONAL_CALL caller=commUpgrade@00835ee8
REF 00836180 UNCONDITIONAL_CALL caller=commUpgrade@00835ee8
REF 008361ac UNCONDITIONAL_CALL caller=commUpgrade@00835ee8
REF 008361c4 UNCONDITIONAL_CALL caller=commUpgrade@00835ee8
REF 008361ec UNCONDITIONAL_CALL caller=commUpgrade@00835ee8
REF 0083620c UNCONDITIONAL_CALL caller=commUpgrade@00835ee8
REF 00836234 UNCONDITIONAL_CALL caller=commUpgrade@00835ee8
REF 00836258 UNCONDITIONAL_CALL caller=commUpgrade@00835ee8
REF 008362dc UNCONDITIONAL_CALL caller=upgrade@00836268
REF 00836338 UNCONDITIONAL_CALL caller=upgrade@00836268
REF 00836350 UNCONDITIONAL_CALL caller=upgrade@00836268
REF 00837f24 UNCONDITIONAL_CALL caller=checkCrc16@00837eb8
REF 0083810c UNCONDITIONAL_CALL caller=worker@008380b8
REF 00838268 UNCONDITIONAL_CALL caller=worker@008380b8
REF 008382c8 UNCONDITIONAL_CALL caller=worker@008380b8
REF 008382d8 UNCONDITIONAL_CALL caller=worker@008380b8
REF 008382fc UNCONDITIONAL_CALL caller=worker@008380b8
REF 00838be4 UNCONDITIONAL_CALL caller=deinit@00838bc0
REF 00839c6c UNCONDITIONAL_CALL caller=openTty@00839b78
REF 00839c94 UNCONDITIONAL_CALL caller=openTty@00839b78
REF 00839cb8 UNCONDITIONAL_CALL caller=openTty@00839b78
REF 0083a2d0 UNCONDITIONAL_CALL caller=imvt_cac_get@0083a180
REF 0083a2f8 UNCONDITIONAL_CALL caller=imvt_cac_get@0083a180
REF 0083ab08 UNCONDITIONAL_CALL caller=imvt_cac_init@0083aa98
REF 0083afe8 UNCONDITIONAL_CALL caller=imvt_nf_calib_read_data@0083af28
REF 0083b030 UNCONDITIONAL_CALL caller=imvt_nf_calib_read_data@0083af28
REF 0083b048 UNCONDITIONAL_CALL caller=imvt_nf_calib_read_data@0083af28
REF 0083b7e4 UNCONDITIONAL_CALL caller=gl_util_create_compute_program@0083b6d8
REF 00848558 UNCONDITIONAL_CALL caller=FUN_00848298@00848298
REF 00848624 UNCONDITIONAL_CALL caller=FUN_00848298@00848298
REF 0084973c UNCONDITIONAL_CALL caller=fmt_uvc_streamer_enable@00849668
REF 00849754 UNCONDITIONAL_CALL caller=fmt_uvc_streamer_enable@00849668
REF 00849770 UNCONDITIONAL_CALL caller=fmt_uvc_streamer_enable@00849668
REF 00849798 UNCONDITIONAL_CALL caller=fmt_uvc_streamer_enable@00849668
REF 0084920c UNCONDITIONAL_CALL caller=FUN_008491c0@008491c0
REF 00849488 UNCONDITIONAL_CALL caller=FUN_00849270@00849270
REF 008494ec UNCONDITIONAL_CALL caller=FUN_00849270@00849270
REF 008495e8 UNCONDITIONAL_CALL caller=FUN_00849270@00849270
REF 00849614 UNCONDITIONAL_CALL caller=FUN_00849270@00849270
REF 00849648 UNCONDITIONAL_CALL caller=FUN_00849270@00849270
REF 0084965c UNCONDITIONAL_CALL caller=FUN_00849270@00849270
REF 00864c44 UNCONDITIONAL_CALL caller=uac_start_playback@00864b78
REF 008649bc UNCONDITIONAL_CALL caller=FUN_00864838@00864838
REF 008649e8 UNCONDITIONAL_CALL caller=FUN_00864838@00864838
REF 00864a18 UNCONDITIONAL_CALL caller=FUN_00864838@00864838
REF 00864a48 UNCONDITIONAL_CALL caller=FUN_00864838@00864838
REF 00864a78 UNCONDITIONAL_CALL caller=FUN_00864838@00864838
REF 00864aa8 UNCONDITIONAL_CALL caller=FUN_00864838@00864838
REF 00864ad8 UNCONDITIONAL_CALL caller=FUN_00864838@00864838
REF 00864b08 UNCONDITIONAL_CALL caller=FUN_00864838@00864838
REF 00864b38 UNCONDITIONAL_CALL caller=FUN_00864838@00864838
REF 00864b64 UNCONDITIONAL_CALL caller=FUN_00864838@00864838
REF 008499e4 UNCONDITIONAL_CALL caller=FUN_00849940@00849940
REF 00849b4c UNCONDITIONAL_CALL caller=FUN_00849ab0@00849ab0
REF 0084ae64 UNCONDITIONAL_CALL caller=imvt_uvc_factory_request_set@0084ae08
REF 0084aed8 UNCONDITIONAL_CALL caller=imvt_uvc_factory_request_set@0084ae08
REF 0084af00 UNCONDITIONAL_CALL caller=imvt_uvc_factory_request_set@0084ae08
REF 0084af14 UNCONDITIONAL_CALL caller=imvt_uvc_factory_request_set@0084ae08
REF 0084ace8 UNCONDITIONAL_CALL caller=FUN_0084ac88@0084ac88
REF 00860398 UNCONDITIONAL_CALL caller=FUN_008602c0@008602c0
REF 00abcc90 UNCONDITIONAL_CALL caller=imvt_raw_bpc_detect_stop@00abcc00
REF 00abccbc UNCONDITIONAL_CALL caller=imvt_raw_bpc_detect_stop@00abcc00
REF 00abccdc UNCONDITIONAL_CALL caller=imvt_raw_bpc_detect_stop@00abcc00
REF 00abcd00 UNCONDITIONAL_CALL caller=imvt_raw_bpc_detect_stop@00abcc00
REF 00abbe78 UNCONDITIONAL_CALL caller=FUN_00abba98@00abba98
REF 00abbe30 UNCONDITIONAL_CALL caller=FUN_00abba98@00abba98
REF 00abc020 UNCONDITIONAL_CALL caller=FUN_00abba98@00abba98
REF 00abc034 UNCONDITIONAL_CALL caller=FUN_00abba98@00abba98
REF 00abc06c UNCONDITIONAL_CALL caller=FUN_00abba98@00abba98
REF 00abc0e8 UNCONDITIONAL_CALL caller=FUN_00abba98@00abba98
*/

void imvt_printf(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                uint param_9,char *param_10,undefined8 param_11,undefined8 param_12,
                undefined8 param_13,undefined8 param_14,undefined8 param_15,undefined8 param_16)

{
  bool bVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  char *pcVar7;
  char *pcVar8;
  size_t *psVar9;
  size_t *psVar10;
  undefined *puVar11;
  undefined1 *local_520;
  undefined1 *puStack_518;
  undefined8 *local_510;
  undefined8 uStack_508;
  size_t local_4d8 [4];
  char acStack_4b8 [1024];
  long local_b8;
  undefined8 local_b0;
  undefined8 local_a0;
  undefined8 local_90;
  undefined8 local_80;
  undefined8 local_70;
  undefined8 local_60;
  undefined8 local_50;
  undefined8 local_40;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 local_8;
  
  local_b8 = *(long *)PTR___stack_chk_guard_010398b8;
  local_b0 = param_1;
  local_a0 = param_2;
  local_90 = param_3;
  local_80 = param_4;
  local_70 = param_5;
  local_60 = param_6;
  local_50 = param_7;
  local_40 = param_8;
  local_30 = param_11;
  uStack_28 = param_12;
  local_20 = param_13;
  uStack_18 = param_14;
  local_10 = param_15;
  local_8 = param_16;
  if ((int)param_9 < 0) {
    puVar11 = &DAT_00e23148;
    pcVar8 = "[E]";
    param_9 = 0;
    bVar1 = false;
    uVar3 = 0;
    if (DAT_046e3dc8 != '\0') goto LAB_00a38a20;
  }
  else {
    if ((int)param_9 < 6) {
      uVar6 = -(ulong)(param_9 >> 0x1f) & 0xfffffff000000000 | (ulong)param_9 << 4;
      pcVar8 = *(char **)((long)&PTR_DAT_010141a0 + uVar6);
      puVar11 = *(undefined **)((long)&PTR_DAT_010141a8 + uVar6);
    }
    else {
      puVar11 = &DAT_00e23158;
      pcVar8 = "[V]";
      param_9 = 4;
    }
    uVar3 = param_9;
    if (DAT_046e3dc8 != '\0') {
LAB_00a38a20:
      param_9 = uVar3;
      if (DAT_046e3224 == 0) goto LAB_00a38ba0;
    }
    bVar1 = (int)(uint)DAT_0108aec0 < (int)param_9;
  }
  memset(acStack_4b8,0,0x400);
  iVar4 = FUN_00a38108(acStack_4b8);
  iVar5 = iVar4 + 3;
  strcpy(acStack_4b8 + iVar4,pcVar8);
  local_510 = &local_30;
  uStack_508 = 0xffffff80ffffffd0;
  local_520 = (undefined1 *)register0x00000008;
  puStack_518 = (undefined1 *)register0x00000008;
  iVar4 = vsnprintf(acStack_4b8 + iVar5,(long)(0x400 - iVar5),param_10,&local_520);
  if (DAT_046e3dc8 == '\0') {
    if ((bVar1) || (DAT_046e3dc9 != '\0')) goto LAB_00a38ba0;
LAB_00a38c00:
    fprintf(*(FILE **)PTR_stderr_010371f0,"%s%s",puVar11,acStack_4b8);
    if (DAT_046e3dc8 == '\0') goto LAB_00a38ba0;
  }
  else {
    if (DAT_046e3c58 != 0) {
      pcVar8 = &DAT_046e3c60;
      do {
        if ((*(int *)(pcVar8 + -4) != 0) &&
           (pcVar7 = strstr(acStack_4b8,pcVar8), pcVar7 != (char *)0x0)) goto LAB_00a38b18;
        pcVar8 = pcVar8 + 0x24;
      } while (pcVar8 != &DAT_046e3dc8);
    }
    if ((!bVar1) && (DAT_046e3dc9 == '\0')) goto LAB_00a38c00;
  }
LAB_00a38b18:
  lVar2 = DAT_046e3c50;
  if ((DAT_046e3224 != 1) && ((int)param_9 < DAT_046e3220)) {
    if (DAT_046e3c50 == 0) {
      FUN_00a381d8(1,"LOG ALREADY DEINIT()\n");
    }
    else {
      iVar5 = mwsr_buffer_write_data_2(DAT_046e3c50,iVar5 + iVar4,local_4d8);
      if (iVar5 != 0) {
        if (iVar5 < 1) {
          iVar4 = 0;
        }
        else {
          iVar4 = 0;
          psVar9 = local_4d8 + 1;
          do {
            memcpy((void *)psVar9[-1],acStack_4b8 + iVar4,*psVar9);
            psVar10 = psVar9 + 2;
            iVar4 = iVar4 + (int)*psVar9;
            psVar9 = psVar10;
          } while (psVar10 != local_4d8 + (ulong)(iVar5 - 1) * 2 + 3);
        }
        mwsr_buffer_write_commit_2(lVar2,iVar4);
      }
    }
  }
LAB_00a38ba0:
  if (local_b8 != *(long *)PTR___stack_chk_guard_010398b8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  return;
}



/* FUNCTION HI_MPI_ISP_GetPubAttr @ 00b06098 body=[[00b06098, 00b060db] [00b060e0, 00b061b3] [00b061b8, 00b0621b]]
REF Entry Point EXTERNAL caller=NONE
REF 007037ec UNCONDITIONAL_CALL caller=imvt_cam_controller_multiple_net_sync_prepare_rec@00703770
REF 00886a50 UNCONDITIONAL_CALL caller=imvt_isp_af_set_attr@008869e8
REF 00885d80 UNCONDITIONAL_CALL caller=FUN_00885cb0@00885cb0
REF 00886c14 UNCONDITIONAL_CALL caller=imvt_isp_af_init@00886be8
REF 00895ea8 UNCONDITIONAL_CALL caller=hi3559av100_switch_vi_mode@00895980
REF 008961b4 UNCONDITIONAL_CALL caller=hi3559av100_switch_vi_mode@00895980
REF 00885f8c UNCONDITIONAL_CALL caller=NONE
*/

int HI_MPI_ISP_GetPubAttr(uint param_1,uint *param_2)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  
  if (param_1 < 10) {
    if (param_2 == (uint *)0x0) {
      iVar2 = -0x5fe37ffa;
      fprintf(*(FILE **)PTR_stderr_010371f0,"[Func]:%s [Line]:%d [Info]:Null Pointer!\n",
              "hi_mpi_isp_get_pub_attr",0x9b);
    }
    else {
      iVar2 = ISP_CheckDevOpen();
      if (iVar2 == 0) {
        iVar2 = ISP_CheckMemInit((ulong)param_1);
        if (iVar2 == 0) {
          iVar2 = (param_1 + 8) * 0x20000;
          uVar3 = IO_READ8(iVar2 + 0xf0);
          uVar3 = uVar3 & 0xff;
          if (3 < uVar3) {
            uVar3 = 4;
          }
          param_2[7] = uVar3;
          uVar4 = IO_READ16(iVar2 + 0x3a);
          uVar3 = (uint)(uVar4 >> 4) & 0x3f;
          if (0xb < uVar3) {
            uVar3 = 0xc;
          }
          param_2[8] = uVar3;
          uVar3 = IO_READ32(iVar2 + 0x10);
          param_2[6] = uVar3;
          uVar1 = IO_READ8(iVar2 + 0xf2);
          *(undefined1 *)(param_2 + 9) = uVar1;
          uVar3 = IO_READ16(iVar2 + 0xd4);
          *param_2 = uVar3 & 0xffff;
          uVar3 = IO_READ16(iVar2 + 0xd6);
          param_2[1] = uVar3 & 0xffff;
          uVar3 = IO_READ16(iVar2 + 0x3c);
          param_2[2] = uVar3 & 0xffff;
          uVar3 = IO_READ16(iVar2 + 0x40);
          param_2[3] = uVar3 & 0xffff;
          uVar3 = IO_READ32(iVar2 + 8);
          param_2[4] = uVar3;
          uVar3 = IO_READ32(iVar2 + 0xc);
          param_2[5] = uVar3;
          return 0;
        }
      }
    }
  }
  else {
    iVar2 = -0x5fe37ffd;
    fprintf(*(FILE **)PTR_stderr_010371f0,"[Func]:%s [Line]:%d [Info]:Err isp pipe %d!\n",
            "hi_mpi_isp_get_pub_attr",0x9a,(ulong)param_1);
  }
  return iVar2;
}



/* FUNCTION FUN_00885cb0 @ 00885cb0 body=[[00885cb0, 00885eab]]
REF 00886aa4 UNCONDITIONAL_CALL caller=imvt_isp_af_set_attr@008869e8
REF 00885fbc UNCONDITIONAL_CALL caller=NONE
REF 008861c4 UNCONDITIONAL_CALL caller=NONE
*/

void FUN_00885cb0(float param_1,float param_2,float param_3,float param_4,undefined4 param_5,
                 undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 local_2c0;
  undefined8 uStack_2b8;
  undefined8 local_2b0;
  undefined4 local_2a8;
  undefined8 local_2a0;
  undefined8 local_298;
  undefined8 local_290;
  undefined8 local_288;
  undefined8 local_280;
  undefined1 auStack_278 [356];
  undefined1 auStack_114 [268];
  long local_8;
  
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  memset(auStack_278,0,0x270);
  local_2a0 = 0;
  local_298 = 0;
  local_290 = 0;
  local_288 = 0;
  local_2c0 = 0;
  uStack_2b8 = 0;
  local_2b0 = 0;
  local_2a8 = 0;
  local_280 = 0;
  uVar1 = HI_MPI_ISP_GetStatisticsConfig(0,auStack_278);
  uVar2 = HI_MPI_ISP_GetPubAttr(0,&local_2a0);
  DAT_045a9398 = (int)(float)local_288;
  DAT_010675ae = (undefined2)(int)param_4;
  DAT_010675ac = (undefined2)(int)param_3;
  DAT_010675a4 = 1;
  DAT_010675b0 = 1;
  DAT_010675a8 = (undefined2)(int)param_1;
  DAT_01067594 = (undefined2)param_5;
  DAT_01067596 = (undefined2)param_6;
  DAT_010675aa = (undefined2)(int)param_2;
  DAT_0106759a = (undefined2)((ulong)local_298 >> 0x20);
  DAT_045a9820 = (undefined4)local_280;
  DAT_01067598 = (undefined2)local_298;
  if ((uVar1 | uVar2) == 0) {
    memcpy(auStack_114,&DAT_01067590,0x10c);
    uVar1 = HI_MPI_ISP_SetStatisticsConfig(0,auStack_278);
    if (uVar1 == 0) {
      DAT_045a93a8 = 0;
      local_2c0 = CONCAT44(param_1 / (float)DAT_045a939c,(undefined4)local_2c0);
      uStack_2b8 = CONCAT44(param_3 / (float)DAT_045a939c,param_2 / (float)DAT_045a93a0);
      local_2b0 = CONCAT44(param_5,param_4 / (float)DAT_045a93a0);
      local_2a8 = param_6;
      n3a_af_set_roi(&local_2c0);
      uVar3 = 0;
    }
    else {
      printf("HI_MPI_ISP_SetStatisticsConfig error!(s32Ret = 0x%x)\n",(ulong)uVar1);
      uVar3 = 0xffffffff;
    }
  }
  else {
    printf("HI_MPI_ISP_GetStatisticsConfig error!(s32Ret = 0x%x)\n",(ulong)(uVar1 | uVar2));
    uVar3 = 0xffffffff;
  }
  if (local_8 == *(long *)PTR___stack_chk_guard_010398b8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}



/* FUNCTION FUN_00887708 @ 00887708 body=[[00887708, 008877e3] [008877e8, 0088781b] [00887820, 0088783b]]
REF 00888308 UNCONDITIONAL_CALL caller=imvt_n3a_af_set_roi@00888298
REF 00887a58 UNCONDITIONAL_CALL caller=FUN_00887840@00887840
REF 008887ac UNCONDITIONAL_CALL caller=imvt_n3a_af_lose_human_roi@00888740
REF 008886d0 UNCONDITIONAL_CALL caller=imvt_n3a_af_set_face_roi@00888548
*/

void FUN_00887708(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  long local_8;
  
  lVar2 = DAT_045a9978;
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  iVar3 = n3a_af_get_af_mode(PTR___stack_chk_guard_010398b8,0);
  uVar1 = *(undefined4 *)(lVar2 + (long)iVar3 * 0x220 + 0x6e8);
  imvt_isp_af_get_roi(&local_28,&local_24,&local_20,&local_1c);
  iVar3 = imvt_isp_af_set_roi(param_1,param_2,param_3,param_4,uVar1);
  if (iVar3 == 0) {
    uVar4 = 0;
    imvt_isp_af_get_roi(&local_18,&local_14,&local_10,&local_c);
    if (((((local_28 != local_18) || (local_24 != local_14)) || (local_20 != local_10)) ||
        (local_1c != local_c)) && (DAT_045a9898 != (code *)0x0)) {
      (*DAT_045a9898)();
    }
    DAT_045a9900 = 0;
  }
  else {
    uVar4 = 0xffffffff;
    imvt_printf(0,"[af] set roi failed !!\n");
  }
  if (local_8 == *(long *)PTR___stack_chk_guard_010398b8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar4);
}



/* FUNCTION n3a_af_get_af_mode @ 00d3a4e8 body=[[00d3a4e8, 00d3a4f3]]
REF Entry Point EXTERNAL caller=NONE
REF 00f1854c INDIRECTION caller=NONE
REF 00fe034c DATA caller=NONE
REF 00889254 UNCONDITIONAL_CALL caller=imvt_n3a_af_set_mode@00889220
REF 008882e0 UNCONDITIONAL_CALL caller=imvt_n3a_af_set_roi@00888298
REF 00887740 UNCONDITIONAL_CALL caller=FUN_00887708@00887708
REF 00888768 UNCONDITIONAL_CALL caller=imvt_n3a_af_lose_human_roi@00888740
REF 00d41d40 UNCONDITIONAL_CALL caller=n3a_af_set_roi@00d41d28
REF 008885a4 UNCONDITIONAL_CALL caller=imvt_n3a_af_set_face_roi@00888548
REF 00d3ae34 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3af1c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d41154 UNCONDITIONAL_CALL caller=n3a_af_parse_fv@00d41110
REF 00889308 UNCONDITIONAL_CALL caller=imvt_n3a_af_get_mode@008892f0
REF 00d3cf74 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d24c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00887598 UNCONDITIONAL_CALL caller=FUN_00887420@00887420
REF 00888838 UNCONDITIONAL_CALL caller=FUN_008887e0@008887e0
*/

undefined4 n3a_af_get_af_mode(void)

{
  return DAT_047b595c;
}



/* FUNCTION FUN_008883d0 @ 008883d0 body=[[008883d0, 008883e3]]
REF 008886e0 UNCONDITIONAL_CALL caller=imvt_n3a_af_set_face_roi@00888548
REF 0088873c UNCONDITIONAL_CALL caller=imvt_n3a_af_lose_face_roi@00888710
*/

void FUN_008883d0(void)

{
  imvt_n3a_af_set_roi((undefined4)DAT_045a98e0,DAT_045a98e0._4_4_,(undefined4)DAT_045a98e8,
                      DAT_045a98e8._4_4_);
  return;
}



/* FUNCTION imvt_af_register_params @ 00730bb0 body=[[00730bb0, 00730bd3]]
REF Entry Point EXTERNAL caller=NONE
REF 00efd994 INDIRECTION caller=NONE
REF 00f4ee3c DATA caller=NONE
REF 00a69ed4 UNCONDITIONAL_CALL caller=imvt_cam_adj_register_af_params@00a69eb0
REF 00a69efc UNCONDITIONAL_CALL caller=imvt_cam_adj_register_af_params@00a69eb0
REF 00a69f14 UNCONDITIONAL_CALL caller=imvt_cam_adj_register_af_params@00a69eb0
*/

void imvt_af_register_params(undefined8 param_1,undefined8 param_2)

{
  imvt_n3a_af_register_params();
  imvt_isp_af_register_params(param_2);
  return;
}



/* FUNCTION imvt_adj_get_af_isp_params @ 00a69f18 body=[[00a69f18, 00a69f23]]
REF Entry Point EXTERNAL caller=NONE
REF 00f118ac INDIRECTION caller=NONE
REF 00fbf000 DATA caller=NONE
REF 00a69ec4 UNCONDITIONAL_CALL caller=imvt_cam_adj_register_af_params@00a69eb0
REF 00a69ee8 UNCONDITIONAL_CALL caller=imvt_cam_adj_register_af_params@00a69eb0
REF 00a69f00 UNCONDITIONAL_CALL caller=imvt_cam_adj_register_af_params@00a69eb0
*/

undefined * imvt_adj_get_af_isp_params(void)

{
  return &DAT_00e2fd10;
}



/* FUNCTION FUN_00d316a0 @ 00d316a0 body=[[00d316a0, 00d317ab] [00d317b0, 00d3190b]]
REF 00d31a84 UNCONDITIONAL_CALL caller=imvt_tracker_run@00d31910
REF 00d31b64 UNCONDITIONAL_CALL caller=imvt_tracker_run_deep_search@00d31b38
*/

void FUN_00d316a0(undefined8 param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  ulong uVar8;
  int iVar9;
  float *pfVar10;
  ulong uVar11;
  int iVar12;
  int iVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  int local_4;
  
  uVar4 = DAT_00d3190c;
  fVar17 = (float)param_2[7];
  DAT_047ae9dc = (float)param_2[3];
  if (fVar17 <= 1.0) {
    fVar17 = 1.0;
  }
  if (param_3 == 0) {
    DAT_047ae9dc = fVar17 * DAT_047ae9dc;
  }
  iVar13 = 0;
  DAT_047ae9e8 = param_3;
  DAT_047ae9f0 = param_1;
  param_2[8] = 0;
  param_2[9] = 0;
  do {
    fVar16 = DAT_047ae9dc / fVar17;
    local_4 = 0;
    DAT_047ae9dc = fVar16;
    pfVar7 = (float *)imvt_yolo2_get_detection_c
                                (fVar16,0x3f000000,&DAT_047ae968,DAT_047ae9e0,DAT_047ae9e4,0,1,
                                 &local_4);
    imvt_yolo2_do_nms_sort_c(uVar4,pfVar7,local_4,DAT_047ae9cc);
    iVar5 = DAT_047ae9cc;
    iVar12 = 0;
    iVar1 = *param_2;
    iVar2 = param_2[1];
    iVar3 = param_2[2];
    if (0 < local_4) {
      iVar12 = 0;
      uVar11 = 0;
      pfVar10 = pfVar7;
      do {
        if (0 < iVar5) {
          uVar8 = 0;
          iVar9 = -1;
          fVar15 = 0.0;
          do {
            while (fVar14 = *(float *)(*(long *)(pfVar10 + 6) + uVar8 * 4), fVar14 <= fVar16) {
LAB_00d317c0:
              uVar8 = uVar8 + 1;
              if (iVar5 <= (int)uVar8) goto LAB_00d317f8;
            }
            if (iVar9 != -1) {
              if (fVar15 < fVar14) {
                uVar11 = uVar8 & 0xffffffff;
                fVar15 = fVar14;
              }
              goto LAB_00d317c0;
            }
            uVar11 = uVar8 & 0xffffffff;
            iVar9 = (int)uVar8;
            uVar8 = uVar8 + 1;
            fVar15 = fVar14;
          } while ((int)uVar8 < iVar5);
LAB_00d317f8:
          if ((iVar9 != -1) && (iVar3 == 0 || (int)uVar11 == 0)) {
            fVar20 = pfVar10[2];
            fVar19 = pfVar10[3];
            fVar18 = *pfVar10;
            fVar14 = pfVar10[1];
            param_2[(long)iVar12 * 4 + 0xe] = (int)fVar15;
            *(short *)(param_2 + (long)iVar12 * 4 + 0xb) = (short)uVar11;
            *(short *)((long)param_2 + (long)iVar12 * 0x10 + 0x32) =
                 (short)(int)((float)iVar1 * fVar20);
            *(short *)(param_2 + (long)iVar12 * 4 + 0xd) = (short)(int)((float)iVar2 * fVar19);
            iVar9 = (int)((fVar18 - fVar20 * 0.5) * (float)iVar1);
            iVar6 = (int)((fVar14 - fVar19 * 0.5) * (float)iVar2);
            if (iVar9 < 0) {
              iVar9 = 0;
            }
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            *(short *)((long)param_2 + (long)iVar12 * 0x10 + 0x2e) = (short)iVar9;
            *(short *)(param_2 + (long)iVar12 * 4 + 0xc) = (short)iVar6;
            iVar12 = iVar12 + 1;
          }
        }
        pfVar10 = pfVar10 + 0xc;
      } while (pfVar10 != pfVar7 + ((ulong)(local_4 - 1) + 1) * 0xc);
    }
    param_2[8] = iVar12;
    iVar13 = iVar13 + 1;
    imvt_yolo2_free_detection_c(pfVar7);
    fVar16 = DAT_047ae9dc;
    if (((param_2[6] <= param_2[8]) || (DAT_047ae9dc <= (float)param_2[4])) ||
       (DAT_047ae9e8 = 1, param_3 == 0)) {
      param_2[9] = iVar13;
      param_2[10] = (int)fVar16;
      return;
    }
  } while( true );
}



/* FUNCTION HI_MPI_SYS_MmzFlushCache @ 00b991b0 body=[[00b991b0, 00b9925b] [00b99260, 00b992ab]]
REF Entry Point EXTERNAL caller=NONE
REF 00d31978 UNCONDITIONAL_CALL caller=imvt_tracker_run@00d31910
REF 00d31a58 UNCONDITIONAL_CALL caller=imvt_tracker_run@00d31910
REF 00d31b14 UNCONDITIONAL_CALL caller=imvt_tracker_run@00d31910
REF 00d31cf0 UNCONDITIONAL_CALL caller=imvt_tracker_init@00d31bb0
REF 00d323b4 UNCONDITIONAL_CALL caller=FUN_00d31f58@00d31f58
REF 00bed820 UNCONDITIONAL_JUMP caller=ive_flush_cache@00bed820
*/

void HI_MPI_SYS_MmzFlushCache(long param_1,long param_2,ulong param_3)

{
  uint uVar1;
  ulong uVar2;
  long local_20;
  long lStack_18;
  ulong local_10;
  long local_8;
  
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  if (param_2 == 0) {
    fprintf(*(FILE **)PTR_stderr_010371f0,"[Func]:%s [Line]:%d [Info]:Null point \n",
            "hi_mpi_sys_mmz_flush_cache",0x3c7);
    uVar2 = 0xa0028006;
  }
  else {
    uVar2 = FUN_00b97a88(PTR___stack_chk_guard_010398b8,0);
    if ((int)uVar2 == 0) {
      pthread_mutex_lock((pthread_mutex_t *)&DAT_0475f230);
      if (param_1 == 0) {
        uVar1 = ioctl(DAT_01330328,0x6328,0);
      }
      else {
        local_20 = param_1;
        lStack_18 = param_2;
        local_10 = param_3 & 0xffffffff;
        uVar1 = ioctl(DAT_01330328,0x40186432,&local_20);
      }
      uVar2 = (ulong)uVar1;
      pthread_mutex_unlock((pthread_mutex_t *)&DAT_0475f230);
    }
  }
  if (local_8 == *(long *)PTR___stack_chk_guard_010398b8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}



/* FUNCTION HI_MPI_SVP_NNIE_Query @ 00d37b38 body=[[00d37b38, 00d37bfb] [00d37c00, 00d37c33] [00d37c38, 00d37c5f]]
REF Entry Point EXTERNAL caller=NONE
REF 00d319f4 UNCONDITIONAL_CALL caller=imvt_tracker_run@00d31910
*/

void HI_MPI_SVP_NNIE_Query
               (undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  uint uVar1;
  ulong uVar2;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  long local_8;
  
  local_20 = 0;
  local_18 = 0;
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  local_10 = 0;
  uVar1 = svp_nnie_check_query_param_user();
  if (uVar1 == 0) {
    local_20 = CONCAT44(param_2,param_1);
    local_18 = CONCAT44(local_18._4_4_,param_4);
    local_10 = 0;
    pthread_mutex_lock((pthread_mutex_t *)&DAT_047b58f8);
    if ((DAT_01384938 < 0) && (DAT_01384938 = open64("/dev/nnie",0), DAT_01384938 < 0)) {
      uVar2 = FUN_00d36238();
      if ((int)uVar2 != 0) goto LAB_00d37bd0;
    }
    else {
      pthread_mutex_unlock((pthread_mutex_t *)&DAT_047b58f8);
    }
    uVar1 = ioctl(DAT_01384938,0xc0184d02,&local_20);
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0) {
      *param_3 = local_18._4_4_;
    }
  }
  else {
    uVar2 = (ulong)uVar1;
    fprintf(*(FILE **)PTR_stderr_010371f0,
            "[Func]:%s [Line]:%d [Info]:Error(%#x): Check query parameters failed!\n",
            "hi_mpi_svp_nnie_query",0x41b,uVar2);
  }
LAB_00d37bd0:
  if (local_8 != *(long *)PTR___stack_chk_guard_010398b8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



/* FUNCTION imvt_yolo2_get_mmz_memory_size_c @ 00d33f38 body=[[00d33f38, 00d33f5b]]
REF Entry Point EXTERNAL caller=NONE
REF 00f183cc INDIRECTION caller=NONE
REF 00fdfd0c DATA caller=NONE
REF 00d31c98 UNCONDITIONAL_CALL caller=imvt_tracker_init@00d31bb0
*/

void imvt_yolo2_get_mmz_memory_size_c(undefined8 param_1)

{
  FUN_00d33b74(param_1,0,0);
  return;
}



/* FUNCTION imvt_nnie_param_deinit @ 00d32890 body=[[00d32890, 00d328f3]]
REF Entry Point EXTERNAL caller=NONE
REF 00d31e90 UNCONDITIONAL_CALL caller=imvt_tracker_deinit@00d31e50
REF 00d31d8c UNCONDITIONAL_CALL caller=imvt_tracker_init@00d31bb0
REF 00d3294c UNCONDITIONAL_CALL caller=imvt_nnie_param_init@00d328f8
*/

undefined8 imvt_nnie_param_deinit(long param_1)

{
  if ((*(long *)(param_1 + 0x30) != 0) && (*(long *)(param_1 + 0x38) != 0)) {
    HI_MPI_SYS_MmzFree();
    *(undefined8 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  if ((*(long *)(param_1 + 0x60) != 0) && (*(long *)(param_1 + 0x68) != 0)) {
    HI_MPI_SYS_MmzFree();
    *(undefined8 *)(param_1 + 0x60) = 0;
    *(undefined8 *)(param_1 + 0x68) = 0;
    return 0;
  }
  return 0;
}



/* FUNCTION HI_MPI_SYS_MmzAlloc_Cached @ 00b98e50 body=[[00b98e50, 00b98fa3] [00b98fa8, 00b99073]]
REF Entry Point EXTERNAL caller=NONE
REF 0080659c UNCONDITIONAL_CALL caller=gl_assitool_init@00806450
REF 00d31ccc UNCONDITIONAL_CALL caller=imvt_tracker_init@00d31bb0
REF 00d32394 UNCONDITIONAL_CALL caller=FUN_00d31f58@00d31f58
REF 00804780 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 00804a88 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 00805600 UNCONDITIONAL_CALL caller=FUN_00804208@00804208
REF 00bed81c UNCONDITIONAL_CALL caller=ive_malloc_cached@00bed810
*/

void HI_MPI_SYS_MmzAlloc_Cached
               (undefined8 *param_1,undefined8 *param_2,long param_3,long param_4,uint param_5)

{
  int __fd;
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 local_70;
  undefined8 uStack_68;
  ulong local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  long local_8;
  
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  if (param_1 == (undefined8 *)0x0) {
    uVar3 = 0x37c;
  }
  else {
    if (param_2 != (undefined8 *)0x0) {
      uVar2 = FUN_00b97a88();
      if ((int)uVar2 == 0) {
        pthread_mutex_lock((pthread_mutex_t *)&DAT_0475f230);
        uVar3 = local_48;
        local_48 = CONCAT71(local_48._1_7_,3);
        local_48 = CONCAT44(SUB84(uVar3,4),
                            (uint)local_48 & 0xfff00000 | (uint)local_48 & 0xff | 0x100);
        local_60 = (ulong)param_5;
        if (param_3 != 0) {
          strncpy_s(&local_40,0x10,param_3,0xf);
        }
        if (param_4 != 0) {
          strncpy_s(&local_30,0x20,param_4,0x1f);
        }
        __fd = DAT_01330328;
        uVar1 = ioctl(DAT_01330328,0xc0686d0a,&local_70);
        uVar2 = (ulong)uVar1;
        if (uVar1 == 0) {
          uVar1 = ioctl(__fd,0xc0686d15,&local_70);
          uVar2 = (ulong)uVar1;
          if (uVar1 == 0) {
            *param_1 = local_70;
            *param_2 = local_50;
            pthread_mutex_unlock((pthread_mutex_t *)&DAT_0475f230);
            uVar2 = 0;
          }
          else {
            fprintf(*(FILE **)PTR_stderr_010371f0,
                    "[Func]:%s [Line]:%d [Info]:system remap mmz memory failed!\n",
                    "hi_mpi_sys_mmz_alloc_cached",0x397);
            ioctl(DAT_01330328,0x40686d0c,&local_70);
            pthread_mutex_unlock((pthread_mutex_t *)&DAT_0475f230);
          }
        }
        else {
          fprintf(*(FILE **)PTR_stderr_010371f0,
                  "[Func]:%s [Line]:%d [Info]:system alloc mmz memory failed!\n",
                  "hi_mpi_sys_mmz_alloc_cached",0x390);
          pthread_mutex_unlock((pthread_mutex_t *)&DAT_0475f230);
        }
      }
      goto LAB_00b98ebc;
    }
    uVar3 = 0x37d;
  }
  fprintf(*(FILE **)PTR_stderr_010371f0,"[Func]:%s [Line]:%d [Info]:Null point \n",
          "hi_mpi_sys_mmz_alloc_cached",uVar3,param_5,0);
  uVar2 = 0xa0028006;
LAB_00b98ebc:
  if (local_8 == *(long *)PTR___stack_chk_guard_010398b8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}



/* FUNCTION imvt_nnie_model_load @ 00d32668 body=[[00d32668, 00d327e3] [00d327e8, 00d32847]]
REF Entry Point EXTERNAL caller=NONE
REF 00d31d18 UNCONDITIONAL_CALL caller=imvt_tracker_init@00d31bb0
*/

undefined8 imvt_nnie_model_load(char *param_1,long param_2)

{
  int iVar1;
  FILE *__stream;
  ulong __size;
  size_t sVar2;
  undefined8 local_10;
  void *pvStack_8;
  
  local_10 = 0;
  pvStack_8 = (void *)0x0;
  __stream = fopen(param_1,"rb");
  if (__stream == (FILE *)0x0) {
    imvt_printf(0,"[imvt_nnie] %s open nnie model failed!\n","imvt_nnie_model_load");
  }
  else {
    iVar1 = fseek(__stream,0,2);
    if (iVar1 != -1) {
      __size = ftell(__stream);
      if ((long)__size < 1) {
        imvt_printf(0,"[imvt_nnie] %s ftell failed!\n","imvt_nnie_model_load");
        return 0xffffffff;
      }
      iVar1 = fseek(__stream,0,0);
      if (iVar1 != -1) {
        iVar1 = HI_MPI_SYS_MmzAlloc(&local_10,&pvStack_8,"IMVT_NNIE_MODEL",0,__size & 0xffffffff);
        if (iVar1 == 0) {
          *(void **)(param_2 + 14000) = pvStack_8;
          *(undefined8 *)(param_2 + 0x36a8) = local_10;
          *(int *)(param_2 + 0x36b8) = (int)__size;
          sVar2 = fread(pvStack_8,__size,1,__stream);
          if ((int)sVar2 == 1) {
            iVar1 = HI_MPI_SVP_NNIE_LoadModel(param_2 + 0x36a8,param_2);
            if (iVar1 == 0) {
              fclose(__stream);
              return 0;
            }
            imvt_printf(0,"[imvt_nnie] %s HI_MPI_SVP_NNIE_LoadModel failed!\n",
                        "imvt_nnie_model_load");
          }
          else {
            imvt_printf(0,"[imvt_nnie] %s read model file failed!\n","imvt_nnie_model_load");
          }
          if ((*(long *)(param_2 + 0x36a8) != 0) && (*(long *)(param_2 + 14000) != 0)) {
            HI_MPI_SYS_MmzFree();
            *(undefined8 *)(param_2 + 0x36a8) = 0;
            *(undefined8 *)(param_2 + 14000) = 0;
          }
          *(undefined4 *)(param_2 + 0x36b8) = 0;
        }
        else {
          imvt_printf(0,"[imvt_nnie] %s Malloc memory failed! (%#x)\n","imvt_nnie_model_load",iVar1)
          ;
        }
        fclose(__stream);
        return 0xffffffff;
      }
    }
    imvt_printf(0,"[imvt_nnie] %s fseek failed!\n","imvt_nnie_model_load");
  }
  return 0xffffffff;
}



/* FUNCTION imvt_yolo2_init_c @ 00d33f5c body=[[00d33f5c, 00d33f8f]]
REF Entry Point EXTERNAL caller=NONE
REF 00f183d4 INDIRECTION caller=NONE
REF 00fdfd30 DATA caller=NONE
REF 00d31d04 UNCONDITIONAL_CALL caller=imvt_tracker_init@00d31bb0
*/

void imvt_yolo2_init_c(region_layer *param_1,void *param_2,int param_3,int param_4)

{
  imvt_yolo2_init(param_1,param_2,param_3,param_4);
  return;
}



/* FUNCTION imvt_nnie_param_init @ 00d328f8 body=[[00d328f8, 00d3292b] [00d32930, 00d32973]]
REF Entry Point EXTERNAL caller=NONE
REF 00d31d34 UNCONDITIONAL_CALL caller=imvt_tracker_init@00d31bb0
*/

undefined8 imvt_nnie_param_init(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_00d31f58();
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
    imvt_printf(0,"[imvt_nnie] imvt_nnie_param_deinit failed\n");
    iVar1 = imvt_nnie_param_deinit(param_2);
    if (iVar1 != 0) {
      imvt_printf(0,"[imvt_nnie] imvt_nnie_param_deinit failed\n");
      return 0xffffffff;
    }
  }
  return uVar2;
}



/* FUNCTION af_printf @ 00d41f20 body=[[00d41f20, 00d41fcf]]
REF Entry Point EXTERNAL caller=NONE
REF 00f18754 INDIRECTION caller=NONE
REF 00fe0ca0 DATA caller=NONE
REF 00d3df04 UNCONDITIONAL_CALL caller=n3a_af_caf_lose_human@00d3deb8
REF 00d3dfc4 UNCONDITIONAL_CALL caller=FUN_00d3df34@00d3df34
REF 00d40d24 UNCONDITIONAL_CALL caller=FUN_00d40c94@00d40c94
REF 00d3a1f8 UNCONDITIONAL_CALL caller=n3a_af_update@00d3a010
REF 00d3a25c UNCONDITIONAL_CALL caller=n3a_af_update@00d3a010
REF 00d3b1a4 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3b1e8 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3b300 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3b330 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3bb28 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3bd9c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c040 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c094 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c2a4 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c35c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c39c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c3f8 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c8c8 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c8dc UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3e558 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3e62c UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3e6fc UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3e72c UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3e920 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3ea44 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3ec24 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3ec4c UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3ed8c UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3edcc UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3f9a4 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3fb6c UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3fc2c UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3fc50 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3fcac UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3fd58 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3fda8 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3fe34 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3ed34 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40218 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40760 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3faf8 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d41728 UNCONDITIONAL_CALL caller=n3a_af_lum_parse@00d41608
REF 00d3a728 UNCONDITIONAL_CALL caller=FUN_00d3a650@00d3a650
REF 00d3a9e0 UNCONDITIONAL_CALL caller=FUN_00d3a770@00d3a770
REF 00d3ad90 UNCONDITIONAL_CALL caller=FUN_00d3ad00@00d3ad00
REF 00d3ada8 UNCONDITIONAL_CALL caller=FUN_00d3ad00@00d3ad00
REF 00d3e0b8 UNCONDITIONAL_CALL caller=FUN_00d3e000@00d3e000
REF 00d3b584 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3b778 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3b800 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3b838 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c244 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3cc0c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d180 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d794 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c49c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3ca3c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3cb8c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c654 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3cd58 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3ce24 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3ce5c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3ceb0 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d118 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d31c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d38c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d3e4 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d400 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d5a4 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d68c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d290 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d77c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d810 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3da10 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3da90 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3dad4 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3dae4 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3cd94 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3cf3c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d04c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d078 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d43c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d474 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d958 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d9a0 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3dab0 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3f1dc UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3f29c UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3f3dc UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40078 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3f47c UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3f4c0 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3f4e4 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3f5c0 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3f6d0 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3f6f8 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3fe98 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3ff98 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d400f8 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40194 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d401dc UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d407d0 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40838 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40978 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3f750 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d402fc UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40380 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40448 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40478 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40550 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d4059c UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d406f8 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40724 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
*/

int af_printf(char *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
             undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  int iVar1;
  undefined1 *local_100;
  undefined1 *puStack_f8;
  undefined1 *local_f0;
  undefined8 uStack_e8;
  undefined1 auStack_40 [8];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  undefined8 local_8;
  
  iVar1 = 0;
  if (DAT_0482d69c != 0) {
    local_f0 = auStack_40;
    uStack_e8 = 0xffffff80ffffffc8;
    local_100 = (undefined1 *)register0x00000008;
    puStack_f8 = (undefined1 *)register0x00000008;
    local_38 = param_2;
    uStack_30 = param_3;
    local_28 = param_4;
    uStack_20 = param_5;
    local_18 = param_6;
    uStack_10 = param_7;
    local_8 = param_8;
    iVar1 = vsnprintf(&DAT_0482d598,0x100,param_1,&local_100);
    printf("%s",&DAT_0482d598);
  }
  return iVar1;
}



/* FUNCTION n3a_af_get_fv2 @ 00d41590 body=[[00d41590, 00d4159b]]
REF Entry Point EXTERNAL caller=NONE
REF 00f186cc INDIRECTION caller=NONE
REF 00fe0a94 DATA caller=NONE
REF 00d3a0a4 UNCONDITIONAL_CALL caller=n3a_af_update@00d3a010
*/

undefined4 n3a_af_get_fv2(void)

{
  return DAT_0481a9b4;
}



/* FUNCTION n3a_af_caf_start @ 00d39fd0 body=[[00d39fd0, 00d3a003] [00d3a008, 00d3a00f]]
REF Entry Point EXTERNAL caller=NONE
REF 00f184d4 INDIRECTION caller=NONE
REF 00fe0174 DATA caller=NONE
REF 00d3a248 UNCONDITIONAL_CALL caller=n3a_af_update@00d3a010
REF 00888df0 UNCONDITIONAL_CALL caller=imvt_n3a_af_caf_start@00888dd8
*/

undefined8 n3a_af_caf_start(void)

{
  undefined8 uVar1;
  
  if ((DAT_047b5928 >> 1 & 1) == 0) {
    return 0xffffffff;
  }
  if (DAT_047b5954 != 0) {
    return 0;
  }
  DAT_047b5950 = 1;
  DAT_047b5954 = 1;
  uVar1 = n3a_af_caf_request(0x96,DAT_047b5944);
  return uVar1;
}



/* FUNCTION n3a_af_camera_is_moving @ 00d41d18 body=[[00d41d18, 00d41d23]]
REF Entry Point EXTERNAL caller=NONE
REF 00f1872c INDIRECTION caller=NONE
REF 00fe0c20 DATA caller=NONE
REF 00d3aea4 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
*/

undefined4 n3a_af_camera_is_moving(void)

{
  return DAT_0481bbc0;
}



/* FUNCTION n3a_af_luminance_is_changing @ 00d41d08 body=[[00d41d08, 00d41d13]]
REF Entry Point EXTERNAL caller=NONE
REF 00f18724 INDIRECTION caller=NONE
REF 00fe0c0c DATA caller=NONE
REF 00d3ae8c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
*/

undefined4 n3a_af_luminance_is_changing(void)

{
  return DAT_0481bbb8;
}



/* FUNCTION n3a_af_get_roi @ 00d41ed0 body=[[00d41ed0, 00d41efb]]
REF Entry Point EXTERNAL caller=NONE
REF 00f1873c INDIRECTION caller=NONE
REF 00fe0c64 DATA caller=NONE
REF 00d3dc60 UNCONDITIONAL_CALL caller=n3a_af_caf_request@00d3dc38
REF 00d3dc7c UNCONDITIONAL_CALL caller=n3a_af_caf_request@00d3dc38
REF 008888c4 UNCONDITIONAL_CALL caller=imvt_n3a_af_get_focus_point@00888850
REF 00d3af7c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3bec4 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3aa9c UNCONDITIONAL_CALL caller=FUN_00d3aa58@00d3aa58
REF 00d3a7c4 UNCONDITIONAL_CALL caller=FUN_00d3a770@00d3a770
REF 00d3b590 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3b5ac UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3b628 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3b634 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
*/

void n3a_af_get_roi(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = DAT_048205e8;
  *param_1 = DAT_048205e0;
  param_1[1] = uVar1;
  param_1[2] = DAT_048205f0;
  *(undefined4 *)(param_1 + 3) = DAT_048205f8;
  return;
}



/* FUNCTION n3a_af_get_ae_info @ 00d41758 body=[[00d41758, 00d41777]]
REF Entry Point EXTERNAL caller=NONE
REF 00f186fc INDIRECTION caller=NONE
REF 00fe0b34 DATA caller=NONE
REF 00d3dc8c UNCONDITIONAL_CALL caller=n3a_af_caf_request@00d3dc38
REF 00d3bb60 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
*/

undefined8 n3a_af_get_ae_info(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = DAT_04820604;
  *param_1 = DAT_048205fc;
  param_1[1] = uVar1;
  return 0;
}



/* FUNCTION FUN_00d3aa58 @ 00d3aa58 body=[[00d3aa58, 00d3ab03] [00d3ab08, 00d3accb] [00d3acd0, 00d3acff]]
REF 00f1859c INDIRECTION caller=NONE
REF 00fe04ec DATA caller=NONE
REF 00d3c144 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
*/

void FUN_00d3aa58(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined4 uVar7;
  undefined8 *puVar8;
  int *piVar9;
  undefined4 local_2038;
  undefined4 auStack_2034 [3];
  undefined8 local_2028;
  undefined8 uStack_2020;
  undefined8 local_2018;
  undefined4 local_2010;
  int local_2008;
  int iStack_2004;
  int local_1800 [1536];
  
  local_2028 = 0;
  uStack_2020 = 0;
  local_2018 = 0;
  local_2010 = 0;
  local_2038 = param_2;
  auStack_2034[0] = param_1;
  n3a_af_get_roi(&local_2028);
  memset(&local_2008,0,0x2008);
  n3a_af_get_fv_info(&local_2008);
  pcVar4 = (char *)n3a_af_get_fv_weight_table();
  if (0 < local_2008 * iStack_2004) {
    piVar9 = local_1800;
    puVar8 = (undefined8 *)&DAT_047b8194;
    do {
      while (iVar1 = DAT_04817cf8, *pcVar4 != '\0') {
        if (*(int *)(puVar8 + 0x5f) == 0) {
          iVar3 = *piVar9;
          *(int *)(puVar8 + 2) = DAT_04817cf8;
          uVar7 = DAT_048179e0;
          *(undefined4 *)puVar8 = DAT_048179e0;
          *(int *)((long)puVar8 + 4) = iVar3;
          *(undefined4 *)(puVar8 + 1) = uVar7;
          *(int *)((long)puVar8 + 0xc) = iVar3;
          *(int *)((long)puVar8 + 0x14) = iVar3;
          *(undefined4 *)(puVar8 + 3) = uVar7;
          if (param_3 == -1) {
            puVar2 = &local_2038;
            if (iVar1 == DAT_047b7e4c) {
              puVar2 = auStack_2034;
            }
            *(undefined4 *)((long)puVar8 + 0x1c) = *puVar2;
          }
          else {
            *(int *)((long)puVar8 + 0x1c) = param_3;
          }
          puVar8[6] = local_2028;
          puVar8[7] = uStack_2020;
          *(undefined4 *)(puVar8 + 4) = 0;
          *(undefined4 *)((long)puVar8 + 0x24) = 0;
          *(undefined4 *)(puVar8 + 5) = 0;
          *(undefined4 *)((long)puVar8 + 0x2c) = 0;
          puVar8[8] = local_2018;
          *(undefined4 *)(puVar8 + 9) = local_2010;
          *(undefined4 *)(puVar8 + 0x5f) = 1;
          break;
        }
        iVar1 = *piVar9;
        if (*(int *)((long)puVar8 + 0x14) < iVar1) {
          *(int *)((long)puVar8 + 0x14) = iVar1;
          uVar7 = DAT_048179e0;
          *(undefined4 *)(puVar8 + 3) = DAT_048179e0;
          *(int *)(puVar8 + 4) = *(int *)(puVar8 + 4) + 1;
          *(undefined4 *)((long)puVar8 + 0x24) = 0;
        }
        else {
          *(int *)((long)puVar8 + 0x24) = *(int *)((long)puVar8 + 0x24) + 1;
          uVar7 = DAT_048179e0;
        }
        *(undefined4 *)(puVar8 + 1) = uVar7;
        *(int *)((long)puVar8 + 0xc) = iVar1;
        *(int *)(puVar8 + 5) = *(int *)(puVar8 + 5) + 1;
        iVar3 = memcmp(&local_2028,puVar8 + 6,0x1c);
        if (iVar3 != 0) {
          *(int *)((long)puVar8 + 0x2c) = *(int *)((long)puVar8 + 0x2c) + 1;
        }
        if (DAT_04817cf8 == DAT_04817cfc) break;
        puVar5 = (undefined8 *)((long)puVar8 + 0x2ac);
        do {
          puVar6 = (undefined8 *)((long)puVar5 + -0x4c);
          *puVar5 = *puVar6;
          puVar5[1] = *(undefined8 *)((long)puVar5 + -0x44);
          puVar5[2] = *(undefined8 *)((long)puVar5 + -0x3c);
          puVar5[3] = *(undefined8 *)((long)puVar5 + -0x34);
          puVar5[4] = *(undefined8 *)((long)puVar5 + -0x2c);
          puVar5[5] = *(undefined8 *)((long)puVar5 + -0x24);
          puVar5[8] = *(undefined8 *)((long)puVar5 + -0xc);
          puVar5[6] = *(undefined8 *)((long)puVar5 + -0x1c);
          puVar5[7] = *(undefined8 *)((long)puVar5 + -0x14);
          *(undefined4 *)(puVar5 + 9) = *(undefined4 *)((long)puVar5 + -4);
          puVar5 = puVar6;
        } while (puVar6 != puVar8);
        *(int *)(puVar8 + 0x5f) = *(int *)(puVar8 + 0x5f) + 1;
        iVar3 = DAT_04817cf8;
        *(int *)(puVar8 + 2) = DAT_04817cf8;
        uVar7 = DAT_048179e0;
        *(undefined4 *)puVar8 = DAT_048179e0;
        *(int *)((long)puVar8 + 4) = iVar1;
        *(undefined4 *)(puVar8 + 1) = uVar7;
        *(int *)((long)puVar8 + 0xc) = iVar1;
        *(int *)((long)puVar8 + 0x14) = iVar1;
        *(undefined4 *)(puVar8 + 3) = uVar7;
        if (param_3 == -1) {
          puVar2 = &local_2038;
          if (iVar3 == DAT_047b7e4c) {
            puVar2 = auStack_2034;
          }
          *(undefined4 *)((long)puVar8 + 0x1c) = *puVar2;
        }
        else {
          *(int *)((long)puVar8 + 0x1c) = param_3;
        }
        *(undefined4 *)(puVar8 + 4) = 0;
        *(undefined4 *)((long)puVar8 + 0x24) = 0;
        pcVar4 = pcVar4 + 1;
        piVar9 = piVar9 + 1;
        *(undefined4 *)(puVar8 + 5) = 0;
        puVar8[6] = local_2028;
        puVar8[7] = uStack_2020;
        puVar8[8] = local_2018;
        *(undefined4 *)(puVar8 + 9) = local_2010;
        *(undefined4 *)((long)puVar8 + 0x2c) = 0;
        puVar8 = (undefined8 *)((long)puVar8 + 0x2fc);
        if ((undefined8 *)(&DAT_047b8490 + (ulong)(local_2008 * iStack_2004 - 1) * 0xbf) == puVar8)
        {
          return;
        }
      }
      puVar8 = (undefined8 *)((long)puVar8 + 0x2fc);
      pcVar4 = pcVar4 + 1;
      piVar9 = piVar9 + 1;
    } while ((undefined8 *)(&DAT_047b8490 + (ulong)(local_2008 * iStack_2004 - 1) * 0xbf) != puVar8)
    ;
  }
  return;
}



/* FUNCTION n3a_af_get_fv_info @ 00d415a0 body=[[00d415a0, 00d415b7]]
REF Entry Point EXTERNAL caller=NONE
REF 00f186d4 INDIRECTION caller=NONE
REF 00fe0aa8 DATA caller=NONE
REF 00d3dce8 UNCONDITIONAL_CALL caller=n3a_af_caf_request@00d3dc38
REF 00d3aab4 UNCONDITIONAL_CALL caller=FUN_00d3aa58@00d3aa58
REF 00d3a82c UNCONDITIONAL_CALL caller=FUN_00d3a770@00d3a770
REF 00d3cdb0 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d458 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
*/

void n3a_af_get_fv_info(void *param_1)

{
  memcpy(param_1,&DAT_0482060c,0x2008);
  return;
}



/* FUNCTION FUN_00d3ad00 @ 00d3ad00 body=[[00d3ad00, 00d3ad7b] [00d3ad80, 00d3ad9b] [00d3ada0, 00d3adb3]]
REF 00f185a4 INDIRECTION caller=NONE
REF 00fe0550 DATA caller=NONE
REF 00d3cae4 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d880 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
*/

undefined8 FUN_00d3ad00(void)

{
  undefined8 uVar1;
  
  if (DAT_04817d1c != 1) {
    return 1;
  }
  if (((DAT_048179a4 != 3) && (DAT_04817cb0 != 1)) && (DAT_04817cb4 != 1)) {
    return 1;
  }
  uVar1 = 1;
  if (DAT_04817cf8 < 1) {
    if (DAT_047b7eb4 < DAT_048179e0) {
      af_printf("@@@@@@@@@@@@@@@@@@@@@@@@not need switch %d!!!!\n");
      uVar1 = 0;
    }
  }
  else if (DAT_048179e0 < DAT_047b7eb4) {
    af_printf("@@@@@@@@@@@@@@@@@@@@@@@not need switch!!!! %d\n");
    uVar1 = 0;
  }
  return uVar1;
}



/* FUNCTION FUN_00d3a608 @ 00d3a608 body=[[00d3a608, 00d3a64f]]
REF 00f18584 INDIRECTION caller=NONE
REF 00fe0440 DATA caller=NONE
REF 00d3dc84 UNCONDITIONAL_CALL caller=n3a_af_caf_request@00d3dc38
REF 00d3b554 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3b5f0 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3b88c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c26c UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d1b8 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d278 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
*/

void FUN_00d3a608(void)

{
  memset(&DAT_047b7e98,0,0x2fc);
  memset(&DAT_047b8194,0,0x5f800);
  return;
}



/* FUNCTION FUN_00d3a770 @ 00d3a770 body=[[00d3a770, 00d3aa3f]]
REF 00f18594 INDIRECTION caller=NONE
REF 00fe04a0 DATA caller=NONE
REF 00d3b6cc UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3b8d8 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
*/

undefined4 FUN_00d3a770(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  float fVar15;
  undefined8 local_2028;
  undefined8 uStack_2020;
  undefined8 local_2018;
  undefined4 local_2010;
  int local_2008;
  int iStack_2004;
  int local_1800 [1024];
  int local_800 [512];
  
  memset(&local_2008,0,0x2008);
  local_2018 = 0;
  local_2010 = 0;
  local_2028 = 0;
  uStack_2020 = 0;
  n3a_af_get_roi(&local_2028);
  DAT_04817994 = 0;
  DAT_04817998 = 0;
  DAT_0481799c = 0;
  DAT_048179a0 = 0;
  if ((DAT_047b81c0 == 0) && (iVar7 = memcmp(&local_2028,&DAT_047b81c4,0x1c), iVar7 == 0)) {
    n3a_af_get_fv_info(&local_2008);
    uVar14 = 0;
    if ((2 < DAT_047b81bc) && (local_2008 = local_2008 * iStack_2004, 0 < local_2008)) {
      piVar9 = local_1800;
      piVar8 = &DAT_047b81a8;
      bVar6 = false;
      bVar5 = false;
      bVar4 = false;
      iVar10 = 0;
      iVar11 = 0;
      iVar7 = DAT_04817994;
      iVar13 = DAT_04817998;
      iVar12 = DAT_0481799c;
      do {
        iVar2 = piVar9[0x400];
        if (3 < local_2008 && iVar2 != 0) goto LAB_00d3a970;
        iVar1 = piVar8[4];
        iVar3 = *piVar8;
        if ((piVar8[3] < 2) || (0 < iVar1)) {
          if ((1 < iVar1) && (*piVar9 < iVar3)) {
            iVar7 = iVar7 + 1;
            bVar5 = true;
          }
          if (iVar3 < 0x51) goto LAB_00d3a9fc;
          if (1 < piVar8[3]) goto LAB_00d3a8f8;
LAB_00d3a918:
          if (iVar3 < 0x15e) {
            if (iVar2 == 0) {
              fVar15 = 0.25;
              if (99 < iVar3) goto LAB_00d3a93c;
              goto LAB_00d3a940;
            }
          }
          else {
            fVar15 = DAT_00d3aa48;
            if ((299 < iVar3 - 700U) && (fVar15 = DAT_00d3aa40, iVar3 < 1000)) {
              fVar15 = DAT_00d3aa44;
            }
            if (iVar2 == 0) {
LAB_00d3a93c:
              iVar10 = iVar10 + 1;
              goto LAB_00d3a940;
            }
          }
        }
        else {
          if (iVar3 <= *piVar9) {
            iVar13 = iVar13 + 1;
            bVar4 = true;
          }
          if (0x50 < iVar3) {
LAB_00d3a8f8:
            if ((1 < iVar1) && (0x23 < iVar3 - *piVar9)) {
              iVar12 = iVar12 + 1;
              bVar6 = true;
            }
            goto LAB_00d3a918;
          }
LAB_00d3a9fc:
          if (iVar2 != 0) goto LAB_00d3a970;
          fVar15 = 0.25;
LAB_00d3a940:
          if (((100 < iVar3 && 1 < iVar1) && (*piVar9 < iVar3)) &&
             ((int)((float)iVar3 * fVar15) <= iVar3 - *piVar9)) {
            iVar11 = iVar11 + 1;
          }
        }
LAB_00d3a970:
        piVar8 = piVar8 + 0xbf;
        piVar9 = piVar9 + 1;
      } while (&DAT_047b84a4 + (ulong)(local_2008 - 1) * 0xbf != piVar8);
      if (bVar4) {
        DAT_04817998 = iVar13;
      }
      if (bVar5) {
        DAT_04817994 = iVar7;
      }
      if (bVar6) {
        DAT_0481799c = iVar12;
      }
      if (DAT_00d3aa50 <= (double)((float)iVar11 / (float)iVar10) && 9 < iVar10) {
        uVar14 = 1;
        DAT_048179a0 = 1;
        af_printf("most point is down hill!!!!\n");
      }
    }
  }
  else {
    uVar14 = 0;
    DAT_0481799c = 1;
  }
  return uVar14;
}



/* FUNCTION n3a_af_caf_cancel_focus @ 00d3adb8 body=[[00d3adb8, 00d3adc7]]
REF Entry Point EXTERNAL caller=NONE
REF 00f185ac INDIRECTION caller=NONE
REF 00fe0574 DATA caller=NONE
REF 00d3c8cc UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3c8e0 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00889078 UNCONDITIONAL_CALL caller=imvt_n3a_af_caf_cancel_focus@00889060
REF 00d3a43c UNCONDITIONAL_CALL caller=n3a_af_set_mf_status@00d3a410
*/

void n3a_af_caf_cancel_focus(void)

{
  DAT_04817d28 = 1;
  return;
}



/* FUNCTION n3a_af_fv_get_tiles_num @ 00d41ce8 body=[[00d41ce8, 00d41d03]]
REF Entry Point EXTERNAL caller=NONE
REF 00f1871c INDIRECTION caller=NONE
REF 00fe0bf8 DATA caller=NONE
REF 00d3af14 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
*/

int n3a_af_fv_get_tiles_num(void)

{
  return DAT_048205f8 * DAT_048205f0._4_4_;
}



/* FUNCTION FUN_00d3a650 @ 00d3a650 body=[[00d3a650, 00d3a71b] [00d3a720, 00d3a763]]
REF 00f1858c INDIRECTION caller=NONE
REF 00fe0468 DATA caller=NONE
REF 00d3c630 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d0d8 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d320 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
REF 00d3d690 UNCONDITIONAL_CALL caller=n3a_af_caf_task_run@00d3adc8
*/

int FUN_00d3a650(void)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  iVar1 = DAT_047b7ebc;
  if (9 < DAT_047b7ebc) {
    iVar1 = 9;
  }
  dVar3 = (double)DAT_04817d00 * DAT_00d3a768;
  if ((0x45 < DAT_048179b0) || ((float)DAT_04817a90 / (float)DAT_04817a88 < 2.0)) {
    DAT_04817cc8 = DAT_047b7eac;
    DAT_04817ccc = DAT_047b7eb0;
  }
  else {
    af_printf("@@@@@@@@@@image_is_low_freq!!!!!!!!!!!!!!\n");
    DAT_04817cd8 = 1;
    DAT_04817ccc = (&DAT_047b5990)[(long)iVar1 + 0x18814];
    DAT_04817cc8 = (&DAT_04817a90)[(long)iVar1 * 0xc];
  }
  DAT_04817ce4 = (float)(int)dVar3;
  iVar2 = DAT_04817ccc - DAT_048179e0;
  DAT_04817cd0 = -iVar2;
  if (-1 < iVar2) {
    DAT_04817cd0 = iVar2;
  }
  n3a_af_fv_set_down_hill_focus_point(iVar1,0);
  return (int)dVar3;
}



/* FUNCTION FUN_00d3e1b0 @ 00d3e1b0 body=[[00d3e1b0, 00d3e24b] [00d3e250, 00d3e26f]]
REF 00f18634 INDIRECTION caller=NONE
REF 00fe07d8 DATA caller=NONE
REF 00d3ece8 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3f76c UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d406fc UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
*/

ulong FUN_00d3e1b0(void)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = (**(code **)(DAT_04817d78 + 0x20))();
  if ((int)uVar2 == 0) {
    if (*(int *)(DAT_04817d78 + 0xb8) == 1) {
      if (((DAT_04818e88 == DAT_04818e8c) && (DAT_04818e88 == DAT_04818e90)) &&
         (DAT_048194d0 == DAT_048194d4)) {
        uVar2 = (ulong)(DAT_04817dfc == DAT_048194d0);
      }
    }
    else if ((DAT_04818e88 == DAT_04818e8c) && (DAT_04818e88 == DAT_04818e90)) {
      iVar1 = (**(code **)(DAT_04817d78 + 0x10))();
      uVar2 = (ulong)(iVar1 != 0);
    }
    return uVar2;
  }
  return 1;
}



/* FUNCTION FUN_00d3e0f0 @ 00d3e0f0 body=[[00d3e0f0, 00d3e18b] [00d3e190, 00d3e1af]]
REF 00f1862c INDIRECTION caller=NONE
REF 00fe07a4 DATA caller=NONE
REF 00d3ea50 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d3fb10 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40730 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
*/

ulong FUN_00d3e0f0(void)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = (**(code **)(DAT_04817d78 + 0x18))();
  if ((int)uVar2 == 0) {
    if (*(int *)(DAT_04817d78 + 0xb8) == 1) {
      if (((DAT_04818e88 == DAT_04818e8c) && (DAT_04818e88 == DAT_04818e90)) &&
         (DAT_048194d0 == DAT_048194d4)) {
        uVar2 = (ulong)(DAT_04817df8 == DAT_048194d0);
      }
    }
    else if ((DAT_04818e88 == DAT_04818e8c) && (DAT_04818e88 == DAT_04818e90)) {
      iVar1 = (**(code **)(DAT_04817d78 + 8))();
      uVar2 = (ulong)(iVar1 != 0);
    }
    return uVar2;
  }
  return 1;
}



/* FUNCTION FUN_00d3e000 @ 00d3e000 body=[[00d3e000, 00d3e0e7]]
REF 00f18624 INDIRECTION caller=NONE
REF 00fe0770 DATA caller=NONE
REF 00d40184 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d401bc UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
REF 00d40818 UNCONDITIONAL_CALL caller=n3a_af_saf_task_run@00d3e270
*/

int FUN_00d3e000(void)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  iVar1 = DAT_04819680;
  if (0x4f < DAT_04819680) {
    iVar1 = 0x4f;
  }
  dVar3 = (double)DAT_0481a2e0 * DAT_00d3e0e8;
  if ((0x45 < DAT_04817e3c) || ((float)DAT_04817f98 / (float)(int)DAT_04817f90 < 2.0)) {
    DAT_0481962c = DAT_04819670;
    DAT_04819630 = DAT_04819674;
  }
  else {
    af_printf("@@@@@@@@@@image_is_low_freq!!!!!!!!!!!!!!\n");
    DAT_0481a934 = 1;
    DAT_04819630 = (&DAT_04818e88)[iVar1];
    DAT_0481962c = (&DAT_04817f98)[(long)iVar1 * 0xc];
  }
  iVar2 = DAT_04819630 - DAT_04818e88;
  DAT_0481a938 = -iVar2;
  if (-1 < iVar2) {
    DAT_0481a938 = iVar2;
  }
  n3a_af_fv_set_down_hill_focus_point(iVar1,0);
  return (int)dVar3;
}



/* FUNCTION n3a_af_caf_is_doing_focus @ 00d3dbf0 body=[[00d3dbf0, 00d3dc03]]
REF Entry Point EXTERNAL caller=NONE
REF 00f185d4 INDIRECTION caller=NONE
REF 00fe0638 DATA caller=NONE
REF 00d412cc UNCONDITIONAL_CALL caller=n3a_af_parse_fv@00d41110
REF 00d41530 UNCONDITIONAL_CALL caller=n3a_af_parse_fv@00d41110
REF 00d3a474 UNCONDITIONAL_CALL caller=n3a_af_is_doing_focus@00d3a448
*/

bool n3a_af_caf_is_doing_focus(void)

{
  return DAT_048179a4 != 0;
}



/* FUNCTION n3a_af_is_caf_on @ 00d3a3f0 body=[[00d3a3f0, 00d3a3ff]]
REF Entry Point EXTERNAL caller=NONE
REF 00f1850c INDIRECTION caller=NONE
REF 00fe0268 DATA caller=NONE
REF 00d3a460 UNCONDITIONAL_CALL caller=n3a_af_is_doing_focus@00d3a448
REF 00d3a428 UNCONDITIONAL_CALL caller=n3a_af_set_mf_status@00d3a410
REF 008890b0 UNCONDITIONAL_CALL caller=imvt_n3a_af_lock@00889088
REF 00d412e8 UNCONDITIONAL_CALL caller=n3a_af_parse_fv@00d41110
REF 00888da8 UNCONDITIONAL_CALL caller=imvt_n3a_af_is_caf_on@00888d90
REF 00887f78 UNCONDITIONAL_CALL caller=NONE
*/

uint n3a_af_is_caf_on(void)

{
  return DAT_047b5928 >> 1 & 1;
}



