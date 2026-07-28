#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int HasFlag101_021571d8(int a);
int DispatchNodeIfType7_02156e2c(void* a, int key);
extern "C" int func_ov004_02157128(void* obj);
void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
struct Slots02083960;
int CountPositiveSlots02083960(struct Slots02083960* s);
struct S_a0b8c;
int CountNonZeroValues020a0b8c(struct S_a0b8c* p);
short CountPositiveEntries0207c638(void* base, unsigned int index);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct Struct021707d8_0215aa10 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215aa10 data_ov004_021707d8;

// USA: func_ov004_0215aa10
extern "C" ARM int func_ov004_0215aa10(void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    int result;
    if (HasFlag101_021571d8((int)obj)) {
        int idx = DispatchNodeIfType7_02156e2c(obj, 0x65);
        if (idx < 0) return 0;
        void* p = GetPtrField0x2a04(bs);
        if (!p) return 0;
        unsigned char key = *(data_ov004_021707d8.ptr + idx + 0x7c);
        result = CountPositiveEntries0207c638((char*)p + 0x1d4, key);
        *(int*)(data_ov004_021707d8.ptr + 0x74) = key;
    } else {
        int val = func_ov004_02157128(obj);
        if (val == -1) {
            void* p = GetPtrField0x2a04(bs);
            if (!p) return 0;
            result = CountNonZeroValues020a0b8c((struct S_a0b8c*)p);
        } else {
            struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, val);
            if (!c) return 0;
            int ptrAsInt = GetFieldAt0x150((unsigned char*)c);
            result = CountPositiveSlots02083960((struct Slots02083960*)ptrAsInt);
        }
    }
    if (result > 0) {
        func_ov011_021848a0(obj, 0x6a);
    }
    return 0;
}
