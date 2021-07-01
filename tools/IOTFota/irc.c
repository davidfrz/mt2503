// irc.c : check if this project has invalid reference for Separate BIN FOTA feature
// IRC = Invalid Reference Checker
// Author: Stanley Chu (MTK02187)

#define _CRT_SECURE_NO_WARNINGS
#define _DBG (0)

#define _VERSION                    "15.04.00"
#define _FILE_LOG                   ".\\irc.log"
#define _FILE_EXCLUDED_LIST         ".\\irc_excluded.txt"

#define _FILE_DBG_LIS_WITH_ALL_LIBS ".\\ASTER02A_DEMO_PCB01_gprs_MT2502_S00.lis"
#define _FILE_DBG_UBIN_OPTION_MAK   ".\\ubin_Option.mak"   // for UBIN COMPLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_CHARS      (300)
#define LINE_BUF_MAX_CHARS  (512)

typedef struct s_sym
{
    char name[NAME_MAX_CHARS];
    int  keep;
    struct s_sym * next;
} syms;

typedef struct s_obj
{
    char name[NAME_MAX_CHARS];
    int  keep;
    int  sym_cnt;
    syms * sym;
    struct s_obj * next;
} objs;

typedef struct s_lib
{
    char name[NAME_MAX_CHARS];
    int  keep;
    int  obj_cnt;
    objs * obj;
    struct s_lib * next;
} libs;

typedef struct s_group
{
    char name[NAME_MAX_CHARS];
    int lib_cnt;
    libs * lib;
    struct s_group * next;
} groups;

typedef struct s_ubin
{
    int group_cnt;
    groups * group;
} group_set;

group_set       g_ubin_complist;
groups          g_all_libs;

char g_line_buf[LINE_BUF_MAX_CHARS];
char g_line_buf2[LINE_BUF_MAX_CHARS];
char g_output_path[NAME_MAX_CHARS];
char g_excluded_list_file[NAME_MAX_CHARS];

groups * add_group(group_set * gs, char * gname, FILE * f_log)
{
    groups * g;

    if (0 == gs->group_cnt)
    {
        g = gs->group = (groups *)malloc(sizeof(groups));
    }
    else    // already has at least 1
    {
        // go through list, check if it is already existed

        g = gs->group;

        while (1)
        {
            if (!strcmp(gname, g->name))
            {
                return g;
            }

            if (NULL == g->next)    // reach the tail, and this lib is not existed in lib list
            {
                // create lib instance for this new lib

                g->next = (groups *)malloc(sizeof(groups));
                g = g->next;

                break;
            }
            else
            {
                g = g->next;
            }
        }
    }

    // fill-in information

    strcpy(g->name, gname);
    g->lib_cnt = 0;
    g->lib = NULL;
    g->next = NULL;

    gs->group_cnt++;

    if (_DBG && f_log)
    {
        fprintf(f_log, "+add_group: gs.group_cnt=%d, group=%s\n", gs->group_cnt, g->name);
    }

    return g;
}


syms * add_sym_in_obj(objs * o, char * sname, FILE * f_log)
{
    syms * s = NULL;

    if (0 == o->sym_cnt)
    {
        s = o->sym = (syms *)malloc(sizeof(syms));
    }
    else    // already has at least 1 lib
    {
        // go through sym list, check if it is already existed

        s = o->sym;

        while (1)
        {
            if (!strcmp(sname, s->name))
            {
                return s;
            }

            if (NULL == s->next)    // reach the tail, and this sym is not existed in sym list
            {
                // create new sym instance

                s->next = (syms *)malloc(sizeof(syms));
                s = s->next;

                break;
            }
            else
            {
                s = s->next;
            }
        }
    }

    // init sym

    strcpy(s->name, sname);

    s->next = NULL;
    s->keep = 0;

    o->sym_cnt++;

    if (_DBG && f_log)
    {
        fprintf(f_log, "    + add_sym: sym=%s, sym_cnt=%d, obj=%s\n", s->name, o->sym_cnt, o->name);
    }

    return s;
}

