#include <globaldefs.h>

extern int data_ov031_02290fa4;
struct RefNode020c80f8;
void ReleaseNodeRef020c80f8(RefNode020c80f8 *node);

// USA: func_ov031_0223fa20
ARM void ReleaseData02290fa4_0223fa20(void) {
    ReleaseNodeRef020c80f8((RefNode020c80f8*)&data_ov031_02290fa4);
}
