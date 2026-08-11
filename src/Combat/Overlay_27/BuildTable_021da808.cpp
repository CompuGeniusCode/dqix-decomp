#include <globaldefs.h>

extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);
extern "C" int func_ov027_021daa34(int idx, int addr, int len);
extern void *data_ov027_021e33ec;

struct TableOut_021da808 {
	int wordArr[3];
	unsigned short thresholds[3];
	unsigned short count;
};

struct Elem_021da808 {
	int f0;
	int f4;
	int f8;
	int pad12;
};

// USA: func_ov027_021da808  (semantic: BuildTable_021da808)
extern "C" ARM int func_ov027_021da808(TableOut_021da808 *out, void *rawElems) {
	Elem_021da808 *elemsArr;
	unsigned short *thresholds = (unsigned short *)((char *)out + 0xc);
	int sum = 0;
	if (rawElems == NULL) {
		return 0;
	}
	unsigned char i = 0;
	do {
		out->wordArr[i] = sum;
		sum += *(int *)((char *)rawElems + i * 0x10 + 0x14);
		i++;
	} while (i < 3);
	thresholds[0] = 0;
	elemsArr = (Elem_021da808 *)((char *)rawElems + 0xc);
	Elem_021da808 *ej;
	int f8;
	unsigned char j = 0;
	do {
		ej = &elemsArr[j];
		int limit = *(int *)((char *)data_ov027_021e33ec + 0x1000 + 0x318);
		f8 = ej->f8;
		unsigned int divResult = _u32_div_f(f8 + limit - 1, limit);
		unsigned short newThreshold = (unsigned short)(thresholds[j] + (unsigned short)divResult);
		int f4 = ej->f4;
		if (!func_ov027_021daa34(j, f4, f8)) {
			return 0;
		}
		if (j < 2) {
			unsigned short *tj = thresholds + j;
			tj[1] = newThreshold;
		} else {
			out->count = newThreshold;
		}
		j++;
	} while (j < 3);
	return 1;
}
