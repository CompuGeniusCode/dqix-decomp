#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void __clear(void* buf, int n);
extern unsigned char CopyOutRegion0x5718(char* obj, void* dst);
extern "C" void func_ov017_021d6134(void*, int);

struct Obj150_021ea46c { char pad[0x150]; char* ptr150; };

// USA: func_ov023_021ea46c
ARM int CountCombatantsByStatus1_021ea46c(void* obj) {
	struct BattleStruct* bs = GetBattleStruct();
	unsigned char buf[4];
	__clear(buf, 4);
	unsigned char len = CopyOutRegion0x5718((char*)bs, buf);
	int count = 0;
	for (int i = 0; i < len; i++) {
		unsigned char id = buf[i];
		struct Obj150_021ea46c* c = (struct Obj150_021ea46c*)GetCombatantWithFlag0x100(bs, id);
		if (c) {
			int val = *(int*)(c->ptr150 + 0x950);
			if ((unsigned int)val <= 9) {
				switch (val) {
					case 1:
					case 4:
					case 7:
					case 9:
						count++;
						break;
				}
			}
		}
	}
	func_ov017_021d6134(obj, count);
	return 1;
}
