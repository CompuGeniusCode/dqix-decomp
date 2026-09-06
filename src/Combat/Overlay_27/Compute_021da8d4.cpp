#include <globaldefs.h>

extern void *data_ov027_021e33ec;

struct Table_021da8d4 {
	int wordArr[3];
	unsigned short thresholds[3];
	unsigned short count;
};

struct Elem_021da8d4 {
	int f0;
	int pad4;
	int f8;
	int pad12;
};

struct Out_021da8d4 {
	int f0;
	int f4;
	int f8;
	unsigned char fc;
};

// USA: func_ov027_021da8d4  (semantic: Compute_021da8d4)
extern "C" ARM int func_ov027_021da8d4(Out_021da8d4 *out, Table_021da8d4 *table, unsigned int key, void *rawElems) {
	if (key >= table->count) {
		return 0;
	}
	signed char idx = 2;
	for (;;) {
		if (key >= table->thresholds[idx]) break;
		idx = idx - 1;
		if (idx < 0) break;
	}
	if (idx < 0) {
		return 0;
	}
	int limit = *(int *)((char *)data_ov027_021e33ec + 0x1000 + 0x318);
	int diff = key - table->thresholds[idx];
	int mulResult = diff * limit;
	Elem_021da8d4 *elemsArr = (Elem_021da8d4 *)((char *)rawElems + 0xc);
	Elem_021da8d4 *e = elemsArr + idx;
	int f4 = e->f8 - mulResult;
	out->f4 = f4;
	int limit2 = *(int *)((char *)data_ov027_021e33ec + 0x1000 + 0x318);
	if ((unsigned int)f4 > (unsigned int)limit2) {
		out->f4 = limit2;
	}
	out->f8 = mulResult + table->wordArr[idx];
	out->f0 = mulResult + e->f0;
	out->fc = (unsigned char)idx;
	return 1;
}
