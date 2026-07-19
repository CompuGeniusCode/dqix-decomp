#include <globaldefs.h>

int IsGlobal0224e5a4Set_02211aec(void);
extern "C" int func_ov031_0223f528(void*, void*, int, int);

// USA: func_ov031_02212c84  (semantic: RunIfGlobalUnset_02212c84)
extern "C" ARM int func_ov031_02212c84(void* a, void* b, int c) {
	if (IsGlobal0224e5a4Set_02211aec()) return 0;
	return func_ov031_0223f528(a, b, c, 0);
}
