#include <globaldefs.h>
#include "System/Memory.h"

struct Obj0224e5c4_02213054 { unsigned char pad[0x17]; unsigned char field17; unsigned char data18[10]; };
struct Glob0224e5c4_02213054 { unsigned char pad[0xc]; Obj0224e5c4_02213054* pField; };
extern Glob0224e5c4_02213054 data_ov031_0224e5c4;
int GetField9OrZero_022134b0(void);

// USA: func_ov031_02213054
ARM int CopyMatchingTierData_02213054(void* buf) {
	int result = 0;
	unsigned int v = GetField9OrZero_022134b0();
	if (v >= 0xa && v <= 0x10) {
		Obj0224e5c4_02213054* p = data_ov031_0224e5c4.pField;
		if (p->field17 == 4 || p->field17 == 8) {
			VectorizedInvertedMemcpy(p->data18, buf, 0xa);
			result = 1;
		}
	}
	return result;
}
