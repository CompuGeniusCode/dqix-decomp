#include <globaldefs.h>

struct Event020da2fc {
    unsigned char pad[0xd];
    unsigned char flags;
};

extern "C" void func_020da8e0(Event020da2fc*);
extern "C" void func_020da31c(Event020da2fc*);

// USA: func_020da2fc
ARM void DispatchEvent020da2fc(Event020da2fc* e) {
    if (e->flags & 1) {
        func_020da8e0(e);
        return;
    }
    func_020da31c(e);
}
