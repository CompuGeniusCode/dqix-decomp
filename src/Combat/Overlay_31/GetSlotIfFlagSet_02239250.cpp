#include <globaldefs.h>
#pragma optimize_for_size off

struct SlotHeader0223911c { unsigned short h0; unsigned short flags2; unsigned char pad[8]; unsigned short hc; };
extern struct SlotHeader0223911c* data_ov031_02290d14;

// USA: func_ov031_02239250
ARM void* GetSlotIfFlagSet_02239250(int bit) {
	struct SlotHeader0223911c* hdr = data_ov031_02290d14;
	if (!(hdr->flags2 & (1 << bit))) return NULL;
	return (char*)hdr + 0xe + (bit - 1) * 0x1e;
}
