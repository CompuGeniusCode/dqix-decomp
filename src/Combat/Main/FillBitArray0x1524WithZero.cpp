#include <globaldefs.h>
#include "std_library_functions.h"

struct BitArrayObj0205e870 {
    unsigned char pad[0x124];
    struct {
        unsigned char pad[0x1400];
        unsigned char bits[0x20];
    } sub;
};

// USA: func_0205e870
ARM void* FillBitArray0x1524WithZero(struct BitArrayObj0205e870* obj) {
    return memset(obj->sub.bits, 0, 0x20);
}
