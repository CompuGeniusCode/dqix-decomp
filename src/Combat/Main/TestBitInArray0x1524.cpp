#include <globaldefs.h>

struct BitArrayObj0205e830 {
    unsigned char pad[0x124];
    struct {
        unsigned char pad[0x1400];
        unsigned char bits[0x20];
    } sub;
};

// USA: func_0205e830
ARM int TestBitInArray0x1524(struct BitArrayObj0205e830* obj, int index) {
    return (1 << (index % 8)) & obj->sub.bits[(unsigned int)index >> 3];
}
