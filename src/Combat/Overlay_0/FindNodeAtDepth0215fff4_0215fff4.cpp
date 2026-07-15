#include <globaldefs.h>

// USA: func_ov000_0215fff4
ARM void* FindNodeAtDepth0215fff4(void* obj, int limit, int idx) {
    unsigned char* bytePtr = (unsigned char*)obj + idx;
    if (bytePtr[0x18] <= limit) return 0;
    void* node = *(void**)((char*)obj + idx * 4);
    int i = 0;
    while (i < limit && node != 0) {
        node = *(void**)((char*)node + 0x20);
        i++;
    }
    return node;
}
