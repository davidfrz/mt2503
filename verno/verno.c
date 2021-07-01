#include "kal_release.h" 
kal_char* release_verno(void) 
{ 
   static kal_char verno_str[] = "MAUI.11C.W14.18.SP4_03.V1"; 
   return verno_str; 
} 
kal_char* release_hal_verno(void) 
{ 
   static kal_char hal_verno_str[] = ""; 
   return hal_verno_str; 
} 
kal_char* release_hw_ver(void) 
{ 
   static kal_char hw_ver_str[] = "ULTRA03AE_11C_HW"; 
   return hw_ver_str; 
} 
kal_char* build_date_time(void) 
{ 
   static kal_char build_date_time_str[] = "2017/01/06 22:26"; 
   return build_date_time_str; 
} 
kal_char* release_build(void) 
{ 
   static kal_char build_str[] = "BUILD_NO"; 
   return build_str; 
} 
kal_char* release_branch(void) 
{ 
   static kal_char build_branch_str[] = "11CW1418SP4_03 ULTRA03AE_11C"; 
   return build_branch_str; 
} 
kal_char* release_flavor(void) 
{ 
   static kal_char build_flavor_str[] = "NONE"; 
   return build_flavor_str; 
} 
kal_char* release_platform(void) 
{ 
   static kal_char release_platform_str[] = "MT2502"; 
   return release_platform_str; 
} 
kal_char* release_mmi_base(void) 
{ 
   static kal_char release_mmi_base_str[] = "PLUTO_MMI"; 
   return release_mmi_base_str; 
} 
kal_char* release_mmi_ver(void) 
{ 
   static kal_char release_mmi_ver_str[] = "PLUTO_MMI"; 
   return release_mmi_ver_str; 
} 