objs * add_obj_in_lib(libs * l, char * oname, FILE * f_log)
{
    objs * o = NULL;

    if (0 == l->obj_cnt)
    {
        o = l->obj = (objs *)malloc(sizeof(objs));
    }
    else    // already has at least 1 lib
    {
        // go through obj list, check if it is already existed

        o = l->obj;

        while (1)
        {
            if (!strcmp(oname, o->name))
            {
                return o;
            }

            if (NULL == o->next)    // reach the tail, and this obj is not existed in obj list
            {
                // create new obj instance

                o->next = (objs *)malloc(sizeof(objs));
                o = o->next;

                break;
            }
            else
            {
                o = o->next;
            }
        }
    }

    // init obj

    strcpy(o->name, oname);

    o->sym_cnt = 0;
    o->keep = 0;
    o->sym = NULL;
    o->next = NULL;

    l->obj_cnt++;

    if (_DBG && f_log)
    {
        fprintf(f_log, "  + add_obj: lib=%s, obj_cnt=%d, obj=%s\n", l->name, l->obj_cnt, o->name);
    }

    return o;
}

libs * add_lib_in_group(groups * g, char * lname, FILE * f_log)
{
    libs * l;

    if (0 == g->lib_cnt)
    {
        l = g->lib = (libs *)malloc(sizeof(libs));
    }
    else    // already has at least 1 lib
    {
        // go through lib list, check if it is already existed

        l = g->lib;

        while (1)
        {
            if (!strcmp(lname, l->name))
            {
                return l;
            }

            if (NULL == l->next)    // reach the tail, and this lib is not existed in lib list
            {
                // create lib instance for this new lib

                l->next = (libs *)malloc(sizeof(libs));
                l = l->next;

                break;
            }
            else
            {
                l = l->next;
            }
        }
    }

    // fill-in lib information

    strcpy(l->name, lname);
    l->obj_cnt = 0;
    l->keep = 0;
    l->obj = NULL;
    l->next = NULL;

    g->lib_cnt++;

    if (_DBG && f_log)
    {
        fprintf(f_log, "+ add_lib_in_group: group=%s, g.lib_cnt=%d, lib=%s\n", g->name, g->lib_cnt, l->name);
    }

    return l;
}

groups * is_ubin_lib(libs * l)
{
    libs * l_in_ubin = NULL;
    groups * g;

    g = g_ubin_complist.group;

    while (g)
    {
        l_in_ubin = g->lib;

        while (l_in_ubin)
        {
            if (!strcmp(l->name, l_in_ubin->name))
            {
                return g;
            }

            l_in_ubin = l_in_ubin->next;
        }

        g = g->next;
    }

    return NULL;
}

int if_sym_belongs_obj(char *sname, objs * o)
{
    syms * s;

    s = o->sym;

    while (s)
    {
        if (!strcmp(sname, s->name))
        {
            return 1;
        }

        s = s->next;
    }

    return 0;
}

libs * get_lib_by_obj(char * oname, char * sname, FILE * f_log)
{
    #define _MAX_OBJ_CNT    (5)
    libs * l;
    objs * o;
    libs * l_candidates[_MAX_OBJ_CNT] = {NULL};
    objs * o_candidates[_MAX_OBJ_CNT] = {NULL};
    syms * s = NULL;
    int found;

    found = 0;

    l = g_all_libs.lib;

    while (l)
    {
        o = l->obj;

        while (o)
        {
            if (!strcmp(oname, o->name))
            {
                if (found < _MAX_OBJ_CNT)
                {
                    o_candidates[found] = o;
                    l_candidates[found] = l;

                    found++;
                }
                else
                {
                    if (f_log)
                    {
                        fprintf(f_log, "!FATAL ERROR! Exceeds %d duplicated objs (%s) are found!\n", _MAX_OBJ_CNT, oname);
                    }

                    break;
                }
            }

            o = o->next;
        }

        l = l->next;
    }

    if (1 == found)
    {
        return l_candidates[0];
    }
    else if (found > 1)
    {
        // duplicated objs are found, locate the precise one

        for (found = found - 1; found >= 0; found--)
        {
            if (if_sym_belongs_obj(sname, o_candidates[found]))
            {
                return l_candidates[found];
            }
        }

        /*
        if (f_log)
        {
            fprintf(f_log, "!FATAL ERROR! can't find any objs matched to symbol %s!\n", sname);
        }
        */
    }

    return NULL;
}


