#include <globaldefs.h>

extern "C" void func_020c702c(int);
extern "C" void func_020cfd7c(int, int);

// USA: func_020d0024
ARM void PrepareAndCommit020d0024(int a) {
    func_020c702c(a);
    func_020cfd7c(a, 1);
}
