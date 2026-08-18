#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern char data_ov033_022a2a14[12];
extern char data_ov033_022a2a08[12];

struct Obj022a296c { void* field0; };

// USA: func_ov033_022a296c
ARM void* InitField0202f808_022a296c(struct Obj022a296c* obj) {
	obj->field0 = &data_ov033_022a2a14;
	((BackgroundLoader*)(obj))->InitializeOrReset();
	obj->field0 = &data_ov033_022a2a08;
	return obj;
}
