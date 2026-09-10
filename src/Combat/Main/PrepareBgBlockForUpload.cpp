#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);
extern "C" int memcmp(void* lhs, void* rhs, int length);

extern "C" void func_0204a8f4(char* layer, char* block);

struct PaletteDirtyHeader;
struct PaletteBlock;
extern "C" void func_0204ab4c(struct PaletteDirtyHeader* header, struct PaletteBlock* buffer);

struct ScreenUploadRecord {
    int unknown0;
    int unknown4;
    int payloadSize;
    int unknownc;
};
extern "C" void func_0204acb0(struct ScreenUploadRecord* rec);
extern "C" void func_0204ad88(void* record, void* block);

extern char strChar;
extern char strPalt;
extern char strScrn;

// Folds one tagged block of the .pac into the background layer it is handed, dispatching on the
// four-character tag at the front of the block: "CHAR" copies the tile-data header into the layer,
// "PALT" cleans only the palette sub-blocks named by the halfword at the layer's +0xe - func_0204ab4c
// reaches it through the sub-object at +0xc, and 0xffff there cleans the whole buffer in one call
// instead of per 0x20-byte sub-block - and "SCRN" just cleans its payload, func_0204acb0 zeroing the
// record first and func_0204ad88 then copying the payload size out of the block into +0x8 of it.
// The tags are the literals at 0x020f0238 and data/menu/bg_lv5.pac holds one of each.
// UploadBgResourceByTag has an identical caller set and always follows on the same block; it
// presumably uploads, but its callback tables are not decompiled.
extern "C" ARM void PrepareBgBlockForUpload(void* layer, char* str) {
    char buf[5];

    if (str == 0) {
        return;
    }

    __clear(buf, 5);
    memcpy(buf, str, 5);

    if (memcmp(buf, &strChar, 4) == 0) {
        func_0204a8f4((char*)layer, str);
        return;
    }

    if (memcmp(buf, &strPalt, 4) == 0) {
        func_0204ab4c((struct PaletteDirtyHeader*)((char*)layer + 0xc), (struct PaletteBlock*)str);
        return;
    }

    if (memcmp(buf, &strScrn, 4) == 0) {
        struct ScreenUploadRecord rec;
        func_0204acb0(&rec);
        func_0204ad88(&rec, str);
    }
}
