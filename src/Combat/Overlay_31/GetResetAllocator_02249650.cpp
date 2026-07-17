#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern SafeAllocator data_ov031_02291e3c;
SafeAllocator* ResetAndReturnAllocator(SafeAllocator* alloc);

// USA: func_ov031_02249650
ARM SafeAllocator* GetResetAllocator_02249650(void) {
	return ResetAndReturnAllocator((SafeAllocator*)&data_ov031_02291e3c);
}
