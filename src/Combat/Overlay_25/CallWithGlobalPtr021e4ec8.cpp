#include <globaldefs.h>

extern void* data_ov025_021ef988;

extern "C" void func_ov025_021e8af8(void* param);

// USA: func_ov025_021e4ec8
ARM int CallWithGlobalPtr021e4ec8(void) {
    func_ov025_021e8af8(*(void**)((char*)&data_ov025_021ef988 + 0xc));
    return 1;
}
