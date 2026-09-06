#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetData02108e10(void);
void* SearchBothTables02079e2c(char* p, int key);
void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
extern "C" void* func_ov000_02161318(void* obj, int id);
extern "C" int func_ov000_02171210(void* a, void* b);

// USA: func_ov000_02175b54  (semantic: RegisterCombatEvent_02175b54)
extern "C" ARM void func_ov000_02175b54(void* obj) {
    void* data = GetData02108e10();
    if (data == 0) {
        return;
    }
    signed char idx = *((signed char*)obj + 0x1d00 + 0x6d);
    signed short val = *(signed short*)((char*)obj + idx * 2 + 0x10);
    void* tableEntry = SearchBothTables02079e2c((char*)data, val);
    if (tableEntry == 0) {
        return;
    }
    struct BattleStruct* battleStruct = GetBattleStruct();
    unsigned char* field2a04 = (unsigned char*)GetPtrField0x2a04(battleStruct);
    signed char combIdx = *(signed char*)(field2a04 + 0xf00 + 0x78);
    char* entry = (char*)func_ov000_02161318(obj, combIdx);
    if (entry == 0) {
        return;
    }
    signed char cnt = *((signed char*)obj + 0x1d00 + 0x68);
    *((char*)obj + 0x1000 + 0xd68) = (char)(cnt + 1);
    int result = func_ov000_02171210(tableEntry, entry);
    signed char cnt2 = *((signed char*)obj + 0x1d00 + 0x68);
    *((char*)obj + cnt2 + 0x1000 + 0xd60) = (char)result;
    *((char*)obj + 0x1c) = entry[0x1d];
}
