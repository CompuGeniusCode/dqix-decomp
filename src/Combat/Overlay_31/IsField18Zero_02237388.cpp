#include <globaldefs.h>

struct Mid02237388 { unsigned char pad[0x18]; unsigned char field18; };
struct Base02237388 { char pad[4]; struct Mid02237388 *p; };
extern struct Base02237388 data_ov031_02290d04;

// USA: func_ov031_02237388
ARM int IsField18Zero_02237388(void) {
    if (data_ov031_02290d04.p == 0) {
        return 1;
    }
    return data_ov031_02290d04.p->field18 == 0;
}
