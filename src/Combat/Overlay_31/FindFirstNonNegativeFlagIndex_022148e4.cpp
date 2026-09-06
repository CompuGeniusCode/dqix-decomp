#include <globaldefs.h>

struct FlagByte022148e4 {
	unsigned char lowBits : 7;
	unsigned char topBit : 1;
};

// USA: func_ov031_022148e4  (semantic: FindFirstNonNegativeFlagIndex_022148e4)
extern "C" ARM int func_ov031_022148e4(void* obj) {
	unsigned char i;
	int result;
	result = 0;
	i = 0;
	unsigned int count = *(unsigned char*)((char*)obj + 0xd12);
	if (i < count) {
		do {
			FlagByte022148e4* fb = (FlagByte022148e4*)((char*)obj + 0x447 + i * 4);
			if (!fb->topBit) {
				result = i;
				break;
			}
			i++;
		} while (i < count);
	}
	return result;
}
