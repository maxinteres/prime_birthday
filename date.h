#ifndef DATE_H
#define DATE_H

#define leap_year(year) ((year)%400==0||(((year)%4==0&&(year)%100!=0)))
typedef unsigned long ul;
typedef struct date {
  unsigned int year;
  unsigned int month;
  unsigned int date;
} Date;
char legal_date(Date *);
Date ul2Date(ul);

#endif
