#include <globaldefs.h>

// USA: func_ov000_02171674
ARM int GetBoundedField156_02171674(void* obj, int index) {
    if (index < 0 || index >= 0x42) return 0;
    return *(int*)((char*)obj + 0x9c + (index << 2));
}
