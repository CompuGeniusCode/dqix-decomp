#include <globaldefs.h>

extern "C" int func_02030c68(int);
extern "C" int func_02030c9c(int);
extern "C" void func_020c199c(void*, int, int);

struct Mtx43_02030d84 { unsigned int v[12]; };

// USA: func_02030d84
ARM void BuildRotationMatrixY(struct Mtx43_02030d84* dst, int angle) {
    struct Mtx43_02030d84 local;
    int s = func_02030c68(angle);
    int c = func_02030c9c(angle);
    func_020c199c(&local, s, c);
    *dst = local;
}
