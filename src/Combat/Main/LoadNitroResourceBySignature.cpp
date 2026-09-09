#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* dst, int size);
extern "C" int memcmp(const void* a, const void* b, unsigned int length);
extern "C" int func_0205a658(void* obj, void* data, int arg2, int arg3);
extern "C" int func_0205a984(void* obj, void* data, int arg2, int arg3);
extern "C" int func_0205aaf8(void* obj, void* data, int arg2);
extern "C" int func_0205ab78(void* obj, void* data, int arg2);

extern char strRecn[];
extern char strRnan[];
extern char strRgcn[];
extern char strRlcn[];

// Routes an already in-memory file image to the right unpacker by its four-byte signature: RECN,
// RNAN, RGCN and RLCN, which are NCER cell banks, NANR cell animations, NCGR character data and
// NCLR palettes with the magic stored little-endian. It does no I/O of its own; the loading is
// into the object the handlers fill. The RLCN branch, func_0205ab78, goes for the PLTT and PCMP
// chunks, which is what an NCLR holds. Returns 1 once a handler accepts the data and 0 when the
// signature is none of the four.
extern "C" ARM int LoadNitroResourceBySignature(void* obj, void* data, int arg2, int arg3) {
    char magic[5];

    __clear(magic, 5);
    memcpy(magic, data, 4);

    if (memcmp(magic, strRecn, 4) == 0 && func_0205a658(obj, data, arg2, arg3)) {
        return 1;
    } else if (memcmp(magic, strRnan, 4) == 0) {
        if (func_0205a984(obj, data, arg2, arg3)) {
            return 1;
        }
    } else if (memcmp(magic, strRgcn, 4) == 0) {
        if (func_0205aaf8(obj, data, arg2)) {
            return 1;
        }
    } else if (memcmp(magic, strRlcn, 4) == 0) {
        if (func_0205ab78(obj, data, arg2)) {
            return 1;
        }
    }
    return 0;
}
