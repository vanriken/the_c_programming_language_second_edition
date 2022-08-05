/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* cat: concatenate files, version 1 */
int main(int argc, char const *argv[]) {

    FILE *fp;
    void filecopy(FILE *, FILE *);

    if (argc == 1)  // no args: copy standard input
    {
        filecopy(stdin, stdout);
    }
    else
    {
        while (--argc > 0)
        {
            if ((fp = fopen(*(++argv), "r")) == NULL)
            {
                printf("cat: cannot open %s\n", *argv);
                return EXIT_FAILURE;
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }

    return EXIT_SUCCESS;
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);
    }
}


/*
#define getchar() getc(stdin)
#define putchar() putc((c), stdout)
*/
