#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct PlayClock020ac614;
void AddPlayClockHours020ac614(struct PlayClock020ac614* clock, int amount);

struct PlayClock020ac644;
void AddPlayClockMinutes020ac644(struct PlayClock020ac644* clock, int amount);

extern "C" void func_020ac6b8(void* clock, int amount);

struct TimeStamp020103f0;
void ComputeElapsedPlayTimeHMS020103f0(struct TimeStamp020103f0* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);

struct TimeStamp020104cc;
void ComputeElapsedPlayTimeHMS020104cc(struct TimeStamp020104cc* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);

int LoadBattleBlock020ac4c0(void* dst);
int CopyInBattleField0x7540(void* src);

unsigned long long GetCurrentTimestamp(void);

// USA: func_020ac4f8
ARM int UpdatePlayClocks020ac4f8(int commit) {
    struct BattleStruct *battle;
    unsigned char buf[0xb0];
    unsigned short hours;
    unsigned char minutes;
    unsigned char seconds;
    unsigned long long ts;
    void *buf2;

    battle = GetBattleStruct();
    LoadBattleBlock020ac4c0(buf);

    hours = 0;
    minutes = 0;
    seconds = 0;
    buf2 = buf + 0x68;
    ComputeElapsedPlayTimeHMS020103f0((struct TimeStamp020103f0*)battle, &hours, &minutes, &seconds);

    AddPlayClockHours020ac614((struct PlayClock020ac614*)(buf + 0), hours);
    AddPlayClockMinutes020ac644((struct PlayClock020ac644*)(buf + 0), minutes);
    func_020ac6b8(buf + 0, seconds);

    AddPlayClockHours020ac614((struct PlayClock020ac614*)buf2, hours);
    AddPlayClockMinutes020ac644((struct PlayClock020ac644*)buf2, minutes);
    func_020ac6b8(buf2, seconds);

    ts = GetCurrentTimestamp();
    *(unsigned int*)((char*)battle + 0x3e8) = (unsigned int)ts;
    *(unsigned int*)((char*)battle + 0x3ec) = (unsigned int)(ts >> 32);

    if (commit != 0) {
        void *buf1b;
        ComputeElapsedPlayTimeHMS020104cc((struct TimeStamp020104cc*)battle, &hours, &minutes, &seconds);
        buf1b = buf + 4;

        AddPlayClockHours020ac614((struct PlayClock020ac614*)buf1b, hours);
        AddPlayClockMinutes020ac644((struct PlayClock020ac644*)buf1b, minutes);
        func_020ac6b8(buf1b, seconds);

        AddPlayClockHours020ac614((struct PlayClock020ac614*)((char*)buf2 + 4), hours);
        AddPlayClockMinutes020ac644((struct PlayClock020ac644*)((char*)buf2 + 4), minutes);
        func_020ac6b8((char*)buf2 + 4, seconds);

        ts = GetCurrentTimestamp();
        *(unsigned int*)((char*)battle + 0x3f0) = (unsigned int)ts;
        *(unsigned int*)((char*)battle + 0x3f4) = (unsigned int)(ts >> 32);
    }

    return CopyInBattleField0x7540(buf);
}
