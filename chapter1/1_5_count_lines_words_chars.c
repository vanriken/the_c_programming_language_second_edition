# include <stdio.h>

# define IN 1  // inside a word
# define OUT 0  // outside a word

/* count lines, words and characters in input */

int main(void)
{
    int c, n_lines, n_words, n_chars, state;

    state = OUT;
    n_lines = n_words = n_chars = 0;

    while ((c = getchar()) != EOF)
    {
        ++n_chars;
        if (c == '\n')
        {
            ++n_lines;
        }
        if (c == ' ' || c == '\n' || c == '\t')  // end of a word
        {
            state = OUT;
        }
        else if (state == OUT)  // start of a new word
        {
            state = IN;
            ++n_words;
        }

    }
    printf("Number of lines: %d\n", n_lines);
    printf("Number of words: %d\n", n_words);
    printf("Number of characters: %d\n", n_chars);

    return 0;
}
