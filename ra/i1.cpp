#include <globaldefs.h>
extern "C" int f(int);
extern "C" void sink(int);
struct N1 { char pad[0x5c]; short v; int Slot() const { return v * 6; } };
static inline int slotS(const short* p){ return p[0]*6; }
inline int slotI(const short* p){ return p[0]*6; }
__inline int slotU(const short* p){ return p[0]*6; }
#define SLOTM(p) ((p)[0]*6)
extern "C" int i1(short* p){ int A=f(1); int B=((N1*)p)->Slot(); sink(0);sink(A);sink(B);sink(A+B); return 0; }
extern "C" int i2(short* p){ int A=f(1); int B=slotS(p+3);   sink(0);sink(A);sink(B);sink(A+B); return 0; }
extern "C" int i3(short* p){ int A=f(1); int B=slotI(p+3);   sink(0);sink(A);sink(B);sink(A+B); return 0; }
extern "C" int i4(short* p){ int A=f(1); int B=slotU(p+3);   sink(0);sink(A);sink(B);sink(A+B); return 0; }
extern "C" int i5(short* p){ int A=f(1); int B=SLOTM(p+3);   sink(0);sink(A);sink(B);sink(A+B); return 0; }
