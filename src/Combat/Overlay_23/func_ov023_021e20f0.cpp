#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" int func_02001aec(unsigned char* a, unsigned char* b, int n);
extern "C" void memcpy(void* dst, const void* src, int n);

extern unsigned char data_ov023_021fdc90;

struct ListHeader021e20f0 {
    char pad0[4];
    int field4;
    char pad8[0xc - 0x8];
    int fieldC;
    char pad10[0x14 - 0x10];
    int field14;
    int field18;
};

struct Target021e20f0 {
    char pad0[8];
    void* arr1;   // 0x8
    void* arr2;   // 0xc
    char pad10[0x14 - 0x10];
    unsigned short count1; // 0x14
    unsigned short sum;    // 0x16
};

struct SrcEntry1_021e20f0 {
    char pad0[4];
    int field4;
    short field8;
    short fieldA;
    char padC[0xe - 0xc];
    unsigned short fieldE;
    unsigned short field10;
    unsigned short field12;
    unsigned short field14;
    unsigned short field16;
    unsigned short field18;
};

struct DstEntry1_021e20f0 {
    signed short field0;
    unsigned short field2;
    void* field4;
    signed short field8;
    signed short fieldA;
    signed short fieldC;
    signed short fieldE;
    signed short field10;
    signed short field12;
    unsigned short field14;
    unsigned char field16;
    unsigned char field17;
};

struct SrcEntry3_021e20f0 {
    int field0;
    short field4;
    short field6;
    signed short field8;
    char pad8[0x10 - 0xa];
    unsigned short field10;
    unsigned short field12;
};

struct DstEntry2Byte3_021e20f0 { unsigned char lowNibble : 4; unsigned char hiNibble : 4; };

struct DstEntry2_021e20f0 {
    short field0;
    unsigned char field2;
    unsigned char field3;
    signed short field4;
    signed short field6;
    signed short field8;
    signed short fieldA;
    int fieldC;
    unsigned char field10;
};

// USA: func_ov023_021e20f0  (semantic: BuildListEntryArrays_021e20f0)
extern "C" ARM int func_ov023_021e20f0(struct Target021e20f0* p, SafeAllocator* alloc,
        struct ListHeader021e20f0* header, void* guard) {
    short negOne = -1;
    if (alloc == 0) return 1;
    if (header == 0) return 1;
    if (guard == 0) return 1;

    if (func_02001aec((unsigned char*)((char*)header + 8), &data_ov023_021fdc90, 3) != 0) {
        return 1;
    }

    header->fieldC = (int)((char*)header + header->fieldC);
    header->field14 = (int)((char*)header + header->field14);
    p->count1 = 0;
    p->sum = 0;
    p->count1 = header->field18;
    p->arr1 = alloc->Allocate(p->count1 * 0x18);
    struct SrcEntry1_021e20f0* srcArray = (struct SrcEntry1_021e20f0*)((char*)header + header->field4);
    unsigned short count1 = p->count1;

    unsigned short i;
    for (i = 0; i < count1; i++) {
        struct SrcEntry1_021e20f0* src = (struct SrcEntry1_021e20f0*)((char*)srcArray + i * 0x1c);
        struct DstEntry1_021e20f0* dst = (struct DstEntry1_021e20f0*)((char*)p->arr1 + i * 0x18);

        dst->field0 = negOne;
        dst->field2 = 0;
        dst->field4 = 0;
        dst->fieldA = 0;
        dst->field8 = dst->fieldA;
        dst->fieldC = negOne;
        dst->fieldE = negOne;
        dst->field10 = negOne;
        dst->field12 = negOne;
        dst->field14 = 0;
        dst->field16 = 3;
        dst->field17 = 0xff;

        dst->field8 = src->field8;
        dst->fieldA = src->fieldA;
        dst->field2 = src->fieldE;
        dst->field4 = alloc->Allocate(src->fieldE * 2);
        char* sumBase = (char*)header->field14 + src->field4;
        if (sumBase != 0) {
            memcpy(dst->field4, sumBase, src->fieldE * 2);
        }
        dst->field0 = src->field10;
        dst->fieldC = src->field12;
        dst->fieldE = src->field14;
        dst->field10 = src->field16;
        dst->field12 = src->field18;
        p->sum = p->sum + dst->field2;
    }

    p->arr2 = alloc->Allocate(p->sum * 0x14);
    struct SrcEntry3_021e20f0* srcArray3 = (struct SrcEntry3_021e20f0*)header->fieldC;

    unsigned short j;
    for (j = 0; j < p->sum; j++) {
        struct SrcEntry3_021e20f0* src3 = (struct SrcEntry3_021e20f0*)((char*)srcArray3 + j * 0x28);
        struct DstEntry2_021e20f0* dst2 = (struct DstEntry2_021e20f0*)((char*)p->arr2 + j * 0x14);

        dst2->field0 = -1;
        dst2->field2 = 0;
        struct DstEntry2Byte3_021e20f0* b3 = (struct DstEntry2Byte3_021e20f0*)&dst2->field3;
        b3->lowNibble = 0xa;
        b3->hiNibble = 0xf;
        dst2->field6 = 0;
        dst2->field4 = dst2->field6;
        dst2->fieldA = 0;
        dst2->field8 = dst2->fieldA;
        dst2->fieldC = 0;
        dst2->field10 = 0;

        dst2->field4 = src3->field4;
        dst2->field6 = src3->field6;
        dst2->field0 = src3->field8;

        switch (src3->field0) {
        case 0:
            dst2->field2 = 2;
            dst2->field8 = *(unsigned short*)((char*)src3 + 0xc);
            dst2->fieldA = *(unsigned short*)((char*)src3 + 0xe);
            break;
        case 1:
            dst2->field2 = 1;
            dst2->field8 = *(unsigned short*)((char*)src3 + 0xc);
            dst2->fieldA = *(unsigned short*)((char*)src3 + 0xe);
            break;
        case 3:
            if (*(int*)((char*)src3 + 0xc) == 0) {
                dst2->field8 = src3->field10;
                dst2->fieldA = src3->field12;
            }
            break;
        case 2:
        default:
            break;
        }
    }

    return 0;
}
