#include <globaldefs.h>

struct Struct02071be8 {
    void* field0;
    void* field4;
    unsigned short field8;
    unsigned short fielda;
};

// USA: func_02071be8
ARM void ClearListHeader(struct Struct02071be8* s) {
    s->field0 = NULL;
    s->field4 = NULL;
    s->field8 = 0;
    s->fielda = 0;
}
