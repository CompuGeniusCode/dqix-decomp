#include <globaldefs.h>

int IsGlobal0224e5a4Set_02211aec(void);
extern "C" int func_ov031_0223f1e8(int);

// USA: func_ov031_02212c18
ARM int RunIfGlobalUnset_02212c18(int a) {
	if (IsGlobal0224e5a4Set_02211aec()) return 0;
	return func_ov031_0223f1e8(a);
}
