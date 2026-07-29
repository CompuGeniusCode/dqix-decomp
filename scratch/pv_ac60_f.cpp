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
    int b = (int)((char*)src + 0xc);
    _Z26EncodeStreamFields020dc0e0iiiihh(data_020e7b60[index], b, 0, val, 1, 0);
}
