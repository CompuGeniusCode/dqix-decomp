#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct FieldPairStruct_0218db90 {
    int a;
    int b;
};

extern FieldPairStruct_0218db90 data_ov020_0218dbc0;

// USA: func_ov020_0218db90  (semantic: SetFieldFromFieldPlus11_0218db90)
extern "C" __declspec(initcode) ARM void __sinit_ov020_0218db90(void) {
    data_ov020_0218dbc0.a = data_ov020_0218dbc0.b + 0xb;
}
