#include <globaldefs.h>

struct Obj0204b010 { char b[0x20]; };
extern "C" void ClearBackgroundScreenBuffer(Obj0204b010*, void*);

struct Cont0205d1e0 {
    char pad0[0x98];
    Obj0204b010* list98;
    char pad9c[0x16];
    unsigned char countB2;
};

// Blanks the tilemap of every background layer this object owns. ClearBackgroundScreenBuffer memsets an
// entry's buffer using data_020e7b98[kind][size], and the two rows of that table are
// 0x800/0x1000/0x1000/0x2000 and 0x200/0x800/0x2000/0x8000 -- the DS text and extended affine
// map sizes for the four BGxCNT screen-size codes -- so +0x1f is the layer kind and +0x18 its
// screen size. The layer count is the byte at +0xb2, the same one UploadAllBGScreenData iterates.
extern "C" ARM void ClearBgTilemaps(Cont0205d1e0* obj) {
    unsigned char i;
    if (obj->list98 == NULL) return;
    for (i = 0; i < obj->countB2; i++) {
        ClearBackgroundScreenBuffer(&obj->list98[i], NULL);
    }
}
