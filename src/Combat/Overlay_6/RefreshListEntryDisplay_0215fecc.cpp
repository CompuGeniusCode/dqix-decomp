#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

int GetData02104304Field4();
extern "C" int func_0202fdd0(void* obj, int key);
struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);
extern "C" void func_02076080(void* a, void* b, int c, int d);
extern "C" void func_020301c8(void* list, int key);

// USA: func_ov006_0215fecc  (semantic: RefreshListEntryDisplay_0215fecc)
extern "C" ARM int func_ov006_0215fecc(char* self) {
    void* list = (void*)GetData02104304Field4();
    if (!func_0202fdd0(list, *(int*)(self + 0x428))) {
        return 0;
    }
    char* base = *(char**)(self + 0xc);
    SafeAllocator* alloc = (SafeAllocator*)(base + 0xb4);
    alloc->Reset();
    int out1 = 0;
    int out2 = 0;
    GetListEntryValues0202fec8((struct List0202fec8*)list, *(int*)(self + 0x428), &out1, &out2);
    func_02076080(self + 0x3b8, alloc, out1, out2);
    func_020301c8(list, *(int*)(self + 0x428));
    *(int*)(self + 0x428) = -1;
    return 1;
}
