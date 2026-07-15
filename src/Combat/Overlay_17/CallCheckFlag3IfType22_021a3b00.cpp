#include <globaldefs.h>

void CheckFlag3ThenFree_021b65bc(char* obj);

// USA: func_ov017_021a3b00
ARM void CallCheckFlag3IfType22_021a3b00(int unused, char* obj) {
	if (obj == NULL) return;
	if ((unsigned char)obj[1] != 0) goto ret1;
	if ((signed char)obj[0] != 0x16) goto ret2;
	CheckFlag3ThenFree_021b65bc(obj);
	return;
ret1:
	return;
ret2:
	return;
}
