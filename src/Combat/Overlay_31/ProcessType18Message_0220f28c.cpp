#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct GuardStruct0220f28c { char pad[0x24]; int field24; };
extern struct GuardStruct0220f28c data_ov031_0224e540;
extern struct BlockedContextList data_ov031_0224e544;
extern "C" void func_ov031_0220dab4(void);

struct MsgHeader0220f28c { unsigned short type; unsigned short value; };

// USA: func_ov031_0220f28c  (semantic: ProcessType18Message_0220f28c)
extern "C" ARM void func_ov031_0220f28c(struct MsgHeader0220f28c* msg) {
	if (msg->type != 0x12) return;
	data_ov031_0224e540.field24 = msg->value;
	if (msg->value == 0) {
		func_ov031_0220dab4();
	}
	UnblockContexts(&data_ov031_0224e544);
}
