#include <globaldefs.h>

extern void *data_ov031_0224e5d8;
extern "C" int IssueBattleCommandSlot11(int arg);

// USA: func_ov031_02216178
ARM int ArmSlot11AndIssue_02216178(int arg) {
	if (arg == 0) return -1;
	*(int*)((char*)data_ov031_0224e5d8 + 0x1000 + 0xa90) = 2;
	int r = IssueBattleCommandSlot11(arg);
	if (r == 2) r = 0;
	return r;
}
