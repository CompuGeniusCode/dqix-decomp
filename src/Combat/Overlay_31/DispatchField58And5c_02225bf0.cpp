#include <globaldefs.h>

struct EntityStruct02225bf0 {
	unsigned char pad[0x58];
	int field58;
	int field5c;
};

extern EntityStruct02225bf0* data_ov031_02250c00;

extern "C" void func_ov031_0223ba20(int a);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_02226b10(void);

// USA: func_ov031_02225bf0  (semantic: DispatchField58And5c_02225bf0)
extern "C" ARM void func_ov031_02225bf0(void) {
	func_ov031_0223ba20(data_ov031_02250c00->field58);
	func_ov031_0223e2b8((void*)data_ov031_02250c00->field5c, (int)func_ov031_02226b10);
}
