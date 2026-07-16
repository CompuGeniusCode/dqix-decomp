#include <globaldefs.h>

extern "C" void func_02034d20(void*);
extern "C" void func_020371b8(void*, int);
extern "C" void func_ov006_021557c0(void*);
extern "C" void func_ov023_021dc488(void*);

// USA: func_ov006_02156b80
ARM void Something02156b80(void *obj) {
	char *o = (char*)obj;
	if (!(*(unsigned short*)(o + 0xa00 + 0xe2) & 8)) {
		func_02034d20(o + 0x238);
		func_02034d20(o + 0x2e4);
		func_02034d20(o + 0x390);
		func_020371b8(o + 0x3c + 0x400, *(int*)(o + 0x308));
	}
	func_ov006_021557c0(obj);
	func_ov023_021dc488(o + 0x2e4 + 0x800);
}
