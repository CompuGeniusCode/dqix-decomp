#include <globaldefs.h>
extern "C" int cA(void);
extern "C" void gA(void*);
struct LocE { char b[0xac]; LocE(); ~LocE(); };
extern "C" int e10(void) {
    int r = 0;
    LocE l;
    gA(&l);
    if (!cA()) return r;
    if (cA()) { gA(&l); r = 0; }
    return r;
}
extern "C" int e11(void) {
    int r = 0;
    LocE l;
    gA(&l);
    if (!cA()) return r;
    gA(&l);
    if (cA()) r = 0;
    return r;
}
extern "C" void* e12(void) {
    void* r = 0;
    LocE l;
    gA(&l);
    if (!cA()) return r;
    r = (void*)cA();
    gA(r);
    r = 0;
    return r;
}
