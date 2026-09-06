#include <globaldefs.h>

struct SignedValue020c5128 {
    unsigned short flags;
    unsigned short unk2;
    unsigned short value;
};
extern "C" ARM void ColorEffect_ChangeBrightness(struct SignedValue020c5128* dst, int value);

struct Struct02290d10_02238588 { unsigned char pad[0x1a]; signed char field1a; };
extern Struct02290d10_02238588* data_ov031_02290d10;

struct Obj_0223e2b8_02238588 { unsigned char pad[8]; int field8; };
extern "C" void func_ov031_0223e2b8(struct Obj_0223e2b8_02238588* obj, int v);

extern "C" void func_ov031_022385e4(void);

// USA: func_ov031_02238588  (semantic: IncrementAndCheckFlag_02238588)
extern "C" ARM void func_ov031_02238588(void* param0) {
    data_ov031_02290d10->field1a++;
    ColorEffect_ChangeBrightness((SignedValue020c5128*)0x4000050, data_ov031_02290d10->field1a);
    if (data_ov031_02290d10->field1a < 0) {
        return;
    }
    func_ov031_0223e2b8((struct Obj_0223e2b8_02238588*)param0, (int)func_ov031_022385e4);
}
