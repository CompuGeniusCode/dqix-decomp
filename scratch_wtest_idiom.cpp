#include <globaldefs.h>

struct SubObjX { unsigned int field0; unsigned short field4; };
struct EntityX { unsigned char pad[0x10]; SubObjX* arr10[10]; };
extern EntityX* data_ov031_02250c00;
extern unsigned char data_ov031_02248c7c[];

extern "C" ARM void testfn(int idx, int val) {
    unsigned char b = data_ov031_02248c7c[val];
    SubObjX* p = data_ov031_02250c00->arr10[idx];
    p->field0 &= ~0xc00;
    p->field4 = (unsigned short)((p->field4 & ~0xf000) | (b << 12));
}
