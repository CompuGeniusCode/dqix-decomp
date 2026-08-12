#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov017_021959b4(void);
void DestroyTreeNode_02184604(void* self, unsigned char* node);

struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
struct Struct02074bf4;
void ClearFlag0x11IfSet(struct Struct02074bf4* obj);

void ShiftInBitOnGlobalObject(void);
void CallFunc02030110OnGlobalObject(void);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
int TransferBg1CharData(int arg0, int arg1, unsigned int arg2);
extern "C" void func_020c5b98(void* p, int a, int b);
int GetData02104304Field4(void);
extern "C" int func_ov023_021f6bb8(void* obj);
extern "C" void func_020301c8(int a, int b);
void HalveGlobalObjectCounter(void);
extern "C" int func_ov017_0218b5b0(void);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);

extern char data_0211e33c[];

// USA: func_ov011_02184770  (semantic: ResetTreeAndGraphicsState_02184770)
extern "C" ARM void func_ov011_02184770(char* self) {
    if (func_ov017_021959b4() != 0 && *(void(**)(void*))(self + 0x1dc) != 0) {
        (*(void(**)(void*))(self + 0x1dc))(self);
    }
    *(void**)(self + 0x1dc) = 0;
    DestroyTreeNode_02184604(self, (unsigned char*)self);

    volatile unsigned int* regA = (volatile unsigned int*)0x4000000;
    *regA = (*regA & ~0x1f00) | 0x100;

    ClearFlag0x10IfSet((struct Struct02074bd0*)(self + 0x194));
    ClearFlag0x11IfSet((struct Struct02074bf4*)(self + 0x194));

    volatile unsigned short* reg304 = (volatile unsigned short*)0x4000304;
    int flag190 = *(int*)(self + 0x190);
    *reg304 = (flag190 << 15) | (*reg304 & ~0x8000);

    ShiftInBitOnGlobalObject();
    CallFunc02030110OnGlobalObject();

    void* buf = data_0211e33c;
    memset(buf, 0, 0x600);
    CleanInvalidateCacheRange(buf, 0x20);
    TransferBg1CharData((int)buf, 0, 0x20);
    CleanInvalidateCacheRange(buf, 0x600);
    func_020c5b98(buf, 0, 0x600);

    unsigned int f1a8 = *(unsigned int*)(self + 0x1a8);
    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    volatile unsigned int* reg1000 = (volatile unsigned int*)0x4001000;
    *reg0 = (f1a8 << 8) | (*reg0 & ~0x1f00);
    unsigned int f1ac = *(unsigned int*)(self + 0x1ac);
    *reg1000 = (f1ac << 8) | (*reg1000 & ~0x1f00);

    int listPtr = GetData02104304Field4();
    int key = func_ov023_021f6bb8(self + 0x118);
    func_020301c8(listPtr, key);

    HalveGlobalObjectCounter();
    ClearBitsInField4((unsigned int*)func_ov017_0218b5b0(), 0xc0);
}
