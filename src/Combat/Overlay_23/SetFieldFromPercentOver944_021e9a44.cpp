#include <globaldefs.h>

int LoadBattleBlock020ac4c0(void* dst);

struct S_a08d8 {
	char pad[0x14];
	unsigned int a : 9;
	unsigned int b : 9;
	unsigned int val : 11;
	unsigned int hi : 3;
};
int GetFieldPercentOver944(struct S_a08d8* p);

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9a44
ARM int SetFieldFromPercentOver944_021e9a44(void* obj) {
	unsigned char buf[0xb0];
	LoadBattleBlock020ac4c0(buf);
	int pct = GetFieldPercentOver944((struct S_a08d8*)buf);
	func_ov017_021d6134(obj, pct);
	return 1;
}
