#include <globaldefs.h>

int GetSharedHalfwordOrBattleDefault(void);
int GetBattleSubField0xbcForState(void);
extern "C" int func_ov031_0223bdb0(int, int, int);

struct Target02223b60 {
	int field0;
	unsigned short field4;
};

struct Handle02223b60 {
	Target02223b60* field0;
	unsigned char pad4[4];
	signed char field8;
};

extern Handle02223b60* data_ov031_02250bf8;
extern char data_ov031_022489a4[];

// USA: func_ov031_02223b60
extern "C" ARM void func_ov031_02223b60(void) {
	volatile unsigned short* ime = (volatile unsigned short*)0x4000208;
	int base = 0;
	unsigned short saved = *ime;
	*ime = 0;
	if (GetSharedHalfwordOrBattleDefault() != 0x8000) {
		base = GetBattleSubField0xbcForState();
	}

	(void)*ime;
	*ime = saved;
	Handle02223b60* h = data_ov031_02250bf8;
	int idx = h->field8;
	Target02223b60* c = h->field0;
	unsigned char v = *(unsigned char*)((data_ov031_022489a4 + idx * 4) + base);
	func_ov031_0223bdb0(0, v, (int)c);

	h = data_ov031_02250bf8;
	c = h->field0;
	c->field0 = (c->field0 & 0xfe00ff00) | 0x26 | 0xe50000;
	h = data_ov031_02250bf8;
	c = h->field0;
	c->field4 = (c->field4 & ~0xc00) | 0x800;
}
