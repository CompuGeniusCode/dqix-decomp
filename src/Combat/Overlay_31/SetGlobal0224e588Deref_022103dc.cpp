#include <globaldefs.h>

extern void* data_ov031_0224e588;

// USA: func_ov031_022103dc
ARM void SetGlobal0224e588Deref_022103dc(void* value) {
	void* volatile* ppTarget = (void* volatile*)data_ov031_0224e588;
	if (ppTarget != NULL) {
		(void)*ppTarget;
		*ppTarget = value;
	}
}
