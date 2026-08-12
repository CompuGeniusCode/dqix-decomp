#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov024_021fe698(void* obj, int idx);
struct S_flag1024;
int IsFlagBit1024Set_021fcac0(struct S_flag1024* obj);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int zero, int val);

struct Obj_021fcd7c {
	char pad0[4];
	short field4;
	unsigned char kind;
	char pad7;
	struct S_flag1024* combatant;
	int field0xc;
};

// USA: func_ov024_021fcd7c  (semantic: CheckKindAndApplyStatus18_021fcd7c)
extern "C" ARM void func_ov024_021fcd7c(struct Obj_021fcd7c* obj) {
	int trigger = 0;
	if (obj->kind == 2) trigger = 1;
	if (obj->kind == 0) return;
	if (obj->field0xc >= 3) trigger = 1;
	if (!trigger) return;
	if (!func_ov024_021fe698(obj, 0x12)) return;
	if (IsFlagBit1024Set_021fcac0(obj->combatant)) return;
	char buf[0xc8];
	memset(buf, 0, 0xc8);
	*(float*)(buf + 0xc4) = 1000.0f;
	func_ov024_021f9874(obj, buf, 0, (unsigned char)obj->field4);
}
