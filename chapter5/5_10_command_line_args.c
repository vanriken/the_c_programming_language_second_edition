/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>

/* command line arguments; 1st version */
int main(int argc, char *argv[])
{
    int i;
    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    printf("\n");
    return 0;
}

// /* command line arguments; 2nd version */
// int main(int argc, char *argv[])
// {
//     while (--argc > 0)
//         printf("%s%s", *++argv, (i < argc-1) ? " " : "");
//     printf("\n");
//     return 0;
// }
