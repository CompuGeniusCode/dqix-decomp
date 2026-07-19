#include <globaldefs.h>

// USA: func_ov023_021e4250
ARM unsigned char GetByteViaFieldIndirectOffset_021e4250_021e4250(char* p) {
	char* q = *(char**)(p + 0x150);
	return *(unsigned char*)(q + *(int*)(q + 0x950) + 0x186);
}
