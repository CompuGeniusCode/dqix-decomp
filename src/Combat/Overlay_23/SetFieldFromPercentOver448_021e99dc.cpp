#include <globaldefs.h>

int LoadBattleBlock020ac4c0(void* dst);

struct S_a090c {
	char pad[0x10];
	unsigned int lo : 23;
	unsigned int val : 9;
};
int GetFieldPercentOver448(struct S_a090c* p);

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e99dc
ARM int SetFieldFromPercentOver448_021e99dc(void* obj) {
	unsigned char buf[0xb0];
	LoadBattleBlock020ac4c0(buf);
	int pct = GetFieldPercentOver448((struct S_a090c*)buf);
	func_ov017_021d6134(obj, pct);
	return 1;
}
