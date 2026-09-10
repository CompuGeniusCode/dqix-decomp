#include <globaldefs.h>

struct MenuItem {
    char unknown0[4];
    short id;
    char unknown6[0x30 - 0x6];
};

struct MenuItemList {
    struct MenuItem* entries;
    short count;
};

// Finds one item of a window's cursor list by the id the layout file gave it -- the *_wnd.bin
// QueueTextAndWindowFiles loads. func_0208036c steps the same items and picks among the four
// pointers at +0x18..+0x24 by D-pad bit (0x40, 0x80, 0x20, 0x10), so the list is the four-way
// navigation graph, and func_0207f72c is what turns the stored ids into those pointers.
// Bit 0x2 of +0x2a marks an item the walk refuses to land on. FindWindowRecordById is the
// same search over the other, 0x18-stride list the same object keeps at +0xc. An item is 0x30
// bytes and only part of it is known: the id searched here is the short at +4, the message id is
// the halfword at +0xe, a kind byte at +0x12 selects what func_020808c8 returns, and the four
// navigation ids sit at +0x18.
extern "C" ARM struct MenuItem* FindMenuItemById(struct MenuItemList* list, int id) {
    short itemIndex;
    struct MenuItem* e;
    if (id < 0) {
        return NULL;
    }
    for (itemIndex = 0; itemIndex < list->count; itemIndex++) {
        e = &list->entries[(unsigned int)itemIndex];
        if (id == e->id) {
            return e;
        }
    }
    return NULL;
}
