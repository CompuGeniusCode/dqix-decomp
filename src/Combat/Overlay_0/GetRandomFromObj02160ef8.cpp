#include <globaldefs.h>
#include "System/Random.h"

// USA: func_ov000_02160ef8
ARM struct Random* GetRandomFromObj02160ef8(unsigned char* obj) {
    return *(struct Random**)(obj + 0x29c);
}
