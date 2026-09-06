#include <globaldefs.h>

extern "C" void* _Z21GetData02104304Field4v(void);
extern "C" int _Z13GetField0x124Pv(void* p);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_0219b624(void);

struct Ctx021b2b68 { char pad[8]; int field8; char pad2[0x38 - 0xc]; int field38; };

// USA: func_ov017_021b2b68
ARM int GetField8OrClearBit4_021b2b68(struct Ctx021b2b68* self) {
    void* d = _Z21GetData02104304Field4v();
    if (_Z13GetField0x124Pv(d) > 0) {
        return self->field8;
    }
    func_ov017_0218b5b0();
    func_ov017_0219b624();
    self->field38 &= ~4;
    return 3;
}
