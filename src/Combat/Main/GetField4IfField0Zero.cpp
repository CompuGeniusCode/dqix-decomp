#include <globaldefs.h>

struct Struct02030b7c {
    int field0;
    void* field4;
};

// USA: func_02030b7c
ARM void* GetField4IfField0Zero(struct Struct02030b7c* s) {
    switch (s->field0) {
        case 0:
            return s->field4;
        default:
            return 0;
    }
}
