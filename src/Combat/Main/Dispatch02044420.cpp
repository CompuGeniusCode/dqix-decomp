#include <globaldefs.h>
#include "std_library_functions.h"

bool IsHighByteFF02044494(void* obj, void* src);

// USA: func_02044420
ARM int Dispatch02044420(void* obj, void* src) {
    unsigned short buf;
    int result = 0;
    memcpy(&buf, src, 2);
    if (!IsHighByteFF02044494(obj, &buf)) {
        return 0;
    }
    switch (buf) {
    case 0xff20:
    case 0xff21:
    case 0xff23:
    case 0xff24:
        result = 1;
        break;
    case 0xff22:
    case 0xff25:
        result = 2;
        break;
    }
    return result;
}
