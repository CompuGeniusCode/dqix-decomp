#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov023_021e8f28(int);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ea71c
ARM int CheckFlag2Set_021ea71c(void *obj) {
	GetBattleStruct();
	void *p = (void*)func_ov023_021e8f28(func_ov017_021d60f4(obj));
	if (!p) return 0;
	void *q = *(void**)((char*)p + 0x130);
	int flag = 0;
	if (*(int*)q & 0x2) flag = 1;
	if (flag) {
		func_ov017_021d6134((char*)obj + 8, 1);
	} else {
		func_ov017_021d6134((char*)obj + 8, 0);
	}
	return 1;
}
