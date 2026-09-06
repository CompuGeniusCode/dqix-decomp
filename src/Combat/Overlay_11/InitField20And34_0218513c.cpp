#include <globaldefs.h>

struct Struct02047230 {
    unsigned char pad[0x84];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
};
struct NameTable02048080 {
    int count;
    void* entries;
};

void MaybeInvoke0204719c(struct Struct02047230* obj);
void ClearNameTable(struct NameTable02048080* table);

// USA: func_ov011_0218513c
ARM void* InitField20And34_0218513c(void* obj) {
    MaybeInvoke0204719c((struct Struct02047230*)((char*)obj + 0x20));
    ClearNameTable((struct NameTable02048080*)((char*)obj + 0x34));
    return obj;
}
