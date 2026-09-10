#include <globaldefs.h>

struct ByteHeader0204693c {
    signed char byte0;
    signed char byte1;
    signed char byte2;
    signed char byte3;
};

// Puts a node of the intrusive list module at 0x02046958-0x02046c78 back into its unlinked state:
// id to -1, in-list byte to 0. RemoveNodeFromList calls it as the final step of a successful unlink, and
// the ov017 and main Init* routines call it before a node is ever appended. Byte 0 is the signed id
// GetListHeadId and func_02046b60 read, byte 2 the in-list byte AppendNodeToTail and
// func_020469f8 set, byte 3 the flag func_020469f8 clears on the displaced head.
extern "C" ARM void ResetListNodeHeader(struct ByteHeader0204693c* p) {
    p->byte0 = -1;
    p->byte1 = 0;
    p->byte2 = 0;
    p->byte3 = 0;
}
