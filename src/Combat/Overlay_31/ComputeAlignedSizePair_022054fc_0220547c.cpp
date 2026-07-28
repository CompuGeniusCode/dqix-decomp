#include <globaldefs.h>

extern "C" unsigned int func_ov031_022070bc(unsigned int size);

struct SizeInputStruct022054fc {
	unsigned short field0;
	unsigned char field2;
	unsigned char field3;
};
ARM int ComputeAlignedSizePair_022054fc(SizeInputStruct022054fc* p);

struct Obj0220547c {
	char pad0[0x2];
	unsigned short field2;
	char pad4[0x2];
	unsigned short field6;
	unsigned short field8;
	unsigned short fieldA;
	unsigned short fieldC;
	char pad14[0x2];
	SizeInputStruct022054fc s10;
	SizeInputStruct022054fc s14;
};

// USA: func_ov031_0220547c  (semantic: GetTotalSize_0220547c)
extern "C" ARM int func_ov031_0220547c(Obj0220547c* obj) {
	int total = 0x80;
	if (obj->field2 != 0) {
		total += 0x114;
		total += func_ov031_022070bc(obj->field2);
		total += func_ov031_022070bc(obj->field8);
		total += ComputeAlignedSizePair_022054fc(&obj->s10);
	}
	if (obj->field6 != 0) {
		total += 0x110;
		total += func_ov031_022070bc(obj->field6);
		total += func_ov031_022070bc(obj->fieldA);
		total += func_ov031_022070bc(obj->fieldC);
		total += ComputeAlignedSizePair_022054fc(&obj->s14);
	}
	return total;
}
