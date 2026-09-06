#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField0x3b0Value(struct BattleStruct* battleStruct);
int GetFlags(int obj);
void UpdateEntry0216d50c(void* work);
extern "C" void func_0202e0a4(int val);

// USA: func_ov017_021959ec
ARM void MaybeUpdateOrDispatchEntry_021959ec(void) {
	struct BattleStruct* bs = GetBattleStruct();
	int val = GetField0x3b0Value(bs);
	if (val == 0) return;
	if (GetFlags(val) & 8) {
		UpdateEntry0216d50c((void*)val);
	} else {
		func_0202e0a4(val);
	}
}
