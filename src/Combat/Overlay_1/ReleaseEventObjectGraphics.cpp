#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void*);

struct Entry_203dce4 { int flags; };
struct EntryList_203dce4 { char unknown0[0xc]; struct Entry_203dce4* entries[0x20]; };
extern "C" extern void* GetFieldObjectRegistry(void);
extern "C" extern struct Entry_203dce4* GetActorSlot(struct EntryList_203dce4* list, int id);
extern "C" int GetActorRecord(int* target);
extern "C" void func_0203d004(void);
extern const char strStrSpr_021657d4[];

struct NamedResourceTable;
extern "C" int func_02040404(struct NamedResourceTable* container, const char* name);
struct ResourceSlotTable;
extern "C" void func_0204039c(struct ResourceSlotTable* target, int index);

extern "C" void _ZN8Object3D7DestroyEv(unsigned char* target);
struct Object3DState;
extern "C" void func_0204128c(struct Object3DState* target);
extern "C" void func_02040504(int* target);

struct ActorSlotList;
extern "C" void func_0203dd10(ActorSlotList* target, unsigned int index, int value);

struct EventObjectTableEntry { int type; int actorSlot; char unknown8[8]; };
struct EventObjectTable { char unknown0[4]; struct EventObjectTableEntry* table; };
extern EventObjectTable data_ov001_02165880;

typedef void* (*IdentityStubFn)(void*);

// Frees the graphics an event object slot is holding and gives the slot back. It only acts when the
// object's table row has type 2 or 6, and what those two distinguish is not established. The choice
// between releasing a named sprite, looked up as "<name>.spr" in the resource container, and
// destroying an Object3D outright is made by the list entry's +0x14. The entry is then reset and
// its pointer cleared out of the registry's 32-entry slot table at +0xc, the same table GetActorSlot
// read it from. Reached only through the dispatch table entry at 0x0216555c, never called directly.
extern "C" ARM int ReleaseEventObjectGraphics(void* self) {
    int id = func_ov017_021d60f4(self);
    if (id < 0) {
        return 0;
    }
    if (data_ov001_02165880.table[id].type != 6 && data_ov001_02165880.table[id].type != 2) {
        return 0;
    }

    void* ctxRaw = GetFieldObjectRegistry();
    struct EntryList_203dce4* list = (struct EntryList_203dce4*)ctxRaw;
    struct Entry_203dce4* entry = GetActorSlot(list, data_ov001_02165880.table[id].actorSlot);
    if (entry == NULL) {
        return 0;
    }

    if (*(int*)((char*)entry + 0x14) != 0) {
        int field = GetActorRecord((int*)entry);
        IdentityStubFn stub = (IdentityStubFn)func_0203d004;
        struct NamedResourceTable* spriteContainer = (struct NamedResourceTable*)stub(ctxRaw);
        char buf[0x10];
        sprintf(buf, strStrSpr_021657d4, field + 4);
        int idx = func_02040404(spriteContainer, buf);
        func_0204039c((struct ResourceSlotTable*)spriteContainer, idx);
    } else {
        if (*(void**)((char*)entry + 0x18) != 0) {
            _ZN8Object3D7DestroyEv((unsigned char*)*(void**)((char*)entry + 0x18));
            func_0204128c((struct Object3DState*)*(void**)((char*)entry + 0x18));
        }
    }

    func_02040504((int*)entry);
    func_0203dd10((ActorSlotList*)list, data_ov001_02165880.table[id].actorSlot, 0);
    return 1;
}
