#include <globaldefs.h>

struct Node0218466c {
    unsigned short id;
};

// USA: func_ov011_0218466c
ARM void* FindNodeById0218466c(void* obj, unsigned short id) {
    char* p = (char*)obj + 0x20;
    while (p) {
        if (((struct Node0218466c*)p)->id == id) return p;
        p = *(char**)(p + 0x78);
    }
    return 0;
}