libs * get_lib_by_sym(char * sname)
{
    libs * l = NULL;
    objs * o = NULL;
    syms * s = NULL;
    int found;

    found = 0;

    l = g_all_libs.lib;

    while (l)
    {
        o = l->obj;

        while (o)
        {
            s = o->sym;

            while (s)
            {
                if (!strcmp(sname, s->name))
                {
                    found = 1;
                }

                if (found)
                {
                    break;
                }

                s = s->next;
            }

            if (found)
            {
                break;
            }

            o = o->next;
        }

        if (found)
        {
            break;
        }

        l = l->next;
    }

    if (found)
    {
        return l;
    }
    else
    {
        return NULL;
    }
}

void load_ubin_complist(FILE * f, FILE * f_log)
{
    int i = 0;
    char * ptr;
    char lname[NAME_MAX_CHARS];
    groups * g;

    ptr = fgets(g_line_buf, LINE_BUF_MAX_CHARS, f);

    while (ptr)
    {
        // 1. check if MMI lib
        if (ptr = strstr(g_line_buf, "UBIN_MMI_COMPLIST += "))
        {
            sscanf(ptr, "UBIN_MMI_COMPLIST += %s\n", lname);

            strcpy(lname + strlen(lname), ".lib");

            g = add_group(&g_ubin_complist, "MMI" , f_log);

            add_lib_in_group(g, lname, f_log);
        }
        else if (ptr = strstr(g_line_buf, "UBIN_BT_COMPLIST += "))
        {
            sscanf(ptr, "UBIN_BT_COMPLIST += %s\n", lname);

            strcpy(lname + strlen(lname), ".lib");

            g = add_group(&g_ubin_complist, "BT" , f_log);

            add_lib_in_group(g, lname, f_log);
        }

        ptr = fgets(g_line_buf, LINE_BUF_MAX_CHARS, f);
    }
}

// input: LIS file
void load_all_stuff(FILE * f_lis, FILE * f_log)
{
    char lname[NAME_MAX_CHARS];
    char oname[NAME_MAX_CHARS];
    char sname[NAME_MAX_CHARS];
    char * ptr;
    int len;
    libs * l;
    objs * o;

    ptr = fgets(g_line_buf, LINE_BUF_MAX_CHARS, f_lis);

    while (1)
    {
        ptr = strstr(g_line_buf, "Loading member");

        if (ptr)
        {
            sscanf(ptr, "Loading member %s from %s\n", oname, lname);

            len = strlen(lname);

            if ('.' == lname[len - 1])
            {
                lname[len - 1] = '\0';
            }

            l = add_lib_in_group(&g_all_libs, lname, f_log);

            o = add_obj_in_lib(l, oname, f_log);

            ptr = fgets(g_line_buf, LINE_BUF_MAX_CHARS, f_lis);

            while (ptr)
            {
                ptr = strstr(g_line_buf, "definition:");

                if (ptr)
                {
                    sscanf(ptr, "definition:  %s\n", sname);

                    // add symbol

                    add_sym_in_obj(o, sname, f_log);

                    // read next line and continue
                }
                else
                {
                    ptr = strstr(g_line_buf, "reference :");

                    if (!ptr)   // not "definition" and not "reference"
                    {
                        break;
                    }
                    // else, read next line and continue;
                }

                ptr = fgets(g_line_buf, LINE_BUF_MAX_CHARS, f_lis);
            }
        }
        else if (0 == strncmp("Section Cross References", g_line_buf, 24))   // meet end of mapping section
        {
            break;
        }
        else
        {
            ptr = fgets(g_line_buf, LINE_BUF_MAX_CHARS, f_lis);

            if (!ptr)
            {
                break;
            }
        }
    }
}

