#include <globaldefs.h>

struct Triple021fbcc0 {
	unsigned int a;
	unsigned int b;
	unsigned int c;
};

// USA: func_ov023_021fbcc0
ARM struct Triple021fbcc0 GetOffset32Triple_021fbcc0(void *src) {
	return *(struct Triple021fbcc0*)((char*)src + 0x20);
}
