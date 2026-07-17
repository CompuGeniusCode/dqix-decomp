#include <globaldefs.h>

struct Holder021583fc { char pad[0x150]; void* ptr; };

// USA: func_ov005_021583fc
ARM void SetPtrFieldByte021583fc(Holder021583fc* obj, char val) {
	char* p = (char*)obj->ptr;
	if (p) {
		p[0x56e] = val;
	}
}
