#include <globaldefs.h>

#pragma optimize_for_size off

extern "C" void* func_020c7e0c(void* data, int a, int b);
extern void* data_ov031_0224e580;

struct Obj0220f518 { char pad0x1c[0x1c]; int f1c; int f20; int f24; };

// USA: func_ov031_0220f518  (semantic: ClearFieldsAndNotify_0220f518)
extern "C" ARM void* func_ov031_0220f518(struct Obj0220f518* obj) {
	if (obj) {
		obj->f1c = 0;
		obj->f20 = 0;
		obj->f24 = 0;
	}
	void* data = data_ov031_0224e580;
	if (data == NULL) return NULL;
	return func_020c7e0c(data, (int)obj, 0);
}
