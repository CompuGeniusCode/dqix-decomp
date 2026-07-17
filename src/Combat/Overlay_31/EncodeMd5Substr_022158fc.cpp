#include <globaldefs.h>
#include "System/Memory.h"

struct Md5State022158fc {
	unsigned int a, b, c, d;
	unsigned int countLow;
	unsigned int countHigh;
	unsigned char buffer[0x40];
};

extern "C" void InitMd5State(struct Md5State022158fc *state);
extern "C" void func_020c0368(struct Md5State022158fc *state, void *data, int len);
extern "C" void func_020c0430(void *digest, struct Md5State022158fc *state);

// USA: func_ov031_022158fc
ARM void EncodeMd5Substr_022158fc(void *data, void *dst) {
	struct Md5State022158fc state;
	unsigned char digest[0x14];
	InitMd5State(&state);
	func_020c0368(&state, data, 0x18);
	func_020c0430(digest, &state);
	VectorizedInvertedMemcpy(digest + 3, dst, 0xd);
}
