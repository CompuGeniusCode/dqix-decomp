#include <globaldefs.h>

unsigned int ComputeNormalizedChecksum_02200684(void* p, unsigned int len);
int IsNonzeroAndNotNeg1_02201b94(int a, int b);
extern "C" void func_ov031_02201a94(void* a, void* b, void* c);
extern "C" void func_ov031_022019b0(void* a, void* b, void* c);

struct Header02201bb4 {
	char pad0[0xc];
	unsigned short seqHi;
	unsigned short seqLo;
	unsigned short ackHi;
	unsigned short ackLo;
};

#define SwapBytes16_02201bb4(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201bb4  (semantic: ProcessHeader_02201bb4)
extern "C" ARM void func_ov031_02201bb4(Header02201bb4* obj, void* type, void* len) {
	unsigned int checksum = ComputeNormalizedChecksum_02200684(type, (unsigned int)len);
	if (checksum != 0xffff) {
		return;
	}
	unsigned short a = obj->ackLo;
	unsigned short b = obj->ackHi;
	unsigned short c = obj->seqLo;
	unsigned short d = obj->seqHi;
	unsigned int seq = ((unsigned int)SwapBytes16_02201bb4(d) << 16) | SwapBytes16_02201bb4(c);
	unsigned int ack = ((unsigned int)SwapBytes16_02201bb4(b) << 16) | SwapBytes16_02201bb4(a);
	if (!IsNonzeroAndNotNeg1_02201b94((int)seq, (int)ack)) {
		return;
	}
	unsigned char kind = *(unsigned char*)type;
	switch (kind) {
	case 0:
		func_ov031_02201a94(obj, type, len);
		return;
	case 8:
		func_ov031_022019b0(obj, type, len);
		return;
	}
}
