/***********************************************************************
    filename:   4_3_9_getch_ungetch_v3.c
    author:     Alexandros Rikos
    date:       YYYY-MM-DD

    description:

    comments: Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
              what their properties should be if an EOF is pushed back, then implement
              your design.
***********************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFSIZE 100

int getch(void);
void ungetch(int c);

int main(void)
{
    unsigned c;

/*
* In the case that EOF is pushed back to ungetch(), the program will simply
* continue execution as it normally would. Ignoring the EOF.
*/
    ungetch(EOF);

    while ((c = getch()) != EOF)
    {
            putchar(c);
    }

    return 0;
}

unsigned buf[BUFFSIZE];  // buffer for ungetch
int bufp = 0;  // next free position in buf

int getch(void) // get a (possibly pushed back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  // push character back on input
{
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else if (c != EOF)
        buf[bufp++] = c;
}

/* The getch() function can't manage correctly the EOF character because
   in the original K&R version buf was a char array, which can't hold the EOF
   because EOF is -1 and char can't hold negative numbers. However the gcc compiler,
   on Windows, uses by default signed chars which can hold EOF, but this is not
   platform independent */
