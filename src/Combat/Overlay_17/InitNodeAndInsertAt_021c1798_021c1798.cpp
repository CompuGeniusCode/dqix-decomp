#include <globaldefs.h>
#include "Grotto/Overlay_17/Struct44C8.h"

extern "C" void func_ov017_021c17cc(void* obj);
struct Node02046a3c;
struct List02046a3c;
void InsertNodeAfterHead(struct List02046a3c* list, struct Node02046a3c* node);

// USA: func_ov017_021c1798
ARM void InitNodeAndInsertAt_021c1798_021c1798(Struct_ov017_44C8* self, unsigned char value) {
    func_ov017_021c17cc(*(void**)((char*)self + 0x3000 + 0xb54));
    (*(unsigned char**)((char*)self + 0x3000 + 0xb54))[0x1d] = value;
    InsertNodeAfterHead(*(struct List02046a3c**)((char*)self + 0x3000 + 0x6fc),
                         *(struct Node02046a3c**)((char*)self + 0x3000 + 0xb54));
}
