#include <stdio.h>
#include <string.h>

void squeeze_char(char s[], int c);
void strconcat(char s[], char t[]);
void squeeze_str(char s1[], char s2[]);
int any(const char s1[], const char s2[]);

int main(void)
{
    char s1[] = "albex";
    squeeze_char(s1, 'b');
    printf("%s\n", s1);

    char s2[] = "andros";
    strconcat(s1, s2);
    printf("%s, len = %d\n", s1, strlen(s1));

    squeeze_str(s1, "spiros");
    printf("%s, len = %d\n", s1, strlen(s1));

    printf("%d\n", any("george", "mark"));

    return 0;
}

/* squeeze: delete all c from s */
void squeeze_char(char s[], int c)
{
    int i,j;

    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

/* squeeze_v2: delete each character in s1 that matches any character in s2 */
void squeeze_str(char s1[], char s2[])
{
    // without using squeeze_char
    /*
    int i, j, k;
    int match = 0;

    for (i = k = 0; s1[i] != '\0'; i++)  // loop through s1
    {
        match = 0;
        for (j = 0; s2[j] != '\0'; j++) // loop through s2
        {
            if (s1[i] == s2[j])
            {
                match = 1;
                break;
            }
        }
        if (!match)
        {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
    */

    // using squeeze_char: more elegant
    int i;
    for (i = 0; s2[i] != '\0'; ++i)
    {
        squeeze_char(s1, s2[i]);
    }
}

/* strcat: concatenate t to the end of s; s must be big enough */
void strconcat(char s[], char t[])
{
    int i, j;
    // find the end of s
    for (i = 0; s[i] != '\0'; i++)
        ;
    // copy t to the end of s
    for (j = 0; (s[i++] = t[j++]) != '\0';)
        ;
}

/* any: return the first location in the string s1 where any character from
the string s2 occurs */
int any(const char s1[], const char s2[])
{
    int i,j;
    for (i = 0; s1[i] != '\0'; ++i)
    {
        for (j = 0; s2[j] != '\0'; ++j)
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
        }
    }
    return -1;
}
