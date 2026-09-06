#include <globaldefs.h>

extern "C" void func_ov031_0223e2c0(int, void*);

struct Mid02236e38 { char pad[0x14]; int f14; };
struct Base02236e38 { char pad[4]; struct Mid02236e38 *p; };
extern struct Base02236e38 data_ov031_02290d04;

// USA: func_ov031_02236e38  (semantic: CallEntryAndClearField14_02236e38)
extern "C" ARM void func_ov031_02236e38(void* extra) {
    func_ov031_0223e2c0(0, extra);
    data_ov031_02290d04.p->f14 = 0;
}
