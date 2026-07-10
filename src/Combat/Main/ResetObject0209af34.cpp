#include <globaldefs.h>
#include "std_library_functions.h"

struct ResetObject0209af34Struct {
    unsigned char data[0x1c8];
    int field_1c8;
    int field_1cc;
    int field_1d0;
};

// USA: func_0209af34
ARM void ResetObject0209af34(struct ResetObject0209af34Struct* obj) {
    obj->field_1c8 = -1;
    obj->field_1cc = 0;
    obj->field_1d0 = 0;
    memset(obj, 0, 0x1c8);
}
