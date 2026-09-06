#include <globaldefs.h>

extern "C" void func_ov031_02239368(int);
extern int IssueBattleCommandSlot1(int);
extern "C" void func_ov031_02239b64(void);
extern void SetField54IfTagNot9Or10(int);

// USA: func_ov031_02239b34  (semantic: IssueSlot1AndSetField54_02239b34)
extern "C" ARM int func_ov031_02239b34(void) {
	func_ov031_02239368(3);
	int r = IssueBattleCommandSlot1((int)func_ov031_02239b64);
	if (r == 2) return 1;
	SetField54IfTagNot9Or10(r);
	return 0;
}
