#include <globaldefs.h>

extern "C" void func_ov001_0215b074(int type, int a, int b);

// USA: func_ov001_0215b64c
ARM int EnqueueEventType10_0215b64c(int a, int b) {
	func_ov001_0215b074(10, a, b);
	return 1;
}
