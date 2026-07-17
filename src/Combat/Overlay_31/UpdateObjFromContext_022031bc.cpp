#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" unsigned short func_ov031_02203078(void);

struct GlobalStruct0224c980_022031bc {
	char pad[0x50];
	unsigned int field50;
};

extern GlobalStruct0224c980_022031bc data_ov031_0224c980;

struct SomeObj_022031bc {
	char pad0[0xa];
	unsigned short fieldA;
	char pad1[0x18 - 0xa - 2];
	unsigned short field18;
	unsigned short field1a;
	unsigned int field1c;
	unsigned int field20;
};

// USA: func_ov031_022031bc
ARM void UpdateObjFromContext_022031bc(int a, unsigned short b, unsigned int c) {
	SomeObj_022031bc* obj = (SomeObj_022031bc*)data_02111304.activeContext->unknown_A4;
	if (obj == NULL) {
		return;
	}
	unsigned int val = (c == 0x7f000001) ? data_ov031_0224c980.field50 : c;
	obj->field1a = b;
	obj->field18 = obj->field1a;
	obj->field20 = val;
	obj->field1c = val;
	if (a != 0) {
		obj->fieldA = (unsigned short)a;
		return;
	}
	obj->fieldA = func_ov031_02203078();
}
