#include <globaldefs.h>

extern "C" void func_0203ac40(void*, int, int, int);

// Starts sound-effect sequence `index` from the sequence archive LoadSeGroupAndSelectSeqArc selected, doing
// nothing while the short at +0xc4 is negative. func_0203ac40 reads that value as a SEQARC number
// through the SDAT INFO record at offset 0xc, and falls back to the handle at +0x98 when `player`
// is null. The object is always the sound-effect singleton at 0x02108760, which SetSoundSceneMode
// loads se_norm.sdat or se_btl.sdat into. 0x0205eb24 plays the outer slot at +0xbc the same way,
// and 0x0205eb90 is an identical duplicate on the same singleton, so it will need a name of its own.
extern "C" ARM void PlaySeFromSelectedSeqArc(void* obj, int a, int b) {
    short s = *(short*)((char*)obj + 0xc4);
    if (s >= 0) {
        func_0203ac40(obj, s, a, b);
    }
}
