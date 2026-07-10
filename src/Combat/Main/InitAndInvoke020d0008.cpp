#include <globaldefs.h>

extern "C" void func_020cfcf8(int, int);
extern "C" void func_020c7010(int);

// USA: func_020d0008
ARM void InitAndInvoke020d0008(int a) {
    func_020cfcf8(a, 1);
    func_020c7010(a);
}
