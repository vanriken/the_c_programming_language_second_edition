#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"
#define BYTE_TO_BINARY(byte)   \
    (byte & 128 ? '1' : '0'),\
    (byte & 64 ? '1' : '0'), \
    (byte & 32 ? '1' : '0'), \
    (byte & 16 ? '1' : '0'), \
    (byte & 8 ? '1' : '0'),  \
    (byte & 4 ? '1' : '0'),  \
    (byte & 2 ? '1' : '0'),  \
    (byte & 1 ? '1' : '0')

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

int main(void)
{
    unsigned int x = 0b01111111;
    unsigned int y = 0b1101;
    unsigned int z;

    printf("x\t%d\t", x);
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
    printf("y\t%d\t", y);
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(y));

    printf("\n");

    printf("function getbits\n");
    z = getbits(x, 7, 4);
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(z));

    printf("\n");

    printf("function setbits\n");
    z = setbits(x, 7, 4, y);
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(z));

    printf("\n");

    printf("function invert\n");
    z = invert(x, 7, 8);
    printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(z));

    printf("\n");

    printf("function rightrot\n");
    z = rightrot(0b11101,1);
    printf("%u", z);  // print as unsigned

    return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    // x >> (p+1-n) moves the desired field to the end of the word
    // ~0 is all 1-bits
    // shifting it left with ~0 << n places zeros in the rightmost n bits
    // complementing the result with ~ makes a mask with ones in the rightmost n bits
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* setbits: returns x with the n bits that begin at position p set to the rightmost
            n bits of y, leaving all other bits unchanged */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned int mask1;
    mask1 = ~(~0 << n);  // mask with ones in the rightmost n bits
    mask1 = ~(mask1 << (p+1-n));  // mask with zeros at positions that will be replaced

    unsigned int mask2;
    mask2 = ~(~0 << n);  // mask with ones in the rightmost n bits
    mask2 = (mask2 & y) << (p+1-n); // rightmost n bits of y shifted to correct position

    // make the position that will be replaced zero, then or with mask2
    return (x & mask1) | mask2;
}

/* invert: returns x with the n bits that begin at position p inverted, leaving all
    all other bits unchanged */
unsigned invert(unsigned x, int p, int n)
{
    unsigned int mask;
    mask = ~(~0 << n);  // mask with ones in the rightmost n bits
    mask = mask << (p+1-n);  // mask with ones shifted to the correct position
    return x ^ mask;  // flip the bits at one-position of the mask
}

/* rightrot: returns the value of integer x rotated to the right by n it positions */
unsigned rightrot(unsigned x, int n)
{
    while (n > 0)
    {
        if (x & 1)  // rightmost bit is a one
        {
            // ~(~0U >> 1) creates the mask 1000...0000
            // this way the right most one is placed at the left end
            x = (x >> 1) | ~(~0U >> 1);
        }
        else
        {
            x = x >> 1;
        }
        --n;
    }
    return x;
}
