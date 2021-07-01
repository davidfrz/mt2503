// keep_sym_gen.c : generate ubin_keep_sym.txt for automatic build flow of Separate Bin FOTA
// Author: Stanley Chu (MTK02187)

#define _CRT_SECURE_NO_WARNINGS
#define _DBG (0)

#define _VERSION                    "14.35.00"
#define _FILE_OUTPUT                "ubin_keep_sym.txt"
#define _FILE_LOG                   ".\\keep_sym_gen.log"

#define _FILE_DBG_LIS_WITH_ALL_LIBS ".\\THOR61A_DEMO_PCB01_none_MT6261_S00.lis"
#define _FILE_DBG_UBIN_LINK_ERROR   ".\\ubin_link.log"
#define _FILE_DBG_INFOMAKE          ".\\infomake.log"   // for UBIN COMPLIST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_CHARS      (300)
#define LINE_BUF_MAX_CHARS  (512)

char g_output_path[NAME_MAX_CHARS];

char g_excluded_obj[3][50] =
{
    "MMISymbolArray.obj",
    "custom_ubin_symbol.obj",
    "0" // end of excluded obj list
};

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
} ubin ;

//ubin g_ubin;

groups  g_all_libs;
groups  g_ubin_complist;

char g_line_buf[LINE_BUF_MAX_CHARS];

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

    if (f_log)
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

    if (f_log)
    {
        fprintf(f_log, "  + add_obj: lib=%s, obj_cnt=%d, obj=%s\n", l->name, l->obj_cnt, o->name);
    }

    return o;
}

libs * add_lib(groups * g, char * lname, FILE * f_log)
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

    if (f_log)
    {
        fprintf(f_log, "+ add_lib: group=%s, g.lib_cnt=%d, lib=%s\n", g->name, g->lib_cnt, l->name);
    }

    return l;
}

int is_ubin_lib(libs * l)
{
    libs * l_in_ubin = NULL;

    l_in_ubin = g_ubin_complist.lib;

    while (l_in_ubin)
    {
        if (!strcmp(l->name, l_in_ubin->name))
        {
            return 1;
        }

        l_in_ubin = l_in_ubin->next;
    }

    return 0;
}

void mark_keep_sym(char * sname)
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
        if (!is_ubin_lib(l))
        {
            l->keep = 1;
            o->keep = 1;
            s->keep = 1;
        }
        // else, UBIN => UBIN, ignored
    }
}

void print_keep_sym(FILE * f_out)
{
    libs * l = NULL;
    objs * o = NULL;
    syms * s = NULL;

    l = g_all_libs.lib;

    while (l)
    {
        o = l->obj;

        while (o)
        {
            if (o->keep)
            {
                fprintf(f_out, "%s(%s)\n", l->name, o->name);

            }

            s = o->sym;

            while (s)
            {
                if (s->keep)
                {
                    fprintf(f_out, "--keep %s\n", s->name);
                }

                s = s->next;
            }

            o = o->next;
        }

        l = l->next;
    }
}

void gen_keep_sym(FILE * f_link_error, FILE * f_log, char * output_path)
{
    char * ptr;
    char sname[NAME_MAX_CHARS];
    char f_output_fullname[NAME_MAX_CHARS];
    FILE * f_out;

    // open output file

    strcpy(f_output_fullname, output_path);
    strcpy(f_output_fullname + strlen(output_path), _FILE_OUTPUT);

    f_out = fopen(f_output_fullname, "w+");

    if (!f_out)
    {

        printf("keep_sym_gen: ERROR! open output file \"%s\" failed\n", f_output_fullname);

        if (f_log)
        {
            fprintf(f_log, "keep_sym_gen: ERROR! open output file \"%s\" failed\n", f_output_fullname);
        }

        return;
    }

    // parse f_link_error

    ptr = fgets(g_line_buf, LINE_BUF_MAX_CHARS, f_link_error);

    while (ptr)
    {
        ptr = strstr(g_line_buf, "Error: L6218E: Undefined symbol ");

        if (ptr)
        {
            sscanf(ptr, "Error: L6218E: Undefined symbol %s (%*s)\n", sname);

            mark_keep_sym(sname);
        }

        ptr = fgets(g_line_buf, LINE_BUF_MAX_CHARS, f_link_error);
    }

    // generate output file

    print_keep_sym(f_out);

    if (f_out)
    {
        fclose(f_out);
    }
}

