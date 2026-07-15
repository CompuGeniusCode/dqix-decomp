#include <globaldefs.h>

extern "C" void func_ov023_021f809c(void* obj, int a1, int a2, int a3);

struct ObjE2_021f8944 { char pad[0xe2]; unsigned short fieldE2; };

// USA: func_ov023_021f8944
ARM void SetFieldE2AndMaybeCall_021f8944(struct ObjE2_021f8944* obj, int a1, int a2, int a3) {
	a2 &= 0xf;
	obj->fieldE2 = a2;
	if (a3 != 0) func_ov023_021f809c(obj, a1, a2, a3);
}
