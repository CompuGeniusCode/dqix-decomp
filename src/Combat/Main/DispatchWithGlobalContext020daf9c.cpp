#include <globaldefs.h>

extern int data_0214e4c8;
extern "C" void func_020db264(void*, int, int, int, int);

// USA: func_020daf9c
ARM void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d) {
    func_020db264(&data_0214e4c8, a, b, c, d);
}
