#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov031_02218e2c(void* self, const char* key);

// USA: func_ov031_02218ed8
ARM int TryFindAndCopyNamedValue_02218ed8(void* self, const char* key, char* dest, int maxLen) {
    const char* value = (const char*)func_ov031_02218e2c(self, key);
    if (value == 0) return 0;
    if ((int)strlen(value) >= maxLen) return 0;
    strcpy(dest, value);
    return 1;
}
