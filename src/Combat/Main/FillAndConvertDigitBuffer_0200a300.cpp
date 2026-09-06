#include <globaldefs.h>

struct Obj0200a300 {
    unsigned char pad0[2];
    short f2;
    unsigned char f4;
    unsigned char arr[1];
};

struct Template0200a300 {
    unsigned char pad0[2];
    short f2;
};

extern "C" void func_0200a180(Obj0200a300* obj);
extern "C" void func_0200966c(Obj0200a300* obj, int count);

// USA: func_0200a300  (semantic: FillAndConvertDigitBuffer_0200a300)
extern "C" ARM void func_0200a300(Template0200a300* tmpl, void* unused1, void* unused2, Obj0200a300* o) {
    short maxCount = tmpl->f2;
    func_0200a180(o);
    if (o->arr[0] > 9) return;
    if (maxCount > 0x20) maxCount = 0x20;
    func_0200966c(o, maxCount);
    if (o->f4 < maxCount) {
        do {
            o->arr[o->f4++] = 0;
        } while (o->f4 < maxCount);
    }
    int i = 0;
    o->f2 = o->f2 - (o->f4 - 1);
    if (i < o->f4) {
        do {
            *((unsigned char*)o + i + 5) += 0x30;
            i++;
        } while (i < o->f4);
    }
}
