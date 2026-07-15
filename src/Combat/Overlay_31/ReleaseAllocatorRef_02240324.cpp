#include <globaldefs.h>

struct RefNode020c80f8;
void ReleaseNodeRef020c80f8(struct RefNode020c80f8* node);
extern struct RefNode020c80f8 data_ov031_022918a4;

// USA: func_ov031_02240324
ARM void ReleaseAllocatorRef_02240324(void) {
	ReleaseNodeRef020c80f8(&data_ov031_022918a4);
}
