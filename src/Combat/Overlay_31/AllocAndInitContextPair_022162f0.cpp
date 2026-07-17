#include <globaldefs.h>
#include "System/Memory.h"

extern "C" int GetBufferSize1da0_02215fcc(void);
extern "C" void* CallWithConst32_02211b54(void *a, void *b);

struct Struct0224e5dc {
	void *field0;
	void *field4;
	int field8;
};
extern struct Struct0224e5dc data_ov031_0224e5dc;

// USA: func_ov031_022162f0
ARM void AllocAndInitContextPair_022162f0(int a, int b) {
	int size = GetBufferSize1da0_02215fcc();
	data_ov031_0224e5dc.field4 = CallWithConst32_02211b54((void*)1, (void*)size);
	data_ov031_0224e5dc.field0 = CallWithConst32_02211b54((void*)1, (void*)0x794);
	VectorizedMemset(data_ov031_0224e5dc.field0, 0, 0x794);
	*(int*)((char*)data_ov031_0224e5dc.field0 + 0) = a;
	*(int*)((char*)data_ov031_0224e5dc.field0 + 0x790) = b;
	data_ov031_0224e5dc.field8 = 0;
}
