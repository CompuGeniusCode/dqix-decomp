#include <globaldefs.h>
#include "System/Interrupts.h"

void Dispatch02203670(void* item);

struct SubCtx02205ebc {
	char pad[0xf8];
	void* field0xf8;
};

struct Obj02205ebc {
	char pad[0x64];
	SubCtx02205ebc* field64;
};

// USA: func_ov031_02205ebc
ARM void* PopField248_02205ebc(Obj02205ebc* obj) {
	SubCtx02205ebc* ctx = obj->field64;
	int state = DisableIRQInterrupts();
	void* val = ctx->field0xf8;
	if (val) {
		ctx->field0xf8 = NULL;
		Dispatch02203670(val);
	}
	SetIRQInterruptState(state);
	return val;
}
