#include <globaldefs.h>

extern "C" int func_02030c68(int);
extern "C" int func_02030c9c(int);
extern "C" void func_020c197c(void*, int, int);

struct Mtx43_02030d30 { unsigned int v[12]; };

// USA: func_02030d30
ARM void BuildRotationMatrixX(struct Mtx43_02030d30* dst, int angle) {
    struct Mtx43_02030d30 local;
    int s = func_02030c68(angle);
    int c = func_02030c9c(angle);
    func_020c197c(&local, s, c);
    *dst = local;
}
