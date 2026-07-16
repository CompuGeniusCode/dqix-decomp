#include <globaldefs.h>
#include "Filesystem/FileAccessor.h"

struct Obj0218f678 {
	char pad[0xc];
	NitroVM* vm;         // 0xc
	unsigned char active; // 0x10
};

// USA: func_ov016_0218f678
ARM void AwaitIfActive_0218f678(Obj0218f678* o) {
	if (o->active == 1) {
		NitroVM_AwaitCommandCompletion(o->vm);
	}
	o->active = 0;
}
