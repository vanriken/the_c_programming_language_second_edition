#include <stdio.h>

/* copy input to output */

int main()
{
    int c;

    printf("The value of EOF is: %d\n", EOF);  // Print the value of EOF

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
}
