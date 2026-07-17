#include <globaldefs.h>

extern "C" void _Z23SaveAndClearDisplayModev();
extern "C" void _Z31TailCallDispatchType18_0223dffcv();
extern "C" void _Z17DispatchIfEquals1i(int);
extern "C" void func_ov031_0223d06c(void);
extern "C" void func_ov031_0223d7f4(void);
extern "C" void func_ov031_0223684c(void);
extern "C" void func_ov031_0223b870(void);
extern "C" void func_ov031_0223da0c(void);
extern "C" void func_ov031_0223c40c(void);
extern "C" void _Z35TailCallFreeGlobal02290d34_0223c040v();
extern "C" void func_ov031_0223b4d4(void);
extern "C" void func_ov031_0223e120(void);
extern "C" void _Z28DestroyMainAllocator0223cedcv();
extern "C" void func_ov031_0223de5c(void);

// USA: func_ov031_02227468
ARM void RunShutdownSequence_02227468(void) {
    _Z23SaveAndClearDisplayModev();
    *(unsigned int*)0x04001000 &= ~0x10000;
    _Z31TailCallDispatchType18_0223dffcv();
    _Z17DispatchIfEquals1i(1);
    func_ov031_0223d06c();
    func_ov031_0223d7f4();
    func_ov031_0223684c();
    func_ov031_0223b870();
    func_ov031_0223da0c();
    func_ov031_0223c40c();
    _Z35TailCallFreeGlobal02290d34_0223c040v();
    func_ov031_0223b4d4();
    func_ov031_0223e120();
    _Z28DestroyMainAllocator0223cedcv();
    func_ov031_0223de5c();
}
