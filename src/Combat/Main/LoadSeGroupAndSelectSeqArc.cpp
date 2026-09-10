#include <globaldefs.h>

extern "C" void func_0203aa80(void* obj, int arg2);
extern "C" int func_0203aa98(void*, int);

// Frees the sound heap back to the mark at +0xc0, loads SDAT group `groupNo` on top of it, and
// records `seqArcNo` at +0xc4 for PlaySeFromSelectedSeqArc to play from. It is a group number because the load
// reaches func_020bdce8, which walks the INFO record at offset 0x1c - type 5, GROUP - dispatching
// items by type 0..3. The object is the sound-effect manager singleton at 0x02108760, filled from
// data/sound/se_norm.sdat or se_btl.sdat, and this scope nests inside the outer one at +0xb8/+0xbc
// that 0x0205ead0 drives. 0x0205eb54 is the same code on the same singleton, bar its call offsets.
extern "C" ARM void LoadSeGroupAndSelectSeqArc(void* obj, int arg1, int arg2) {
    func_0203aa80(obj, *(int*)((char*)obj + 0xc0));
    func_0203aa98(obj, arg1);
    *(short*)((char*)obj + 0xc4) = (short)arg2;
}
