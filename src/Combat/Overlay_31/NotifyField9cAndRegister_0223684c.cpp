#include <globaldefs.h>

struct Struct0223684c { unsigned char pad[0x9c]; int field9c; };
extern Struct0223684c* data_ov031_02290d00;
void TailCallField4_0223e2c0(int, int);
void FreeAndClearPtr_0223cf70(void*);

// USA: func_ov031_0223684c
ARM void NotifyField9cAndRegister_0223684c(void) {
    TailCallField4_0223e2c0(0, data_ov031_02290d00->field9c);
    FreeAndClearPtr_0223cf70(&data_ov031_02290d00);
}
