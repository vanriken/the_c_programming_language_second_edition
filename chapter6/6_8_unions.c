/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // EXIT_SUCCESS and EXIT_FAILURE

int main(void)
{
    // suppose that constant may be int, float, or a char *
    // union: single variable that can legitimately hold any one of several types
    union u_tag
    {
        int ival;
        float fval;
        char *sval;
    };

    // a union may only be initialized with a value of the type of its first member
    // in this file, u can be initialized with an integer
    union u_tag u = {2};

    printf("initialized: %d\n\n", u.ival);

    u.ival = 4;
    printf("%d\n", u.ival);
    printf("size: %d\n", sizeof(u));
    u.fval = 3.14;
    printf("%f\n", u.fval);
    printf("size: %d\n", sizeof(u));
    u.sval = "string";
    printf("%s\n", u.sval);
    printf("size: %d\n", sizeof(u));

    // unions may occur within structures and arrays, and vice versa
    struct
    {
        char *name;
        int flags;
        int utype;
        union
        {
            int ival;
            float fval;
            char *sval;
        } u;
    } symtab[16];




    return 0;
}
