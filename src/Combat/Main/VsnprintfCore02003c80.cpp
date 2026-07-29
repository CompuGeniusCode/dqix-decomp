#include <globaldefs.h>

extern "C" unsigned int func_02003418(void* callback, void* state, const char* fmt, void* args);
extern "C" void func_02003c3c(void);

struct VsnprintfState02003c80 {
    char* buf;
    unsigned int sizeLimit;
    int count;
};

// USA: func_02003c80
#pragma optimize_for_size off
extern "C" ARM unsigned int func_02003c80(char* buf, unsigned int sizeLimit, const char* fmt, void* args) {
    struct VsnprintfState02003c80 local;
    local.buf = buf;
    local.sizeLimit = sizeLimit;
    local.count = 0;
    unsigned int result = func_02003418((void*)func_02003c3c, &local, fmt, args);
    if (buf == 0) {
        return result;
    }
    if (result < sizeLimit) {
        buf[result] = 0;
        return result;
    }
    if (sizeLimit != 0) {
        *(buf + sizeLimit - 1) = 0;
    }
    return result;
}
