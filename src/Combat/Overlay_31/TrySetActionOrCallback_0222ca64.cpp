#include <globaldefs.h>

extern "C" int func_ov031_02236878(int index);
extern void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_0222c71c(void);

struct Inner0222ca64 {
    unsigned char pad[0x38];
    void* field0x38;
    unsigned char pad2[0x1d];
    unsigned char field0x59;
};
struct Struct0222ca64 {
    unsigned char pad[2];
    unsigned short field2;
    Inner0222ca64* field4;
};
extern Struct0222ca64 data_ov031_02290c8c;

// USA: func_ov031_0222ca64  (semantic: TrySetActionOrCallback_0222ca64)
extern "C" ARM void func_ov031_0222ca64(void) {
    if (data_ov031_02290c8c.field2 == 0) {
        if (data_ov031_02290c8c.field4->field0x59 != 0) return;
        func_ov031_02236878(9);
        data_ov031_02290c8c.field4->field0x59 = 1;
    } else {
        func_ov031_02236878(0x13);
        void* r = CallWithZeroExtra_0223e218(NULL, (void*)func_ov031_0222c71c, NULL, 0x78);
        data_ov031_02290c8c.field4->field0x38 = r;
    }
}
