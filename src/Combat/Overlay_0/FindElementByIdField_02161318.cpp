#include <globaldefs.h>

// USA: func_ov000_02161318  (semantic: FindElementByIdField_02161318)
extern "C" ARM void* func_ov000_02161318(void* obj, int id) {
    int valid = (id >= 0 && id <= 3) ? 1 : 0;
    if (valid) {
        for (int i = 0; i < 4; i++) {
            int cur = *(int*)((char*)obj + i * 0x448 + 0x9a4);
            if (id == cur) {
                return (char*)obj + 0x958 + i * 0x448;
            }
        }
    }
    return 0;
}
