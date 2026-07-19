#include <globaldefs.h>

struct Struct0223bbd8_02235744 {
    void* field0;
    char pad0[0xc];
    unsigned short field10;
    unsigned short field12;
    char pad14[6];
    unsigned char field1a;
};
extern Struct0223bbd8_02235744* data_ov031_02290cf4;
extern "C" void func_ov031_0223bbd8(void*, int, int, int);

// USA: func_ov031_02235744
ARM void ForwardWithOffsetThenTag_02235744(int a) {
    Struct0223bbd8_02235744* p = data_ov031_02290cf4;
    func_ov031_0223bbd8(p->field0, -1, p->field10, a + p->field12);
    data_ov031_02290cf4->field1a = (unsigned char)a;
}
