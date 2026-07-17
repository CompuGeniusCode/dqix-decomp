#include <globaldefs.h>

extern "C" int func_ov031_02239368(int);
extern "C" int IssueBattleCommandSlot1(int);
void SetField54IfTagNot9Or10(int);
void DispatchByField2_02239b64(void);

// USA: func_ov031_02239b34
ARM int RegisterTagB64AndSetField54_02239b34(void) {
	func_ov031_02239368(3);
	int r = IssueBattleCommandSlot1((int)DispatchByField2_02239b64);
	if (r == 2) {
		return 1;
	}
	SetField54IfTagNot9Or10(r);
	return 0;
}
