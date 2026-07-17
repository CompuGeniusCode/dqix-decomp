#include <globaldefs.h>

void* GetFieldPtrByMask_022133f8(unsigned int mask);

// USA: func_ov031_02214ac8
ARM void SetProgressBit_02214ac8(unsigned int v) {
	char* p = (char*)GetFieldPtrByMask_022133f8(0x10);
	p += 0xd00;
	if (v > 0xd) v = 0xd;
	unsigned short flags = *(unsigned short*)(p + 0x16);
	flags |= 1 << (v - 1);
	*(unsigned short*)(p + 0x16) = flags;
}
