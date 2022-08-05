/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char arrays vs char pointers in C
int main(void)
{
    char s1[] = "Alexandros";
    char *s2 = "Alexandros";

    // print char array and char pointer as string
    printf("%s\n", s1);
    printf("%s\n\n", s2);

    // print a single character in the char array and char pointer
    printf("%c\n", s1[2]);
    printf("%c\n", s2[2]);
    printf("%c\n\n", *(s2+2));

    // print the length of the string using strlen
    printf("%d\n", strlen(s1));
    printf("%d\n\n", strlen(s2));

    // for s1 sizeof gives size of array, for s2 it gives size of pointer to first char
    printf("%d\n", sizeof(s1));
    printf("%d\n", sizeof(&s1[0]));
    printf("%d\n\n", sizeof(s2));

    // the elements of an array can be modified
    s1[0] = 'E';
    s1[1] = 'd';

    // s2 points to a string constant
    // we are not allowed to change the contents of a string constant
    //s2[0] = 'E';

    // printing
    printf("%s\n", s1);
    printf("%s\n", s2);

    return 0;
}
