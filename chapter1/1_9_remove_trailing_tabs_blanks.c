#include <stdio.h>
#define MAX_INPUT_SIZE 1000 // maximum input line size

int getline(char line[], int max_input_size);
void remove_trailing_blanks(char line[], int length);

/* remove trailing blanks and tabs from the input */

int main(void)
{
    int length;  // current line length
    char line[MAX_INPUT_SIZE];  // current input line

    while((length = getline(line, MAX_INPUT_SIZE)) > 0)
    {
        remove_trailing_blanks(line, length);
        printf("%s", line);
    }

}

/* getline: read a line into s, return lengthgth of the line */
int getline(char line[], int max_input_size)
{
    int c, i;
    for (i = 0; i<max_input_size-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    // '\0' is used to mark the end of the character array
    line[i] = '\0';
    return i;
}

/* remove_trailing_blanks: remove trailing blanks and tabs from a line */
void remove_trailing_blanks(char line[], int length)
{
    /*
    From the implementation of getline it follows that
    line[length] = '\0' and line[length-1] = '\n'.

    Therefore we start from line[length - 2] and work backwards until we find
    the first character that is not a space or a tab.

    Once this character index is found, set
    line[i+1] = '\n' and line[length+2] = '\0'.
    */

    int i;
    for (i = length - 2; line[i] == ' ' || line[i] == '\t'; --i)
        ;  // do nothing inside the for loop

    line[i + 1] = '\n';
    line[i + 2] = '\0';
}
