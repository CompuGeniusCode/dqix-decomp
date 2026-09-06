#include <globaldefs.h>

int GetListEntryWord4020bd79c(unsigned int index);
extern "C" int func_020bd7c4(unsigned int index, void* buf, int size, int flag);
struct Obj020bda58;
extern void* AllocateAndLinkEntry020bda58(struct Obj020bda58* obj, unsigned int size, int a2, int a3, int a4);
void CleanCacheRange(const void* addr, unsigned int size);

// USA: func_020be09c  (semantic: AllocateAndFillListEntry020be09c)
#pragma optimize_for_size off
extern "C" ARM void* func_020be09c(unsigned int index, int a2, int a3, int a4, struct Obj020bda58* obj) {
    unsigned int listEntry = GetListEntryWord4020bd79c(index);
    if (!listEntry) {
        return 0;
    }
    if (!obj) {
        return 0;
    }
    void* newEntry = AllocateAndLinkEntry020bda58(obj, listEntry + 0x20, a2, a3, a4);
    if (!newEntry) {
        return 0;
    }
    if (func_020bd7c4(index, newEntry, listEntry, 0) != (int)listEntry) {
        return 0;
    }
    CleanCacheRange(newEntry, listEntry);
    return newEntry;
}
