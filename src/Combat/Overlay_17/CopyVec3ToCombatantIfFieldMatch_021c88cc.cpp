#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
void* GetField6b0_021b8470(void* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Ret021c88cc {
	unsigned char pad0[8];
	unsigned short field8;
};

struct Src021c88cc {
	unsigned char pad0[4];
	int vec[3];
	short field10;
	unsigned short field12;
};

// USA: func_ov017_021c88cc
ARM void CopyVec3ToCombatantIfFieldMatch_021c88cc(int unused0, Src021c88cc* src, struct BattleStruct* battleStruct, unsigned char* obj) {
	unsigned char* base = obj + 0x3000;
	void* h = *(void**)(base + 0x718);
	Ret021c88cc* r = (Ret021c88cc*)func_ov017_021b8478(h);
	if (!r) return;
	if (!func_ov017_021b8468(h)) return;
	if (!GetField6b0_021b8470(h)) return;
	if (r->field8 != src->field12) return;
	struct CombatantStruct* c = GetCombatantFromList(battleStruct, src->field10);
	if (!c) return;
	int* dst = *(int**)((unsigned char*)c + 0x13c);
	if (!dst) return;
	_ZN8Vector3iaSERKS_((int*)((unsigned char*)dst + 0x10), src->vec);
}
