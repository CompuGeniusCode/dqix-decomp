#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj020dfe88;
extern "C" int func_020dfe88(struct Obj020dfe88*);

struct Struct020dfc40 {
    unsigned char pad[0xc];
    short field_c;
    int field_10;
};

// Clears a background file-load request. The word at +0x10 is a BackgroundLoader task handle:
// func_020dfe88, which this calls, cancels it through BackgroundLoader::RemoveTask.
// The order matters -- the handle is overwritten with -1 before func_020dfe88 gets to
// test it, so an in-flight task is abandoned rather than removed; func_020dfc6c runs the two the
// other way round and does cancel. func_020dfc84 is the matching setup, filling the same object
// from two filenames, put through func_020e05f8 when a flag argument is set.
extern "C" ARM void ResetBackgroundLoadRequest(Struct020dfc40* p) {
    memset(p, 0, 0xc);
    p->field_c = -1;
    p->field_10 = -1;
    func_020dfe88((struct Obj020dfe88*)p);
}
