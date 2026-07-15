#include <globaldefs.h>
#include "std_library_functions.h"

unsigned int GetBg1ScreenBaseAddr(void);

// USA: func_ov023_021dcd78
ARM void ClearBg1Screen_021dcd78(void) {
	memset((void*)GetBg1ScreenBaseAddr(), 0, 0x800);
}
