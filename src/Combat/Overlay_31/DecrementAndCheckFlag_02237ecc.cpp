#include <globaldefs.h>

struct SignedValue020c5128 {
    unsigned short flags;
    unsigned short unk2;
    unsigned short value;
};
ARM void StoreMagnitudeAndSignFlag020c5128(struct SignedValue020c5128* dst, int value);

struct Struct02290d10_02237ecc { unsigned char pad[0x1a]; signed char field1a; };
extern Struct02290d10_02237ecc* data_ov031_02290d10;

struct Obj_0223e2b8_02237ecc { unsigned char pad[8]; int field8; };
extern "C" void func_ov031_0223e2b8(struct Obj_0223e2b8_02237ecc* obj, int v);

extern "C" void func_ov031_02237f2c(void);

// USA: func_ov031_02237ecc  (semantic: DecrementAndCheckFlag_02237ecc)
extern "C" ARM void func_ov031_02237ecc(void* param0) {
    data_ov031_02290d10->field1a--;
    StoreMagnitudeAndSignFlag020c5128((SignedValue020c5128*)0x4000050, data_ov031_02290d10->field1a);
    if (data_ov031_02290d10->field1a > -12) {
        return;
    }
    func_ov031_0223e2b8((struct Obj_0223e2b8_02237ecc*)param0, (int)func_ov031_02237f2c);
}
