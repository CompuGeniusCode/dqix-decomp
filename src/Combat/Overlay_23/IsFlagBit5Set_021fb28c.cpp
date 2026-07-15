#include <globaldefs.h>

struct FlagObj021fb28c {
	char pad[0xc];
	unsigned char flags;
};

// USA: func_ov023_021fb28c
ARM int IsFlagBit5Set_021fb28c(struct FlagObj021fb28c *obj) {
	return (obj->flags & 0x20) != 0;
}
