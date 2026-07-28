#include <globaldefs.h>
struct D { char pad[8]; unsigned char* ptr; };
extern D dataX;
struct C7 { unsigned int low7:7; unsigned int rest:25; };
extern "C" void act(void);
extern "C" int tC(void* e) {
    C7* c = (C7*)((char*)e + 4);
    unsigned char thresh = dataX.ptr[0x11];
    unsigned int v = c->low7;
    if (thresh <= v) { act(); }
    return 0;
}
