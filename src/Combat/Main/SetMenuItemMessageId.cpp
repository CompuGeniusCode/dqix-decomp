#include <globaldefs.h>

struct Entry0208103c {
    char unk0[0xe];
    short field_e;
    char unk10[0x30 - 0x10];
};

struct List0207f6ac;

extern "C" extern struct Entry0208103c* FindMenuItemById(struct List0207f6ac*, int);

// Stores the string id a menu item draws its label from, in the halfword at +0xe of the item
// FindMenuItemById returns. func_02081a14, which renders one item, passes that halfword straight
// to FindMessageStringById against the list's text table and formats the result into the item's buffer;
// func_020808c8 reads it only in its kind-0 branch -- kind 1 returns two numbers and no string at
// all, and kind 4 takes its text from the pointer at +0. ov003's func_02167fa4 computes the ids
// from a table, so labels are data-driven rather than fixed at the call site.
extern "C" ARM void SetMenuItemMessageId(void* obj, int id, int value) {
    struct Entry0208103c* e = FindMenuItemById((struct List0207f6ac*)((char*)obj + 4), id);
    if (e != NULL) {
        e->field_e = (short)value;
    }
}
