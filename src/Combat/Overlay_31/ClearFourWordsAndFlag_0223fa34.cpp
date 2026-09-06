#include <globaldefs.h>

struct FourWords;
extern "C" void _Z19ZeroInitializeMutexP5Mutex(struct FourWords* p);
extern struct FourWords data_ov031_02290f8c;
extern int data_ov031_02290f88;

// USA: func_ov031_0223fa34
ARM int ClearFourWordsAndFlag_0223fa34(void) {
	_Z19ZeroInitializeMutexP5Mutex(&data_ov031_02290f8c);
	data_ov031_02290f88 = 0;
	return 1;
}
