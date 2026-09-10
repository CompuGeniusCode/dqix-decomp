#include <globaldefs.h>

struct WindowRecord {
    char unknown0[8];
    short id;
    char unknowna[0x18 - 0xa];
};

struct WindowRecordList {
    struct WindowRecord* entries;
    short count;
};

// Finds the layout record for a window id in the 0x18-stride list the manager keeps at +0xc; the id
// is the short at +8, and a negative id or one no record carries gives null. OpenWindowById passes
// the same id here and to FindOpenWindowById, and FindMenuItemById is the twin search over the other
// list, at +0x4. The record holds the window's position in tiles at +0xa and +0xc and, at +0, a
// pointer to the ids of the menu items inside it with the count at +0x13: func_02081574 walks that
// array and looks each id up with FindMenuItemById, and func_02081498 reads the shorts at
// +0xa..+0x10 with the nibbles at +0x14 and the flags at +0x15. So unknown0 and unknowna are spans
// with known contents rather than unexamined bytes. Which of the three files
// QueueTextAndWindowFiles loads builds this list is not established -- the parser is not decompiled.
extern "C" ARM struct WindowRecord* FindWindowRecordById(struct WindowRecordList* list, int id) {
    short recordIndex;
    struct WindowRecord* e;
    if (id < 0) {
        return NULL;
    }
    for (recordIndex = 0; recordIndex < list->count; recordIndex++) {
        e = &list->entries[(unsigned int)recordIndex];
        if (id == e->id) {
            return e;
        }
    }
    return NULL;
}
