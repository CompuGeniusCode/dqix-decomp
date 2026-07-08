#include <globaldefs.h>

struct S3f58 {
    char unk[0x1a8];
    int field1a8;
    int field1ac;
};

// USA: func_02053f58
ARM void GetFields1a8And1ac(struct S3f58* obj, int* out1, int* out2) {
    *out1 = obj->field1a8;
    *out2 = obj->field1ac;
}
