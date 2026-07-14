#include <globaldefs.h>

extern "C" void func_020c6688(void* obj);
extern "C" void func_020c66bc(void* ptr, int a, int b);
extern "C" void func_020c6728();

struct DmaJob020b2f4c {
    unsigned char pad00[0x2c];
    int field2c;
    unsigned short field30;
    unsigned short field32;
    unsigned char pad34[4];
    int field38;
};

// USA: func_020b2f4c
ARM void ConfigureDmaJob020b2f4c(DmaJob020b2f4c* obj, int flag) {
    if (flag)
        func_020c6688(obj);
    func_020c66bc((char*)obj + obj->field38, (unsigned short)obj->field2c << 3, obj->field30 << 3);
    obj->field32 |= 1;
    if (flag)
        func_020c6728();
}
