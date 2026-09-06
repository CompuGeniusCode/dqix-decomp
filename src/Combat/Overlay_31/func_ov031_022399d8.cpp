#include <globaldefs.h>

int IssueBattleCommandSlot9(int arg);
void SetField54IfTagNot9Or10(int v);
int SetField54OrTagOne_02239a00(short* p);

// USA: func_ov031_022399d8
extern "C" ARM int func_ov031_022399d8(void) {
	int r = IssueBattleCommandSlot9((int)SetField54OrTagOne_02239a00);
	if (r == 2) return 1;
	SetField54IfTagNot9Or10(r);
	return 0;
}
