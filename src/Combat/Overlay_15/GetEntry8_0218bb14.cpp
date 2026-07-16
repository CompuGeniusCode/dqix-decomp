#include <globaldefs.h>

struct Entry8_0218bb14 { int a; int b; };
struct List8_0218bb14 { void* f0; Entry8_0218bb14* arr; void* f8; int count; };

// USA: func_ov015_0218bb14
ARM struct Entry8_0218bb14* GetEntry8_0218bb14(struct List8_0218bb14* obj, int idx) {
	if (idx < 0) goto fail;
	if (obj->count > idx) goto success;
fail:
	return NULL;
success:
	return &obj->arr[idx];
}
