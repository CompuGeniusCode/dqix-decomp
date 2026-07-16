#include <globaldefs.h>
#include "Filesystem/FileAccessor.h"

struct Obj0218f5fc {
	char pad[0x8];
	int position;          // 0x8
	NitroVM* vm;           // 0xc
	unsigned char active;  // 0x10
};

// USA: func_ov016_0218f5fc
ARM int ReadAlignedAsync_0218f5fc(Obj0218f5fc* o, void* buf, int size) {
	int base = o->position & ~0x1FF;
	int rem = o->position - base;
	int total = size + rem;
	if (total & 0x1FF)
		total = (total & ~0x1FF) + 0x200;
	NitroVM_Seek(o->vm, base, 0);
	if (NitroVM_ReadAsync(o->vm, buf, total) == -1)
		return 0;
	o->position += size;
	o->active = 1;
	return rem;
}
