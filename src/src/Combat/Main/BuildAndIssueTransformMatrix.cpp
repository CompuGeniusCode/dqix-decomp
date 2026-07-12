#include <globaldefs.h>

struct MtxFx43_02030dd8 { unsigned int v[12]; };
void BuildTransformMatrix02030dd8(struct MtxFx43_02030dd8* dst, void* src);
void IssueCommand0x19(int cmd);

// USA: func_02031278
ARM void BuildAndIssueTransformMatrix(void* src) {
    if (src == NULL) return;
    struct MtxFx43_02030dd8 mtxCopy;
    struct MtxFx43_02030dd8 mtx;
    BuildTransformMatrix02030dd8(&mtx, src);
    mtxCopy = mtx;
    IssueCommand0x19((int)&mtxCopy);
}
