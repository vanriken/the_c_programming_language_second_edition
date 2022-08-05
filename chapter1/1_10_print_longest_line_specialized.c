#include <stdio.h>
#define MAX_INPUT_SIZE 1000 // maximum input line size

// definitions of external variables
int max_length;
char line[MAX_INPUT_SIZE];
char max_line[MAX_INPUT_SIZE];

int getline(void);
void copy(void);

/* print longest input line; specialized version */

int main(void)
{
    int length;  // current line length
    extern int max_length;
    extern char max_line[];

    max_length = 0;
    while((length = getline()) > 0)
    {
        if (length > max_length)
        {
            max_length = length;
            copy();
        }
    }
    if (max_length > 0)  // there was a line
    {
        printf("Longest line: %s", max_line);
        printf("Length = %d\n", max_length);
    }
    return 0;
}

/* getline (specialized version): read a line into s, return lengthgth of the line */
int getline()
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAX_INPUT_SIZE-1 && (c=getchar()) != EOF && c != '\n'; ++i)
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

/* copy (specialized version): copy 'from' into 'to'; assume that 'to' is big enough */
void copy()
{
    int i;
    extern char line[], max_line[];

    i = 0;
    while ((max_line[i] = line[i]) != '\0')
    {
        ++i;
    }
}
