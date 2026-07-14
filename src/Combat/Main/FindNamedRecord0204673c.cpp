#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0204673c
char* FindNamedRecord0204673c(char* records, char* rawPath) {
    if (records == NULL) {
        return NULL;
    }
    if (rawPath == NULL) {
        return NULL;
    }
    if (rawPath[0] == 0) {
        return NULL;
    }

    char* s = rawPath;
    char* name = rawPath;
    while (*s != 0) {
        if (*s == '/') {
            name = s + 1;
        }
        s++;
    }

    while (records[0] != 0) {
        if (strcmp(records, name) == 0) {
            return records;
        }
        records += *(int*)(records + 0x48);
    }
    return NULL;
}
