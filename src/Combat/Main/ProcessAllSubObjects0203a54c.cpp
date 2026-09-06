#include <globaldefs.h>

struct Struct02047230 { unsigned char pad[0x88]; };
struct Container0203a54c {
    struct Struct02047230 arrayA[5];
    struct Struct02047230 arrayB[5];
};

void MaybeInvoke0204719c(struct Struct02047230* obj);

// USA: func_0203a54c
ARM void ProcessAllSubObjects0203a54c(struct Container0203a54c* c) {
    int i;
    for (i = 0; i < 5; i++) {
        MaybeInvoke0204719c(&c->arrayA[i]);
        MaybeInvoke0204719c(&c->arrayB[i]);
    }
}
