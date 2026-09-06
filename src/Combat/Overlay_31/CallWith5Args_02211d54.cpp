#include <globaldefs.h>

struct Entry02211d54 { unsigned char pad[0xc]; unsigned char fieldc; };
struct Glob0224e5b4_02211d54 { void* pad0; Entry02211d54* pField; };
extern Glob0224e5b4_02211d54 data_ov031_0224e5b4;

extern "C" void func_ov031_02211ca0(void);
extern "C" int func_ov031_02211f24(void);
extern "C" void func_ov031_022130e8(int, int, int, int, int);

// USA: func_ov031_02211d54
ARM void CallWith5Args_02211d54(int a, int b, int c, int d, int e) {
	func_ov031_02211ca0();
	if (data_ov031_0224e5b4.pField != NULL) {
		data_ov031_0224e5b4.pField->fieldc = 1;
	}
	if (func_ov031_02211f24() == 2) {
		func_ov031_022130e8(a, b, c, d, e);
	}
}
