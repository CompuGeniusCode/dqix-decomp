#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Src_021d0d9c { unsigned char pad0[4]; int val; };

// USA: func_ov017_021d0d9c
ARM void StoreFieldIntoOffset2c94_021d0d9c(void* unused0, Src_021d0d9c* src, struct BattleStruct* battleStruct) {
	unsigned char* p = (unsigned char*)GetPtrField0x2a04(battleStruct);
	*(int*)(p + 0x2000 + 0xc94) = src->val;
}
