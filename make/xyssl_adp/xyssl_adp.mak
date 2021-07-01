# Define source file lists to SRC_LIST
SRC_LIST = security\xyssl\adaptation\system\src\xyssl_mem.c \
           security\xyssl\adaptation\system\src\xyssl_fs.c \
           security\xyssl\adaptation\system\src\xyssl_soc.c \
           security\xyssl\adaptation\system\src\xyssl_time.c \
           security\xyssl\adaptation\system\src\xyssl_interface.c
 
# Define include path lists to INC_DIR
INC_DIR = applib\misc\include \
          vendor\framework\obigo_Q03C\adaptation\integration\include\trc \
          vendor\framework\obigo_Q03C\adaptation\integration\include \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\config \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\export \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_lib\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\intgr \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\refsrc \
          vendor\framework\obigo_Q03C\v1_official\msf\msf_mgr\source \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\config \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\export \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\intgr \
          vendor\stk\obigo_Q03C\v1_official\modules\STK\source \
          vendor\wap\obigo_Q03C\adaptation\integration\include \
          security\xyssl\adaptation\system\include \
          security\xyssl\v1_official\ssl\include \
          security\seclib\include \
          interface\security
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = OPENSSL_DISABLE_OLD_DES_SUPPORT \
            OSSL_ADP_MEM_STAT \
            NO_SYS_TYPES_H \
            L_ENDIAN \
            OPENSSL_NO_TLSEXT
 
