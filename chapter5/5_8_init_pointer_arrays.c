/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>

char *month_name(int n);

int main(void)
{
    for (int i = 0; i <= 12; i++)
        printf("%s\n", month_name(i));
    return 0;
}

char *month_name(int n)
{
    // an array of char pointers
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}
