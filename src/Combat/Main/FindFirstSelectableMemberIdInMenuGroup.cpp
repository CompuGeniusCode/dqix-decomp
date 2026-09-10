#include <globaldefs.h>

struct WindowRecordList;
struct WindowRecord;
extern "C" WindowRecord* FindWindowRecordById(WindowRecordList* list, int id);

struct MenuItemList;
struct MenuItem;
extern "C" MenuItem* FindMenuItemById(MenuItemList* list, int id);

struct WindowRecord {
    short* memberIds;
    char unknown4[0x13 - 4];
    unsigned char count;
};

struct MenuItem {
    char unknown0[4];
    short f4;
    char unknown6[0x18 - 6];
    int neighbourDown;
    int neighbourUp;
    int neighbourRight;
    int neighbourLeft;
    char unknown28[0x2a - 0x28];
    unsigned char flags;
};

// Walks the member ids of one group in the list at +0xc and returns the first still selectable: its
// entry in the list at +0x4 must not carry bit 2 of the byte at +0x2a and must have at least one
// cursor neighbour -- func_0208036c follows +0x1c under key mask 0x40 (up), +0x18 under 0x80
// (down), +0x24 under 0x20 (left) and +0x20 under 0x10 (right). The id handed back is the one on
// the entry itself, the short at +0x4 FindMenuItemById matched on, rather than the one the group
// listed; the two agree because the lookup was keyed on it. The id is stored before the entry is
// checked, so with no member qualifying it hands back the last id examined rather than -1; only
// a missing or empty group gives -1.
extern "C" ARM short FindFirstSelectableMemberIdInMenuGroup(void* windowManager, int id) {
    short result = -1;
    WindowRecord* group = (WindowRecord*)FindWindowRecordById((WindowRecordList*)((char*)windowManager + 0xc), id);
    if (group != NULL) {
        unsigned char member;
        for (member = 0; member < group->count; member++) {
            result = group->memberIds[member];
            MenuItem* item = (MenuItem*)FindMenuItemById((MenuItemList*)((char*)windowManager + 4), result);
            if (item == NULL) continue;
            if (item->flags & 2) continue;
            if (item->neighbourDown == 0 && item->neighbourUp == 0 && item->neighbourRight == 0 && item->neighbourLeft == 0) continue;
            result = item->f4;
            break;
        }
    }
    return result;
}
