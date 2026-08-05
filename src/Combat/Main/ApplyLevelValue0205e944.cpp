#include <globaldefs.h>

void SetEntryByte(int index, int value);
extern float data_020e7dd4[];

struct Struct0205e944 {
    unsigned char pad0[0xc8];
    int fc8;
    unsigned char fcc;
};

// USA: func_0205e944  (semantic: ApplyLevelValue0205e944)
extern "C" ARM void func_0205e944(Struct0205e944* obj, int level) {
    float f;
    int value;
    obj->fc8 = level;
    f = (float)level;
    f = f * data_020e7dd4[obj->fcc - 1];
    value = (int)f;
    SetEntryByte(0xa, value);
    SetEntryByte(0xb, value);
    SetEntryByte(0xc, value);
    SetEntryByte(0xd, value);
    SetEntryByte(0xe, value);
    SetEntryByte(0xf, value);
    SetEntryByte(0xa, value);
    SetEntryByte(0xc, value);
    SetEntryByte(0xd, value);
    SetEntryByte(0x10, value);
}
