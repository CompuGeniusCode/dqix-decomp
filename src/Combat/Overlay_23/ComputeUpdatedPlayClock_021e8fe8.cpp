#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct PlayClock020ac614 { unsigned short hours; unsigned char minutes; unsigned char seconds; };
void AddPlayClockHours020ac614(struct PlayClock020ac614* clock, int amount);

struct PlayClock020ac644 { unsigned short hours; unsigned char minutes; unsigned char seconds; };
void AddPlayClockMinutes020ac644(struct PlayClock020ac644* clock, int amount);

struct TimeStamp020103f0;
void ComputeElapsedPlayTimeHMS020103f0(struct TimeStamp020103f0* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);

struct TimeStamp020104cc;
void ComputeElapsedPlayTimeHMS020104cc(struct TimeStamp020104cc* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);

extern "C" void* func_0202ae18(void);
int GetFieldAt0x0(int* obj);

extern "C" int _s32_div_f(int a, int b);

// USA: func_ov023_021e8fe8  (semantic: ComputeUpdatedPlayClock_021e8fe8)
extern "C" ARM struct PlayClock020ac614 func_ov023_021e8fe8(struct PlayClock020ac614 clock, int flag) {
    struct BattleStruct* battle = GetBattleStruct();
    struct PlayClock020ac614 result;
    unsigned short tHours;
    unsigned char tMinutes;
    unsigned char tSeconds;

    tHours = 0;
    tMinutes = 0;
    tSeconds = 0;
    result.hours = 0;
    result.minutes = 0;
    result.seconds = 0;

    if (flag == 0) {
        ComputeElapsedPlayTimeHMS020103f0((struct TimeStamp020103f0*)battle, &tHours, &tMinutes, &tSeconds);
    } else {
        void* ptr = func_0202ae18();
        int val = GetFieldAt0x0((int*)ptr);
        int byteVal = *((unsigned char*)ptr + 0x100d);
        if ((val == 5 && byteVal > 1) || val == 6) {
            ComputeElapsedPlayTimeHMS020104cc((struct TimeStamp020104cc*)battle, &tHours, &tMinutes, &tSeconds);
        } else {
            tHours = 0;
            tMinutes = 0;
            tSeconds = 0;
        }
    }

    AddPlayClockHours020ac614(&result, (unsigned short)(clock.hours + tHours));
    AddPlayClockMinutes020ac644((struct PlayClock020ac644*)&result, (unsigned char)(clock.minutes + tMinutes));

    result.seconds = result.seconds + (unsigned char)(clock.seconds + tSeconds);
    unsigned char secs = result.seconds;
    if (secs > 0x3b) {
        unsigned char carry = secs / 0x3c;
        if (result.hours == 0x270f) {
            int m = result.minutes + carry;
            if (m > 0x3b) {
                result.hours = 0x270f;
                result.minutes = 0x3b;
                result.seconds = 0x3b;
                goto done;
            }
        }
        AddPlayClockMinutes020ac644((struct PlayClock020ac644*)&result, carry);
        result.seconds = result.seconds % 0x3c;
    }
done:
    return result;
}
