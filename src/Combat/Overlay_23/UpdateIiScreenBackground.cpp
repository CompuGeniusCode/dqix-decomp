#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct ItemRecord;
struct ItemTable;
extern "C" struct ItemRecord* FindItemRecordById(struct ItemTable* itemTable, int key);

extern "C" void func_ov023_021db0d4(void* obj, int flag);
extern int data_ov023_021ffa0c;

struct ItemRecordKindView;
extern "C" unsigned char func_ov023_021dcb70(struct ItemRecordKindView* p);

extern "C" void __clear(void* buf, int len);
extern "C" void func_ov023_021dde00(void* obj);
extern "C" void func_ov023_021dbd10(void* layout, void* itemRecord);

extern char strDataAniBgIidcPac[];
extern char strDataAniBgIilistPac[];
extern char strDataAniBglii2NumGp2[];
extern char strBglii2NumLgPac[];
extern char strDataAniBgii2NumGp2[];
extern char strBgii2NumLgPac[];

// Picks the background for the item info screen from the record the key at +0x770 finds.
// func_ov023_021dcb70 maps that record's kind field to 1 or 2, or to 0 when no record was found; if
// that equals the byte at +0x779 nothing is loaded and 2 comes back, and if +0x77c is 1 sub-screen
// DISPCNT at 0x4001000 also gets BG1 and OBJ, plus BG0 for any non-zero index. Otherwise index 0 takes
// bg_iidc.pac or bg_iilist.pac for modes 1 and 2 at +0x778 and an empty name for 3 or more; every
// other case takes bgii2<n> or bglii2<n>, in data/ani for n = 0..2. Separately, a flag set when the
// three bits at 9..11 of the record's word at +0x8 read 5 goes to func_ov023_021db0d4, which parks
// that flag at +0x24 of the global it initialises; those bits are not the four-bit kind at 0..3 that
// func_ov023_021dcb70 reads, and what the value 5 selects is not established. AdvanceItemInfoSetup
// reads "ii" as item info, from obj_iteminfo.NCGR inside data/ani/obj_ii.pac, and QueueIiLayoutLoad
// tests a cached answer at +0x79a the same way +0x779 is tested here, its poll step
// func_ov023_021e04e8 being what writes it.
extern "C" ARM int UpdateIiScreenBackground(void* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();

    if (*(void**)((char*)obj + 0x48) != 0) {
        short key = *(short*)((char*)obj + 0x700 + 0x70);
        *(void**)((char*)obj + 0x50) = FindItemRecordById((struct ItemTable*)*(void**)((char*)obj + 0x48), key);
    }

    int flag = 0;
    void* itemRecord = *(void**)((char*)obj + 0x50);
    if (itemRecord != 0) {
        unsigned int field = ((unsigned int)*(int*)((char*)itemRecord + 8) << 0x14) >> 0x1d;
        if (field == 5) flag = 1;
    }

    func_ov023_021db0d4(&data_ov023_021ffa0c, flag);

    unsigned char lookupResult = func_ov023_021dcb70((struct ItemRecordKindView*)*(void**)((char*)obj + 0x50));
    signed char cachedBackgroundIndex = *(signed char*)((char*)obj + 0x700 + 0x79);
    int backgroundIndex = lookupResult;

    if (backgroundIndex == cachedBackgroundIndex) {
        *(int*)((char*)obj + 0x75c) = 0x3800;
        if (*(signed char*)((char*)obj + 0x700 + 0x7b) == 1) {
            *(int*)((char*)obj + 0x75c) = 0x2800;
        }
        *(int*)((char*)obj + 0x760) = 0;
        *(int*)((char*)obj + 0x768) = 0;
        func_ov023_021dde00(obj);
        func_ov023_021dbd10((char*)obj + 0xcc, *(void**)((char*)obj + 0x50));
        *(void**)((char*)obj + 0x4c) = *(void**)((char*)obj + 0x50);
        *(void**)((char*)obj + 0x50) = 0;

        if (*(signed char*)((char*)obj + 0x700 + 0x7c) == 1) {
            unsigned int* reg = (unsigned int*)0x4001000;
            unsigned int bits = 0x12;
            if (backgroundIndex != 0) bits |= 1;
            *reg = (*reg & ~0x1f00) | (bits << 8);
        }

        *(unsigned short*)((char*)obj + 0x700 + 0x74) |= 0x2000;
        return 2;
    }

    char buf1[0x40];
    char buf2[0x40];
    __clear(buf1, 0x40);
    __clear(buf2, 0x40);

    int useTwoStrings = 0;
    if (backgroundIndex == 0) {
        unsigned char m = *(unsigned char*)((char*)obj + 0x700 + 0x78);
        switch (m) {
        case 0:
            goto selectNumberedBackground;
        case 1:
            sprintf(buf1, strDataAniBgIidcPac);
            goto queueLoad;
        case 2:
            sprintf(buf1, strDataAniBgIilistPac);
            goto queueLoad;
        default:
            goto queueLoad;
        }
    }

selectNumberedBackground:
    if (!(*(unsigned short*)((char*)obj + 0x700 + 0x74) & 4)) goto useBgii2;
    if (*(unsigned char*)((char*)obj + 0x700 + 0x78) == 0) goto useBglii2;
    if (*(int*)((char*)obj + 0x734) <= 0) goto useBgii2;
useBglii2:
    sprintf(buf1, strDataAniBglii2NumGp2, backgroundIndex);
    sprintf(buf2, strBglii2NumLgPac, backgroundIndex);
    useTwoStrings = 1;
    goto queueLoad;
useBgii2:
    sprintf(buf1, strDataAniBgii2NumGp2, backgroundIndex);
    sprintf(buf2, strBgii2NumLgPac, backgroundIndex);
    useTwoStrings = 1;

queueLoad:
    {
        int result;
        if (useTwoStrings) {
            result = ((BackgroundLoader*)(listPtr))->QueueLoadFileInGP2((const char*)((int)buf1), (const char*)((int)buf2), (SafeAllocator*)(0));
        } else {
            result = ((BackgroundLoader*)(listPtr))->QueueLoadFile((const char*)((int)buf1), (SafeAllocator*)(0));
        }
        *(int*)((char*)obj + 0x734) = result;
    }
    return 1;
}
