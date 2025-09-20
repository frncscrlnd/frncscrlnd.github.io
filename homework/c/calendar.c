#include <stdio.h>

//input
int input(){
    int year;
    printf("Input year: ");
    scanf("%d", &year);
    return year;
};

//array with all months days (excluding leap year)
int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

//strings array with all months
char *months[] = {
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember"
};

//determines whether the year is a leap year or not ((is it dividable by 4? AND is it NOT dividable by 100?) OR is it dividable by 400?)
int isLeapYear(int year)
{
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        daysInMonth[1] = 29;
    }
}

//determines the days of the week by calculating a daycode
int determineDayCode(int year)
{
    int dayCode;
    dayCode = (year + (year-1)/4 - (year-1)/100 + (year-1)/400) % 7;
    return dayCode;
}

//prints calendar
void calendar(int year, int dayCode)
{
    int month, day;
    for(month = 0; month <= 11; month++)
    {
        printf("%s", months[month]);
        printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for(day = 1; day <= 1 + dayCode * 5; day++)
        {
            printf(" ");
        }

        for(day = 1; day <= daysInMonth[month]; day++)
        {
            //if the day is less than 10 it will occupy on char less, so print out " " to make the spaces even
            if(day<10)
            {
                printf("%d ", day);
            }
            else
            {
                printf("%d", day);
            }

            if((day + dayCode) % 7 > 0)
            {
                printf("   ");
            }
            //when it reaches 0 (sunday), print new line
            else
            {
                printf("\n ");
            }
        }

        //reset daycode
        dayCode = (dayCode + daysInMonth[month]) % 7;
    }
}

int main(){

    //declare necessary variables
    int year, dayCode, leapyear;

    //execute functions
    year = input();
    dayCode = determineDayCode(year);
    isLeapYear(year);
    calendar(year, dayCode);

    //new line
    printf("\n");

}