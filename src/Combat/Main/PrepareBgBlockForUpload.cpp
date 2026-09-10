#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);
extern "C" int memcmp(void* a, void* b, int n);

extern "C" void func_0204a8f4(char* dst, char* src);

struct HeaderAt0204ab4c;
struct BufferAt0204ab4c;
extern "C" void func_0204ab4c(struct HeaderAt0204ab4c* header, struct BufferAt0204ab4c* buffer);

struct Record0204acb0 {
    int w0;
    int w4;
    int w8;
    int wc;
};
extern "C" void func_0204acb0(struct Record0204acb0* rec);
extern "C" void func_0204ad88(void* a, void* b);

extern char strChar;
extern char strPalt;
extern char strScrn;

// Folds one tagged block of a .pac into a background layer, dispatching on its four-character tag:
// "CHAR" copies the tile-data header into the layer, "PALT" cleans only the palette sub-blocks the
// halfword at the header's +0x2 names (0xffff cleans the whole buffer in one call instead of per
// 0x20-byte sub-block), and "SCRN" just cleans its payload. The tags are the literals at 0x020f0238
// and data/menu/bg_lv5.pac holds one of each. UploadBgResourceByTag has an identical caller set and always
// follows on the same block; it presumably uploads, but its callback tables are not decompiled.
extern "C" ARM void PrepareBgBlockForUpload(void* obj, char* str) {
    char buf[5];

    if (str == 0) {
        return;
    }

    __clear(buf, 5);
    memcpy(buf, str, 5);

    if (memcmp(buf, &strChar, 4) == 0) {
        func_0204a8f4((char*)obj, str);
        return;
    }

    if (memcmp(buf, &strPalt, 4) == 0) {
        func_0204ab4c((struct HeaderAt0204ab4c*)((char*)obj + 0xc), (struct BufferAt0204ab4c*)str);
        return;
    }

    if (memcmp(buf, &strScrn, 4) == 0) {
        struct Record0204acb0 rec;
        func_0204acb0(&rec);
        func_0204ad88(&rec, str);
    }
}
