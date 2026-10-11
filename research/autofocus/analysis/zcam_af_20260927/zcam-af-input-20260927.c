/* FUNCTION imvt_af_init @ 007308c0 body=[[007308c0, 00730917]]
REF Entry Point EXTERNAL caller=NONE
REF 00efd83c INDIRECTION caller=NONE
REF 00f4ea50 DATA caller=NONE
REF 006ea138 UNCONDITIONAL_CALL caller=imvt_cam_controller_init@006e98e0
*/

uint imvt_af_init(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar1 = imvt_lens_controller_get_lens_type();
  imvt_cam_adj_register_af_params();
  if ((iVar1 != 0) && (uVar4 = 3, iVar1 == 1)) {
    uVar4 = 1;
  }
  uVar2 = imvt_isp_af_init();
  uVar3 = imvt_n3a_af_init(uVar4);
  if ((uVar2 | uVar3) == 0) {
    imvt_isp_af_start();
  }
  return uVar2 | uVar3;
}



/* FUNCTION FUN_007e9010 @ 007e9010 body=[[007e9010, 007e90b3] [007e90b8, 007e929b] [007e92a0, 007e930b] [007e9310, 007e931b] [007e9320, 007e932b] [007e9330, 007e933b] [007e9340, 007e9387]]
REF 00f00f7c INDIRECTION caller=NONE
REF 00f63e04 DATA caller=NONE
REF 007e9a90 UNCONDITIONAL_CALL caller=FUN_007e9a50@007e9a50
*/

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007e9010(long param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int *piVar7;
  undefined2 *puVar8;
  float fVar9;
  undefined8 local_288;
  short local_280;
  undefined2 local_27e;
  undefined2 local_27c;
  int local_278 [5];
  int aiStack_264 [71];
  undefined1 auStack_148 [8];
  short local_140;
  undefined2 local_134 [150];
  long local_8;
  
  DAT_045464c4 = DAT_045464c4 + 1;
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  if (DAT_045461f0 == 0) goto LAB_007e905c;
  pthread_mutex_lock((pthread_mutex_t *)&DAT_045464d8);
  DAT_04546508 = 1;
  if (DAT_045461fa == 0) {
    DAT_04546508 = 0;
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_045464d8);
    goto LAB_007e905c;
  }
  iVar6 = imvt_tracker_run(param_1,DAT_0454620c,DAT_04546210,&DAT_04546214);
  DAT_04546508 = 0;
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_045464d8);
  if (iVar6 != 0) goto LAB_007e905c;
  if (DAT_045464c0 != 0) {
    imvt_printf((double)DAT_0454623c,3,"[nnie] detect num:%d search:%d final_thresh:%f\n",
                _DAT_04546234,DAT_04546238);
  }
  iVar6 = (int)DAT_04546234;
  local_280 = DAT_04546234;
  if (DAT_04546234 < 0xb) {
    local_288 = *(undefined8 *)(param_1 + 0xf0);
    local_27e = (undefined2)DAT_0454620c;
    local_27c = (undefined2)DAT_04546210;
    if (0 < DAT_04546234) goto LAB_007e9120;
  }
  else {
    imvt_printf(1,"[nnie] no enough buffer. max:%d, num:%d\n",10);
    local_288 = *(undefined8 *)(param_1 + 0xf0);
    iVar6 = 10;
    local_280 = 10;
    local_27e = (undefined2)DAT_0454620c;
    local_27c = (undefined2)DAT_04546210;
LAB_007e9120:
    puVar8 = &DAT_04546240;
    piVar7 = local_278;
    do {
      fVar9 = *(float *)(puVar8 + 6);
      sVar4 = puVar8[3];
      uVar1 = *puVar8;
      *(short *)(piVar7 + 4) = sVar4;
      uVar2 = puVar8[1];
      uVar3 = puVar8[2];
      sVar5 = puVar8[4];
      *(undefined2 *)(piVar7 + 1) = 0;
      *(undefined2 *)((long)piVar7 + 6) = 0xffff;
      *(undefined2 *)(piVar7 + 2) = uVar1;
      *(undefined2 *)(piVar7 + 3) = uVar2;
      *(undefined2 *)((long)piVar7 + 0xe) = uVar3;
      *(short *)((long)piVar7 + 0x12) = sVar5;
      *piVar7 = DAT_045464c4;
      *(short *)((long)piVar7 + 10) = (short)(int)(fVar9 * DAT_007e9388);
      if (DAT_0454620c < sVar4) {
        *(undefined2 *)(piVar7 + 4) = local_27e;
      }
      if (sVar5 != DAT_04546210 && DAT_04546210 <= sVar5) {
        *(undefined2 *)((long)piVar7 + 0x12) = local_27c;
      }
      piVar7 = piVar7 + 5;
      puVar8 = puVar8 + 8;
    } while (piVar7 != aiStack_264 + (ulong)(iVar6 - 1) * 5);
  }
  if (DAT_045461f2 != 0) {
    imvt_nnie_ptz_handle_detection(&local_288);
  }
  if (DAT_045461f4 != 0) {
    imvt_nnie_crop_handle_detection(&local_288);
  }
  imvt_tracking_process(param_1,DAT_04546200,&local_288,auStack_148);
  if (DAT_045461f6 != 0) {
    imvt_nnie_af_update_af_and_face(auStack_148);
  }
  if (DAT_04546204 != 0) {
    iVar6 = (int)local_280;
    if (0 < local_140) {
      if (local_280 < 0xf) {
        puVar8 = local_134;
        piVar7 = local_278 + (long)(int)local_280 * 5;
        do {
          iVar6 = iVar6 + 1;
          uVar1 = *puVar8;
          *(undefined2 *)((long)piVar7 + 6) = puVar8[1];
          uVar2 = puVar8[2];
          *(undefined2 *)((long)piVar7 + 10) = puVar8[3];
          uVar3 = puVar8[5];
          *(undefined2 *)(piVar7 + 1) = uVar1;
          *(undefined2 *)(piVar7 + 2) = uVar2;
          uVar1 = puVar8[4];
          uVar2 = puVar8[6];
          *(undefined2 *)((long)piVar7 + 0xe) = uVar3;
          uVar3 = puVar8[7];
          *(undefined2 *)(piVar7 + 3) = uVar1;
          *(undefined2 *)(piVar7 + 4) = uVar2;
          *(undefined2 *)((long)piVar7 + 0x12) = uVar3;
          *piVar7 = 0;
          if (iVar6 == (int)local_280 + (int)local_140) {
            local_280 = (short)iVar6;
            goto LAB_007e920c;
          }
          piVar7 = piVar7 + 5;
          puVar8 = puVar8 + 10;
        } while (iVar6 != 0xf);
      }
      imvt_printf(1,"[nnie] %s imvt_nnie_result buffer overflow\n","_append_nnie_result");
      local_280 = 0xe;
    }
  }
