#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int HasFlag101_021571d8(int a);
int DispatchNodeIfType7_02156e2c(void* a, int key);
extern "C" void* func_ov004_02156ed0(void* a, int key);
extern "C" int func_ov004_02157128(void* obj);
int GetFieldAt0x150(unsigned char* obj);
ARM int CheckThenNotify_02157088(void);
extern "C" void func_ov023_021dcae0(int a, int b);
void* GetPointerFromArray0xbd0(unsigned char* obj, unsigned int index);

struct Struct021707d8_0215be9c { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215be9c data_ov004_021707d8;

// USA: func_ov004_0215be9c
extern "C" ARM int func_ov004_0215be9c(void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    void* p = GetPtrField0x2a04(bs);
    if (!p) return 0;

    void* node = func_ov004_02156ed0(obj, 0x63);
    int r4 = *(short*)((char*)node + 0x5c) << 3;
    void* r7;

    if (HasFlag101_021571d8((int)obj)) {
        int idx = DispatchNodeIfType7_02156e2c(obj, 0x65);
        if (idx < 0) return 0;
        unsigned char key = data_ov004_021707d8.ptr[idx + 0x7c];
        r7 = GetPointerFromArray0xbd0((unsigned char*)p + 0x1d4, key);
    } else {
        int val = func_ov004_02157128(obj);
        if (val >= 0) {
            struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, val);
            if (!c) return 0;
            r7 = (void*)(GetFieldAt0x150((unsigned char*)c) + 0x54 + 0x400);
            r4 = 0;
        } else {
            r7 = (char*)p + 0xc;
        }
    }

    int flag = CheckThenNotify_02157088();
    int idx63 = DispatchNodeIfType7_02156e2c(obj, 0x63);
    if (flag) {
        short v = *(short*)((char*)r7 + ((r4 + idx63) << 1));
        func_ov023_021dcae0(flag, v);
    }
    return 0;
}
