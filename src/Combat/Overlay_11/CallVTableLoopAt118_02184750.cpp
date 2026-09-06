#include <globaldefs.h>

struct ListHead021f69bc;
extern "C" ARM void func_ov023_021f69bc(struct ListHead021f69bc* head);

// USA: func_ov011_02184750  (semantic: CallVTableLoopAt118_02184750)
extern "C" ARM void func_ov011_02184750(void* obj) {
    func_ov023_021f69bc((struct ListHead021f69bc*)((char*)obj + 0x118));
}
