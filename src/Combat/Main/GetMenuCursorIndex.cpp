#include <globaldefs.h>

struct Struct_0205c570;
extern "C" int func_0205c570(struct Struct_0205c570*);

// The menu widget's selection index, as its callers use it: ov003 keeps it as a signed char and
// indexes the per-choice table at obj+0x58a, ov013 stores it as the 0/1 answer its 0xc0 key toggle
// flips, and six ov012 functions drop it into the object's selection field. -1 comes back when the
// widget is inactive, but only on the field95 == 0 path -- with field95 set the +0x54 sum always
// wins and the sentinel is discarded. The work is func_0205c570's; this only forwards, yet 83
// relocs point here instead.
extern "C" ARM int GetMenuCursorIndex(struct Struct_0205c570* s) {
    return func_0205c570(s);
}
