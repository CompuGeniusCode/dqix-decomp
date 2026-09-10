#include <globaldefs.h>

struct NSBXXAnimationJAC {
    char signature[4];
    unsigned short numFrames;
};

struct AnimationData {
    int time;
    int weight;
    struct NSBXXAnimationJAC* rawData;
};

extern "C" void _Z36CalculateBoneMatrixRenderDataFromJACP17NSBXXAnimationJACiiP20BoneMatrixRenderData(struct NSBXXAnimationJAC* target, int trackIndex, int time, int renderData);

// The AnimationData callback for J.AC joint animations: clamps the animation time to the
// animation's own length and hands it to CalculateBoneMatrixRenderDataFromJAC. Time is fix32 with
// twelve fraction bits, so the frame count at +0x4 of the J.AC shifted left twelve is one past the
// end and the clamp lands on that minus one; a negative time is pulled up to 0. The parameter order
// is the awkward part: the void* the AnimationData::Callback signature passes first is the
// BoneMatrixRenderData the callee wants last, and the int passed last is the track index it wants
// second. The weight at +0x4 of AnimationData plays no part here.
extern "C" ARM void _Z30JACAnimationProcessingCallbackPvP13AnimationDatai(int renderData, struct AnimationData* args, int trackIndex) {
    struct NSBXXAnimationJAC* target = args->rawData;
    int time = args->time;
    int endTime = target->numFrames << 12;
    if (time >= endTime) {
        time = endTime - 1;
    } else if (time < 0) {
        time = 0;
    }
    _Z36CalculateBoneMatrixRenderDataFromJACP17NSBXXAnimationJACiiP20BoneMatrixRenderData(target, trackIndex, time, renderData);
}
