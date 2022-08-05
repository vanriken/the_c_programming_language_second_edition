#include <stdio.h>
#include <ctype.h>  // isspace() and isdigit()
#include <math.h>  // pow()

#define MAXLINE 1000

// function prototypes
double atof42(char s[]);
int atoi42(char s[]);
int getline(char s[], int lim);

int main(void)
{
    char line[MAXLINE];
    char s[] = "123.25";
    double sum;

    // test atof and atoi with s as input
    printf("%f\n", atof42(s));
    printf("%d\n", atoi42(s));

    printf("*** Primitive Calculator ***\n");

    sum = 0;
    while (getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof42(line));
    return 0;
}

/* atof: convert string s to double */
double atof42(char s[])
{
    double val, power, exp;
    int i, sign, esign;

    for (i = 0; isspace(s[i]); i++)  // skip the white space
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)  // integer part
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
    {
        i++;
        for (power = 1.0; isdigit(s[i]); i++)  // fraction
        {
            val = 10.0 * val + (s[i] - '0');
            power *= 10.0;
        }
        val *= sign / power;
    }
    if (s[i] == 'e' || s[i] == 'E')  // exponent
    {
        esign = (s[i++] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0.0; isdigit(s[i]); i++)
            exp = 10.0 * exp + (s[i] - '0');
        val = val * pow(10, esign * exp);
    }

    return val;
}

/* atoi: convert string to integer using atof */
int atoi42(char s[])
{
    return (int) atof42(s);
}

/* getline: get line into s return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}
