#include <globaldefs.h>

extern "C" void func_0203b110(void* obj, int value, int frames);
extern "C" void func_0203b19c(void* obj, int value, int frames);

// USA: func_0203b280
ARM void SetAndLockBothCounters(unsigned char* obj, int value, int frames) {
    func_0203b110(obj, value, frames);
    obj[0x24] = 1;
    func_0203b19c(obj, value, frames);
    obj[0x25] = 1;
}
