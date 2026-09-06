#include <globaldefs.h>

extern "C" int func_02030c9c(int);
extern "C" int func_02030c68(int);
extern "C" void func_ov017_0218db14(void* obj, int* vec, int c, int d, unsigned char e);

// USA: func_ov017_0218da48
ARM void BuildAndForwardVec_0218da48(void* obj, int angle, int c, int d, unsigned char e) {
	int vec[3];
	int cosv = func_02030c9c(angle);
	int sinv = func_02030c68(angle);
	vec[0] = sinv;
	vec[1] = 0;
	vec[2] = cosv;
	func_ov017_0218db14(obj, vec, c, d, e);
}
