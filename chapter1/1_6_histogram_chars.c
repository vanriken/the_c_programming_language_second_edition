#include <stdio.h>

#define ALPHA_NR 26
#define NUM_NR 10


/* print histogram of characters in the input */

int main(void)
{

    int i;
    int chars_freq[ALPHA_NR + NUM_NR];

    // initialize the chars_freq array with zero
    for (i = 0; i < ALPHA_NR + NUM_NR; i++)
    {
        chars_freq[i] = 0;
    }

    int c;
    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            ++chars_freq[c - 'a'];
        }
        else if ( c >= 'A' && c <= 'Z')
        {
            ++chars_freq[c - 'A'];
        }
        else if (c >= '0' && c <= '9')
        {
            ++chars_freq[ALPHA_NR + c - '0'];
        }
    }

    // Print horizontal histogram
    printf("Horizontal Histogram\n--------------------\n");

    for (i = 0; i < ALPHA_NR + NUM_NR; i++)
    {
        if (i < ALPHA_NR)
        {
            printf("%c: ", 'a' + i);
        }
        else
        {
            printf("%c: ", '0' + i - ALPHA_NR);
        }

        int j;
        for (j = 0; j < chars_freq[i]; j++)
        {
            printf("#");
        }

        putchar('\n');
    }
}
