#include <globaldefs.h>

extern "C" int func_020b2d60(void*, void*);

// USA: func_020b2dd4
ARM void RemoveNodeFromAnyList020b2dd4(void* self, void* node) {
    if (func_020b2d60((char*)self + 8, node) ||
        func_020b2d60((char*)self + 0x10, node) ||
        func_020b2d60((char*)self + 0x18, node)) {
        *(unsigned int*)self |= 0x10;
    }
}
