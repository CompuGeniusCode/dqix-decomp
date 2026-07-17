#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void* func_020c8074(void *node);

struct RefNode020c80f8;
void ReleaseNodeRef020c80f8(struct RefNode020c80f8 *node);

// USA: func_ov031_02217e70
ARM void RefreshRefIfFlagged_02217e70(char *self) {
	if (*(unsigned char*)(self + 0x1000) != 0xff) return;
	func_020c8074(self + 0x3f8 + 0x1800);
	*(int*)(self + 0x1000 + 0xc10) = 1;
	ReleaseNodeRef020c80f8((struct RefNode020c80f8*)(self + 0x3f8 + 0x1800));
	if (*(int*)(self + 0x1000 + 0xba4) == 0) return;
	AwaitContextCompletion((ProcessorContext*)(self + 0x1800 + 0x338));
}
