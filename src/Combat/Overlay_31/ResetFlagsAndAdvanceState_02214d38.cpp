#include <globaldefs.h>

extern "C" void func_ov031_02214520(int mode);

struct NibblePair02214d38 {
	unsigned char lowNibble : 4;
	unsigned char highNibble : 4;
};

// USA: func_ov031_02214d38  (semantic: ResetFlagsAndAdvanceState_02214d38)
extern "C" ARM int func_ov031_02214d38(char* obj) {
	*(unsigned char*)(obj + 0xd15) = 0;
	((struct NibblePair02214d38*)(obj + 0xd0b))->highNibble += 1;
	func_ov031_02214520(0);
	*(unsigned char*)(obj + 0xd11) = 1;
	return 3;
}
