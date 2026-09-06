#include <globaldefs.h>

extern "C" int func_ov031_02213800(void* obj, void* b);
extern "C" int strncmp(const void*, const void*, unsigned int);

// USA: func_ov031_02213910  (semantic: FindMatchingEntry2_02213910)
extern "C" ARM int func_ov031_02213910(char* obj, char* b) {
	if (*(unsigned short*)(obj + 0xa) == 0x20) {
		int r = func_ov031_02213800(obj, b);
		if (r > 0) return r;
	}
	int i = 0;
	int count0 = *(unsigned char*)(b + 0xd12);
	if (count0 > 0) {
		char* entry = b;
		char* namePtr = b + 0x47c;
		unsigned short nameLen = *(unsigned short*)(obj + 0xa);
		int count = *(unsigned char*)(b + 0xd12);
		do {
			if (nameLen == *(unsigned short*)(entry + 0x47a)) {
				if (strncmp(obj + 0xc, namePtr, nameLen) == 0) {
					return *(unsigned char*)(b + 0x445 + i * 4);
				}
			}
			i++;
			entry += 0xc0;
			namePtr += 0xc0;
		} while (i < count);
	}
	return -1;
}