LAB_007e920c:
  if (DAT_04546510 != (code *)0x0) {
    (*DAT_04546510)(0xb000000,&local_288);
  }
LAB_007e905c:
  if (local_8 != *(long *)PTR___stack_chk_guard_010398b8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* FUNCTION FUN_007e9a50 @ 007e9a50 body=[[007e9a50, 007e9aab] [007e9ab0, 007e9b77]]
REF 00f00fac INDIRECTION caller=NONE
REF 00f63f50 DATA caller=NONE
REF 007e9914 DATA caller=imvt_nnie_init@007e9850
REF 007e98f4 PARAM caller=imvt_nnie_init@007e9850
*/

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007e9a50(void)

{
  int iVar1;
  undefined8 uVar2;
  
  if (_DAT_045461f8 == 1) {
    DAT_045461fa = 0;
    DAT_045461f8 = 2;
    uVar2 = imvt_tracker_init("/tmp/storage/app_data/nnie/zcam_ai_tracker.wk");
    if ((int)uVar2 != 0) {
      imvt_printf(0,"[nnie] imvt_tracker_init load model FAILED\n");
      _DAT_045461f8 = CONCAT22(DAT_045461fa,4);
                    /* WARNING: Could not recover jumptable at 0x007e9b74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_04546510)(0xb000005,0);
      return;
    }
    imvt_tracker_ctrl(uVar2,1000);
    imvt_printf(2,"[nnie] imvt_tracker_init load model OK\n");
    _DAT_045461f8 = CONCAT22(DAT_045461fa,3);
    (*DAT_04546510)(0xb000004,0);
    _DAT_045461f8 = CONCAT22(1,DAT_045461f8);
    iVar1 = _wait_and_lock_vgs_frame();
  }
  else {
    iVar1 = _wait_and_lock_vgs_frame();
  }
  if (-1 < iVar1) {
    FUN_007e9010(&DAT_045466f8 + (long)iVar1 * 0xbe);
    if (DAT_04546518 == 0) {
      FUN_007e9390(iVar1,0);
      return;
    }
    return;
  }
  imvt_printf(1,"[nnie] no more vgs frame\n");
  return;
}



/* FUNCTION imvt_nnie_enable_af_roi @ 007ea010 body=[[007ea010, 007ea01f]]
REF Entry Point EXTERNAL caller=NONE
REF 00f00fec INDIRECTION caller=NONE
REF 00f640c0 DATA caller=NONE
REF 00730b50 UNCONDITIONAL_CALL caller=imvt_af_set_mode@00730af8
REF 00730b6c UNCONDITIONAL_CALL caller=imvt_af_set_mode@00730af8
REF 006fef28 UNCONDITIONAL_CALL caller=FUN_006fe728@006fe728
REF 00810398 UNCONDITIONAL_CALL caller=FUN_00810378@00810378
*/

undefined8 imvt_nnie_enable_af_roi(undefined2 param_1)

{
  DAT_045461f6 = param_1;
  return 0;
}



/* FUNCTION FUN_00885288 @ 00885288 body=[[00885288, 008852b3]]
*/

undefined8 FUN_00885288(ulong param_1)

{
  printf("Illegal handle id %d in %s!\n",param_1 & 0xffffffff,"imvt_isp_ae_exit");
  return 0xffffffff;
}



/* FUNCTION FUN_008852b8 @ 008852b8 body=[[008852b8, 00885313]]
REF 008856d8 DATA caller=imvt_isp_ae_register@00885668
REF 008856b4 PARAM caller=imvt_isp_ae_register@00885668
*/

undefined8 FUN_008852b8(uint param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_1 < 4) {
    uVar1 = 0;
    if (param_2 == 0) {
      printf("Null Pointer in %s!\n","imvt_isp_ae_init");
      uVar1 = 0xffffffff;
    }
  }
  else {
    printf("Illegal handle id %d in %s!\n",(ulong)param_1,"imvt_isp_ae_init");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* FUNCTION FUN_00885330 @ 00885330 body=[[00885330, 00885643]]
REF 008856d8 DATA caller=imvt_isp_ae_register@00885668
REF 008856bc PARAM caller=imvt_isp_ae_register@00885668
*/

undefined8 FUN_00885330(uint param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  short sVar7;
  ushort uVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  float fVar12;
  undefined *puVar13;
  undefined4 uVar14;
  uint uVar15;
  int iVar16;
  undefined4 *puVar17;
  undefined8 uVar18;
  undefined2 *puVar19;
  uint *puVar20;
  float *pfVar21;
  undefined4 *puVar22;
  undefined4 *puVar23;
  ushort *puVar24;
  ushort *puVar25;
  long lVar26;
  float fVar27;
  
  if (param_1 < 4) {
    if ((param_2 == (undefined4 *)0x0) || (param_3 == (void *)0x0)) {
      printf("Null Pointer in %s!\n","imvt_isp_ae_run");
      uVar18 = 0xffffffff;
    }
    else {
      lVar26 = (long)(int)param_1;
      *(undefined4 *)(PTR_g_imvt_isp_ae_context_010348b0 + lVar26 * 0xb20 + 0x28) = *param_2;
      puVar17 = (undefined4 *)imvt_n3a_ae_get();
      dVar9 = DAT_00885648;
      if (puVar17 == (undefined4 *)0x0) {
        return 0;
      }
      *puVar17 = *param_2;
      dVar10 = DAT_00885650;
      *(undefined2 *)(puVar17 + 3) = 0;
      *(undefined2 *)((long)puVar17 + 0xe) = 0;
      *(undefined2 *)(puVar17 + 4) = 1;
      *(undefined2 *)((long)puVar17 + 0x12) = 1;
      *(undefined2 *)((long)puVar17 + 0x16) = 0;
      *(undefined2 *)(puVar17 + 5) = 0;
      dVar11 = DAT_00885658;
      puVar25 = *(ushort **)(param_2 + 0x14);
      *(undefined2 *)(puVar17 + 2) = 0x11;
      *(undefined2 *)((long)puVar17 + 10) = 0xf;
      puVar22 = puVar17 + 6;
      do {
        puVar2 = (undefined4 *)((long)puVar22 + 0x66);
        puVar24 = puVar25;
        do {
          *(undefined2 *)(puVar22 + 1) = 0;
          *(undefined2 *)((long)puVar22 + 2) = 0;
          puVar23 = (undefined4 *)((long)puVar22 + 6);
          *(short *)puVar22 =
               (short)(int)((double)(puVar24[1] >> 2) * dVar9 + dVar10 * (double)(*puVar24 >> 2) +
                           dVar11 * (double)(puVar24[3] >> 2));
          puVar22 = puVar23;
          puVar24 = puVar24 + 4;
        } while (puVar2 != puVar23);
        puVar25 = puVar25 + 0x44;
        puVar22 = puVar2;
      } while (puVar2 != (undefined4 *)((long)puVar17 + 0x612));
      puVar19 = *(undefined2 **)(param_2 + 0x12);
      uVar4 = *puVar19;
      *(undefined2 *)((long)puVar17 + 0x622) = puVar19[1];
      uVar5 = puVar19[2];
      uVar6 = puVar19[3];
      *(undefined2 *)(puVar17 + 0x188) = uVar4;
      *(undefined2 *)(puVar17 + 0x189) = uVar5;
      *(undefined2 *)((long)puVar17 + 0x626) = uVar6;
      *(undefined8 *)(puVar17 + 0x186) = 0;
      imvt_n3a_ae_run((ulong)param_1);
      puVar3 = PTR_g_imvt_isp_ae_context_010348b0;
      fVar12 = DAT_00885660;
      sVar7 = *(short *)(puVar17 + 0x197);
      fVar27 = (float)puVar17[0x18a] * DAT_00885660;
      *(undefined4 *)(PTR_g_imvt_isp_ae_context_010348b0 + lVar26 * 0xb20 + 0xd4) = 0x100;
      *(undefined4 *)(puVar3 + lVar26 * 0xb20 + 0xd8) = 0x100;
      *(undefined4 *)(puVar3 + lVar26 * 0xb20 + 0xdc) = 0x100;
      *(undefined4 *)(puVar3 + lVar26 * 0xb20 + 0xe0) = 0x100;
      uVar15 = (uint)fVar27;
      *(uint *)(puVar3 + lVar26 * 0xb20 + 0x90) = uVar15;
      *(uint *)(puVar3 + lVar26 * 0xb20 + 0x94) = uVar15;
      *(uint *)(puVar3 + lVar26 * 0xb20 + 0x98) = uVar15;
      *(uint *)(puVar3 + lVar26 * 0xb20 + 0x9c) = uVar15;
      if (sVar7 == 1) {
        uVar8 = *(ushort *)((long)puVar17 + 0x65e);
        pfVar21 = (float *)(puVar17 + 0x198);
        puVar20 = (uint *)(puVar3 + (long)(int)param_1 * 0xb20 + 0x90);
        iVar16 = 0;
        do {
          iVar1 = iVar16 + 1;
          if (iVar16 < (int)(uint)uVar8) {
            uVar15 = (uint)(*pfVar21 * fVar12);
          }
          *puVar20 = uVar15;
          pfVar21 = pfVar21 + 1;
          puVar20 = puVar20 + 1;
          iVar16 = iVar1;
        } while (iVar1 != 4);
      }
      else if (sVar7 == 2) {
        *(int *)(puVar3 + lVar26 * 0xb20 + 0x94) = (int)((float)uVar15 * (float)puVar17[0x19b]);
      }
      puVar3 = PTR_g_imvt_isp_ae_context_010348b0;
      iVar16 = puVar17[0x19d];
      *(int *)(PTR_g_imvt_isp_ae_context_010348b0 + lVar26 * 0xb20 + 0xac) =
           (int)((float)puVar17[0x18b] * DAT_00885664);
      if (iVar16 - 100U < 0x65) {
        iVar16 = imvt_isp_special_iso_adjust();
        *(int *)(puVar3 + lVar26 * 0xb20 + 0xac) = *(int *)(puVar3 + lVar26 * 0xb20 + 0xac) + iVar16
        ;
      }
      puVar3 = PTR_g_imvt_isp_ae_context_010348b0;
      if (PTR_g_imvt_isp_ae_context_010348b0[lVar26 * 0xb20 + 0xb1c] != '\0') {
        imvt_printf((double)(float)puVar17[0x18a],(double)(float)puVar17[0x19b],3,
                    "[imvt_isp_ae] [ISP][WDR Gain] integrate_time:%f short:%u long:%u isp gain:%f\n"
                    ,*(undefined4 *)(PTR_g_imvt_isp_ae_context_010348b0 + lVar26 * 0xb20 + 0x90),
                    *(undefined4 *)(PTR_g_imvt_isp_ae_context_010348b0 + lVar26 * 0xb20 + 0x94));
        puVar3[lVar26 * 0xb20 + 0xb1c] = 0;
      }
      uVar14 = DAT_045a8f88;
      puVar13 = PTR_g_imvt_isp_ae_context_010348b0;
      puVar3 = PTR_g_imvt_isp_ae_context_010348b0 + (long)(int)param_1 * 0xb20 + 0x90;
      *(int *)(PTR_g_imvt_isp_ae_context_010348b0 + lVar26 * 0xb20 + 0xa0) =
           (int)puVar17[0x18d] >> 4;
      puVar13[lVar26 * 0xb20 + 0xc0] = 1;
      *(undefined4 *)(puVar13 + lVar26 * 0xb20 + 0xd0) = uVar14;
      memcpy(param_3,puVar3,0xa8c);
      *(undefined4 *)(puVar13 + lVar26 * 0xb20 + 0xec) = 0;
      uVar18 = 0;
    }
  }
  else {
    printf("Illegal handle id %d in %s!\n",(ulong)param_1,"imvt_isp_ae_run");
    uVar18 = 0xffffffff;
  }
  return uVar18;
}



/* FUNCTION FUN_00885834 @ 00885834 body=[[00885834, 0088585b]]
*/

undefined8 FUN_00885834(void)

{
  imvt_printf(0,"[imvt_isp_ae] invalid fwwdr mode:%d!\n");
  return 0xffffffff;
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



/* FUNCTION FUN_00887420 @ 00887420 body=[[00887420, 008876ff]]
REF 00888054 PARAM caller=FUN_00888030@00888030
*/

void FUN_00887420(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  long local_8;
  
  uVar1 = DAT_00887700;
  local_88 = 0;
  local_80 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_98 = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  local_58 = 0;
  local_50 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  if (DAT_045a9984 != 0) {
    uVar11 = 0;
    do {
      while( true ) {
        pthread_mutex_lock((pthread_mutex_t *)&DAT_045a9988);
        uVar10 = DAT_045a98e8;
        uVar9 = DAT_045a98e0;
        local_68 = DAT_045a98e0;
        local_60 = DAT_045a98e8;
        imvt_isp_af_get_roi(&local_98,&local_94,&local_90,&local_8c);
        uVar5 = local_8c;
        uVar4 = local_90;
        uVar3 = local_94;
        uVar2 = local_98;
        local_50 = CONCAT44(local_8c,local_90);
        local_58 = CONCAT44(local_94,local_98);
        pthread_mutex_unlock((pthread_mutex_t *)&DAT_045a9988);
        iVar8 = memcmp(&local_68,&local_88,0x10);
        if ((iVar8 == 0) || (iVar8 = n3a_af_get_af_mode(), iVar8 != 3)) {
          iVar8 = memcmp(&local_58,&local_78,0x10);
          uVar9 = local_78;
          uVar10 = local_70;
        }
        else {
          imvt_cam_region_roi_show
                    (local_88 & 0xffffffff,local_88._4_4_,local_80 & 0xffffffff,local_80._4_4_,0,0);
          imvt_cam_region_roi_show
                    (local_68 & 0xffffffff,local_68._4_4_,local_60 & 0xffffffff,local_60._4_4_,
                     0x801f,0);
          local_88 = uVar9;
          local_80 = uVar10;
          iVar8 = memcmp(&local_58,&local_78,0x10);
          uVar9 = local_78;
          uVar10 = local_70;
        }
        local_78 = uVar9;
        local_70 = uVar10;
        if (iVar8 != 0) {
          local_78._4_4_ = (undefined4)(uVar9 >> 0x20);
          uVar6 = local_78._4_4_;
          local_70._4_4_ = (undefined4)(uVar10 >> 0x20);
          uVar7 = local_70._4_4_;
          imvt_cam_region_roi_show(uVar9 & 0xffffffff,uVar6,uVar10 & 0xffffffff,uVar7,0,0);
          imvt_cam_region_roi_show(uVar2,uVar3,uVar4,uVar5,0xfc00,0);
          local_78 = local_58;
          local_70 = local_50;
        }
        iVar8 = (int)uVar11;
        if (iVar8 != (int)(uVar11 / 0x1e) * 0x1e) break;
        uVar9 = n3a_af_get_fv();
        uVar11 = (ulong)(iVar8 + 1);
        uVar10 = (**(code **)(DAT_045a9880 + 0x28))();
        iVar8 = snprintf((char *)&local_48,0x40,"%d %d %.2f %.2f %.2f %.2f",(double)(float)local_68,
                         (double)local_68._4_4_,(double)(float)local_60,(double)local_60._4_4_,
                         uVar9 & 0xffffffff,uVar10 & 0xffffffff);
        imvt_cam_region_roi_clear(0,0,0x3e800000,uVar1,iVar8);
        imvt_cam_region_roi_show(0,0,0x3e800000,uVar1,0,&local_48);
        usleep(2000);
        if (DAT_045a9984 == 0) goto LAB_008876b8;
      }
      uVar11 = (ulong)(iVar8 + 1);
      usleep(2000);
    } while (DAT_045a9984 != 0);
  }
LAB_008876b8:
  if (local_8 != *(long *)PTR___stack_chk_guard_010398b8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  return;
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



/* FUNCTION FUN_00887840 @ 00887840 body=[[00887840, 00887b23] [00887b28, 00887be3] [00887be8, 00887bfb]]
REF 008883a8 UNCONDITIONAL_CALL caller=imvt_n3a_af_set_roi@00888298
REF 00888008 UNCONDITIONAL_CALL caller=NONE
*/

void FUN_00887840(float param_1,float param_2,float param_3,float param_4)

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  int local_30;
  undefined1 auStack_2c [4];
  float local_28;
  float local_24;
  float local_20;
  float fStack_1c;
  float local_18;
  float local_14;
  float local_10;
  float fStack_c;
  long local_8;
  
  local_8 = *(long *)PTR___stack_chk_guard_010398b8;
  if (DAT_045a98a0 != 0) {
    uVar2 = 0xffffffff;
    goto LAB_00887a60;
  }
  fVar3 = *(float *)(DAT_045a9978 + 0x1408);
  fVar8 = *(float *)(DAT_045a9978 + 0x13f8);
  fVar9 = *(float *)(DAT_045a9978 + 0x13fc);
  fVar7 = *(float *)(DAT_045a9978 + 0x1400);
  fVar10 = *(float *)(DAT_045a9978 + 0x1410);
  fVar4 = *(float *)(DAT_045a9978 + 0x140c);
  iVar1 = *(int *)(DAT_045a9978 + 0x1404);
  DAT_045a98e0._0_4_ = param_1;
  DAT_045a98e0._4_4_ = param_2;
  DAT_045a98e8._0_4_ = param_3;
  DAT_045a98e8._4_4_ = param_4;
  imvt_isp_af_get_roi(&local_40,&local_3c,&local_38,&local_34);
  imvt_isp_af_get_res(&local_30,auStack_2c);
  fVar5 = 0.0;
  if (fVar8 == 0.0) {
LAB_00887920:
    if (param_1 != 0.0) goto LAB_00887a98;
LAB_0088792c:
    if (0.5 <= param_1 + param_3) goto LAB_00887a98;
LAB_00887938:
    fVar7 = param_3 * param_4;
    fVar5 = param_1;
    fVar8 = param_2;
    fVar9 = param_4;
    fVar6 = param_3;
  }
  else {
    if (DAT_00887c00 / (double)fVar8 <= (double)((float)local_30 * param_3)) {
      fVar5 = (param_3 - param_3 * fVar8) * 0.5;
      goto LAB_00887920;
    }
    fVar5 = 0.0;
    if ((float)local_30 * param_3 <= DAT_00887c08) goto LAB_00887920;
    fVar5 = (float)(((double)param_3 - DAT_00887c00 / (double)local_30) * 0.5);
    if (param_1 == 0.0) goto LAB_0088792c;
LAB_00887a98:
    if ((param_1 + param_3 == 1.0) && (0.5 < param_1)) goto LAB_00887938;
    fVar6 = param_3 - fVar5 * 2.0;
    fVar5 = fVar5 + param_1;
    fVar9 = fVar9 * param_4 * 0.5;
    fVar8 = param_2 + fVar9;
    fVar9 = param_4 - (fVar7 * param_4 * 0.5 + fVar9);
    fVar7 = fVar6 * fVar9;
  }
  if (fVar10 < fVar7) {
    fVar10 = fVar10 / (param_3 * param_4);
    if (fVar10 < 0.0) {
      sqrtf(fVar10);
    }
    fVar6 = param_3 * SQRT(fVar10);
    fVar9 = param_4 * SQRT(fVar10);
    fVar5 = param_1 + (param_3 - fVar6) * 0.5;
    fVar8 = param_2 + (param_4 - fVar9) * 0.5;
  }
  if (iVar1 != 0) {
    if ((((local_40 < param_1) || (fVar5 + fVar6 < local_40 + local_38)) || (local_3c < fVar8)) ||
       (fVar8 + fVar9 < local_3c + local_34)) {
      fVar4 = local_40 + local_38;
      if (((((fVar5 < local_40) || (fVar4 < fVar5 + fVar6)) ||
           ((fVar8 < local_3c || (local_3c + local_34 < fVar8 + fVar9)))) &&
          ((fVar5 <= fVar4 && (local_40 <= fVar5 + fVar6)))) &&
         ((fVar8 <= local_3c + local_34 && (local_3c <= fVar8 + fVar9)))) {
        local_28 = local_40;
        local_18 = local_3c;
        local_24 = fVar4;
        local_20 = fVar5;
        fStack_1c = fVar5 + fVar6;
        local_14 = local_3c + local_34;
        local_10 = fVar8;
        fStack_c = fVar8 + fVar9;
        qsort(&local_28,4,4,(__compar_fn_t)&LAB_00887408);
        qsort(&local_18,4,4,(__compar_fn_t)&LAB_00887408);
        fVar4 = ABS(local_24 - local_20) * ABS(local_14 - local_10);
        fVar10 = fVar4 / (fVar6 * fVar9);
        if (((fVar3 <= fVar10) && (fVar4 <= fVar6 * fVar9)) &&
           ((fVar3 <= fVar4 / (local_38 * local_34) || (fVar10 <= fVar3)))) {
          uVar2 = 0;
          goto LAB_00887a60;
        }
      }
    }
    else {
      uVar2 = 0;
      if (fVar4 <= (local_38 * local_34) / (fVar6 * fVar9)) goto LAB_00887a60;
    }
  }
  uVar2 = FUN_00887708(fVar5,fVar8,fVar6,fVar9);
LAB_00887a60:
  if (local_8 != *(long *)PTR___stack_chk_guard_010398b8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
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



/* FUNCTION imvt_n3a_af_init @ 008893c8 body=[[008893c8, 0088946b] [00889470, 00889497]]
REF Entry Point EXTERNAL caller=NONE
REF 007308f8 UNCONDITIONAL_CALL caller=imvt_af_init@007308c0
*/

undefined4 imvt_n3a_af_init(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_045a98a4 = 0;
  DAT_045a98b8 = 0;
  DAT_045a9900 = 0;
  iVar1 = pthread_mutex_init((pthread_mutex_t *)&DAT_045a9988,(pthread_mutexattr_t *)0x0);
  if (param_1 == 0) {
    DAT_045a9880 = imvt_n3a_af_init_lens_mft(iVar1);
  }
  else if (param_1 == 1) {
    DAT_045a9880 = imvt_n3a_af_init_lens_ef();
  }
  else {
    if (param_1 != 2) {
      imvt_printf(0,"[af] af now not support this lens!!\n");
      return 0xffffffff;
    }
    DAT_045a9880 = imvt_n3a_af_init_lens_vcm();
  }
  (**(code **)(DAT_045a9880 + 0x90))(FUN_008887e0);
  uVar2 = n3a_af_init(DAT_045a9880);
  imvt_n3a_af_tof_set_lens(DAT_045a9880);
  DAT_045a98ac = 1;
  imvt_n3a_af_set_roi_type(1);
  imvt_isp_af_register_callback(&LAB_00887c10);
  return uVar2;
}



/* FUNCTION n3a_af_caf_set_params @ 00d3de20 body=[[00d3de20, 00d3de97]]
REF Entry Point EXTERNAL caller=NONE
REF 00f185f4 INDIRECTION caller=NONE
REF 00fe06a4 DATA caller=NONE
REF 00d3a49c UNCONDITIONAL_CALL caller=n3a_af_register_params@00d3a478
*/

void n3a_af_caf_set_params(void *param_1,undefined8 *param_2)

{
  memcpy(&DAT_047b7a08,param_1,0x450);
  DAT_047b7e58 = *param_2;
  DAT_047b7e60 = param_2[1];
  DAT_047b7e68 = param_2[2];
  DAT_047b7e70 = param_2[3];
  DAT_047b7e78 = param_2[4];
  DAT_047b7e80 = param_2[5];
  DAT_047b7e88 = *(undefined4 *)(param_2 + 6);
  DAT_04817d50 = *(undefined8 *)((long)param_1 + 0x420);
  return;
}



/* FUNCTION n3a_af_saf_set_params @ 00d40c40 body=[[00d40c40, 00d40c7b]]
REF Entry Point EXTERNAL caller=NONE
REF 00f1867c INDIRECTION caller=NONE
REF 00fe0928 DATA caller=NONE
REF 00d3a48c UNCONDITIONAL_CALL caller=n3a_af_register_params@00d3a478
*/

void n3a_af_saf_set_params(void *param_1)

{
  memcpy(&DAT_04817d98,param_1,0x90);
  DAT_0481a308 = *(undefined8 *)((long)param_1 + 0x40);
  return;
}



