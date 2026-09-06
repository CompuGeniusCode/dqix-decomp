#include <globaldefs.h>
extern "C" int cA(void);
extern "C" void gA(void*);
struct LocE { char b[0xac]; LocE(); ~LocE(); };
extern "C" int e5(void) {
    LocE l;
    gA(&l);
    if (!cA()) return 0;
    gA(&l);
    return 0;
}
