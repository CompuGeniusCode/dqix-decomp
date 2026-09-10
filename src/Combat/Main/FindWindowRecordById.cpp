#include <globaldefs.h>

struct Entry0207f0ac {
    char pad[8];
    short id;
    char pad2[0x18 - 0xa];
};

struct List0207f0ac {
    struct Entry0207f0ac* entries;
    short count;
};

// Finds the layout record for a window id in the 0x18-stride list the manager keeps at +0xc; the id
// is the short at +8, and a negative id or one no record carries gives null. OpenWindowById passes
// the same id here and to FindOpenWindowById, and FindMenuItemById is the twin search over the other
// list, at +0x4. The record holds the window's position in tiles at +0xa and +0xc and, at +0, the
// ids of the menu items inside it with the count at +0x13. Which of the three files
// QueueTextAndWindowFiles loads builds this list is not established -- the parser is not decompiled.
extern "C" ARM struct Entry0207f0ac* FindWindowRecordById(struct List0207f0ac* list, int id) {
    short i;
    struct Entry0207f0ac* e;
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
