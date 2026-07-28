#include <globaldefs.h>
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0(void);
extern "C" int func_0205d6e4(void* obj, int flag);
extern "C" void func_ov003_0216abd8(void* obj, void* buf);
extern "C" void func_0204500c(void* dst, void* src, int a, int b);

// USA: func_ov003_02169430  (semantic: InitOrClearEntry_02169430)
extern "C" ARM void func_ov003_02169430(void* p) {
    char* obj = (char*)p;
    int g = GetGlobalField0x1c020421a0();
    unsigned char state = *(unsigned char*)(obj + 0x4e8);
    if (state == 0) {
        func_0205d6e4(obj + 0xe4, 1);
        memset(*(void**)(obj + 0x7c), 0, 0x960);
        func_ov003_0216abd8(obj, *(void**)(obj + 0x7c));
        func_0204500c((void*)g, *(void**)(obj + 0x7c), 0, 0xe3);
        *(unsigned char*)(obj + 0x4e8) = *(unsigned char*)(obj + 0x4e8) + 1;
    } else if (state == 1) {
        if (*(int*)((char*)g + 0x998) == 0) {
            *(unsigned char*)(obj + 0x4ec) = 6;
            *(unsigned char*)(obj + 0x4e8) = 0;
        }
    }
}
