#include <globaldefs.h>

// Reads the option the player is on, at +0x954 of the message work GetMessageWork returns.
// func_02045740, immediately before this on the same object, decrements +0x954 on one
// input flag and increments it on the other, wraps it against the option count at +0x9a4 and
// mirrors it to +0x994 -- a cursor over a bounded option list. Callers take it as the answer:
// func_ov011_02184ae4 switches case 0 / case 1 between two stored jump targets, and
// func_ov001_021609c0 hands it straight to an event-script variable.
extern "C" ARM int GetMessageChoiceIndex(char* obj) {
    return *(int*)(obj + 0x954);
}
