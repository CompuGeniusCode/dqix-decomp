#include <globaldefs.h>
#include "std_library_functions.h"

struct NameBuf02046574 { char c[0x40]; };

struct Obj02046574 {
    char pad[0x4ac];
    struct NameBuf02046574 names[16];
};

// Fills one of the 16 name-substitution slots the message system interpolates into text, each 0x40
// bytes at +0x4ac of the global message context. func_020691f8 is the reader, reached only through
// the function-pointer table at 0x020e7eb0: it parses the digit out of a message tag, subtracts one,
// and prints that slot -- so the tag digit is one-based while this index is zero-based. ov004's
// func_02164e40 is a typical writer, putting a combatant's name in slot 0.
extern "C" ARM void SetMessageNameSlot(struct Obj02046574* obj, int index, char* str) {
    if (str == NULL) return;
    if (index < 0) return;
    if (index >= 0x10) return;
    strncpy(obj->names[index].c, str, 0x3f);
    obj->names[index].c[0x3f] = 0;
}
