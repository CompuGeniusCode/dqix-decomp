#include <globaldefs.h>

extern "C" int func_ov031_02239368(int);
extern "C" int func_020d5aec(int);
void SetField54IfTagNot9Or10(int);
void CheckField2ThenDispatch_02239aa4(void);

// USA: func_ov031_02239a74
ARM int RegisterTagAaa4AndSetField54_02239a74(void) {
	func_ov031_02239368(3);
	int r = func_020d5aec((int)CheckField2ThenDispatch_02239aa4);
	if (r == 2) {
		return 1;
	}
	SetField54IfTagNot9Or10(r);
	return 0;
}
