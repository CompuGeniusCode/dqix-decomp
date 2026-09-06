#include <globaldefs.h>
#include "Filesystem/FileAccessor.h"

struct Obj0218f58c {
	char pad[0x8];
	int position;          // 0x8
	NitroVM* vm;           // 0xc
	unsigned char active;  // 0x10
};

// USA: func_ov016_0218f58c
#pragma optimize_for_size off
ARM int SeekAndReadSync_0218f58c(Obj0218f58c* o, void* buf, int size) {
	if (o->active == 1) {
		NitroVM_AwaitCommandCompletion(o->vm);
		NitroVM_Seek(o->vm, o->position, 0);
		o->active = 0;
	}
	if (NitroVM_ReadSync(o->vm, buf, size) == -1)
		return 0;
	o->position += size;
	return 1;
}
