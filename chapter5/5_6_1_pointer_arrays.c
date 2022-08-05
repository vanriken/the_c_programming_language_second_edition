/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:    Exercise 5-7, page 110: Rewrite readlines to store lines in an array
                    supplied by main, rather than calling alloc to maintain storage.

    comments:

***********************************************************************/
#include <stdio.h>
#include <string.h>
#include "getline.c"

#define MAXLINES 5000  // max # of lines to be sorted
#define MAXSTORE 10000  // max # of chars from all lines to be stored

char *lineptr[MAXLINES];  // pointers to text lines

int readlines(char *lineptr[], int maxlines, char *stored_lines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(void)
{
    int nlines;  // number of input lines read
    char stored_lines[MAXSTORE];  // number of chars to be stored for all lines

    if ((nlines = readlines(lineptr, MAXLINES, stored_lines)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        printf("------\n");
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000  // max length of any input line
int getline(char *, int);
char *alloc(int);

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
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;  // do nothing if array contains less than two elements
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
