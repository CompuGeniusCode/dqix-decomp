#include <globaldefs.h>
#include "std_library_functions.h"

int EncodeStreamFields020dc0e0(int a, int b, int c, int d, unsigned char e, unsigned char f);
extern int data_020e7b70[];

// USA: func_0204a9c4
ARM void EncodeIndexedStreamValue0204a9c4(int* obj, int idx, int c, void* d) {
    if (d == NULL) {
        return;
    }
    int temp;
    memcpy(&temp, (char*)d + 0xc, 4);
    int a = c << 1;
    int cArg = *obj;
    a += data_020e7b70[idx];
    void* b = (char*)d + 0x10;
    EncodeStreamFields020dc0e0(a, (int)b, cArg, temp, 1, 0);
}
