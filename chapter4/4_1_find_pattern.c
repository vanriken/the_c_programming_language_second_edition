#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "d";

/* find all lines matching a pattern */
int main(void)
{
    char line[MAXLINE];
    int found = 0;
    int index = -1;

    while (getline(line, MAXLINE) > 0)
    {
        // left most occurence of pattern in line
        if ((index = strindex(line, pattern)) >= 0)
        {
            printf("%s", line);
            printf("index: %d\n", index);
            found++;
        }

        // rightmost occurence of pattern in line
        if ((index = strrindex(line, pattern)) >= 0)
        {
            printf("%s", line);
            printf("index: %d\n", index);
        }
    }
    return found;
}

/* getline: get line into s return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        {
            ;
        }
        if (k > 0 && t[k] == '\0')
        {
            return i;
        }
    }
    return -1;
}

/* strrindex: return rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k, rindex;

    rindex = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        // check if t starts at this index in s
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        {
            ;
        }
        if (k > 0 && t[k] == '\0')  // t is present starting at index i
        {
            rindex = i;  // replace rindex with our find
        }
    }
    return rindex;
}
