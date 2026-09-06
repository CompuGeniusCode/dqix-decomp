#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_021b8478(void* table);
extern "C" int func_ov017_021b8468(void* table);
void* GetField6b0_021b8470(void* obj);
void SetSubstructByte0x1c(unsigned char* obj, unsigned char value);

struct Header021c8ab0 {
    unsigned char pad0[8];
    unsigned short field8;
};

struct Arr021c8ab0 {
    unsigned char pad0[4];
    unsigned char array1[4];
    unsigned char array2[8];
    unsigned short field10;
};

// USA: func_ov017_021c8ab0
extern "C" ARM void func_ov017_021c8ab0(int unused0, struct Arr021c8ab0* arr, struct BattleStruct* battleStruct, unsigned char* base) {
    void* table = *(void**)(base + 0x3000 + 0x718);
    struct Header021c8ab0* header = (struct Header021c8ab0*)func_ov017_021b8478(table);
    if (header == NULL) return;
    if (!func_ov017_021b8468(table)) return;
    if (!GetField6b0_021b8470(table)) return;
    if (header->field8 != arr->field10) return;

    int i;
    for (i = 0; i < 4; i++) {
        struct CombatantStruct* c = GetCombatantFromList(battleStruct, i);
        if (c != NULL && arr->array1[i] != 0xff) {
            SetSubstructByte0x1c((unsigned char*)c, arr->array1[i]);
        }
    }
    for (int j = 0; j < 8; j++) {
        struct CombatantStruct* c = GetCombatantFromList(battleStruct, j + 0xc0);
        if (c != NULL && arr->array2[j] != 0xff) {
            SetSubstructByte0x1c((unsigned char*)c, arr->array2[j]);
        }
    }
}
