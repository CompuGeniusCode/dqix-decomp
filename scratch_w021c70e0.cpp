#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_021b8478(void* table);
extern "C" int func_ov017_021b8468(void* table);
void* GetField6b0_021b8470(void* obj);
int GetField0x3acValue(struct BattleStruct* battleStruct);

struct Header021c70e0 {
    unsigned char pad0[8];
    unsigned short field8;
    unsigned char pad1[0x20];
    signed char field2a;
};

struct SrcEntry021c70e0 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned char bytes8[4];
    short fieldc;
    short fielde;
    short field10;
    short field12;
};

// USA: func_ov017_021c70e0
extern "C" ARM void func_ov017_021c70e0(int unused0, struct SrcEntry021c70e0* src, struct BattleStruct* battleStruct, unsigned char* base) {
    void* table = *(void**)(base + 0x3000 + 0x718);
    struct Header021c70e0* header = (struct Header021c70e0*)func_ov017_021b8478(table);
    if (header == NULL) return;
    if (!func_ov017_021b8468(table)) return;
    if (!GetField6b0_021b8470(table)) return;
    if (header->field2a == GetField0x3acValue(battleStruct)) return;
    if (header->field8 != src->field4) return;

    struct CombatantStruct* c = GetCombatantFromList(battleStruct, src->field6);
    if (c == NULL) return;

    memcpy((unsigned char*)c->currentStats + 0x58, src->bytes8, 4);
    *(short*)((unsigned char*)c->currentStats + 0x28) = src->fieldc;
    *(short*)((unsigned char*)c->currentStats + 0x2a) = src->fielde;
    *(short*)((unsigned char*)c->currentStats + 0x2c) = src->field10;
    *(short*)((unsigned char*)c->currentStats + 0x2e) = src->field12;
}
