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
#include <stdlib.h> // EXIT_SUCCESS and EXIT_FAILURE

struct nlist
{
        struct nlist *next;     // next entry in the chain
        char *name;             // defined name
        char *defn;             // replacement text
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];  // pointer table

unsigned hash(char *);
struct nlist *lookup(char *);
char *strdupl(char *);
struct nlist *install(char *, char *);


int main(void)
{
    struct nlist *np;

    np = install("MAX", "255");
    np = install("PROCESSOR", "STM32F3");

    if ((np = lookup("MAX")) != NULL)
    {
        printf("name: %s\n", np->name);
        printf("defn: %s\n", np->defn);
    }

    if ((np = lookup("MIN")) != NULL)
    {
        printf("name: %s\n", np->name);
        printf("defn: %s\n", np->defn);
    }

    if ((np = lookup("PROCESSOR")) != NULL)
    {
        printf("name: %s\n", np->name);
        printf("defn: %s\n", np->defn);
    }


    return EXIT_SUCCESS;
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    {
        if (strcmp(s, np->name) == 0)
        {
            return np;  // entry found
        }
    }
    return NULL;  // entry not found
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL)  // not found
    {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdupl(name)) == NULL)
        {
            return NULL;  // no room for a new entry
        }
        hashval = hash(name);
        // np.next becomes a pointer to the struct that is currently at the beginning of the linked list
        np->next = hashtab[hashval];
        // the current struct is then inserted at the beginning of the linked list
        hashtab[hashval] = np;
    }
    else
    {
        free((void *) np->defn);
    }
    if ((np->defn = strdupl(defn)) == NULL)
    {
        return NULL;  // no room for the replacement text
    }
    return np;
}

/* strdupl: make a duplicate of s */
char *strdupl(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s)+1);  // +1 for string null-terminator
    if (p != NULL)                     // malloc returns NULL when no space is available
    {
        strcpy(p, s);
    }
    return p;
}
