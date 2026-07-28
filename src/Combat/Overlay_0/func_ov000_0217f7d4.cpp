#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int HasAnyFlags_021719f8_021719f8(int* obj);
struct Struct02170fd0;
void CallHandlerIfF38Set02170fd0(struct Struct02170fd0* obj, int b);
void* GetFieldAt0x150(unsigned char* obj);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

struct Entry0217f7d4 {
    char pad0[0x18];
    signed char field18;
    char pad2[0x24 - 0x19];
    unsigned char field24;
    char pad3[0x4c - 0x25];
    int field4c;
    char pad4[0x87 - 0x50];
    unsigned char field87;
    char pad5[0x445 - 0x88];
    unsigned char field445;
    char pad6[0x448 - 0x446];
};

// USA: func_ov000_0217f7d4  (semantic: FindReadyCombatantId_0217f7d4)
extern "C" ARM int func_ov000_0217f7d4(char* obj) {
    int result = -1;
    struct BattleStruct* bs = GetBattleStruct();
    struct Entry0217f7d4* entry;
    for (int i = 0; i < 4; i++) {
        signed char idx = *(signed char*)(obj + 0x6c + i);
        entry = (struct Entry0217f7d4*)(obj + 0x958) + idx;
        if (entry->field4c < 0) continue;
        if (entry->field87 == 0) continue;
        if (HasAnyFlags_021719f8_021719f8((int*)entry)) continue;
        if (entry->field445 == 0) continue;

        if (*(int*)(obj + 0x17c) == entry->field4c) {
            CallHandlerIfF38Set02170fd0((struct Struct02170fd0*)entry, 0);
            entry->field24 = entry->field24 & ~4;
            break;
        }

        idx = *(signed char*)(obj + 0x6c + i);
        struct CombatantStruct* c = GetCombatantWithFlag0x800(bs, idx);
        if (c == NULL || (signed char)*(int*)((char*)GetFieldAt0x150((unsigned char*)c) + 0x94c) == 5) {
            signed char v = *(signed char*)((char*)entry + entry->field18 + 0x10);
            if (v == 0x64) result = entry->field4c;
        }
    }
    return result;
}
