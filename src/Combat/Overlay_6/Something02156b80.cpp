#include <globaldefs.h>

extern "C" void _ZN8Object3D14AdvanceEffectsEv(void*);
extern "C" void _ZN8Object3D26SetNormalizedAnimationTimeEi(void*, int);
extern "C" void func_ov006_021557c0(void*);
extern "C" void func_ov023_021dc488(void*);

// USA: func_ov006_02156b80
ARM void Something02156b80(void *obj) {
	char *o = (char*)obj;
	if (!(*(unsigned short*)(o + 0xa00 + 0xe2) & 8)) {
		_ZN8Object3D14AdvanceEffectsEv(o + 0x238);
		_ZN8Object3D14AdvanceEffectsEv(o + 0x2e4);
		_ZN8Object3D14AdvanceEffectsEv(o + 0x390);
		_ZN8Object3D26SetNormalizedAnimationTimeEi(o + 0x3c + 0x400, *(int*)(o + 0x308));
	}
	func_ov006_021557c0(obj);
	func_ov023_021dc488(o + 0x2e4 + 0x800);
}
