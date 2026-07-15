#include <globaldefs.h>

struct Sub150_021612ac { unsigned char pad[0x56b]; unsigned char field56b : 4; };

// USA: func_ov001_021612ac
ARM int GetNibbleAt56b(void* p) {
	struct Sub150_021612ac* q = *(struct Sub150_021612ac**)((char*)p + 0x150);
	if (!q) return 0;
	return q->field56b;
}
