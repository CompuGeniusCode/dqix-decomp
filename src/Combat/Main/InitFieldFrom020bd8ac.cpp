#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void* func_020bd8ac(void* arg);

// USA: func_020c0110
ARM int InitFieldFrom020bd8ac(char* obj, void* arg) {
    void* p = func_020bd8ac(arg);
    *(void**)(obj + 0xa4) = p;
    VectorizedInvertedMemcpy(p, obj + 0xa8, 0x40);
    return 1;
}
