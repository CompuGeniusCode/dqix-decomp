#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov031_02218e2c
ARM void* FindEntryValueByName_02218e2c(int obj, const char* name) {
    int i = 0;
    while (1) {
        char* entryName = *(char**)((char*)obj + (i << 3) + 0x1000 + 0xa38);
        if (entryName == 0) {
            break;
        }
        if (strcmp(name, entryName) == 0) {
            return *(void**)(obj + (i << 3) + 0x1000 + 0xa3c);
        }
        i++;
        if (i >= 0x20) {
            break;
        }
    }
    return 0;
}
