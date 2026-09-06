#include <globaldefs.h>

extern "C" void func_0205addc(void* obj, unsigned char idx);

struct Header0205ae8c {
    char pad[4];
    unsigned short count;
};

// USA: func_0205ae8c  (semantic: CallForEachEntry_0205ae8c)
extern "C" ARM void func_0205ae8c(void* obj) {
    unsigned short count;
    struct Header0205ae8c* h;
    unsigned short i;

    h = *(struct Header0205ae8c**)((char*)obj + 0x3c);
    if (h == 0) {
        return;
    }
    count = h->count;
    i = 0;
    while (i < count) {
        func_0205addc(obj, (unsigned char)i);
        i++;
    }
}
