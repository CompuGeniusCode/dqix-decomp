#include <globaldefs.h>
#include "System/ProcessorContext.h"

// USA: func_ov031_02207d60
ARM void RegisterNamedEntry_02207d60(void* a, void* b) {
	void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
	if (mgr) {
		void* list = *(void**)((char*)mgr + 0xc);
		if (list) {
			*(void**)((char*)list + 0x814) = a;
			*(void**)((char*)list + 0x818) = b;
		}
	}
}
