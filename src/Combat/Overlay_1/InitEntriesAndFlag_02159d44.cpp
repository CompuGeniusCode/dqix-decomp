#include <globaldefs.h>

struct S02159d44 { void* entries; int count; char pad[0x88]; int field144; };

extern "C" void func_ov001_02159d9c(struct S02159d44* a);
extern "C" void func_ov001_02159cfc(void* entry);

// USA: func_ov001_02159d44
ARM int InitEntriesAndFlag_02159d44(struct S02159d44* a, void* entries, int count) {
    a->entries = entries;
    a->count = count;
    func_ov001_02159d9c(a);
    if (a->entries != NULL && a->count > 0) {
        for (int i = 0; i < a->count; i++) {
            func_ov001_02159cfc((char*)a->entries + i * 0x40);
        }
    }
    a->field144 = 0x1000;
    return 0x1000;
}
