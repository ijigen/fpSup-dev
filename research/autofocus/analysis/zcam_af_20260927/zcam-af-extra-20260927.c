/* audit_0x885eb0 @ 00885eb0 */

void audit_0x885eb0(void)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  bool bVar7;
  ushort uVar8;
  code *pcVar9;
  int iVar10;
  uint uVar11;
  pthread_t __th;
  ushort *puVar12;
  void *pvVar13;
  uint *puVar14;
  uint *puVar15;
  undefined1 *puVar16;
  ushort *puVar17;
  uint *puVar18;
  undefined8 uStack_7d60;
  undefined8 uStack_7d58;
  undefined8 uStack_7d50;
  undefined4 uStack_7d48;
  undefined1 auStack_7d40 [8216];
  undefined8 uStack_5d28;
  undefined8 uStack_5d20;
  undefined8 uStack_5d18;
  undefined4 uStack_5d10;
  undefined1 auStack_5d08 [8];
  undefined4 uStack_5d00;
  undefined4 uStack_5cfc;
  int iStack_5ce8;
  cpu_set_t cStack_5ce0;
  uint auStack_5c60 [2050];
  undefined1 auStack_3c58 [3060];
  undefined1 auStack_3064 [12380];
  long lStack_8;
  
  lStack_8 = *(long *)PTR___stack_chk_guard_010398b8;
  prctl(0xf,"get_focus_data_task",PTR___stack_chk_guard_010398b8,0);
  cStack_5ce0.__bits[0] = 0;
  cStack_5ce0.__bits[1] = 0;
  cStack_5ce0.__bits[2] = 0;
  cStack_5ce0.__bits[3] = 0;
  cStack_5ce0.__bits[4] = 0;
  cStack_5ce0.__bits[5] = 0;
  cStack_5ce0.__bits[6] = 0;
  cStack_5ce0.__bits[7] = 0;
  cStack_5ce0.__bits[8] = 0;
  cStack_5ce0.__bits[9] = 0;
  cStack_5ce0.__bits[10] = 0;
  cStack_5ce0.__bits[0xb] = 0;
  cStack_5ce0.__bits[0xc] = 0;
  cStack_5ce0.__bits[0xd] = 0;
  cStack_5ce0.__bits[0xe] = 0;
  cStack_5ce0.__bits[0xf] = 0;
  printf("bind cpu core %d\n",1);
  cStack_5ce0.__bits[0] = cStack_5ce0.__bits[0] | 2;
  __th = pthread_self();
  iVar10 = pthread_setaffinity_np(__th,0x80,&cStack_5ce0);
  if (iVar10 < 0) {
    printf("pthread_setaffinity_np error %s\n","get_focus_data_task");
  }
  bVar7 = false;
  memset(auStack_5c60,0,0x2008);
  HI_MPI_ISP_GetPubAttr(0,auStack_5d08);
  DAT_045a939c = uStack_5d00;
  DAT_045a93a0 = uStack_5cfc;
  DAT_045a9820 = iStack_5ce8;
  FUN_00885cb0(DAT_045a97c8,DAT_045a97cc,DAT_045a97d0,DAT_045a97d4,DAT_045a93b0,DAT_045a93b4);
