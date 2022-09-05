#include <stdio.h>
#include "sqlite3.h"

int main()
{
    //printf("%d", sqlite3_stricmp("jann", "jann"));

    char *ch = "HELLO WORLD";

    //printf("%d", sqlite3Pow10(2));

    sqlite3_str *st = sqlite3_str_new(NULL);
    sqlite3_str_appendf(st, "%s", ch);

    // printf("VALUE: %s", sqlite3_str_value(st));
    int ans  = sqlite3_str_length(st);
    printf("%d\n", ans);
    int ans2 = sqlite3_strglob("tashfia", "tashfia");
    printf("%d", ans2);
    
    
}