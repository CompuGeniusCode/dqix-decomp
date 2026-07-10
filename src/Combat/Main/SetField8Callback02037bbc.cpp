#include <globaldefs.h>

struct S_37760;
struct Fields020b2e28;
struct S_37760* GetSelfIfField0xa8Bit0Set(struct S_37760* obj);
void SetWordAndTwoBytesAt0x20(struct Fields020b2e28* s, int a, int b, unsigned char c, int d);
extern "C" void func_02037bf8(void);

struct Obj02037bbc {
    unsigned char pad[8];
    struct S_37760* field8;   // 0x8
};

// USA: func_02037bbc
ARM void SetField8Callback02037bbc(struct Obj02037bbc* obj) {
    struct S_37760* self;
    if (obj->field8 == NULL) return;
    self = GetSelfIfField0xa8Bit0Set(obj->field8);
    if (self == NULL) return;
    SetWordAndTwoBytesAt0x20((struct Fields020b2e28*)self, (int)func_02037bf8, 0, 6, 3);
}
