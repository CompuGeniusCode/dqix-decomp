#include <globaldefs.h>

struct MenuItem { char pad[0x13]; unsigned char paletteAndAdvance; };
struct MenuItemList { struct MenuItem* entries; short count; };
extern "C" struct MenuItem* FindMenuItemById(struct MenuItemList* list, int id);

struct MenuWindow { char pad[4]; struct MenuItemList list; };

// Writes the high nibble of the byte at +0x13 of a menu item, which is the text palette index:
// func_02081a14 passes it to the string drawer func_0204f41c as its sixth argument, and from
// 0x0204f668 that drawer lets an inline <PLTT=n> tag, the one AppendPaletteTag emits, overwrite the
// same argument mid-string. It is forced to 5 when the item carries bit 0x4 of +0x2a, and ov003's
// func_ov003_02167fa4 passes 0xd instead of the usual 0xf when the number shown is 100. The low
// nibble of that byte is a different field, the newline advance callers copy to +0xb6, not a font
// id. FindMenuItemById walks the same list on a 0x30 stride, so an item runs well past the 0x14
// this file declares.
extern "C" ARM void SetMenuItemTextPalette(struct MenuWindow* window, int id, int paletteIndex) {
    struct MenuItem* item = FindMenuItemById(&window->list, id);
    if (item != NULL) {
        item->paletteAndAdvance = (item->paletteAndAdvance & ~0xf0) | ((paletteIndex & 0xf) << 4);
    }
}
