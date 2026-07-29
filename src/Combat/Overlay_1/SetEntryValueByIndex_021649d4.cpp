#include <globaldefs.h>

struct Entry021649d4 { int type; char pad[8]; void* ptr; };
struct IntField0x64_020377c4;
void SetIntAt0x64(IntField0x64_020377c4* obj, int value);

// USA: func_ov001_021649d4  (semantic: SetEntryValueByIndex_021649d4)
extern "C" ARM int func_ov001_021649d4(Entry021649d4* arr, int idx, int value) {
    if (idx < 0 || idx >= 0x20) {
        return 0;
    }
    int type = arr[idx].type;
    Entry021649d4* entry = &arr[idx];
    if (type != 1) {
        goto fail;
    }
    {
        void* ptr = entry->ptr;
        if (ptr == NULL) {
            return 0;
        }
        SetIntAt0x64((IntField0x64_020377c4*)ptr, value);
        return 1;
    }
fail:
    return 0;
}
