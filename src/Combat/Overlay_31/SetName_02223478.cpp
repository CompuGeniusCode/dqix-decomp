#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" unsigned char GetField0_02227548(void);

struct Struct02223478 {
	char name[5];
	char field5;
};

extern Struct02223478 data_ov031_02250bb0;
extern unsigned char data_ov031_02248990[];

// USA: func_ov031_02223478
ARM Struct02223478* SetName_02223478(const unsigned char *name) {
	strncpy((char*)&data_ov031_02250bb0, (const char*)name, 0x3f);
	if (name[5] == 'x') {
		return &data_ov031_02250bb0;
	}
	unsigned char field0 = GetField0_02227548();
	if (name[5] == 'y') {
		if (field0 != 0) {
			return &data_ov031_02250bb0;
		}
	}
	data_ov031_02250bb0.field5 = data_ov031_02248990[field0];
	return &data_ov031_02250bb0;
}
