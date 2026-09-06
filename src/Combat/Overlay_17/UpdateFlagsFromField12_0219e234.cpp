#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetFieldIfFlag4(char* obj);
void SetFlagsAt0x244(unsigned char* obj, unsigned char mask);
void BlankFunction020a289c(void);
typedef void (*BlankFn020a289c)(void*, int);
void ClearFlagBits(unsigned char* obj, int mask);

struct Field12Bits0219e234 {
	unsigned char nibble : 4;
	unsigned char mid : 3;
	unsigned char high : 1;
};

// USA: func_ov017_0219e234
ARM void UpdateFlagsFromField12_0219e234(int a0, int a1, int a2, void* obj) {
	struct BattleStruct* battle = GetBattleStruct();
	int f = GetFieldIfFlag4((char*)battle);
	if (!f) return;
	struct Field12Bits0219e234* b = (struct Field12Bits0219e234*)((char*)obj + 0xc);
	if (b->nibble == 0 || b->high == 0) {
		SetFlagsAt0x244((unsigned char*)f, 0x10);
		((BlankFn020a289c)&BlankFunction020a289c)((void*)f, 2);
		return;
	}
	ClearFlagBits((unsigned char*)f, 0x10);
}
