#include <globaldefs.h>

extern int data_0210782c[];

struct KeyEnt020425e4 { unsigned short key; signed char val; unsigned char pad; };

// USA: func_020425e4
ARM int LookupKeyValue020425e4(int a, int b, int tableIdx) {
    char* t = (char*)data_0210782c[tableIdx];
    unsigned short key = (a & 0xff) | ((b & 0xff) << 8);
    unsigned int count = *(unsigned int*)(t + 0x8);
    struct KeyEnt020425e4* p = *(struct KeyEnt020425e4**)(t + 0xc);
    unsigned int i;
    for (i = 0; i < count; i++) {
        if (p->key == key) return p->val;
        p++;
    }
    return 0;
}
