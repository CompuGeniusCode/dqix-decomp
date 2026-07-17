#include <globaldefs.h>

void* GetFieldPtrByMask_022133f8(unsigned int mask);
extern "C" int strncmp(const void*, const void*, unsigned int);
extern char data_ov031_02245fe0;

struct StateField022145b4 {
	unsigned char state : 4;
	unsigned char rest : 4;
};

// USA: func_ov031_022145b4
ARM int CheckStateAndName_022145b4(char* obj) {
	void* p = GetFieldPtrByMask_022133f8(0x10);
	struct StateField022145b4* f = (struct StateField022145b4*)((char*)p + 0xd0c);
	unsigned int state = f->state;
	if (state == 0 || state == 6) {
		if (strncmp(obj + 0xc, &data_ov031_02245fe0, 8) == 0) {
			return 8;
		}
	}
	return 0;
}
