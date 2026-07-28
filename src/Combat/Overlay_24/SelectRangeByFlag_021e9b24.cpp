#include <globaldefs.h>

struct PackedTriple_021e9b24 {
	unsigned int a : 10;
	unsigned int b : 10;
	unsigned int c : 10;
	unsigned int hi : 2;
};

struct Range_021e9b24 {
	char pad[0x20];
	struct PackedTriple_021e9b24 f20;
	struct PackedTriple_021e9b24 f24;
};

unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);

// USA: func_ov024_021e9b24  (semantic: SelectRangeByFlag_021e9b24)
extern "C" ARM unsigned short func_ov024_021e9b24(void* unused0, int id, struct Range_021e9b24* range, int flagArg) {
	if (flagArg != 0) {
		return SelectByIndexRange0to3_021da644(id, range->f24.b, range->f24.c);
	} else {
		return SelectByIndexRange0to3_021da644(id, range->f20.c, range->f24.a);
	}
}
