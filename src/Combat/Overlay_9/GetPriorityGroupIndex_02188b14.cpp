#include <globaldefs.h>

extern signed char data_ov009_0218a9bc[10];

// USA: func_ov009_02188b14  (semantic: GetPriorityGroupIndex_02188b14)
extern "C" ARM int func_ov009_02188b14(void* objRaw, int type, int idx) {
    char* obj = (char*)objRaw;
    signed char table[10];
    int n;
    unsigned char* d;
    unsigned char* s = (unsigned char*)data_ov009_0218a9bc;
    d = (unsigned char*)table;
    n = 10;
    do {
        unsigned char v = *s;
        s++;
        *d = v;
        d++;
    } while (--n);

    if (type == 5) {
        if (*(unsigned char*)(obj + 0xda3) != 0) {
            table[0] = 1;
            table[1] = 0;
        } else {
            table[0] = 4;
            table[1] = 0;
            table[2] = 1;
            table[3] = 2;
            table[4] = 3;
        }
        return table[idx];
    }
    if (type == 3) {
        if (*(unsigned char*)(obj + 0xda3) != 0) {
            table[0] = 6;
            table[1] = 0;
            table[2] = 1;
            table[3] = 2;
            table[4] = 3;
            table[5] = 4;
            table[6] = 5;
        }
        return table[idx];
    }
    return idx;
}
