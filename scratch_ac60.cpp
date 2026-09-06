#include <globaldefs.h>
#include "std_library_functions.h"

ARM int EncodeStreamFields020dc0e0(int a, int b, int c, int d, unsigned char e, unsigned char f);
extern int data_020e7b60[];

// USA: func_0204ac60
ARM int EncodeIndexedStreamField0204ac60(void *unused, int idx, char *buf) {
    int tmp;
    unsigned char e = 1;
    unsigned char f = 0;
    memcpy(&tmp, buf + 8, 4);
    return EncodeStreamFields020dc0e0(data_020e7b60[idx], (int)(buf + 0xc), 0, tmp, e, f);
}
