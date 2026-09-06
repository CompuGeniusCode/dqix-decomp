#include <globaldefs.h>

extern "C" void _Z9LockMutexP5Mutex(void *node);
struct RefNode020c80f8;
extern "C" void _Z11UnlockMutexP5Mutex(struct RefNode020c80f8 *node);

extern char *data_ov031_0224e60c;

// USA: func_ov031_0221a1d4  (semantic: SetFieldAndReleaseRef_0221a1d4)
extern "C" ARM void func_ov031_0221a1d4(int a) {
	_Z9LockMutexP5Mutex(data_ov031_0224e60c + 0x1dc + 0x1000);
	*(int*)(data_ov031_0224e60c + 0x1000) = a;
	_Z11UnlockMutexP5Mutex((struct RefNode020c80f8*)(data_ov031_0224e60c + 0x1dc + 0x1000));
}
