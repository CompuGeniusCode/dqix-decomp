#include <globaldefs.h>

struct S02055080 {
    char pad[0x4];
    void* field4;
};

// USA: func_02055080
ARM void* GetField0x4OrNull(struct S02055080* p) {
    void* x = p->field4;
    return x != NULL ? x : NULL;
}
