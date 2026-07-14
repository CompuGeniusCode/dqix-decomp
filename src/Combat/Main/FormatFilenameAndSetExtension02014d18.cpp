#include <globaldefs.h>
#include "std_library_functions.h"

extern const char data_020ef1de[];
extern const char data_020ef1e6[];

// USA: func_02014d18
ARM void FormatFilenameAndSetExtension02014d18(int id, char* ext, char* buffer) {
    sprintf(buffer, data_020ef1de, id);
    char* dot = strrchr(buffer, '.');
    if (dot != NULL) {
        strcpy(dot + 1, ext);
    } else {
        strcat(buffer, data_020ef1e6);
        strcat(buffer, ext);
    }
}
