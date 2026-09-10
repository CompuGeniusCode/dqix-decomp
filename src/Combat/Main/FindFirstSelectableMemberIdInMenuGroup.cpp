#include <globaldefs.h>

struct List0207f0ac;
struct Entry0207f0ac;
extern "C" Entry0207f0ac* FindWindowRecordById(List0207f0ac* list, int id);

struct List0207f6ac;
struct Entry0207f6ac;
extern "C" Entry0207f6ac* FindMenuItemById(List0207f6ac* list, int id);

struct Group02080468 {
    short* memberIds;
    char pad[0x13 - 4];
    unsigned char count;
};

struct CombatEntry02080468 {
    char pad0[4];
    short f4;
    char pad1[0x18 - 6];
    int f18;
    int f1c;
    int f20;
    int f24;
    char pad2[0x2a - 0x28];
    unsigned char flag2a;
};

// Walks the member ids of one group in the list at +0xc and returns the first still selectable: its
// entry in the list at +0x4 must not carry bit 2 of the byte at +0x2a and must have at least one
// cursor neighbour -- func_0208036c follows +0x1c under key mask 0x40 (up), +0x18 under 0x80
// (down), +0x24 under 0x20 (left) and +0x20 under 0x10 (right). The id is stored before the entry
// is checked, so with no member qualifying it hands back the last id examined rather than -1; only
// a missing or empty group gives -1.
extern "C" ARM short FindFirstSelectableMemberIdInMenuGroup(void* obj, int id) {
    short result = -1;
    Group02080468* group = (Group02080468*)FindWindowRecordById((List0207f0ac*)((char*)obj + 0xc), id);
    if (group != NULL) {
        unsigned char i;
        for (i = 0; i < group->count; i++) {
            result = group->memberIds[i];
            CombatEntry02080468* e = (CombatEntry02080468*)FindMenuItemById((List0207f6ac*)((char*)obj + 4), result);
            if (e == NULL) continue;
            if (e->flag2a & 2) continue;
            if (e->f18 == 0 && e->f1c == 0 && e->f20 == 0 && e->f24 == 0) continue;
            result = e->f4;
            break;
        }
    }
    return result;
}
