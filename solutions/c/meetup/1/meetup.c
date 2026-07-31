#include "meetup.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week)
{
   const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int day = 0;
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(days[i],day_of_week) == 0)
            day = i;
    }
    int result = 0;
    
    if (strcmp(week,"teenth") == 0)
        result = teenth(year,month,day);
    
    else if ((strcmp(week,"first") == 0) || (strcmp(week,"second") == 0) || (strcmp(week,"third") == 0) || (strcmp(week,"fourth") == 0))
        result = first_to_fourth(year,month,day,week);
    
    else
        result = last(year,month,day);

    return result;
}

int last(unsigned int year, unsigned int month, int day)
{
    printf("last\n");
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    int last[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
    int result = 0;
    printf("debug\n");
    for (int i = 0; i < 31; i++)
    {
    date.tm_mday = last[i];
    mktime(&date);
    if (date.tm_wday == day && date.tm_mon + 1 == (int)month)
        result = last[i];
    }
    return result;

}

int teenth(unsigned int year, unsigned int month, int day)
{
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    // date.tm_isdst = -1;
    int teenth[7] = {13,14,15,16,17,18,19};
    for (int i = 0; i < 7; i++)
    {
    date.tm_mday = teenth[i];
    mktime(&date);
    if (date.tm_wday == day)
        return teenth[i];
    }
    return 0;
    
}

int first_to_fourth(unsigned int year, unsigned int month, int day,const char *week)
{
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    int four[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28};
    int count = 0;
    for (int i = 0; i < 28; i++)
    {
    date.tm_mday = four[i];
    mktime(&date);
    if (date.tm_wday == day)
    {
        count++;
        if (strcmp(week,"first") == 0)
            return four[i];
        else if (strcmp(week,"second") == 0 && count == 2)
            return four[i];
        else if (strcmp(week,"third") == 0 && count == 3)
            return four[i];
        else if (strcmp(week,"fourth") == 0 && count == 4)
            return four[i];
    }
    }
    return 0; 
}