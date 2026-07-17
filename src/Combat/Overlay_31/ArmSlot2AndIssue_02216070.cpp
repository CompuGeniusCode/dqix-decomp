#include <globaldefs.h>

extern void *data_ov031_0224e5d8;
extern "C" int IssueBattleCommandSlot2(int arg);

// USA: func_ov031_02216070
ARM int ArmSlot2AndIssue_02216070(int arg) {
	if (arg == 0) return -1;
	*(int*)((char*)data_ov031_0224e5d8 + 0x1000 + 0xa90) = 3;
	data_ov031_0224e5d8 = 0;
	int r = IssueBattleCommandSlot2(arg);
	if (r == 2) r = 0;
	return r;
}
