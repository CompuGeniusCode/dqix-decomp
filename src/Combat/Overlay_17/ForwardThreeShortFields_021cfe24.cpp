#include <globaldefs.h>

extern "C" int func_ov017_021b6174(int a, int b, int c);

// USA: func_ov017_021cfe24
ARM int ForwardThreeShortFields_021cfe24(void* obj, char* rec) {
    return func_ov017_021b6174(*(unsigned short*)(rec + 4), *(unsigned short*)(rec + 6), *(unsigned short*)(rec + 8));
}
