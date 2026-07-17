#include <globaldefs.h>

struct Struct02290c40 { void* field0; };
extern Struct02290c40 data_ov031_02290c40;

extern "C" void* func_ov031_0223cf4c(int, int);
extern "C" int func_ov031_0223beec(int, void*, int);

// USA: func_ov031_022275e0
ARM void Init_022275e0(void) {
    data_ov031_02290c40.field0 = func_ov031_0223cf4c(0x64, 4);
    int r = func_ov031_0223beec(8, data_ov031_02290c40.field0, 0xc);
    *(int*)((char*)data_ov031_02290c40.field0 + 0x60) = r;
}
