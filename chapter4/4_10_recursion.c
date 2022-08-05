/***********************************************************************

    filename:   4_10_recursion

    author:     Alexandros Rikos
    date:       YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <limits.h>
#include <string.h>

void printd(int);
void itoa_rec(int, char []);
void reverse(char []);

int main(void)
{
    // printd
    printd(0b1010);
    printf("\n");

    printd(-28);
    printf("\n");

    // itoa
    char s[100] = "";
    itoa_rec(25, s);
    printf("'%s'\n", s);

    itoa_rec(153, s);
    printf("'%s'\n", s);

    char str[] = "alexandros";
    reverse(str);
    printf("%s\n", str);
}

/* printd: print n in decimal (recursive) */
void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
    {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}

/* itoa_rec1: convert an integer into a string by calling a recursive routine */
void itoa_rec(int n, char s[])
{
    if (n < 0)  // negative number
    {
        s[0] = '-';
        n *= -1;
    }

    if (n / 10)  // recursive call
        itoa_rec(n / 10, s);

    int idx = 0;  // position for the next digit
    int m = n;  // helper variable equal to n
    while (m = m / 10)  // get position for next digit (e.g. m = 245 -> idx = 2)
        idx++;
    if (s[0] == '-')  // if number is negative, the first position is for the sign
        idx++;

    s[idx++] = n % 10 + '0';
    s[idx] = '\0';
}

/* reverse: reverses the string s in place */
void reverse(char s[])
{
    static int i = 0;
    static int j = 0;

    if (s[i] != '\0')
    {
        char c = s[i++];
        reverse(s);
        s[j++] = c;
    }

    /* NOTE: When recursive functions are used, static variables become handy to
             construct some useful functionalities */

}
