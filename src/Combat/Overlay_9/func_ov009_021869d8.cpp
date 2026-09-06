#include <globaldefs.h>

extern "C" void func_ov009_02188c2c(void *self);
extern "C" void func_ov009_02188d9c(void *self);
extern "C" void func_ov009_02188e70(void *self, unsigned char val);
extern "C" void func_ov009_02188944(void *self, unsigned char val);
extern "C" int func_ov009_02188ee8(void *self);
extern "C" ARM void _Z20SetStatValue021855dcPhi(unsigned char *self, int val);

// USA: func_ov009_021869d8  (semantic: AdvanceStatStep_021869d8)
extern "C" ARM void func_ov009_021869d8(unsigned char *self) {
	unsigned char step = self[0xc59];
	if (step == 0) {
		func_ov009_02188c2c(self);
		func_ov009_02188d9c(self);
		int idx = self[0xda3];
		unsigned char val = *(self + idx + 0xdae);
		func_ov009_02188e70(self, val);
		*(unsigned int*)(self + 0xd9c) |= 1;
		self[0xc59] = self[0xc59] + 1;
		return;
	}
	if (step == 1) {
		if (*(unsigned int*)(self + 0xd9c) & 0x80) {
			return;
		}
		int idx = self[0xda3];
		unsigned char val = *(self + idx + 0xdae);
		func_ov009_02188944(self, val);
		self[0xc59] = self[0xc59] + 1;
		return;
	}
	if (step != 2) {
		return;
	}
	int result = func_ov009_02188ee8(self);
	if (result == -2) {
		_Z20SetStatValue021855dcPhi(self, 5);
		return;
	}
	if (result == -3) {
		_Z20SetStatValue021855dcPhi(self, 3);
		return;
	}
	if (result < 0x65 || result > 0x6c) {
		return;
	}
	int idx2 = self[0xda3];
	int v = result - 0x64;
	signed char *arr = (signed char*)(self + 0xda0);
	if (v > arr[idx2]) {
		return;
	}
	if (v == *(signed char*)(self + 0xc58)) {
		return;
	}
	_Z20SetStatValue021855dcPhi(self, v & 0xff);
}
