#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0();

struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
int TransferBg1CharData(int arg0, int arg1, unsigned int arg2);

// USA: func_ov003_02174454
extern "C" ARM void func_ov003_02174454(char* self) {
    unsigned char i;

    int data4 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(self + 0xfec) >= 0) {
        ((BackgroundLoader*)(data4))->RemoveTask((int)(*(int*)(self + 0xfec)));
        *(int*)(self + 0xfec) = -1;
    }

    unsigned char* g = (unsigned char*)GetGlobalField0x1c020421a0();
    *(int*)(g + 0x2d8) = 0;
    g[0x2e6] = 1;

    unsigned int* reg = (unsigned int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(unsigned short*)0x4000050 = 0;
    ClearFlag0x10IfSet((struct Struct02074bd0*)(self + 0x24));

    if (*(void**)(self + 0xff4) != 0) {
        memset(*(void**)(self + 0xff4), 0, 0x20);
        CleanInvalidateCacheRange(*(void**)(self + 0xff4), 0x20);
        TransferBg1CharData((int)*(void**)(self + 0xff4), 0, 0x20);
    }
    *(void**)(self + 0xff4) = 0;

    if (*(void**)(self + 4) == 0) return;

    for (i = 0; i < 6; i++) {
        ((SafeAllocator*)(*(char**)(self + 4) + i * 0x14))->Destroy();
    }
}
