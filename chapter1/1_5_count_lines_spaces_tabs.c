#include <stdio.h>

/* count lines, spaces and tabs in input */

int main()
{
    int c;
    int number_of_lines;
    int number_of_spaces;
    int number_of_tabs;

    number_of_lines = 0;
    number_of_spaces = 0;
    number_of_tabs = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++number_of_lines;
        }
        else if (c == ' ')
        {
            ++number_of_spaces;
        }
        else if (c == '\t')
        {
            ++number_of_tabs;
        }
    }
    printf("Number of lines: %d\n", number_of_lines);
    printf("Number of spaces: %d\n", number_of_spaces);
    printf("Number of tabs: %d\n", number_of_tabs);
}
