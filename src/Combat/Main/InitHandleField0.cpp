#include <globaldefs.h>

int DisableSubBgExtPalette(void);
extern int data_02111240[];

// USA: func_020c6328
ARM void InitHandleField0(void) {
    data_02111240[0] = DisableSubBgExtPalette();
}
