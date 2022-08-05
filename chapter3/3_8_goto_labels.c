#include <stdio.h>
#include <string.h>

void common_item_goto(int x[], int lx, int y[], int ly);
void common_item(int x[], int lx, int y[], int ly);

/*
* Code that relies on goto statements is generally harder to understand and to maintain.
* Code involving a goto statement can always be written without once.
* goto statements should be used rarely, if at all.
*/

int main(void)
{
    int x[] = {1,2,3};
    int y[] = {1,4,5};

    common_item_goto(x, sizeof(x)/sizeof(x[0]), y, sizeof(y)/sizeof(y[0]));
    printf("\n");
    common_item(x, sizeof(x)/sizeof(x[0]), y, sizeof(y)/sizeof(y[0]));

    return 0;
}

void common_item_goto(int x[], int lx, int y[], int ly)
{
    int i, j;

    for (i = 0; i < lx; i++)
    {
        for (j = 0; j < ly; j++)
        {
            if (x[i] == y[j])
            {
                goto found;
            }
        }
    }
    printf("No match has been found.\n");
    return;

    found:
        printf("A match has been found at position %d: %d\n", i, x[i]);
}


void common_item(int x[], int lx, int y[], int ly)
{
    int i, j, idx, found;

    found = 0;
    for (i = 0; i < lx; i++)
    {
        for (j = 0; j < ly; j++)
        {
            if (x[i] == y[j])
            {
                found = 1;
                idx = i;
            }
        }
    }

    if (found)
    {
        printf("A match has been found at position %d: %d\n", idx, x[idx]);
    }
    else
    {
        printf("No match has been found\n");
    }
}
