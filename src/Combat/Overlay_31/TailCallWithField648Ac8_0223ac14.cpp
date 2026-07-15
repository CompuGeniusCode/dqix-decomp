#include <globaldefs.h>

extern "C" int func_ov031_022386d4(void*, unsigned short);
struct Base_0223ac14 { char pad[0x648]; unsigned short field648; char pad2[0xac8 - 0x64a]; void* fieldac8; };
extern struct Base_0223ac14* data_ov031_02290d20;

// USA: func_ov031_0223ac14
ARM int TailCallWithField648Ac8_0223ac14(void) {
	struct Base_0223ac14* b = data_ov031_02290d20;
	return func_ov031_022386d4(b->fieldac8, b->field648);
}
