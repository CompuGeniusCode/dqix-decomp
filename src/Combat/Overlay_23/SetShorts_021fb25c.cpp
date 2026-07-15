#include <globaldefs.h>

struct Obj021fb25c {
	char pad[0x30];
	unsigned short a;
	unsigned short b;
	unsigned short c;
	unsigned short d;
};

// USA: func_ov023_021fb25c
ARM void SetShorts_021fb25c(struct Obj021fb25c *obj, unsigned short a, unsigned short b, unsigned short c, int d) {
	obj->a = a;
	obj->b = b;
	obj->c = c;
	obj->d = d;
}
