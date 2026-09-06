#include <globaldefs.h>
#include "System/Timing.h"

extern "C" void func_ov031_02201e70(void*, void*);
extern "C" int func_ov031_02201f10(int, int, int);

struct Hdr022020e8 { unsigned char pad[0xc]; unsigned short f0c; unsigned short f0e; unsigned short f10; unsigned short f12; };
struct Src022020e8 { unsigned short f0; unsigned char pad1[2]; unsigned short f4; unsigned short f6; };
struct Dst022020e8 {
	unsigned char pad0[8];
	unsigned char f8;
	unsigned char pad1[0x10 - 0x8 - 1];
	unsigned int f10;
	unsigned int f14;
	unsigned short f18;
	unsigned char pad2[0x1c - 0x18 - 2];
	unsigned int f1c;
	unsigned char pad3[0x24 - 0x1c - 4];
	unsigned int f24;
};

#define SW16_022020e8(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_022020e8  (semantic: BuildAndDispatchPacket_022020e8)
extern "C" ARM void func_ov031_022020e8(Hdr022020e8* hdr, Src022020e8* src, Dst022020e8* dst) {
	dst->f8 = 3;
	dst->f10 = (unsigned int)(GetCurrentTimestamp() >> 16);
	dst->f14 = ((unsigned int)SW16_022020e8(hdr->f10) << 16) | SW16_022020e8(hdr->f12);
	dst->f18 = SW16_022020e8(src->f0);
	dst->f1c = ((unsigned int)SW16_022020e8(hdr->f0c) << 16) | SW16_022020e8(hdr->f0e);
	dst->f24 = (((unsigned int)SW16_022020e8(src->f4) << 16) | SW16_022020e8(src->f6)) + 1;
	func_ov031_02201e70(src, dst);
	func_ov031_02201f10((int)dst, 0x12, 0);
}
