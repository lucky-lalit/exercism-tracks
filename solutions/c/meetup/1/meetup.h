#ifndef MEETUP_H
#define MEETUP_H

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week);

int last(unsigned int year, unsigned int month, int day);
int teenth(unsigned int year, unsigned int month, int day);
int first_to_fourth(unsigned int year, unsigned int month, int day,const char *week);

#endif
