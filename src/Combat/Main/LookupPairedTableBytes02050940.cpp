#include <globaldefs.h>

extern unsigned char data_020f0320[][32];
extern unsigned char data_020f0321[][32];

// USA: func_02050940
ARM int LookupPairedTableBytes02050940(int unused, int i, int *out) {
    int hi = i >> 4;
    int lo = i ^ (hi << 4);
    *out = data_020f0320[hi][lo * 2];
    return data_020f0321[hi][lo * 2];
}
