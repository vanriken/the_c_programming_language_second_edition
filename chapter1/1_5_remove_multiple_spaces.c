#include <stdio.h>

/* copy input to output, replacing each string of one or multiple blanks
with a single blank */

int main()
{
    int c, last_c;

    while((c = getchar()) != EOF)
    {
        if (c != ' ' || last_c != ' ')
        {
            putchar(c);
        }

        last_c = c;

    }
}
