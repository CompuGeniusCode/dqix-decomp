#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void*);

struct SpawnedActor { int flags; };
struct SpawnedActorList { char pad[0xc]; struct SpawnedActor* actors[0x20]; };
extern "C" extern void* GetFieldObjectRegistry(void);
extern "C" extern struct SpawnedActor* GetActorSlot(struct SpawnedActorList* list, int id);
extern "C" int GetActorRecord(int* obj);
extern "C" void func_0203d004(void);
extern const char strStrSpr_021657d4[];

struct SpriteNameTable;
extern "C" int func_02040404(struct SpriteNameTable* container, const char* name);
struct SpriteSlotTable;
extern "C" void func_0204039c(struct SpriteSlotTable* obj, int index);

extern "C" void _ZN8Object3D7DestroyEv(unsigned char* obj);
struct Object3DState;
extern "C" void func_0204128c(struct Object3DState* obj);
extern "C" void func_02040504(int* obj);

struct SpawnedActorSlots;
extern "C" void func_0203dd10(SpawnedActorSlots* obj, unsigned int index, int value);

struct ActorSpawnRequest { int requestType; int targetActorId; int c; int unknownc; };
extern "C" void func_ov001_0215acb4(ActorSpawnRequest* p);

struct ActorSpawnRequestTable { char unknown0[4]; ActorSpawnRequest* requests; };
extern ActorSpawnRequestTable data_ov001_02165880;

typedef void* (*PassThroughStubFn)(void*);

// Handler for command 0x209 in ov001's {id, handler} table; its entry is the pair at
// 0x021651f8, and the table runs from about 0x02164d78 to the null handler at 0x021656e8. The
// operand is a TaggedValue that func_ov017_021d60f4 coerces to an int, and it indexes the 32
// slots of the global list behind GetFieldObjectRegistry - func_0203e524 measures a world
// distance to each of those slots.
// Tears the slot down whichever way it was built: a sprite slot is released from the named
// resource table by its "<name>.spr" resource name, a model slot gets Object3D::Destroy plus a
// state reset. func_0203d004 has an empty body, so calling it through a pointer-returning type
// hands its argument straight back - the resource table and the actor list are one object seen
// two ways.
// The slot bit is then cleared and every entry behind data_ov001_02165880 whose type word is 2
// or 6 and whose second word names this slot is reset to -1/-1/1/0. What those entries are is
// not established; ReleaseEventObjectGraphics is the handler for command 0x023c in the same table and
// reaches the same teardown through one of them.
extern "C" ARM int DespawnActor(void* self) {
    int id = func_ov017_021d60f4(self);
    if (id >= 0x20) {
        return 0;
    }
    struct SpawnedActorList* list = (struct SpawnedActorList*)GetFieldObjectRegistry();
    struct SpawnedActor* actor = GetActorSlot(list, id);
    if (actor == NULL) {
        return 0;
    }
    if (*(int*)((char*)actor + 0x14) != 0) {
        int actorRecord = GetActorRecord((int*)actor);
        PassThroughStubFn passThroughStub = (PassThroughStubFn)func_0203d004;
        struct SpriteNameTable* c = (struct SpriteNameTable*)passThroughStub(list);
        char spriteName[0x10];
        sprintf(spriteName, strStrSpr_021657d4, actorRecord + 4);
        int spriteIndex = func_02040404(c, spriteName);
        func_0204039c((struct SpriteSlotTable*)c, spriteIndex);
    } else {
        if (*(void**)((char*)actor + 0x18) != 0) {
            _ZN8Object3D7DestroyEv((unsigned char*)*(void**)((char*)actor + 0x18));
            func_0204128c((struct Object3DState*)*(void**)((char*)actor + 0x18));
        }
    }
    func_02040504((int*)actor);
    func_0203dd10((SpawnedActorSlots*)list, id, 0);

    if (data_ov001_02165880.requests != NULL) {
        for (int requestIndex = 0; requestIndex < 0x20; requestIndex++) {
            if (data_ov001_02165880.requests[requestIndex].requestType == 2 || data_ov001_02165880.requests[requestIndex].requestType == 6) {
                if (data_ov001_02165880.requests[requestIndex].targetActorId == id) {
                    func_ov001_0215acb4(&data_ov001_02165880.requests[requestIndex]);
                }
            }
        }
    }
    return 1;
}
