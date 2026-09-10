#include <globaldefs.h>

struct MenuItem { int value; };
struct MenuItemList { struct MenuItem* items; short itemCount; };
extern "C" struct MenuItem* FindMenuItemById(struct MenuItemList* list, int id);

struct WindowSet { char unknown0[4]; struct MenuItemList list; };

// Stores a number into the first word of a menu item, found by FindMenuItemById (0x0207f6ac) in
// the list at obj + 4. Callers put the page number and page count of a scrolling list there
// (ov014 0x021885bc), the alchemy quantity selector's 1..9 count (ov006 0x02159320) and a
// quantity times a per-unit value in a shisetsu screen (ov003 0x0217726c), so the slot holds the
// number the item displays rather than a parameter the item acts on.
// 0x02080f8c and 0x02080fc4 are byte-identical to this function and write the same slot; what
// distinguishes the three entry points is not established.
extern "C" ARM void SetMenuItemValue(struct WindowSet* windowSet, int id, int value) {
    struct MenuItem* menuItem = FindMenuItemById(&windowSet->list, id);
    if (menuItem != NULL) {
        menuItem->value = value;
    }
}
