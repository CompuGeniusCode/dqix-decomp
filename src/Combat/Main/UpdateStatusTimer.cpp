#include <globaldefs.h>

// USA: func_020658ac
ARM void UpdateStatusTimer(unsigned char* base, unsigned int amount) {
    unsigned char c;
    if (base[0x19c1] != 0) {
        if (base[0x19c0] == 0) {
            base[0x19c0] = 1;
            base[0x195d] = 0x1e;
        }
    }
    if (base[0x19c0] == 0) return;
    c = base[0x195d];
    if (c <= amount) {
        if (base[0x19c1] != 0) {
            base[0x195d] = c + (0x1e - amount);
        } else {
            base[0x195d] = 0;
            base[0x19c0] = 0;
        }
    } else {
        base[0x195d] = c - amount;
    }
}
