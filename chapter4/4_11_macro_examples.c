/***********************************************************************

    filename:   4_11_macro_examples.c

    author:     Alexandros Rikos
    date:       YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>

#define     max(A, B)           ((A) > (B) ? A : B)
#define     square(X)           (X) * (X)
#define     swap(type, x, y)    \
    {                           \
        type temp;              \
        temp = x;               \
        x = y;                  \
        y = x;                  \
    };


int main(void)
{
    printf("%d\n", square(4));
    printf("%d\n", max(3, 4));

    int x1 = 10;
    int x2 = 20;

    printf("%d %d\n", x1, x2);
    swap(int, x1, x2);
    printf("%d %d\n", x1, x2);
    return 0;
}
