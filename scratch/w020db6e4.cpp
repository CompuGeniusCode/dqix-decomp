#include <globaldefs.h>

extern "C" int GetObjectValue020db2dc(int a, int b);

struct Cell020db6e4 {
    unsigned int word;
    union {
        unsigned short raw;
        struct { unsigned short low10 : 10, mid2 : 2, hi4 : 4; } bits;
    } flags;
    unsigned short pad;
};

struct Obj020db6e4 {
    unsigned char pad0[0x3c];
    unsigned char field3c;
};

// USA: func_020db6e4
ARM void SetupCellGrid020db6e4(Obj020db6e4* obj, int val) {
    int dummy0, dummy1;
    Cell020db6e4* arr = (Cell020db6e4*)GetObjectValue020db2dc((int)obj, obj->field3c);
    unsigned short value = (unsigned short)(val | 0xf800);
    int i, j;
    unsigned int base;
    for (i = 0; i < 3; i++) {
        base = ((i << 6) & 0xff) | 0xc0000000;
        for (j = 0; j < 4; j++) {
            arr[j + i * 4 + 0x10].word = base | ((j & 7) << 22);
            arr[j + i * 4 + 0x10].flags.raw = value;
            arr[j + i * 4 + 0x10].flags.bits.mid2 = 2;
        }
    }
}