void load_ubin_complist(FILE * f, FILE * f_log)
{
    int i = 0;
    char * ptr;
    char lname[NAME_MAX_CHARS];

    ptr = fgets(g_line_buf, LINE_BUF_MAX_CHARS, f);

    while (ptr)
    {
        ptr = strstr(g_line_buf, "UBIN_COMPLIST");

        if (ptr)
        {
            ptr = strstr(ptr, "=");
            ptr++;

            // now ptr is behind 'UBIN_COMPLIST ='

            // skip any spaces
            while (*ptr == ' ')
            {
                ptr++;
            }

            // start to load all ubin libs
            i = 0;

            for (; *ptr != '\0' && *ptr != '\n';)
            {
                if (*ptr == ' ')        // meet ' ', this lib finishes
                {
                    strcpy(lname + i, ".lib");
                    //lname[i] = '\0';    // finish this lib name

                    add_lib(&g_ubin_complist, lname, f_log);

                    ptr++;              // go next lib
                    i = 0;              // reset lname

                    while (*ptr == ' ') // skip all space between libs
                    {
                        ptr++;
                    }
                }
                else
                {
                    lname[i++] = *ptr;
                    ptr++;
                }
            }

            if (0 != i) // for case: UBIN_COMPLIST is not ended with ' ', add the last lib
            {
                i++;
                lname[i] = '\0';

                add_lib(&g_ubin_complist, lname, f_log);
            }

            break;
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

            l = add_lib(&g_all_libs, lname, f_log);

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

int init()
{
    // init g_all_libs

    g_all_libs.lib = NULL;
    g_all_libs.next = NULL;
    g_all_libs.lib_cnt = 0;
    strcpy(g_all_libs.name, "All_Libs");

    //
    g_ubin_complist.lib = NULL;
    g_ubin_complist.next = NULL;
    g_ubin_complist.lib_cnt = 0;
    strcpy(g_ubin_complist.name, "UBIN_Libs");

    return 0;
}

int main(int argc, char* argv[])
{
    FILE * fp = NULL;
    FILE * fp_log = NULL;
    int result = 0;
    int i;
    char fullname[NAME_MAX_CHARS];

    printf("====== keep_sym_gen for IOT Separate Bin FOTA v%s ======\n", _VERSION);

    init();

    if (!_DBG && argc < 4)
    {
        printf("keep_sym_gen: ERROR! no input LIS file! Please use \"keep_sym_gen [LIS_FILE_WITH_ALL_LIBS] [INFO_MAKE] [UBIN_LINK_LOG] [OUTPUT_PATH (optional)]\"\n");
        goto keep_sym_gen_exit;
    }

    // 0. handle output path
    if (argc >= 5)
    {
        strcpy(g_output_path, argv[4]);

        i = strlen(g_output_path);

        if (g_output_path[i - 1] != '\\')
        {
            g_output_path[i] = '\\';
            g_output_path[i + 1] = '\0';
        }
    }
    else
    {
        strcpy(g_output_path, ".\\");
    }

    // 1. open log file

    strcpy(fullname, g_output_path);
    strcpy(fullname + strlen(fullname), _FILE_LOG);

    fp_log = fopen(fullname, "w+");

    if (!fp_log)
    {
        printf("keep_sym_gen: ERROR! open log file \"%s\" failed\n", fullname);

        goto keep_sym_gen_exit;
    }

    // 2. load all stuff

    printf("keep_sym_gen: loading all libs and objs from LIS file ...\n");

    if (!_DBG)
        fp = fopen(argv[1], "r");
    else
        fp = fopen(_FILE_DBG_LIS_WITH_ALL_LIBS, "r");

    if (!fp)
    {
        printf("keep_sym_gen: ERROR! open [LIS_FILE_WITH_ALL_LIBS] file \"%s\" failed\n", argv[1]);

        if (fp_log)
            fprintf(fp_log, "keep_sym_gen: ERROR! open [LIS_FILE_WITH_ALL_LIBS] \"%s\" failed\n", argv[1]);

        goto keep_sym_gen_exit;
    }

    load_all_stuff(fp, fp_log);

    if (fp)
    {
        fclose(fp);
    }

    // 3. load UBIN complist

    printf("keep_sym_gen: loading UBIN compile list ...\n");

    if (!_DBG)
        fp = fopen(argv[2], "r");
    else
        fp = fopen(_FILE_DBG_INFOMAKE, "r");

    if (!fp)
    {
        printf("keep_sym_gen: ERROR! open [INFO_MAKE] file \"%s\" failed\n", argv[2]);

        if (fp_log)
            fprintf(fp_log, "keep_sym_gen: ERROR! open [INFO_MAKE] \"%s\" failed\n", argv[2]);

        goto keep_sym_gen_exit;
    }

    load_ubin_complist(fp, fp_log);

    if (fp)
    {
        fclose(fp);
    }

    // 4. load UBIN link error log and generate keep information

    printf("keep_sym_gen: loading UBIN link error information ...\n");

    if (!_DBG)
        fp = fopen(argv[3], "r");
    else
        fp = fopen(_FILE_DBG_UBIN_LINK_ERROR, "r");

    if (!fp)
    {
        printf("keep_sym_gen: ERROR! open UBIN_LINK_LOG file \"%s\" failed\n", argv[3]);

        if (fp_log)
            fprintf(fp_log, "keep_sym_gen: ERROR! open [UBIN_LINK_LOG] \"%s\" failed\n", argv[3]);

        goto keep_sym_gen_exit;
    }

    printf("keep_sym_gen: generating ubin_keep_sym.txt ...\n");

    gen_keep_sym(fp, fp_log, g_output_path);

    if (fp)
    {
        fclose(fp);
    }

keep_sym_gen_exit:

    if (fp_log)
        fclose(fp_log);    

	return result;
}
