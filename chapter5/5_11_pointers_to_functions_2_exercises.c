/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:    Modify the sort program to handle an -r flag, which indicates
                    sorting in reverse (decreasing) order. Be sure that -r works
                    with -n.

                    Add the option -f to fold upper and lower case together, so
                    that case distinctions are not made during sorting; for example
                    a and A compare equal.

                    Add the -d option, which makes comparisons only on letters, numbers
                    and blanks. Make sure it works together with -f.
    comments:

***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "alloc.c"
#include "getline.c"

#define MAXLINES 5000  // max # of lines to be sorted
char *lineptr[MAXLINES];  // pointers to text lines

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void quick_sort(void *lineptr[], int left, int right,
        int (*comp)(void *, void *), int order);

int numcmp(char *,char *);
int string_compare(char *, char *);


int (*comp)(void *, void *);

// use global variables for directory and foldcase flags.
int directory = 0;  // 1 for directory sort
int foldcase = 0;  // 1 for sorting case insensitive

// sort input lines
int main(int argc, char *argv[])
{
    int nlines;  // number of input lines read
    int numeric = 0;  // 1 for numeric sort
    int reverse = 0;  // 1 for sorting in reverse order

    while (--argc > 0)
    {
        if (strcmp(*++argv, "-n") == 0)
            numeric = 1;
        else if (strcmp(*argv, "-r") == 0)
            reverse = 1;
        else if (strcmp(*argv, "-f") == 0)
            foldcase = 1;
        else if (strcmp(*argv, "-d") == 0)
            directory = 1;
        else
            printf("Illegal option %s\n", *argv);
    }

    // assign the correct comparison function
    if (numeric)
        comp = (int (*)(void *, void *)) numcmp;
    else
        comp = (int (*)(void *, void *)) string_compare;

    // one-liner
    //comp = (int (*)(void *, void *))(numeric ? numcmp : string_compare);

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        quick_sort((void **) lineptr, 0, nlines-1, comp, reverse ? -1 : 1);
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
    int (*comp)(void *, void *), int order)
{
    int i, last;
    void swap(void *v[], int i, int j);

    if (left >= right)
        return;  // do nothing if array contains less than two elements
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (order * (*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    quick_sort(v, left, last-1, comp, order);
    quick_sort(v, last+1, right, comp, order);
}

/* string_compare: custom version of strcmp*/
int string_compare(char *s1, char *s2)
{
    if (directory)
    {
        while (!isalnum(*s1) && !isspace(*s1) && *s1)
            ++s1;  // ignore bad characters
        while (!isalnum(*s2) && !isspace(*s2) && *s2)
            ++s2;  // ignore bad characters
    }

    while (foldcase ? (tolower(*s1) == tolower(*s2)) : (*s1 == *s2))
    {
        if (*s1 == '\0')
            return 0;
        ++s1;
        ++s2;
        if (directory)
        {
            while (!isalnum(*s1) && !isspace(*s1) && *s1)
                ++s1;  // ignore bad characters
            while (!isalnum(*s2) && !isspace(*s2) && *s2)
                ++s2;  // ignore bad characters
        }
    }
    return foldcase ? (tolower(*s1) - tolower(*s2)) : (*s1 - *s2);
}

/* my_strcmp */
int my_strcmp(char *s1, char *s2)
{
    for (; *s1 == *s2; s1++, s2++)
        if (*s1 == '\0')
            return 0;
    return *s1 - *s2;
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
