#include <globaldefs.h>

typedef void (*Fn0204b088)(int, int, int);

extern int data_020e7b98[][4];
extern Fn0204b088 data_020f0218[][4];

struct Obj0204b088 {
    unsigned char pad0[0x14];
    int field14;
    int field18;
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    unsigned char pad2[0x1f - 0x1d];
    unsigned char field1f;
};

// USA: func_0204b088
ARM void DispatchByNibble0204b088(struct Obj0204b088* obj, int val) {
    if (val == 0) {
        val = obj->field14;
        if (val == 0) return;
    }
    unsigned char lo = obj->lowNibble;
    unsigned char hi = obj->highNibble;
    unsigned char f1f = obj->field1f;
    int f18 = obj->field18;
    data_020f0218[lo][hi](val, 0, data_020e7b98[f1f][f18]);
}
