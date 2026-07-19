#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/GrottoStruct.h"

struct SomeObj021cfd2c {
	unsigned char pad[4];
	unsigned char field4;
};

extern "C" void func_02012fe4(GrottoStruct* grotto);
void MaybeClearGrottoState0201bfd4(void);

// USA: func_ov017_021cfd2c
ARM void SetGrottoUnknown4_021cfd2c(int unused, SomeObj021cfd2c* obj) {
	GrottoStruct* grotto = GetGrottoStruct(GetBattleStruct());
	grotto->unknown_0[4] = (obj->field4 != 0) ? 1 : 0;
	func_02012fe4(grotto);
	MaybeClearGrottoState0201bfd4();
}
