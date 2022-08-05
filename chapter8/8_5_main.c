/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include "8_5_stdio.h"

// The array _iob must be defined and initialized for stdin, stdout and stderr
FILE _iob[OPEN_MAX] = {  // stdin, stdout, stderr
    {0, (char *) 0, (char *) 0, _READ, 0},
    {0, (char *) 0, (char *) 0, _WRITE, 1},
    {0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2},
};

int main(int argc, char *argv[])
{
    return 0;
}
