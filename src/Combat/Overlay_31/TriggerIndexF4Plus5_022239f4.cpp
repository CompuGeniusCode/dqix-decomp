#include <globaldefs.h>

extern "C" char* GetOffset400_02235c70(void);
int RegisterEntryAndCallback_02223998(int);

// USA: func_ov031_022239f4
ARM int TriggerIndexF4Plus5_022239f4(void) {
    return RegisterEntryAndCallback_02223998((unsigned char)GetOffset400_02235c70()[0xf4] + 5);
}
