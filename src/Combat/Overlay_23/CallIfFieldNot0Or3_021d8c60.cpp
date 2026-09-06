#include <globaldefs.h>

struct Obj021d8c60 { char pad[0x11a]; unsigned char field11a; };

extern "C" void _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(void* obj);
extern "C" void _Z28CallFunc0204c8f0OverList0x9cP12Cont0205d228(void* obj);
extern "C" void _Z28CallFunc0204b04cOverList0x98P12Cont0205d274(void* obj);

// USA: func_ov023_021d8c60
ARM void CallIfFieldNot0Or3_021d8c60(struct Obj021d8c60* obj) {
	unsigned char v = obj->field11a;
	if (v == 0 || v == 3) return;
	_Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0((char*)obj + 0x20);
	_Z28CallFunc0204c8f0OverList0x9cP12Cont0205d228((char*)obj + 0x20);
	_Z28CallFunc0204b04cOverList0x98P12Cont0205d274((char*)obj + 0x20);
}
