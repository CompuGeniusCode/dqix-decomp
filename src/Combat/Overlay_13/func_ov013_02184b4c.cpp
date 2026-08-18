#include <globaldefs.h>

#pragma opt_arithtransformation off

int GetFieldAt0x150(unsigned char* obj);
int GetTableByte020dd11c(unsigned int a, unsigned int b);

// USA: func_ov013_02184b4c
extern "C" ARM void func_ov013_02184b4c(void* obj, void* arg) {
    unsigned char* o = (unsigned char*)obj;
    unsigned char* p = (unsigned char*)arg;
    unsigned char* ctx;
    unsigned short baseVal;
    int field950;
    int i;

    if (arg == 0) return;

    ctx = (unsigned char*)GetFieldAt0x150(p);
    *(void**)(o + 0x6a4) = *(void**)(p + 0x134);

    baseVal = *(unsigned short*)(ctx + 0x564);
    *(int*)(o + 0x66c) = baseVal;
    *(int*)(o + 0x668) = baseVal;

    field950 = *(int*)(ctx + 0x950);
    {
        unsigned int idx = field950 & 0xff;
        o[0x6a8] = (unsigned char)field950;
        *(int*)(o + 0x6b0) = *(unsigned short*)(ctx + 0x16c + idx * 2);
    }
    {
        unsigned char* q = ctx + o[0x6a8];
        *(int*)(o + 0x6b8) = q[0x186];
    }

    *(unsigned short*)(o + 0x6c0) = *(unsigned short*)(*(unsigned char**)(p + 0x134) + 0x30);
    *(unsigned short*)(o + 0x6c4) = *(unsigned short*)(*(unsigned char**)(p + 0x134) + 0x32);
    *(unsigned short*)(o + 0x6c6) = *(unsigned short*)(*(unsigned char**)(p + 0x134) + 0x34);
    *(unsigned short*)(o + 0x6c8) = *(unsigned short*)(*(unsigned char**)(p + 0x134) + 0x36);
    *(unsigned short*)(o + 0x6ca) = *(unsigned short*)(*(unsigned char**)(p + 0x134) + 0x38);

    if (o[0x640] != 0) {
        *(unsigned short*)(o + 0x6be) = *(unsigned short*)(*(unsigned char**)(p + 0x138));
        *(unsigned short*)(o + 0x6c2) = *(unsigned short*)(*(unsigned char**)(p + 0x138) + 2);
    } else {
        *(unsigned short*)(o + 0x6be) = *(unsigned short*)(*(unsigned char**)(p + 0x130) + 4);
        *(unsigned short*)(o + 0x6c2) = *(unsigned short*)(*(unsigned char**)(p + 0x130) + 6);
    }

    if (*(int*)(o + 0x6b8) != 0) o[0x6b4] = 1;
    *(int*)(o + 0x670) = 0x64;

    for (i = 0; i < 5; i++) {
        (o + i)[0x6a9] = (unsigned char)GetTableByte020dd11c(o[0x6a8], (unsigned char)i);
        (o + i)[0x69c] = 0;
        {
            unsigned char idx = (o + i)[0x6a9];
            unsigned char* q2 = ctx + idx;
            *(int*)(o + 0x674 + i * 4) = q2[0x464];
        }
    }
}
