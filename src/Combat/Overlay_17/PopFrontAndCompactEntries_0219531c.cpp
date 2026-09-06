#include <globaldefs.h>

extern "C" void func_ov017_02195214(void* dst, void* src);

// USA: func_ov017_0219531c
ARM int PopFrontAndCompactEntries_0219531c(void* obj, void* outEntry) {
	unsigned char* o = (unsigned char*)obj;
	if (o[0x42f0] == 0) return 0;
	func_ov017_02195214(outEntry, o + 0x42f1);
	o[0x42f0] = o[0x42f0] - 1;
	int i = 0;
	while (i < o[0x42f0]) {
		func_ov017_02195214(o + 0x42f1 + i * 15, o + 0x42f1 + (i + 1) * 15);
		i++;
	}
	return 1;
}
