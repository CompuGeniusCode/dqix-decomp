#include <globaldefs.h>

class PMFObj021e7c58 { public: virtual void Dummy021e7c58(); };
typedef void (PMFObj021e7c58::*MemFn021e7c58)();

struct DispatchTable021e7c58 { MemFn021e7c58 fns[3]; };
extern const DispatchTable021e7c58 data_ov023_021fd7b4;

// USA: func_ov023_021e7c58
ARM void DispatchEntryByIndex_021e7c58(PMFObj021e7c58 *obj, unsigned int selector, int idx) {
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
	DispatchTable021e7c58 table = data_ov023_021fd7b4;
	(obj->*table.fns[selector])();
}