LAB_00885fc4:
  do {
    do {
      if (DAT_045a9394 == 0) {
LAB_00886174:
        if (lStack_8 == *(long *)PTR___stack_chk_guard_010398b8) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(0);
      }
      iVar10 = HI_MPI_ISP_GetVDTimeOut(0,1,200);
    } while (DAT_045a93a4 != 0 || iVar10 != 0);
    iVar10 = HI_MPI_ISP_GetFocusStatistics(0,auStack_3c58);
    uVar8 = DAT_01067594;
    if (iVar10 != 0) {
      imvt_printf(0,"[isp_af] HI_MPI_ISP_GetStatistics error!(s32Ret = 0x%x)===============\n",
                  iVar10);
      if (bVar7) {
        imvt_printf(0,"[isp_af] isp af get data failed , exit thread!!!!\n");
        DAT_045a9394 = 0;
        goto LAB_00886174;
      }
      bVar7 = true;
      goto LAB_00885fc4;
    }
    auStack_5c60[0] = (uint)DAT_01067594;
    auStack_5c60[1] = (uint)DAT_01067596;
    puVar16 = auStack_3c58;
    if ((DAT_045a9820 != 0) && (puVar16 = auStack_3064, DAT_010675b0 == 2)) {
      puVar16 = auStack_3c58;
    }
    if (auStack_5c60[1] != 0) {
      uVar11 = (uint)DAT_01067596;
      puVar18 = &DAT_045a93bc;
      puVar17 = (ushort *)(puVar16 + 2);
      iVar10 = 0;
      do {
        if (uVar8 != 0) {
          puVar12 = puVar17;
          puVar14 = auStack_5c60 + iVar10;
          puVar15 = puVar18;
          do {
            uVar2 = puVar12[1];
            uVar3 = puVar12[2];
            puVar1 = puVar12 + 6;
            uVar4 = puVar12[4];
            uVar5 = *puVar12;
            puVar14[0x402] = (uint)puVar12[3];
            puVar14[2] = (uint)uVar5;
            puVar14[0x602] = (uint)uVar4;
            uVar6 = (uint)uVar2 * 10 + (uint)uVar3 * 0x36 >> 6;
            *puVar15 = uVar6;
            puVar14[0x202] = uVar6;
            puVar12 = puVar1;
            puVar14 = puVar14 + 1;
            puVar15 = puVar15 + 1;
          } while (puVar1 != puVar17 + (ulong)(auStack_5c60[0] - 1) * 6 + 6);
          iVar10 = iVar10 + (uint)uVar8;
        }
        puVar18 = puVar18 + 0x11;
        puVar17 = puVar17 + 0x66;
      } while (puVar18 != (uint *)((ulong)(uVar11 - 1) * 0x44 + 0x45a9400));
    }
    pcVar9 = DAT_045a97c0;
    if (DAT_045a97c0 != (code *)0x0) {
      pvVar13 = memcpy(auStack_7d40,auStack_5c60,0x2008);
      uStack_7d60 = uStack_5d28;
      uStack_7d58 = uStack_5d20;
      uStack_7d48 = uStack_5d10;
      uStack_7d50 = uStack_5d18;
      (*pcVar9)(pvVar13,&uStack_7d60,DAT_045a9398);
    }
    pthread_mutex_lock((pthread_mutex_t *)&DAT_045a97e8);
    if (DAT_045a93a8 != 0) {
      FUN_00885cb0(DAT_045a97c8,DAT_045a97cc,DAT_045a97d0,DAT_045a97d4,DAT_045a93b0,DAT_045a93b4);
    }
    bVar7 = false;
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_045a97e8);
  } while( true );
}


/* audit_0x887c10 @ 00887c10 */

void audit_0x887c10(void *param_1,undefined8 *param_2,int param_3)

