#include <globaldefs.h>
extern "C" void* _Z12CreateRandomP6RandomPKch(void*, const char*, char);
extern void* data_02108ddc;
extern char data_020f0d66;
// USA: func_020e60c0
ARM void* CreateRandom_020e60c0(void) {
    return _Z12CreateRandomP6RandomPKch(&data_02108ddc, (const char*)&data_020f0d66, 1);
}
