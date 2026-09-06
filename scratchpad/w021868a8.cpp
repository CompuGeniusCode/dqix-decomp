#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

ARM int GetWord0x0(int* obj);
ARM void SetBothCounters(void* obj, int value, int frames);
extern "C" void func_0203b19c(void* obj, int value, int frames);
ARM int CheckField0x14Or0x20Positive(int* obj);
ARM int IsAnimationActive0209ca2c(void* obj);
struct Entry_0205d6a0;
ARM void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);

struct ShortField0xb8_0209cae8;
ARM short GetShortAt0xb8(struct ShortField0xb8_0209cae8* obj);

struct Actor0209c678;
ARM void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);

extern int data_02109bf4;

struct Actor021868a8 {
    char pad0[0xb10];
    unsigned char f0xb10;
    unsigned char cnt;
    char pad1[0xb13 - 0xb12];
    unsigned char f0xb13;
    char pad2[0xb24 - 0xb14];
    int f0xb24;
};

// USA: func_021868a8
ARM void ProcessActor0xb11_021868a8(struct Actor021868a8* actor) {
    void* val = (void*)GetWord0x0((int*)GetBattleStruct());
    if (actor->cnt == 0) {
        if (actor->f0xb24 == 0) {
            SetBothCounters(val, -16, 15);
            if (actor->f0xb13 == 0) {
                if (GetShortAt0xb8((struct ShortField0xb8_0209cae8*)&data_02109bf4) != 0x29) {
                    DispatchContextByState0209c678((struct Actor0209c678*)&data_02109bf4, 15);
                }
            }
        } else {
            func_0203b19c(val, -16, 15);
        }
        actor->cnt++;
    } else {
        if (actor->cnt != 1) return;
        if (CheckField0x14Or0x20Positive((int*)val)) return;
        if (IsAnimationActive0209ca2c((void*)&data_02109bf4)) return;
        ResetEntryList0205d6a0((struct Entry_0205d6a0*)((char*)actor + 0x130), 1);
        actor->f0xb10 = 0xe;
        actor->cnt = 0;
    }
}
