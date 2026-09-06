#include <globaldefs.h>
#include "Filesystem/FileAccessor.h"

struct Obj0218f540 {
	char pad[0x8];
	int position;          // 0x8
	NitroVM* vm;           // 0xc
	unsigned char active;  // 0x10
};

// USA: func_ov016_0218f540
ARM int SeekIfInactive_0218f540(Obj0218f540* o, int pos) {
	if (o->active == 1) {
		NitroVM_AwaitCommandCompletion(o->vm);
		o->active = 0;
	}
	if (!NitroVM_Seek(o->vm, pos, 0))
		return 0;
	o->position = pos;
	return 1;
}
