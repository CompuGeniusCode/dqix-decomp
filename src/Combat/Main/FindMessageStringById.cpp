#include <globaldefs.h>

struct EntryA68 {
    short key;
    void* value;
};

struct TableA68 {
    struct EntryA68* entries;
    short count;
};

// Looks a string up by its numeric id in one of the window/message system's text tables: entries
// are {s16 id, char* text} eight bytes apart, with the count in the halfword at +4. Every caller
// treats the result as a C string -- ov004's func_02157374 does memcpy(dst, name, strlen(name)),
// ov023's func_021e8ef8 appends it to a window-markup buffer, func_02081a14 hands it to
// FormatMessageText, and func_020808c8 measures it with MeasureStringWidth. Ids are table-local,
// from 0x26 in ov003 to 0x27d8 in ov012, so which file each table comes from is not established.
extern "C" ARM void* FindMessageStringById(struct TableA68* table, int key) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (key == table->entries[i].key) {
            return table->entries[i].value;
        }
    }
    return 0;
}
