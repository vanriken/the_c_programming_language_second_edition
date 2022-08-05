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

#include "../chapter4/getch_ungetch.c"

struct tnode {              // the tree node
    char *word;             // points to the text
    int count;              // number of occurences
    struct tnode *left;     // pointer to left child
    struct tnode *right;    // pointer to right child
};

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode *talloc(void);
char *strdupl(char *);


int main(void)
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return EXIT_SUCCESS;
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


/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL)          // a new word has arrived
    {
        p = talloc();       // make a new node
        p->word = strdupl(w);
        p->count = 1;
        p->left = NULL;
        p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count++;         // repeated word
    }
    else if (cond < 0)  	// go into the left subtree
    {
        p->left = addtree(p->left, w);
    }
    else                    // go into the right subtree
    {
        p->right = addtree(p->right, w);
    }
    return p;
}


/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}


/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
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

// storage obtained by calling malloc may be freed for re-use by calling free.
