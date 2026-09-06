#include <globaldefs.h>

struct Base_0223caec { char pad[0x67c]; unsigned char flag67c; unsigned char flag67d; };
extern struct Base_0223caec* data_ov031_02290d38;

// USA: func_ov031_0223caec
ARM void SetFlagIfMatchesElem0_0223caec(void* ptr) {
	struct Base_0223caec* base = data_ov031_02290d38;
	if (ptr == (char*)base + 0x610) {
		base->flag67c = 1;
	} else {
		base->flag67d = 1;
	}
}
