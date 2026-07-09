#include <globaldefs.h>

// USA: func_02053604
ARM int GetIndexedEntryField0x178(signed char* obj) {
    signed char a = obj[0x17c];
    if (a == 0) return -1;
    signed char b = obj[0x17d];
    if (b >= 4) return -1;
    signed char* q = obj + b;
    return q[0x178];
}