{
  undefined8 uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  void *pvVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 uStack_2100;
  undefined8 uStack_20f8;
  undefined8 uStack_20f0;
  undefined8 uStack_20e8;
  undefined8 uStack_20e0;
  undefined8 uStack_20d0;
  undefined8 uStack_20c8;
  undefined8 uStack_20c0;
  undefined4 uStack_20b8;
  undefined1 auStack_20b0 [8212];
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  uint uStack_90;
  undefined4 uStack_8c;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined4 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined8 uStack_10;
  long lStack_8;
  
  lStack_8 = *(long *)PTR___stack_chk_guard_010398b8;
  DAT_045a9900 = DAT_045a9900 + 1;
  uStack_88 = 0;
  uStack_80 = 0;
  uStack_68 = 0;
  uStack_40 = 0;
  uStack_78 = 0;
  uStack_70 = 0;
  uStack_60 = 0;
  uStack_58 = 0;
  uStack_50 = 0;
  uStack_48 = 0;
  DAT_045a98b8 = DAT_045a98b8 + 1;
  uVar4 = 0;
  if (DAT_045a98b0 == 0) goto LAB_00887cc4;
  if (0 < DAT_045a98b4) {
    DAT_045a98b4 = DAT_045a98b4 + -1;
    uVar4 = 0;
    goto LAB_00887cc4;
  }
  if (param_3 < 1) {
    param_3 = 1;
  }
  if (param_3 < 0x32) {
    bVar2 = false;
    if ((DAT_045a98a0 != 0) && (2 < param_3)) {
LAB_00887f1c:
      iVar3 = param_3 / 6;
      goto LAB_00887f30;
    }
  }
  else {
    if (param_3 == (param_3 / 0x1e) * 0x1e) {
      iVar3 = param_3 / 0x3c;
    }
    else {
      iVar3 = param_3 / 0x32;
    }
    if (DAT_045a98a0 != 0) goto LAB_00887f1c;
LAB_00887f30:
    uVar7 = (ulong)iVar3;
    uVar8 = 0;
    if (uVar7 != 0) {
      uVar8 = DAT_045a98b8 / uVar7;
    }
    bVar2 = DAT_045a98b8 != uVar8 * uVar7;
  }
  if (bVar2 || DAT_045a98c0 != 0) {
    uVar4 = 0;
    goto LAB_00887cc4;
  }
  if ((DAT_045a98c8 != 0) && (iVar3 = n3a_af_is_doing_focus(), iVar3 == 0)) {
    iVar3 = pthread_mutex_lock((pthread_mutex_t *)&DAT_045a9988);
    FUN_00887840(DAT_045a98d0,DAT_045a98d4,DAT_045a98d8,DAT_045a98dc,iVar3);
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_045a9988);
    DAT_045a98c8 = 0;
  }
  if (DAT_045a98a0 == 0) {
    if (*(int *)(DAT_045a9880 + 0x17) == 0) {
      iVar3 = n3a_af_is_doing_focus();
      if ((iVar3 == 0) || (iVar3 = n3a_af_is_caf_on(), iVar3 != 0)) {
        iVar3 = (*(code *)*DAT_045a9880)();
        goto joined_r0x00887fa0;
      }
    }
    else {
      iVar3 = n3a_af_is_doing_focus();
joined_r0x00887fa0:
      if ((iVar3 == 0) && ((DAT_045a9878 < 4 && param_3 != 4) && (DAT_045a9878 >= 4 || 3 < param_3))
         ) {
        DAT_045a9878 = DAT_045a9878 + 1;
        goto LAB_00887d8c;
      }
    }
    (*(code *)DAT_045a9880[0xf])(&uStack_88);
    DAT_045a9878 = 0;
  }
  else {
    (*(code *)DAT_045a9880[0xf])(&uStack_88);
    DAT_045a9878 = 0;
  }
LAB_00887d8c:
  uVar4 = 0;
  if (DAT_045a98a0 == 0) {
    iVar3 = imvt_get_imu_data(&uStack_38);
    if (iVar3 == 0) {
      uStack_50 = CONCAT44(uStack_20,uStack_24);
      uStack_60 = CONCAT44(uStack_34,uStack_38);
      uStack_58 = CONCAT44(uStack_28,uStack_30);
      uStack_48 = CONCAT44(uStack_48._4_4_,uStack_1c);
      uStack_40 = uStack_10;
    }
    lVar5 = n3a_ae_af_get_lv_value();
    uStack_8c = 0;
    uStack_9c = 0;
    uStack_98 = 0;
    uStack_94 = 0;
    uStack_90 = 0;
    n3a_ae_get_luma_contrast(&uStack_9c,&uStack_98,&uStack_94,&uStack_90);
    uVar8 = (ulong)uStack_90;
    uVar1 = CONCAT44(uStack_8c,uStack_94);
    if (DAT_045a9900 < 4) {
      iVar3 = n3a_af_is_caf_started();
      uVar4 = 0;
      if (iVar3 == 0) goto LAB_00887cc4;
    }
    pvVar6 = memcpy(auStack_20b0,param_1,0x2008);
    uStack_20c0 = param_2[2];
    uStack_20d0 = *param_2;
    uStack_20c8 = param_2[1];
    uStack_20b8 = *(undefined4 *)(param_2 + 3);
    uStack_2100 = uStack_60;
    uStack_20f8 = uStack_58;
    uStack_20e0 = uStack_40;
    uStack_20f0 = uStack_50;
    uStack_20e8 = uStack_48;
    uVar4 = n3a_af_update(pvVar6,&uStack_20d0,uVar1,lVar5 << 0x20 | uVar8,&uStack_2100);
  }
LAB_00887cc4:
  if (lStack_8 != *(long *)PTR___stack_chk_guard_010398b8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}


