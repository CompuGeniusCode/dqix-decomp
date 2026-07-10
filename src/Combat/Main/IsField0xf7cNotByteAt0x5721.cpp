#include <globaldefs.h>

extern "C" void* func_02010828(void* arg);
extern "C" int func_02011538(void* arg);

// USA: func_0206852c
ARM int IsField0xf7cNotByteAt0x5721(void* arg) {
    unsigned char* p = (unsigned char*)func_02010828(arg);
    int v = func_02011538(arg);
    return p[0xf7c] != v;
}
