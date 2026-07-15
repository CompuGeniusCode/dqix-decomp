#include <globaldefs.h>

struct Obj02176134 { char pad[0xc]; short val; };

extern "C" void func_ov000_0217616c(struct Obj02176134*);

// USA: func_ov000_02176134
ARM void SetShortField0xC02176134(struct Obj02176134* obj, short val) {
    if (val == obj->val) return;
    obj->val = val;
    func_ov000_0217616c(obj);
}
