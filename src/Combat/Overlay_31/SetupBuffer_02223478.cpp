#include <globaldefs.h>
#include "std_library_functions.h"

extern unsigned char GetField0_02227548(void);
extern unsigned char data_ov031_02250bb0;
extern unsigned char data_ov031_02248990;

// USA: func_ov031_02223478
ARM void* SetupBuffer_02223478(const unsigned char* name) {
	strncpy((char*)&data_ov031_02250bb0, (const char*)name, 0x3f);
	if (name[5] == 0x78) return &data_ov031_02250bb0;
	unsigned char field0 = GetField0_02227548();
	if (name[5] == 0x79 && field0 != 0) return &data_ov031_02250bb0;
	(&data_ov031_02250bb0)[5] = (&data_ov031_02248990)[field0];
	return &data_ov031_02250bb0;
}
