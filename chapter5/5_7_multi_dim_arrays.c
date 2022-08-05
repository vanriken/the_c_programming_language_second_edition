/***********************************************************************

    filename:       filename.c

    author:         Alexandros Rikos
    date:           YYYY-MM-DD

    description:

    comments:       Static vs Global variables:
                    https://stackoverflow.com/questions/2271902/static-vs-global

***********************************************************************/
#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    int year = 2020;
    int nday = 160;

    // what is the 152nd day of 2022
    int month;
    int day;
    month_day(year, nday, &month, &day);
    printf("month: %d, day: %d\n", month, day);

    // does day of year give the correct result
    printf("Day of year: %d", day_of_year(year, month, day));
    return 0;
}

// two dimensional array for leap years and non-leap years
// char can be used to store small-size integers
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    // error checking negative inputs
    if (month < 1 || day < 1)
    {
        printf("Error: month and day must be positive\n");
        return -1;
    }
    // error checking month
    if (month > 12)
    {
        printf("Error: a year has 12 months, choose a number between 1 and 12.\n");
        return -2;
    }
    // error checking day
    if (day > daytab[leap][month])
    {
        printf("Error: the %d month has %d days.\n", month, daytab[leap][month]);
        return -3;
    }


    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    // error checking negative days
    if (yearday < 1)
    {
        // Reset the provided month and day.
        *pmonth = 0;
        *pday = 0;
        printf("Error: parameter yearday must be positive.\n");
        return;
    }
    // error checking maximum days
    if ((!leap && yearday > 365) || (leap && yearday > 366))
    {
        // Reset the provided month and day.
        *pmonth = 0;
        *pday = 0;
        printf("Error: year %d has %d days.\n", year, leap ? 366 : 365);
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}
