#include <globaldefs.h>

extern "C" void* func_ov031_02205414(void* arg);

struct Obj02205194;
void* SetLookupFields_02205134(void* a, void* b, int c);
int GetField64OrField68Then0220520c_0220529c(Obj02205194* obj, void* extra);

extern "C" void func_ov031_022053a0(void);

// USA: func_ov031_02205364
extern "C" ARM int func_ov031_02205364(void* arg) {
	void* obj = func_ov031_02205414(arg);
	if (!obj) return -0x31;
	void* extra = SetLookupFields_02205134((void*)func_ov031_022053a0, obj, 1);
	GetField64OrField68Then0220520c_0220529c((Obj02205194*)obj, extra);
	return (int)obj;
}
