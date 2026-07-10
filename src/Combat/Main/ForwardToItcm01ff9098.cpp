#include <globaldefs.h>

extern "C" void func_01ff9098(void*);
extern int data_0214e5e4;

// USA: func_020dc200
ARM void ForwardToItcm01ff9098(void) {
    func_01ff9098(&data_0214e5e4);
}
