#include <globaldefs.h>

struct FourWords;
extern "C" void _Z19ZeroInitializeMutexP5Mutex(struct FourWords* p);
extern struct FourWords data_ov031_022918a4;

// USA: func_ov031_022402f4
ARM int ClearFourWords022918a4_022402f4(void) {
	_Z19ZeroInitializeMutexP5Mutex(&data_ov031_022918a4);
	return 1;
}
