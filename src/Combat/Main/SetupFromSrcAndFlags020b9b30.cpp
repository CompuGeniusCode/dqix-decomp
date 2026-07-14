#include <globaldefs.h>

extern void* data_0210a274;
extern int data_0210b084;
extern int data_0210b088;
extern int data_0210b08c;

struct Obj020b9b30 {
    unsigned int flags; // 0x0
    int f4;             // 0x4
    int f8;             // 0x8
    int fc;             // 0xc
    int f10;            // 0x10
    int f14;            // 0x14
    int f18;             // 0x18
};

struct Src020b9b30 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
};

struct ByteArr020b9b30 {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
};

struct Rec3_020b9b30 { unsigned int v[3]; };

#pragma optimize_for_size off
// USA: func_020b9b30
ARM void SetupFromSrcAndFlags020b9b30(struct Obj020b9b30* obj, struct Src020b9b30* src, struct ByteArr020b9b30* barr, unsigned int flags) {
    unsigned char flagByte3 = barr->b3;

    if (flags & 0x4) {
        obj->flags |= 0x1;
        if (flagByte3 & 0x2) {
            unsigned int idx = barr->b1;
            unsigned int* table = (unsigned int*)((char*)data_0210a274 + 0xc4);
            table[idx >> 5] |= (1u << (idx & 0x1f));
        }
    } else {
        obj->f4 = src->f0;
        obj->f8 = src->f4;
        obj->fc = src->f8;
        if (flagByte3 & 0x2) {
            unsigned int idx = barr->b1;
            unsigned int* table = (unsigned int*)((char*)data_0210a274 + 0xc4);
            table[idx >> 5] &= ~(1u << (idx & 0x1f));

            int off = idx * 0x18;
            *(int*)((char*)&data_0210b084 + off) = src->fc;
            *(int*)((char*)&data_0210b088 + off) = src->f10;
            *(int*)((char*)&data_0210b08c + off) = src->f14;
        }
    }

    if (flagByte3 & 0x1) {
        unsigned int idx2 = barr->b2;
        obj->flags |= 0x20;
        {
            unsigned int* table = (unsigned int*)((char*)data_0210a274 + 0xc4);
            if (table[idx2 >> 5] & (1u << (idx2 & 0x1f))) {
                obj->flags |= 0x8;
            } else {
                int off = idx2 * 0x18;
                *(struct Rec3_020b9b30*)&obj->f10 = *(struct Rec3_020b9b30*)((char*)&data_0210b084 + off);
            }
        }
    }

    obj->flags |= 0x10;
}
