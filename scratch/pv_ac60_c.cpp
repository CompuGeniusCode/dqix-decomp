#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void _Z26EncodeStreamFields020dc0e0iiiihh(int a, int b, int c, int d, unsigned char e, unsigned char f);
extern int data_020e7b60[];

struct Src0204ac60 {
    char pad[8];
    int field8;
};

extern "C" ARM void F(void* unused, int index, struct Src0204ac60* src) {
    int val;
    memcpy(&val, &src->field8, 4);
    unsigned char a5 = 1;
    unsigned char a6 = 0;
    int a1 = data_020e7b60[index];
    int a4 = val;
    int a2 = (int)((char*)src + 0xc);
    int a3 = 0;
    _Z26EncodeStreamFields020dc0e0iiiihh(a1, a2, a3, a4, a5, a6);
}
