#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov031_02218e2c  (semantic: FindNamedEntryValue_02218e2c)
#pragma optimize_for_size off
extern "C" ARM void* func_ov031_02218e2c(void* self, const char* key) {
	int i = 0;
	do {
		const char* name = *(const char**)((char*)self + i * 8 + 0x1000 + 0xa38);
		if (name == NULL) break;
		if (strcmp(key, name) == 0) {
			return *(void**)((char*)self + 0x1000 + i * 8 + 0xa3c);
		}
		i++;
	} while (i < 0x20);
	return NULL;
}
