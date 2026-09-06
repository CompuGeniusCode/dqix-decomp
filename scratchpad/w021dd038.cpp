#include <globaldefs.h>

struct Inner021dd038 {
	char pad[0xc];
	unsigned short field_0xc;
};
struct Struct021dd038 {
	char pad[0x8];
	struct Inner021dd038* field_0x8;
};
extern struct Struct021dd038 data_ov027_021e33e0;

// USA: func_ov027_021dd038
unsigned short GetField021dd038(void) {
	return data_ov027_021e33e0.field_0x8->field_0xc;
}
