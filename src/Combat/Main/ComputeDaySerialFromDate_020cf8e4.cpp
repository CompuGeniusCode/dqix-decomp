#include <globaldefs.h>

extern int data_020f2298[13];

struct DateFields_020cf8e4 {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    int weekday;
};

// USA: func_020cf8e4  (semantic: ComputeDaySerialFromDate_020cf8e4)
extern "C" ARM int func_020cf8e4(struct DateFields_020cf8e4* d) {
    unsigned int year, month, day;
    int weekday;
    if ((year = d->year) >= 100 || (month = d->month) < 1 || month > 12 ||
        (day = d->day) < 1 || day > 31 || (weekday = d->weekday) >= 7 ||
        month < 1 || month > 12) {
        return -1;
    }
    int days = (day - 1) + data_020f2298[month];
    if (month >= 3 && (year & 3) == 0) days++;
    return year * 365 + days + (year + 3) / 4;
}
