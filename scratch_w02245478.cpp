#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" ARM int func_ov031_022119d0(int *out, int *mapped);

struct Struct_02245528;
void SetField34AndClear35_37_02245528(struct Struct_02245528* p, int v);

struct Struct02245478 {
	unsigned char pad_0[0x37c];
	void* field_37c;
	int field_380;
	unsigned char pad_384[0x394 - 0x384];
	int field_394;
	unsigned char field_398;
};

// USA: func_ov031_02245478
extern "C" ARM void func_ov031_02245478(struct Struct02245478* obj) {
	int a, b;
	int state = func_ov031_022119d0(&a, &b);
	memset(obj->field_37c, 0, obj->field_380);
	obj->field_394 = -a;
	switch (b) {
		case 0:
			obj->field_394 = 0;
			break;
		case 1:
			obj->field_394 = 0;
			break;
		case 6:
			if ((unsigned int)(state - 14) <= 1) {
				obj->field_398 = 1;
			}
			break;
		case 7:
			obj->field_398 = 2;
			break;
		default:
			break;
	}
	SetField34AndClear35_37_02245528((struct Struct_02245528*)obj, 0);
}
