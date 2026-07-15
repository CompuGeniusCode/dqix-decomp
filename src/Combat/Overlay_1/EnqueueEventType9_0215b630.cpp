#include <globaldefs.h>

extern "C" void func_ov001_0215b074(int type, int a, int b);

// USA: func_ov001_0215b630
ARM int EnqueueEventType9_0215b630(int a, int b) {
	func_ov001_0215b074(9, a, b);
	return 1;
}
