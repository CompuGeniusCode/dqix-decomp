#include <globaldefs.h>

extern "C" void func_0203b110(void* obj, int value, int frames);
extern "C" void func_0203b19c(void* obj, int value, int frames);

// USA: func_0203b2e0
ARM void UnlockAndSetBothCounters(unsigned char* obj, int value, int frames) {
    obj[0x24] = 0;
    func_0203b110(obj, value, frames);
    obj[0x25] = 0;
    func_0203b19c(obj, value, frames);
}
