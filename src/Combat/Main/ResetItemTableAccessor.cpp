#include <globaldefs.h>

extern "C" void func_020de848(void* obj);

// Empties the item-table helper: the record descriptor at +0x14 plus the cached table pointer at
// +0x2c and the two words after it. func_0207d6dc builds the same 0x38-byte object -- a
// SafeAllocator at +0x0 with itemdt_<LG>.nat from data/prm/itemdt.gp2 read into +0x14 -- and
// func_0207d134 uses it to look an item up and hand it to func_0207c378, the bag insert that caps
// a stack at 0x63. func_0209d8a8 instead points +0x2c at a container out of ov017 state, so the
// cached table is not always the one func_0207d6dc loads. func_0207cc0c only calls this.
extern "C" ARM void ResetItemTableAccessor(char* obj) {
    func_020de848(obj + 0x14);
    *(int*)(obj + 0x2c) = 0;
    *(int*)(obj + 0x30) = 0;
    *(int*)(obj + 0x34) = 0;
}
