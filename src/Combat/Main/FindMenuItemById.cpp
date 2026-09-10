#include <globaldefs.h>

struct Entry0207f6ac {
    char pad[4];
    short id;
    char pad2[0x30 - 0x6];
};

struct List0207f6ac {
    struct Entry0207f6ac* entries;
    short count;
};

// Finds one entry of a window's cursor list by the id the layout file gave it -- the *_wnd.bin
// func_0207f914 loads. func_0208036c steps the same entries and picks among the four
// pointers at +0x18..+0x24 by D-pad bit (0x40, 0x80, 0x20, 0x10), so the list is the four-way
// navigation graph, and func_0207f72c is what turns the stored ids into those pointers.
// Bit 0x2 of +0x2a marks an entry the walk refuses to land on. FindWindowRecordById is the
// same search over the other, 0x18-stride list the same object keeps at +0xc.
extern "C" ARM struct Entry0207f6ac* FindMenuItemById(struct List0207f6ac* list, int id) {
    short i;
    struct Entry0207f6ac* e;
    if (id < 0) {
        return NULL;
    }
    for (i = 0; i < list->count; i++) {
        e = &list->entries[(unsigned int)i];
        if (id == e->id) {
            return e;
        }
    }
    return NULL;
}
