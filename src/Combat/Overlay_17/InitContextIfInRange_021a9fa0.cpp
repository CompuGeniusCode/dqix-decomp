#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" ARM int func_ov017_0218b5b0(void);
extern "C" ARM unsigned short* func_02012fe4(void);
ARM int GetFieldIfFlag4(char* obj);
ARM void SetField0x23cTrue(void* obj);
ARM int IsValueInRange0201b5d8(int x);
ARM void InitContext020e1154(void* obj);

// USA: func_ov017_021a9fa0  (semantic: InitContextIfInRange_021a9fa0)
extern "C" ARM void func_ov017_021a9fa0(void* obj) {
	struct BattleStruct* battle = GetBattleStruct();
	func_ov017_0218b5b0();
	unsigned short* w = func_02012fe4();
	SetField0x23cTrue((void*)GetFieldIfFlag4((char*)battle));
	if (IsValueInRange0201b5d8(*w))
		InitContext020e1154((void*)0x3e8);
	((unsigned char*)obj)[1] = 1;
}
