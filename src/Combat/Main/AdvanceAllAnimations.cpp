#include <globaldefs.h>

struct AnimationList {
    char unknown0[4];
    unsigned short count;
};

extern "C" void func_0205a254(struct AnimationList*, int, int);

// Advances every animation entry in the set by the given number of frames. The worker at
// 0x0205a254 looks each entry up with FindAnimationByKey, and for entries whose byte at 0x15 has
// bit 1 set -- the state StartAnimationByKey leaves them in -- it adds the argument to the
// halfword timer at 0x12, compares that against the halfword the table at 0xc holds for the
// current frame index at 0x10, and steps the frame on overflow.
// ov008 0x02188870, ov013 0x021847c4 and ov023 0x021e3304 pass *(battle + 0x3c4), the same repeat
// count 0x02067e58 clamps its step loop to; ov003 0x0216acf0 passes a value of its own, so the
// argument is a frame step rather than a fixed tick.
// The loop feeds its own counter in as the key, so entry keys look like the indices 0..count-1,
// though 0x0205a3d0 matches a stored halfword rather than an index.
extern "C" ARM void AdvanceAllAnimations(struct AnimationList* animations, int elapsedFrames) {
    unsigned short animationKey;
    for (animationKey = 0; animationKey < animations->count; animationKey++) {
        func_0205a254(animations, animationKey & 0xff, elapsedFrames);
    }
}
