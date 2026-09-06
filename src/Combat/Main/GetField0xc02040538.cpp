#include <globaldefs.h>

struct S02040538 {
    char pad[0xc];
    void* field0xc;
};

// USA: func_02040538
ARM void* GetField0xc02040538(struct S02040538* p) {
    return p->field0xc;
}
