#include <globaldefs.h>

struct BattleStruct;
struct BattleStruct* GetBattleStruct();
extern "C" void* func_ov017_0218b5b0(void);
void SetFlag2AndMaybeCall_0216d7ec(char* obj);

// USA: func_ov003_0217f194  (semantic: CallSetFlagIfFieldCSet_0217f194)
extern "C" ARM void func_ov003_0217f194(char* obj) {
	GetBattleStruct();
	func_ov017_0218b5b0();
	char* p = *(char**)(obj + 0xc);
	if (p != 0) SetFlag2AndMaybeCall_0216d7ec(p);
}
