/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* cat: concatenate files, version 2

   Assign a second output stream to the program, called stderr.
   Output written on stderr normally appears on the screen even if
   the standard output is redirected.

   The diagnostic output produced by fprintf goes onto stderr, so it finds its way
   to the screen instead of disappearing down a pipeline or into an output file.

   The standard library function exit terminates program execution when it is called.
   The argument of exit is available to whatever process called this one.
   Wihtin main, 'return expr' is equivalent to 'exit(expr)'.
   exit has the advantage that it can be called from any other function.

   Serious programs should take care to return sensible, useful status values.

   Output errors are rare, but can occur, so a program should check for them.
   The function 'int ferror(FILE *fp)' returns non-zero if an error occured on the stream fp.
   The function 'int feof(FILE *fp)' returns non-zero if end of file has occured.
 */
int main(int argc, char const *argv[]) {

    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog_name = argv[0];  // program name for errors

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
                fprintf(stderr, "%s: cannot open %s\n", prog_name, *argv);
                exit(1);
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }

    if (ferror(stdout))
    {
        fprintf(stderr, "%s: error writing stdout\n", prog_name);
        exit(2);
    }

    exit(0);
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
