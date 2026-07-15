#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);

struct Param021e8550 { char pad[8]; short value; };

// USA: func_ov025_021e8550
ARM int SetGlobalField_021e8550(struct Param021e8550* p) {
    short v = p->value;
    int base = GetGlobalField0x1c020421a0();
    *(short*)((char*)base + 0x1900 + 0xda) = v;
    return 1;
}
