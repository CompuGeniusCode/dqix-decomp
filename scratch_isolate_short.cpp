#include <globaldefs.h>

struct S { unsigned char pad[4]; unsigned short id; };

extern "C" void TakesShort(int id, short val);
extern "C" void Other(void);

ARM void CallerG(int a, S* s) {
    short v = s->id;
    TakesShort(a, v);
    Other();
}
