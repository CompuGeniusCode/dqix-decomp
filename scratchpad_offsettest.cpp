#include <globaldefs.h>

void CopyVec3(int* dst, int* src);

struct Elem0x400 { char pad[0x400]; };
struct Container { char pad0[8]; struct Elem0x400 arr[2]; };

ARM void Test(struct Container* c, int* local) {
    CopyVec3(local, (int*)((char*)&c->arr[1] + 0x44));
}
