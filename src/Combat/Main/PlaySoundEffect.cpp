#include <globaldefs.h>

extern "C" void func_0203ac40(void*, int, int, int);

struct Obj0205eaa0 {
    char pad_00[0xb4];
    short field_b4;
};

// Plays one sequence out of a sound-effect archive. The halfword at +0xb4 is a SEQARC index into
// the SDAT at +0x4, and it is fixed per object: 35 of the 38 arm9 call sites pass data_02108760,
// which func_0205ea20 opens as data/sound/se_norm.sdat, where SEQARC 100 is SYMB-named SEQ_SY_001
// and the sequences the callers ask for (0x12, 0x13, 0x62) are SE_SY018_tanao, SE_SY019_tanac and
// SE_SY098. The first argument picks the sequence; the second is an optional handle, and
// func_0203ac40 falls back to the object's own handle at +0x98.
extern "C" ARM void PlaySoundEffect(struct Obj0205eaa0* obj, int a, int b) {
    func_0203ac40(obj, obj->field_b4, a, b);
}
