#include <globaldefs.h>

struct Item02037af8 {
    char pad0[0x34];
    Item02037af8* next;
};

extern "C" void func_020c1840(void* p);

// USA: func_02037af8
ARM void AppendToList02037af8(void* owner, Item02037af8* item) {
    item->next = NULL;
    func_020c1840((char*)item + 4);
    Item02037af8* cur = *(Item02037af8**)((char*)owner + 0xa8);
    if (cur != NULL) {
        while (cur->next != NULL) cur = cur->next;
        cur->next = item;
        return;
    }
    *(Item02037af8**)((char*)owner + 0xa8) = item;
}
