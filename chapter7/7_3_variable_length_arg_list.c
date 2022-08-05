/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/

#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

void minprintf(char *fmt, ...);

int main(int argc, char *argv[])
{
    minprintf("%d is my %s", 16, "favourite number");
    return EXIT_SUCCESS;
}

/*
Type va_list is used to declare a variable that will refer to each arg in return
In minprintf, this variables is called ap (argument pointer).
*/

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
    va_list ap;  // points to each unnamed arg in turn
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);  // make ap point to first unnamed arg
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }

        switch (*++p)
        {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                {
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);  // clean up, must be called before function returns
}
