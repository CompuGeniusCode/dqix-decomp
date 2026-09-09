#include <globaldefs.h>

struct Struct0204a82c;
extern "C" ARM void func_0204a82c(struct Struct0204a82c*);

struct List0204af64 {
    char pad0[0xc];
    unsigned char b0c;
    unsigned char pad0d;
    unsigned short h0e;
    int w10;
    int w14;
    int w18;
    unsigned char b1c_lo : 4;
    unsigned char b1c_hi : 4;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;
};

// Clears a background-layer descriptor: the CHAR chunk header fields func_0204a8f4 copies in, the
// 0xffff id at +0xe, the three words at +0x10..+0x18 and the engine/BG nibbles at +0x1c. Only the
// descriptor is touched; no hardware register is written. The nibbles are what make this a
// per-engine, per-BG layer - func_0204b3a0 dispatches them through three parallel tables, one each
// for CHAR, PALT and SCRN, and func_02020cb8 sets them to (1,1) before calling SetBackgroundScroll. The
// words at +0x10..+0x18 are not established; the caller then puts 0x6000 in +0x0 and 0xfffe in +0xe.
extern "C" ARM void ResetBackgroundLayer(struct List0204af64* obj) {
    func_0204a82c((struct Struct0204a82c*)obj);
    obj->b0c = 0;
    obj->h0e = 0xffff;
    obj->w10 = 0;
    obj->w14 = 0;
    obj->w18 = 0;
    obj->b1c_lo = 0;
    obj->b1c_hi = 0;
    obj->b1d = 0;
    obj->b1e = 0;
    obj->b1f = 0;
}
