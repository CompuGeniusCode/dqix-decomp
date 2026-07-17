#include <globaldefs.h>

char* GetFieldPtrByMask_022133f8(int tag);
extern "C" void func_ov031_02215528(void *a, int b, void *c);
extern "C" int func_ov031_0220764c(void *a);
extern "C" void SetFieldCAndA_022134cc(int);

extern int data_ov031_0224e1c0;

// USA: func_ov031_02215358
ARM int SetupAndDispatch_02215358(int arg) {
	char *p1 = GetFieldPtrByMask_022133f8(1);
	char *p2 = GetFieldPtrByMask_022133f8(4);
	func_ov031_02215528(p1, arg, p2);
	data_ov031_0224e1c0 = 4;
	if (func_ov031_0220764c(p2) == 0) return 0xc;
	SetFieldCAndA_022134cc(2);
	return 0x11;
}
