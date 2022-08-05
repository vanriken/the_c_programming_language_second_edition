#include <stdio.h>

#define BUFFER 100

/* print histogram of lengths of words in the input */

int main(void)
{
    int i, j;
    int histogram[BUFFER];
    int histogram_length = 0;

    int c;
    int word_count_index = 0;
    int max_word_count = 0;

    for (i = 0; i < BUFFER; i++)
    {
        histogram[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        // the character is whitespace
        if (c != ' ' && c != '\n' && c != '\t')
        {
            ++word_count_index;
        }
        else
        {
            if (word_count_index > 0)
            {
                ++histogram[word_count_index-1];

                if (histogram[word_count_index-1] > max_word_count)
                {
                    max_word_count = histogram[word_count_index-1];
                }

                if (histogram_length < word_count_index - 1)
                {
                    histogram_length = word_count_index - 1;
                }

                word_count_index = 0;
            }
        }
    }

    // Add in the histogram array a end of useful data char
    histogram[histogram_length + 1] = '$';

    // Print horizontal histogram
    printf("Horizontal Histogram\n--------------------\n");

    int row_index = 0;
    int column_index = 0;

    while (histogram[row_index] != '$')
    {
        printf("%3d: \t", row_index + 1);
        for (column_index = 0; column_index < histogram[row_index]; column_index++)
        {
            putchar('#');
        }

        putchar('\n');
        ++row_index;
    }

    putchar('\n');

    // Print vertical histogram
    printf("Vertical Histogram\n--------------------\n");

    for(row_index = max_word_count; row_index >= 0; --row_index)
    {
        column_index = 0;
        while (histogram[column_index] != '$')
        {
            if (row_index == 0)
            {
                printf("%2d ", column_index + 1);
            }
            else if (histogram[column_index] >= row_index)
            {
                printf("## ");
            }
            else
            {
                printf("   ");
            }

            ++column_index;
        }

        putchar('\n');
    }

    return 0;
}
