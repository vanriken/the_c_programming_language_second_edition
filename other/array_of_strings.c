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

int main(void)
{
    // if you do not want to change the strings

    const char *a[2];  // array of two pointer to const char

    // set the pointers to the addresses of two static strings
    a[0] = "alex";
    a[1] = "mareike";

    printf("%s\n", a[0]);  // print using index
    printf("%s\n", *a);  // print using pointer
    printf("%s\n", a[1]);
    printf("%s\n", *(a+1));
    // ------------------------------------------------

    // if you want to be able to change the strings

    // allocate two consecutive arrays of 14 chars each
    // content of static arrays can be copied into them
    char b[2][14];

    strcpy(b[0], "wlexandros");
    strcpy(b[1], "markos");

    b[0][0] = 'a';

    printf("%s\n", b[0]);  // print using index
    printf("%s\n", b[1]);

    return 0;
}
