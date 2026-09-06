#include <globaldefs.h>

struct Header02211b28 {
	int magic;
	int value;
};

// USA: func_ov031_02211b28
ARM void* InitHeaderMagic_02211b28(Header02211b28* h, int value) {
	h->magic = 0x4457434d;
	h->value = value;
	return (char*)h + 0x20;
}
