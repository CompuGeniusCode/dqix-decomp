#include <globaldefs.h>

extern "C" void func_020be3f4(int, int, int);
extern "C" void func_020d2c98(int);
void PostEvent0x20(int, int);

// USA: func_020be4a4
ARM void PostRangeEvent0x20(int start, int length, int c, int d) {
    func_020be3f4(start, c, d);
    PostEvent0x20(start, start + length);
    func_020d2c98(start);
}