int is_excluded(char * line_buf)
{
    FILE * f;

    f = fopen(g_excluded_list_file, "r");

    while (fgets(g_line_buf, LINE_BUF_MAX_CHARS, f) != NULL)
    {
        if (!strcmp(g_line_buf, line_buf))
        {
            return 1;
        }
    }

    fclose(f);

    return 0;
}

int irc(FILE * f_lis, FILE * f_log)
{
    int result = 0;
    int i, j, k;
    char oname_src[NAME_MAX_CHARS];
    char oname_dst[NAME_MAX_CHARS];
    char sname_src[NAME_MAX_CHARS];
    char sname_dst[NAME_MAX_CHARS];
    char fname[NAME_MAX_CHARS];
    libs * lsrc;
    libs * ldst;
    groups *gsrc;
    groups *gdst;
    char *sname_src_p;
    char *sname_dst_p;

    fprintf(f_log, "====== Invalid Reference ======\n");

    // now we are in the line "Section Cross References"

    while (fgets(g_line_buf, LINE_BUF_MAX_CHARS, f_lis) != NULL)
    {
        if (NULL != strstr(g_line_buf, "refers to"))
        {
            // debug
            //printf("%s\n", g_line_buf);

            sscanf(g_line_buf, "%s refers to %s for %s\n", oname_src, oname_dst, fname);

            // split to obj name and symbol name

            // src
            for (i = 0; oname_src[i] != '\0'; i++)
            {
                if (oname_src[i] == '(')
                {
                    oname_src[i] = '\0';
                    break;
                }
            }

            for (j = i + 1, k = 0; oname_src[j] != ')';)
            {
                sname_src[k] = oname_src[j];
                j++;
                k++;
            }

            sname_src[k] = '\0';

            if (!strncmp(sname_src, "i.", 2))
            {
                sname_src_p = sname_src + 2;
            }
            else
            {
                sname_src_p = sname_src;
            }

            // dst
            for (i = 0; oname_dst[i] != '\0'; i++)
            {
                if (oname_dst[i] == '(')
                {
                    oname_dst[i] = '\0';
                    break;
                }
            }

            for (j = i + 1, k = 0; oname_dst[j] != ')';)
            {
                sname_dst[k] = oname_dst[j];
                j++;
                k++;
            }

            sname_dst[k] = '\0';

            if (!strncmp(sname_dst, "i.", 2))
            {
                sname_dst_p = sname_dst + 2;
            }
            else
            {
                sname_dst_p = sname_dst;
            }

            lsrc = get_lib_by_obj(oname_src, sname_src_p, f_log);
            ldst = get_lib_by_obj(oname_dst, fname, f_log);

            if (lsrc == NULL)
            {
                //if (f_log)
                    //fprintf(f_log, "WARNING: The lib of symbol %s is not found.\n", sname_src_p);
                continue;
            }
            else if (ldst == NULL)
            {
                //if (f_log)
                    //fprintf(f_log, "WARNING: The lib of symbol %s is not found.\n", sname_dst_p);
                continue;
            }

            gsrc = is_ubin_lib(lsrc);
            gdst = is_ubin_lib(ldst);

            // 1. check if MBIN => UBIN

            if (NULL == gsrc && NULL != gdst) // reference MAIN => any group
            {
                sprintf(g_line_buf2, "MBIN => UBIN: %s, %s, %s => %s, %s, %s (%s)\n",
                        lsrc->name, oname_src, sname_src_p, ldst->name, oname_dst, sname_dst_p, fname);

                if (!is_excluded(g_line_buf2))
                {
                    result = -1;

                    if (f_log)
                    {
                        fprintf(f_log, "%s", g_line_buf2);
                    }
                }
            }
            else if (NULL != gsrc && NULL != gdst && gsrc != gdst)  // reference between groups
            {
                sprintf(g_line_buf2, "%s => %s: %s, %s, %s => %s, %s, %s (%s)\n",
                        gsrc->name, gdst->name, lsrc->name, oname_src, sname_src_p, ldst->name, oname_dst, sname_dst_p, fname);

                if (!is_excluded(g_line_buf2))
                {
                    result = -1;

                    if (f_log)
                    {
                        fprintf(f_log, "%s", g_line_buf2);
                    }
                }
            }

            // 2. check reference between groups

            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
        }
    }

    return result;
}


