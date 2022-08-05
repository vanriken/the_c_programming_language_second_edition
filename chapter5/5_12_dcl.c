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
#include "../chapter4/getch_ungetch.c"

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};
enum {OK = 0, ERROR};

int dcl(void);
int dirdcl(void);

void nextline(void);
int gettoken(void);
int tokentype;              // type of last token
char token[MAXTOKEN];       // last token string
char name[MAXTOKEN];        // identifier name
char datatype[MAXTOKEN];    // data type = char, int, etc.
char out[1000];             // output string

/*
int *f()  // function returning a pointer to int
int (*pf)()  // a pointer to a function returning an int

https://www.codementor.io/@dankhan/how-to-easily-decipher-complex-pointer-declarations-cpp-so24b66me
https://medium.com/@bartobri/untangling-complex-c-declarations-9b6a0cf88c96
*/

int main(void)  // convert declaration to words
{
    int result;

    while (gettoken() != EOF)
    {
        strcpy(datatype, token);  // first token on line is the datatype
        out[0] = '\0';
        if ((result = dcl()) != OK)
            nextline();
        else if (tokentype != '\n')
        {
            printf("syntax error\n");
            nextline();
        }
        else
            printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

/*
    gettoken: skips blanks and tabs and then finds the next token in the input.
    A "token" is a name, a pair of parentheses, a pair of brackets perhaps including
    a number, or any other single character.
*/
int gettoken(void)
{
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
    {
        return tokentype = c;
    }

}

/* nextline: move to the next line of the input */
void nextline(void)
{
    int c;
    while ((c = getch()) != '\n' && c != EOF)
        ;
    if (c == EOF)
        ungetch(c);
}

/* dcl: parse a declarator */
int dcl(void)
{
    int ns, result;
    for (ns = 0; gettoken() == '*'; )  // count *'s
        ns++;
    if ((result = dirdcl()) != OK)
        return result;
    while (ns-- > 0)
        strcat(out, " pointer to");
    return OK;
}

/* dircl: parse a direct declarator */
int dirdcl(void)
{
    int type, result;

    if (tokentype == '(')
    {
        if ((result = dcl()) != OK)
            return result;
        if (tokentype != ')')
        {
            printf("error: missing )\n");
            return ERROR;
        }
    }
    else if (tokentype == NAME)
    {
        strcpy(name, token);
    }
    else
    {
        printf("error: expected name or (dcl)\n");
        return ERROR;
    }

    while ((type=gettoken()) == PARENS || type == BRACKETS)
    {
        if (type == PARENS)
        {
            strcat(out, " function returning");
        }

        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
    return OK;
}
