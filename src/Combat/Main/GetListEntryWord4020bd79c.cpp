#include <globaldefs.h>

struct Entry020bd79c { int f0; int f4; int f8; int fc; };
struct EntryList020bd79c { int _0; int _4; int count; struct Entry020bd79c entries[1]; };
struct Holder020bd79c { char _pad[0x84]; struct EntryList020bd79c* list; };
extern struct Holder020bd79c* data_02110370;

// USA: func_020bd79c
ARM int GetListEntryWord4020bd79c(unsigned int index) {
    struct EntryList020bd79c* list = data_02110370->list;
    if (index >= (unsigned int)list->count) return 0;
    return list->entries[index].f4;
}
