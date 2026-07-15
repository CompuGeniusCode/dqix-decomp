#include <globaldefs.h>

void SetCombatWorkFlags0x55f4(void* work, int mask);

// USA: func_ov000_02166e3c
ARM void SetCombatWorkFlags0x2And0x4(void* work) {
	SetCombatWorkFlags0x55f4(work, 2);
	SetCombatWorkFlags0x55f4(work, 4);
}
