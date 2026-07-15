#include <globaldefs.h>

struct Outer020e28dc;
struct Struct020e2794;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
void UpdateEntryIfActive020e2794(struct Struct020e2794* self, void* b);

struct Wrapper02176098 {
	void* field0;
};

// USA: func_ov003_02176098
ARM void UpdateFlagEntry_02176098(struct Wrapper02176098* p) {
	if (p->field0 == NULL) return;
	if (!GetInnerFlagBit0020e28dc((struct Outer020e28dc*)p->field0)) return;
	void* b = (char*)p + 0x7d8;
	UpdateEntryIfActive020e2794((struct Struct020e2794*)p->field0, b);
}
