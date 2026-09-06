#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_020269e4
ARM void AppendRecord020269e4(char* obj, const void* src) {
    unsigned char count = *(unsigned char*)(obj + 0x780);
    if (count >= 0x14) return;
    if (src == NULL) return;
    VectorizedInvertedMemcpy(src, obj + 0x784 + count * 0x1c, 0x1c);
    *(unsigned char*)(obj + 0x780) += 1;
}
