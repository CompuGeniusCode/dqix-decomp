#include <globaldefs.h>
#include "std_library_functions.h"

struct MessageNameSlot { char text[0x40]; };

struct MessageContext {
    char unknown0[0x4ac];
    struct MessageNameSlot names[16];
};

// Fills one of the 16 name-substitution slots the message system interpolates into text, each 0x40
// bytes at +0x4ac of the global message context. func_020691f8 is the reader, reached only through
// the function-pointer table at 0x020e7eb0: it parses the digit out of a message tag, subtracts one,
// and prints that slot -- so the tag digit is one-based while this index is zero-based. ov004's
// func_02164e40 is a typical writer, putting a combatant's name in slot 0; it takes the context from
// the global at func_020421a0+0x1c and then fills a second indexed string at +0x2ec of the same
// object, so unknown0 is a span with other message state in it, not dead bytes.
extern "C" ARM void SetMessageNameSlot(struct MessageContext* context, int index, char* str) {
    if (str == NULL) return;
    if (index < 0) return;
    if (index >= 0x10) return;
    strncpy(context->names[index].text, str, 0x3f);
    context->names[index].text[0x3f] = 0;
}
