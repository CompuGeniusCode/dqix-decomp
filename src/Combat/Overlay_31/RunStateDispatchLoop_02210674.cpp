#include <globaldefs.h>

struct Obj02210674 { volatile int selector; };

extern void* data_ov031_0224e588;

void SetGlobal0224e588Deref_022103dc(void* value);
void DispatchByState4Field_02210720(void);
extern "C" void func_ov031_02210780(void);
extern "C" void func_ov031_0221087c(void);
extern "C" void func_ov031_02210988(void);
extern "C" void func_ov031_02210b4c(void);
extern "C" void func_ov031_02210bec(void);
extern "C" void func_ov031_02210e20(void);

// USA: func_ov031_02210674  (semantic: RunStateDispatchLoop_02210674)
extern "C" ARM void func_ov031_02210674(void) {
	if (data_ov031_0224e588 == NULL) return;
	SetGlobal0224e588Deref_022103dc((void*)1);
	Obj02210674* obj = (Obj02210674*)data_ov031_0224e588;
	if (obj->selector == 0) return;
	do {
		switch (obj->selector) {
		case 1: DispatchByState4Field_02210720(); break;
		case 2: func_ov031_02210780(); break;
		case 3: func_ov031_0221087c(); break;
		case 4: func_ov031_02210988(); break;
		case 5: func_ov031_02210b4c(); break;
		case 6: func_ov031_02210bec(); break;
		case 7: func_ov031_02210e20(); break;
		}
		obj = (Obj02210674*)data_ov031_0224e588;
	} while (obj->selector != 0);
}
