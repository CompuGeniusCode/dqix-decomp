#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

int GetField0x3acValue(struct BattleStruct* battleStruct);
int GetGlobalField0x1c020421a0(void);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);

struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);

extern "C" void func_02046380(void* global);
extern "C" void func_02046608(int a, int b, void* c, void* d, int e, int f, int g);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

struct Bits0205de24_021ed4b8 { unsigned char low4 : 4; unsigned char high4 : 4; };

// USA: func_ov023_021ed4b8  (semantic: InitAndDispatchElementEntry_021ed4b8)
extern "C" ARM void func_ov023_021ed4b8(char* obj) {
    unsigned char keyLow = ((struct Bits0205de24_021ed4b8*)(obj + 0xc0))->low4;
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0xc4), keyLow, 3);

    *(unsigned short*)(obj + 0x164) = 0x1e;
    *(unsigned short*)(obj + 0x166) = 0x7;
    *(unsigned short*)(obj + 0x168) = 0x1;
    *(unsigned short*)(obj + 0x16a) = 0x9;
    *(unsigned short*)(obj + 0x16c) = 0x7;
    *(unsigned short*)(obj + 0x16e) = 0xa;
    *(unsigned short*)(obj + 0x170) = 0xc;
    *(unsigned short*)(obj + 0x172) = 0xc;
    *(unsigned char*)(obj + 0x17b) = 0xc;
    *(unsigned char*)(obj + 0x175) = 2;
    unsigned char zero = 0;
    *(unsigned char*)(obj + 0x179) = zero;
    *(unsigned char*)(obj + 0x17a) = zero;

    unsigned char idx = *(unsigned char*)(obj + 0x28);
    char* base = *(char**)(obj + 0x20);
    char* elem = base + idx * 0x244;

    memset(*(void**)(obj + 0x1c), zero, 0x960);

    struct BattleStruct* bs = GetBattleStruct();
    int id = GetField0x3acValue(bs);
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(bs, id);
    if (combatant == NULL) return;

    int g = GetGlobalField0x1c020421a0();
    func_02046380((void*)g);

    char localbuf[0xc];
    int combatantId = *(short*)((char*)combatant + 0x4);
    InitObjFromCombatantId020e4bf4(localbuf, combatantId);

    *(void**)((char*)g + 0x0) = localbuf;
    SetIndexedName02046574((struct Obj02046574*)g, 1, elem + 0xc);

    int key = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0x4), 0x64);
    func_02046608(g, 1, (void*)(long)key, *(void**)(obj + 0x1c), 0xe3, 0, 1);

    func_0205d304(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0, 1);
}
