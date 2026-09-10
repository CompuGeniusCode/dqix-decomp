#include <globaldefs.h>

// Hands back one of the eight item-id lists whose pointers sit at +0xbd0. func_0207c258 lays them
// out inside the same object with capacities 272, 48, 192, 96, 144, 80, 112 and 64 taken from
// data_020e8a24, pairs each with a stack-count array at +0xbf0, and writes -1 into every id slot to
// mean empty; func_0207c378 caps a stack at 0x63, which is the 99 the bag shows. The argument is the
// index into the pointer table, which func_0207c258 starts out equal to the category key at +0xc20
// that the other accessors search by, though nothing keeps the two in step.
extern "C" ARM void* GetItemIdListForCategory(unsigned char* obj, unsigned int index) {
    if (index > 7) {
        return NULL;
    }
    return *(void**)(obj + index * 4 + 0xbd0);
}
