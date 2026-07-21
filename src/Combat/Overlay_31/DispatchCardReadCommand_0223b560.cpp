#include <globaldefs.h>

struct Inner_0223b560 { unsigned char pad[0xe4]; unsigned short handle; };
struct Outer_0223b560 { struct Inner_0223b560* p; };
extern struct Outer_0223b560 data_ov031_02290d24;

void NitroVM_Command_AcquireCardReadResources(unsigned short);
void NitroVM_Command_ReleaseCardReadResources(unsigned short);

// USA: func_ov031_0223b560  (semantic: DispatchCardReadCommand_0223b560)
extern "C" ARM int func_ov031_0223b560(void* unused, int tag) {
	switch (tag) {
	case 9:
		NitroVM_Command_AcquireCardReadResources(data_ov031_02290d24.p->handle);
		return 0;
	case 0xa:
		NitroVM_Command_ReleaseCardReadResources(data_ov031_02290d24.p->handle);
		return 0;
	case 1:
		return 4;
	default:
		return 8;
	}
}
