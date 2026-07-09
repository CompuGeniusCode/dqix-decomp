#include <globaldefs.h>

struct S020d8fcc {
    unsigned int pad0;
    unsigned int f4 : 24;
    unsigned int f4hi : 8;
    unsigned int f8 : 24;
    unsigned int f8hi : 8;
};

// USA: func_020d8fcc
ARM int GetDataPtrAndValue020d8fcc(void** outPtr, unsigned int* outVal, unsigned char* base, struct S020d8fcc* s) {
    unsigned int off;
    if (s == NULL) {
        return 0;
    }
    off = s->f4 * 4 + ((unsigned int)*(unsigned short*)(base + 0xa) << 2);
    *outPtr = base + off;
    *outVal = s->f8;
    return 1;
}
