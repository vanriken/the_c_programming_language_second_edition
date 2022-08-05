/***********************************************************************

    filename:       4_6_11_reverse_polish_calc.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:    Modify getop so that it does not need to use ungetch().
                    Hint: use an internal static variable.

    comments:

***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAL 100
#define BUFFSIZE 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

int main(void)
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
    case NUMBER:
      push(atof(s));
      break;

    case '+':
      push(pop() + pop());
      break;

    case '-':
      op2 = pop();
      push(pop() - op2);
      break;

    case '*':
      push(pop() * pop());
      break;

    case '/':
      op2 = pop();

      if (op2 != 0.0)
      {
        push(pop() / op2);
      }
      else
      {
        printf("Error: zero divisor.\n");
      }

      break;

    case '%':
      op2 = pop();

      if (op2 != 0.0)
      {
        push((int)pop() % (int)op2);
      }
      else
      {
        printf("Error: zero divisor.\n");
      }
      break;

    case '\n':
      printf("result: %.8g\n", pop());
      break;

    default:
      printf("Error: unknown command %s.\n", s);
      break;
    }
  }

  return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f)
{
  if (sp < MAXVAL)
  {
    val[sp++] = f;
  }
  else
  {
    printf("Error: stack full, can't push %g.\n", f);
  }
}

double pop(void)
{
  if (sp > 0)
  {
    return val[--sp];
  }
  else
  {
    printf("Error: stack empty.\n");
    return 0.0;
  }
}


int getop(char s[])
{
    int i = 0, c, next;
    static int buf = EOF;

    if (buf == EOF || buf == ' ' || buf == '\t')
    {
        // skips blanks and tabs
        while ((s[0] = c = getchar()) == ' ' || c == '\t');
        s[1] = '\0';
    }
    else
    {
        c = buf;
    }

    if (!isdigit(c) && c != '.' && c != '-')  // not a number
        return c;

    // minus can be an operator but also the start of a negative number
    if (c == '-')
    {
        next = getchar();

        // the '-' can be interpreted as an operand when
        // the following character is neither a digit nor a space OR when
        // the following character is whitespace
        if ((!isdigit(next) && next != '.') || isspace(next))
        {
            buf = next;
            return c;
        }
        s[i++] = c;  // add the minus sign to the string
        s[i] = next; // add first char after the minus
    }

    // collect the integer part
    while (isdigit(s[++i] = c = getchar()));

    if (c == '.')  // collect the fraction part
        while (isdigit(s[++i] = c = getchar()));

    s[i] = '\0';  // terminate string

    if (c != EOF)
        buf = c;

    return NUMBER;
}


/* NOTE: The static definition can also be applied to internal variables. Internal
         static variables are local to a particular function just as automatic variables
         are, but unlike automatics, they remain in existence rather than coming and
         going each time the function is activated. This means that internal static
         variables provide private, permanent storage within a single function. */
