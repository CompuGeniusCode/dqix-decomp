#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int HasAnyFlags_021719f8_021719f8(int* obj);
extern "C" void __clear(void* buf, int n);
extern "C" int func_ov000_02171a74(void* entry, char* buf);

struct Obj0203c108;
void SwapGlobalEntry0203c108(struct Obj0203c108* obj, char* fmt);

struct Entry021814bc {
    char pad0[0x28];
    int field28;
    char pad1[0x3c - 0x2c];
    int field3c;
    char pad2[0x4c - 0x40];
    int field4c;
    char pad3[0x448 - 0x50];
};

// USA: func_ov000_021814bc  (semantic: SwapReadyCombatEntries_021814bc)
extern "C" ARM void func_ov000_021814bc(char* obj) {
    char buf[0x80];
    struct Entry021814bc* entry;
    int i;
    (void)GetBattleStruct();
    for (i = 0; i < 4; i++) {
        entry = (struct Entry021814bc*)(obj + 0x958) + *(signed char*)(obj + i + 0x6c);
        if (entry->field4c < 0) continue;
        entry->field3c = entry->field28;
        if (!HasAnyFlags_021719f8_021719f8((int*)entry)) continue;
        __clear(buf, 0x80);
        if (func_ov000_02171a74(entry, buf) < 0) continue;
        SwapGlobalEntry0203c108((struct Obj0203c108*)((char*)entry + 0x50), buf);
    }
}
