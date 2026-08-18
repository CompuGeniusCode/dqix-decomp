#include <globaldefs.h>

struct FourWords;
extern "C" void _Z19ZeroInitializeMutexP5Mutex(FourWords* p);
void ClearCallbackTable();

extern "C" void func_020d2220(void);

extern int data_02112750;
extern FourWords data_02112754;

// USA: func_020d21c0
ARM void InitFourWordsAndCallbacksOnce(void) {
    if (data_02112750 != 0) {
        return;
    }
    data_02112750 = 1;
    _Z19ZeroInitializeMutexP5Mutex(&data_02112754);
    func_020d2220();
    ClearCallbackTable();
}
