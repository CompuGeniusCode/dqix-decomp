#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void* p);
extern "C" int func_0203b318(void* obj, int a, int b);

struct Param021e58b4 { char pad[8]; unsigned short field_8; signed char field_a; };

// USA: func_ov025_021e58b4
ARM int DispatchEvent021e58b4(struct Param021e58b4* p) {
    void* obj = func_ov017_0218b5b0(p);
    func_0203b318(obj, p->field_a, p->field_8);
    return 1;
}
