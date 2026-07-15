#include <globaldefs.h>

// USA: func_ov017_021972f8
ARM void EnqueueHalfword_021972f8(void *obj, unsigned short val) {
	unsigned char *counter = (unsigned char *)obj + 0x44c0;
	unsigned short *arr = (unsigned short *)((unsigned char *)obj + 0x44b8);
	unsigned char idx = *counter;
	*counter = idx + 1;
	arr[idx] = val;
	*counter = *counter & 3;
}
