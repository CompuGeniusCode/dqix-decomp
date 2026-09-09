#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct Element020de650;
struct Container020dedd0;
extern "C" struct Element020de650* FindItemRecordById(struct Container020dedd0* c, int key);

extern "C" void func_ov023_021db0d4(void* obj, int flag);
extern int data_ov023_021ffa0c;

struct Obj021dcb70;
extern "C" unsigned char func_ov023_021dcb70(struct Obj021dcb70* p);

extern "C" void __clear(void* buf, int len);
extern "C" void func_ov023_021dde00(void* obj);
extern "C" void func_ov023_021dbd10(void* a, void* b);

extern char strDataAniBgIidcPac[];
extern char strDataAniBgIilistPac[];
extern char strDataAniBglii2NumGp2[];
extern char strBglii2NumLgPac[];
extern char strDataAniBgii2NumGp2[];
extern char strBgii2NumLgPac[];

// Picks the background for the "ii" screen from the record the key at +0x770 finds.
// func_ov023_021dcb70 maps that record's kind field to 1 or 2, or to 0 when no record was found; if
// that equals the byte at +0x779 nothing is loaded and 2 comes back, and if +0x77c is 1 sub-screen
// DISPCNT at 0x4001000 also gets BG1 and OBJ, plus BG0 for a non-zero index. Otherwise index 0 takes
// bg_iidc.pac or bg_iilist.pac for modes 1 and 2 at +0x778 and an empty name for 3 or more; every
// other case takes bgii2<n> or bglii2<n>, in data/ani for n = 0..2. What "ii" means is not established.
extern "C" ARM int UpdateIiScreenBackground(void* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();

    if (*(void**)((char*)obj + 0x48) != 0) {
        short key = *(short*)((char*)obj + 0x700 + 0x70);
        *(void**)((char*)obj + 0x50) = FindItemRecordById((struct Container020dedd0*)*(void**)((char*)obj + 0x48), key);
    }

    int flag = 0;
    void* node = *(void**)((char*)obj + 0x50);
    if (node != 0) {
        unsigned int field = ((unsigned int)*(int*)((char*)node + 8) << 0x14) >> 0x1d;
        if (field == 5) flag = 1;
    }

    func_ov023_021db0d4(&data_ov023_021ffa0c, flag);

    unsigned char lookupResult = func_ov023_021dcb70((struct Obj021dcb70*)*(void**)((char*)obj + 0x50));
    signed char field779 = *(signed char*)((char*)obj + 0x700 + 0x79);
    int r5 = lookupResult;

    if (r5 == field779) {
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
            if (r5 != 0) bits |= 1;
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
    if (r5 == 0) {
        unsigned char m = *(unsigned char*)((char*)obj + 0x700 + 0x78);
        switch (m) {
        case 0:
            goto dfdfc021dfc90;
        case 1:
            sprintf(buf1, strDataAniBgIidcPac);
            goto tail021dfc90;
        case 2:
            sprintf(buf1, strDataAniBgIilistPac);
            goto tail021dfc90;
        default:
            goto tail021dfc90;
        }
    }

dfdfc021dfc90:
    if (!(*(unsigned short*)((char*)obj + 0x700 + 0x74) & 4)) goto e4c021dfc90;
    if (*(unsigned char*)((char*)obj + 0x700 + 0x78) == 0) goto e24021dfc90;
    if (*(int*)((char*)obj + 0x734) <= 0) goto e4c021dfc90;
e24021dfc90:
    sprintf(buf1, strDataAniBglii2NumGp2, r5);
    sprintf(buf2, strBglii2NumLgPac, r5);
    useTwoStrings = 1;
    goto tail021dfc90;
e4c021dfc90:
    sprintf(buf1, strDataAniBgii2NumGp2, r5);
    sprintf(buf2, strBgii2NumLgPac, r5);
    useTwoStrings = 1;

tail021dfc90:
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
