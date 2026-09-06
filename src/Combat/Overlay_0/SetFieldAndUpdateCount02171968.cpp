#include <globaldefs.h>

struct S021719c0 { char pad[0x1a4]; int field[0x93]; };
short CountNonZero021719c0(struct S021719c0* s);

// USA: func_ov000_02171968
ARM void SetFieldAndUpdateCount02171968(struct S021719c0* obj, int idx, int val) {
    if (idx < 0) return;
    if (idx >= 0x93) return;
    if (val == 0) return;
    obj->field[idx] = val;
    *(short*)((char*)obj + 0x84) = CountNonZero021719c0(obj);
}
