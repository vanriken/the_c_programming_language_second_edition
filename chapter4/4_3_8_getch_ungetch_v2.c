/***********************************************************************
    filename:   4_3_8_getch_ungetch_v2.c
    author:     Alexandros Rikos
    date:       YYYY-MM-DD

    description:

    comments: Suppose there will never be more than one character of pushback.
              Modify getch and ungetch accordingly.
***********************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int getch(void);
void ungetch(int c);

int main(void)
{
    char c = getch();
    printf("%c\n", c);

    ungetch(c);

    printf("%c\n", c = getch());

    return 0;
}

// buf == -1 means that the buffer is empty
int buf = -1;

int getch(void) // get a (possibly pushed back) character
{
    char temp;
    if (buf != -1)
    {
        temp = buf;
        buf = -1;
        return temp;
    }
    else
        return getchar();
}

void ungetch(int c)  // push character back on input
{
    if (buf != -1)
        printf("ungetch: buffer full\n");
    else
        buf = c;
}
