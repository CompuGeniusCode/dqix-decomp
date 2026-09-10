#include <globaldefs.h>

struct MenuItem {
    char unknown0[0xe];
    short messageId;
    char unknown10[0x30 - 0x10];
};

struct MenuItemList;

extern "C" extern struct MenuItem* FindMenuItemById(struct MenuItemList*, int);

// Stores the string id a menu item draws its label from, in the halfword at +0xe of the item
// FindMenuItemById returns. func_02081a14, which renders one item, passes that halfword straight
// to FindMessageStringById against the list's text table and formats the result into the item's buffer;
// func_020808c8 reads it only in its kind-0 branch -- kind 1 returns two numbers and no string at
// all, and kind 4 takes its text from the pointer at +0. ov003's func_02167fa4 computes the ids
// from a table, so labels are data-driven rather than fixed at the call site. The list searched is
// the one the owning menu keeps at +4, the same 0x30-stride list FindMenuItemById walks.
extern "C" ARM void SetMenuItemMessageId(void* menu, int id, int messageId) {
    struct MenuItem* item = FindMenuItemById((struct MenuItemList*)((char*)menu + 4), id);
    if (item != NULL) {
        item->messageId = (short)messageId;
    }
}
