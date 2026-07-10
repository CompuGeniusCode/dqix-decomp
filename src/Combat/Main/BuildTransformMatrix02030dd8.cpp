#include <globaldefs.h>

struct MtxFx43_02030dd8 { unsigned int v[12]; };

int GetTableEntryEven02030c68(int);
int GetTableEntryOdd02030c9c(int);
extern "C" struct MtxFx43_02030dd8 func_020c19b8(int a, int b);

// USA: func_02030dd8
ARM void BuildTransformMatrix02030dd8(struct MtxFx43_02030dd8* dst, void* src) {
    *dst = func_020c19b8(GetTableEntryEven02030c68((int)src), GetTableEntryOdd02030c9c((int)src));
}
