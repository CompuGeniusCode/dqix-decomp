#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct FlagWord02046708 { unsigned int flags; };

void* GetDataPtr02114e04_020d6c00(void);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
int Forward020bbdcc(int a);
extern "C" int func_020ce89c(int a, int b, int c);
int GetGlobalWord02112140();
int DispatchIfEquals1(int a);
int GetWord0x0(int* obj);
void CancelActionIfHeadIdMatches_02199e98(void* obj);
int IsPowcntBit0Set(void);
struct Brightness0203b540;
void SetBrightnessRegisters0203b540(struct Brightness0203b540* obj);

// USA: func_02012de8  (semantic: HandleBrightnessOrDispatchState02012de8)
extern "C" ARM void func_02012de8(void) {
    struct FlagWord02046708* p1 = (struct FlagWord02046708*)GetDataPtr02114e04_020d6c00();
    int* p2 = (int*)func_0202ae18();

    int bit15 = (*(volatile unsigned short*)0x027fffa8 & 0x8000) >> 15;
    if (bit15) {
        if (CheckField0NonZero(p2) && !TestFlags02046708(p1, 0x1000000)) {
            goto skipFirst;
        }
        if (!TestFlags02046708(p1, 0x80)) {
            Forward020bbdcc(0);
            func_020ce89c(0xc, 0, 0);
            if (GetGlobalWord02112140() == 0) {
                Forward020bbdcc(0x7f);
            }
            return;
        }
    skipFirst:
        if (!TestFlags02046708(p1, 0x400000)) {
            DispatchIfEquals1(0);
        }
        if (!CheckField0NonZero(p2)) return;
        if (TestFlags02046708(p1, 0x1000000)) return;
        {
            int word = GetWord0x0((int*)GetBattleStruct());
            if (word == 0) return;
            CancelActionIfHeadIdMatches_02199e98((void*)word);
        }
        return;
    }

    if (IsPowcntBit0Set()) return;
    DispatchIfEquals1(1);
    {
        int word = GetWord0x0((int*)GetBattleStruct());
        if (word == 0) return;
        SetBrightnessRegisters0203b540((struct Brightness0203b540*)word);
    }
}
