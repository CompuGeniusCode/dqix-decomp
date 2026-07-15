#include <globaldefs.h>

typedef void (*FnType021d4bc8)(void*, int);

struct A021d4bc8 { unsigned char pad[4]; int count; FnType021d4bc8* funcs; };
struct B021d4bc8 { unsigned char pad[4]; int idx; unsigned char data[1]; };

// USA: func_ov017_021d4bc8
ARM void DispatchIndexedCallback_021d4bc8(A021d4bc8* a, B021d4bc8* b, int c) {
	int idx = b->idx;
	if (idx < 0) return;
	if (idx >= a->count) return;
	FnType021d4bc8 fn = a->funcs[idx];
	if (!fn) return;
	fn(&b->data, c - 1);
}
