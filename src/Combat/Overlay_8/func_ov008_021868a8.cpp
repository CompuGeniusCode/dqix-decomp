#include <globaldefs.h>

extern "C" void* _Z15GetBattleStructv();
extern "C" int* _Z10GetWord0x0Pi(void* battle);
void SetBothCounters(void* obj, int value, int frames);
extern "C" void func_0203b19c(void* obj, int a, int b);
extern "C" int _Z28CheckField0x14Or0x20PositivePi(int* word);
int IsAnimationActive0209ca2c(void* obj);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(void* p, int flag);

struct ShortField0xb8_0209cae8;
short GetShortAt0xb8(struct ShortField0xb8_0209cae8* obj);

struct Actor0209c678;
void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);

extern int data_02109bf4;

struct Obj021868a8 {
    char pad0[0xb10];
    unsigned char b10;
    unsigned char b11;
    char pad1;
    unsigned char b13;
    char pad2[0xb24 - 0xb14];
    int b24;
};

// USA: func_ov008_021868a8
extern "C" ARM void func_ov008_021868a8(struct Obj021868a8* obj) {
    int* word = _Z10GetWord0x0Pi(_Z15GetBattleStructv());
    unsigned char flag = obj->b11;
    if (flag == 0) {
        if (obj->b24 == 0) {
            SetBothCounters(word, -16, 15);
            if (obj->b13 == 0) {
                if (GetShortAt0xb8((struct ShortField0xb8_0209cae8*)&data_02109bf4) != 0x29) {
                    DispatchContextByState0209c678((struct Actor0209c678*)&data_02109bf4, 15);
                }
            }
        } else {
            func_0203b19c(word, -16, 15);
        }
        obj->b11 = obj->b11 + 1;
        return;
    }
    if (flag != 1) return;
    if (_Z28CheckField0x14Or0x20PositivePi(word) != 0) return;
    if (IsAnimationActive0209ca2c(&data_02109bf4) != 0) return;
    _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((char*)obj + 0x130, 1);
    obj->b10 = 0xe;
    obj->b11 = 0;
}
