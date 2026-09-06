#include <globaldefs.h>

struct Entry8_0218ba1c { int a; int b; };
struct List8_0218ba1c { void* f0; Entry8_0218ba1c* arr; void* f8; int count; };

// USA: func_ov015_0218ba1c
ARM void AddEntry8_0218ba1c(struct List8_0218ba1c* obj, struct Entry8_0218ba1c* src) {
	int idx = obj->count;
	obj->count = idx + 1;
	struct Entry8_0218ba1c* dst = &obj->arr[idx];
	dst->a = src->a;
	dst->b = src->b;
}
