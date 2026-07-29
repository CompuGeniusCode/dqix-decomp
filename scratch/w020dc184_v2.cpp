#include <globaldefs.h>

extern "C" void *func_01ff8b48(void *a0, int a1, void *a2, unsigned int a3, unsigned int a4, int a5, int a6);
extern int data_0214e5e4;

struct StructDc184 {
    char pad[8];
    unsigned int field8;
    unsigned short fieldC;
    unsigned short pad_e;
    unsigned short field10;
    unsigned short pad_12;
    unsigned int field14;
};

// USA: func_020dc184
ARM int func_020dc184(StructDc184 *p, int param2) {
    if (p == 0) return -1;
    p->field10 = p->field10 | 1;
    unsigned int arg5 = p->fieldC << 3;
    void* arg3 = (char*)p + p->field14;
    unsigned int arg4 = (unsigned short)p->field8 << 3;
    return (int)func_01ff8b48(&data_0214e5e4, 1, arg3, arg4, arg5, param2, 0);
}
