#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int length);

struct GlobalSub1840_020a9b2c {
    char pad0[0xb34];
    int f_b34;
    int f_b38;
    int f_b3c;
    char pad1[0xb44 - 0xb40];
    int f_b44;
};

struct S1840Ext_020a9b2c {
    char pad[0xb61];
    unsigned char flag;
};

// USA: func_020a9b2c
ARM int ImportBattleWorkBuffer020a9b2c(void* self) {
    char* s = (char*)self + 0x198 + 0xc00;
    char* g = (char*)func_02012fe4();
    struct GlobalSub1840_020a9b2c* p = (struct GlobalSub1840_020a9b2c*)(g + 0x1840);
    p->f_b38 = *(int*)(s + 0xd98);
    p->f_b34 = *(int*)(s + 0xd9c);
    p->f_b44 = *(int*)(s + 0xda0);
    unsigned short h = *(unsigned short*)(s + 0xd00 + 0xa4);
    p->f_b3c = h & 0xff;
    ((struct S1840Ext_020a9b2c*)(g + 0x1840))->flag = (*(unsigned char*)(s + 0xda6) != 0) ? 1 : 0;
    VectorizedInvertedMemcpy(self, g + 0x840, 0x1b30);
    return 1;
}
