#include <globaldefs.h>

struct Struct021dcee8 {
	char pad[0x26];
	unsigned short field_0x26;
};
extern struct Struct021dcee8 data_ov027_021e33e0;

// USA: func_ov027_021dcee8
void SetField26_021dcee8(unsigned short v) {
	data_ov027_021e33e0.field_0x26 = v;
}
