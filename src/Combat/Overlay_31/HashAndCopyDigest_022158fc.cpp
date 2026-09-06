#include <globaldefs.h>
#include "System/Memory.h"

struct Md5State020c0328;
void InitMd5State(struct Md5State020c0328* state);

extern "C" void func_020c0368(struct Md5State020c0328* state, const void* data, unsigned int length);
extern "C" void func_020c0430(void* digest, struct Md5State020c0328* state);

// USA: func_ov031_022158fc  (semantic: HashAndCopyDigest_022158fc)
extern "C" ARM void func_ov031_022158fc(void* src, void* dst) {
	char state[0x58];
	char digest[0x14];
	InitMd5State((struct Md5State020c0328*)state);
	func_020c0368((struct Md5State020c0328*)state, src, 0x18);
	func_020c0430(digest, (struct Md5State020c0328*)state);
	VectorizedInvertedMemcpy(digest + 3, dst, 0xd);
}
