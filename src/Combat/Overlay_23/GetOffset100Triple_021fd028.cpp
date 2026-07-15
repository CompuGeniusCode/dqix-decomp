#include <globaldefs.h>

struct Triple021fd028 {
	unsigned int a;
	unsigned int b;
	unsigned int c;
};

// USA: func_ov023_021fd028
ARM struct Triple021fd028 GetOffset100Triple_021fd028(void *src) {
	return *(struct Triple021fd028*)((char*)src + 0x64);
}
