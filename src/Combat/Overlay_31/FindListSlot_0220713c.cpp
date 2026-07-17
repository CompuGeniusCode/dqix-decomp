#include <globaldefs.h>

// USA: func_ov031_0220713c
extern "C" ARM void* FindListSlot_0220713c(void* head, void* item) {
	void** slot = (void**)head;
	void* cur = *slot;
	if (cur == NULL) goto notfound;
loop:
	if (cur == item) return slot;
	slot = (void**)((char*)cur + 0x7c);
	cur = *slot;
	if (cur != NULL) goto loop;
notfound:
	return NULL;
}
