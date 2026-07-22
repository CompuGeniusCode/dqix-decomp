#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField0x3acValue(struct BattleStruct* battleStruct);

extern "C" void* func_ov000_02161318(void* obj, int id);
extern "C" void func_ov000_02171d90(void* entry);
extern "C" void func_ov000_02170db0(void* entry);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern int data_02108760;

// USA: func_ov000_02174428
ARM void ApplyCombatantSlotFields_02174428(void* obj, int a, int f0, int f1, signed char bestIdxByte, short f6, signed char f4, unsigned short f8) {
    void* entry = func_ov000_02161318(obj, a);
    if (entry == 0) return;

    struct BattleStruct* bs = GetBattleStruct();
    int mainId = GetField0x3acValue(bs);
    if (a != mainId) {
        if (f0 == 0x64) {
            signed char val = *((signed char*)entry + *((signed char*)entry + 0x18) + 0x10);
            if (f0 != val) {
                DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0x19, 0);
            }
        }
    }

    if (*((unsigned char*)entry + 0x43e) != 0) return;

    int cond = 0;
    int field4c = *(int*)((char*)entry + 0x4c);
    if (field4c >= 0) {
        if (field4c <= 3) {
            cond = 1;
        }
    }
    if (cond == 0) return;

    signed char off = *((signed char*)entry + 0x18);
    *((unsigned char*)entry + off + 0x10) = (unsigned char)f0;
    *((unsigned char*)entry + 0x1c) = (unsigned char)f1;
    *((unsigned char*)entry + 0x1d) = (unsigned char)bestIdxByte;
    *(short*)((char*)entry + 0x2c) = f6;
    *((unsigned char*)entry + 0x2e) = (unsigned char)f4;
    *(unsigned short*)((char*)entry + 0x26) = (unsigned short)f8;

    func_ov000_02171d90(entry);
    func_ov000_02170db0(entry);
}
