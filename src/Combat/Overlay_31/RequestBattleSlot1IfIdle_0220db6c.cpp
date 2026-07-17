#include <globaldefs.h>

int IssueBattleCommandSlot1(int arg);
extern "C" void func_ov031_0220da1c(int);
void ReadClearAndDispatch_0220d984(short a, int b, int c, int d);
extern "C" void func_ov031_0220e7b0(void);

extern void* data_ov031_0224e53c;

// USA: func_ov031_0220db6c
ARM void RequestBattleSlot1IfIdle_0220db6c(void) {
	char* io = (char*)data_ov031_0224e53c + 0x2000;
	if (*(unsigned char*)(io + 0x26b) != 0) return;
	*(unsigned char*)(io + 0x26b) = 1;
	int r = IssueBattleCommandSlot1((int)func_ov031_0220e7b0);
	if (r == 2) return;
	func_ov031_0220da1c(0xb);
	ReadClearAndDispatch_0220d984(7, 0, 0, 0x610);
}
