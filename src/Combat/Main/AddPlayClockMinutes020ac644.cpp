#include <globaldefs.h>

struct PlayClock020ac614;
void AddPlayClockHours020ac614(struct PlayClock020ac614* clock, int amount);

struct PlayClock020ac644 {
    unsigned short hours;
    unsigned char minutes;
    unsigned char seconds;
};

// USA: func_020ac644
ARM void AddPlayClockMinutes020ac644(struct PlayClock020ac644* clock, int amount) {
    clock->minutes = clock->minutes + amount;
    unsigned char mins = clock->minutes;
    if (mins <= 0x3b) return;

    unsigned short carryHours = mins / 0x3c;
    if ((int)(clock->hours + carryHours) > 0x270f) {
        clock->hours = 0x270f;
        clock->minutes = 0x3b;
        clock->seconds = 0x3b;
        return;
    }

    AddPlayClockHours020ac614((struct PlayClock020ac614*)clock, carryHours);
    clock->minutes = clock->minutes % 0x3c;
}
