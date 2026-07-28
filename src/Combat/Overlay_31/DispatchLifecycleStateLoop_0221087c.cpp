#include <globaldefs.h>

struct GlobalCtx0221087c {
	int field0;
	int field4;
	char pad8[0x40 - 8];
	volatile int field40;
};

extern void* volatile data_ov031_0224e588;

void SetGlobal0224e588Deref_022103dc(void* value);
void ResetFieldAndUnblock_022103f8(void* value);
int GetStateAndMaybeNotify_02212598(void);
int CallStub0221a854_022125bc(void);
int RegisterAndDispatch_02212524(char* str, void* b);
void SleepCurrentContext(unsigned int ms);

// USA: func_ov031_0221087c  (semantic: DispatchLifecycleStateLoop_0221087c)
extern "C" ARM void func_ov031_0221087c(void) {
	{
		GlobalCtx0221087c* obj = (GlobalCtx0221087c*)data_ov031_0224e588;
		if (obj->field4 == 1 && obj->field40 == 3) {
			SetGlobal0224e588Deref_022103dc((void*)4);
			return;
		}
	}

	{
		GlobalCtx0221087c* obj = (GlobalCtx0221087c*)data_ov031_0224e588;
		if (!RegisterAndDispatch_02212524((char*)obj + 0x38, (char*)obj + 0x44)) return;
	}

	GlobalCtx0221087c* obj;
	while ((obj = (GlobalCtx0221087c*)data_ov031_0224e588)->field40 != 3 && obj->field40 != 5 && obj->field40 != 4) {
		int state = GetStateAndMaybeNotify_02212598();
		obj = (GlobalCtx0221087c*)data_ov031_0224e588;
		obj->field40 = state;
		obj = (GlobalCtx0221087c*)data_ov031_0224e588;
		switch (obj->field40) {
		case 1:
		case 2:
			SleepCurrentContext(0x64);
			obj = (GlobalCtx0221087c*)data_ov031_0224e588;
			if (obj->field4 == 2) {
				CallStub0221a854_022125bc();
			}
			break;
		case 0:
		case 3:
		case 4:
		case 5:
			if (obj->field40 == 3 && obj->field4 == 1) {
				SetGlobal0224e588Deref_022103dc((void*)4);
			} else {
				ResetFieldAndUnblock_022103f8((void*)1);
				obj = (GlobalCtx0221087c*)data_ov031_0224e588;
				obj->field40;
			}
			break;
		}
	}
}
