#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main(void)
{
    int arr[] = {1,3,4};
    int target = 2;
    int idx;

    idx = binsearch(target, arr, sizeof(arr) / sizeof(arr[0]));
    printf("idx = %d, ", idx);
    printf("match%sfound\n", (idx >= 0) ? " " : " not ");

    printf("\n");
    idx = binsearch2(target, arr, sizeof(arr) / sizeof(arr[0]));
    printf("idx = %d, ", idx);
    printf("match%sfound\n", (idx >= 0) ? " " : " not ");
    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid-1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;  // match found
        }
    }
    return -1;  // not found
}

/* binsearch2: uses only one test inside the loop */
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (x <= v[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return (x == v[low]) ? low : -1;
}
