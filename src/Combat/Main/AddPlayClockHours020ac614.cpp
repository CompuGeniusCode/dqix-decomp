#include <globaldefs.h>

struct PlayClock020ac614 {
    unsigned short hours;
    unsigned char minutes;
    unsigned char seconds;
};

// USA: func_020ac614
ARM void AddPlayClockHours020ac614(struct PlayClock020ac614* clock, int amount) {
    clock->hours += amount;
    if (clock->hours > 0x270f) {
        clock->hours = 0x270f;
        clock->minutes = 0x3b;
        clock->seconds = 0x3b;
    }
}
