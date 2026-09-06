#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField5cbcValue(char* obj);
extern "C" void func_ov017_021d6134(void* obj, int v);

// USA: func_ov023_021e934c
ARM int SetFieldFromBattleStruct5cbc_021e934c(void* obj) {
	struct BattleStruct* bs = GetBattleStruct();
	int v = GetField5cbcValue((char*)bs);
	func_ov017_021d6134(obj, v);
	return 1;
}
