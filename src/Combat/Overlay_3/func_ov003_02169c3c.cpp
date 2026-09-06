#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
extern void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Elem_0205d81c;
struct Struct_0205d81c;
extern struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);

extern "C" void func_ov003_02169d10(void* obj, void* ptr7c, int flag);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov003_02169c3c
extern "C" ARM void func_ov003_02169c3c(char* obj) {
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0xe4), 0, 2);

    *(short*)(obj + 0x184) = 0xe;
    *(short*)(obj + 0x186) = 7;
    *(short*)(obj + 0x188) = 0x11;
    *(short*)(obj + 0x18a) = 7;
    *(short*)(obj + 0x18c) = 8;
    *(short*)(obj + 0x18e) = 0x10;
    *(short*)(obj + 0x190) = 0xc;
    *(short*)(obj + 0x192) = 0xe;

    obj[0x195] = 2;
    obj[0x199] = 1;
    obj[0x4ee] = 3;

    memset(*(void**)(obj + 0x7c), 0, 0x960);
    func_ov003_02169d10(obj, *(void**)(obj + 0x7c), 0);
    func_0205d304(obj + 0xe4, *(void**)(obj + 0x7c), 0, 0, 0, 0, 0, 1);

    struct Elem_0205d81c* e = FindElementByC40205d81c((struct Struct_0205d81c*)(obj + 0xe4), 2);
    *((unsigned char*)e + 0xc6) = 0;
}
