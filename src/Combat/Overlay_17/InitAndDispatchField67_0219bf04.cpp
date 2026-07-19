#include <globaldefs.h>
#include "Grotto/Overlay_17/Struct44C8.h"

struct BattleStruct;

struct BattleStruct* GetBattleStruct();
void* GetField0x3f8Address(struct BattleStruct* battleStruct);
void InitFieldsFromCombatant_0219bcac(unsigned char flag);
int* GetGlobal02109030(void);
extern "C" void func_02094030(int*, short, short, signed char);

// USA: func_ov017_0219bf04  (semantic: InitAndDispatchField67_0219bf04)
extern "C" ARM void func_ov017_0219bf04(unsigned char flag, int mode) {
	struct BattleStruct* battleStruct = GetBattleStruct();
	Struct_ov017_44C8* ov = func_ov017_0218b5b0();
	InitFieldsFromCombatant_0219bcac(flag);
	char* obj = (char*)GetField0x3f8Address(battleStruct);
	obj[0x6e] = 1;
	obj[0xa] = 0;
	obj[0x67] = 1;
	if (mode == 0) {
		*(short*)((char*)ov + 0x4400 + 0xb2) = 0x4e23;
		return;
	}
	int* g = GetGlobal02109030();
	func_02094030(g, 0x4e23, -1, 0);
}
