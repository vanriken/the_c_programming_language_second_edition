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
#include <stdlib.h>

enum modes {TO_LOWER, TO_UPPER};

int main(int argc, char *argv[])
{
    enum modes mode = TO_LOWER;
    int c;

    switch (argc)
    {
        case 1:
            break;
        case 2:
            if (strcmp(argv[1], "lower") == 0)
            {
                mode = TO_LOWER;
            }
            else if (strcmp(argv[1], "upper") == 0)
            {
                mode = TO_UPPER;
            }
            else
            {
                printf("Error. Invalid argument.\n");
                return(EXIT_FAILURE);
            }
            break;
        default:
            printf("Too many arguments.\n");
            return(EXIT_FAILURE);
    }


    while ((c = getchar()) != EOF)
    {
        if (mode == TO_LOWER)
        {
            putchar(tolower(c));
        }
        else
        {
            putchar(toupper(c));
        }

    }
    return EXIT_SUCCESS;
}
