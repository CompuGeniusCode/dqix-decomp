#include <globaldefs.h>

// Returns the record pointer at +0x8 of a field object slot -- one of the 32 entries GetActorSlot
// indexes on the registry GetFieldObjectRegistry returns. The record opens with the short id
// FindFieldObjectById searches on and carries a name four bytes in, which ov001's
// ReleaseEventObjectGraphics formats into "%s.spr" to give the sprite back. func_02040520 is the
// write. Where the records themselves are parsed from has not been worked out.
extern "C" ARM int GetActorRecord(int* obj) {
    return obj[2];
}
