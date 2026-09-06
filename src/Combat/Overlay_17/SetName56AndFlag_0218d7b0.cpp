#include <globaldefs.h>
#include "std_library_functions.h"

void ClearFields0to5_0218d7fc(unsigned char* obj);
void* GetData02153637(void);
void StoreInFirstEmptySlot(unsigned char* base, unsigned char val);

// USA: func_ov017_0218d7b0
ARM void SetName56AndFlag_0218d7b0(unsigned char* obj, char* name) {
	if (!name) return;
	ClearFields0to5_0218d7fc(obj + 0x56 + 0x4300);
	memcpy(obj + 0x56 + 0x4300, name, 6);
	obj[0x4000 + 0x35b] = 1;
	StoreInFirstEmptySlot((unsigned char*)GetData02153637(), 1);
}
