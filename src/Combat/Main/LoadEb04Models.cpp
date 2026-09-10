#include <globaldefs.h>
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void RestoreVramAllocatorCursors(char* vramCursorState);
extern "C" void SaveVramAllocatorState(char* vramCursorState);

struct ModelNode;
extern "C" void func_020553ac(struct ModelNode* model);
extern "C" int func_020553ec(void* model, int typeId, void* alloc, void* fileData, unsigned int fileSize);

struct ModelNode {
    unsigned char unknown0[0x1ec];
    struct ModelNode* next;
};

struct ModelFileName { char name[12]; };
struct ModelFileNameTable { ModelFileName items[6]; };
extern const ModelFileNameTable strEb0400Chr;

struct ModelTypeIdTable { int items[6]; };
extern const ModelTypeIdTable data_020ee218;

struct ModelListHolder {
    char unknown0[0xa20];
    ModelNode* head;
    char unknowna24[0xa3c - 0xa24];
    unsigned char flagA3c;
};

// Pulls the five eb04 models out of the NARC it is handed and chains them onto the list at +0xa20.
// The name table at 0x020ee230 is "eb0400.chr", "eb0430.chr", "eb0440.chr", "eb0420.chr" and
// "eb0410.chr", followed by an empty sixth entry that ends the loop, paired with the type ids 0..4
// at 0x020ee218; each is copied into allocator memory, loaded through Object3D::LoadFromCHRArchive
// between RestoreVramAllocatorCursors and SaveVramAllocatorState, and the flag at +0xa3c is
// cleared. A node is the same 0x1f0-byte record func_02057de0 allocates for a .beff: func_020553ac
// puts an Object3D at +0x14 and the chain pointer sits at +0x1ec. The one caller is battle setup
// opening data/bin/btarc.nsarc, the only archive holding them; what they depict is not established.
extern "C" ARM int LoadEb04Models(ModelListHolder* holder, const void* narc, SafeAllocator* alloc, char* vramCursorState) {
    ModelTypeIdTable types;
    ModelFileNameTable names;
    ModelFileName* nameEntry;
    int* typeEntry;
    ModelNode* prev;

    holder->flagA3c = 0;
    holder->head = NULL;

    RestoreVramAllocatorCursors(vramCursorState);

    names = strEb0400Chr;
    types = data_020ee218;

    nameEntry = &names.items[0];
    typeEntry = &types.items[0];
    prev = NULL;

    while (nameEntry->name[0] != 0) {
        unsigned int fileSize;
        const void* fileData;
        if (GetFileInNarc(narc, nameEntry->name, &fileData, &fileSize, 0)) {
            ModelNode* model = (ModelNode*)alloc->Allocate(0x1f0);
            void* dataBuf = alloc->Allocate(fileSize);
            if (model != NULL && dataBuf != NULL) {
                memcpy(dataBuf, (void*)fileData, fileSize);
                func_020553ac((struct ModelNode*)model);
                if (func_020553ec(model, *typeEntry, alloc, dataBuf, fileSize) != 0) {
                    if (prev != NULL) {
                        prev->next = model;
                    } else {
                        holder->head = model;
                    }
                    prev = model;
                }
            }
        }
        nameEntry++;
        typeEntry++;
    }

    SaveVramAllocatorState(vramCursorState);
    return 1;
}
