#include <stdio.h>
#define MAX_INPUT_SIZE 1000 // maximum input line size

int getline(char line[], int max_input_size);
void copy(char to[], char from[]);

/* print longest input line */

int main(void)
{
    int length;  // current line length
    int max_length;  // maximum line length seen so far
    char line[MAX_INPUT_SIZE];  // current input line
    char max_line[MAX_INPUT_SIZE];  // longest line saved here

    max_length = 0;
    while((length = getline(line, MAX_INPUT_SIZE)) > 0)
    {
        if (length > max_length)
        {
            max_length = length;
            copy(max_line, line);
        }
    }
    if (max_length > 0)  // there was a line
    {
        printf("Longest line: %s", max_line);
        printf("Length = %d\n", max_length);
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

    // print the correct line length for lines that are longer than MAX_INPUT_SIZE
    while(c != EOF && c != '\n')
    {
        ++i;
        c = getchar();
    }

    return i;
}

/* copy: copy 'from' into 'to'; assume that 'to' is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}
