#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct MenuContextHolder { char unknown0[8]; unsigned char* menuContext; };
extern MenuContextHolder data_ov004_021707d8;

extern int data_02109bf4;
extern char strDataPrmItemnameGp2_021703d7;
extern char strItemnameLgNat_021703ed;

extern "C" unsigned int GetSubBG0ScreenBase(void);
extern "C" unsigned int GetMainBG3ScreenBase(void);
extern "C" void* GetZoneState(void);
struct BgmActor;
extern "C" void PlayBgm(struct BgmActor* actor, int bgmId);
extern "C" void func_0209ca70(void* bgmActor, int mode);
extern "C" void func_020dc2bc(void);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" int func_020e56fc(void* itemNameTable, int data, int length);

// One step of the ov004 menu state machine: it blanks the sub engine's BG0 map and the main
// engine's BG3 map, then pulls itemname_<LG>.nat out of data/prm/itemname.gp2 and copies it into
// the buffer hanging off the menu context at +0x98, refusing anything larger than 0x10800 bytes.
// func_020e53bc then runs a one-time fixup pass over the blob, setting the header's top bit so it
// only happens once; func_020e56fc only checks that the copy and its length are non-zero before
// handing both on. The BackgroundLoader lock is held across the extract. The zone-derived value
// pushed into data_02109bf4 is the low seven bits of the byte at +0xd of the record at zone state
// +0x8, played as a track, followed by the byte at menu context +0x2d as a mode clamped to 1 to 5;
// why the menu does this here is not established.
extern "C" ARM int LoadItemNameTableForMenu() {
    unsigned short* bg0 = (unsigned short*)GetSubBG0ScreenBase();
    int mapEntry;
    for (mapEntry = 0; mapEntry < 0x800; mapEntry++) {
        *bg0++ = 0;
    }
    memset((void*)GetMainBG3ScreenBase(), 0, 0x1000);
    struct ZoneRecordByte { unsigned char low7 : 7; unsigned char hi1 : 1; };
    void* g = GetZoneState();
    ZoneRecordByte* zoneRecord = *(ZoneRecordByte**)((char*)g + 8);
    unsigned char bgmId = ((ZoneRecordByte*)((char*)zoneRecord + 0xd))->low7;
    PlayBgm((struct BgmActor*)&data_02109bf4, bgmId);
    func_0209ca70(&data_02109bf4, data_ov004_021707d8.menuContext[0x2d]);
    func_020dc2bc();
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* buf = ExtractFileFromGP2(&strDataPrmItemnameGp2_021703d7, &strItemnameLgNat_021703ed, &size);
    if (size <= 0x10800) {
        memcpy(*(void**)(data_ov004_021707d8.menuContext + 0x98), buf, size);
        func_020e56fc(data_ov004_021707d8.menuContext + 0x8c, (int)*(void**)(data_ov004_021707d8.menuContext + 0x98), (int)size);
    }
    BackgroundLoader::RemoveLockGlobal();
    return 0;
}
