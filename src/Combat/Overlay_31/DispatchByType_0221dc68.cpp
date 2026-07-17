#include <globaldefs.h>

extern "C" int func_ov031_0221d384(int a1);
extern "C" int func_ov031_0221dcbc(void* a, void* b, void* c);
extern "C" int func_ov031_0221de00(void* a, void* b, void* c);
extern "C" int func_ov031_0221dedc(void* a, void* b, void* c);

// USA: func_ov031_0221dc68
ARM int DispatchByType_0221dc68(int type, void* a2, void* a3, void* a4) {
	switch (type) {
	case 0:
		func_ov031_0221d384(2);
		return func_ov031_0221dcbc(a2, a3, a4);
	case 1:
		func_ov031_0221d384(3);
		return func_ov031_0221de00(a2, a3, a4);
	case 2:
		func_ov031_0221d384(5);
		return func_ov031_0221dedc(a2, a3, a4);
	default:
		return -1;
	}
}
