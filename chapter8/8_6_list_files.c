/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>
#include <dirent.h>
#include <inttypes.h>

/*
*   The <dirent.h> header defines the following data type through typedef:
*
*   DIR: A type representing a directory stream.
*
*   It also defines the structure dirent which includes the following members:
*   ino_t  d_ino       file serial number
*   char   d_name[]    name of entry
*/

// dirent.h - https://pubs.opengroup.org/onlinepubs/7908799/xsh/dirent.h.html
// opendir - https://pubs.opengroup.org/onlinepubs/7908799/xsh/opendir.html
// readdir - https://pubs.opengroup.org/onlinepubs/7908799/xsh/readdir.html
// closdir - https://pubs.opengroup.org/onlinepubs/7908799/xsh/closedir.html

int main(int argc, char **argv)
{
    DIR *dir;  // pointer to a directory stream
    struct dirent *de;

    dir = opendir("."); /*your directory*/
    while(dir)
    {
        de = readdir(dir);
        if (!de)
            break;
        printf("name: %s\n", de->d_name);
    }
    closedir(dir);
    return 0;
}
