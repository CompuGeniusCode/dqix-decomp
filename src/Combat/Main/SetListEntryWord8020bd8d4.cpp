#include <globaldefs.h>

struct Entry020bd8d4 { int f0; int f4; int f8; int fc; };
struct EntryList020bd8d4 { int _0; int _4; int count; struct Entry020bd8d4 entries[1]; };
struct Holder020bd8d4 { char _pad[0x84]; struct EntryList020bd8d4* list; };
extern struct Holder020bd8d4* data_02110370;

// USA: func_020bd8d4
ARM void SetListEntryWord8020bd8d4(unsigned int index, int value) {
    data_02110370->list->entries[index].f8 = value;
}
