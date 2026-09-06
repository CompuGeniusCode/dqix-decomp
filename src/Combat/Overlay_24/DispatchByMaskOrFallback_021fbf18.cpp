#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" int func_ov024_021fe698(void* obj, int arg);
extern "C" void func_ov024_021fdf04(void* obj, int idx);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int zero, int val);

struct Sub_021fbf18 {
	char pad[4];
	unsigned int code : 12;
	unsigned int rest : 20;
};

struct Obj_021fbf18 {
	char pad0[6];
	unsigned char field6;
	char pad1[1];
	struct CombatantStruct* field8;
	int fieldC;
	char pad2[0x64c - 0x10];
	struct Sub_021fbf18* field64c;
};

// USA: func_ov024_021fbf18  (semantic: DispatchByMaskOrFallback_021fbf18)
extern "C" ARM void func_ov024_021fbf18(struct Obj_021fbf18* obj) {
	unsigned int code = obj->field64c->code;
	if (code == 0x1fc || code == 0x20f) {
		int flag = 0;
		if (obj->field6 == 2) flag = 1;
		if (obj->field6 == 0) return;
		if (obj->fieldC >= 3) flag = 1;
		if (!flag) return;
		if (!func_ov024_021fe698(obj, 0x12)) return;
		if (((unsigned char*)obj->field8->currentStats)[0x24] >= 3) return;
		char buf[0xc8];
		memset(buf, 0, 0xc8);
		*(float*)(buf + 0xc4) = 1000.0f;
		func_ov024_021f9874(obj, buf, 0, 0);
	} else {
		if (func_ov024_021fe698(obj, 1)) {
			func_ov024_021fdf04(obj, 8);
		}
	}
}
