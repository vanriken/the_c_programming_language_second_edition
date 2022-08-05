/***********************************************************************

    filename:       4_10_quicksort.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>

void qsort(int [], int, int);
void printarray(int [], int);

int main(void)
{
    int v[] = {5, 4, 3, 2, -4};
    int len = sizeof(v)/sizeof(v[0]);

    printarray(v, len);

    qsort(v, 0, len-1);

    printarray(v, len);

    return 0;
}

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int [], int, int);

    if (left >= right)
        return;  // do nothing if array contains fewer than two elements

    swap(v, left, (left + right)/2);  // move partition element
    last = left;

    for (i = left+1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);

    swap(v, left, last);  // restore partition element

    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* printarray: prints the contents of an array */
void printarray(int v[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%3d ", v[i]);
    printf("\n");
}
