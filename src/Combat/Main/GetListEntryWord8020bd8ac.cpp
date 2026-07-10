#include <globaldefs.h>

struct Entry020bd8ac { int f0; int f4; int f8; int fc; };
struct EntryList020bd8ac { int _0; int _4; int count; struct Entry020bd8ac entries[1]; };
struct Holder020bd8ac { char _pad[0x84]; struct EntryList020bd8ac* list; };
extern struct Holder020bd8ac* data_02110370;

// USA: func_020bd8ac
ARM int GetListEntryWord8020bd8ac(unsigned int index) {
    struct EntryList020bd8ac* list = data_02110370->list;
    if (index >= (unsigned int)list->count) return 0;
    return list->entries[index].f8;
}
