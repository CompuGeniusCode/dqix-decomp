#include <globaldefs.h>

struct Inner021e2bdc { short val; };
struct Ret021e2bdc { char pad2[2]; unsigned short flag; struct Inner021e2bdc* ptr; };

extern "C" struct Ret021e2bdc* func_ov023_021db4e4(void*);
extern "C" void func_ov023_021e2b5c(void*, int, short*, short*);

// USA: func_ov023_021e2bdc
ARM void ComputeShortPair_021e2bdc(void* a, int unused, short* out1, short* out2) {
    struct Ret021e2bdc* r = func_ov023_021db4e4(a);
    if (r != 0 && r->flag != 0 && r->ptr != 0) {
        short v = r->ptr->val;
        short a_val, b_val;
        func_ov023_021e2b5c(a, v, &a_val, &b_val);
        *out1 = a_val;
        *out2 = b_val;
    }
}
