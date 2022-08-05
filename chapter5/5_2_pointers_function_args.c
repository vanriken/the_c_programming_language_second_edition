/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <ctype.h>

void swap(int *, int *);
int getint(int *);
int getfloat(float *);
int getch(void);
void ungetch(int);
void printarray_int(int [], int);
void printarray_float(float [], int);

#define SIZE 10

int main(void)
{
    int n, arr1[SIZE];
    float arr2[SIZE];

    // initialize both arrays with zeros
    for (n = 0; n < SIZE; n++)
    {
        arr1[n] = 0;
        arr2[n] = 0.0;
    }

    // read integers
    printf("Read integers:\n");
    for (n = 0; n < SIZE && getint(&arr1[n]) != EOF; n++)
        ;
    printf("Array: ");
    printarray_int(arr1, sizeof(arr1)/sizeof(arr1[0]));
    printf("n = %d\n", n);

    //read floats
    printf("Read floats:\n");
    for (n = 0; n < SIZE && getfloat(&arr2[n]) != EOF; n++)
        ;

    printf("Array: ");
    printarray_float(arr2, sizeof(arr2)/sizeof(arr2[0]));
    printf("n = %d\n", n);

    return 0;
}

void swap(int *px, int *py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ;  // skip the white space
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);  // it is not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
        if (!isdigit(c) && c != EOF)  // + or - not followed by a digit
        {
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF )
        ungetch(c);
    return c;
}

/* getfloat: get next float input into *pn */
int getfloat(float *pn)
{
    double power;
    int c, sign;

    while (isspace(c = getch()))
        ;  // skip the white space

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);  // it is not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
        if (!isdigit(c))  // + or - not followed by a digit
        {
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }
    for (*pn = 0.0; isdigit(c); c = getch())  // integer part
        *pn = 10.0 * *pn + (c - '0');

    if (c == '.')  // handle the decimal point
        c = getchar();

    for (power = 1.0; isdigit(c); c = getch())  // fractional part
    {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }

    *pn = (sign / power) * *pn;

    if (c != EOF )
        ungetch(c);

    return c;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];  // buffer for ungetch
int bufp = 0;  // next free position in buf

int getch(void) // get a (possibly pushed back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  // push character back on input
{
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* printarray_int: prints the contents of an array */
void printarray_int(int v[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%3d ", v[i]);
    printf("\n");
}

/* printarray_float: prints the contents of an array */
void printarray_float(float v[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%3.3g ", v[i]);
    printf("\n");
}
