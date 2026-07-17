#include <globaldefs.h>

extern "C" char* GetOffset400_02235c70(void);
int RegisterEntryAndCallback_02223998(int);

// USA: func_ov031_02223a0c
ARM int TriggerIndexF4Plus2_02223a0c(void) {
    return RegisterEntryAndCallback_02223998((unsigned char)GetOffset400_02235c70()[0xf4] + 2);
}
