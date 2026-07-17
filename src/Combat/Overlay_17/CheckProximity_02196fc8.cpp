#include <globaldefs.h>

int GetIntAt0x64(unsigned char* obj);

struct Vec3i_02196fc8 { int x; int y; int z; };
Vec3i_02196fc8 GetVec3FromShortsAt0x5c(unsigned char* src);

struct Outer02077a20;
int GetField0x8OrDefault02077a20(struct Outer02077a20* p);

int AbsInt(int x);

struct Vec3s32_020c3030;
int Distance3D020c3030(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

// USA: func_ov017_02196fc8
ARM int CheckProximity_02196fc8(unsigned char* self, unsigned char* other, int extra) {
	int a = GetIntAt0x64(self);
	int half;

	if (*(unsigned short*)other & 0x20) {
		int vx15 = GetVec3FromShortsAt0x5c(other).x * 15;
		int halfScale = GetField0x8OrDefault02077a20((struct Outer02077a20*)other) >> 1;
		half = (int)(((long long)halfScale * vx15 + 0x800) >> 12);
	} else {
		half = GetIntAt0x64(other) >> 1;
	}

	int dist = extra + (half + (a >> 1));

	if (dist < AbsInt(*(int*)(self + 0x44) - *(int*)(other + 0x44))) return 0;
	if (dist < AbsInt(*(int*)(self + 0x4c) - *(int*)(other + 0x4c))) return 0;

	int d = Distance3D020c3030((struct Vec3s32_020c3030*)(self + 0x44), (struct Vec3s32_020c3030*)(other + 0x44));
	if (dist < d) return 0;

	return d != 0;
}
