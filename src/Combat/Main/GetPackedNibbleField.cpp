#include <globaldefs.h>

struct PackedNibbleArray0206e120 {
    unsigned char pad[0x2CC];
    unsigned char bits[1];
};

// USA: func_0206e120
ARM int GetPackedNibbleField(struct PackedNibbleArray0206e120* obj, int index) {
    int byteIndex;
    if (index >= 0xCC || index < 0) {
        return 0;
    }
    byteIndex = index / 2;
    if (index % 2) {
        return (obj->bits[byteIndex] >> 4) & 3;
    }
    return obj->bits[byteIndex] & 3;
}
