#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int AppendFormatted02041f70(char* buf, int a, int b);
int AppendXTag(char* dst, int x);
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int GetCombatSignedByteAt0x2c8d02039730(void* unused, int index);
struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
int AppendDotLeaderLabel02042084(char* buffer, char* label, int width, int extra);

struct Table_0219a544 { int values[5]; };
extern struct Table_0219a544 data_ov017_021d6470;
extern int data_ov017_021d6460[4];

// USA: func_ov017_0219a544
ARM void AppendFieldTagWithLookup_0219a544(unsigned char* a, char* buf, int type, int value) {
	if (!buf) return;
	if (type == 3 && value > 0) {
		AppendFormatted02041f70(buf, 3, 2);
	}
	int resultByte = value;
	if (type == 3 && value <= 0) {
		struct Table_0219a544 local = data_ov017_021d6470;
		struct CombatantStruct* combatant;
		int idx = 0;
		struct BattleStruct* battle = GetBattleStruct();
		combatant = GetCombatantAtField0x3ac(battle);
		while (((volatile int*)local.values)[idx] != 7) {
			resultByte = (signed char)GetCombatSignedByteAt0x2c8d02039730(combatant, ((volatile int*)local.values)[idx]);
			if (resultByte > 0) break;
			idx = (idx + 1) & 0xff;
		}
	}
	int key = (resultByte < 0) ? 0 : resultByte;
	struct Container020e0310* container = *(struct Container020e0310**)(a + 0x4084);
	int fieldResult = GetFieldByKey020e0434(container, key);
	if (!fieldResult) return;
	AppendXTag(buf, 0);
	int width = data_ov017_021d6460[type];
	AppendDotLeaderLabel02042084(buf, (char*)fieldResult, width, 0);
}
