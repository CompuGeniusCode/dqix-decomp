#include <globaldefs.h>

extern int data_ov031_022918a4;
extern "C" void* _Z9LockMutexP5Mutex(void *a);

// USA: func_ov031_02240310
ARM void* AcquireData022918a4_02240310(void) {
    return _Z9LockMutexP5Mutex(&data_ov031_022918a4);
}
