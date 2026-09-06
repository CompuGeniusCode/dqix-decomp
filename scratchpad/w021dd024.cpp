#include <globaldefs.h>

struct Inner021dd024 {
	char pad[0x8];
	int field_0x8;
};
struct Struct021dd024 {
	char pad[0x8];
	struct Inner021dd024* field_0x8;
};
extern struct Struct021dd024 data_ov027_021e33e0;

// USA: func_ov027_021dd024
int GetField021dd024(void) {
	return data_ov027_021e33e0.field_0x8->field_0x8;
}
