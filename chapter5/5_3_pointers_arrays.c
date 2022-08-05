/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *alloc(int);
void afree(char *);

int main(void)
{
    // pass part of array to a function "lex"
    // printf("%d\n", strlen(&"Alex"[1]));
    // printf("%d\n", strlen("Alex" + 1));

    char *p1, *p2, *p3, *p4;

    p1 = alloc(2);
    p2 = alloc(1);
    p3 = alloc(4);

    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);
    printf("p3 = %p\n", p3);

    afree(p1);
    printf("\n");

    p4 = alloc(1);
    printf("p3 = %p\n", p4);

    return 0;
}

#define ALLOCSIZE 10000  // available space

static char allocbuf[ALLOCSIZE];  // storage for alloc
static char *allocp = allocbuf;  // next free position

char *alloc(int n)  // return pointer to n characters
{
    if (allocbuf + ALLOCSIZE - allocp >= n)  // it fits
    {
        allocp += n;
        return allocp - n;  // old pointer
    }
    else  // not enough room in allocbuf
    {
        return 0;
    }
}

void afree(char *p)  // free storage pointed to by p
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)  // check that p is inside the buffer
        allocp = p;
}
