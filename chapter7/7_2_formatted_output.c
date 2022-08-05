/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char mystring[16];
    strcpy(mystring, "hello, world");

    printf(":%s:\n", mystring);
    printf(":%10s:\n", mystring);
    printf(":%.10s:\n", mystring);
    printf(":%-10s:\n", mystring);
    printf(":%.15s:\n", mystring);
    printf(":%-15s:\n", mystring);
    printf(":%15.10s:\n", mystring);
    printf(":%-15.10s:\n", mystring);

    sprintf(mystring, "Decimal value: %d, Hex value: 0x%X\n", 255, 255);
    printf(mystring);




    return EXIT_SUCCESS;
}
