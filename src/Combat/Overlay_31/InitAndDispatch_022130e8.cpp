#include <globaldefs.h>
#include "System/Memory.h"

struct T022133f8 { unsigned char pad[0x18]; unsigned char data18[10]; unsigned char field22; };
T022133f8* GetFieldPtrByMask_022133f8(int);
extern "C" void func_ov031_0221314c(void*, void*, void*);

// USA: func_ov031_022130e8
ARM void InitAndDispatch_022130e8(void* a, void* b, void* c, void* d, int e) {
	T022133f8* t = GetFieldPtrByMask_022133f8(1);
	if (d != NULL) {
		VectorizedInvertedMemcpy(d, t->data18, 0xa);
	} else {
		VectorizedMemset(t->data18, 0, 0xa);
	}
	t->field22 = (unsigned char)e;
	func_ov031_0221314c(a, b, c);
}
