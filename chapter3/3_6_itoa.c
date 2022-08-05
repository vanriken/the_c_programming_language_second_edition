# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>

void itoa_basic(int n, char s[]);
void itoa_34(int n, char s[]);
void itob(int n, char s[], int b);
void itoa_36(int n, char s[], int w);

int main(void)
{
    int n = INT_MIN;
    char s[128];

    // itoa basic test
    itoa_basic(42, s);
    printf("%s\n", s);
    itoa_basic(n, s);
    printf("%s\n", s);

    printf("\n");

    // itoa_34 test
    itoa_34(42, s);
    printf("%s\n", s);
    itoa_34(n, s);
    printf("%s\n", s);

    printf("\n");

    // itob test
    itob(-255, s, 8);
    printf("%s\n", s);
    itob(-255, s, 16);
    printf("%s\n", s);
    itob(INT_MAX, s, 16);
    printf("%s\n", s);

    printf("\n");

    // itoa_36 test
    itoa_36(-255, s, 4);
    printf("%s\n", s);
    itoa_36(-255, s, 8);
    printf("%s\n", s);
    itoa_36(-255, s, 16);
    printf("%s\n", s);

    return 0;
}

/* itoa: convert n to characters in s */
void itoa_basic(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do
    {  // generate digits in reverse order
        s[i++] = n % 10 + '0';  // get the next digit
    } while ((n /= 10) > 0);  // delete the digit

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    strrev(s);
}

/*
* itoa_34: modification of itoa; see exercise 3-4 page 64
*
* In a two's complement number representation, our version of itoa does
* not handle the largest negative number, that is, the value of n equal
* to -(2^(wordsize - 1)). Explain why not. Modify it to print that
* value correctly regardless of the machine on which it runs.
*
* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
* It does not handle the largest negative number because it does not
* have a positive equivalent; -n where n is the largest negative number
* gives n; because n is still negative n%10 gives negative values
* instead of the desired positive ones. If we take the asbolute value
* of n%10 we get the correct value and character.
*/
void itoa_34(int n, char s[])
{
    int i, sign;

    sign = n;

    i = 0;
    do
    {  // generate digits in reverse order
        s[i++] = abs(n % 10) + '0';  // get the next digit
    } while (n /= 10);  // delete the digit

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    strrev(s);
}

/* itob: converts the integer n into a base b character in the string s */
void itob(int n, char s[], int b)
{
    int i, sign;
    char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (2 > b || b > strlen(symbols))
        return;  // not a valid base

    sign = n;
    i = 0;
    do
    {
        s[i++] = symbols[abs(n % b)];
    } while (n /= b);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    strrev(s);
}

/*
* itoa_36: modification of itoa_34
*
* The third argument is the minimum field width.
* The converted number must be padded with blanks on the left (if necessary) to make
* it wide enough.
*/
void itoa_36(int n, char s[], int w)
{
    int i, sign;

    sign = n;

    i = 0;
    do
    {  // generate digits in reverse order
        s[i++] = abs(n % 10) + '0';  // get the next digit
    } while (n /= 10);  // delete the digit

    if (sign < 0)
        s[i++] = '-';
    while (i < w)  // pad with blanks if necessary
        s[i++] = ' ';
    s[i] = '\0';

    strrev(s);
}
