#include <globaldefs.h>

struct Container02080fa8;
int SetEntryFlagById02080b40(void* obj, int id);
void SetEntryFirstField02080fa8(struct Container02080fa8* obj, int id, int value);

// USA: func_ov003_0215f5e8  (semantic: SetEntriesAndAlign_0215f5e8)
extern "C" ARM void func_ov003_0215f5e8(void* obj, int index, int count) {
    if (count <= 4) {
        return;
    }
    int aligned = count + 3;
    aligned = aligned & ~3u;
    SetEntryFlagById02080b40(obj, 0xd3);
    SetEntryFlagById02080b40(obj, 0xd4);
    SetEntryFlagById02080b40(obj, 0xd5);
    SetEntryFirstField02080fa8((struct Container02080fa8*)obj, 0xd4, index + 1);
    SetEntryFirstField02080fa8((struct Container02080fa8*)obj, 0xd5, aligned / 4);
}
