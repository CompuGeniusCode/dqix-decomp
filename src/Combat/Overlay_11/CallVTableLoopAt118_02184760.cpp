#include <globaldefs.h>

struct ListHead021f69ec;
extern "C" ARM void func_ov023_021f69ec(struct ListHead021f69ec* head);

// USA: func_ov011_02184760  (semantic: CallVTableLoopAt118_02184760)
extern "C" ARM void func_ov011_02184760(void* obj) {
    func_ov023_021f69ec((struct ListHead021f69ec*)((char*)obj + 0x118));
}
