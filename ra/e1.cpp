#include <globaldefs.h>
extern "C" int cA(void);
extern "C" void gA(void*);
extern "C" void* dtorA(void*);
struct LocE { char b[0xac]; LocE(); ~LocE(); };
extern "C" int e1(void) { int r = 0; gA(0); return r; }
extern "C" int e2(void) { int r = 0; if (cA()) r = 0; gA(0); return r; }
extern "C" int e3(void) { LocE l; if (!cA()) return 0; gA(&l); return 0; }
extern "C" int e4(void* p) { int r = 0; gA(p); gA(p); return r; }
