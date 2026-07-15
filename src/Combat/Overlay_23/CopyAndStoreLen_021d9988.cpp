#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj021d9988 {
	char pad[0x124];
	char buf[4];
	unsigned char lenByte;
};

// USA: func_ov023_021d9988
ARM void CopyAndStoreLen_021d9988(struct Obj021d9988 *obj, void *src, unsigned int len) {
	memcpy(obj->buf, src, len);
	obj->lenByte = (unsigned char)len;
}
