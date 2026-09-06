#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int CheckFlag0x1ClearAndFlag0x1000000Clear(unsigned char* obj);
struct S88514;
int CheckFlag0x2AndState2(struct S88514* obj);
extern "C" void func_ov024_021fd088(void* obj, float pct, int a2);
struct IndexedObj_021fe6b4;
void SetFieldFromIndexed_021fe6b4(struct IndexedObj_021fe6b4* obj, int val);

struct Field14Bits_021fd358 { unsigned int lo : 7; unsigned int val : 7; };
struct State64c_021fd358 { char pad[0x14]; struct Field14Bits_021fd358 bits; };

struct Obj_021fd358 {
	char pad0[0x64c];
	struct State64c_021fd358* state64c;
	char pad2[0x668 - 0x64c - 4];
	struct CombatantStruct* ptr668;
};

// USA: func_ov024_021fd358  (semantic: ApplyBuffScaledPercent2_021fd358)
extern "C" ARM void func_ov024_021fd358(struct Obj_021fd358* obj) {
	struct CombatantStruct* c = obj->ptr668;
	if (!CheckFlag0x1ClearAndFlag0x1000000Clear((unsigned char*)c->currentStats)) return;
	if (CheckFlag0x2AndState2((struct S88514*)c->currentStats)) return;
	float valF = (float)obj->state64c->bits.val;
	unsigned char pctBase = *(unsigned char*)((char*)c->currentStats + 0x4d);
	float scaled = valF * ((float)pctBase / 100.0f);
	if (scaled > 100.0f) scaled = 100.0f;
	SetFieldFromIndexed_021fe6b4((struct IndexedObj_021fe6b4*)obj, 1);
	func_ov024_021fd088(obj, scaled, 2);
}
