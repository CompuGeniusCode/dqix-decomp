#include <globaldefs.h>

// USA: func_ov006_02158cac
ARM void ComputeField_02158cac_02158cac(void *obj) {
	unsigned short count = 0;
	void *node = *(void**)((char*)obj + 0x2c);
	while (node) {
		count++;
		node = *(void**)((char*)node + 0x1c);
	}
	int val = (count + 15) / 16;
	*(signed char*)((char*)obj + 0x389) = val;
	if ((val & 0xff) == 0) {
		*(signed char*)((char*)obj + 0x389) = 1;
	}
	*(unsigned char*)((char*)obj + 0x388) = 0;
}
