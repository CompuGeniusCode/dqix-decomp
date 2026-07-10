#include <globaldefs.h>

struct ElemA02083508 {
    void* pB;       // 0x0
    void* pResult;  // 0x4
    char pad[0x18];
};

struct ElemB02083508 {
    char data[0x20];
};

struct Obj02083508 {
    char pad[0x194];
    struct ElemA02083508 arrA[11];  // 0x194
    char pad2[0x3fc];
    struct ElemB02083508 arrB[11];  // 0x6f0
};

extern "C" void func_020de1d4(struct ElemA02083508* e);
unsigned char* GetIndexedBlockPointer0208349c(unsigned char* base, int idx);

// USA: func_02083508
ARM void InitIndexedElements02083508(struct Obj02083508* o) {
    int i;
    for (i = 0; i < 11; i++) {
        func_020de1d4(&o->arrA[i]);
        o->arrA[i].pResult = GetIndexedBlockPointer0208349c((unsigned char*)o, i);
        o->arrA[i].pB = &o->arrB[i];
    }
}
