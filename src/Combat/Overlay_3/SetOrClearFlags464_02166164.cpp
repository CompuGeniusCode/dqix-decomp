#include <globaldefs.h>

struct SubFlags02166164 { char pad[0x400]; int flags; };
struct Outer02166164 { char pad[0x64]; SubFlags02166164 sub; };

// USA: func_ov003_02166164
ARM void SetOrClearFlags464_02166164(Outer02166164* obj, int set, int mask) {
    if (set) {
        obj->sub.flags |= mask;
    } else {
        obj->sub.flags &= ~mask;
    }
}
