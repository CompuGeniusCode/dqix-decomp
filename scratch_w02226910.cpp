#include <globaldefs.h>

struct SubObj02226910 { unsigned int field0; unsigned short field4; };
struct EntityStruct02226910 {
    unsigned char pad0[0x10];
    SubObj02226910* arr10[10];
    SubObj02226910* arr38[2];
    void* arr40[1];
};

extern EntityStruct02226910* data_ov031_02250c00;
extern unsigned char data_ov031_02248c7c[];
extern unsigned char data_ov031_02248c70[];
extern "C" void func_ov031_0223bb58(void* obj, int a, int b);

// USA: func_ov031_02226910
extern "C" ARM void func_ov031_02226910(int idx, int val) {
    if (idx < 0) return;
    if (idx < 0xa) {
        SubObj02226910* p = data_ov031_02250c00->arr10[idx];
        unsigned char b = data_ov031_02248c7c[val];
        p->field0 &= ~0xc00;
        p->field4 = (unsigned short)((p->field4 & ~0xf000) | (b << 12));
        return;
    }
    int off1 = idx - 0xa;
    if (off1 < 2) {
        unsigned char b = data_ov031_02248c7c[val];
        SubObj02226910* p = data_ov031_02250c00->arr38[off1];
        p->field0 &= ~0xc00;
        p->field4 = (unsigned short)((p->field4 & ~0xf000) | (b << 12));
        return;
    }
    void* p = data_ov031_02250c00->arr40[idx - 0xc];
    (void)*(volatile unsigned char*)&data_ov031_02248c70[val];
    func_ov031_0223bb58(p, -1, 0);
}
