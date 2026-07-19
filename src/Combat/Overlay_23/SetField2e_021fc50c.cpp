#include <globaldefs.h>

struct S021fc50c { char pad[0x2e]; unsigned char field2e; };

// USA: func_ov023_021fc50c
ARM void SetField2e_021fc50c(struct S021fc50c *obj, unsigned char v) {
	obj->field2e = v;
}
