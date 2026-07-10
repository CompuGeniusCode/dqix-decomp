#include <globaldefs.h>

extern "C" int func_020bc0a4(int handle);

// USA: func_0209c6bc
ARM int IsHandleB8Active0209c6bc(void* obj) {
    return func_020bc0a4(*(short*)((char*)obj + 0xb8)) != 0;
}
