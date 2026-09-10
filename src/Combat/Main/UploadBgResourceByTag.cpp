#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);
extern "C" int memcmp(void* a, void* b, int n);

typedef void (*Fn0204a984)(void*, int, int);
extern "C" void func_0204a984(int* a0, Fn0204a984 fn, char* ctx);

typedef void (*Callback0204abcc)(void*, int, int);
struct Obj0204abcc;
struct P0204abcc;
extern "C" void func_0204abcc(struct Obj0204abcc* obj, Callback0204abcc fn, struct P0204abcc* p);

typedef void (*Callback0204adb4)(void*, int, int);
extern "C" void func_0204adb4(unsigned char* dst, Callback0204adb4 callback, unsigned char* src);

struct Record0204acb0 { int w0, w4, w8, wc; };
extern "C" void func_0204acb0(struct Record0204acb0* rec);

extern char strChar;
extern char strPalt;
extern char strScrn;
extern int data_020f01f8[][4];
extern Callback0204abcc data_020f01b0[];
extern int data_020f0218[][4];

struct SelfTag0204b3a0 {
    unsigned char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

// Takes a resource block whose first four bytes are the tag "CHAR", "PALT" or "SCRN" and hands it to
// the loader for the BG this object owns; the byte at +0x1c packs that BG, low nibble the 2D engine
// and high nibble the layer. data_020f01f8 is the 2x4 table LoadToMainBG0CharacterData through
// LoadToSubBG3CharacterData and data_020f0218 the matching ScreenData set; the palette table
// data_020f01b0 has only two entries and is indexed by the low nibble alone. The twin at 0x0204b2e0
// splits on the same three tags but routes to the cache-flush copies instead.
extern "C" ARM void UploadBgResourceByTag(struct SelfTag0204b3a0* self, char* str) {
    char buf[5];

    if (str == 0) {
        return;
    }

    __clear(buf, 5);
    memcpy(buf, str, 5);

    if (memcmp(buf, &strChar, 4) == 0) {
        Fn0204a984 fn = (Fn0204a984)data_020f01f8[self->lo][self->hi];
        func_0204a984((int*)self, fn, str);
        return;
    }

    if (memcmp(buf, &strPalt, 4) == 0) {
        Callback0204abcc fn = data_020f01b0[self->lo];
        func_0204abcc((struct Obj0204abcc*)((char*)self + 0xc), fn, (struct P0204abcc*)str);
        return;
    }

    if (memcmp(buf, &strScrn, 4) == 0) {
        struct Record0204acb0 rec;
        func_0204acb0(&rec);
        Callback0204adb4 fn = (Callback0204adb4)data_020f0218[self->lo][self->hi];
        func_0204adb4((unsigned char*)&rec, fn, (unsigned char*)str);
    }
}
