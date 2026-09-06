#include <globaldefs.h>

struct NitroVM;
int NitroVM_CancelCommand(struct NitroVM*);

// USA: func_020c0100
ARM int TailForwardToField0x5c020c0100(void* obj) {
    return NitroVM_CancelCommand((struct NitroVM*)((char*)obj + 0x5c));
}
