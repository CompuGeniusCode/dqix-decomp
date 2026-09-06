#include <globaldefs.h>

// USA: func_02039830
ARM void CopyByteField0x253To0x252(void* obj) {
    *(unsigned char*)((char*)obj + 0x252) = *(unsigned char*)((char*)obj + 0x253);
}
