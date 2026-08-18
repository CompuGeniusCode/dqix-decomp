#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
void* ResetCombatantFields_0215a2f8(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov023_021f65d4(void* a, int key, int mask);

struct Struct021707d8_0215a294 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215a294 data_ov004_021707d8;

// USA: func_ov004_0215a294  (semantic: UpdateThenResetAndFlag_0215a294)
#pragma opt_propagation off
extern "C" ARM int func_ov004_0215a294(void* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    GetPtrField0x2a04(battle);
    unsigned char* fieldPtr = data_ov004_021707d8.ptr;
    unsigned char byteVal = (unsigned char)*(short*)(fieldPtr + 0x3a);
    short base0x396 = 0x396;
    short f32 = *(short*)(fieldPtr + 0x32);
    *(short*)(fieldPtr + 0x3c) = f32;
    func_ov011_021848a0(obj, base0x396 + byteVal);
    ResetCombatantFields_0215a2f8(data_ov004_021707d8.ptr);
    func_ov023_021f65d4(obj, 2, 8);
    return 0;
}
