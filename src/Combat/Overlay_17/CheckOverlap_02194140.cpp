#include <globaldefs.h>

struct IntField0x68_020377bc {
	char unk[0x68];
	int field;
};
int GetIntAt0x68(struct IntField0x68_020377bc* obj);
int GetIntAt0x64(unsigned char* obj);

int AbsInt(int x);

struct Vec3s32_020c3030 { int x; int y; int z; };
int Distance3D020c3030(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

// USA: func_ov017_02194140  (semantic: CheckOverlap_02194140)
extern "C" ARM int func_ov017_02194140(unsigned char* self, unsigned char* other) {
	int extSelf = GetIntAt0x68((struct IntField0x68_020377bc*)self);
	int extOther = GetIntAt0x68((struct IntField0x68_020377bc*)other);

	if (!(*(int*)(self + 0x48) + extSelf >= *(int*)(other + 0x48) &&
	      *(int*)(other + 0x48) + extOther >= *(int*)(self + 0x48))) return 0;

	int half = (GetIntAt0x64(self) >> 1) + (GetIntAt0x64(other) >> 1);

	if (half < AbsInt(*(int*)(self + 0x44) - *(int*)(other + 0x44)) ||
	    half < AbsInt(*(int*)(self + 0x4c) - *(int*)(other + 0x4c))) return 0;

	int d = Distance3D020c3030((struct Vec3s32_020c3030*)(self + 0x44), (struct Vec3s32_020c3030*)(other + 0x44));
	return half >= d;
}
