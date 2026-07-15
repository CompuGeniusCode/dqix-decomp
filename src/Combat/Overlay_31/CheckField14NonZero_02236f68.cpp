#include <globaldefs.h>

struct Mid02236f68 { char pad[0x14]; int f14; };
struct Base02236f68 { char pad[4]; struct Mid02236f68 *p; };
extern struct Base02236f68 data_ov031_02290d04;

// USA: func_ov031_02236f68
ARM int CheckField14NonZero_02236f68(void) {
    return data_ov031_02290d04.p->f14 != 0;
}
