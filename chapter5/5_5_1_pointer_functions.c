/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <string.h>

void strcpy1(char *, char *);
void strcpy2(char *, char *);
void strcpy3(char *, char *);
void strcpy4(char *, char *);

int strcmp1(char *, char *);
int strcmp2(char *, char *);

void strcat1(char *, char *);
void strcat2(char *, char *);

int strend(char *, char *);

void strncpy1(char *s, char *t, int n);
void strncat1(char *s, char *t, int n);
int strncmp1(char *s, char *t, int n);

int main(void)
{
    char s1[32] = "Alexandros";
    char s2[32];

    // strcpy
    strcpy4(s2, s1);
    printf("strcpy: %s\n", s2);

    // strcmp
    printf("strcmp: %d\n", strcmp1("A", "B"));

    // strcat
    strcat2(s1, s2);
    printf("strcat: %s\n", s1);

    // strend
    printf("strend: %d\n", strend("Alexandros","dros"));

    printf("\n");

    // strncpy
    strncpy1(s2, s1, 4);
    printf("strncpy: %s\n", s2);

    // strncat
    strncat1(s1, s2, 2);
    printf("strncat: %s\n", s1);

    // strncmp1
    printf("strncmp: %d\n", strncmp1( "Alexa", "Alexios", 4));  // should return 0
    printf("strncmp: %d\n", strncmp1( "Alexa", "Alexios", 5));  // should return <0
    return 0;


}

/* strcpy1: copy t to s; array subscript version */
void strcpy1(char *s, char *t)
{
    int i = 0;
    while((s[i] = t[i]) != '\0')
        i++;
}

/* strcpy2: copy t to s; pointer version 2 */
void strcpy2(char *s, char *t)
{
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }

}

/* strcpy3: copy t to s; pointer version 3 */
void strcpy3(char *s, char *t)
{
    // increment s and t inside the test part of the loop
    while ((*(s++) = *(t++)) != '\0')
        ;
}

/* strcpy3: copy t to s; pointer version 4 */
void strcpy4(char *s, char *t)
{
    // comparison against '\0' is redundant since the value of '\0' is zero
    while ((*(s++) = *(t++)))
        ;
}

/* strcmp1: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp1(char *s, char *t)
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

/* strcmp2: return <0 if s<t, 0 if s==t, >0 if s>t; pointer version */
int strcmp2(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

/* strcat1: concatenate t to the end of s; s must be big enough */
void strcat1(char s[], char t[])
{
    int i, j;
    // find the end of s
    for (i = 0; s[i] != '\0'; i++)
        ;
    // copy t to the end of s
    for (j = 0; (s[i++] = t[j++]) != '\0';)
        ;
}

/* strcat2: concatenate t to the end of s; pointer version */
void strcat2(char *s, char *t)
{
    // find the end of s
    while (*s)
        s++;
    // copy t to the end of s
    while (*t)
        *(s++) = *(t++);
    // add string terminator
    *s = '\0';
}

/* strend: returns 1 if t occurs at the end of s, and zero otherwise */
int strend(char *s, char *t)
{
    int ls, lt;
    for (ls = 0; *(s+ls); ls++);  // find length of s
    for (lt = 0; *(t+lt); lt++);  // find length of t

    if (ls > lt)
    {
        s = s + (ls - lt);  // point s to where t should start
        while (*s++ == *t++)
        {
            if (*s == '\0')  // we found the end of s and therefore the end of t
                return 1;
        }
    }
    return 0;
}


/* strncpy1: copies the first n characters from t to s */
void strncpy1(char *s, char *t, int n)
{
    while (*t && n-- > 0)
        *s++ = *t++;
    *s = '\0';
}

/* strncat1: concatenates n characters of t to s */
void strncat1(char *s, char *t, int n)
{
    // find the end of s
    while (*s)
        s++;
    while (*t && n-- > 0)
        *s++ = *t++;
    *s = '\0';
}

/* strncmp1: return <0 if s<t, 0 if s==t, >0 if s>t; operate on first n characters */
int strncmp1(char *s, char *t, int n)
{
    int i = 0;
    for (; *s == *t && n-- > 0; *s++, *t++)
        if (*s == '\0' || n == 0)
            return 0;
    return *s - *t;
}
