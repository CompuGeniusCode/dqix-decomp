#include <globaldefs.h>

struct InitStruct02158828;
void InitEntry02158828(struct InitStruct02158828* obj);

struct Obj0x30_02158e8c {
    char pad[0x30];
    int f30;
    int f34;
};

// USA: func_ov001_02158e8c  (semantic: DispatchInitByMode_02158e8c)
extern "C" ARM void* func_ov001_02158e8c(struct Obj0x30_02158e8c* obj, struct InitStruct02158828* p1, int mode) {
    if (p1 == NULL) {
        return NULL;
    }
    void* result = *(void**)((char*)p1 + 0x48);
    switch (mode) {
        case 0:
            if (obj->f30 == 0) {
                InitEntry02158828(p1);
            }
            break;
        case 1:
            if (obj->f34 == 0) {
                InitEntry02158828(p1);
            }
            break;
        case 2:
            InitEntry02158828(p1);
            break;
        default:
            break;
    }
    return result;
}
