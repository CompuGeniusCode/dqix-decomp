#include <globaldefs.h>

struct Vec3_0215758c {
	int x, y, z;
};

struct Self02158348 {
	int f0;
	struct Vec3_0215758c v1;
	struct Vec3_0215758c v2;
};

struct RingBuf0215758c;
int AppendVec3PairToRing_0215758c(struct RingBuf0215758c* buf, struct Vec3_0215758c v1, struct Vec3_0215758c v2);

// USA: func_ov001_02158348
ARM int ForwardVecsToRingAt15c_02158348(struct Self02158348* self, char* dest) {
	AppendVec3PairToRing_0215758c((struct RingBuf0215758c*)(dest + 0x15c), self->v1, self->v2);
	return 0;
}
