#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop:  get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = line[line_i++]) == ' ' || c == '\t'); // skip the white space
    s[1] = '\0';  // terminate string s

    // c has been set in the previous while loop
    if (!isdigit(c) && c != '.')
        return c;      /* not a number */

    i = 0;
    if (isdigit(c))    /* collect integer part */
        while (isdigit(s[++i] = c = line[line_i++]));

    if (c == '.')      /* collect fraction part */
        while (isdigit(s[++i] = c = line[line_i++]));

    s[i] = '\0'; // terminate string
    line_i--; // decrement the line idx before next call to getop

    return NUMBER;
}
