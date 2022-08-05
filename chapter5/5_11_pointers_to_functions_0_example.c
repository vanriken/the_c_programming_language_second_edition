/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:

***********************************************************************/
#include <stdio.h>

void hello(const char *name)
{
    printf("Hello %s\n", name);
}

void get_name_and_greet(void (*hello_function)(const char *))
{
    char name[256];
    printf("Please enter name: ");
    scanf("%255s", name);

    hello_function(name);  // Use the function pointer
}

int main(void)
{
    get_name_and_greet(&hello);  // Pass a pointer to the function
    get_name_and_greet(hello);  // Pass a pointer to the function
}
