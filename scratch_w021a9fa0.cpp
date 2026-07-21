#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_0218b5b0(void);
extern "C" void* func_02012fe4(void);
int GetFieldIfFlag4(char* obj);
void SetField0x23cTrue(void* obj);
int IsValueInRange0201b5d8(int x);
void InitContext020e1154(void* obj);

// USA: func_ov017_021a9fa0
ARM void SomeFunc_021a9fa0(char* self) {
	struct BattleStruct* battle = GetBattleStruct();
	func_ov017_0218b5b0();
	unsigned short* p = (unsigned short*)func_02012fe4();
	SetField0x23cTrue((void*)GetFieldIfFlag4((char*)battle));
	if (IsValueInRange0201b5d8(*p)) {
		InitContext020e1154((void*)0x3e8);
	}
	self[1] = 1;
}
