#include <globaldefs.h>

struct SlotArray020d2eb8;
void StoreField0x3cArrayEntryAndFlush(struct SlotArray020d2eb8*, int, int);
void* ResolveOffsetOrPointerEntry(void*, int);
void PostEvent0x20(int, int);

// USA: func_020be4f4
ARM void DetachEntryAndPostRangeEvent0x20(int start, int length, void* base, int index) {
    if (start == (int)ResolveOffsetOrPointerEntry(base, index)) {
        StoreField0x3cArrayEntryAndFlush((struct SlotArray020d2eb8*)base, index, 0);
    }
    PostEvent0x20(start, start + length);
}
