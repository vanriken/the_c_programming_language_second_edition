/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:    Write the program tail, which prints the last n lines of its input.
                    By default n is 10, but it can be changed by an optional command
                    line argument.

    comments:

***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "getline.c"

#define MAXLINES 5000  // max # of lines to be sorted
#define MAXSTORE 10000  // max # of chars from all lines to be stored

char *lineptr[MAXLINES];  // pointers to text lines

int readlines(char *lineptr[], int maxlines, char *stored_lines);
void writelines(char *lineptr[], int n_input_lines, int n_output_lines);
void handle_error(const char *msg);

int main(int argc, char *argv[])
{
    int n_input_lines;  // number of input lines read
    int n_output_lines;  // number of lines to print
    char stored_lines[MAXSTORE];  // number of chars to be stored for all lines

    if (argc == 1)  // no optional argument
        n_output_lines = 10;
    else if (argc == 2)
    {
        if (*argv[1] == '-' && isdigit(*(argv[1]+1)))
            n_output_lines = atoi(++argv[1]);
        else
            handle_error("Usage: find -n.");
    }
    else  // too many optional arguments
    {
        handle_error("Usage: find -n.");
    }


    // read lines from the input and print the last n lines
    if ((n_input_lines = readlines(lineptr, MAXLINES, stored_lines)) >= 0)
    {
        printf("------\n");
        writelines(lineptr, n_input_lines, n_output_lines);
        return 0;
    }
    else
    {
        printf("error: input is too big.\n");
        return 1;
    }
}

void handle_error(const char *msg)
{
    printf("Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

#define MAXLEN 1000  // max length of any input line
int getline(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *stored_lines)
{
    int len, nlines;
    // init p with first empty position from stored_lines
    char *p = stored_lines + strlen(stored_lines);
    char line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
    {
        // Checking if the current # of lines exceeds the max # of lines that can be stored
        // Also checking if the max # of chars from the stored_lines buffer is not exceeded
        if (nlines >= maxlines || (strlen(stored_lines) + len) > MAXSTORE)
            return -1;
        else
        {
            line[len-1] = '\0';  // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;  // Move p to the next empty position
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int n_input_lines, int n_output_lines)
{
    int i, start;

    if (n_output_lines > n_input_lines)
        start = 0;
    else
        start = n_input_lines - n_output_lines;

    for (i = start; i < n_input_lines; i++)
        printf("%s\n", lineptr[i]);
}
