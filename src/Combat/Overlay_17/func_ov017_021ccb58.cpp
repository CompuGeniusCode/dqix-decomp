#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* buf, int c);

struct Dst021ccb58 {
	unsigned char marker;
	char pad1[3];
	unsigned int words[3];
	unsigned short field10;
	unsigned char field12;
};

// USA: func_ov017_021ccb58
extern "C" ARM void func_ov017_021ccb58(int id, int idx) {
	struct BattleStruct* battle = GetBattleStruct();
	struct CombatantStruct* c = GetCombatantWithFlag0x100(battle, id);
	if (!c) return;
	unsigned char* base = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
	if (!base) return;

	void* d = GetData02100044();
	Dst021ccb58 buf;
	buf.marker = 0xd;
	buf.field10 = (unsigned short)id;
	buf.field12 = (unsigned char)idx;
	unsigned char i = 0;
	while (i < 3) {
		unsigned int v = *(unsigned int*)(base + (i + idx) * 4 + 0x138);
		buf.words[i] = v;
		i++;
	}
	func_0205e330(d, &buf, 0);
}
