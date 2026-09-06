#include <globaldefs.h>

extern "C" void func_0203b110(void* obj, int value, int frames);
extern "C" void func_0203b19c(void* obj, int value, int frames);

// USA: func_0203b228
ARM void SetBothCounters(void* obj, int value, int frames) {
    func_0203b110(obj, value, frames);
    func_0203b19c(obj, value, frames);
}
