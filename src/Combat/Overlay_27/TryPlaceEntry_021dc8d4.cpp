#include <globaldefs.h>
#include "System/Interrupts.h"

int CheckPositionInRange_021dc864(unsigned int a, unsigned int b, int c);

struct FieldHolder_021dc8d4 {
	unsigned char pad0[8];
	unsigned char *ptr;
};

extern FieldHolder_021dc8d4 data_ov027_021e33e0;

// USA: func_ov027_021dc8d4  (semantic: TryPlaceEntry_021dc8d4)
extern "C" ARM int func_ov027_021dc8d4(int a, int b) {
	int oldState = DisableIRQInterrupts();
	if (data_ov027_021e33e0.ptr[0x50d] != 0) {
		SetIRQInterruptState(oldState);
		return 0;
	}
	if (!CheckPositionInRange_021dc864(a, 8, b)) {
		SetIRQInterruptState(oldState);
		return 0;
	}
	*(unsigned short *)(data_ov027_021e33e0.ptr + 0x10) = (unsigned short)b;
	*(unsigned short *)(data_ov027_021e33e0.ptr + 0x500) = (unsigned short)a;
	*(unsigned short *)(data_ov027_021e33e0.ptr + 0x502) = 8;
	SetIRQInterruptState(oldState);
	return 1;
}
