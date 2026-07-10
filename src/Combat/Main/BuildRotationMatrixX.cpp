#include <globaldefs.h>

int GetTableEntryEven02030c68(int);
int GetTableEntryOdd02030c9c(int);
extern "C" void func_020c197c(void*, int, int);

struct Mtx43_02030d30 { unsigned int v[12]; };

// USA: func_02030d30
ARM void BuildRotationMatrixX(struct Mtx43_02030d30* dst, int angle) {
    struct Mtx43_02030d30 local;
    int s = GetTableEntryEven02030c68(angle);
    int c = GetTableEntryOdd02030c9c(angle);
    func_020c197c(&local, s, c);
    *dst = local;
}
