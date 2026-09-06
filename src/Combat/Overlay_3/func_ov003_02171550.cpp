#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

struct SearchStruct;
struct Obj02171550 {
    unsigned char field0;
    char pad1[0x730 - 1];
    unsigned char field730;
};

extern "C" void* func_0202ae18(void);
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
extern "C" int func_0202b000(void* ptr);
extern "C" void func_0202b0f4(void* ptr);
int SetState2AndCall0202d6c8(void* obj);
extern "C" void func_0202c360(void* self, int value);
extern "C" void func_0202b2f0(void* ptr);
void CopyBattleTailToObjField0x102c(void* obj);
void SetField0To5AndField0x1008To1(unsigned char* obj);
void RemoveSearchEntry0202c21c(struct SearchStruct* obj, int value);
void SetSearchFlagBitAt0xc(struct SearchStruct* obj, int value);
extern "C" void func_0202c288(void* ptr);

// USA: func_ov003_02171550  (semantic: StartSearchIfEligible_02171550)
extern "C" ARM void func_ov003_02171550(struct Obj02171550* obj) {
    if (!(obj->field730 & 1)) {
        obj->field0 = 8;
        return;
    }

    struct BattleStruct* battle = GetBattleStruct();
    void* ptr = func_0202ae18();
    struct CombatantStruct* c = GetCombatantAtField0x3ac(battle);

    int state = func_0202b000(ptr);
    if (state != 0) {
        if (state == 3) return;
        func_0202b0f4(ptr);
        obj->field0 = 0xa;
        return;
    }

    SetState2AndCall0202d6c8(ptr);
    func_0202c360(ptr, *(int*)((char*)c + 0x134));
    func_0202b2f0(ptr);
    CopyBattleTailToObjField0x102c(ptr);
    SetField0To5AndField0x1008To1((unsigned char*)ptr);
    RemoveSearchEntry0202c21c((struct SearchStruct*)ptr, 0xf);
    SetSearchFlagBitAt0xc((struct SearchStruct*)ptr, 0);
    func_0202c288(ptr);

    *(int*)((char*)obj + 4) = (rand() % 4 + 2) * 500;

    *(int*)((char*)obj + 0x72c) = 0;
    *(int*)((char*)obj + 0x724) = 0;
    *(int*)((char*)obj + 0x71c) = 0;
    *(int*)((char*)obj + 0x720) = 0;
    obj->field0 = 1;
}
