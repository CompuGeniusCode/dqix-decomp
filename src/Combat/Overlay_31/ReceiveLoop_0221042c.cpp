#include <globaldefs.h>

extern "C" int CallWithZeroZeroZero_02207360(int a, int b, int c);
extern "C" void func_ov031_02210358(int a, int b);

struct GlobalPtrStruct0221042c {
	char pad[0x1b8];
	int field1b8;
};

extern GlobalPtrStruct0221042c* data_ov031_0224e588;

// USA: func_ov031_0221042c
ARM int ReceiveLoop_0221042c(void *buf) {
	int result = 0;
	int off;
	if (data_ov031_0224e588 == NULL) {
		return -0x1c + result;
	}
	int total = *(int*)buf;
	if (total > 0x414) {
		func_ov031_02210358(6, 6-0x38);
		return ~0x22;
	}
	off = result;
	if (total <= 0) {
		return result;
	}
	do {
		result = CallWithZeroZeroZero_02207360(data_ov031_0224e588->field1b8, (int)buf, total - off);
		if (result < 0) {
			func_ov031_02210358(6, 6-0x38);
			return result;
		}
		off += result;
		buf = (char*)buf + result;
	} while (off < total);
	return off;
}
