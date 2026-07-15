#include <globaldefs.h>

int PeekInputLogB(void);
extern "C" int func_ov026_021dbe44(void* p);

// USA: func_ov000_02163b40
ARM int InvokeIfInputLogBIs3_021dbe44(void* p) {
	int v = PeekInputLogB();
	if (v != 3) {
		return v;
	}
	return func_ov026_021dbe44(p);
}
