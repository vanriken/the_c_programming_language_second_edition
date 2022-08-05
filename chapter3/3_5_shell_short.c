#include <stdio.h>

void shellshort(int v[], int n);
void printarray(int v[], int n);

int main(void)
{
    int v[] = {10, 8, 9, 4, 1, -5, 30, 7, -2};
    printarray(v, sizeof(v) / sizeof(v[0]));

    shellshort(v, sizeof(v) / sizeof(v[0]));

    printarray(v, sizeof(v) / sizeof(v[0]));

    return 0;
}

/* printarray: prints the contents of an array */
void printarray(int v[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%3d ", v[i]);
    printf("\n");
}

/* shellshort: sort v[0], v[1], ..., v[n-1] into increasing order

Basic idea of this sorting algorithm is that in early stages far-apart elements
are compared, rather than adjacent ones. This tends to eliminate large amounts of
disorder quickly, so that later stages have less work to do. */
void shellshort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i-gap; j>=0 && v[j] > v[j+gap]; j-=gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}
