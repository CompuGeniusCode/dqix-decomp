#include <globaldefs.h>

extern "C" void func_ov001_0215b074(int type, int a, int b);

// USA: func_ov001_0215b684
ARM int EnqueueEventType12_0215b684(int a, int b) {
	func_ov001_0215b074(12, a, b);
	return 1;
}
