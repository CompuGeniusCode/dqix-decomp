#include <globaldefs.h>

extern "C" void func_ov031_0221038c(int v);
void SetGlobal0224e588Deref_022103dc(void* value);
struct BlockedContextList;
void UnblockContexts(struct BlockedContextList*);

extern void* data_ov031_0224e588;

// USA: func_ov031_022103f8
ARM void ResetFieldAndUnblock_022103f8(void* value) {
	func_ov031_0221038c(0);
	SetGlobal0224e588Deref_022103dc(value);
	UnblockContexts((BlockedContextList*)((char*)data_ov031_0224e588 + 0xa04));
}
