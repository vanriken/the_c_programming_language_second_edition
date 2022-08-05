/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include "8_5_stdio.h"
#include <fcntl.h>
#include <unistd.h>  // instead of syscalls.h

#define PERMS 0666  // RW for owner, group, others
#define _READ 01
#define _WRITE 02

/* my_fopen: open file, return file pointer */
FILE *my_fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    {
        return NULL;
    }
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
    {
        if ((fp->flag & (_READ | _WRITE)) == 0)
        {
            break;  // found free slot
        }
    }
    if (fp >= _iob + OPEN_MAX)  // no free slots
    {
        return NULL;
    }

    if (*mode == 'w')
    {
        fd = creat(name, PERMS);
    }
    else if (*mode == 'a')
    {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
        {
            fd = creat(name, PERMS);
        }
        lseek(fd, 0L, 2);
    }
    else
    {
        fd = open(name, O_RDONLY, 0);
    }

    if (fd == -1)  // could not access name
    {
        return NULL;
    }
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}
