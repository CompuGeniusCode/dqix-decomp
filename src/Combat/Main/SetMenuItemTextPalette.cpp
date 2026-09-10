#include <globaldefs.h>

struct Entry02080cc0 { char pad[0x13]; unsigned char flags; };
struct List0207f6ac { struct Entry02080cc0* entries; short count; };
extern "C" struct Entry02080cc0* FindMenuItemById(struct List0207f6ac* list, int id);

struct Container02080cc0 { char pad[4]; struct List0207f6ac list; };

// Writes the high nibble of the byte at +0x13 of a menu item, which is the text palette index:
// func_02081a14 passes it to the string drawer func_0204f41c as arg 6, and from 0x0204f668 that
// drawer lets an inline <PLTT=n> tag, the one AppendPaletteTag emits, overwrite the same argument
// mid-string. It is forced to 5 when the item carries bit 0x4 of +0x2a, and ov003's func_02167fa4
// passes 0xd instead of the usual 0xf when the value shown is 100. The low nibble of that byte is a
// different field, the newline advance callers copy to +0xb6, not a font id.
extern "C" ARM void SetMenuItemTextPalette(struct Container02080cc0* obj, int id, int value) {
    struct Entry02080cc0* e = FindMenuItemById(&obj->list, id);
    if (e != NULL) {
        e->flags = (e->flags & ~0xf0) | ((value & 0xf) << 4);
    }
}
