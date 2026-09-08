#include <globaldefs.h>

struct InitStruct02075cdcStruct {
    int f00; int f04; int f08; int f0c;
    int f10; int f14; int f18; int f1c;
    int f20; int f24; int f28; int f2c;
    short f30; short pad32;
    int f34; int f38; int f3c; int f40;
    int f44; int f48; int f4c; int f50; int f54; int f58;
    short f5c; unsigned char f5e; unsigned char f5f;
    int f60; int f64; int f68; int f6c;
};
extern "C" void _Z18InitStruct02075cdcP24InitStruct02075cdcStruct(struct InitStruct02075cdcStruct* s);

struct Struct0215479c {
    struct InitStruct02075cdcStruct base;
    int f70;
    short f74;
    short f76;
    short f78;
    unsigned char f7a;
};

// USA: func_ov006_0215479c
#pragma opt_propagation off
extern "C" ARM void func_ov006_0215479c(struct Struct0215479c* self) {
    _Z18InitStruct02075cdcP24InitStruct02075cdcStruct(&self->base);
    self->f70 = -1;
    int zero = 0;
    self->f74 = -1;
    self->f78 = zero;
    self->f76 = zero;
    self->f7a = zero;
}
