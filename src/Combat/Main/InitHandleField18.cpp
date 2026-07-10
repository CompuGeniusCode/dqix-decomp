#include <globaldefs.h>

int DisableSubObjExtPalette(void);
extern int data_02111240[];

// USA: func_020c63e4
ARM void InitHandleField18(void) {
    data_02111240[6] = DisableSubObjExtPalette();
}
