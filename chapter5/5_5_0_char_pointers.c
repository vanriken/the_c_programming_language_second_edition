/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    char amessage[] = "test";  // an array
    char *pmessage = "test";  // a pointer

    /* amessage is an array, just big enough to hold the sequence of characters and '\0'
       that initializes it. Individual characters within the array may be changed but
       amessage will always refer to the same storage.

       On the other hand, pmessage is a pointer, initialized to point to a string
       constant; the pointer may subsquently be modified to point elsewhere, but the
       result is undefined if you try to modify the string contents */

    printf("string: %s, len = %d\n", amessage, strlen(amessage));
    printf("string: %s, len = %d\n", pmessage, strlen(pmessage));

    printf("\n");
    for (i = 0; i < strlen(amessage); i ++)
    {
        printf("address: %p\n", &amessage[0]+i);
        printf("character: %c\n", amessage[i]);
    }

    printf("\n");
    for (i = 0; i < strlen(pmessage); i ++)
    {
        printf("address: %p\n", pmessage+i);
        printf("character: %c\n", *(pmessage+i));
    }

    amessage[1] = 'o';  // individual characters within the array may be changed
    printf("\n");
    printf("%s\n", amessage);

    // *(pmessage + 1) = 'o';  // result is undefined if we try to modify string contents
    printf("%s\n", pmessage);

    printf("\n");
    printf("The value of '\\0' is %d.\n", '\0');

    return 0;
}
