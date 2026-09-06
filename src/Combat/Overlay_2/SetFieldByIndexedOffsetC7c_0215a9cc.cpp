#include <globaldefs.h>

extern int data_ov002_0216c9c0;

// USA: func_ov002_0215a9cc
ARM void SetFieldByIndexedOffsetC7c_0215a9cc(void* obj, int val) {
    unsigned char* p = (unsigned char*)obj + 0x1c00;
    short idx = *(short*)(p + 0xa);
    int off = (&data_ov002_0216c9c0)[idx];
    unsigned char* q = (unsigned char*)obj + off + 0x1000;
    q[0xc7c] = (unsigned char)val;
}
