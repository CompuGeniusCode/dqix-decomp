#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct LocalEvt021cee78 {
	unsigned char tag;
	unsigned char pad0[3];
	int vec[3];
	unsigned short field10;
	unsigned char field12;
	unsigned char field13;
};

// USA: func_ov017_021cee78
ARM void EnqueueEventTag20_021cee78(int id, unsigned char b) {
	struct CombatantStruct* c = GetCombatantUnchecked(GetBattleStruct(), id);
	if (c == NULL) {
		return;
	}
	void* p = GetData02100044();
	LocalEvt021cee78 buf;
	buf.tag = 0x14;
	buf.field12 = id;
	_ZN8Vector3iaSERKS_(buf.vec, (int*)((char*)c + 0x44));
	buf.field10 = *(int*)((char*)c + 0x54);
	buf.field13 = b;
	func_0205e330(p, &buf, 0);
}
