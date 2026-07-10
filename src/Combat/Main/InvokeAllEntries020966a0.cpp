#include <globaldefs.h>

struct Struct02047230;
void MaybeInvoke0204719c(struct Struct02047230* obj);

struct Entry020966a0 {
    unsigned char data[0x88];
};

// USA: func_020966a0
ARM void InvokeAllEntries020966a0(struct Entry020966a0* arr) {
    int i;
    for (i = 0; i < 4; i++) {
        MaybeInvoke0204719c((struct Struct02047230*)&arr[i]);
    }
}
