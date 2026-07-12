#include <globaldefs.h>

struct Mtx43_02030d30 { unsigned int v[12]; };
void BuildRotationMatrixX(struct Mtx43_02030d30* dst, int angle);
void IssueCommand0x19(int cmd);

// USA: func_020311f0
ARM void BuildAndIssueRotationMatrixX(int angle) {
    if (angle == 0) return;
    struct Mtx43_02030d30 mtxCopy;
    struct Mtx43_02030d30 mtx;
    BuildRotationMatrixX(&mtx, angle);
    mtxCopy = mtx;
    IssueCommand0x19((int)&mtxCopy);
}
