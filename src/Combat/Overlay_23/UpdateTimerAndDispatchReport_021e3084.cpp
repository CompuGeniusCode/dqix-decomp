#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Obj021e3084 {
	char pad0[0x128];
	void* field128;
	char pad1[0x134 - 0x12c];
	int field134;
	char pad2[0x634 - 0x138];
	unsigned short field634;
};

extern "C" int func_ov017_0218b5b0(void);
extern "C" int func_ov017_021bdbe4(void* base);
extern "C" int func_ov017_021bdbd8(void* base);
extern "C" void func_ov023_021e5628(void* a, int* b);

// USA: func_ov023_021e3084  (semantic: UpdateTimerAndDispatchReport_021e3084)
extern "C" ARM void func_ov023_021e3084(struct Obj021e3084* obj) {
	GetBattleStruct();
	if (obj->field134 > 0) {
		obj->field134--;
		if (obj->field134 == 0) {
			obj->field634 |= 0x8;
		}
	}
	if (obj->field634 & 0x20) {
		int base = func_ov017_0218b5b0();
		int arr[2];
		if (base == 0) {
			arr[1] = 0;
			arr[0] = 0;
		} else {
			arr[1] = func_ov017_021bdbe4((void*)base);
			arr[0] = func_ov017_021bdbd8((void*)base);
		}
		if (obj->field128 != 0) {
			*(int*)0x4000444 = 0;
			func_ov023_021e5628(obj->field128, arr);
			*(int*)0x4000448 = 1;
		}
	}
}
