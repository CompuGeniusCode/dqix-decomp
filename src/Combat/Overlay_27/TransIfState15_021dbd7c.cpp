#include <globaldefs.h>

struct FieldHolder021dbd7c {
    unsigned int field0;
    unsigned int field4;
    unsigned char* field8;
};

extern FieldHolder021dbd7c data_ov027_021e33e0;

typedef void (*Callback021dbd7c)(int, void*);

struct Obj021dbd7c {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
};

// USA: func_ov027_021dbd7c  (semantic: TransIfState15_021dbd7c)
extern "C" ARM void func_ov027_021dbd7c(Obj021dbd7c* obj) {
    if (obj->f2 != 0) return;
    switch (obj->f4) {
    case 7:
    case 9:
        break;
    case 0x19:
    case 0x1a:
        break;
    case 0x15: {
        Callback021dbd7c fn = *(Callback021dbd7c*)(data_ov027_021e33e0.field8 + 0x51c);
        fn(9, obj);
        break;
    }
    default:
        break;
    }
}
