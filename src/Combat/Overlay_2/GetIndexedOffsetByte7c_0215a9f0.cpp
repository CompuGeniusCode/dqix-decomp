#include <globaldefs.h>

extern int data_ov002_0216c9dc;

// USA: func_ov002_0215a9f0
ARM signed char GetIndexedOffsetByte7c_0215a9f0(void* obj) {
    unsigned char* p = (unsigned char*)obj + 0x1c00;
    short idx = *(short*)(p + 0xa);
    int off = (&data_ov002_0216c9dc)[idx];
    unsigned char* q = (unsigned char*)obj + off + 0x1c00;
    return *(signed char*)(q + 0x7c);
}
