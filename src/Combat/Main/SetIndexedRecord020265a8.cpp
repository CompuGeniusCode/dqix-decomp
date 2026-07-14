#include <globaldefs.h>
#include "std_library_functions.h"

extern char data_020ef6d0;
extern char data_020ef6ca;
extern char data_020ef6d3;

// USA: func_020265a8
ARM void SetIndexedRecord020265a8(char* obj, int index, const char* name, int extra) {
    if ((unsigned int)index >= 3) return;
    if (name != NULL && *name != 0) {
        strcpy(obj + 0x5fc + index * 0x48, name);
        sprintf(obj + 0x6d4 + index * 8, &data_020ef6d0, extra);
    } else {
        strcpy(obj + 0x5fc + index * 0x48, &data_020ef6ca);
        strcpy(obj + 0x6d4 + index * 8, &data_020ef6d3);
    }
}
