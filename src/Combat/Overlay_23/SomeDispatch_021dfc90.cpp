#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"


struct Element020de650;
struct Container020dedd0;
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

void InitFields_021db0d4(void* obj, int flag);
extern int data_ov023_021ffa0c;

struct Obj021dcb70;
unsigned char LookupByField8_021dcb70(struct Obj021dcb70* p);

extern "C" void __clear(void* buf, int len);
extern "C" void func_ov023_021dde00(void* obj);
extern "C" void func_ov023_021dbd10(void* a, void* b);


extern char data_ov023_021fdba9[];
extern char data_ov023_021fdbbe[];
extern char data_ov023_021fdbd5[];
extern char data_ov023_021fdbeb[];
extern char data_ov023_021fdbfd[];
extern char data_ov023_021fdc12[];

// USA: func_ov023_021dfc90  (semantic: SomeDispatch_021dfc90)
extern "C" ARM int func_ov023_021dfc90(void* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();

    if (*(void**)((char*)obj + 0x48) != 0) {
        short key = *(short*)((char*)obj + 0x700 + 0x70);
        *(void**)((char*)obj + 0x50) = FindElementByKey020dedd0((struct Container020dedd0*)*(void**)((char*)obj + 0x48), key);
    }

    int flag = 0;
    void* node = *(void**)((char*)obj + 0x50);
    if (node != 0) {
        unsigned int field = ((unsigned int)*(int*)((char*)node + 8) << 0x14) >> 0x1d;
        if (field == 5) flag = 1;
    }

    InitFields_021db0d4(&data_ov023_021ffa0c, flag);

    unsigned char lookupResult = LookupByField8_021dcb70((struct Obj021dcb70*)*(void**)((char*)obj + 0x50));
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
            sprintf(buf1, data_ov023_021fdba9);
            goto tail021dfc90;
        case 2:
            sprintf(buf1, data_ov023_021fdbbe);
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
    sprintf(buf1, data_ov023_021fdbd5, r5);
    sprintf(buf2, data_ov023_021fdbeb, r5);
    useTwoStrings = 1;
    goto tail021dfc90;
e4c021dfc90:
    sprintf(buf1, data_ov023_021fdbfd, r5);
    sprintf(buf2, data_ov023_021fdc12, r5);
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
