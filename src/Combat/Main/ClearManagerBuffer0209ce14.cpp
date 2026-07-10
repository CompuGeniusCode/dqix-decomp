#include <globaldefs.h>

struct Obj0209e4a0;
void ClearEntryBuffer0209e4a0(struct Obj0209e4a0*);
void* GetGlobalManager0209dccc();

// USA: func_0209ce14
ARM int ClearManagerBuffer0209ce14() {
    struct Obj0209e4a0* mgr = (struct Obj0209e4a0*)GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    ClearEntryBuffer0209e4a0(mgr);
    return 1;
}