int init()
{
    // init g_all_libs

    g_all_libs.lib = NULL;
    g_all_libs.next = NULL;
    g_all_libs.lib_cnt = 0;
    strcpy(g_all_libs.name, "All_Libs");

    //
    g_ubin_complist.group = NULL;
    g_ubin_complist.group_cnt = 0;

    return 0;
}

int main(int argc, char* argv[])
{
    FILE * fp = NULL;
    FILE * fp_log = NULL;
    int result = 0;
    int i;
    char fullname[NAME_MAX_CHARS];

    printf("====== Invalid Reference Checker (for IOT Separate Bin FOTA) v%s ======\n", _VERSION);

    init();

    if (!_DBG && argc < 4)
    {
        printf("irc: ERROR! no input LIS file! Please use \"irc [LIS_FILE] [UBIN_OPTION_MAK] [EXCLUDED_LIST] [OUTPUT_PATH (optional)]\"\n");
        goto irc_exit;
    }

    // 0. handle output path
    if (argc >= 5)
    {
        strcpy(g_output_path, argv[4]);

        for (i = 0; g_output_path[i] != '\0'; i++);

        if (g_output_path[i - 1] != '\\')
        {
            g_output_path[i - 1] = '\\';
            g_output_path[i] = '\0';
        }
    }
    else
    {
        strcpy(g_output_path, ".\\");
    }

    // 0. handle excluded list file path
    if (_DBG)
    {
        strcpy(g_excluded_list_file, _FILE_EXCLUDED_LIST);
    }
    else
    {
        strcpy(g_excluded_list_file, argv[3]);
    }

    // 1. open log file

    strcpy(fullname, g_output_path);
    strcpy(fullname + strlen(fullname), _FILE_LOG);

    fp_log = fopen(fullname, "w+");

    if (!fp_log)
    {
        printf("irc: ERROR! open log file \"%s\" failed\n", fullname);

        goto irc_exit;
    }

    // 2. load UBIN complist

    printf("irc: loading UBIN compile list (ubin_Option.mak) ...\n");

    if (!_DBG)
        fp = fopen(argv[2], "r");
    else
        fp = fopen(_FILE_DBG_UBIN_OPTION_MAK, "r");

    if (!fp)
    {
        printf("irc: ERROR! open [UBIN_OPTION_MAK] file \"%s\" failed\n", argv[2]);

        if (fp_log)
            fprintf(fp_log, "irc: ERROR! open [UBIN_OPTION_MAK] \"%s\" failed\n", argv[2]);

        goto irc_exit;
    }

    load_ubin_complist(fp, fp_log);

    if (fp)
    {
        fclose(fp);
    }


    // 3. load all stuff

    printf("irc: loading all libs and objs from LIS file ...\n");

    if (!_DBG)
        fp = fopen(argv[1], "r");
    else
        fp = fopen(_FILE_DBG_LIS_WITH_ALL_LIBS, "r");

    if (!fp)
    {
        printf("irc: ERROR! open [LIS_FILE] file \"%s\" failed\n", argv[1]);

        if (fp_log)
            fprintf(fp_log, "irc: ERROR! open [LIS_FILE] \"%s\" failed\n", argv[1]);

        goto irc_exit;
    }

    load_all_stuff(fp, fp_log);

    // 4. IRC

    printf("irc: check invalid references ...\n");

    i = irc(fp, fp_log);

    if (i == 0)
    {
        printf("irc: PASS\n");

        if (fp_log)
            fprintf(fp_log, "irc: PASS\n");
    }
    else
    {
        printf("irc: FAIL. Please refer to irc.log for details.\n");
    }

    if (fp)
    {
        fclose(fp);
    }

irc_exit:

    if (fp_log)
        fclose(fp_log);

	return result;
}
