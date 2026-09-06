#include <globaldefs.h>

class PMFObj021e7bc4 { public: virtual void Dummy021e7bc4(); };
typedef void (PMFObj021e7bc4::*MemFn021e7bc4)();

struct DispatchTable021e7bc4 { MemFn021e7bc4 fns[3]; };
extern const DispatchTable021e7bc4 data_ov023_021fd79c;

// USA: func_ov023_021e7bc4
ARM void DispatchEntryByIndex_021e7bc4(PMFObj021e7bc4 *obj, unsigned int selector, int idx) {
	char *base = (char*)obj;
	if (*(int*)(base + 0x5d4) == 0) return;
	if (*(int*)(base + 0x5dc) == 0) return;

	int inRange;
	if (idx < 0) goto zero;
	if (idx <= 3) {
		inRange = 1;
		goto check;
	}
zero:
	inRange = 0;
check:
	if (inRange == 0) return;

	*(int*)(base + 0x5f0) = idx;
	DispatchTable021e7bc4 table = data_ov023_021fd79c;
	(obj->*table.fns[selector])();
}
