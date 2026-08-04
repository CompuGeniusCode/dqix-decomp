#include <globaldefs.h>

extern "C" void* func_0200d9e4(void* ptr, int* outVal);

struct Ctx0200f1fc {
    char pad[4];
    unsigned char* data;
};

struct Self0200f1fc {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1[0x38 - 0x1c];
    int f38;
    char pad2[0x48 - 0x3c];
    int f48;
    char pad3[0x60 - 0x4c];
    int f60;
    int f64;
    unsigned short f68;
    unsigned char f6a;
    unsigned char f6b;
    unsigned char f6c;
};

// USA: func_0200f1fc  (semantic: DecodeHeaderFlags0200f1fc)
extern "C" ARM void func_0200f1fc(Self0200f1fc* self, Ctx0200f1fc* ctx) {
    unsigned char* data = ctx->data;
    unsigned char byte0 = data[0];
    int flag40 = byte0 & 0x40;
    self->f6b = flag40 ? 1 : 0;
    self->f6a = (byte0 & 0x20) ? 1 : 0;
    int flag80 = byte0 & 0x80;
    self->f6c = flag80 ? 1 : 0;
    unsigned char byte1 = data[1];
    unsigned char* srcPtr = data + 2;
    self->f68 = byte1 << 4;
    self->f68 = self->f68 | 0x4000;
    srcPtr = (unsigned char*)func_0200d9e4(srcPtr, &self->f60);
    if (flag40 != 0) {
        func_0200d9e4(srcPtr, &self->f64);
    }
    if (flag40 != 0) {
        if (flag80 != 0) {
            self->f18 = self->f38;
        } else {
            self->f18 = self->f48;
        }
    } else {
        self->f18 = self->f14;
    }
}
