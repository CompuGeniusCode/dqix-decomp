#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Variant02030b0c { int tag; int val; };
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct Struct02030b7c {
    int field0;
    void* field4;
};
void* GetField4IfField0Zero(struct Struct02030b7c* s);

int CheckField0NonZero(int* obj);
int IsField3dcSet(struct S_020103b4* obj);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

extern "C" void* func_0202ae18(void);
extern "C" int func_ov017_021b9bcc(int a);

extern unsigned char data_ov017_021d8438;
extern signed char data_ov017_021d7c54;

// USA: func_ov017_021ba124
ARM int CheckTriggerCondition3_021ba124(struct Variant02030b0c* a0, int a1) {
    if (*(int*)((char*)&data_ov017_021d8438 + 0x10) != 0) return 1;
    if (*((char*)&data_ov017_021d7c54 + 0x0) > -1) return 1;
    if (*((char*)&data_ov017_021d8438 + 0x1) != 0) return 1;
    if (*((char*)&data_ov017_021d7c54 + 0x1) > -1) return 1;

    GetBattleStruct();
    void* search = func_0202ae18();
    if (!CheckField0NonZero((int*)search)) return 1;
    if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search) != 0) return 1;

    int v0 = GetIntFromVariant02030b0c(a0);
    int v1 = GetIntFromVariant02030b0c(a0 + 1);
    struct Variant02030b0c* p = a0 + 2;
    if (v0 >= 0) {
        int lim = *(int*)((char*)&data_ov017_021d8438 + 0x4);
        if (v0 > lim) return 1;
        if (v1 < lim) return 1;
    }

    if (a1 >= 5) {
        int v2 = GetIntFromVariant02030b0c(p);
        p++;
        if (v2 != 0) {
            if (IsField3dcSet((struct S_020103b4*)GetBattleStruct())) return 1;
            *((char*)&data_ov017_021d8438 + 0x2) = 1;
        }
    } else {
        if (*((char*)&data_ov017_021d8438 + 0x2) != 0) return 1;
    }

    int v3 = GetIntFromVariant02030b0c(p);
    void* v4 = GetField4IfField0Zero((struct Struct02030b7c*)(p + 1));
    if (v4 == 0) return 0;
    if (func_ov017_021b9bcc(v3) != 0) {
        *((char*)&data_ov017_021d8438 + 0x0) = 1;
    }
    return 1;
}
