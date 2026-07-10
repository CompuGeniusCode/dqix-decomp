#include <globaldefs.h>

extern "C" void func_020370a0(void*, int, int);

// USA: func_02041628
ARM void SetByte0x2e8AndDispatch02041628(void* obj, int v) {
    unsigned char* p = (unsigned char*)obj + 0x2e8;
    *p = v;
    func_020370a0(obj, *p, 0);
}
