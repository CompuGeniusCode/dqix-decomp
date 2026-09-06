#include <globaldefs.h>

struct Struct02030b7c;
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);

struct Data02108e40 {
    int f0;
    void* f4;
    int f8;
};
extern struct Data02108e40 data_02108e40;

// USA: func_0207a1f0
ARM int StoreField4IfGlobalActive0207a1f0(struct Struct02030b7c* arg) {
    if (data_02108e40.f8 == 0) return 0;
    data_02108e40.f4 = _ZNK6Script9Parameter8ToStringEv(arg);
    return 1;
}
