#include <globaldefs.h>
#include "std_library_functions.h"

extern void* data_020fe9a4;

// USA: func_02029060
ARM void ClearBuffer02029060() {
    if (data_020fe9a4 == NULL) return;
    memset(data_020fe9a4, 0, 0x6000);
}
