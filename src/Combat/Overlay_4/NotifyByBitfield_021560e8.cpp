#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
extern "C" int func_ov023_021f9bc8(void*);
extern "C" void func_ov011_021848a0(void*, int);

struct Elem020a15bc { unsigned int field : 9; unsigned int pad : 23; unsigned int w1; unsigned int w2; };
struct Array020a15bc { struct Elem020a15bc* base; unsigned short pad4; unsigned short count; };
struct Elem020a15bc* FindElementByField020a15bc(struct Array020a15bc* arr, int id);

struct Data021707c8 { char pad[8]; short* keys; struct Array020a15bc* arr; };
extern struct Data021707c8 data_ov004_021707c8;

// USA: func_ov004_021560e8
ARM int NotifyByBitfield_021560e8(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 3);
    if (!node) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 7) return 0;

    short field5c = *(short*)((char*)node + 0x5c);
    short offset = (short)(field5c * 12);
    int addr = func_ov023_021f9bc8(node) + offset;

    short key = data_ov004_021707c8.keys[addr];
    struct Elem020a15bc* elem = FindElementByField020a15bc(data_ov004_021707c8.arr, key);
    if (!elem) return 0;

    unsigned int top2 = *(unsigned int*)elem >> 30;
    switch (top2) {
        case 0: func_ov011_021848a0(a, 0x6e); break;
        case 1: func_ov011_021848a0(a, 0x6f); break;
        case 2: func_ov011_021848a0(a, 0x70); break;
    }
    return 0;
}
