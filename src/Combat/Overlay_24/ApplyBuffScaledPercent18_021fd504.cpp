#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_ov024_021fd088(void* obj, float pct, int a2);
extern "C" void func_ov024_021fd104(void* obj, int mode);
struct IndexedObj_021fe6b4;
void SetFieldFromIndexed_021fe6b4(struct IndexedObj_021fe6b4* obj, int val);

struct Field14Bits_021fd504 { unsigned int lo : 7; unsigned int val : 7; };
struct State64c_021fd504 { char pad[0x14]; struct Field14Bits_021fd504 bits; char pad2[0x1a]; short field32; };

struct Obj_021fd504 {
	char pad0[0x64c];
	struct State64c_021fd504* state64c;
	char pad2[0x661 - 0x64c - 4];
	unsigned char flag661;
	char pad3[0x668 - 0x661 - 1];
	struct CombatantStruct* ptr668;
};

// USA: func_ov024_021fd504  (semantic: ApplyBuffScaledPercent18_021fd504)
extern "C" ARM void func_ov024_021fd504(struct Obj_021fd504* obj) {
	struct ModifiableCombatStats* stats = obj->ptr668->currentStats;
	if (stats->defenseBuff <= -2) return;
	unsigned char pctBase = *(unsigned char*)((char*)stats + 0x50);
	if (pctBase == 0) return;
	if (obj->flag661) {
		struct State64c_021fd504* state = obj->state64c;
		float valF = (float)state->bits.val;
		float scaled = valF * ((float)pctBase / 100.0f);
		if (scaled > 100.0f) scaled = 100.0f;
		if (state->field32 >= 0) return;
		SetFieldFromIndexed_021fe6b4((struct IndexedObj_021fe6b4*)obj, 0xd);
		func_ov024_021fd088(obj, scaled, 0x12);
	} else {
		func_ov024_021fd104(obj, 0x12);
	}
}
