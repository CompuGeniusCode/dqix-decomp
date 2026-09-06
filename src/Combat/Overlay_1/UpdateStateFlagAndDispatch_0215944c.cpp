#include <globaldefs.h>

extern "C" void func_ov001_021579ac(void* a);
extern "C" void func_ov001_02157ae0(void* a, void* b, void* c);

struct Struct02157acc {
	unsigned char pad0[0xc4];
	int field0xc4;
	unsigned char pad1[0x464 - 0xc8];
	int field0x464;
};
void SetFlagIfFieldPositive02157acc(struct Struct02157acc* s);

struct Obj0215944c {
	unsigned char pad0[0x48];
	int f48;
	unsigned char pad1[0x74 - 0x4c];
	int f74;
	unsigned char pad2[0x84 - 0x78];
	int f84;
	unsigned char pad3[0x11c - 0x88];
	unsigned char at11c[1];
	unsigned char pad4[0x580 - 0x11d];
	int f580;
};

// USA: func_ov001_0215944c
ARM int UpdateStateFlagAndDispatch_0215944c(void* unused, struct Obj0215944c* obj) {
	if (obj->f48 <= 0) {
		func_ov001_021579ac(&obj->at11c);
		SetFlagIfFieldPositive02157acc((struct Struct02157acc*)&obj->at11c);
		obj->f48 = 1;
	}
	func_ov001_02157ae0(&obj->at11c, &obj->f74, &obj->f84);
	int x = (obj->f580 == 0) ? 1 : 0;
	if (x) {
		x = 0;
		obj->f48 = x;
	} else {
		x = 1;
	}
	return x;
}
