/***********************************************************************

    filename:   4_3_reverse_polish_calc.c

    author:     Alexandros Rikos
    date:       YYYY-MM-DD

    description:

    comments:

***********************************************************************/

#include <stdio.h>
#include <stdlib.h>  // atof()
#include <math.h>  // fmod(), sin(), exp(), pow()
#include <string.h>  // strcmp

#define MAXOP 100  // max size of operand or operator
#define NUMBER 0  // signal that a number was found

#define IDENTIFIER 1  // signal that a library function was found
#define ENDSTRING 2

#define MAX_ID_LEN 32  // max id length
#define MAXVARS 30  // max number of variables

enum boolean {FALSE = 0, TRUE};

struct varType  // structure to hold variable name and value
{
    char name[MAX_ID_LEN];
    double val;
};

// function prototypes
int getop(char []);

void push(double);
double pop(void);
int is_empty(void);
void show_stack(void);
void duplicate_top(void);
void swap_top(void);

void clearStacks(struct varType var[]);
void dealWithName(char s[], struct varType var[]);
void dealWithVar(char s[], struct varType var[]);

int pos = 0;
struct varType last;

/* Reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];
    struct varType var[MAXVARS];

    clearStacks(var);

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;

            case IDENTIFIER:
                dealWithName(s, var);
                break;

            case '+':
                push(pop() + pop());
                break;

            case '*':
                push(pop() * pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: division by zero\n");
                break;

            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: division by zero\n");
                break;

            case '~':
                swap_top();
                break;

            case '?':
                show_stack();
                break;

            case '#':
                duplicate_top();
                break;

            case '!':
                clearStacks(var);
                break;

            case '\n':
                if (!is_empty())
                    printf("\t%.8g\n", pop());
                break;

            case ENDSTRING:
                break;

            case '=':
                pop();
                var[pos].val = pop();
                last.val = var[pos].val;
                push(last.val);
                break;

            case '<':
                printf("The last variable used was: %s (value == %g)\n",
                    last.name, last.val);
                break;

            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* dealWithName: handles the execution of library functions */
void dealWithName(char s[], struct varType var[])
{
    double op1, op2;

    if (strcmp(s, "sin") == 0)
        push(sin(pop()));

    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));

    else if (strcmp(s, "tan") == 0)
        push(tan(pop()));

    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));

    else if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        op1 = pop();
        if (op1 == 0 && op2 <= 0)
            printf("error: %g^%g\n", op1, op2);
        else
            push(pow(op1, op2));
    }
    /* Finally if it isn't one of the supported math functions we have a variable
       to deal with */
    else
        dealWithVar(s, var);
}

void dealWithVar(char s[], struct varType var[])
{
    int i = 0;

    while(var[i].name[0] != '\0' && i < MAXVARS -1)
    {
        if (strcmp(s, var[i].name) == 0)
        {
            strcpy(last.name, s);
            last.val = var[i].val;
            push(var[i].val);
            pos = i;
            return;
        }
        i++;
    }

    // variable name not found so add it
    strcpy(var[i].name, s);
    strcpy(last.name, s);
    push(var[i].val);
    pos = i;
}


/************************************************************
*
*   Functions related to the stack
*
*************************************************************/

#define MAXVAL 100  // maximum depth of val stack
int sp = 0;  // next free stack position
double val[MAXVAL];

/* push: push f onto the value stack */
void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
        printf("error: stack is full, cannot push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack is empty\n");
        return 0.0;
    }
}

/* is_empty: returns TRUE if the stack is empty, FALSE otherwise */
int is_empty(void)
{
  if (sp > 0)
  {
    return FALSE;
  }

  return TRUE;
}

/* show_stack: prints the top element of the stack without popping it */
void show_stack(void)
{
    int i;

    if (sp > 0)
    {
        printf("elements in the stack: ");
        for (i = sp - 1; i >= 0; i--)
            printf("%g ", val[i]);
        printf("\n");
    }
    else
        printf("stack is empty\n");
}

/* duplicate_top: duplicates the top element of the stack */
void duplicate_top(void)
{
    if (sp > 0)
    {
        double tmp = pop();
        push(tmp);
        push(tmp);
    }
    else
    {
        // stack is empty
    }
}

/* swap: swap the top two elements of the stack */
void swap_top(void)
{
    if (sp > 0)
    {
        double first = pop();
        double second = pop();
        push(first);
        push(second);
    }
    else
    {
        // stack is empty
    }

}

/* clear: clear the stacks */
void clearStacks(struct varType var[])
{
    int i;

    sp = 0;  // clear main stack by setting pointer to the bottom

    // clear the variables by setting the initial element of each name to
    // the terminating character
    for (i = 0; i < MAXVARS; i++)
    {
        var[i].name[0] = '\0';
        var[i].val = 0.0;
    }

    printf("stacks cleared\n");
}

/************************************************************
*
*  getop
*
*************************************************************/

#include <ctype.h>

int getch(void);
void ungetch(int c);

/* getop: get the next operator or numeric operand
*
* Skips blanks and tabs
* If the next character is not a digit or a decimal point, return it
* Otherwise, collect a string of digits and return NUMBER, the signal that a number
* has been collected
*/
int getop(char s[])
{
    int i = 0, c, next;

    // skips blanks and tabs
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    if (isalpha(c))
    {
        while (isalpha(s[++i] = c = getch()));
        s[i] = '\0';  // terminate the string at current position
        if (c != EOF)
            ungetch(c);
        return IDENTIFIER;
    }

    if (!isdigit(c) && c != '.' && c != '-')
    {
        // deal with assigning a variable
        if ((c == '=') && (next = getch()) == '\n')
        {
            ungetch('\n');
            return c;
        }
        if (c == '\0')
            return ENDSTRING;

        return c;
    }

    // minus can be an operator but also the start of a negative number
    if (c == '-')
    {
        next = getch();

        // the '-' can be interpreted as an operand when
        // the following character is neither a digit nor a space OR when
        // the following character is whitespace
        if ((!isdigit(next) && next != '.') || isspace(next))
        {
            ungetch(next);
            return c;
        }
        s[i] = c;  // add the minus sign to the string
        ungetch(next);  // unget character after the minus sign
    }

    // collect the integer part
    while (isdigit(s[++i] = c = getch()));

    if (c == '.')  // collect the fraction part
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';  // terminate string

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

/************************************************************
*
*  getch, ungeth, getstr, ungetstr
*
*************************************************************/

#define BUFFSIZE 1000
#define MAXLEN 1000

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
