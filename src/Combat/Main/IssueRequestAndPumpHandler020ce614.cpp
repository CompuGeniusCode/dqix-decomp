#include <globaldefs.h>
void StoreValueIfPtrNotNull(int, int*);

extern "C" void func_020ce234(void);
int RemapRequestTypeAndRunHandler(int, void(*)(void), int*);
extern void (*data_020f2298)(void);

// USA: func_020ce614
ARM int IssueRequestAndPumpHandler020ce614(int a) {
    int out;
    int r = RemapRequestTypeAndRunHandler(a, func_020ce234, &out);
    if (r != 0) return r;
    data_020f2298();
    return out;
}
