#include <globaldefs.h>

// USA: func_ov017_021954c4
ARM void SetSearchBitAndClearFlag_021954c4(void* obj, int bitIdx) {
	unsigned char* ptr = *(unsigned char**)((char*)obj + 0x4000 + 0x41c);
	if (ptr[0] != 0) {
		if (ptr[2] == bitIdx) {
			ptr[0] = 0;
			ptr[1] = 0;
			{
				unsigned char* other = *(unsigned char**)((char*)obj + 0x3000 + 0xb30);
				if (other[3] != 0) other[8] = 1;
			}
		}
	}
	*((unsigned char*)obj + 0x4000 + 0x31e) |= (1 << bitIdx);
}
