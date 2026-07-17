#include <globaldefs.h>
#include <Combat/Main/BattleList.h>
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(int a, short* buf, int max, int start);
struct Obj02049f50; void SetField41AndScaleSub02049f50(struct Obj02049f50*, int, int);
struct ObjA { char pad[0x29c]; int field29c; };
ARM void test(struct ObjA* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    short buf[16];
    int n = func_ov000_0215e9fc(obj->field29c, buf, 0x10, 0);
    n = func_ov000_0215ec1c(obj->field29c, buf + n, 0x10 - n, 0) + n;
    short* p = buf;
    for (int i = 0; i < n; i++, p++) {
        struct CombatantStruct* c = GetCombatantFromList(bs, *p);
        if (c) SetField41AndScaleSub02049f50((struct Obj02049f50*)c, 0x1f, 0);
    }
}
