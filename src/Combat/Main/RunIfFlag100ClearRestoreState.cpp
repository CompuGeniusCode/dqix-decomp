#include <globaldefs.h>

extern "C" unsigned char _Z27SetResourceMutexOperationalb(unsigned char v);

struct FlagWord02046708;
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
void* GetDataPtr02114e04_020d6c00(void);

extern "C" void func_020dbae0(void* obj);

// USA: func_020dbc0c  (semantic: RunIfFlag100ClearRestoreState)
extern "C" ARM void func_020dbc0c(void* obj) {
    unsigned char old = _Z27SetResourceMutexOperationalb(0);
    if (!TestFlags02046708((struct FlagWord02046708*)GetDataPtr02114e04_020d6c00(), 0x100)) {
        func_020dbae0(obj);
    }
    _Z27SetResourceMutexOperationalb(old);
}
