#include <globaldefs.h>

// USA: func_ov016_0218f2f0
ARM int IncrementCounters_0218f2f0(void* obj) {
	char* o = (char*)obj;
	unsigned int count = *(unsigned int*)(o + 0x9c);
	unsigned int limit = *(unsigned int*)(o + 0xa0);
	if (count >= limit) return 0;
	*(unsigned int*)(o + 0x9c) = count + 1;
	unsigned int c2 = *(unsigned int*)(o + 0xc4) + 1;
	*(unsigned int*)(o + 0xc4) = c2;
	if (c2 == *(unsigned int*)(o + 0xa8)) {
		*(unsigned int*)(o + 0xc4) = 0;
	}
	return 1;
}
