#include <globaldefs.h>

struct Actor02024d48 {
    unsigned char pad[0x11];
    unsigned char flag0x11;
    unsigned char flag0x12;
};

// USA: func_02024d48
ARM int CheckActionAllowed(struct Actor02024d48* actor, int flag) {
    int result = 1;
    int keep = 1;
    unsigned char v12 = actor->flag0x12;
    if (v12 != 0) {
        if (v12 == 0 || actor->flag0x11 != 0) {
            keep = 0;
        }
    }
    if (keep == 0) {
        if (v12 == 0 || flag != 0) {
            result = 0;
        }
    }
    return result;
}
