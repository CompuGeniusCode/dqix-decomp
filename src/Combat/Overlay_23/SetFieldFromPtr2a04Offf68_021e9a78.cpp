#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_ov017_021d6134(void* obj, int v);

// USA: func_ov023_021e9a78
ARM int SetFieldFromPtr2a04Offf68_021e9a78(void* obj) {
	struct BattleStruct* bs = GetBattleStruct();
	void* p = GetPtrField0x2a04(bs);
	int v = *(int*)((char*)p + 0xf68);
	func_ov017_021d6134(obj, v);
	return 1;
}
