#include <globaldefs.h>

struct Entry020bd774 { int f0; int f4; int f8; int fc; };
struct EntryList020bd774 { int _0; int _4; int count; struct Entry020bd774 entries[1]; };
struct Holder020bd774 { char _pad[0x84]; struct EntryList020bd774* list; };
extern struct Holder020bd774* data_02110370;

// USA: func_020bd774
ARM int GetListEntryWord0020bd774(unsigned int index) {
    struct EntryList020bd774* list = data_02110370->list;
    if (index >= (unsigned int)list->count) return 0;
    return list->entries[index].f0;
}
