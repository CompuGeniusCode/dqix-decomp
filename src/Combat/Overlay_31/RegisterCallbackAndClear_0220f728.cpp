#include <globaldefs.h>

struct Queue0220f728 {
    unsigned char pad[0xc];
    int* field0xc;
    unsigned char pad2[0x20 - 0x10];
    int field20;
    int field24;
};

struct Obj0220f728 {
    unsigned char pad[0x24];
    struct Queue0220f728* field24;
};

extern struct Obj0220f728* data_ov031_0224e580;

extern "C" int func_ov031_0220fe44(int arg);
void ClearField28SetField2C_0220fed8(void);

// USA: func_ov031_0220f728  (semantic: RegisterCallbackAndClear_0220f728)
extern "C" ARM void func_ov031_0220f728(void) {
    if (func_ov031_0220fe44(0)) {
        struct Queue0220f728* q = data_ov031_0224e580->field24;
        q->field24 = *q->field0xc;
        q = data_ov031_0224e580->field24;
        q->field20 = 1;
    }
    ClearField28SetField2C_0220fed8();
}
