#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void func_ov031_0220aa30(void*);
void DispatchContext02200264(void);
unsigned long long GetCurrentTimestamp(void);

typedef int (*FnPtr02203424)(void);
struct GlobalStruct0224c980_02203424 {
	char pad[0x48];
	FnPtr02203424 field48;
};
extern GlobalStruct0224c980_02203424 data_ov031_0224c980;

// USA: func_ov031_02203424
ARM void UpdateAndWaitOnContext_02203424(void) {
	void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
	if (mgr == NULL) return;
	if (*((unsigned char*)mgr + 9) != 0) {
		func_ov031_0220aa30(mgr);
	}
	int start = (int)(GetCurrentTimestamp() >> 16);
	while (data_ov031_0224c980.field48() != 0 && *((unsigned char*)mgr + 8) != 0
	       && (int)(GetCurrentTimestamp() >> 16) - start < 0x27) {
		DispatchContext02200264();
	}
	*((unsigned char*)mgr + 8) = 0;
}
