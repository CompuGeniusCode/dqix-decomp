#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);
extern "C" int memcmp(void* lhs, void* rhs, int length);

typedef void (*CharacterDataUploadFn)(void*, int, int);
extern "C" void func_0204a984(int* bgTarget, CharacterDataUploadFn fn, char* ctx);

typedef void (*PaletteUploadFn)(void*, int, int);
struct PaletteChunkMask;
struct PaltBlock;
extern "C" void func_0204abcc(struct PaletteChunkMask* chunkMask, PaletteUploadFn fn, struct PaltBlock* p);

typedef void (*ScreenDataUploadFn)(void*, int, int);
extern "C" void func_0204adb4(unsigned char* destRecord, ScreenDataUploadFn callback, unsigned char* sourceBlock);

struct BgUploadRecord { int unknown0, unknown4, dataLength, unknownC; };
extern "C" void func_0204acb0(struct BgUploadRecord* rec);

extern char strChar;
extern char strPalt;
extern char strScrn;
extern int data_020f01f8[][4];
extern PaletteUploadFn data_020f01b0[];
extern int data_020f0218[][4];

struct BgTarget {
    unsigned char unknown0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

// Takes one resource block whose first four bytes are the tag "CHAR", "PALT" or "SCRN" and hands it
// to the loader for the BG this object owns; the byte at +0x1c packs that BG, low nibble the 2D
// engine and high nibble the layer, the same nibble pair func_0204ffc0 reads off its own target.
// data_020f01f8 is the 2x4 table LoadToMainBG0CharacterData through LoadToSubBG3CharacterData and
// data_020f0218 the matching ScreenData set; the palette table data_020f01b0 has only two entries
// and is indexed by the low nibble alone. The SCRN path's scratch record goes to func_0204acb0
// first, which is not decompiled, then func_0204adb4 copies the block's length word from +0xc into
// its +0x8 and calls the handler with the payload at +0x10 and that length. The twin at 0x0204b2e0
// splits on the same three tags but routes to the cache-flush copies instead.
extern "C" ARM void UploadBgResourceByTag(struct BgTarget* self, char* str) {
    char buf[5];

    if (str == 0) {
        return;
    }

    __clear(buf, 5);
    memcpy(buf, str, 5);

    if (memcmp(buf, &strChar, 4) == 0) {
        CharacterDataUploadFn fn = (CharacterDataUploadFn)data_020f01f8[self->lo][self->hi];
        func_0204a984((int*)self, fn, str);
        return;
    }

    if (memcmp(buf, &strPalt, 4) == 0) {
        PaletteUploadFn fn = data_020f01b0[self->lo];
        func_0204abcc((struct PaletteChunkMask*)((char*)self + 0xc), fn, (struct PaltBlock*)str);
        return;
    }

    if (memcmp(buf, &strScrn, 4) == 0) {
        struct BgUploadRecord rec;
        func_0204acb0(&rec);
        ScreenDataUploadFn fn = (ScreenDataUploadFn)data_020f0218[self->lo][self->hi];
        func_0204adb4((unsigned char*)&rec, fn, (unsigned char*)str);
    }
}
