#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct Global020fdc20_d4ec {
    int pad0;
    int pad4;
    unsigned char* obj; // 0x8
};
extern struct Global020fdc20_d4ec data_020fdc20;

// USA: func_0201d4ec
extern "C" ARM int _Z20WarpScript_Opcode_70PN6Script9ParameterEi(struct Variant02030b0c* v) {
    int a = _ZNK6Script9Parameter5ToIntEv(v);
    int b = _ZNK6Script9Parameter5ToIntEv(v + 1);
    int c = _ZNK6Script9Parameter5ToIntEv(v + 2);
    *(unsigned short*)(data_020fdc20.obj + 0x7e) = a | (b << 5) | (c << 10);
    return 1;
}
