#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov031_022119d0(int* out, int* mapped);

struct Struct_02245528;
void SetField34AndClear35_37_02245528(Struct_02245528* p, int v);

struct Struct_02245478 {
	unsigned char pad_000[0x37c];
	void* p37c;
	int len380;
	unsigned char pad_384[0x394 - 0x384];
	int f394;
	unsigned char f398;
};

// USA: func_ov031_02245478  (semantic: DispatchMappedCategoryAndClear_02245478)
extern "C" ARM void func_ov031_02245478(struct Struct_02245478* obj) {
	int outVal;
	int mapped;
	int cat = func_ov031_022119d0(&outVal, &mapped);
	memset(obj->p37c, 0, obj->len380);
	obj->f394 = -outVal;
	switch (mapped) {
	case 0:
		obj->f394 = 0;
		break;
	case 1:
		obj->f394 = 0;
		break;
	case 6:
		if ((unsigned int)(cat - 14) <= 1) {
			obj->f398 = 1;
		}
		break;
	case 7:
		obj->f398 = 2;
		break;
	default:
		break;
	}
	SetField34AndClear35_37_02245528((Struct_02245528*)obj, 0);
}
