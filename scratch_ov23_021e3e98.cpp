#include <globaldefs.h>

extern "C" int func_ov023_021e29d0(void* p);
extern "C" int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern unsigned short data_02114e30;

struct Obj_021e3e98 {
	void* ptr0;
	char pad1[0xd0];
	char pad2[0x410];
	unsigned char f4e4;
	unsigned char pad5;
	signed char f4e6;
	signed char f4e7;
	char pad3[0x14c];
	unsigned short f634;
};

// USA: func_ov023_021e3e98
ARM void CheckStateAndClearFields_021e3e98(struct Obj_021e3e98* obj) {
	int active = (func_ov023_021e29d0((char*)obj + 0xd4) == 0x1f);
	if (active) obj->f634 |= 0x800;
	if (obj->ptr0) {
		if ((*(int*)((char*)obj->ptr0 + 0x3dcc) & 0x400) == 0) return;
	}
	if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) active = 1;
	if (!active) return;
	obj->f634 |= 0x800;
	obj->f4e7 = obj->f4e6;
	obj->f4e6 = 1;
	obj->f4e4 = 0;
}
