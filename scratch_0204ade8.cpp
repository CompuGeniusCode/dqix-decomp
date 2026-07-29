#include <globaldefs.h>
#include "std_library_functions.h"

int EncodeStreamFields020dc0e0(int a, int b, int c, int d, unsigned char e, unsigned char f);
extern int data_020e7b68[];

// USA: func_0204ade8
ARM void EncodeIndexedStreamValueField0204ade8(void* obj, int idx, int c, void* d) {
    memcpy((char*)obj + 8, (char*)d + 0xc, 4);
    int dArg = *(int*)((char*)obj + 8);
    EncodeStreamFields020dc0e0(data_020e7b68[idx] + (c << 1), (int)((char*)d + 0x10), 0, dArg, 1, 0);
}
