#include <globaldefs.h>

extern "C" void func_0202e9a4(void* obj, int val);

// USA: func_0202f0c4
ARM void SetFields0x1f0And0x1f4(void* obj, int a, int b) {
    *(int*)((char*)obj + 0x1f0) = a;
    *(int*)((char*)obj + 0x1f4) = b;
    if (b == 0) {
        func_0202e9a4(obj, a);
    }
}
