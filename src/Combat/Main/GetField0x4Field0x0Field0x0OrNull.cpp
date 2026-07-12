#include <globaldefs.h>

struct S02055080;
void* GetField0x4Field0x0OrNull(struct S02055080* obj);

// USA: func_02055168
ARM int GetField0x4Field0x0Field0x0OrNull(struct S02055080* obj) {
    void* x = GetField0x4Field0x0OrNull(obj);
    if (x == NULL) return 0;
    return *(int*)x;
}
