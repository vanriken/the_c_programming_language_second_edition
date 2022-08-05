#include <stdio.h>
#include <string.h>

int atoi(const char s[]);
int lower(int c);
int htoi(const char s[]);

int main(void)
{
    char s[] = "1234";
    printf("atoi(%s) + 1 = %d\n", s, atoi(s) + 1);

    printf("lower('%c') = '%c'\n", 'A', lower('A'));

    char hex_string[] = "0x1FAB";
    printf("%s -> %d base 10\n", hex_string, htoi(hex_string));

    return 0;
}

/* atoi (ASCII to integer): convert string of digits into numeric equivalent */
int atoi(const char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
    {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 'a' + c - 'A';
    }
    else
    {
        return c;
    }
}

/* htoi (hex to integer): convert a string of hex digits into its equivalent integer value. */
int htoi(const char s[])
{
    int i, n;
    n = 0;
    i = 0;

    // skip the first two characters if hex number starts with 0x or 0X
    if (strlen(s) > 2 && (s[0] == '0') && (s[1] == 'x' || s[1] == 'X'))
    {
        i = 2;
    }

    for (; i < strlen(s); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            n = 16 * n + (s[i] - '0');
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            n = 16 * n + (10 + s[i] - 'a');
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            n = 16 * n + (10 + s[i] - 'A');
        }
        else if (s[i] == '\n')
        {
            return n;
        }
        else
        {
            printf("Error: Not a valid hex value.\n");
            return -1;
        }
    }
    return n;
}
