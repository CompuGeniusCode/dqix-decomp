#include <globaldefs.h>

struct S_cc758;
void InitStructField0x10To0xE(struct S_cc758* p);
extern "C" int func_020cc780(void* work, void* path, int flag, void* out);

struct PathWork020ccc7c { char data[0x48]; };
struct PathResult020ccc7c { unsigned int v[3]; };
extern PathResult020ccc7c data_0211172c;

#pragma optimize_for_size off
// USA: func_020ccc7c
ARM int ParsePathIntoGlobal020ccc7c(void* path) {
    struct PathWork020ccc7c work;
    struct PathResult020ccc7c result;
    InitStructField0x10To0xE((struct S_cc758*)&work);
    if (func_020cc780(&work, path, 0, &result) == 0) {
        return 0;
    }
    data_0211172c = result;
    return 1;
}
