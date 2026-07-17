#include <globaldefs.h>

struct Obj02205194;

int AllocateAndInit_02205414(void);
void* SetLookupFields_02205134(void* a, void* b, int c);
int GetField64OrField68Then0220520c_0220529c(Obj02205194* obj, void* extra);
int RunSessionCase_022053a0(void);

// USA: func_ov031_02205364
ARM int InitAndRegister_02205364(void) {
	int obj = AllocateAndInit_02205414();
	if (obj == 0) {
		return -49;
	}
	void* extra = SetLookupFields_02205134((void*)RunSessionCase_022053a0, (void*)obj, 1);
	GetField64OrField68Then0220520c_0220529c((Obj02205194*)obj, extra);
	return obj;
}
