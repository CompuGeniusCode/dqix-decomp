#include <globaldefs.h>

struct ElemArr0222c5d4 {
    unsigned char pad0[0x26];
    unsigned short field26;
    unsigned char field28;
    unsigned char pad1[0x2a - 0x29];
};

struct Inner0222c5d4 {
    ElemArr0222c5d4* elems;
    unsigned char pad0xc[0x51 - 4];
    unsigned char field51;
};
struct Struct0222c5d4 {
    unsigned char pad[2];
    unsigned short field2;
    Inner0222c5d4* field4;
};
extern Struct0222c5d4 data_ov031_02290c8c;

// USA: func_ov031_0222c5d4
extern "C" ARM void func_ov031_0222c5d4(int idxA, int idxB) {
    Inner0222c5d4* inner = data_ov031_02290c8c.field4;
    if (idxA >= inner->field51) return;

    unsigned char byteIdx = inner->elems[idxA].field28;
    void* p10 = *(void**)((char*)inner + 0x10 + idxB * 4);
    unsigned short val42 = *(unsigned short*)((char*)inner + 0x42 + byteIdx * 2);
    unsigned short* dst42 = (unsigned short*)((char*)p10 + 4);
    *dst42 = (*dst42 & ~0x3ff) | val42;

    Inner0222c5d4* inner2 = data_ov031_02290c8c.field4;
    void* p24 = *(void**)((char*)inner2 + 0x24 + idxB * 4);
    unsigned short shortIdx = inner2->elems[idxA].field26;
    unsigned short val48 = *(unsigned short*)((char*)inner2 + 0x48 + shortIdx * 2);
    unsigned short* dst48 = (unsigned short*)((char*)p24 + 4);
    *dst48 = (*dst48 & ~0x3ff) | val48;
}
