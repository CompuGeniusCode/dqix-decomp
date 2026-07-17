#include <globaldefs.h>
#include "std_library_functions.h"

struct Vec3_0215758c {
	int x, y, z;
};

struct RingBuf0215758c {
	struct Vec3_0215758c slots[16];
	struct Vec3_0215758c alt[16];
	int count;
};

// USA: func_ov001_0215758c
ARM int AppendVec3PairToRing_0215758c(struct RingBuf0215758c* buf, struct Vec3_0215758c v1, struct Vec3_0215758c v2) {
	if (buf->count >= 16) {
		return 1;
	}
	memcpy(&buf->slots[buf->count], &v1, 0xc);
	memcpy(&buf->alt[buf->count], &v2, 0xc);
	buf->count++;
	return 0;
}
