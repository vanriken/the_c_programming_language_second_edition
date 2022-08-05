#include <stdio.h>
#include <string.h>

#define BUFFER 100

void escape(char s1[], char s2[]);
void escape_reverse(char s1[], char s2[]);

int main(void)
{
    char s1[BUFFER] = "This is a string with a tab\t and \n a new line.";
    char s2[BUFFER];

    printf("%s\n\n", s1);
    escape(s1, s2);

    printf("%s\n\n", s2);

    escape_reverse(s2, s1);
    printf("%s\n", s1);

    return 0;
}

/* escape: copies src into dst, converting newlines and tabs
into visible escape sequences */
void escape(char src[], char dst[])
{
    int i, j;

    for (i = j = 0; src[i] != '\0'; ++i)
    {
        switch (src[i])
        {
            case '\t':
                dst[j++] = '\\';
                dst[j++] = 't';
                break;

            case '\n':
                dst[j++] = '\\';
                dst[j++] = 'n';
                break;

            default:
                dst[j++] = src[i];
                break;
        }
    }
    dst[j] = '\0';
}

/* escape_reverse: copies src into dst, converting visible escape sequences
into the real characters */
void escape_reverse(char src[], char dst[])
{
    int i, j;

    for (i = j = 0; src[i] != '\0'; i++)
    {
        switch (src[i])
        {
            case '\\':
                switch (src[i+1])
                {
                    case 't':
                        dst[j++] = '\t';
                        i++;
                        break;

                    case 'n':
                        dst[j++] = '\n';
                        i++;
                        break;

                    default:
                        dst[j] = '\\';
                        j++;
                        break;
                }
                break;

            default:
                dst[j++] = src[i];
                break;
        }
    }
    dst[j] = '\0';
}
