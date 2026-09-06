#include <globaldefs.h>
#include "std_library_functions.h"

extern char data_020ef6bc;

extern "C" {
    int func_020420e8(char*, int);
}

// USA: func_02026428
// Copies the supplied string (or a default string when none is given) into a
// buffer at +0x5b4, then records the result of func_020420e8 at +0xbe4.
ARM void CopyStringOrDefault02026428(void* obj, const char* name) {
    if (name == NULL)
        strcpy((char*)obj + 0x5b4, &data_020ef6bc);
    else
        strcpy((char*)obj + 0x5b4, name);
    *(int*)((char*)obj + 0xbe4) = func_020420e8((char*)obj + 0x5b4, 0);
}
