#include <globaldefs.h>

// USA: func_ov009_021855dc
ARM void SetStatValue021855dc(unsigned char *self, int val) {
	signed char v = (signed char)val;
	*(signed char*)(self + 0xc58) = v;
	*(signed char*)(self + 0xc59) = 0;
	int idx = self[0xda3];
	signed char *arr = (signed char*)(self + 0xda0);
	if (arr[idx] < val) {
		arr[idx] = v;
	}
	*(unsigned int*)(self + 0xd9c) |= 0x1100;
	if (val != 9 && val != 0xb && val != 0xc) {
		unsigned char *sub = self + 0x19c;
		*(unsigned int*)(sub + 0xc00) |= 0x80;
	}
}
