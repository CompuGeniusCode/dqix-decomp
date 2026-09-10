#include <globaldefs.h>

struct Struct0204a82c;
struct Record0204acb0 { unsigned char pad[0x10]; };
extern "C" void func_0204a82c(struct Struct0204a82c* s);
extern "C" void func_0204acb0(struct Record0204acb0* rec);

struct List0204afb4 {
    unsigned char pad0[0xc];
    unsigned char fc;              // 0xc
    unsigned char pad_d;           // 0xd
    unsigned short fe;             // 0xe
    struct Record0204acb0* f10;    // 0x10
    int f14;                       // 0x14
    unsigned char pad18[0x5];      // 0x18..0x1c
    unsigned char f1d;             // 0x1d
};

// Tears a background layer down: drops the screen buffer pointer at +0x14, resets the same
// leading fields ResetBackgroundLayer does, and clears every tilemap record the layer owns --
// the 0x10-byte {width, height, ..., buffer} descriptors func_0204af14 hands out.
// It deliberately leaves the engine/BG assignment at +0x1c and the screen-size fields alone.
// ov020's company-logo setup uses it exactly that way on a stack layer, right after the tilemap
// has been uploaded, so it reads as the teardown half of ResetBackgroundLayer.
extern "C" ARM void ResetBackgroundLayerTilemaps(struct List0204afb4* obj) {
    unsigned char i;
    obj->f14 = 0;
    func_0204a82c((struct Struct0204a82c*)obj);
    obj->fc = 0;
    obj->fe = 0xffff;
    if (obj->f10 == 0) return;
    i = 0;
    while (i < obj->f1d) {
        func_0204acb0(&obj->f10[i]);
        i++;
    }
}
