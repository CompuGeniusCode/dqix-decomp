#include <globaldefs.h>

struct Pair021d4a64 { int a; int b; };
extern void CopyPair_021d4a64(Pair021d4a64* dst, Pair021d4a64* src);

struct S1_021d4a38 { unsigned char pad[0x14]; Pair021d4a64* cursor; };

// USA: func_ov017_021d4a38
ARM void EnqueuePairEntry_021d4a38(S1_021d4a38* obj, Pair021d4a64 arg) {
	Pair021d4a64* e = obj->cursor;
	obj->cursor = e + 1;
	CopyPair_021d4a64(e, &arg);
}
