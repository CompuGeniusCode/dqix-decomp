#include <globaldefs.h>
#include "System/ProcessorContext.h"

int IsGlobal0224e598Set_02211848(void);
void SetGlobal0224e588Deref_022103dc(void* value);
extern "C" void func_ov031_0221038c(int v);

struct Ctx02210720 {
	int field0;
	int field4;
};

extern Ctx02210720* data_ov031_0224e588;

// USA: func_ov031_02210720
ARM void DispatchByState4Field_02210720(void) {
	if (IsGlobal0224e598Set_02211848()) {
		func_ov031_0221038c(2);
	}
	switch (data_ov031_0224e588->field4) {
	case 1:
		SetGlobal0224e588Deref_022103dc((void*)2);
		break;
	case 2:
		SetGlobal0224e588Deref_022103dc((void*)0);
		break;
	default:
		SleepCurrentContext(0x64);
		break;
	}
}
