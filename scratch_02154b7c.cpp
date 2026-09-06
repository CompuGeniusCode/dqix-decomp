#include <globaldefs.h>

extern "C" void func_ov004_02153978(void* obj, short* outAt4, short* outAt2, short* outAt0);
extern "C" short func_ov004_021537e0(void);
extern "C" short func_ov004_02153860(void);
extern "C" short func_ov004_021538f0(void);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" void func_ov023_021f645c(void* obj, int a, int b, int c);
extern "C" void func_ov023_021f64a8(void* obj, int a, unsigned short b, int c);
extern "C" void func_ov023_021f809c(void* node, void* obj);

extern char* data_ov004_021707c0; // pointer to struct with fields at 0x78 (short), 0x7a (short)

struct Struct78_7a { short f78; short f7a; };

// USA: func_ov004_02154b7c
extern "C" ARM int func_ov004_02154b7c(void* obj) {
    short a4, a2, a0;
    func_ov004_02153978(obj, &a4, &a2, &a0);

    int tag = 0x32;
    unsigned short val;
    if (a4 != 0) goto notDefault;
    val = *(short*)(data_ov004_021707c0 + 0x7a);
    goto valDone;
notDefault:
    if (a2 == 0) {
        val = func_ov004_021537e0();
        tag = 0x33;
    } else if (a4 == 3) {
        val = func_ov004_021538f0();
        tag = 0x34;
    } else {
        val = func_ov004_02153860();
        tag = 0x34;
    }
valDone:

    func_ov023_021f645c(obj, 7, tag, 0xf);
    func_ov023_021f64a8(obj, 0x14, val, 0xf);

    void* node = func_ov023_021f6880(func_ov011_021849c8(obj), 0x10);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 6) return 0;
    func_ov023_021f809c(node, obj);
    return 0;
}
