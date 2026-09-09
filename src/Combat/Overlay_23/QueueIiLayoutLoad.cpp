#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Container020dedd0;
struct Element020de650_021e0414 {
    char pad0[8];
    unsigned int nibble : 4;
    unsigned int restBits : 28;
};
extern "C" Element020de650_021e0414* FindItemRecordById(struct Container020dedd0*, int);

extern "C" void func_ov023_021e20c0(void*);

extern int strDataAniLayIieLia;
extern int strDataAniLayIiuLia;

struct Obj021e0414 {
    char pad0[0x48];
    Container020dedd0* field48;
    Element020de650_021e0414* field4c;
    char pad50[0x73c - 0x50];
    int field73c;
    char pad740[0x770 - 0x740];
    short field770;
    char pad772[0x79a - 0x772];
    signed char field79a;
};

// Queues a BackgroundLoader read of the layout matching the record for the current selection at
// +0x770: data/ani/lay_iie.lia when bit 3 of the record's byte at +0x8 is clear, lay_iiu.lia when
// it is set. The object at +0xcc that the layout builds is cleared first, and it returns 6. It only
// reads the answer cached at +0x79a - func_ov023_021e04e8, the poll step, writes it - so the two
// together fire the load only when the choice flips. "ii" is a prefix a group of ov023 assets share
// (oiij, oiir, bg_iidc, bg_iilist, str_ii); its expansion, and so the e/u split, is not established.
extern "C" ARM int QueueIiLayoutLoad(struct Obj021e0414* obj) {
    int a = (int)BackgroundLoader::GetInstance();
    if (obj->field48 != NULL) {
        obj->field4c = FindItemRecordById(obj->field48, obj->field770);
    }
    Element020de650_021e0414* elem = obj->field4c;
    if (elem != NULL) {
        unsigned int nibble = elem->nibble;
        int cond1 = (nibble <= 7);
        signed char flag = (cond1 != 0);
        signed char b = obj->field79a;
        if (b != flag) {
            func_ov023_021e20c0((char*)obj + 0xcc);
            elem = obj->field4c;
            unsigned int nibble2 = elem->nibble;
            int cond2 = (nibble2 <= 7);
            if (cond2) {
                obj->field73c = ((BackgroundLoader*)(a))->QueueLoadFile((const char*)((int)&strDataAniLayIieLia), (SafeAllocator*)(0));
            } else {
                obj->field73c = ((BackgroundLoader*)(a))->QueueLoadFile((const char*)((int)&strDataAniLayIiuLia), (SafeAllocator*)(0));
            }
        }
    }
    return 6;
}
