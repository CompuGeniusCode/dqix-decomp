#include <globaldefs.h>

struct FourWords;
extern "C" void _Z19ZeroInitializeMutexP5Mutex(struct FourWords* p);
extern struct FourWords data_ov031_02290fa4;

// USA: func_ov031_0223f9f0
ARM int ClearFourWords02290fa4_0223f9f0(void) {
	_Z19ZeroInitializeMutexP5Mutex(&data_ov031_02290fa4);
	return 1;
}
