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

#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04

/*
flags |= EXTERNAL | STATIC;     // turns on the EXTERNAL and STATIC bits in flags
flags &= ~(EXTERNAL | STATIC)   // turns off the EXTERNAL and STATIC bit in flags
if ((flags &  (EXTERNAL | STATIC)) == 0)  // true when both bits are off
*/


int main(void)
{
    int flags = 0;

    // turn on a certain bit
    flags |= EXTERNAL;
    printf("flags: %d\n", flags);

    flags |= STATIC;
    printf("flags: %d\n", flags);

    flags |= KEYWORD;
    printf("flags: %d\n", flags);

    // turn off a certain bit
    flags &= ~STATIC;
    printf("flags: %d\n", flags);

    // check if a bit is on or off
    printf("KEYWORD BIT: %d\n", ((flags & KEYWORD) == 0) ? 0 : 1);
    printf("EXTERNAL BIT: %d\n", ((flags & EXTERNAL) == 0) ? 0 : 1);
    printf("STATIC BIT: %d\n", ((flags & STATIC) == 0) ? 0 : 1);

    /* C offers capability to define and accessing fields within a word directly
       rather than by bitwise logical operators
    */

    // alternative approach: use a bit field
    struct
    {
        unsigned int is_keyword : 1;
        unsigned int is_extern : 1;
        unsigned int is_static : 1;
    } bit_field = {0, 0, 0};

    printf("(%d, %d, %d)\n", bit_field.is_keyword, bit_field.is_extern, bit_field.is_static);

    // turn on two bits
    bit_field.is_extern = bit_field.is_keyword = 1;
    printf("(%d, %d, %d)\n", bit_field.is_keyword, bit_field.is_extern, bit_field.is_static);

    // turn a bit off
    bit_field.is_extern = 0;
    printf("(%d, %d, %d)\n", bit_field.is_keyword, bit_field.is_extern, bit_field.is_static);

    // test a bit
    printf("KEYWORD: %s\n", (bit_field.is_keyword) ? "TRUE" : "FALSE");

    return 0;
}
