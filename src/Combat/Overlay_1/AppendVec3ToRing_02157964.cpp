#include <globaldefs.h>
#include "std_library_functions.h"

struct Vec3_02157964 {
	int x, y, z;
};

struct RingBuf02157964 {
	struct Vec3_02157964 slots[16];
	int pad0xc0;
	int count;
};

// USA: func_ov001_02157964  (semantic: AppendVec3ToRing_02157964)
extern "C" ARM int func_ov001_02157964(struct RingBuf02157964* buf, struct Vec3_02157964 v) {
	if (buf->count >= 16) {
		return 1;
	}
	memcpy(&buf->slots[buf->count], &v, 0xc);
	buf->count++;
	return 0;
}
