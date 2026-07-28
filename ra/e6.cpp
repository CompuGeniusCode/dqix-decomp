#include <globaldefs.h>
extern "C" int cA(void);
extern "C" void gA(void*);
struct LocE { char b[0xac]; LocE(); ~LocE(); };
extern "C" int e7(void) {
    int r = 0;
    LocE l;
    gA(&l);
    if (!cA()) return r;
    gA(&l);
    r = 0;
    return r;
}
extern "C" int e8(void) {
    int r;
    LocE l;
    gA(&l);
    if (!cA()) { r = 0; return r; }
    gA(&l);
    r = 0;
    return r;
}
extern "C" int e9(void) {
    int r = 0;
    LocE l;
    gA(&l);
    if (cA()) { gA(&l); r = 0; }
    return r;
}
