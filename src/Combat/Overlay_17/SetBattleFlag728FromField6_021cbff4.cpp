#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov017_021b8478(void* obj);

struct Ret021cbff4 {
	unsigned char pad0[8];
	unsigned short field8;
};

struct Src021cbff4 {
	unsigned char pad0[4];
	unsigned short field4;
	unsigned char field6;
};

// USA: func_ov017_021cbff4
ARM void SetBattleFlag728FromField6_021cbff4(int unused0, Src021cbff4* src, int unused2, unsigned char* obj) {
	unsigned char* h = *(unsigned char**)(obj + 0x3000 + 0x718);
	if (!h || h[3] == 0) return;
	Ret021cbff4* r = (Ret021cbff4*)func_ov017_021b8478(h);
	if (!r) return;
	if (r->field8 != src->field4) return;
	unsigned char* bs = (unsigned char*)GetBattleStruct();
	bs[0x5728] = src->field6 != 0 ? 1 : 0;
}
