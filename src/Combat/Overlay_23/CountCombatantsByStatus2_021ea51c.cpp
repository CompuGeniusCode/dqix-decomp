#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void __clear(void* buf, int n);
extern unsigned char CopyOutRegion0x5718(char* obj, void* dst);
extern "C" void func_ov017_021d6134(void*, int);

struct Obj150_021ea51c { char pad[0x150]; char* ptr150; };

// USA: func_ov023_021ea51c
ARM int CountCombatantsByStatus2_021ea51c(void* obj) {
	struct BattleStruct* bs = GetBattleStruct();
	unsigned char buf[4];
	__clear(buf, 4);
	unsigned char len = CopyOutRegion0x5718((char*)bs, buf);
	int count = 0;
	for (int i = 0; i < len; i++) {
		unsigned char id = buf[i];
		struct Obj150_021ea51c* c = (struct Obj150_021ea51c*)GetCombatantWithFlag0x100(bs, id);
		if (c) {
			int val = *(int*)(c->ptr150 + 0x950);
			if (val == 2 || val == 3 || val == 0xa) count++;
		}
	}
	func_ov017_021d6134(obj, count);
	return 1;
}
