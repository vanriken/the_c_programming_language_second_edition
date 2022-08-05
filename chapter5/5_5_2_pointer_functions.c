/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// TODO: getline, atoi, itoa, reverse, strindex, getop

int getline(char *s, int max_input_size);
int atoi(char *s);
void itoa(int n, char *s);
void reverse(char *s);
int strindex(char *s, char *t);

int main(void)
{
    // char s[32];
    // int len = getline(s, 4);
    // printf("%s\n", s);
    // printf("length = %d\n", len);

    // printf("ATOI\n");
    // printf("%d\n", atoi("-42"));
    // printf("%d\n", atoi("2048"));
    //
    // char s[32];
    // printf("ITOA\n");
    // itoa(-24, s);
    // printf("%s\n", s);
    // itoa(128, s);
    // printf("%s\n", s);
    //
    // strcpy(s, "alexandros");
    // reverse(s);
    // printf("%s\n", s);

    printf("strindex(\"Alexandros\", \"dros\") = %d\n",
        strindex("Alexandros", "dros"));

    return 0;
}

/* getline: read a line into s, return length of the line */
int getline(char *s, int lim)
{
    char *p;
    int c;

    p = s;  // point p to s
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        *s++ = c;
    }
    if (c == '\n')
    {
        *s++ = c;
    }

    *s = '\0';
    return s - p;
}

/* atoi: convert string s to integer */
int atoi(char *s)
{
    int n, sign;
    while (isspace(*s))
        *s++;  // skip whitespace
    sign = (*s == '-') ? -1 : 1;
    if (*s == '-' || *s == '+')
        *s++;  // skip sign
    for (n = 0; isdigit(*s); *s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}

/* itoa: convert n to characters in s */
void itoa(int n, char *s)
{
    int sign;
    char *p;

    p = s;
    sign = n;

    // generate digits in reverse order
    do
    {
        *p++ = abs(n % 10) + '0';  // get next digit
    } while (n /= 10);             // delete it

    if (sign < 0)
        *p++ = '-';
    *p = '\0';

    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char *s)
{
    char tmp, *p;
    p = s + strlen(s) - 1;  // point p to end of s
    while (p > s)
    {
        tmp = *s;
        *s++ = *p;
        *p-- = tmp;
    }
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
    char *i, *j, *k;
    for (i = s; *i != '\0'; i++)  /* for each character in s */
    {
        j = i, k = t;
        while(*j == *k && *k != '\0')
        {
            j++;
            k++;
        }
        if (k-t > 0 && *k == '\0')      /* if it is the start of t */
        {
            return i-s;                 /* return its index */
        }
    }
    return -1;                          /* t was not found return -1 */
}


/* getop: get next operator or numeric operand */
int getop(char *s)
{
    int i, c;

    while((s[0] = c = getchar()) == ' ' || c == '\t')
        ;  // skip whitespace
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;  // not a number
    i = 0;
    if (isdigit(c))  // collect integer part
        while (isdigit(s[++i] = c = getchar()));
    if (c == '.')  // collect fraction part
        while (isdigit(s[++i] = c = getchar()));
    s[i] = '\0';
    if (c != EOF)
        ungetc(c, stdin);
    return NUMBER;
}

/* getop_pointer: get next operator or numeric operand; pointer version */
int getop(char *s)
{
    int i, c;

    while((*s = c = getchar()) == ' ' || c == '\t')
        ;  // skip whitespace
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;  // not a number
    if (isdigit(c))  // collect integer part
        while (isdigit(*++s = c = getchar()));
    if (c == '.')  // collect fraction part
        while (isdigit(*++s = c = getchar()));
    *s = '\0';
    if (c != EOF)
        ungetch(c, stdin);
    return NUMBER;
}
