#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);

struct Src021ccaf8 {
	unsigned short arr[6];
	unsigned short id;
	unsigned char idx;
};

// USA: func_ov017_021ccaf8
ARM void CopyShortArrayIntoField150_021ccaf8(int unused0, char* p1raw, struct BattleStruct* bs) {
	struct Src021ccaf8* p1 = (struct Src021ccaf8*)(p1raw + 4);

	struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, p1->id);
	if (!c) return;

	int field150 = GetFieldAt0x150((unsigned char*)c);
	if (!field150) return;

	unsigned char idx = p1->idx;
	for (unsigned char i = 0; i < 6; i++) {
		unsigned short v = p1->arr[i];
		short* dst = (short*)((char*)field150 + (i + idx) * 2 + 0x100 + 0x6c);
		*dst = v;
	}
}
