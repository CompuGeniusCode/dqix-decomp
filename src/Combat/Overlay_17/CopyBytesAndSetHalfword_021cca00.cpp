#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetFieldAt0x150(unsigned char* obj);

struct Src021cca00 {
	unsigned short field0;
	unsigned short field2;
	unsigned char bytes[12];
};

// USA: func_ov017_021cca00
ARM void CopyBytesAndSetHalfword_021cca00(int unused0, unsigned char* src, struct BattleStruct* battleStruct, int unused3) {
	Src021cca00* s = (Src021cca00*)(src + 4);
	struct CombatantStruct* c = GetCombatantWithFlag0x100(battleStruct, *(unsigned short*)(src + 4));
	if (!c) return;
	unsigned char* work = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
	if (!work) return;
	*(unsigned short*)(work + 0x900 + 0x54) = s->field2;
	int i = 0;
	while (i < 12) {
		unsigned char v = s->bytes[i];
		i++;
		unsigned char* dst = work + i;
		dst[0x186] = v;
	}
}
