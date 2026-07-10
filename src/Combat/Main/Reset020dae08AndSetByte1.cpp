#include <globaldefs.h>

struct Obj020dae98 { char pad0; unsigned char field_1; };

extern "C" void func_020dae08(struct Obj020dae98* obj);

// USA: func_020dae98
ARM void Reset020dae08AndSetByte1(struct Obj020dae98* obj) {
    func_020dae08(obj);
    obj->field_1 = 1;
}
