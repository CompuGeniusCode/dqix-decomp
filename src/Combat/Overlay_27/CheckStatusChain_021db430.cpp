#include <globaldefs.h>

struct Obj021db430 {
    unsigned char pad0[0x50c];
    unsigned char f50c;
    unsigned char pad1[0x526 - 0x50d];
    unsigned short f526;
    unsigned short f528;
    unsigned short f52a;
};

struct DataStruct021db430 {
    unsigned char pad0[8];
    Obj021db430* obj;
};

extern DataStruct021db430 data_ov027_021e33e0;

// USA: func_ov027_021db430  (semantic: CheckStatusChain_021db430)
extern "C" ARM int func_ov027_021db430(void) {
    int result = 0;
    int b = 0;
    int a = 0;
    Obj021db430* obj = data_ov027_021e33e0.obj;
    if (obj->f528 == 1 && obj->f50c == 0) {
        a = 1;
    }
    if (a) {
        if (obj->f526 == 0) {
            b = 1;
        }
    }
    if (b) {
        if (obj->f52a != 0) {
            result = 1;
        }
    }
    return result;
}
