#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"
#include "System/Timing.h"

extern "C" int func_ov017_0218b5b0(void);
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct*);
extern "C" void func_0202ae18(void);
void InitStruct02013718(char* obj, int a, int b);
extern "C" void func_02012fe4(void);
int IsField0xcNonNegative(int* obj);
void* GetPtrField0x468(void* obj);
struct SearchEntry;
struct SearchTable;
struct SearchEntry* FindEntryByHalfwordKey(struct SearchTable* table, int key);
extern "C" void func_0201383c(void* g, int val, int flag);
extern "C" void func_02012de8(void);
struct Obj0202fa00;
extern "C" void func_02015438(void* p);
void BlankFunction020d84f4(void);
void SetCombatWorkFlags0x55f4(void* work, int mask);

// USA: func_ov000_02166880
ARM void InitAndProcessCombat02166880(unsigned char* obj) {
    func_ov017_0218b5b0();
    struct BattleStruct* battle = GetBattleStruct();
    struct Obj0202fa00* fieldObj = (struct Obj0202fa00*)(int)BackgroundLoader::GetInstance();
    GetCombatantAtField0x3ac(battle);
    func_0202ae18();
    InitStruct02013718((char*)(obj + 0x2c8 + 0xc00), (int)(obj + 8), (int)(obj + 0x6f0 + 0x3000));
    func_02012fe4();

    if (IsField0xcNonNegative(*(int**)(obj + 0x2a0))) {
        unsigned short v = *(unsigned short*)((char*)*(int**)(obj + 0x2a0) + 0x20);
        if (v != 0) *(unsigned short*)((char*)*(int**)(obj + 0x2a0) + 2) = v;
    }

    void* table = GetPtrField0x468(battle);
    struct SearchEntry* entry = FindEntryByHalfwordKey((struct SearchTable*)table,
        *(unsigned short*)((char*)*(int**)(obj + 0x2a0) + 2));
    if (entry == NULL || *(unsigned short*)((char*)*(int**)(obj + 0x2a0) + 2) == 30000) {
        *(unsigned short*)((char*)*(int**)(obj + 0x2a0) + 2) = 0x75a4;
    }
    func_0201383c(obj + 0x2c8 + 0xc00, *(unsigned short*)((char*)*(int**)(obj + 0x2a0) + 2), 0);

    GetCurrentTimestamp();
    for (;;) {
        func_02012de8();
        ((BackgroundLoader*)(fieldObj))->RemoveAllLocks();
        func_02015438(obj + 0x2c8 + 0xc00);
        if (*(int*)(obj + 0x1000 + 0x2ec) == 0) break;
        BlankFunction020d84f4();
    }
    SetCombatWorkFlags0x55f4(obj, 0x10);
}
