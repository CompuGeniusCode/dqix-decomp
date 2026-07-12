#include <globaldefs.h>
void StoreValueIfPtrNotNull(int, int*);

extern "C" void func_020ce234(void);
extern "C" int func_020ce5b0(int a, void (*b)(void), int *c);
extern void (*data_020f2298)(void);

// USA: func_020ce614
ARM int IssueRequestAndPumpHandler020ce614(int a) {
    int out;
    int r = func_020ce5b0(a, func_020ce234, &out);
    if (r != 0) return r;
    data_020f2298();
    return out;
}
