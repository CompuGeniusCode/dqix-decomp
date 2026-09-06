#include <globaldefs.h>

int PeekInputLogB(void);
extern "C" int func_ov026_021dbf04(void* p);

// USA: func_ov000_02163d94
ARM int InvokeIfInputLogBIs3_021dbf04(void* p) {
	int v = PeekInputLogB();
	if (v != 3) {
		return v;
	}
	return func_ov026_021dbf04(p);
}
