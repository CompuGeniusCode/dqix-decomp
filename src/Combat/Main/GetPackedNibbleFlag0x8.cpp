#include <globaldefs.h>

struct PackedNibbleArray0206e2dc {
    unsigned char pad[0x2CC];
    unsigned char bits[1];
};

// USA: func_0206e2dc
ARM int GetPackedNibbleFlag0x8(struct PackedNibbleArray0206e2dc* obj, int index) {
    int mask;
    if (index >= 0xCC || index < 0) {
        return 0;
    }
    mask = (index % 2) ? 0x80 : 0x8;
    return mask & obj->bits[index / 2];
}
