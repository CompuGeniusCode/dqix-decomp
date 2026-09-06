#include <globaldefs.h>

struct TimeOfDay020cfaf4 {
    int hours;
    int minutes;
    int seconds;
};

// USA: func_020cfaf4
#pragma optimize_for_size off
ARM void SplitSecondsIntoTimeOfDay(struct TimeOfDay020cfaf4* out, int time) {
    if (time < 0) time = 0;
    if (time > 86399) time = 86399;
    out->seconds = time % 60;
    time /= 60;
    out->minutes = time % 60;
    time /= 60;
    out->hours = time;
}
