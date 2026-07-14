#include <globaldefs.h>

struct Mtx43_02030d84 { unsigned int v[12]; };
void BuildRotationMatrixY(struct Mtx43_02030d84* dst, int angle);
void IssueCommand0x19(int cmd);

// USA: func_02031234
ARM void BuildAndIssueRotationMatrixY(int angle) {
    if (angle == 0) return;
    struct Mtx43_02030d84 mtxCopy;
    struct Mtx43_02030d84 mtx;
    BuildRotationMatrixY(&mtx, angle);
    mtxCopy = mtx;
    IssueCommand0x19((int)&mtxCopy);
}
