#include <globaldefs.h>

struct List0207f0ac;

struct StatusEntry02081164 {
    char pad[0x15];
    unsigned char flags;
};

extern "C" struct StatusEntry02081164* FindWindowRecordById(struct List0207f0ac* list, int id);

struct StatusOwner02081164 {
    char pad[0xc];
};

// Sets or clears the 0x2 bit of the flag byte at +0x15 of the window record with this id. The list
// at +0xc of the owner is the window table: curated OpenWindowById (0x020813ec) resolves its
// argument through FindWindowRecordById over that same list, and
// FindFirstSelectableMemberIdInMenuGroup reads a record's member-id array at +0, count at +0x13 and
// position at +0xa/+0xc in eight-pixel units. 0x02081130 sets the 0x1 bit and 0x02081198 the high
// nibble of +0x12; what the 0x2 bit means is not established. Callers are ov003, ov006 and ov014.
extern "C" ARM void SetWindowFlag2ById(struct StatusOwner02081164* owner, int id, int enable) {
    struct StatusEntry02081164* e = FindWindowRecordById((struct List0207f0ac*)((char*)owner + 0xc), id);
    if (e == NULL) {
        return;
    }
    if (enable) {
        e->flags |= 0x2;
    } else {
        e->flags &= ~0x2;
    }
}
