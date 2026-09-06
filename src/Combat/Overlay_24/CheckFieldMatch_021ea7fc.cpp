#include <globaldefs.h>

struct FieldObj_021ea7fc {
	unsigned int pad0;
	unsigned int val:12;
	unsigned int rest:20;
	unsigned int val8:29;
	unsigned int flag8:1;
	unsigned int rest8:2;
};

// USA: func_ov024_021ea7fc
ARM int CheckFieldMatch_021ea7fc(void* unused0, struct FieldObj_021ea7fc* p, int c) {
	if (c == 0) return 0;
	if (p->flag8) {
		if (p->val != 0x1f9) return 0;
	}
	if (p->val == 0x70) return 0;
	if (p->val == 0x48) return 0;
	return 1;
}
