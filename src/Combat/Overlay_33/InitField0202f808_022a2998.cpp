#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern char data_ov033_022a2a14[12];

struct Obj022a2998 { void* field0; };

// USA: func_ov033_022a2998
ARM void* InitField0202f808_022a2998(struct Obj022a2998* obj) {
	obj->field0 = &data_ov033_022a2a14;
	((BackgroundLoader*)(obj))->InitializeOrReset();
	return obj;
}
