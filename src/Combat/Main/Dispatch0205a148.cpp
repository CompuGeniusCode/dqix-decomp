#include <globaldefs.h>

extern "C" void func_02035a2c(void* obj, int flag);
int ForwardField4To0205765c(int* obj);

struct Obj0205a148 {
    unsigned char pad_ac[0xac];
    int field_ac;                 // 0xac
    short field_b0;               // 0xb0
    unsigned char pad_b2[0x1a];   // 0xb2..0xcb
    unsigned char field_cc;       // 0xcc
};

// USA: func_0205a148
ARM void Dispatch0205a148(struct Obj0205a148* obj) {
    if (obj->field_b0 > 0) return;
    if (obj->field_ac == 0) {
        func_02035a2c(obj, ((unsigned int)obj->field_cc << 29) >> 31);
        return;
    }
    ForwardField4To0205765c((int*)obj);
}
