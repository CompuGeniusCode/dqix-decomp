#include <globaldefs.h>

struct Counter0223c150 {
	unsigned char pad0[4];
	short field4;
	unsigned short field6;
	unsigned char field8;
	unsigned char field9;
};

struct SignedValue0223c150 { unsigned short flags; unsigned short unk2; unsigned short value; };

int Divide32(int numer, unsigned int denom);
void StoreMagnitudeAndSignFlag020c5128(struct SignedValue0223c150* dst, int value);
void TailCallField4_0223e2c0(int, void*);
extern unsigned char data_ov031_022493a0[8];
extern Counter0223c150* data_ov031_02290d34;

// USA: func_ov031_0223c150
#pragma optimize_for_size off
ARM void UpdateCounterAndReportSigned_0223c150(void* a, Counter0223c150* s) {
	unsigned char local[8];
	local[4] = data_ov031_022493a0[4];
	local[5] = data_ov031_022493a0[5];
	local[6] = data_ov031_022493a0[6];
	local[7] = data_ov031_022493a0[7];
	local[0] = data_ov031_022493a0[0];
	local[1] = data_ov031_022493a0[1];
	local[2] = data_ov031_022493a0[2];
	local[3] = data_ov031_022493a0[3];

	s->field4 = s->field4 + 1;
	int q = Divide32(s->field4 << 4, s->field6);
	unsigned char* p1 = &local[4];
	unsigned char flagByte = p1[s->field8];
	if (flagByte & 1) {
		q = 0x10 - q;
	}
	if (flagByte & 0x10) {
		q = -q;
	}
	if (s == data_ov031_02290d34) {
		StoreMagnitudeAndSignFlag020c5128((struct SignedValue0223c150*)0x4001050, q);
	} else {
		StoreMagnitudeAndSignFlag020c5128((struct SignedValue0223c150*)0x4000050, q);
	}
	if (s->field4 < s->field6) {
		return;
	}
	if (s == data_ov031_02290d34) {
		StoreMagnitudeAndSignFlag020c5128((struct SignedValue0223c150*)0x4001050, (signed char)local[s->field8]);
	} else {
		StoreMagnitudeAndSignFlag020c5128((struct SignedValue0223c150*)0x4000050, (signed char)local[s->field8]);
	}
	s->field9 = 0;
	TailCallField4_0223e2c0(1, a);
}
