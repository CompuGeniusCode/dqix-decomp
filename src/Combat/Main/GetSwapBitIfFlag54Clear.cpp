#include <globaldefs.h>

struct Struct020db9a8 {
    unsigned char pad[0x54];
    unsigned char flag54;
};

// USA: func_020db9a8
ARM int GetSwapBitIfFlag54Clear(struct Struct020db9a8* obj) {
    if (obj->flag54 == 0) {
        return (*(unsigned short*)0x4000304 & 0x8000) >> 15;
    }
    return 0;
}
