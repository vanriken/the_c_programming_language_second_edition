/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    typedef int Length;
    Length len, maxlen;
    Length *lengths[10];  // array of pointers to int

    typedef struct tnode *Treeptr;
    typedef struct tnode
    {
        char *word;
        int count;
        Treeptr left;
        Treeptr right;
    } Treenode;

    // create the type PFI for
    // "pointer to function (of two char * arguments) returning int"
    typedef int (*PFI)(char *, char *);
    PFI strcmp, numcmp;

    return 0;
}
