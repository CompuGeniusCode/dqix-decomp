#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// The global per-frame step at +0x3c4 of the game state root, set to 2 by func_02010124 next to
// +0x3b4/+0x3b8 = 0x21 (33 ms, one 30 Hz tick) and +0x3c0 = fix32 2.0, which Object3D.cpp already
// annotates as the model-animation deltaTime -- so this is presumably that same step in whole
// ticks. func_02067e58 clamps a repeat count up to it, func_02033710 multiplies an actor's turn
// rate by it, and func_ov001_02157e18 steps a tween to a limit of twice the requested duration,
// which only lands on that duration at a step of 2. Nothing decompiled writes it after the init.
extern "C" ARM unsigned int GetFrameTimeStep(struct BattleStruct* battleStruct) {
    return *(unsigned int*)((char*)battleStruct + 0x3c4);
}
