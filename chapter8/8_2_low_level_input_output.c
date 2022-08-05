/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/

#include <unistd.h>
#include <stdio.h>
int getchar_unbuffered(void);
int getchar_buffered(void);

int main() /* copy input to output */
{
    char buf[BUFSIZ];
    int n;

    // while ((n = read(0, buf, BUFSIZ)) > 0)
    // {
    //     write(1, buf, n);
    // }

    //printf("%c\n", getchar_unbuffered());

    printf("%c\n", getchar_buffered());
    printf("%c\n", getchar_buffered());
    printf("%c\n", getchar_buffered());

    return 0;
}

/* getchar_unbuffered: unbuffered single character input */
int getchar_unbuffered(void)
{
    char c;
    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

/* getchar_buffered: simple buffered version */
int getchar_buffered(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n;

    if (n == 0) // buffer is empty
    {
        n = read(0, buf, sizeof(buf));
        bufp = buf; // bufp points to start of buffer
    }

    // increment bufp for the next call to getchar
    // decrement n each time a char is handed out
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
