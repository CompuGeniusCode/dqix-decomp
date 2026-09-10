#include <globaldefs.h>

struct SearchStruct;
extern "C" signed char func_0202bcbc(struct SearchStruct* obj, int value);

// Answers whether the member with this id holds a slot in the multiplayer session state that
// GetMultiplayerState returns: func_0202bcbc scans the sixteen signed bytes at +0x1038 for the id,
// and the bit tested sits at +0x100c, set on registration by func_0202c1e8 and cleared by
// func_0202c21c along with the member's id. It is a second condition on top of the id being in the
// table - func_0202bd68 tests both, over slots 0..3 only. A reset leaves the byte at 1, so bit 0 is
// presumably the local slot; five more bytes at +0x100d..+0x1011 are set up with it, roles unknown.
extern "C" ARM int IsMultiplayerMemberPresent(struct SearchStruct* obj, int value) {
    int idx = func_0202bcbc(obj, value);
    if (idx < 0) return 0;
    return *(unsigned char*)((char*)obj + 0x1000 + 0xc) & (1 << idx);
}
