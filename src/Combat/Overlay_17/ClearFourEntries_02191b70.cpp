#include <globaldefs.h>

struct Entry02191b70 { unsigned char b0; unsigned char pad; unsigned short h2; };

// USA: func_ov017_02191b70
ARM void ClearFourEntries_02191b70(void* obj) {
	Entry02191b70* p = (Entry02191b70*)((char*)obj + 0x9c + 0x4400);
	int i;
	for (i = 0; i < 4; i++) {
		p->b0 = 0;
		p->h2 = 0;
		p++;
	}
}
