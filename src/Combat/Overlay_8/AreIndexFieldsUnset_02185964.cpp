#include <globaldefs.h>

struct Obj02185964 { char pad[0x60]; int f60; int f64; };

// USA: func_ov008_02185964  (semantic: AreIndexFieldsUnset_02185964)
extern "C" ARM int func_ov008_02185964(struct Obj02185964* obj) {
    return ((obj->f60 == -1) & (obj->f64 == -1)) != 0;
}
