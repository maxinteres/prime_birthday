#include "date.h"
static int days[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

char legal_date(Date *date) {
  if (date->year < 1900)
    return 0;
  if (date->month < 1 || date->month > 12)
    return 0;
  if (date->date > days[date->month])
    return 0;
  if (!leap_year(date->year) &&date->month == 2 &&date->date == 29)
    return 0;
  return 1;
}

Date ul2Date(ul num) {
  Date result_date;
  result_date.date = num % 100;
  result_date.month = (num / 100) % 100;
  result_date.year = num / 10000;
  return result_date;
}
