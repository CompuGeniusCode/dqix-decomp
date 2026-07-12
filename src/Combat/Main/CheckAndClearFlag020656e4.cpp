#include <globaldefs.h>

extern void* GetGlobalPtr021075f4(void);

struct EntryList_203dce4;
struct Entry_203dce4;
extern struct Entry_203dce4* GetEntryUnlessFlag0x8000(struct EntryList_203dce4* list, int id);

struct Child02040af0;
extern void SetValueOnActiveChild02040af0(struct Child02040af0* obj, int value);

struct Struct_020409e0;
extern int GetDisplayValue020409e0(struct Struct_020409e0* obj);

struct Struct02040a20;
extern int GetOffset0x54FromFallbackChain(struct Struct02040a20* obj);

struct FlagHolder_020656e4 { char pad[0x9b6]; unsigned char flag; };

// USA: func_020656e4
ARM int CheckAndClearFlag020656e4(void* a) {
    if (!*(unsigned char*)((char*)a + 0x1000 + 0x9b6)) return 0;

    struct Entry_203dce4* entry = GetEntryUnlessFlag0x8000(
        (struct EntryList_203dce4*)GetGlobalPtr021075f4(),
        *(int*)((char*)a + 0x1000 + 0x838));
    if (entry == NULL) return 0;

    int result = 1;
    SetValueOnActiveChild02040af0((struct Child02040af0*)entry,
        *(int*)((char*)a + 0x1000 + 0x844));

    if (GetDisplayValue020409e0((struct Struct_020409e0*)entry) ==
        GetOffset0x54FromFallbackChain((struct Struct02040a20*)entry)) {
        ((struct FlagHolder_020656e4*)((char*)a + 0x1000))->flag = 0;
        result = 0;
    }
    return result;
}
