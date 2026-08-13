#include <globaldefs.h>

struct BattleStruct;
struct BattleStruct* GetBattleStruct();
int GetWord0x0(int* obj);
void SetBothCounters(void* obj, int value, int frames);
int CheckField0x14Or0x20Positive(int* obj);

struct Struct0215b0fc {
    unsigned char pad0[0x10];
    void* f10;
    unsigned char pad1[0x38f - 0x14];
    unsigned char f38f;
    unsigned char f390;
    unsigned char pad2[0x394 - 0x391];
    unsigned short f394;
    unsigned char pad3[0x397 - 0x396];
    unsigned char f397;
};

// USA: func_ov006_0215b0fc
extern "C" ARM void func_ov006_0215b0fc(struct Struct0215b0fc* obj) {
    int ctx = GetWord0x0((int*)GetBattleStruct());
    unsigned char state = obj->f390;
    if (state == 0) {
        unsigned short flags = *(unsigned short*)((char*)obj->f10 + 0xae2);
        if (flags & 0x1008) {
            obj->f390 = state + 1;
        }
        return;
    }
    if (state == 1) {
        SetBothCounters((void*)ctx, 0, 8);
        obj->f390 = obj->f390 + 1;
        return;
    }
    if (state != 2) {
        return;
    }
    if (CheckField0x14Or0x20Positive((int*)ctx) != 0) {
        return;
    }
    obj->f38f = 4;
    obj->f390 = 0;
    if (obj->f394 & 2) {
        obj->f397 = 2;
        obj->f38f = 2;
    }
}
