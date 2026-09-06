#include <globaldefs.h>

extern "C" ARM int func_ov017_0218b5b0(void);
void SetFlagBit_0218d4b8(unsigned char* base, int bit);
void ClearFlagBit_0218d4d0(void* obj, int bit);

// USA: func_ov017_021d2774
ARM void SetOrClearOverlayFlagFromConfig_021d2774(void* unused, unsigned char* cfg) {
	unsigned char* base = (unsigned char*)func_ov017_0218b5b0();
	if (cfg[5]) {
		int bit = cfg[4];
		SetFlagBit_0218d4b8(base, bit);
	} else {
		int bit = cfg[4];
		ClearFlagBit_0218d4d0(base, bit);
	}
}
