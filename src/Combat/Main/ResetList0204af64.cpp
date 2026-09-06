#include <globaldefs.h>

struct Struct0204a82c;
ARM void ClearStruct0204a82c(struct Struct0204a82c*);

struct List0204af64 {
    char pad0[0xc];
    unsigned char b0c;
    unsigned char pad0d;
    unsigned short h0e;
    int w10;
    int w14;
    int w18;
    unsigned char b1c_lo : 4;
    unsigned char b1c_hi : 4;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;
};

// USA: func_0204af64
ARM void ResetList0204af64(struct List0204af64* obj) {
    ClearStruct0204a82c((struct Struct0204a82c*)obj);
    obj->b0c = 0;
    obj->h0e = 0xffff;
    obj->w10 = 0;
    obj->w14 = 0;
    obj->w18 = 0;
    obj->b1c_lo = 0;
    obj->b1c_hi = 0;
    obj->b1d = 0;
    obj->b1e = 0;
    obj->b1f = 0;
}
