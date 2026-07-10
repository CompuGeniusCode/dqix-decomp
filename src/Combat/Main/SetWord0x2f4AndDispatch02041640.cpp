#include <globaldefs.h>

extern "C" void func_02036e34(void*, int, int);

// USA: func_02041640
ARM void SetWord0x2f4AndDispatch02041640(void* obj, int v) {
    int* p = (int*)((char*)obj + 0x2f4);
    *p = v;
    func_02036e34(obj, *p, 0);
}
