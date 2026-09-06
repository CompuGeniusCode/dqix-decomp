#include <globaldefs.h>

int PeekInputLogB(void);
extern "C" int func_ov026_021dbd1c(void* p0, void* p1, int flag);

// USA: func_ov000_02163b14
ARM int InvokeIfInputLogBIs3_021dbd1c(void* p0, void* p1) {
	int v = PeekInputLogB();
	if (v != 3) {
		return v;
	}
	return func_ov026_021dbd1c(p0, p1, 1);
}
