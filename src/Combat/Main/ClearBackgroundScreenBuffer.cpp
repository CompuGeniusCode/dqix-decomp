#include <globaldefs.h>
#include "std_library_functions.h"

extern unsigned int data_020e7b98[][4];

struct Obj0204b010 {
    char pad0[0x14];
    void* field14;
    unsigned int field18;
    char pad1c[3];
    unsigned char byte1f;
};

// Zeroes a background layer's screen (tilemap) buffer, falling back to the buffer the layer
// already owns at +0x14 when none is passed. The size comes from data_020e7b98 indexed by the
// layer's BG type at +0x1f and its screen-size setting at +0x18; the two rows hold
// 0x800/0x1000/0x1000/0x2000 and 0x200/0x800/0x2000/0x8000, the DS text-mode screen sizes and the
// extended-affine ones, whose 16-bit entries double a plain affine map.
// AllocateBackgroundScreenBuffer sizes its allocation the same way.
extern "C" ARM void ClearBackgroundScreenBuffer(Obj0204b010* obj, void* p) {
    if (p == NULL) p = obj->field14;
    if (p == NULL) return;
    memset(p, 0, data_020e7b98[obj->byte1f][obj->field18]);
}
