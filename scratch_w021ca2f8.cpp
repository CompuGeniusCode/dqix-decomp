#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetData02100044(void);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Ret021ca2f8 {
	unsigned char pad0[8];
	unsigned short field8;
};

struct Mid021ca2f8 {
	unsigned short field4;
	unsigned char field6;
};

struct LocalEvt021ca2f8 {
	unsigned char tag;
	unsigned char pad0[3];
	Mid021ca2f8 mid;
	unsigned char pad1[12];
};

// USA: func_ov017_021ca2f8
ARM void EnqueueEventTag91_021ca2f8(int id) {
	void* p = GetData02100044();
	GetBattleStruct();
	void* h = *(void**)((char*)(long)func_ov017_0218b5b0() + 0x3000 + 0x718);
	Ret021ca2f8* r = (Ret021ca2f8*)func_ov017_021b8478(h);
	if (r == NULL) return;
	LocalEvt021ca2f8 buf;
	buf.tag = 0x5b;
	Mid021ca2f8* m = &buf.mid;
	m->field4 = r->field8;
	m->field6 = (unsigned char)id;
	func_0205e330(p, &buf, 0);
}
