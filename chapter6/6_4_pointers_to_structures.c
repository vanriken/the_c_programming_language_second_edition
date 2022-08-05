/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../chapter4/getch_ungetch.c"
#define MAXWORD 100

// declare a structure type "key"
struct key {
    char *word;
    int count;
};

// declare an array of structs
struct key keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "struct", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
};

#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))

int getword(char *, int);
// declaration of binsearch must denote that it returns a pointer to struct key
struct key *binsearch(char *, struct key *, int);

/* count c keywords: pointer version */
int main(void)
{
    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            if ((p = binsearch(word, keytab, NKEYS)) != NULL)
            {
                p->count++;
            }
        }
    }
    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1]
   if binsearch finds the word, it returns a pointer to it
   if it fails, it returns NULL */
struct key *
binsearch(char *word, struct key *tab, int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low <= high)
    {
        mid = low + (high-low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid-1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c;
    char *w = word;

    while (isspace(c = getch()))  // skip the white space
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
