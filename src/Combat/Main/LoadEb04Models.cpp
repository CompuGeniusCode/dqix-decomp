#include <globaldefs.h>
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void RestoreVramAllocatorCursors(char* obj);
extern "C" void SaveVramAllocatorState(char* obj);

struct Obj020553ac;
extern "C" void func_020553ac(struct Obj020553ac* obj);
extern "C" int func_020553ec(void* obj, int typeId, void* alloc, void* fileData, unsigned int fileSize);

struct Node020d6d90 {
    unsigned char pad[0x1ec];
    struct Node020d6d90* next;
};

struct NameEntry020d6d90 { char name[12]; };
struct NamesTable020d6d90 { NameEntry020d6d90 items[6]; };
extern const NamesTable020d6d90 strEb0400Chr;

struct TypeTable020d6d90 { int items[6]; };
extern const TypeTable020d6d90 data_020ee218;

struct Obj020d6d90 {
    char pad0[0xa20];
    Node020d6d90* head;
    char pad1[0xa3c - 0xa24];
    unsigned char flagA3c;
};

// Pulls the five eb04 models out of the NARC it is handed and chains them onto the list at +0xa20.
// The name table at 0x020ee230 is "eb0400.chr", "eb0430.chr", "eb0440.chr", "eb0420.chr" and
// "eb0410.chr", paired with the type ids 0..4 at 0x020ee218; each is copied into allocator memory,
// loaded through Object3D::LoadFromCHRArchive between SaveVramAllocatorState and
// RestoreVramAllocatorCursors, and the flag at +0xa3c is cleared. The one caller is battle setup
// opening data/bin/btarc.nsarc, the only archive holding them; what they depict is not established.
extern "C" ARM int LoadEb04Models(Obj020d6d90* obj, const void* narc, SafeAllocator* alloc, char* pairTablesBuf) {
    TypeTable020d6d90 types;
    NamesTable020d6d90 names;
    NameEntry020d6d90* nameEntry;
    int* typeEntry;
    Node020d6d90* prev;

    obj->flagA3c = 0;
    obj->head = NULL;

    RestoreVramAllocatorCursors(pairTablesBuf);

    names = strEb0400Chr;
    types = data_020ee218;

    nameEntry = &names.items[0];
    typeEntry = &types.items[0];
    prev = NULL;

    while (nameEntry->name[0] != 0) {
        unsigned int fileSize;
        const void* fileData;
        if (GetFileInNarc(narc, nameEntry->name, &fileData, &fileSize, 0)) {
            Node020d6d90* node = (Node020d6d90*)alloc->Allocate(0x1f0);
            void* dataBuf = alloc->Allocate(fileSize);
            if (node != NULL && dataBuf != NULL) {
                memcpy(dataBuf, (void*)fileData, fileSize);
                func_020553ac((struct Obj020553ac*)node);
                if (func_020553ec(node, *typeEntry, alloc, dataBuf, fileSize) != 0) {
                    if (prev != NULL) {
                        prev->next = node;
                    } else {
                        obj->head = node;
                    }
                    prev = node;
                }
            }
        }
        nameEntry++;
        typeEntry++;
    }

    SaveVramAllocatorState(pairTablesBuf);
    return 1;
}
