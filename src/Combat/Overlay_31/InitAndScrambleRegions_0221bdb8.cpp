#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_020ca390(int a, void* b, unsigned int c);
extern "C" void func_ov031_0221bfe8(void* buf);
extern "C" void* func_ov031_0221b8e4(void* buf);

// USA: func_ov031_0221bdb8
ARM int InitAndScrambleRegions_0221bdb8(char* obj) {
    char buf[0x14];
    func_020ca390(0, obj, 0x400);
    int i = 0;
    do {
        *(unsigned char*)(obj + (i << 8) + 0xe7) = 0xff;
        i++;
    } while (i < 3);
    func_ov031_0221bfe8(buf);
    void* key = func_ov031_0221b8e4(buf);
    int k = 0;
    do {
        VectorizedInvertedMemcpy(key, obj + 0xf0, 0xe);
        obj += 0x100;
        k++;
    } while (k < 2);
    return 0;
}
