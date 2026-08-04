#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* func_0202ae18(void);
extern "C" void* func_0205ec34(void);
extern "C" void* func_02012fe4(void);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
extern "C" int func_0202c508(void* obj);
struct Obj020ad4c4;
extern int CheckAndInvoke020ad4c4(struct Obj020ad4c4* obj);
extern "C" int func_02098080(void* p);
struct U16Field0x6_020375f8;
extern unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);
extern "C" int func_0206e558(void* obj);
extern "C" int func_ov017_0219c774(int a, int b, int c);

// USA: func_ov017_0219bddc  (semantic: EvaluateCombatantTransition_0219bddc)
extern "C" ARM int func_ov017_0219bddc(unsigned char* p0) {
    func_ov017_0218b5b0();
    struct BattleStruct* bs = GetBattleStruct();
    void* search = func_0202ae18();
    void* obj8 = func_0205ec34();
    void* obj4 = func_02012fe4();
    struct CombatantStruct* c7 = GetCombatantUnchecked(bs, 0);
    struct CombatantStruct* c6 = GetCombatantAtField0x3ac(bs);

    if (func_0202c508(search) != 0) {
        return 0;
    }
    if (c7 == NULL) {
        return 0;
    }
    if (c6 == NULL) {
        return 0;
    }

    int result = 0;
    if (CheckAndInvoke020ad4c4((struct Obj020ad4c4*)obj4) != 0) {
        result = 1;
        goto end;
    }
    if (func_02098080((char*)obj4 + 0x840) != 0) {
        result = 1;
        p0[0] = (unsigned char)result;
        goto end;
    }

    unsigned short v1 = GetU16At0x6((struct U16Field0x6_020375f8*)c7);
    unsigned short v2 = GetU16At0x6((struct U16Field0x6_020375f8*)c6);
    if (v1 != v2) {
        return result;
    }

    if (func_0206e558(obj8) != 0) {
        result = 1;
    }
    if (func_ov017_0219c774(*(int*)((char*)obj4 + 8), 0, 0) != 0) {
        result = 1;
    }

end:
    return result;
}
