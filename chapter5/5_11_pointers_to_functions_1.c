/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alloc.c"
#include "getline.c"

#define MAXLINES 5000  // max # of lines to be sorted
char *lineptr[MAXLINES];  // pointers to text lines

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void quick_sort(void *lineptr[], int left, int right,
        int (*comp)(void *, void *));
int numcmp(char *,char *);
int (*comp)(void *, void *);


// sort input lines
int main(int argc, char *argv[])
{
    int nlines;  // number of input lines read
    int numeric = 1;  // 1 for numeric sort

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;

    if (numeric)
        comp = (int (*)(void *, void *)) numcmp;
    else
        comp = (int (*)(void *, void *)) strcmp;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        quick_sort((void **) lineptr, 0, nlines-1, comp);
        printf("--------\n");
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
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0';  // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
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

/* quick_sort: sort v[left] ... v[right] into increasing order */
void quick_sort(void *v[], int left, int right,
    int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int i, int j);

    if (left >= right)
        return;  // do nothing if array contains less than two elements
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    quick_sort(v, left, last-1, comp);
    quick_sort(v, last+1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/*
The function quick_sort expects an array of pointers, two integers and a function with
two pointer arguments. The generic pointer type void * is used for the pointer
arguments.

int (*comp)(void *, void *)
This declaration says that comp is a pointer to a function that has two void *
arguments and returns an int.

int *comp(void *, void *)
This declaration says that comp is a function that has two void * arguments
and returns a pointer to an int (very different).

As others have pointed out, for (int (*)(void*,void*))(numeric ? numcmp : strcmp)
then the following is a type cast: (int (*)(void*,void*))
and the expression is: (numeric ? numcmp : strcmp)
*/
