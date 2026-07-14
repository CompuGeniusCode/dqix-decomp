#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_0200f374(void* buf, int len);
extern "C" int func_02001aec(void* a, void* b, int n);

typedef void (*Fn0204a984)(void*, int, int);
void InvokeWithCopiedArg0204a984(int* a0, Fn0204a984 fn, char* ctx);

typedef void (*Callback0204abcc)(void*, int, int);
struct Obj0204abcc;
struct P0204abcc;
void ForEachMaskedChunk0204abcc(struct Obj0204abcc* obj, Callback0204abcc fn, struct P0204abcc* p);

typedef void (*Callback0204adb4)(void*, int, int);
void CopyWordAndInvokeCallback0204adb4(unsigned char* dst, Callback0204adb4 callback, unsigned char* src);

struct Record0204acb0 { int w0, w4, w8, wc; };
void ClearRecordFields(struct Record0204acb0* rec);

extern char data_020f0238;
extern char data_020f023d;
extern char data_020f0242;
extern int data_020f01f8[][4];
extern Callback0204abcc data_020f01b0[];
extern int data_020f0218[][4];

struct SelfTag0204b3a0 {
    unsigned char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

// USA: func_0204b3a0
ARM void DispatchByTagLookup0204b3a0(struct SelfTag0204b3a0* self, char* str) {
    char buf[5];

    if (str == 0) {
        return;
    }

    func_0200f374(buf, 5);
    memcpy(buf, str, 5);

    if (func_02001aec(buf, &data_020f0238, 4) == 0) {
        Fn0204a984 fn = (Fn0204a984)data_020f01f8[self->lo][self->hi];
        InvokeWithCopiedArg0204a984((int*)self, fn, str);
        return;
    }

    if (func_02001aec(buf, &data_020f023d, 4) == 0) {
        Callback0204abcc fn = data_020f01b0[self->lo];
        ForEachMaskedChunk0204abcc((struct Obj0204abcc*)((char*)self + 0xc), fn, (struct P0204abcc*)str);
        return;
    }

    if (func_02001aec(buf, &data_020f0242, 4) == 0) {
        struct Record0204acb0 rec;
        ClearRecordFields(&rec);
        Callback0204adb4 fn = (Callback0204adb4)data_020f0218[self->lo][self->hi];
        CopyWordAndInvokeCallback0204adb4((unsigned char*)&rec, fn, (unsigned char*)str);
    }
}
