#include <globaldefs.h>

struct NameTable02048080;
void ClearNameTable(struct NameTable02048080* table);
extern "C" void func_0204719c(void* obj);
extern int data_ov023_021fe3e4;

// USA: func_ov004_0215c448  (semantic: InitStructVtableAndClear_0215c448)
extern "C" ARM void* func_ov004_0215c448(void* obj) {
	*(void**)obj = &data_ov023_021fe3e4;
	ClearNameTable((struct NameTable02048080*)((char*)obj + 0x34));
	func_0204719c((char*)obj + 0x20);
	return obj;
}
