#include <globaldefs.h>

struct Entry0218b9d4 {
	int a;
	int b;
	unsigned short c;
	unsigned char d;
	unsigned char e;
};

struct List0218b9d4 {
	Entry0218b9d4* arr;
	int pad4;
	int count;
};

// USA: func_ov015_0218b9d4
ARM void AppendEntry0218b9d4(struct List0218b9d4* list, struct Entry0218b9d4* src) {
	int index = list->count;
	Entry0218b9d4* dst;
	list->count = index + 1;
	dst = list->arr + index;
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
	dst->d = src->d;
	dst->e = src->e;
}
