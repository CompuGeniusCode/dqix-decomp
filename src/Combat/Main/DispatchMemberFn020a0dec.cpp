#include <globaldefs.h>

struct DispatchObj020a0dec {
    int selector;
};

typedef void (DispatchObj020a0dec::*DispatchFn020a0dec)();

struct DispatchTable020a0dec {
    DispatchFn020a0dec fns[3];
};

extern const DispatchTable020a0dec data_020e8f08;

// USA: func_020a0dec
ARM void DispatchMemberFn020a0dec(DispatchObj020a0dec* obj) {
    DispatchTable020a0dec table = data_020e8f08;
    (obj->*table.fns[obj->selector])();
}
