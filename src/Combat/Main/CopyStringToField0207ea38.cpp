#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_020b752c(void* dst, void* src);

struct Struct0207ea38 {
    char unk[0x54];
    void* field_54;
};

// USA: func_0207ea38
ARM int CopyStringToField0207ea38(struct Struct0207ea38* obj, char* str) {
    char buf[0x10];
    if (obj->field_54 == NULL) return -1;
    memset(buf, 0, 0x10);
    strcpy(buf, str);
    return func_020b752c((char*)obj->field_54 + 0x40, buf);
}
