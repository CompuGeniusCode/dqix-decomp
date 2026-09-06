#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

ARM int GetData02104304Field4();

struct Entry_0205d6a0;
ARM void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);

ARM void* GetDataPtr02114e04_020d6c00(void);

struct FlagWord020466f4;
ARM void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);

extern "C" void* func_ov017_0218b5b0(void);
void ClearBitsInWord(unsigned int*, unsigned int);

extern "C" void func_020301c8(int a, int b);

struct Actor0218b240 {
    char pad0[0xe99];
    unsigned char f0xe99;
    unsigned char f0xe9a;
    unsigned char f0xe9b;
    unsigned char f0xe9c;
    char pad1[0xea0 - 0xe9d];
    int f0xea0;
    int f0xea4;
    int f0xea8;
    char pad4[0xeb4 - 0xeac];
    int f0xeb4;
    char pad5[0xec0 - 0xeb8];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char restBits : 4;
};

// USA: func_0218b240
ARM void ResetBattleState_0218b240(struct Actor0218b240* obj) {
    if (obj->bit3) return;

    GetBattleStruct();
    int v = GetData02104304Field4();

    obj->bit0 = 0;
    ResetEntryList0205d6a0((struct Entry_0205d6a0*)((char*)obj + 0x18), 1);

    obj->f0xe99 = 0x2f;
    obj->f0xe9a = 0;
    obj->f0xe9b = 0x2f;
    obj->f0xe9c = 0;

    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x2f);

    ClearBitsInWord((unsigned int*)func_ov017_0218b5b0(), 0x10);

    func_020301c8(v, obj->f0xea0);
    func_020301c8(v, obj->f0xeb4);
    func_020301c8(v, obj->f0xea4);
    func_020301c8(v, obj->f0xea8);

    obj->f0xea0 = -1;
    obj->f0xeb4 = -1;
    obj->f0xea4 = -1;
    obj->f0xea8 = -1;

    obj->bit3 = 1;
}
