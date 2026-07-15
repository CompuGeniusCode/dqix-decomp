#include <globaldefs.h>

struct S02171698 { char pad[0x9c]; int field[0x42]; };
signed char CountNonZero02171698(struct S02171698* s);

// USA: func_ov000_02171640
ARM void SetFieldAndUpdateCount02171640(struct S02171698* obj, int idx, int val) {
    if (idx < 0) return;
    if (idx >= 0x42) return;
    if (val == 0) return;
    obj->field[idx] = val;
    *(short*)((char*)obj + 0x82) = CountNonZero02171698(obj);
}
