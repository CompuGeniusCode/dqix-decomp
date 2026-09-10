#include <globaldefs.h>

struct WindowRecordList;

struct WindowRecord {
    char unknown0[0x15];
    unsigned char flags;
};

extern "C" struct WindowRecord* FindWindowRecordById(struct WindowRecordList* list, int id);

struct WindowManager {
    char unknown0[0xc];
};

// Sets or clears the 0x2 bit of the flag byte at +0x15 of the window record with this id. The list
// at +0xc of the owner is the window table: curated OpenWindowById (0x020813ec) resolves its
// argument through FindWindowRecordById over that same list, and
// FindFirstSelectableMemberIdInMenuGroup reads a record's member-id array at +0, count at +0x13 and
// position at +0xa/+0xc in eight-pixel units. Records are 0x18 bytes and carry their id in the
// short at +8, so the flag byte sits inside one. 0x02081130 sets the 0x1 bit and 0x02081198 the
// high nibble of +0x12; what the 0x2 bit means is not established. Callers are ov003, ov006 and
// ov014.
extern "C" ARM void SetWindowFlag2ById(struct WindowManager* owner, int id, int enable) {
    struct WindowRecord* record = FindWindowRecordById((struct WindowRecordList*)((char*)owner + 0xc), id);
    if (record == NULL) {
        return;
    }
    if (enable) {
        record->flags |= 0x2;
    } else {
        record->flags &= ~0x2;
    }
}
