#include <stdio.h>
#include <string.h>

#define TRUE 1;
#define FALSE 0;

void reverse(char s[]);
void expand(char s1[], char s2[]);
int validrange(char c1, char c2);

int main(void)
{
    char name[] = "Alexandros";
    printf("%s\n", name);
    reverse(name);
    printf("%s\n", name);

    char s1[512] = "-a-z 0-9 a-d-f -0-2 some text 1-1 WITH CAPITALS! 0-0 5-3 -";
    char s2[512];
    expand(s1, s2);
    printf("%s\n", s2);

    return 0;
}

/* reverse: reverse a string in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* expand: expand shorthand notation in s1 into the equivalent complete list in s2 */
void expand(char s1[], char s2[])
{
    int i, j;
    char temp;
    int dash;

    dash = 0;
    for (i = j = 0; s1[i] != '\0'; ++i)
    {
        if (s1[i] == '-')
        {
            if (i == 0 || s1[i+1] == '\0')  // '-' is leading or trailing, copy it
            {
                s2[j++] = s1[i];
            }
            else  // check if this is a valid range
            {
                if (validrange(s1[i-1], s1[i+1]))
                {
                    while (s2[j-1] < s1[i+1])
                    {
                        s2[j] = s2[j-1] + 1;
                        j++;
                    }
                    i++;  // skip the next character; we have already printed it
                }
                else // not a valid range, just copy
                {
                    s2[j++] = s1[i];
                }
            }
        }
        else
        {
            s2[j++] = s1[i];
        }
    }
}

/* validrange: return non-zero if c1-c2 is a valid range */
int validrange(char c1, char c2)
{
    if (('a' <= c1 && c1 <= 'z') &&  // valid range in a-z
        (c1 <= c2 && c2 <= 'z'))
        return TRUE;
    if (('A' <= c1 && c1 <= 'Z') &&  // valid range in A-Z
        (c1 <= c2 && c2 <= 'Z'))
        return TRUE;
    if (('0' <= c1 && c1 <= '9') &&  // valid range in 0-9
        (c1 <= c2 && c2 <= '9'))
        return TRUE;

    return FALSE;  // not a valid range
}
