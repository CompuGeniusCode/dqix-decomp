#include <globaldefs.h>

void InitObjectFields0203a914(void* obj);
void ClearField0x0_020bc078(int* field);
extern "C" void func_0209c2e0(void* obj, int a, int b);
void SetModeClamped0209ca70(void* obj, int val);

struct Actor0209c174 {
    char pad0[0xb0];
    int state;               // 0xb0
    int field_b4;             // 0xb4
    short field_b8;             // 0xb8
    short field_ba;               // 0xba
    void* fieldBC;                 // 0xbc
    void* fieldC0;                   // 0xc0
    void* fieldC4;                     // 0xc4
    unsigned char field_c8;              // 0xc8
    unsigned char field_c9;                // 0xc9
    short field_ca;                          // 0xca
    unsigned char field_cc;                    // 0xcc
    unsigned char field_cd;                      // 0xcd
    short field_ce;                                // 0xce
};

// USA: func_0209c174
ARM void ResetActor0209c174(struct Actor0209c174* self) {
    InitObjectFields0203a914(self);
    self->state = 0;
    self->field_b4 = 0;
    self->field_b8 = -1;
    ClearField0x0_020bc078((int*)&self->fieldBC);
    self->field_ba = -1;
    ClearField0x0_020bc078((int*)&self->fieldC0);
    ClearField0x0_020bc078((int*)&self->fieldC4);
    self->field_c8 &= ~1;
    func_0209c2e0(self, 0x7f, 0);
    SetModeClamped0209ca70(self, 3);
    self->field_ce = -1;
    self->field_c9 = 0;
    self->field_ca = 0;
    self->field_c8 &= ~4;
    self->field_c8 &= ~8;
}
