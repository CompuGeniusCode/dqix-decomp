#include <globaldefs.h>
#include "System/Memory.h"

void CopyHeaderAndDispatch_02200850(void* a, unsigned int b, void* c, unsigned int d);

extern unsigned char data_ov031_0224ce68[6];

struct GlobalStruct0224c980_022017c4 {
    unsigned char pad[0x50];
    unsigned int field50;
};
extern GlobalStruct0224c980_022017c4 data_ov031_0224c980;

// USA: func_ov031_022017c4
extern "C" ARM void func_ov031_022017c4(void* a) {
    char* obj = (char*)a;
    *(unsigned short*)(obj + 0x6) = 0x200;
    VectorizedInvertedMemcpy(obj + 0x8, obj + 0x12, 0xa);
    VectorizedInvertedMemcpy(data_ov031_0224ce68, obj + 0x8, 6);

    unsigned int v = data_ov031_0224c980.field50;
    unsigned short hi = (unsigned short)(v >> 16);
    hi = (unsigned short)((hi >> 8) | (hi << 8));
    *(unsigned short*)(obj + 0xe) = hi;

    unsigned int v2 = data_ov031_0224c980.field50;
    unsigned short lo = (unsigned short)v2;
    lo = (unsigned short)((lo >> 8) | (lo << 8));
    *(unsigned short*)(obj + 0x10) = lo;

    VectorizedInvertedMemcpy(obj + 0x12, obj - 0xe, 6);
    VectorizedInvertedMemcpy(data_ov031_0224ce68, obj - 0x8, 6);
    CopyHeaderAndDispatch_02200850(obj - 0xe, 0x2a, NULL, 0);
}
