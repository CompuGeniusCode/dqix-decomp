#include <globaldefs.h>

extern "C" void func_ov031_0221e894(void*);
extern "C" void func_ov031_02236364(void*);
extern "C" int func_ov031_0223cf70(void*);

struct Struct02226f18_B { unsigned char pad[0x116]; unsigned char field116; };
struct Struct02226f18_A { unsigned char field0; unsigned char pad[3]; Struct02226f18_B* field4; };

extern Struct02226f18_A data_ov031_02250c04;
extern int data_ov031_02250c08;

// USA: func_ov031_02226f18  (semantic: NotifyThenMaybeProcessAndFree_02226f18)
extern "C" ARM void func_ov031_02226f18(void* arg) {
	func_ov031_0221e894(arg);
	if (arg != 0) {
		if (data_ov031_02250c04.field4->field116 == 0 && data_ov031_02250c04.field0 == 1) {
			func_ov031_02236364((char*)data_ov031_02250c04.field4 + 0x117);
		}
	}
	func_ov031_0223cf70(&data_ov031_02250c08);
}
