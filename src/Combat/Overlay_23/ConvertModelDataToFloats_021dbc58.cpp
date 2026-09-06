#include <globaldefs.h>

extern "C" void func_020dd7ac(void*);
extern "C" void func_020dd8b4(int, int, int, int);

struct RawModelData_021dbc58 {
    char pad0[0x3e];
    unsigned short h3e;
    char pad40[0x42 - 0x40];
    unsigned short h42;
    char pad44[0x48 - 0x44];
    int i48;
    char pad4c[0x50 - 0x4c];
    int i50;
    char pad54[0x58 - 0x54];
    int i58;
    char pad5c[0x66 - 0x5c];
    unsigned short h66;
    char pad68[0x6a - 0x68];
    unsigned short h6a;
    char pad6c[0x6e - 0x6c];
    unsigned short h6e;
    char pad70[0x72 - 0x70];
    unsigned short h72;
    char pad74[0x76 - 0x74];
    unsigned short h76;
    char pad78[0x7a - 0x78];
    unsigned short h7a;
};

struct FloatModelOut_021dbc58 {
    float f0;
    float f4;
    int f8;
    int fc;
    int f10;
    int f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
};

// USA: func_ov023_021dbc58
ARM void ConvertModelDataToFloats_021dbc58(void* obj, FloatModelOut_021dbc58* dest, int flagC) {
    RawModelData_021dbc58 raw;
    func_020dd7ac(&raw);
    func_020dd8b4((int)&raw, (int)obj, flagC, 1);

    dest->f0 = raw.h3e;
    dest->f4 = raw.h42;
    dest->f8 = raw.i48;
    dest->fc = raw.i50;
    dest->f10 = raw.i58;
    dest->f14 = 0;
    dest->f18 = raw.h66;
    dest->f1c = raw.h6a;
    dest->f20 = raw.h6e;
    dest->f24 = raw.h72;
    dest->f28 = raw.h76;
    dest->f2c = raw.h7a;
}
