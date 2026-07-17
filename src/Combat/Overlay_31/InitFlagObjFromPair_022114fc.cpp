#include <globaldefs.h>
#include "System/Memory.h"

long long GetPair_02212d20(void);
void SetFlagBit0_02211754(struct FlagObj02211754* obj);
extern "C" void func_ov031_02211678(void* dst, int lo, int hi);

struct FlagObj02211754;

struct BigFlagObj022114fc {
	int field0;
	char pad4[0xc];
	char pad10[0xc];
	int field1c;
	char pad20[4];
	int field24;
	int field28;
	int field2c;
};

// USA: func_ov031_022114fc
ARM void InitFlagObjFromPair_022114fc(BigFlagObj022114fc* obj, int b) {
	VectorizedMemset(obj, 0, 0x40);
	obj->field0 = 0x40;
	long long pair = GetPair_02212d20();
	func_ov031_02211678((char*)obj + 4, (int)pair, (int)(pair >> 32));
	func_ov031_02211678((char*)obj + 0x10, 0, 0);
	obj->field1c = 0;
	obj->field24 = b;
	obj->field28 = 0x41435753;
	obj->field2c = 0x10000;
	SetFlagBit0_02211754((struct FlagObj02211754*)obj);
}
