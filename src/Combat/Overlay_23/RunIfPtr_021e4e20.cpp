#include <globaldefs.h>

struct Obj021e4e20 {
	char pad[0x128];
	void *ptr;
};

extern "C" int func_ov023_021e6194(void *p);

// USA: func_ov023_021e4e20
ARM int RunIfPtr_021e4e20(struct Obj021e4e20 *obj) {
	void *p = obj->ptr;
	if (p == NULL) {
		return 0;
	}
	return func_ov023_021e6194(p);
}
