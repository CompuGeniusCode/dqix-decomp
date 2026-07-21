#include <globaldefs.h>
#pragma optimize_for_size off

extern "C" void func_ov031_0223c150();
void StoreSignedPairWithFlag020c5100(unsigned short* dst, int flag, int value);
void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);

extern unsigned char data_ov031_022493a0[];

struct Entry0223c078 {
	unsigned int result;
	unsigned short reserved4;
	unsigned short extra;
	unsigned char idx;
	unsigned char ready;
	unsigned char pad[2];
};
extern Entry0223c078* data_ov031_02290d34;

// USA: func_ov031_0223c078  (semantic: InitEntryIfFree_0223c078)
extern "C" ARM int func_ov031_0223c078(int idx, int side, int flag, int extra) {
	signed char buf[4];
	buf[0] = data_ov031_022493a0[0x8];
	buf[1] = data_ov031_022493a0[0x9];
	buf[2] = data_ov031_022493a0[0xa];
	buf[3] = data_ov031_022493a0[0xb];

	Entry0223c078* entry = (side == 1) ? data_ov031_02290d34 : (Entry0223c078*)((char*)data_ov031_02290d34 + 0xc);
	if (entry->ready != 0) {
		return 0;
	}

	if (side == 1) {
		StoreSignedPairWithFlag020c5100((unsigned short*)0x4001050, flag, buf[idx]);
	} else {
		StoreSignedPairWithFlag020c5100((unsigned short*)0x4000050, flag, buf[idx]);
	}

	entry->result = (unsigned int)CallWithZeroExtra_0223e218((void*)1, (void*)func_ov031_0223c150, entry, 0xc8);
	entry->reserved4 = 0;
	entry->idx = (unsigned char)idx;
	entry->extra = (unsigned short)extra;
	entry->ready = 1;
	return 1;
}
