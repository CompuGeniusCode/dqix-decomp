#include <globaldefs.h>

extern int data_ov031_02290fa4;
extern "C" void* _Z9LockMutexP5Mutex(void *a);

// USA: func_ov031_0223fa0c
ARM void* CallField8074_0223fa0c(void) {
    return _Z9LockMutexP5Mutex(&data_ov031_02290fa4);
}
