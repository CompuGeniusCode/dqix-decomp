#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* FindEntryValueByName_02218e2c(int obj, const char* name);

// USA: func_ov031_02218ed8
ARM int CopyEntryIfFits_02218ed8(int obj, const char* name, char* buf, int maxlen) {
    void* entry = FindEntryValueByName_02218e2c(obj, name);
    if (entry == 0) {
        return 0;
    }
    int len = strlen((char*)entry);
    if (len >= maxlen) {
        return 0;
    }
    strcpy(buf, (char*)entry);
    return 1;
}
