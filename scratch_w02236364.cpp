#include <globaldefs.h>
#include "System/Memory.h"

struct Base02236364 { void* field0; };
extern Base02236364 data_ov031_02290cfc;
extern "C" void func_ov031_02236174(void);

struct Flags0xe6_02236364 {
    unsigned char low2 : 2;
    unsigned char rest6 : 6;
};

// USA: func_ov031_02236364
ARM void PackObjectIntoBuffer_02236364(void* obj) {
    unsigned char* base = (unsigned char*)data_ov031_02290cfc.field0 + 0x400;
    VectorizedMemset(base, 0, 0xef);
    VectorizedInvertedMemcpy(obj, base + 0xd1, 5);
    VectorizedInvertedMemcpy((char*)obj + 0x6, base + 0xd6, 5);
    VectorizedInvertedMemcpy((char*)obj + 0xc, base + 0xdb, 5);
    VectorizedInvertedMemcpy((char*)obj + 0x12, base + 0xe0, 5);
    VectorizedInvertedMemcpy((char*)obj + 0x18, base + 0x60, 0x20);
    VectorizedInvertedMemcpy((char*)obj + 0x39, base + 0x80, 0xd);
    VectorizedInvertedMemcpy((char*)obj + 0x47, base + 0x90, 0xd);
    VectorizedInvertedMemcpy((char*)obj + 0x55, base + 0xa0, 0xd);
    VectorizedInvertedMemcpy((char*)obj + 0x63, base + 0xb0, 0xd);
    VectorizedInvertedMemcpy((char*)obj + 0x71, base + 0x40, 0x20);

    ((Flags0xe6_02236364*)(base + 0xe6))->low2 = 2;
    ((Flags0xe6_02236364*)(base + 0xe6))->rest6 = 0;
    base[0xe7] = 1;

    VectorizedMemset(base + 0xf0, 0, 4);
    base[0xf5] = 1;
    base[0xf6] = 1;
    func_ov031_02236174();
}
