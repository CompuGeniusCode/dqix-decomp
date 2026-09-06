#include <globaldefs.h>

struct EntryBuf_02189398;
struct ArrayStruct021893e4;
struct KeyStruct021893e4;
extern "C" ARM int* func_ov014_0218940c(struct ArrayStruct021893e4* table, int index, struct KeyStruct021893e4* key);
ARM int* AllocAlignedSlot_02189398(struct EntryBuf_02189398* s);

// USA: func_ov014_02189430  (semantic: ResolveIndexedSlot_02189430)
extern "C" ARM int* func_ov014_02189430(struct EntryBuf_02189398* obj, int index, struct KeyStruct021893e4* key) {
	if (!key) return 0;
	int* slot = func_ov014_0218940c((struct ArrayStruct021893e4*)obj, index, key);
	if (!slot) return 0;
	int* base = AllocAlignedSlot_02189398(obj);
	return base + *(unsigned short*)slot;
}
