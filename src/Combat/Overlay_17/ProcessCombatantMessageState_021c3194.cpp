#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
void* GetGlobalField0x1c020421a0(void);
extern "C" void func_ov017_0218b5b0(void);
extern "C" void func_020531f0(void* obj);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
extern "C" void func_02046380(void* obj);
int CallFunc020e0434With02153694(int value);
extern "C" int sprintf(char* dst, const char* fmt, ...);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
extern "C" void func_0204500c(void*, const char*, int, int);
void SetByteField0x253(void* obj);

struct Obj_021c3194 {
    unsigned char pad0;
    unsigned char field1;
    unsigned char pad2[6];
    unsigned char field8;
    unsigned char field9;
};

// USA: func_ov017_021c3194  (semantic: ProcessCombatantMessageState_021c3194)
extern "C" ARM void func_ov017_021c3194(struct Obj_021c3194* obj) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    func_ov017_0218b5b0();
    struct CombatantStruct* a = GetCombatantAtField0x397c(battleStruct);
    struct CombatantStruct* c = GetCombatantWithFlag0x800(battleStruct, obj->field9);
    char* g = (char*)GetGlobalField0x1c020421a0();

    if (c == NULL) {
        obj->field8 = 2;
    }

    unsigned char state = obj->field8;
    if (state == 0) {
        if (a != NULL) {
            func_020531f0(a);
            CancelPendingAction020397cc((struct Obj020397cc*)a, 1);
        }
        func_02046380(g);
        char* buf = *(char**)(g + 0x5c);
        sprintf(buf, (const char*)CallFunc020e0434With02153694(0x25));
        char localBuf[0xc];
        InitObjFromCombatantId020e4bf4(localBuf, obj->field9);
        *(void**)(g + 0x10) = localBuf;
        func_0204500c(g, buf, 0, 0xe3);
        *(unsigned char*)(g + 0x1000 + 0x9b2) = 0;
        *(int*)(g + 0x998) = 1;
        obj->field8 = 1;
        return;
    }
    if (state == 1) {
        if (*(int*)(g + 0x998) == 0) {
            obj->field8 = 2;
        }
        return;
    }
    if (state == 2) {
        SetByteField0x253(a);
        obj->field1 = 1;
    }
}
