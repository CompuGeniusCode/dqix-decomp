#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct Struct021707d8_0215bf94 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215bf94 data_ov004_021707d8;

extern int data_02109bf4;
extern char strDataPrmItemnameGp2_021703d7;
extern char strItemnameLgNat_021703ed;

extern "C" unsigned int GetSubBG0ScreenBase(void);
extern "C" unsigned int GetMainBG3ScreenBase(void);
extern "C" void* GetZoneState(void);
struct Actor0209c3b4;
extern "C" void PlayBgm(struct Actor0209c3b4* actor, int val);
extern "C" void func_0209ca70(void* obj, int val);
extern "C" void func_020dc2bc(void);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" int func_020e56fc(void* a0, int a1, int a2);

// One step of the ov004 menu state machine: it blanks the sub engine's BG0 map and the main
// engine's BG3 map, then pulls itemname_<LG>.nat out of data/prm/itemname.gp2 and copies it into
// the buffer hanging off the menu context at +0x98, refusing anything larger than 0x10800 bytes.
// func_020e53bc then runs a one-time fixup pass over the blob, setting the header's top bit so it
// only happens once. The BackgroundLoader lock is held across the extract. Why it first pushes a
// zone-derived value into data_02109bf4 is not established.
extern "C" ARM int LoadItemNameTableForMenu() {
    unsigned short* bg0 = (unsigned short*)GetSubBG0ScreenBase();
    int i;
    for (i = 0; i < 0x800; i++) {
        *bg0++ = 0;
    }
    memset((void*)GetMainBG3ScreenBase(), 0, 0x1000);
    struct Bits0215bf94 { unsigned char low7 : 7; unsigned char hi1 : 1; };
    void* g = GetZoneState();
    Bits0215bf94* p2 = *(Bits0215bf94**)((char*)g + 8);
    unsigned char v = ((Bits0215bf94*)((char*)p2 + 0xd))->low7;
    PlayBgm((struct Actor0209c3b4*)&data_02109bf4, v);
    func_0209ca70(&data_02109bf4, data_ov004_021707d8.ptr[0x2d]);
    func_020dc2bc();
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* buf = ExtractFileFromGP2(&strDataPrmItemnameGp2_021703d7, &strItemnameLgNat_021703ed, &size);
    if (size <= 0x10800) {
        memcpy(*(void**)(data_ov004_021707d8.ptr + 0x98), buf, size);
        func_020e56fc(data_ov004_021707d8.ptr + 0x8c, (int)*(void**)(data_ov004_021707d8.ptr + 0x98), (int)size);
    }
    BackgroundLoader::RemoveLockGlobal();
    return 0;
}
