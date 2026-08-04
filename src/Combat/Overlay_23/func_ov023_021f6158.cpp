#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);

struct Bits021f6158 {
    unsigned int counter : 12;
    unsigned int index : 4;
    unsigned int field2 : 5;
    unsigned int cur : 5;
    unsigned int reserved : 6;
};
struct Obj021f6158 { struct Bits021f6158 bits; };

struct Ptr33_021f6158 { char pad[0x33]; unsigned char byte33; };

struct Block48_021f6158 { unsigned int w[0xc]; };
extern struct Block48_021f6158 data_ov023_021fd8a8;

// USA: func_ov023_021f6158
extern "C" ARM void func_ov023_021f6158(struct Obj021f6158* obj) {
    struct Ptr33_021f6158* ptr2 = (struct Ptr33_021f6158*)*(void**)((unsigned char*)func_ov017_0218b5b0() + 0x3000 + 0xb48);
    unsigned char maxCur = ptr2->byte33;
    unsigned int cur = obj->bits.cur;
    int flag = 0;
    if (maxCur <= cur) {
        obj->bits.cur = maxCur;
        obj->bits.reserved = 0;
        flag = 1;
    } else {
        unsigned int threshold = maxCur - 2;
        if ((int)threshold < 0) threshold += 0x18;
        if (cur < threshold) {
            obj->bits.reserved = 0;
            obj->bits.cur = ptr2->byte33;
        } else {
            obj->bits.cur = obj->bits.cur + 2;
            if (obj->bits.cur >= 0x18) {
                obj->bits.cur = obj->bits.cur - 0x18;
                flag = 1;
            }
        }
    }
    if (flag == 0) return;

    obj->bits.field2 = obj->bits.field2 + 1;
    struct Block48_021f6158 localBuf = data_ov023_021fd8a8;
    if ((obj->bits.counter & 3) == 0) {
        localBuf.w[1] = 0x1d;
    }
    unsigned int index = obj->bits.index;
    unsigned int field2 = obj->bits.field2;
    unsigned int elem = *(unsigned int*)((char*)&localBuf - 4 + index * 4);
    if (elem >= field2) {
        if (field2 != 0) return;
    }

    obj->bits.field2 = 1;
    obj->bits.index = obj->bits.index + 1;
    if (obj->bits.index <= 0xc) return;
    obj->bits.index = 1;
    obj->bits.counter = obj->bits.counter + 1;
}
