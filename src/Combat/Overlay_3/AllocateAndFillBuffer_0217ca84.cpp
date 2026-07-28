#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_020c6688(void);
extern "C" void func_020c66bc(void* ptr, int a, unsigned int b);
extern "C" void func_020c6728(void);
void PushOneBitField0x3c(void);
int GetField0x580207ecc4(void* obj);
int GetIntAt0xa4(unsigned char* obj);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void HalveField0x3c020dc098(void);

struct S0217ca84 {
    SafeAllocator* allocator;
    char pad4[0x88 - 4];
    void* field88;
};

struct Inner0217ca84 {
    char pad0[0x2c];
    int field2c;
    char pad30[0x30 - 0x30];
    unsigned short field30;
};

// USA: func_ov003_0217ca84  (semantic: AllocateAndFillBuffer_0217ca84)
extern "C" ARM void func_ov003_0217ca84(S0217ca84* obj, unsigned short fillValue) {
    GetBattleStruct();
    PushOneBitField0x3c();
    func_020c6688();

    void* p88 = obj->field88;
    if (p88 != NULL) {
        Inner0217ca84* inner = (Inner0217ca84*)GetField0x580207ecc4(p88);
        if (inner != NULL) {
            int size = inner->field2c;
            if (GetIntAt0xa4((unsigned char*)obj + 0x80)) {
                size = GetIntAt0xa4((unsigned char*)obj + 0x80);
            }

            void* buf;
            unsigned int allocSize = (unsigned int)inner->field30 << 3;
            int scaledSize = (unsigned short)size << 3;

            buf = obj->allocator->Allocate(allocSize);
            if (buf != NULL) {
                unsigned int i;
                for (i = 0; i < allocSize / 2; i++) {
                    ((unsigned short*)buf)[i] = fillValue;
                }
                CleanInvalidateCacheRange(buf, allocSize);
                func_020c66bc(buf, scaledSize, allocSize);
            }
        }
    }

    func_020c6728();
    HalveField0x3c020dc098();
}
