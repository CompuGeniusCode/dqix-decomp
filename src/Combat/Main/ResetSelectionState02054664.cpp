#include <globaldefs.h>

extern "C" void func_02037d10(void *obj);
void SetBitsInField0x6c(unsigned char *obj, unsigned int mask);

struct Obj02054664 {
    unsigned short field0;   // 0x00
    char pad2[0x2ce];        // 0x02..0x2cf
    signed char b2d0;        // 0x2d0
    signed char b2d1;        // 0x2d1
    signed char b2d2;        // 0x2d2
};

// USA: func_02054664
ARM void ResetSelectionState02054664(struct Obj02054664 *obj) {
    func_02037d10(obj);
    obj->field0 |= 0x1000;
    obj->b2d0 = -1;
    obj->b2d1 = -1;
    obj->b2d2 = 0;
    SetBitsInField0x6c((unsigned char *)obj, 0x80);
}
