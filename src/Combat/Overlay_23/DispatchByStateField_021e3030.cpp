#include <globaldefs.h>

extern "C" void func_ov023_021e4e3c(void* obj);
extern "C" void func_ov023_021e33b4(void* obj);
extern "C" void func_ov023_021e3db0(void* obj);
extern "C" void func_ov023_021e3f34(void* obj);

// USA: func_ov023_021e3030  (semantic: DispatchByStateField_021e3030)
extern "C" ARM void func_ov023_021e3030(void* obj) {
    func_ov023_021e4e3c(obj);
    signed char state = *(signed char*)((char*)obj + 0x400 + 0xe6);
    if (state == 0) goto case0;
    if (state == 1) goto case1;
    if (state == 3) goto case3;
    return;
case0:
    func_ov023_021e33b4(obj);
    return;
case3:
    func_ov023_021e3db0(obj);
    return;
case1:
    func_ov023_021e3f34(obj);
    return;
}
