#include <globaldefs.h>

void* GetBattleStruct(void);
extern "C" void func_0205d0e0(void* obj, int val);
struct TimeStamp020103f0;
void ComputeElapsedPlayTimeHMS020103f0(struct TimeStamp020103f0* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);
struct PlayClock020ac614;
void AddPlayClockHours020ac614(struct PlayClock020ac614* clock, int amount);
struct PlayClock020ac644;
void AddPlayClockMinutes020ac644(struct PlayClock020ac644* clock, int amount);
struct ShortBytePair021e71a0;
void ClearShortAndTwoBytes_021e71a0(struct ShortBytePair021e71a0* p);
class PMFObj021e7c58;
void DispatchEntryByIndex_021e7c58(PMFObj021e7c58* obj, unsigned int selector, int idx);

// USA: func_ov023_021e7404
extern "C" ARM void func_ov023_021e7404(char* obj, int amount) {
    int useAmount = amount;
    if (useAmount == 0) useAmount = 1;

    if (*(int*)(obj + 0x5dc) == 0) {
        return;
    }

    func_0205d0e0(obj + 0x78, useAmount);
    *(int*)0x4001010 = 0;

    if (*(int*)(obj + 0x3c) == 0) {
        void* battleStruct = GetBattleStruct();
        char* savedClock = (char*)battleStruct + 0x104 + 0x7400;
        int firstTime = 0;
        unsigned char prevField610 = *(unsigned char*)(obj + 0x610);

        unsigned short hoursOut;
        unsigned char secondsOut;
        unsigned char minutesOut;
        hoursOut = 0;
        minutesOut = 0;
        secondsOut = 0;

        if (*(unsigned short*)(obj + 0x60e) == 0 && *(unsigned char*)(obj + 0x610) == 0) {
            firstTime = 1;
        }

        battleStruct = GetBattleStruct();
        ComputeElapsedPlayTimeHMS020103f0((struct TimeStamp020103f0*)battleStruct, &hoursOut, &minutesOut, &secondsOut);

        ClearShortAndTwoBytes_021e71a0((struct ShortBytePair021e71a0*)(obj + 0x60e));

        unsigned short savedHours = *(unsigned short*)(savedClock + 0x3c);
        AddPlayClockHours020ac614((struct PlayClock020ac614*)(obj + 0x60e), (unsigned short)(savedHours + hoursOut));

        unsigned char savedMinutes = *(unsigned char*)(savedClock + 0x3e);
        AddPlayClockMinutes020ac644((struct PlayClock020ac644*)(obj + 0x60e), (unsigned char)(savedMinutes + minutesOut));

        unsigned char savedSeconds = *(unsigned char*)(savedClock + 0x3f);
        *(unsigned char*)(obj + 0x611) = *(unsigned char*)(obj + 0x611) + (unsigned char)(savedSeconds + secondsOut);

        if (*(unsigned char*)(obj + 0x611) > 0x3b) {
            unsigned char carryMinutes = *(unsigned char*)(obj + 0x611) / 60;

            if (*(unsigned short*)(obj + 0x60e) == 0x270f) {
                int newField610 = *(unsigned char*)(obj + 0x610) + carryMinutes;
                if (newField610 > 0x3b) {
                    *(short*)(obj + 0x60e) = 0x270f;
                    *(unsigned char*)(obj + 0x610) = 0x3b;
                    *(unsigned char*)(obj + 0x611) = 0x3b;
                    goto afterMinuteCarry;
                }
            }

            AddPlayClockMinutes020ac644((struct PlayClock020ac644*)(obj + 0x60e), carryMinutes);
            *(unsigned char*)(obj + 0x611) = *(unsigned char*)(obj + 0x611) % 60;
        }
afterMinuteCarry:

        int cond;
        if (firstTime != 0) {
            cond = 1;
        } else {
            cond = (prevField610 != *(unsigned char*)(obj + 0x610)) ? 1 : 0;
        }
        if (cond != 0) {
            DispatchEntryByIndex_021e7c58((PMFObj021e7c58*)obj, 0, 0);
        }
    }

    *(int*)(obj + 0x5e8) = *(int*)(obj + 0x5e8) - (useAmount << 11);
    *(int*)(obj + 0x5ec) = *(int*)(obj + 0x5ec) + (useAmount << 11);

    if (*(int*)(obj + 0x5e8) < -0x100000) {
        *(int*)(obj + 0x5e8) = *(int*)(obj + 0x5e8) + 0x100000;
    }
    if (*(int*)(obj + 0x5ec) > 0x100000) {
        *(int*)(obj + 0x5ec) = *(int*)(obj + 0x5ec) - 0x100000;
    }

    int secShifted = *(int*)(obj + 0x5ec) >> 12;
    *(int*)0x4001014 = ((*(int*)(obj + 0x5e8) >> 12) & 0x1ff) | ((0x1ff << 16) & (secShifted << 16));
}
