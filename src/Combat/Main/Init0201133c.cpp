#include <globaldefs.h>
#include "std_library_functions.h"

struct Pair0209a338;
void ClearFirstTwoWords0209a338(Pair0209a338* p);
extern "C" void func_0209a3dc(void* a, void* b);

// USA: func_0201133c
ARM void Init0201133c(char* obj) {
    memset(obj + 0x5734, 0, 0x570);
    ClearFirstTwoWords0209a338((Pair0209a338*)(obj + 0x572c));
    func_0209a3dc(obj + 0x572c, obj + 0x5734);
}
