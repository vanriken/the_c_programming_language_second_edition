/***********************************************************************
    filename:   4_3_7_get_unget_str.c
    author:     Alexandros Rikos
    date:       YYYY-MM-DD

    description:

    comments: Write a routing ungets(s) that will push back an entire string onto
              the input. Should ungets know about buf and bufp, or should it just use
              ungetch?
***********************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFSIZE 1000
#define MAXLEN 1000

int getch(void);
void ungetch(int c);
int getstr(char line[], int limit);
void ungetstr(char line[]);

int main(void)
{
    char line[MAXLEN];
    char s[] = "Alexandros";

    getstr(line, MAXLEN);
    printf("%s", line);

    ungetstr(s);

    getstr(line, MAXLEN);
    printf("%s", line);

    return 0;
}

/* getstr: get a string */
int getstr(char line[], int limit)
{
    int i = 0, c;

    while (limit - 1 > 0 && (c = getch()) != EOF && c != '\n')
        line[i++] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';
    return i;
}

/* ungetstr: push string back on input */
void ungetstr(char line[])
{
    int i = strlen(line);

    while(i)
        ungetch(line[--i]);
}

char buf[BUFFSIZE];  // buffer for ungetch
int bufp = 0;  // next free position in buf

int getch(void) // get a (possibly pushed back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  // push character back on input
{
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

// NOTE: The ungetstr() function doesn't need access to buf and bufp. It is enough
// just to use the ungetch() function.
