#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Struct_021fa76c;
int CheckAllFlagsClear_021fa76c(struct Struct_021fa76c* combatant);
int CheckField0x14Flags0x9Clear(unsigned char* obj);
int CheckFlag0x14Bit0x10Set(unsigned char* obj);
extern "C" void func_ov024_021fd088(void* obj, float pct, int a2);
struct IndexedObj_021fe6b4;
void SetFieldFromIndexed_021fe6b4(struct IndexedObj_021fe6b4* obj, int val);

struct Field14Bits_021fd45c { unsigned int lo : 7; unsigned int val : 7; };
struct State64c_021fd45c { char pad[0x14]; struct Field14Bits_021fd45c bits; };

struct Obj_021fd45c {
	char pad0[0x64c];
	struct State64c_021fd45c* state64c;
	char pad2[0x668 - 0x64c - 4];
	struct CombatantStruct* ptr668;
};

// USA: func_ov024_021fd45c  (semantic: ApplyBuffScaledPercent4_021fd45c)
extern "C" ARM void func_ov024_021fd45c(struct Obj_021fd45c* obj) {
	struct CombatantStruct* c = obj->ptr668;
	if (!CheckAllFlagsClear_021fa76c((struct Struct_021fa76c*)c)) return;
	if (!CheckField0x14Flags0x9Clear((unsigned char*)c->currentStats)) return;
	if (CheckFlag0x14Bit0x10Set((unsigned char*)c->currentStats)) return;
	float valF = (float)obj->state64c->bits.val;
	unsigned char pctBase = *(unsigned char*)((char*)c->currentStats + 0x47);
	float scaled = valF * ((float)pctBase / 100.0f);
	if (scaled > 100.0f) scaled = 100.0f;
	SetFieldFromIndexed_021fe6b4((struct IndexedObj_021fe6b4*)obj, 1);
	func_ov024_021fd088(obj, scaled, 4);
}
