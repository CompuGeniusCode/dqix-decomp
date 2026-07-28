#include <globaldefs.h>

extern char* data_ov004_0217101c;
extern "C" void* func_ov023_021f6524(void* ctx, int value, short a, short b);

// USA: func_ov004_02166730
ARM int TestDiv8_02166730(void* obj, short key) {
    void* node = *(void**)(data_ov004_0217101c + 8);
    short index = 0;
    while (node != NULL) {
        if (*(short*)((char*)node + 0) == key) break;
        index++;
        node = *(void**)((char*)node + 8);
    }
    short v6 = index / 8;
    short v7 = index % 8;
    void* r = func_ov023_021f6524(obj, 0x5b, v6, v7);
    (void)r;
    return 0;
}
