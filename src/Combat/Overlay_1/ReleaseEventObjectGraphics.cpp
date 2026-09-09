#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void*);

struct Entry_203dce4 { int flags; };
struct EntryList_203dce4 { char pad[0xc]; struct Entry_203dce4* entries[0x20]; };
extern "C" extern void* func_0203cf4c(void);
extern "C" extern struct Entry_203dce4* func_0203dce4(struct EntryList_203dce4* list, int id);
extern "C" int func_02040528(int* obj);
extern "C" void func_0203d004(void);
extern const char strStrSpr_021657d4[];

struct Container02040404;
extern "C" int func_02040404(struct Container02040404* container, const char* name);
struct Container0204039c;
extern "C" void func_0204039c(struct Container0204039c* obj, int index);

extern "C" void _ZN8Object3D7DestroyEv(unsigned char* obj);
struct State02041244;
extern "C" void func_0204128c(struct State02041244* obj);
extern "C" void func_02040504(int* obj);

struct SlotArray0203dd10;
extern "C" void func_0203dd10(SlotArray0203dd10* obj, unsigned int index, int value);

struct TableEntry_02161754 { int type; int field4; char pad8[8]; };
struct DataOv001_02161754 { char pad0[4]; struct TableEntry_02161754* table; };
extern DataOv001_02161754 data_ov001_02165880;

typedef void* (*EmptyStubFn_02161754)(void*);

// Frees the graphics an event object slot is holding and gives the slot back. It only acts when the
// object's table row has type 2 or 6, and what those two distinguish is not established. The choice
// between releasing a named sprite, looked up as "<name>.spr" in the resource container, and
// destroying an Object3D outright is made by the list entry's +0x14. The entry is then reset and its
// bit cleared in the 32-slot mask. Reached only through the dispatch table entry at 0x0216555c,
// never called directly.
extern "C" ARM int ReleaseEventObjectGraphics(void* self) {
    int id = func_ov017_021d60f4(self);
    if (id < 0) {
        return 0;
    }
    if (data_ov001_02165880.table[id].type != 6 && data_ov001_02165880.table[id].type != 2) {
        return 0;
    }

    void* ctxRaw = func_0203cf4c();
    struct EntryList_203dce4* list = (struct EntryList_203dce4*)ctxRaw;
    struct Entry_203dce4* entry = func_0203dce4(list, data_ov001_02165880.table[id].field4);
    if (entry == NULL) {
        return 0;
    }

    if (*(int*)((char*)entry + 0x14) != 0) {
        int field = func_02040528((int*)entry);
        EmptyStubFn_02161754 stub = (EmptyStubFn_02161754)func_0203d004;
        struct Container02040404* c = (struct Container02040404*)stub(ctxRaw);
        char buf[0x10];
        sprintf(buf, strStrSpr_021657d4, field + 4);
        int idx = func_02040404(c, buf);
        func_0204039c((struct Container0204039c*)c, idx);
    } else {
        if (*(void**)((char*)entry + 0x18) != 0) {
            _ZN8Object3D7DestroyEv((unsigned char*)*(void**)((char*)entry + 0x18));
            func_0204128c((struct State02041244*)*(void**)((char*)entry + 0x18));
        }
    }

    func_02040504((int*)entry);
    func_0203dd10((SlotArray0203dd10*)list, data_ov001_02165880.table[id].field4, 0);
    return 1;
}
