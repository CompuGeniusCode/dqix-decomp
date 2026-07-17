#include <globaldefs.h>

extern "C" unsigned char* func_ov031_02200af8(int* outLen);
extern "C" void func_ov031_02202e44(void* p, int len);
extern "C" void func_ov031_0220186c(void* p, int len);
void AdvanceAndClampField30_02200bb8(void);

// USA: func_ov031_02203008
ARM void ProcessIncomingPacket_02203008(void) {
	for (;;) {
		int len;
		unsigned char* buf = func_ov031_02200af8(&len);
		if ((unsigned int)len > 0x22) {
			unsigned short raw = *(unsigned short*)(buf + 0xc);
			unsigned int swapped = (unsigned short)((raw >> 8) | (raw << 8));
			switch (swapped) {
			case 0x800:
				func_ov031_02202e44(buf + 0xe, len - 0xe);
				break;
			case 0x806:
				func_ov031_0220186c(buf + 0xe, len - 0xe);
				break;
			}
		}
		AdvanceAndClampField30_02200bb8();
	}
}
