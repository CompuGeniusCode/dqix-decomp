#include <globaldefs.h>

// USA: func_ov031_022148e4
ARM unsigned int FindFirstClearBit_022148e4(char* obj) {
	unsigned char count = *(unsigned char*)(obj + 0xd12);
	unsigned int i = 0;
	unsigned int result = 0;
	if (i < count) {
		do {
			unsigned char b = *(unsigned char*)(obj + i * 4 + 0x447);
			if (!(b & 0x80)) {
				result = i;
				goto end;
			}
			i = (i + 1) & 0xff;
		} while (i < count);
	}
end:
	return result;
}
