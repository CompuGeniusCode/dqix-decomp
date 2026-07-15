#include <globaldefs.h>

struct SrcObj_021ca2d8 { unsigned char pad[4]; unsigned short h4; unsigned short h6; };

extern "C" int func_ov017_021b88d0(int, unsigned short, unsigned short);

// USA: func_ov017_021ca2d8
ARM int DispatchWithHalfwords_021ca2d8(int unused0, SrcObj_021ca2d8* src, int unused2, unsigned char* ov) {
	int val = *(int*)(ov + 0x3000 + 0x718);
	return func_ov017_021b88d0(val, src->h4, src->h6);
}
