#include <globaldefs.h>

struct ToggleState {
    char unk[0x9C4];
    unsigned char isActive;
    char unk9C5[0x3];
    unsigned char mode;
};

// USA: func_02021410
ARM void SetToggleState(struct ToggleState* state, int active, int mode) {
    state->isActive = active != 0;
    state->mode = mode;
}
