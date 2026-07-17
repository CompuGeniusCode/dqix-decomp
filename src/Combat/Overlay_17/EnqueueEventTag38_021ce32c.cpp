#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);
int GetSignedByte0x2d0(void* obj);
int GetSignedByte0x2d1(void* obj);
int GetSignedByte0x1c8(void* obj);
int GetSignedByte0x1c9(void* obj);
struct CombatantStruct* GetCombatantWithFlag0x1000(struct BattleStruct* battleStruct, int combatantId);

struct LocalEvt021ce32c {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned short field4;
	unsigned char field6;
	unsigned char field7;
	unsigned char field8;
	unsigned char field9;
	unsigned char fielda;
	unsigned char pad1[9];
};

// USA: func_ov017_021ce32c
ARM void EnqueueEventTag38_021ce32c(int id) {
	void* p = GetData02100044();
	struct CombatantStruct* c = GetCombatantWithFlag0x1000(GetBattleStruct(), id);
	if (c == NULL) {
		return;
	}
	LocalEvt021ce32c buf;
	buf.tag = 0x26;
	buf.field4 = id;
	buf.field6 = GetSignedByte0x2d0(c);
	buf.field7 = GetSignedByte0x2d1(c);
	buf.field8 = GetSignedByte0x1c8(c);
	buf.field9 = GetSignedByte0x1c9(c);
	buf.fielda = *(unsigned char*)((char*)c + 0x2d2);
	func_0205e330(p, &buf, 0);
}
