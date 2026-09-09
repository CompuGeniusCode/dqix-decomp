#include <globaldefs.h>

extern "C" void func_0204b04c(void* p, int flag);

struct Elem0205d274 { char b[0x20]; };

struct Cont0205d274 {
    char pad0[0x98];
    Elem0205d274* list98;
    char pad9c[0x16];
    unsigned char countB2;
};

// Cleans the CPU cache over every background screen buffer the object owns: the list of 0x20-byte
// descriptors at +0x98, count at +0xb2. func_0204b04c is the cache half of UploadTilemapToBGScreen
// and sizes the range from data_020e7b98, whose two rows are the DS screen data sizes
// 0x800/0x1000/0x1000/0x2000 for text backgrounds and 0x200/0x800/0x2000/0x8000 for extended
// affine ones. The same container keeps its 0xe0-byte window elements in a second list at +0x9c,
// counted at +0xb3.
extern "C" ARM void FlushBgScreenBufferCaches(Cont0205d274* obj) {
    unsigned char i;
    if (obj->list98 == NULL) return;
    for (i = 0; i < obj->countB2; i++) {
        func_0204b04c(&obj->list98[i], 0);
    }
}
