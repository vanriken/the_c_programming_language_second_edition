#include <stdio.h>
#define MAX_INPUT_SIZE 1000 // maximum input line size

int getline(char line[], int max_input_size);
int len(char s[]);
void reverse(char s[]);

/* print longest input line */

int main(void)
{
    int length;  // current line length
    char line[MAX_INPUT_SIZE];  // current input line

    // Test with a hardcoded string
    char my_name[] = "Alexandros";
    printf("String: %s\n", my_name);
    printf("Length: %d\n", len(my_name));
    reverse(my_name); // reverse the line
    printf("String: %s\n", my_name);
    printf("Length: %d\n", len(my_name));

    while((length = getline(line, MAX_INPUT_SIZE)) > 0)
    {
        printf("Line: %s", line);
        printf("Length: %d\n", len(line));
        reverse(line); // reverse the line
        printf("Line: %s", line);
        printf("Length: %d\n", len(line));
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

/* reverse_string: reverses the character string s */
void reverse(char s[])
{
    int i_front = 0;
    int i_back = len(s) - 1;
    char temp;

    // if last character is a newline character, start reversing before it
    if (s[i_back] == '\n')
    {
        --i_back;
    }

    while (i_back > i_front)
    {
        temp = s[i_front];
        s[i_front] = s[i_back];
        s[i_back] = temp;

        ++i_front;
        --i_back;
    }
}

/* length: return the length of the character string s */
int len(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}
