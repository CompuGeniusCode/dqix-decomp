#include <globaldefs.h>

struct SearchStruct;
extern "C" signed char func_0202bcbc(struct SearchStruct* obj, int value);

// Maps a player id to that player's record inside the multiplayer state block, the object
// GetMultiplayerState hands out. obj+0x1038 is a sixteen-entry slot-to-id table and the records
// are 0x74 bytes from obj+0xbc0, but only four are ever filled: func_0202bf40 loops i < 4, and the
// local player's own copy sits separately at obj+0x7c0, which callers substitute when the id
// matches their own slot. Nothing bounds the index here, so an id parked in a table slot above 3
// would read past the four records.
extern "C" ARM void* GetMultiplayerPlayerRecord(struct SearchStruct* obj, int value) {
    int idx = func_0202bcbc(obj, value);
    if (idx < 0) return NULL;
    return (char*)obj + 0xbc0 + idx * 0x74;
}
