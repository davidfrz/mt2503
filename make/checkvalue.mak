#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2008
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).

#
# This file lists valid feature values to avoid wrong feature configurations.
#

ifdef NAND_FLASH_BOOTING
NAND_FLASH_BOOTING_VALUE = NONE ENFB ONDEMAND MIXED BASIC 
    # NONE, ENFB, ONDEMAND, MIXED, BASIC
                                   # NONE: NORXIP Project and it's not NAND FLASH BOOTING
                                   # ENFB: MMI Images and string put on THIRD_ROM and dynmaic load into RAM by application. Default for MT6228/29/30
                                   # ONDEMAND: MMI Resource and Some Non-Real-Time App RO put on NAND and on-demand page in. 
                                   #           ARM9 MMU Required. Default for MT6235/38
                                   # MIXED: Both ENFB and On-Demand Page In mechanism enabled. ARM9 MMU Required. Pick this to support MBA Feature.
                                   # BASIC: Nand Flash Booting is turned on, but none of ENFB and ONDEMAND exists. Only ROM and SECONDARY_ROM.
  ifeq ($(findstring $(strip $(NAND_FLASH_BOOTING)) ,$(NAND_FLASH_BOOTING_VALUE)),)
    $(warning ERROR: NAND_FLASH_BOOTING value ($(strip $(NAND_FLASH_BOOTING))) is not in the valid list: $(strip $(NAND_FLASH_BOOTING_VALUE)))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef CSD_SUPPORT
CSD_SUPPORT_VALUE = NONE T_NT NT_ONLY 
  ifeq ($(findstring $(strip $(CSD_SUPPORT)) ,$(CSD_SUPPORT_VALUE)),)
    $(warning ERROR: CSD_SUPPORT value ($(strip $(CSD_SUPPORT))) is not in the valid list: $(strip $(CSD_SUPPORT_VALUE)))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef CAMCORDER_SUPPORT
CAMCORDER_SUPPORT_VALUE = NONE FULL SLIM STANDARD CUSTOM 
  ifeq ($(findstring $(strip $(CAMCORDER_SUPPORT)) ,$(CAMCORDER_SUPPORT_VALUE)),)
    $(warning ERROR: CAMCORDER_SUPPORT value ($(strip $(CAMCORDER_SUPPORT))) is not in the valid list: $(strip $(CAMCORDER_SUPPORT_VALUE)))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef WAP_SUPPORT
  $(warning ERROR: WAP_SUPPORT has been renamed to BROWSER_SUPPORT, please Do Not use the OLD option name anymore!)
  DEPENDENCY_CONFLICT = TRUE    
endif
  
ifdef TELECA_FEATURE
  $(warning ERROR: TELECA_FEATURE has been renamed to OBIGO_FEATURE, please Do Not use the OLD option name anymore!)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef JOGBALL_SUPPORT
JOGBALL_SUPPORT_VALUE = NONE JOGBALL OFN
  ifeq ($(findstring $(strip $(JOGBALL_SUPPORT)),$(JOGBALL_SUPPORT_VALUE)),)
    $(warning ERROR: JOGBALL_SUPPORT value ($(strip $(JOGBALL_SUPPORT))) is not in the valid list: $(strip $(JOGBALL_SUPPORT_VALUE)))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef MOTION_SENSOR_SUPPORT
  ifeq ($(MOTION_SENSOR_SUPPORT),FALSE)
    $(warning ERROR: MOTION_SENSOR_SUPPORT value ($(strip $(MOTION_SENSOR_SUPPORT))) is not in the valid list, it should be (NONE))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(PLATFORM)),MT6261)
  ifdef CSD_SUPPORT
    ifneq ($(strip $(CSD_SUPPORT)),NONE)
      $(warning ERROR: PLease set CSD_SUPPORT to NONE on MT6261)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef L1_EGPRS
    ifneq ($(strip $(L1_EGPRS)),FALSE)
       $(warning ERROR: PLease set L1_EGPRS to FALSE on MT6261)
       DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef AUDIO_COMPENSATION_ENABLE
    ifneq ($(strip $(AUDIO_COMPENSATION_ENABLE)),FALSE)
      $(warning ERROR: PLease set AUDIO_COMPENSATION_ENABLE to FALSE on MT6261)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
