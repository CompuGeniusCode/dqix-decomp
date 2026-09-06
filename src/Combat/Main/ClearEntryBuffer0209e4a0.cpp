#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj0209e4a0 {
    unsigned char pad[0x98];
    int count;
    unsigned char buffer[0x400];
};

// USA: func_0209e4a0
ARM void ClearEntryBuffer0209e4a0(struct Obj0209e4a0* obj) {
    obj->count = 0;
    memset(obj->buffer, 0, 0x400);
}
