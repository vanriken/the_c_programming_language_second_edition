#include <stdio.h>

/* count characters in input */

// int main()
// {
//     long number_of_characters;
//     number_of_characters = 0;
//     while (getchar() != EOF)
//     {
//         ++number_of_characters;
//     }
//     printf("Number of characters: %ld\n", number_of_characters);
// }

int main()
{
    double number_of_characters;
    for (number_of_characters = 0; getchar() != EOF; ++number_of_characters)
    {
        ;
    }
    printf("Number of characters: %.0f\n", number_of_characters);
}
