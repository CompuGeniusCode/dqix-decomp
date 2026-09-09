#include <globaldefs.h>

extern "C" int _Z8fix32cosi(int);
extern "C" int _Z8fix32sini(int);
extern "C" void func_ov017_0218db14(void* obj, int* vec, int c, int d, unsigned char e);

// USA: func_ov017_0218da48
ARM void BuildAndForwardVec_0218da48(void* obj, int angle, int c, int d, unsigned char e) {
	int vec[3];
	int cosv = _Z8fix32cosi(angle);
	int sinv = _Z8fix32sini(angle);
	vec[0] = sinv;
	vec[1] = 0;
	vec[2] = cosv;
	func_ov017_0218db14(obj, vec, c, d, e);
}
