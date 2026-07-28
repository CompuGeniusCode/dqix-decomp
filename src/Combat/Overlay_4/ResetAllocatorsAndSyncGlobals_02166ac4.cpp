#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern char* data_ov004_0217101c;
int GetData02104304Field4();
extern "C" void func_020301c8(int a, int b);
extern "C" void* func_0205ec34(void);
int* GetGlobal02109418(void);
int GetGlobalField0x1c020421a0(void);

// USA: func_ov004_02166ac4  (semantic: ResetAllocatorsAndSyncGlobals_02166ac4)
extern "C" ARM int func_ov004_02166ac4() {
    char* base = data_ov004_0217101c;
    int a = GetData02104304Field4();
    int b = *(int*)(base + 0x44);
    func_020301c8(a, b);
    *(int*)(base + 0x44) = -1;
    ((SafeAllocator*)(base + 0x30))->Destroy();
    ((SafeAllocator*)(base + 0x1c))->Destroy();
    char* c = (char*)func_0205ec34();
    memcpy(c + 0x2cc, data_ov004_0217101c + 0x51, 0x66);
    int* g = GetGlobal02109418();
    *(int*)((char*)g + 0xa0) = *(int*)(data_ov004_0217101c + 0xb8);
    char* f = (char*)GetGlobalField0x1c020421a0();
    *(unsigned char*)(f + 0x1000 + 0x962) = 0;
    return 0;
}
