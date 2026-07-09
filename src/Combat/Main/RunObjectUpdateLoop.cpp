#include <globaldefs.h>

struct VirtualObject0202f744 {
    virtual void Update();
};

// USA: func_0202f744
ARM void RunObjectUpdateLoop(struct VirtualObject0202f744* obj) {
    for (;;) {
        obj->Update();
    }
}
