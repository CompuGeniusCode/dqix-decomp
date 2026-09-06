#include <globaldefs.h>

extern void* data_ov025_021ef988;

extern "C" void func_ov025_021e8b6c(void* param);

// USA: func_ov025_021e4ee4
ARM int CallWithGlobalPtr021e4ee4(void) {
    func_ov025_021e8b6c(*(void**)((char*)&data_ov025_021ef988 + 0xc));
    return 1;
}
