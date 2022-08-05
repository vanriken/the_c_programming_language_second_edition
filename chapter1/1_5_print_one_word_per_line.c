# include <stdio.h>

# define IN 1  // inside a word
# define OUT 0  // outside a word

/* count lines, words and characters in input */

int main(void)
{
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF)
    {
        // the character is whitespace
        if (c != ' ' && c != '\n' && c != '\t')
        {
            putchar(c);
            state = IN;
        }
        else if (state == IN)
        {
            putchar('\n');
            state = OUT;
        }
    }

    return 0;
}
