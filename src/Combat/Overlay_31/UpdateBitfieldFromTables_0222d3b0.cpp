#include <globaldefs.h>

struct Struct0222d3b0 {
	unsigned char pad0[4];
	int* field4;
	unsigned char pad8[0x29 - 8];
	unsigned char field29;
};
extern Struct0222d3b0* data_ov031_02290c94;
extern unsigned char data_ov031_02248ecc[];
extern unsigned char data_ov031_02248ed0[];

// USA: func_ov031_0222d3b0  (semantic: UpdateBitfieldFromTables_0222d3b0)
extern "C" ARM void func_ov031_0222d3b0(void) {
	unsigned char b = data_ov031_02290c94->field29;
	int* p = data_ov031_02290c94->field4;
	int idx0 = b & 0xf;
	int idx1 = b >> 4;
	if (b >= 0x20) {
		idx1 = 1;
		idx0 = 0xf;
	}
	unsigned char t1 = data_ov031_02248ecc[idx1];
	unsigned char t2 = data_ov031_02248ed0[idx0];
	unsigned int val = *(unsigned int*)p;
	*(unsigned int*)p = (val & 0xfe00ff00u) | t1 | (((unsigned int)t2 << 23) >> 7);
}
