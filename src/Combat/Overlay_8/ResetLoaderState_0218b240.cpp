#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"

extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(void* p, int flag);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v();
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(void* p, unsigned int mask);
extern "C" void* func_ov017_0218b5b0(void);
extern "C" void _Z15ClearBitsInWordPjj(unsigned int* p, unsigned int mask);

struct Manager0218b240 {
    char pad0[0xe99];
    unsigned char e99;
    unsigned char e9a;
    unsigned char e9b;
    unsigned char e9c;
    char pad1[0xea0 - 0xe9d];
    int ea0;
    int ea4;
    int ea8;
    char pad2[0xeb4 - 0xeac];
    int eb4;
    char pad3[0xec0 - 0xeb8];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char rest : 4;
};

// USA: func_ov008_0218b240  (semantic: ResetLoaderState_0218b240)
extern "C" ARM void func_ov008_0218b240(Manager0218b240* obj) {
    if (obj->bit3) return;

    GetBattleStruct();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    obj->bit0 = 0;
    _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((char*)obj + 0x18, 1);

    obj->e99 = 2;
    obj->e9a = 0;
    obj->e9b = 2;
    obj->e9c = 0;

    void* ptr = _Z27GetDataPtr02114e04_020d6c00v();
    _Z18ClearFlags020466f4P16FlagWord020466f4j(ptr, 0x2f);
    _Z15ClearBitsInWordPjj((unsigned int*)func_ov017_0218b5b0(), 0x10);

    loader->RemoveTask(obj->ea0);
    loader->RemoveTask(obj->eb4);
    loader->RemoveTask(obj->ea4);
    loader->RemoveTask(obj->ea8);

    obj->ea0 = -1;
    obj->eb4 = -1;
    obj->ea4 = -1;
    obj->ea8 = -1;

    obj->bit3 = 1;
}
