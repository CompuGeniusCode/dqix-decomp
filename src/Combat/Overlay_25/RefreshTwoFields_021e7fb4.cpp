#include <globaldefs.h>

extern int data_ov025_021ef988;
extern "C" void func_ov025_021e9d14(void* p);
extern "C" void func_ov025_021e9edc(void* p);

// USA: func_ov025_021e7fb4
ARM int RefreshTwoFields_021e7fb4() {
    char* p = *(char**)((char*)&data_ov025_021ef988 + 0xc);
    func_ov025_021e9d14(p);
    p = *(char**)((char*)&data_ov025_021ef988 + 0xc);
    func_ov025_021e9edc(p);
    return 1;
}
