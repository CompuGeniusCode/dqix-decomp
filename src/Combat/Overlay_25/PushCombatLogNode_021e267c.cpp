#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
void* GetArrayEntry_021e8a54_021e8a54(char* obj);
unsigned char GetByte48_021e8ba4(void* obj);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void* thisPtr, unsigned int size);
extern "C" void func_02036804(void* obj, void* params, int flag);
extern "C" void func_02036e34(void* obj, void* member, int arg3);

struct PtrField0x1c_020371b0;
void* GetPointerAt0x1c020371b0(struct PtrField0x1c_020371b0* obj);
struct S1a0;
void ShiftField0x1cInto0x20(struct S1a0* obj, unsigned int v);

struct Struct_203dafc {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
    int field1c;
};
void ClearEightWords(struct Struct_203dafc* obj);

struct Obj021e8bac;
struct Node021e8bac {
    unsigned char byte0;
    unsigned char byte1;
    unsigned short half2;
    unsigned short half4;
    struct Node021e8bac* next;
};
void PushLogNode021e8bac(struct Obj021e8bac* obj, struct Node021e8bac* node);

extern int data_ov025_021ef988;

// USA: func_ov025_021e267c  (semantic: PushCombatLogNode_021e267c)
extern "C" ARM void func_ov025_021e267c(int combatantId, int arg1, int arg2, int flag) {
    struct BattleStruct* battle = GetBattleStruct();
    void* entryObj = *(void**)((char*)&data_ov025_021ef988 + 0xc);
    void* entry = GetArrayEntry_021e8a54_021e8a54((char*)entryObj);
    struct CombatantStruct* combatant = GetCombatantUnchecked(battle, combatantId);
    if (!combatant) return;
    struct Node021e8bac* node = (struct Node021e8bac*)_ZN13SafeAllocator8AllocateEj(entry, 0xc);
    if (!node) return;
    char* name = *(char**)((char*)combatant + 0x14);
    char buf[0x20];
    if (name) {
        strcpy(buf, name);
    }
    void* ptr = GetPointerAt0x1c020371b0((struct PtrField0x1c_020371b0*)combatant);
    struct Struct_203dafc s;
    ClearEightWords(&s);
    void* byteObj = *(void**)((char*)&data_ov025_021ef988 + 0xc);
    s.fieldc = (int)entry;
    s.field4 = arg1;
    s.field8 = arg2;
    s.field10 = 1;
    unsigned char b = GetByte48_021e8ba4(byteObj);
    s.field1c = b + 4;
    func_02036804(combatant, &s, flag);
    if (name) {
        func_02036e34(combatant, buf, 0);
        ShiftField0x1cInto0x20((struct S1a0*)combatant, (unsigned int)ptr);
    }
    node->byte0 = 0;
    node->half2 = combatantId;
    node->half4 = s.field1c;
    void* pushObj = *(void**)((char*)&data_ov025_021ef988 + 0xc);
    PushLogNode021e8bac((struct Obj021e8bac*)pushObj, node);
}
