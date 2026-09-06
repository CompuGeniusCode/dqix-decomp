#include <globaldefs.h>

extern short data_020e8a24[8];

struct PoolTables0207c258 {
    char pad0[0xbd0];
    short* group1[8];
    unsigned char* group2[8];
    short counts[8];
    unsigned char index[8];
    unsigned char used[8];
};

// USA: func_0207c258  (semantic: InitPoolTables0207c258)
extern "C" ARM void func_0207c258(struct PoolTables0207c258* obj) {
    int i, j;
    char* base = (char*)obj;

    obj->group1[0] = (short*)obj;
    obj->group1[1] = (short*)(base + 0x330);
    obj->group1[2] = (short*)(base + 0x3c0);
    obj->group1[3] = (short*)(base + 0x600);
    obj->group1[4] = (short*)(base + 0x720);
    obj->group1[5] = (short*)(base + 0x8d0);
    obj->group1[6] = (short*)(base + 0x9c0);
    obj->group1[7] = (short*)(base + 0xb10);
    obj->group2[0] = (unsigned char*)(base + 0x220);
    obj->group2[1] = (unsigned char*)(base + 0x390);
    obj->group2[2] = (unsigned char*)(base + 0x540);
    obj->group2[3] = (unsigned char*)(base + 0x6c0);
    obj->group2[4] = (unsigned char*)(base + 0x840);
    obj->group2[5] = (unsigned char*)(base + 0x970);
    obj->group2[6] = (unsigned char*)(base + 0xaa0);
    obj->group2[7] = (unsigned char*)(base + 0xb90);

    for (i = 0; i < 8; i++) {
        obj->counts[i] = data_020e8a24[i];
        obj->index[i] = (unsigned char)i;
    }

    for (j = 0; j < 8; j++) {
        short* g1 = obj->group1[j];
        unsigned char* g2 = obj->group2[j];
        short count = obj->counts[j];
        int k;
        for (k = 0; k < count; k++) {
            g1[k] = -1;
            g2[k] = 0;
        }
        obj->used[j] = 0;
    }
}
