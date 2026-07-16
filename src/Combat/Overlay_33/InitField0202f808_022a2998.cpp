#include <globaldefs.h>

extern "C" int func_0202f808(void*);
extern char data_ov033_022a2a14[12];

struct Obj022a2998 { void* field0; };

// USA: func_ov033_022a2998
ARM void* InitField0202f808_022a2998(struct Obj022a2998* obj) {
	obj->field0 = &data_ov033_022a2a14;
	func_0202f808(obj);
	return obj;
}
