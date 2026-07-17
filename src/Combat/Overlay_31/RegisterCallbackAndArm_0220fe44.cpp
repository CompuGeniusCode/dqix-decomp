#include <globaldefs.h>

extern void* data_ov031_0224e580;
int BlockIfNotStateSeven_022102c8(void);
void InvokeCallbackField28IfMatch_0220fdec(int a, int* b);
void SetGlobal0224e588FieldA0c_02210314(int v);

// USA: func_ov031_0220fe44
ARM int RegisterCallbackAndArm_0220fe44(int (*cb)(int*)) {
	if (data_ov031_0224e580 == NULL) return 0;
	if (!BlockIfNotStateSeven_022102c8()) return 0;
	*(int*)((char*)data_ov031_0224e580 + 0x2c) = 0;
	*(int (**)(int*))((char*)data_ov031_0224e580 + 0x28) = cb;
	SetGlobal0224e588FieldA0c_02210314((int)InvokeCallbackField28IfMatch_0220fdec);
	return 1;
}
