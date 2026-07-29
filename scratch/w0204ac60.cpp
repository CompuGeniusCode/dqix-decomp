#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void _Z26EncodeStreamFields020dc0e0iiiihh(int a, int b, int c, int d, unsigned char e, unsigned char f);
extern int data_020e7b60[];

struct Src0204ac60 {
    char pad[8];
    int field8;
};

// USA: func_0204ac60
extern "C" ARM void SendEncodedStream0204ac60(void* unused, int index, struct Src0204ac60* src) {
    int val;
    memcpy(&val, &src->field8, 4);
    unsigned char e = 1;
    int* table = data_020e7b60;
    unsigned char f = 0;
    int c = 0;
    int a = table[index];
    int d = val;
    int b = (int)((char*)src + 0xc);
    _Z26EncodeStreamFields020dc0e0iiiihh(a, b, c, d, e, f);
}
